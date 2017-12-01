#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

#include <cstdint>

namespace Optimizations {

class SortObjectsForGameObjectUpdateOptimization
{
public:
    SortObjectsForGameObjectUpdateOptimization(const uint32_t flushCount, NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher);

private:
    static NWNXLib::API::CLastUpdateObject* GetLastUpdateObjectHook(NWNXLib::API::CNWSPlayer*, NWNXLib::API::Types::ObjectID);
};

}
