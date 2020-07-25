#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Effect {

class Effect : public NWNXLib::Plugin
{
public:
    Effect(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Effect();

private:
    std::string m_effectExpiredData;
    uint32_t m_effectExpiredDepth;
    ObjectID m_effectExpiredCreator;

    ArgumentStack PackEffect(ArgumentStack&& args);
    ArgumentStack UnpackEffect(ArgumentStack&& args);
    ArgumentStack SetEffectExpiredScript(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredData(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredCreator(ArgumentStack&& args);
};

}
