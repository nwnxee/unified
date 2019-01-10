#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "Common.hpp"
#include "API/CExoLocString.hpp"
#include "ViewPtr.hpp"

#include <unordered_map>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
  Rename(const Plugin::CreateParams& params);
  virtual ~Rename();
  
private:
  
  using ObjectIDToNameMap = std::unordered_map<NWNXLib::API::Types::ObjectID, NWNXLib::API::CExoLocString>;
  
  ObjectIDToNameMap m_ObjectIDtoRealFirstName;
  ObjectIDToNameMap m_ObjectIDtoRealLastName;
  ObjectIDToNameMap m_ObjectIDtoNameOverride;
  
  NWNXLib::API::CExoLocString m_blankLocStr;
  
  NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerPlayerList_All;
  
  static int32_t HookPlayerList(NWNXLib::API::CNWSMessage* message, NWNXLib::API::CNWSPlayer* pPlayer);
  void UpdateName(NWNXLib::API::CNWSCreature* targetObject);
  ArgumentStack SetPlayerNameOverride(ArgumentStack&& args);
   
  NWNXLib::API::CNWSPlayer *player(NWNXLib::API::Types::ObjectID playerId);
};
 
}