#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"
#include <cstdint>

namespace Events {

class DMActionEvents
{
public:
    DMActionEvents(NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patching);

private:
    static void SetExperiencePatch(NWNXLib::API::CNWSCreatureStats*, uint32_t, int32_t);
    static void AddGoldPatch(NWNXLib::API::CNWSCreature*, int32_t, int32_t);
};

}
