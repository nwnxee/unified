#pragma once

#include "BT/Interface/IComposite.hpp"

namespace BT {

class CompositeSelector : public IComposite
{
public:
    template <typename ... Args>
    CompositeSelector(Args ... args) : IComposite(args ...) { }

    virtual ~CompositeSelector() override {}

protected:
    virtual TaskStatus Run() override
    {
        for (auto& child : m_children)
        {
            const TaskStatus status = child->Tick();

            if (status != TaskStatus::FAILURE)
            {
                return status;
            }
        }

        return TaskStatus::FAILURE;
    }

    virtual void End(TaskStatus) override
    {
        for (auto& child : m_children)
        {
            Reset(*child);
        }
    }
};

}
