#include "stdlib.h"

#define PREFETCH(a)   __builtin_prefetch(a, 0, 0)
#define LIKELY(x)     __builtin_expect((x),1)
#define UNLIKELY(x)   __builtin_expect((x),0)

//
// This is a ridiculously memory hungry but *fast* hash table.
// It is not a general purpose data structure. In most cases
// you're better off using std::unordered_map instead.
//
template <typename T, uint32_t BucketCount=1024, uint32_t CacheSize=4, uint32_t BadID=0x7f000000>
struct HashTable32
{
    static_assert((BucketCount&(BucketCount-1)) == 0, "BucketCount must be power of two");

    // DO NOT REARRANGE ANY FIELDS - optimal placement across cache lines
    struct alignas(64) Cache
    {
        T*       m_ptrs[CacheSize];
        uint32_t m_ids[CacheSize];
    };

    static constexpr uint32_t ItemsInNode = 4;
    struct alignas(64) TopLevelNode
    {
        T*       m_ptrs[ItemsInNode];
        uint32_t m_ids[ItemsInNode];
        uint32_t m_vecCapacity;
        uint32_t m_vecSize;
        struct
        {
            T*       m_ptr;
            uint32_t m_id;
        } * m_vec;
    };
    static_assert(sizeof(TopLevelNode) == 64);

    Cache         m_cache;
    TopLevelNode* m_array;

    void Initialize()
    {
        constexpr uint32_t size = BucketCount * sizeof(TopLevelNode);
        m_array = (TopLevelNode*)aligned_alloc(0x1000, size);
        memset(m_array, 0, size);
        if constexpr (BadID != 0)
        {
            for (uint32_t i = 0; i < BucketCount; i++)
            {
                for (uint32_t j = 0; j < ItemsInNode; j++)
                    m_array[i].m_ids[j] = BadID;
            }
            for (uint32_t i = 0; i < CacheSize; i++)
                m_cache.m_ids[i] = BadID;
        }
    }

    inline uint32_t GetBucketCount() const { return BucketCount; }

    inline TopLevelNode& GetNode(uint32_t id) const { return m_array[id & (BucketCount-1)]; }
    inline void PrefetchNode(uint32_t id) const { PREFETCH(&m_array[id & (BucketCount-1)]); }

    bool Add(uint32_t id, T* ptr)
    {
        auto& node = GetNode(id);
        for (uint32_t i = 0; i < ItemsInNode; i++)
        {
            if (node.m_ids[i] == id)
                return false; // double insert

            if (node.m_ids[i] == BadID)
            {
                node.m_ids[i] = id;
                node.m_ptrs[i] = ptr;
                return true;
            }
        }
        if (node.m_vecSize == node.m_vecCapacity)
        {
            node.m_vecCapacity = (node.m_vecCapacity+4) * 2;
            node.m_vec = (decltype(node.m_vec))realloc(node.m_vec, node.m_vecCapacity * sizeof(*node.m_vec));
        }
        node.m_vec[node.m_vecSize].m_id  = id;
        node.m_vec[node.m_vecSize].m_ptr = ptr;
        node.m_vecSize++;
        return true;
    }

    bool Delete(uint32_t id, T** ptr = nullptr)
    {
        if (id == BadID)
            return false;

        for (uint32_t i = 0; i < CacheSize; i++)
        {
            if (m_cache.m_ids[i] == id)
            {
                m_cache.m_ids[i]  = BadID;
                m_cache.m_ptrs[i] = nullptr;
            }
        }

        auto& node = GetNode(id);
        for (uint32_t i = 0; i < ItemsInNode; i++)
        {
            if (node.m_ids[i] == id)
            {
                if (ptr) *ptr = node.m_ptrs[i];

                const uint32_t movecnt = ItemsInNode - i - 1;
                if (movecnt > 0)
                {
                    memmove(&node.m_ids[i],  &node.m_ids[i+1],  movecnt * sizeof(id));
                    memmove(&node.m_ptrs[i], &node.m_ptrs[i+1], movecnt * sizeof(ptr));
                }
                if (node.m_vecSize > 0)
                {
                    node.m_ids[ItemsInNode-1]  = node.m_vec[node.m_vecSize-1].m_id;
                    node.m_ptrs[ItemsInNode-1] = node.m_vec[node.m_vecSize-1].m_ptr;
                    node.m_vecSize--;
                }
                else
                {
                    node.m_ids[ItemsInNode-1]  = BadID;
                    node.m_ptrs[ItemsInNode-1] = nullptr;
                }
                return true;
            }
        }
        if (node.m_vecSize > 0)
        {
            for (uint32_t i = 0; i < node.m_vecSize; i++)
            {
                if (node.m_vec[i].m_id == id)
                {
                    if (ptr) *ptr = node.m_vec[i].m_ptr;
                    if (i == node.m_vecSize-1)
                    {
                        node.m_vec[i].m_id = BadID;
                        node.m_vec[i].m_ptr = nullptr;
                    }
                    else
                    {
                        node.m_vec[i] = node.m_vec[node.m_vecSize-1];
                    }
                    node.m_vecSize--;
                    return true;
                }
            }
        }
        return false;
    }

    inline T* AddToCache(uint32_t id, T* ptr, uint32_t shiftby = CacheSize-1) __attribute__((hot))
    {
        PREFETCH(ptr);
        memmove(&m_cache.m_ids[1],  &m_cache.m_ids[0],  shiftby * sizeof(m_cache.m_ids[0]));
        memmove(&m_cache.m_ptrs[1], &m_cache.m_ptrs[0], shiftby * sizeof(m_cache.m_ptrs[0]));
        m_cache.m_ids[0] = id;
        m_cache.m_ptrs[0] = ptr;
        return ptr;
    }

    #pragma GCC optimize ("unroll-loops")
    T* Get(uint32_t id) __attribute__((hot))
    {
        // This function needs to be AS FAST AS POSSIBLE, so be very careful what you add to it.
        // The optimization should target the average case where the object does exist.
        if (UNLIKELY(id == BadID))
            return nullptr;

        // We first check our first level cache for the mappings. However, while
        // we're checking the logic there, we can fetch the required node from
        // the main memory into the CPU L1 cache. If our own cache does not contain
        // the mapping, we won't have to wait on a CPU cache miss later.
        PrefetchNode(id);

        // Check our first level cache first
        for (uint32_t i = 0; i < CacheSize; i++)
        {
            if (LIKELY(m_cache.m_ids[i] == id))
                return AddToCache(id, m_cache.m_ptrs[i], i);
        }

        auto& node = GetNode(id);
        for (uint32_t i = 0; i < ItemsInNode; i++)
        {
            if (LIKELY(node.m_ids[i] == id))
                return AddToCache(id, node.m_ptrs[i]);
        }

        for (uint32_t i = 0; i < node.m_vecSize; i++)
        {
            if (LIKELY(node.m_vec[i].m_id == id))
                return AddToCache(node.m_vec[i].m_id, node.m_vec[i].m_ptr);
        }
        return nullptr;
    }

    ~HashTable32()
    {
        if (m_array)
        {
            for (uint32_t i = 0; i < BucketCount; i++)
                free(m_array[i].m_vec);
            free(m_array);
        }

        memset(this, 0, sizeof(*this));
    }
};

