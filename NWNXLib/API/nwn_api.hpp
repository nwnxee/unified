#pragma once

#include "Constants.hpp"
#include <stdlib.h>
#include <string>
#include <memory>
#include <vector>
#include <type_traits>

#include "External/json/json.hpp"

#define NWNX_INTERNAL_EXPAND(s) #s
#define NWNX_INTERNAL_STRINGIFY(s) NWNX_INTERNAL_EXPAND(s)

#define NWNX_EXPECT_VERSION(version, revision)            \
static_assert(NWNX_TARGET_NWN_BUILD == version && NWNX_TARGET_NWN_BUILD_REVISION == revision, \
"This build-specific code targets build "       \
#version " revision " #revision                 \
" but is being compiled against build "         \
NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD)  \
" revision " NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD_REVISION))

#define NWN_API_PROLOGUE(...)
#define NWN_API_EPILOGUE(...)

struct CExoLinkedListNode;
typedef uint16_t RESTYPE;
typedef uint32_t ObjectID;
typedef uint32_t PlayerID;

struct DataView;
using DataViewRef = std::shared_ptr<DataView>;
struct DataBlock;
using DataBlockRef = std::shared_ptr<DataBlock>;

struct DataView
{
    struct Shared
    {
        Shared(const void* data, size_t used, size_t allocated, bool owned) : m_data(const_cast<void*>(data)), m_used(used), m_allocated(allocated), m_owned(owned) {}
        ~Shared()
        {
            if (m_owned)
                free(m_data);
        }

        void* m_data;
        size_t m_used;
        size_t m_allocated;
        bool m_owned;
    };
    using SharedRef = std::shared_ptr<Shared>;

    SharedRef m_shared;
    SharedRef m_parent;

    explicit DataView(const void* data, size_t length) : m_shared(std::make_shared<Shared>(data, length, 0, false)) {}
    const void* Data() const { return m_shared->m_data; };
    size_t Used() const { return m_shared->m_used; }
    size_t Allocated() const { return m_shared->m_allocated; }
    DataViewRef View(size_t offset, size_t count) const;
    DataBlockRef MakeCopy() const;
    bool empty() const { return m_shared->m_used == 0; };
};

struct DataBlock : DataView
{
    explicit DataBlock(size_t preallocate = 0) : DataView(nullptr, 0)
    {
        m_shared->m_owned = true;
        if (preallocate > 0)
            AllocateAtLeast(preallocate);
    }
    explicit DataBlock(const void *data, size_t length) : DataView(nullptr, 0)
    {
        Append(data, length);
        m_shared->m_owned = true;
    }

    explicit DataBlock(const std::vector<uint8_t>& data) : DataView(nullptr, 0)
    {
        Append(data.data(), data.size());
        m_shared->m_owned = true;
    }
    explicit DataBlock(const std::string& data) : DataView(nullptr, 0)
    {
        Append(data.data(), data.size());
        m_shared->m_owned = true;
    }

    void* Data() { return m_shared->m_data; }
    void AllocateAtLeast(size_t length);
    void MarkUsed(size_t length);
    void Prepend(const void* payload, size_t length, size_t chunkSize = 0);
    void Append(const void* payload, size_t length, size_t chunkSize = 0);
    void Compact();
};

// sole.h
struct CUUID {
    CUUID() : ab(0), cd(0) {}

    uint64_t ab;
    uint64_t cd;

    bool empty() const { return ab == 0 && cd == 0; }
    operator bool() const { return !empty(); }

    void clear() { ab = 0; cd = 0; }

    inline bool operator==( const CUUID &other ) const {
        return ab == other.ab && cd == other.cd;
    }
    inline bool operator!=( const CUUID &other ) const {
        return !operator==(other);
    }
    inline bool operator<( const CUUID &other ) const {
        if( ab < other.ab ) return true;
        if( ab > other.ab ) return false;
        if( cd < other.cd ) return true;
        return false;
    }

    std::string pretty() const;
    std::string base62() const;
    std::string str() const;

    template<typename ostream>
    inline friend ostream &operator<<( ostream &os, const CUUID &self ) {
        return os << self.str(), os;
    }

