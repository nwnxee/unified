#pragma once

#include "API/Types.hpp"
#include "API/CGameObject.hpp"
#include <string>


namespace NWNXLib {
namespace Utils {

std::string ObjectIDToString(const API::Types::ObjectID id);

std::string GetCurrentScript();
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner);

// Since there's no RTTI, and NWN's dynamic casts don't work in NWNX.
// These return nullptr if the object type isn't right.
API::CNWSArea*               AsNWSArea(API::CGameObject* obj);
API::CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(API::CGameObject* obj);
API::CNWSCreature*           AsNWSCreature(API::CGameObject* obj);
API::CNWSDoor*               AsNWSDoor(API::CGameObject* obj);
API::CNWSEncounter*          AsNWSEncounter(API::CGameObject* obj);
API::CNWSItem*               AsNWSItem(API::CGameObject* obj);
API::CNWSModule*             AsNWSModule(API::CGameObject* obj);
API::CNWSObject*             AsNWSObject(API::CGameObject* obj);
API::CNWSPlaceable*          AsNWSPlaceable(API::CGameObject* obj);
API::CNWSSoundObject*        AsNWSSoundObject(API::CGameObject* obj);
API::CNWSStore*              AsNWSStore(API::CGameObject* obj);
API::CNWSTrigger*            AsNWSTrigger(API::CGameObject* obj);
API::CNWSWaypoint*           AsNWSWaypoint(API::CGameObject* obj);

}

}
