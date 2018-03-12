#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSItem.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Item {

class Item : public NWNXLib::Plugin
{
public:
    Item(const Plugin::CreateParams& params);
    virtual ~Item();

private:
    ArgumentStack SetWeight      (ArgumentStack&& args);

    NWNXLib::API::CNWSItem *item(ArgumentStack& args);
};

}
