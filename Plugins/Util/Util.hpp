#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Util {

class Util : public NWNXLib::Plugin
{
public:
    Util(const Plugin::CreateParams& params);
    virtual ~Util();

private:
    ArgumentStack GetCurrentScriptName(ArgumentStack&& args);
    ArgumentStack GetAsciiTableString(ArgumentStack&& args);
    ArgumentStack Hash(ArgumentStack&& args);
    ArgumentStack GetCustomToken(ArgumentStack&& args);
    ArgumentStack EffectTypeCast(ArgumentStack&& args);
    ArgumentStack GenerateUUID(ArgumentStack&& args);
    ArgumentStack StripColors(ArgumentStack&& args);
    ArgumentStack IsValidResRef(ArgumentStack&& args);
    ArgumentStack GetEnvironmentVariable(ArgumentStack&& args);
};

}
