#pragma once

#include "nwnx.hpp"
namespace Ruby {

class Ruby : public NWNXLib::Plugin
{
public:
    Ruby(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Ruby();

    NWNXLib::ArgumentStack Evaluate(NWNXLib::ArgumentStack&& args);

private:
    bool m_evaluateMetrics;
    int32_t m_nextEvaluationId;

    void SafeRequire(const std::string& script);
    void HandleError(const int errCode);
};

}
