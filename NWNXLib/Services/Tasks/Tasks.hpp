#pragma once

#include "Services/Services.hpp"

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <unordered_map>
#include <vector>

namespace NWNXLib::Services {

class Tasks;

class AsyncWorkerThread
{
public:
    AsyncWorkerThread(Tasks& manager);
    ~AsyncWorkerThread();

    void Stop();
    bool IsFinished();

    static void ThreadFunc(AsyncWorkerThread* owner);

private:
    Tasks& m_manager;
    std::unique_ptr<std::thread> m_thread;
    bool m_stop;
    bool m_finished;
};

class Tasks
{
public: // Structures
    using ThreadWorkItem = std::function<void()>;
    using ThreadWorkToken = std::future<void>;

public:
    Tasks();
    ~Tasks();

    ThreadWorkToken QueueOnMainThread(ThreadWorkItem&& work);
    ThreadWorkToken QueueOnAsyncThread(ThreadWorkItem&& work);

    void ProcessWorkOnMainThread();

private: // Structures
    using ThreadWorkListItem = std::packaged_task<void()>;
    using ThreadWorkList = std::vector<ThreadWorkListItem>;

private:
    static constexpr size_t WORKER_COUNT = 1;

    std::vector<std::unique_ptr<AsyncWorkerThread>> m_asyncWorkers;
    std::condition_variable m_asyncSignal;

    ThreadWorkList m_mainThreadWork;
    ThreadWorkList m_asyncThreadWork;

    std::mutex m_mainThreadLock;
    std::mutex m_asyncThreadLock;

    ThreadWorkToken QueueWork(ThreadWorkItem&& work, ThreadWorkList& list, std::mutex& lock);
    void ProcessWork(Tasks::ThreadWorkList& work, std::mutex& lock);

    friend class AsyncWorkerThread;
    void ProcessWorkOnAsyncThread();
    void BlockUntilAsyncWorkReady(const bool& abort);
};

class TasksProxy : public ServiceProxy<Tasks>
{
public:
    TasksProxy(Tasks& tasks);
    ~TasksProxy();

    void QueueOnMainThread(Tasks::ThreadWorkItem&& work);
    void QueueOnAsyncThread(Tasks::ThreadWorkItem&& work);
    void QueueOnMainThreadBlocking(Tasks::ThreadWorkItem&& work);
    void QueueOnAsyncThreadBlocking(Tasks::ThreadWorkItem&& work);

private:
    std::mutex m_lock;
    std::vector<Tasks::ThreadWorkToken> m_work;

    std::pair<bool, std::shared_mutex>& GetDestroyLocks();

    void QueueOnThreadInternal(Tasks::ThreadWorkItem&& work,
        Tasks::ThreadWorkToken(Tasks::*func)(Tasks::ThreadWorkItem&&),
        bool blocking);

    void ClearFinishedTasks();
};

}
