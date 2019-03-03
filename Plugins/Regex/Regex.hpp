#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"

#include <regex>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Regex {

class Regex : public NWNXLib::Plugin
{
public:
    Regex(const Plugin::CreateParams& params);
    virtual ~Regex();

private:
    ArgumentStack Search(ArgumentStack&& args);
    ArgumentStack Replace(ArgumentStack&& args);
};

}
