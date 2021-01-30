#pragma once

#include "nwnx.hpp"

namespace Events {

class MaterialChangeEvents
{
public:
    MaterialChangeEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void SetPositionHook(CNWSObject*, Vector, int32_t);
};

}
