#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

class FeatEvents
{
public:
    FeatEvents(NWNXLib::Services::HooksProxy* hooker);

private:
        static int32_t UseFeatHook
        (
            CNWSCreature* thisPtr,
            uint16_t nFeat,
            uint16_t nSubFeat,
            ObjectID oidTarget,
            ObjectID oidArea,
            Vector* pvTarget
        );
        static int32_t HasFeatHook
        (
            CNWSCreatureStats* thisPtr,
            uint16_t nFeat
        );
};

}
