#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class EffectEvents
{
public:
    EffectEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void HandleEffectHook(const std::string&, bool, CNWSObject*, CGameEffect*);
    static int32_t OnEffectAppliedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    static int32_t OnEffectRemovedHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
};

}
