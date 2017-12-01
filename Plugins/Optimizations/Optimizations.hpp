#pragma once

#include "Common.hpp"
#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <memory>

namespace Optimizations {

class AIMasterOptimizations;
class BroadcastCombatStateToPartyOptimization;
class CGameObjectArrayOptimization;
class GetClientObjectByObjectIdOptimization;
class GetHRTOptimization;
class MainLoopSleepOptimization;
class SortObjectsForGameObjectUpdateOptimization;

class Optimizations : public NWNXLib::Plugin
{
public:
    Optimizations(const Plugin::CreateParams& params);
    virtual ~Optimizations();

    static void MainLoopUpdate(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerExoAppInternal*);

private:
    std::unique_ptr<AIMasterOptimizations> m_aiMasterOptimizations;
    std::unique_ptr<BroadcastCombatStateToPartyOptimization> m_broadcastCombatStateToPartyOptimization;
    std::unique_ptr<CGameObjectArrayOptimization> m_cgameObjectArrayOptimization;
    std::unique_ptr<GetClientObjectByObjectIdOptimization> m_getClientObjectByObjectIdOptimization;
    std::unique_ptr<GetHRTOptimization> m_getHRTOptimization;
    std::unique_ptr<MainLoopSleepOptimization> m_mainLoopSleepOptimization;
    std::unique_ptr<SortObjectsForGameObjectUpdateOptimization> m_sortObjectsForGameObjectUpdateOptimization;
};

}
