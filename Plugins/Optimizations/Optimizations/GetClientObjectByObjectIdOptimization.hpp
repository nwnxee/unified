#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

#include <cstdint>

namespace Optimizations {

class GetClientObjectByObjectIdOptimization
{
public:
    GetClientObjectByObjectIdOptimization(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static NWNXLib::API::CNWSPlayer* GetClientObjectByObjectIdHook(NWNXLib::API::CServerExoAppInternal*, NWNXLib::API::Types::ObjectID);
};

}
