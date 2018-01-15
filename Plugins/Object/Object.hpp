#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSObject.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Object {

class Object : public NWNXLib::Plugin
{
public:
    Object(const Plugin::CreateParams& params);
    virtual ~Object();

private:
    ArgumentStack GetLocalVariableCount(ArgumentStack&& args);
    ArgumentStack GetLocalVariable     (ArgumentStack&& args);
    ArgumentStack StringToObject       (ArgumentStack&& args);
    ArgumentStack GetEventHandler      (ArgumentStack&& args);
    ArgumentStack SetEventHandler      (ArgumentStack&& args);
    ArgumentStack SetPosition          (ArgumentStack&& args);
    ArgumentStack SetCurrentHitPoints  (ArgumentStack&& args);
    ArgumentStack SetMaxHitPoints      (ArgumentStack&& args);
    ArgumentStack GetPortrait          (ArgumentStack&& args);
    ArgumentStack SetPortrait          (ArgumentStack&& args);
    ArgumentStack Serialize            (ArgumentStack&& args);
    ArgumentStack Deserialize          (ArgumentStack&& args);
    ArgumentStack GetDialogResref      (ArgumentStack&& args);

    NWNXLib::API::CNWSObject *object(ArgumentStack& args);

};

}
