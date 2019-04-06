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
    ArgumentStack SetPosition          (ArgumentStack&& args);
    ArgumentStack SetCurrentHitPoints  (ArgumentStack&& args);
    ArgumentStack SetMaxHitPoints      (ArgumentStack&& args);
    ArgumentStack Serialize            (ArgumentStack&& args);
    ArgumentStack Deserialize          (ArgumentStack&& args);
    ArgumentStack GetDialogResref      (ArgumentStack&& args);
    ArgumentStack SetDialogResref      (ArgumentStack&& args);
    ArgumentStack SetAppearance        (ArgumentStack&& args);
    ArgumentStack GetAppearance        (ArgumentStack&& args);
    ArgumentStack GetHasVisualEffect   (ArgumentStack&& args);
    ArgumentStack CheckFit             (ArgumentStack&& args);
    ArgumentStack GetDamageImmunity    (ArgumentStack&& args);
    ArgumentStack AddToArea            (ArgumentStack&& args);
    ArgumentStack GetPlaceableIsStatic (ArgumentStack&& args);
    ArgumentStack SetPlaceableIsStatic (ArgumentStack&& args);

    NWNXLib::API::CNWSObject *object(ArgumentStack& args);

};

}
