#pragma once

#include "BT/Interface/ILeaf.hpp"

namespace BT {

class LeafAlwaysSucceed : public ILeaf
{
public:
    LeafAlwaysSucceed() {}
    virtual ~LeafAlwaysSucceed() override {}

protected:
    virtual TaskStatus Run() override
    {
        return TaskStatus::SUCCESS;
    }
};

}
