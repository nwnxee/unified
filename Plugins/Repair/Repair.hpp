#pragma once

#include "Plugin.hpp"
#include <memory>

namespace Repair {

class DDoS;
class ResolveSpecialAttackDamageBonus;
class SpawnInHeartbeatPerception;

class Repair : public NWNXLib::Plugin
{
public:
    Repair(const Plugin::CreateParams& params);
    virtual ~Repair();

private:
    std::unique_ptr<DDoS> m_ddosTarget;
    std::unique_ptr<ResolveSpecialAttackDamageBonus> m_resolveSpecialAttackDamageBonusTarget;
    std::unique_ptr<SpawnInHeartbeatPerception> m_spawnInHeartbeatPerceptionTarget;
};

}
