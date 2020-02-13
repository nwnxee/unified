#include "Factions.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CNWSCreature.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Factions::Factions* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Factions",
        "Allows retrieval of faction id as well as changing faction by id",
        "Baaleos",
        "Baaleos@azmodan.net",
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
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetFactionId);
    REGISTER(SetFaction);

#undef REGISTER

    
}

Factions::~Factions()
{
}



ArgumentStack Factions::GetFactionId(ArgumentStack&& args)
{
	int32_t retVal = -1;
	    if (auto *pCreature = Creature(args))
	    {
	        auto *faction = pCreature->GetFaction();
			retVal = faction->m_nFactionId;
	    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Factions::SetFaction(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pObject = Object(args))
    {
        
		  
		  const auto nFacId = Services::Events::ExtractArgument<int32_t>(args);
		  auto* pFactionManager= Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager;
		  auto* pFaction = pFactionManager->GetFaction(nFacId);
		  if (pFaction){
		      pFaction->AddMember(pObject);
			  retVal = 1;
		  }

        
    }

    return Services::Events::Arguments(retVal);
}

}
