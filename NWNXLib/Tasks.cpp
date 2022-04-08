#include "nwnx.hpp"
#include "../Core/NWNXCore.hpp"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

namespace NWNXLib::Tasks
{

struct LockedQueue
{
    void Push(WorkItem&& work)
    {
        std::lock_guard<std::mutex> lg(m_lock);
        m_queue.emplace(work);
    }
    std::optional<WorkItem> Pop()
    {
        std::lock_guard<std::mutex> lg(m_lock);
        if (m_queue.empty())
            return std::optional<WorkItem>();

        auto work = std::make_optional<WorkItem>(m_queue.front());
        m_queue.pop();
        return work;
    }
    bool Empty()
    {
        std::lock_guard<std::mutex> lg(m_lock);
        return m_queue.empty();
    }
private:
    std::queue<WorkItem> m_queue;
    std::mutex m_lock;
};

static LockedQueue s_mainThreadQueue;
static LockedQueue s_asyncThreadQueue;

static std::condition_variable s_asyncSignal;
static std::mutex s_asyncSignalLock;

void QueueOnMainThread(WorkItem&& work)
{
    s_mainThreadQueue.Push(std::forward<WorkItem>(work));
}
void QueueOnAsyncThread(WorkItem&& work)
{
    s_asyncThreadQueue.Push(std::forward<WorkItem>(work));
    std::unique_lock<std::mutex> signalLock(s_asyncSignalLock);
    s_asyncSignal.notify_one();
}

void ProcessMainThreadWork()
{
    while (auto work = s_mainThreadQueue.Pop())
    {
        (*work)();
    }
}

static bool s_shutdown = false;
void AsyncWorkerThread()
{
    while (!s_shutdown)
    {
        while (auto work = s_asyncThreadQueue.Pop())
        {
            (*work)();
        }

        std::unique_lock<std::mutex> signalLock(s_asyncSignalLock);
        s_asyncSignal.wait_for(signalLock,
            std::chrono::seconds(1),
            []{ return s_shutdown || !s_asyncThreadQueue.Empty(); }); 
    }
}

static std::thread* s_asyncWorker;
void StartAsyncWorkers()
{
    s_asyncWorker = new std::thread(AsyncWorkerThread);
}
void StopAsyncWorkers()
{
    s_shutdown = true;
    s_asyncWorker->join();
}


}
