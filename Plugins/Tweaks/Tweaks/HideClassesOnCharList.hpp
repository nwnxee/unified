#pragma once

#include "API/Types.hpp"
#include "Common.hpp"

namespace Tweaks {

class HideClassesOnCharList
{
public:
    HideClassesOnCharList(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(
        CNWSMessage*, NWNXLib::API::Types::PlayerID,
        NWNXLib::API::Types::ObjectID, int32_t);
};

}
