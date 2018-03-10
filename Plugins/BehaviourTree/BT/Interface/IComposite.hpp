#pragma once

#include "BT/Interface/ITask.hpp"
#include <memory>
#include <vector>

namespace BT {

class IComposite : public ITask
{
public:
    IComposite(const std::vector<ITask*>& children)
    {
        for (auto& child: children)
        {
            m_children.push_back(std::unique_ptr<ITask>(child));
        }
    }

    template <typename ... Args>
    IComposite(Args ... args)
    {
        std::initializer_list<ITask*> children = { args ... };
        for (auto& child : children)
        {
            m_children.push_back(std::unique_ptr<ITask>(child));
        }
    }

    virtual ~IComposite() {}

protected:
    std::vector<std::unique_ptr<ITask>> m_children;
    virtual TaskStatus Run() = 0;
};

}
