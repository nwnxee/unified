#pragma once

#include "Common.hpp"

namespace Tweaks {

class HideClassesOnCharList
{
public:
    HideClassesOnCharList(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage*, PlayerID, ObjectID, int32_t);
};

}
