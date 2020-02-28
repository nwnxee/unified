#include "Factions.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CFactionManager.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Item::Item* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
  {
    "Factions",
    "Ability to interact with factions of creatures via Id",
    "Baaleos / Golot",
    "baaleos at azmodan.net",
    1,
    true
  };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
	g_plugin = new Factions::Factions(params);
    return g_plugin;
}


namespace Factions {

Factions::Factions(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetFaction);
    REGISTER(GetFaction);
    

#undef REGISTER
}

Item::~Factions()
{
}




ArgumentStack Factions::SetFaction(ArgumentStack&& args)
{
	int32_t retVal = -1;

		const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);
		if (objectId == Constants::OBJECT_INVALID)
		    {
		        LOG_NOTICE("NWNX_Faction SetFaction called on OBJECT_INVALID");
		    }else if (auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId))
	        {
	  		  const auto nFacId = Services::Events::ExtractArgument<int32_t>(args);
	  		  auto* pFaction= Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFaction(nFacId);
	  		  if (pFaction){
	  		      pFaction->AddMember(objectId);
	  			  retVal = 1;
	  		  }
			
	        }
	    return Services::Events::Arguments(retVal);
}


ArgumentStack Factions::GetFaction(ArgumentStack&& args)
{
    int32_t retVal = -1;
	if (auto *pCreature = Creature(args))
		    {
		        auto *faction = pCreature->GetFaction();
				retVal = faction->m_nFactionId;
		    }
    return Services::Events::Arguments(retVal);
}


}
