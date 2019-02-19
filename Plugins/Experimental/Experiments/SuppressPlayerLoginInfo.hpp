#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo
{
public:
    SuppressPlayerLoginInfo(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t SendServerToPlayerPlayerList_AddHook(NWNXLib::API::CNWSMessage*, uint32_t, NWNXLib::API::CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_AllHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
    static int32_t SendServerToPlayerPlayerList_DeleteHook(NWNXLib::API::CNWSMessage*, uint32_t, NWNXLib::API::CNWSPlayer*);
};

}