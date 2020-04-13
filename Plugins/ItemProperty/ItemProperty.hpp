#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace ItemProperty {

class ItemProperty : public NWNXLib::Plugin
{
public:
    ItemProperty(const Plugin::CreateParams& params);
    virtual ~ItemProperty();

private:

    ArgumentStack PackIP(ArgumentStack&& args);
    ArgumentStack UnpackIP(ArgumentStack&& args);
};

}
