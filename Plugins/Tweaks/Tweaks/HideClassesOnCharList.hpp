#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class HideClassesOnCharList
{
public:
    HideClassesOnCharList(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(
        NWNXLib::API::CNWSMessage*, NWNXLib::API::Types::PlayerID,
        NWNXLib::API::Types::ObjectID, int32_t);
};

}
