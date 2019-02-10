#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "API/CNWSCreature.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class FeatEvents
{
public:
    FeatEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
        static int32_t UseFeatHook
        (
            NWNXLib::API::CNWSCreature* thisPtr,
            uint16_t nFeat,
            uint16_t nSubFeat,
            NWNXLib::API::Types::ObjectID oidTarget,
            NWNXLib::API::Types::ObjectID oidArea,
            NWNXLib::API::Vector* pvTarget
        );
};

}
