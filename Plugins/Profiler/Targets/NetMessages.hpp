#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Profiler {

class NetMessages
{
public:
    NetMessages(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics);

private:
    static void ComputeGameObjectUpdateForCategory(NWNXLib::Services::Hooks::CallType,
        NWNXLib::API::CNWSMessage*,
        uint32_t,
        uint32_t,
        NWNXLib::API::CNWSPlayer*,
        NWNXLib::API::CNWSObject*,
        NWNXLib::API::CGameObjectArray*,
        NWNXLib::API::CNWSPlayerLUOSortedObjectList*,
        int32_t);

    static void SendServerToPlayerMessageHook(NWNXLib::Services::Hooks::CallType,
        NWNXLib::API::CNWSMessage*,
        NWNXLib::API::Types::PlayerID,
        uint8_t,
        uint8_t,
        uint8_t*,
        uint32_t);

    static void HandlePlayerToServerMessageHook(NWNXLib::Services::Hooks::CallType,
        NWNXLib::API::CNWSMessage*,
        NWNXLib::API::Types::PlayerID,
        uint8_t*,
        uint32_t);
};

}
