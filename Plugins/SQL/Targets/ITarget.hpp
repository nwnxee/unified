#pragma once

#include "Common.hpp"
#include "Maybe.hpp"
#include "ViewPtr.hpp"

#include <queue>
#include <string>
#include <vector>

namespace SQL {

using Query = std::string;
using Result = std::string;
using ResultRow = std::vector<Result>;
using ResultSet = std::queue<ResultRow>; // Queue is row, vector is column

struct ITarget
{
    virtual ~ITarget() { }
    virtual void Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config) = 0;
    virtual bool IsConnected() = 0;
    virtual NWNXLib::Maybe<ResultSet> ExecuteQuery(const Query& query) = 0;
};

}
