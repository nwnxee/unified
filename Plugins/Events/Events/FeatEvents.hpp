#pragma once

#include "API/Vector.hpp"
#include "API/CNWSCreature.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

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
};

}
