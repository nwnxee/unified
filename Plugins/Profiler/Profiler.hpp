#pragma once

#include "nwnx.hpp"
#include <chrono>
#include <memory>

namespace Profiler {

class AIMasterUpdates;
class MainLoop;
class NetLayer;
class NetMessages;
class ObjectAIUpdates;
class ObjectEventHandlers;
class Pathing;
class Scripts;

class Profiler : public NWNXLib::Plugin
{
public:
    Profiler(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Profiler();

private:
    std::unique_ptr<AIMasterUpdates> m_aiMasterUpdates;
    std::unique_ptr<MainLoop> m_mainLoop;
    std::unique_ptr<NetLayer> m_netLayer;
    std::unique_ptr<NetMessages> m_netMessages;
    std::unique_ptr<ObjectAIUpdates> m_objectAIUpdates;
    std::unique_ptr<ObjectEventHandlers> m_objectEventHandlers;
    std::unique_ptr<Pathing> m_pathing;
    std::unique_ptr<Scripts> m_scripts;

    static void HandleTickrateReporting(const std::chrono::time_point<std::chrono::high_resolution_clock>& now);
    static void HandleRecalibration(const std::chrono::time_point<std::chrono::high_resolution_clock>& now);

    static int32_t MainLoopUpdate(CServerExoAppInternal*);

    void SetPerfScopeResampler(const std::string& name);
    void PushPerfScope(std::string&& name, NWNXLib::Services::MetricData::Tags&& tags);
    void PopPerfScope();
};

}
