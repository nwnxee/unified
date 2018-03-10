#pragma once

#include "BT/Interface/ITask.hpp"

namespace BT {

class ILeaf : public ITask
{
public:
    ILeaf() {}
    virtual ~ILeaf() {}

protected:
    virtual TaskStatus Run() = 0;
};

}
