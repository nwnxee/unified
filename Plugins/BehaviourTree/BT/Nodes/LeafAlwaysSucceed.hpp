#pragma once

#include "BT/Interface/ILeaf.hpp"

namespace BT {

class LeafAlwaysSucceed : public ILeaf
{
public:
    LeafAlwaysSucceed() {}
    virtual ~LeafAlwaysSucceed() {};

protected:
    virtual TaskStatus Run() override
    {
        return TaskStatus::SUCCESS;
    }
};

}
