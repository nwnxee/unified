#pragma once

#include "BT/Interface/IDecorator.hpp"

namespace BT {

class DecoratorInvert : public IDecorator
{
public:
    DecoratorInvert(ITask* task) : IDecorator(task)  {}
    virtual ~DecoratorInvert() override { }

protected:
    virtual TaskStatus Run() override
    {
        const TaskStatus status = m_child->Tick();

        if (status == TaskStatus::FAILURE)
        {
            return TaskStatus::SUCCESS;
        }
        else if (status == TaskStatus::SUCCESS)
        {
            return TaskStatus::FAILURE;
        }

        return status;
    }
};

}
