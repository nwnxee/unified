#include "Services/Tasks/Tasks.hpp"

#include <algorithm>
#include <chrono>

namespace NWNXLib::Services {

AsyncWorkerThread::AsyncWorkerThread(Tasks& manager)
    : m_manager(manager),
      m_stop(false),
      m_finished(false)
{
    m_thread = std::make_unique<std::thread>(&ThreadFunc, this);
}

AsyncWorkerThread::~AsyncWorkerThread()
{
    m_thread->join();
}

void AsyncWorkerThread::Stop()
{
    m_stop = true;
}

bool AsyncWorkerThread::IsFinished()
{
    return m_finished;
}

void AsyncWorkerThread::ThreadFunc(AsyncWorkerThread* owner)
{
    while (!owner->m_stop)
    {
        owner->m_manager.ProcessWorkOnAsyncThread();
        owner->m_manager.BlockUntilAsyncWorkReady(owner->m_stop);
    }

    owner->m_finished = true;
}

Tasks::Tasks()
{
    for (size_t i = 0; i < WORKER_COUNT; ++i)
    {
        m_asyncWorkers.emplace_back(std::make_unique<AsyncWorkerThread>(*this));
    }
}

Tasks::~Tasks()
{
    for (auto& worker : m_asyncWorkers)
    {
        // Signal all threads to stop.
        worker->Stop();
    }

    for (auto& worker : m_asyncWorkers)
    {
        // Continue trying to wake them up until they have all stopped.
        while (!worker->IsFinished())
        {
            std::unique_lock<std::mutex> signalLock(m_asyncThreadLock);
            m_asyncSignal.notify_all();
            std::this_thread::yield();
        }
    }

    m_asyncWorkers.clear(); // Blocks until all threads joined.
}

Tasks::ThreadWorkToken Tasks::QueueWork(Tasks::ThreadWorkItem&& work, Tasks::ThreadWorkList& list, std::mutex& lock)
{
    auto listItem = ThreadWorkListItem(std::forward<ThreadWorkItem>(work));
    auto token = listItem.get_future();
    std::lock_guard<std::mutex> scopeLock(lock);
    list.emplace_back(std::move(listItem));
    return token;
}

Tasks::ThreadWorkToken Tasks::QueueOnMainThread(Tasks::ThreadWorkItem&& work)
{
    return QueueWork(std::forward<ThreadWorkItem>(work), m_mainThreadWork, m_mainThreadLock);
}

Tasks::ThreadWorkToken Tasks::QueueOnAsyncThread(Tasks::ThreadWorkItem&& work)
{
    auto token = QueueWork(std::forward<ThreadWorkItem>(work), m_asyncThreadWork, m_asyncThreadLock);
    std::unique_lock<std::mutex> signalLock(m_asyncThreadLock);
    m_asyncSignal.notify_one();
    return token;
}

void Tasks::ProcessWork(Tasks::ThreadWorkList& work, std::mutex& lock)
{
    ThreadWorkList localWork;

    {
        std::lock_guard<std::mutex> scopeLock(lock);
        std::swap(work, localWork);
    }

    for (ThreadWorkListItem& workItem : localWork)
    {
        workItem();
    }
}

void Tasks::ProcessWorkOnMainThread()
{
    ProcessWork(m_mainThreadWork, m_mainThreadLock);
}

void Tasks::ProcessWorkOnAsyncThread()
{
    ProcessWork(m_asyncThreadWork, m_asyncThreadLock);
}

void Tasks::BlockUntilAsyncWorkReady(const bool& abort)
{
    std::unique_lock<std::mutex> signalLock(m_asyncThreadLock);
    auto cnd = [&abort, this] { return abort || !m_asyncThreadWork.empty(); };
    if (cnd()) { return; } // Don't wait needlessly if the queue isn't empty.
    m_asyncSignal.wait_for(signalLock, std::chrono::seconds(1), cnd); // Wait 1s max, just in case.
}

TasksProxy::TasksProxy(Tasks& tasks)
    : ServiceProxy<Tasks>(tasks)
{
    GetDestroyLocks().first = false;
}

TasksProxy::~TasksProxy()
{
    std::unique_lock<std::shared_mutex> scopeDestroyLock(GetDestroyLocks().second);
    m_proxyBase.ProcessWorkOnMainThread(); // We process work here to clear up all of our queued tasks.
    std::for_each(std::begin(m_work), std::end(m_work), [](auto& work) { work.wait(); });
    m_work.clear();
    GetDestroyLocks().first = true;
}

std::pair<bool, std::shared_mutex>& TasksProxy::GetDestroyLocks()
{
    // This keeps a map between pointers and { destroyedState, sharedMutex }.
    // This is needed because it's entirely possible depending on thread sleep times for
    // one thread to queue work, pause thread before acquiring lock, the other thread to
    // destroy the TasksProxy completely, then the first thread resumes and acquires a
    // shared mutex in invalid memory and queues up another task.
    static std::unordered_map<TasksProxy*, std::pair<bool, std::shared_mutex>> s_destroyLocks;
    return s_destroyLocks[this];
}

void TasksProxy::QueueOnThreadInternal(Tasks::ThreadWorkItem&& work,
    Tasks::ThreadWorkToken(Tasks::*func)(Tasks::ThreadWorkItem&&),
    bool blocking)
{
    std::shared_lock<std::shared_mutex> scopeDestroyLock(GetDestroyLocks().second, std::try_to_lock);

    // Check if this TasksProxy is already destroyed, or if we failed to acquire the lock.
    // In either case, we've either been destroyed OR we're about to be, so we want to bail.
    if (GetDestroyLocks().first || !scopeDestroyLock.owns_lock())
    {
        // We're already being destroyed, so we just need to bail.
        return;
    }

    auto token = (m_proxyBase.*func)(std::forward<Tasks::ThreadWorkItem>(work));

    if (blocking)
    {
        token.wait();
    }

    std::lock_guard<std::mutex> scopeLock(m_lock);
    m_work.emplace_back(std::move(token));
    ClearFinishedTasks();
}

void TasksProxy::QueueOnMainThread(Tasks::ThreadWorkItem&& work)
{
    QueueOnThreadInternal(std::forward<Tasks::ThreadWorkItem>(work), &Tasks::QueueOnMainThread, false);
}

void TasksProxy::QueueOnAsyncThread(Tasks::ThreadWorkItem&& work)
{
    QueueOnThreadInternal(std::forward<Tasks::ThreadWorkItem>(work), &Tasks::QueueOnAsyncThread, false);
}

void TasksProxy::QueueOnMainThreadBlocking(Tasks::ThreadWorkItem&& work)
{
    QueueOnThreadInternal(std::forward<Tasks::ThreadWorkItem>(work), &Tasks::QueueOnMainThread, true);
}

void TasksProxy::QueueOnAsyncThreadBlocking(Tasks::ThreadWorkItem&& work)
{
    QueueOnThreadInternal(std::forward<Tasks::ThreadWorkItem>(work), &Tasks::QueueOnAsyncThread, true);
}

void TasksProxy::ClearFinishedTasks()
{
    // Lock should always be acquired before entering here.
    auto iter = std::begin(m_work);
    while (iter != std::end(m_work))
    {
        const bool finished = iter->wait_for(std::chrono::seconds(0)) == std::future_status::ready;
        iter = finished ? m_work.erase(iter) : std::next(iter);
    }
}

}
