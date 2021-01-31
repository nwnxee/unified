#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace ItemProperty {

class ItemProperty : public NWNXLib::Plugin
{
public:
    ItemProperty(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ItemProperty();

private:

    ArgumentStack PackIP(ArgumentStack&& args);
    ArgumentStack UnpackIP(ArgumentStack&& args);
    ArgumentStack GetActiveProperty(ArgumentStack&& args);

};

}
