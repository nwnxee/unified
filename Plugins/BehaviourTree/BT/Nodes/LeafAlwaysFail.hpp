#pragma once

#include "BT/Interface/ILeaf.hpp"

namespace BT {

class LeafAlwaysFail : public ILeaf
{
public:
    LeafAlwaysFail() {}
    virtual ~LeafAlwaysFail() override {}

protected:
    virtual TaskStatus Run() override
    {
        return TaskStatus::FAILURE;
    }
};

}
