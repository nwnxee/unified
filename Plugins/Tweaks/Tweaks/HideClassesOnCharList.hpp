#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class HideClassesOnCharList
{
public:
    HideClassesOnCharList();

private:
    static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage*, PlayerID, ObjectID, int32_t);
};

}
