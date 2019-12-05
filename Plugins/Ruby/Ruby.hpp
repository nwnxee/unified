#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

namespace Ruby {

class Ruby : public NWNXLib::Plugin
{
public:
    Ruby(const Plugin::CreateParams& params);
    virtual ~Ruby();

    NWNXLib::Services::Events::ArgumentStack Evaluate(NWNXLib::Services::Events::ArgumentStack&& args);

private:
    bool m_evaluateMetrics;
    int32_t m_nextEvaluationId;

    void SafeRequire(const std::string& script);
    void HandleError(const int errCode);
};

}