    // Generators
    static CUUID uuid0(); // UUID v0, pro: unique; cons: MAC revealed, pid revealed, predictable.
    static CUUID uuid1(); // UUID v1, pro: unique; cons: MAC revealed, predictable.
    static CUUID uuid4(); // UUID v4, pros: anonymous, fast; con: uuids "can clash"

    // Rebuilders
    static CUUID rebuild( uint64_t ab, uint64_t cd );
    static CUUID rebuild( const std::string &uustr );
};
using json = nlohmann::json;

namespace Nui::JSON {
    using WindowToken = int32_t; // nwscript compat type
    using WindowIdentifier = std::string;
    using ElementId = std::string;
    using EventType = std::string;
    using EventPayload = json;
    using BindName = std::string;
    using BindValue = json;
    struct BindUpdate
    {
        ObjectID m_player = NWNXLib::API::Constants::OBJECT_INVALID;
        WindowToken m_token = 0;
        BindName m_bind;
        BindValue m_value;
        bool IsValid() const { return m_token > 0; }
    };
    //using BindUpdateQueue = std::queue<BindUpdate>;
    struct Event
    {
        ObjectID m_player = NWNXLib::API::Constants::OBJECT_INVALID;
        WindowToken m_token = 0;
        EventType m_event;
        ElementId m_element;
        int32_t m_array_index = -1;
        EventPayload m_payload;
        bool IsValid() const { return m_token > 0; }
    };
    //using EventQueue = std::queue<Event>;
}

template<typename T>
struct SharedPtrEngineStructure
{
    std::shared_ptr<T> m_shared;
    virtual ~SharedPtrEngineStructure() {}
    virtual bool IsEmpty() const = 0;
    virtual void Clear() = 0;
    virtual void Unlink() = 0;
};

template<typename T>
struct DistinctSimpleType
{
    static_assert(std::is_trivially_copyable_v<T>, "T must be a trivially copyable type");

    DistinctSimpleType(const DistinctSimpleType& other) = default;
    DistinctSimpleType(DistinctSimpleType&& other) = default;
    DistinctSimpleType& operator=(const DistinctSimpleType& other) = default;
    DistinctSimpleType& operator=(DistinctSimpleType&& other) = default;

    bool operator==(const DistinctSimpleType& rhs) const
    {
        return m_id == rhs.m_id;
    }

    bool operator!=(const DistinctSimpleType& rhs) const
    {
        return !(*this == rhs);
    }

    T operator*() const
    {
        return m_id;
    }

protected:
    explicit DistinctSimpleType(T initial) : m_id(initial) {}

    T m_id;
};

struct CNetConnectionId : public DistinctSimpleType<uint32_t>
{
    CNetConnectionId() : DistinctSimpleType(INVALID) {}
    explicit CNetConnectionId(uint32_t id) : DistinctSimpleType(id) {}

    static const CNetConnectionId INVALID;
    static const CNetConnectionId MASTERSERVER;
    static const CNetConnectionId BROADCAST;
    static const CNetConnectionId SINGLEPLAYER;
};

#define NWN_CLASS_EXTENSION_CGameObject \
    using CleanupFunc = std::function<void(void*)>;                                                                         \
    void nwnxSet(const std::string& key, int value, bool persist = false, const char *pn = PLUGIN_NAME);                    \
    void nwnxSet(const std::string& key, float value, bool persist = false, const char *pn = PLUGIN_NAME);                  \
    void nwnxSet(const std::string& key, std::string value, bool persist = false, const char *pn = PLUGIN_NAME);            \
    void nwnxSet(const std::string& key, void *value, std::optional<CleanupFunc> cleanup, const char *pn = PLUGIN_NAME);    \
    template <typename T> std::optional<T> nwnxGet(const std::string& key, const char *pn = PLUGIN_NAME);                   \
    void nwnxRemove(const std::string& key, const char *pn = PLUGIN_NAME);                                                  \
    void nwnxRemoveRegex(const std::string& regex, const char *pn = PLUGIN_NAME);                                           \

