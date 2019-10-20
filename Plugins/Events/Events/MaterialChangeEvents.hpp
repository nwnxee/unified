#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class MaterialChangeEvents
{
public:
    MaterialChangeEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void SetPositionHook(NWNXLib::Services::Hooks::CallType, CNWSObject*, Vector, int32_t);
};

}
