#pragma once

#include <queue>
#include <set>
#include <thread>
#include <mutex>

// This is a generic pool you can use to manage opaque objects.
// It can be used, for example, to do database connection management, but is
// in no way limited to that.
// All it needs to know is how to create instances.
//
// Usage:
// - Summon it with giving a MakeFunc to the ctor. The MakeFunc needs to be able
//   to create instances of T. It needs to be threadsafe.
// - Use Take/Give to fetch Ts from the pool; or if you do not want to care
//   about that, use Borrow() to automatically return it to the pool after
//   you are done with it
// - Thats it.
//
// N.B.: Currently, the pool will happily accept old connections back after
//       reconfiguring with a new MakeFunc.
template<typename T>
class Pool
{
public:
    typedef std::unique_ptr<T> Contained;
    typedef std::function<Contained()> MakeFunc;

public:
    Pool(Pool<T>& other) = delete;
    Pool<T> operator=(Pool<T> const& other) = delete;

    Pool(MakeFunc make, size_t min = 1, size_t max = 10)
    {
        Reconfigure(make, min, max);
    }
    ~Pool() {}

    // Clear out current pool. Useful to call after Reconfigure() if the
    // MakeFunc changed.
    void Clean()
    {
        std::lock_guard<std::mutex> lock(m_pool_mtx);

        // Remake the whole pool because we can't know what the
        // new initializer does different.
        while (!m_pool_available.empty())
            m_pool_available.pop();
    }

    // (Re)-Configure this pool.
    //  - make() needs to return a T.
    //  - min is the minimum amount of T to keep around
    //  - max is a upper limit of idle connections the pool can hold
    //    Any returned above that are discarded.
    void Reconfigure(MakeFunc make, size_t min = 1, size_t max = 10)
    {
        ASSERT(min < max);

        std::lock_guard<std::mutex> lock(m_pool_mtx);

        m_make = make;
        m_min = min;
        m_max = max;

        LOG_INFO("Pool reconfigured: min=%d, max=%d", m_min, m_max);
    }

    // Borrow a T with a function, ensuring it gets put back into to the pool
    // after returning from your callback.
    template <typename Ret>
    Ret Borrow(std::function<Ret(T&)> borrower)
    {
        Contained inst = Take();
        SCOPEGUARD(
            if (inst)
                Give(std::move(inst));
            // else: borrower ate pointer somehow
        );
        return borrower(*inst.get());
    }

    // Takes a T out of the pool. You do not neccessarily give it back.
    Contained Take()
    {
        std::lock_guard<std::mutex> lock(m_pool_mtx);

        while (m_pool_available.size() < 1 + m_min)
        {
            m_pool_available.push(m_make());
            LOG_DEBUG("Pool exhausted, making new; pool at: %d", m_pool_available.size());
        }

        auto inst = std::move(m_pool_available.front());
        m_pool_available.pop();

        return inst;
    }

    // Give a T to the pool.
    // The pool doesn't really care if it once had this T in the past or
    // if it was created with the MakeFunc given.
    // The pool makes no promises to accept or keep it.
    void Give(Contained t)
    {
        std::lock_guard<std::mutex> lock(m_pool_mtx);

        if (m_pool_available.size() < m_max)
            m_pool_available.push(std::move(t));
    }

private:

    std::mutex m_pool_mtx;

    std::queue<Contained> m_pool_available;

    MakeFunc m_make;
    size_t m_min;
    size_t m_max;
};
