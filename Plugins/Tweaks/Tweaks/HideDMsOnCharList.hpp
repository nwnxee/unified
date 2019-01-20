#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class HideDMsOnCharList
{
public:
    HideDMsOnCharList(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePlayerToServerPlayModuleCharacterList_StartHook(
        NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
};

}
