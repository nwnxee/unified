#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Profiler {

class NetMessages
{
public:
    NetMessages(NWNXLib::Services::HooksProxy* hooker,
        NWNXLib::Services::MetricsProxy* metrics);

private:
    static void ComputeGameObjectUpdateForCategory(bool, CNWSMessage*, uint32_t, uint32_t, CNWSPlayer*, CNWSObject*, CGameObjectArray*, CNWSPlayerLUOSortedObjectList*, int32_t);
    static void SendServerToPlayerMessageHook(bool, CNWSMessage*, NWNXLib::API::Types::PlayerID, uint8_t, uint8_t, uint8_t*, uint32_t);
    static void HandlePlayerToServerMessageHook(bool, CNWSMessage*, NWNXLib::API::Types::PlayerID, uint8_t*, uint32_t);
};

}
