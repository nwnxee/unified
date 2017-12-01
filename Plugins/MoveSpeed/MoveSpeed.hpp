#pragma once

#include "API/Types.hpp"
#include "Plugin.hpp"
#include <unordered_map>

namespace MoveSpeed {

class MoveSpeed : public NWNXLib::Plugin
{
public:
    MoveSpeed(const Plugin::CreateParams& params);
    virtual ~MoveSpeed();

private:
    std::unordered_map<NWNXLib::API::Types::ObjectID, bool> m_simulateDetectMap;
    std::unordered_map<NWNXLib::API::Types::ObjectID, bool> m_capWalkSpeedMap;

    static void SimulateDetectInlineHook(NWNXLib::API::CNWSCreature* creature, int* limitCount);
    static float GetWalkRateHook(NWNXLib::API::CNWSCreature* creature);
};

}
