#pragma once

#include "nwnx.hpp"
#include <regex>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Regex {

class Regex : public NWNXLib::Plugin
{
public:
    Regex(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Regex();

private:
    ArgumentStack Search(ArgumentStack&& args);
    ArgumentStack Replace(ArgumentStack&& args);
};

}
