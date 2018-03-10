#pragma once

namespace BT {

enum class TaskStatus
{
    // Failure reflects a failure of the task.
    // The task ran but the intended action did not succeed.
    FAILURE,

    // Success reflects the success of the task.
    // The task ran and completed its action successfully.
    SUCCESS,

    // Running reflects a task that is still in progress.
    // The task is current running.
    RUNNING
};

class ITask
{
public:
    ITask() : m_init(false) {}
    virtual ~ITask() {}

    // Tick should, in most cases, be called, rather than calling the various interface functions directly.
    // This handles calling Init, Run, and End automatically.
    TaskStatus Tick()
    {
        if (!m_init)
        {
            Init();
            m_init = true;
        }

        const TaskStatus status = Run();

        if (status == TaskStatus::FAILURE || status == TaskStatus::SUCCESS)
        {
            End(status);
        }

        return status;
    }

protected:
    // Init is called the first time this node has been processed in this tree.
    // This function is optional.
    virtual void Init() {}

    // Run is called for every tick of the behaviour tree. It should retunn a TaskStatus.
    // This function must be implemented.
    virtual TaskStatus Run() = 0;

    // End is called whenever the task returns success or failure.
    // This function is optional.
    virtual void End(TaskStatus) {}

    // Reset is called whenever the parent task returns success or failure.
    // This function is optional.
    virtual void Reset() {}

    // These functions allow us to bypass the C++ rule which states that derived classes may only access
    // protected members of the base class if through a pointer to the derives class or further down.
    static void Init(ITask& task) { return task.Init(); }
    static TaskStatus Run(ITask& task) { return task.Run(); }
    static void End(ITask& task, TaskStatus status) { return task.End(status); }
    static void Reset(ITask& task) { return task.Reset(); }

private:
    bool m_init;
};

}
