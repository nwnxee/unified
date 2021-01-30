#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class EffectEvents
{
public:
    EffectEvents();

private:
    static void HandleEffectHook(const std::string&, bool, CNWSObject*, CGameEffect*);
    static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    static int32_t OnEffectRemovedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
};

}
