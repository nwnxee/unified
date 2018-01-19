#pragma once

#include "BT/Interface/IComposite.hpp"

namespace BT {

class CompositeSequence : public IComposite
{
public:
    template <typename ... Args>
    CompositeSequence(Args ... args) : IComposite(args ...) { }

    virtual ~CompositeSequence() {};

protected:
    virtual TaskStatus Run() override
    {
        for (auto& child : m_children)
        {
            const TaskStatus status = child->Tick();

            if (status != TaskStatus::SUCCESS)
            {
                return status;
            }
        }

        return TaskStatus::SUCCESS;
    }

    virtual void End(TaskStatus status)
    {
        for (auto& child : m_children)
        {
            Reset(*child);
        }
    }
};

}
