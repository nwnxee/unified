#pragma once

#include "nwnx.hpp"

namespace Profiler {

class NetMessages
{
public:
    NetMessages(NWNXLib::Services::MetricsProxy* metrics);

private:
    static int32_t ComputeGameObjectUpdateForCategoryHook(CNWSMessage*, uint32_t, uint32_t, CNWSPlayer*, CNWSObject*,
                                                          CGameObjectArray*, CNWSPlayerLUOSortedObjectList*, int32_t);
    static int32_t SendServerToPlayerMessageHook(CNWSMessage*, PlayerID, uint8_t, uint8_t, uint8_t*, uint32_t);
    static void HandlePlayerToServerMessageHook(CNWSMessage*, PlayerID, uint8_t*, uint32_t);
};

}
