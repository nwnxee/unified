#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Visibility {

class Visibility : public NWNXLib::Plugin
{
public:
    Visibility(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Visibility();

private:
    static int32_t TestObjectVisibleHook(CNWSMessage*, CNWSObject*, CNWSObject*);
    static int32_t GetGlobalOverride(ObjectID);
    static int32_t GetPersonalOverride(ObjectID, ObjectID);

    ArgumentStack GetVisibilityOverride (ArgumentStack&&);
    ArgumentStack SetVisibilityOverride (ArgumentStack&&);
};

}
