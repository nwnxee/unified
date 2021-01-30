#pragma once

#include "nwnx.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo;
class AdjustReputationFix;
class DisableLevelUpValidation;
class UnhardcodeRangerDualWield;

class Experimental : public NWNXLib::Plugin
{
public:
    Experimental(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Experimental();

private:
    std::unique_ptr<SuppressPlayerLoginInfo> m_SuppressPlayerLoginInfo;
    std::unique_ptr<AdjustReputationFix> m_AdjustReputationFix;
    std::unique_ptr<DisableLevelUpValidation> m_DisableLevelUpValidation;
    std::unique_ptr<UnhardcodeRangerDualWield> m_UnhardcodeRangerDualWield;
};

}
