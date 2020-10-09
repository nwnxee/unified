#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class MaterialChangeEvents
{
public:
    MaterialChangeEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void SetPositionHook(bool, CNWSObject*, Vector, int32_t);
};

}
