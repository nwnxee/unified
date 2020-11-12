#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

    class FactionEvents
    {
    public:
        FactionEvents(NWNXLib::Services::HooksProxy* hooker);

    private:
        static void HandleSetNPCFactionReputationHook(CFactionManager*, int32_t, int32_t, int32_t);
    };

}
