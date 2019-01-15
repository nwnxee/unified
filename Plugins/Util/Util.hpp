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

};

}
