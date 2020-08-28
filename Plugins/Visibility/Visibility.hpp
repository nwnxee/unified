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

    static int32_t TestObjectVisibleHook(CNWSMessage *pThis, CNWSObject *pAreaObject, CNWSObject *pPlayerGameObject);
    NWNXLib::Hooking::FunctionHook* m_TestObjectVisibilityHook;

    static int32_t GetGlobalOverride(ObjectID targetId);
    static int32_t GetPersonalOverride(ObjectID playerId, ObjectID targetId);

    ArgumentStack GetVisibilityOverride (ArgumentStack&& args);
    ArgumentStack SetVisibilityOverride (ArgumentStack&& args);
};

}
