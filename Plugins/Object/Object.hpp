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
    ArgumentStack GetLocalVariableCount     (ArgumentStack&& args);
    ArgumentStack GetLocalVariable          (ArgumentStack&& args);
    ArgumentStack StringToObject            (ArgumentStack&& args);
    ArgumentStack SetPosition               (ArgumentStack&& args);
    ArgumentStack SetCurrentHitPoints       (ArgumentStack&& args);
    ArgumentStack SetMaxHitPoints           (ArgumentStack&& args);
    ArgumentStack Serialize                 (ArgumentStack&& args);
    ArgumentStack Deserialize               (ArgumentStack&& args);
    ArgumentStack GetDialogResref           (ArgumentStack&& args);
    ArgumentStack SetDialogResref           (ArgumentStack&& args);
    ArgumentStack SetAppearance             (ArgumentStack&& args);
    ArgumentStack GetAppearance             (ArgumentStack&& args);
    ArgumentStack GetHasVisualEffect        (ArgumentStack&& args);
    ArgumentStack CheckFit                  (ArgumentStack&& args);
    ArgumentStack GetDamageImmunity         (ArgumentStack&& args);
    ArgumentStack AddToArea                 (ArgumentStack&& args);
    ArgumentStack GetPlaceableIsStatic      (ArgumentStack&& args);
    ArgumentStack SetPlaceableIsStatic      (ArgumentStack&& args);
    ArgumentStack GetAutoRemoveKey          (ArgumentStack&& args);
    ArgumentStack SetAutoRemoveKey          (ArgumentStack&& args);
    ArgumentStack GetTriggerGeometry        (ArgumentStack&& args);
    ArgumentStack SetTriggerGeometry        (ArgumentStack&& args);
    ArgumentStack RemoveIconEffect          (ArgumentStack&& args);
    ArgumentStack AddIconEffect             (ArgumentStack&& args);
    ArgumentStack Export                    (ArgumentStack&& args);
    ArgumentStack GetInt                    (ArgumentStack&& args);
    ArgumentStack SetInt                    (ArgumentStack&& args);
    ArgumentStack DeleteInt                 (ArgumentStack&& args);
    ArgumentStack GetString                 (ArgumentStack&& args);
    ArgumentStack SetString                 (ArgumentStack&& args);
    ArgumentStack DeleteString              (ArgumentStack&& args);
    ArgumentStack GetFloat                  (ArgumentStack&& args);
    ArgumentStack SetFloat                  (ArgumentStack&& args);
    ArgumentStack DeleteFloat               (ArgumentStack&& args);
    ArgumentStack DeleteVarRegex            (ArgumentStack&& args);
    ArgumentStack GetPositionIsInTrigger    (ArgumentStack&& args);
    ArgumentStack GetInternalObjectType     (ArgumentStack&& args);
    ArgumentStack AcquireItem               (ArgumentStack&& args);
    ArgumentStack SetFacing                 (ArgumentStack&& args);

    CNWSObject *object(ArgumentStack& args);
};

}
