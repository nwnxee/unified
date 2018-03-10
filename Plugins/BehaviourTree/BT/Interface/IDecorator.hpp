#pragma once

#include "BT/Interface/ITask.hpp"
#include <memory>

namespace BT {

class IDecorator : public ITask
{
public:
    IDecorator(ITask* task) : m_child(task) {}
    virtual ~IDecorator() {}

protected:
    std::unique_ptr<ITask> m_child;
    virtual TaskStatus Run() = 0;
};

}
