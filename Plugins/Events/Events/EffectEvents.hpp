#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class EffectEvents
{
public:
    EffectEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandleEffectHook(const std::string&, bool, CNWSObject*, CGameEffect*);
    static void OnEffectAppliedHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    static void OnEffectRemovedHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
};

}
