#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class MaxLevel
{
public:
    MaxLevel(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker, uint8_t maxLevel);

private:
    static void ReloadAllHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWRules* rules);
    static int32_t CNWSCreatureStats__CanLevelUp_hook(NWNXLib::API::CNWSCreatureStats*);
    static NWNXLib::Hooking::FunctionHook* pCanLevelUp_hook;
    static uint8_t m_maxLevel;
    static uint32_t m_nExperienceTableAdded[20];
};

}
