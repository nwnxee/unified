#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class EffectEvents
{
public:
    EffectEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void HandleEffectHook(const std::string&, NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSObject*,
                                NWNXLib::API::CGameEffect*);
    static void OnEffectAppliedHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSEffectListHandler*,
                                NWNXLib::API::CNWSObject*, NWNXLib::API::CGameEffect*, int32_t);
    static void OnEffectRemovedHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSEffectListHandler*,
                                NWNXLib::API::CNWSObject*, NWNXLib::API::CGameEffect*);
};

}