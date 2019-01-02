#include "Encounter.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CEncounterListEntry.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"
#include "Utils.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Encounter::Encounter> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Encounter",
        "Functions exposing additional encounter properties",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Encounter::Encounter(params);
    return g_plugin;
}


namespace Encounter {

Encounter::Encounter(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Encounter::func, this, std::placeholders::_1))

    REGISTER(GetNumberOfCreaturesInEncounterList);
    REGISTER(GetEncounterCreatureByIndex);

#undef REGISTER
}

Encounter::~Encounter()
{
}

CNWSEncounter *Encounter::encounter(ArgumentStack& args)
{
    const auto encounterId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (encounterId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Encounter function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pEncounter = Globals::AppManager()->m_pServerExoApp->GetEncounterByGameObjectID(encounterId);

    if (!pEncounter)
    {
        LOG_NOTICE("NWNX_Encounter function called on non-area object %x", encounterId);
    }

    return pEncounter;
}

ArgumentStack Encounter::GetNumberOfCreaturesInEncounterList(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nNumEncounterListEntries;
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Encounter::GetEncounterCreatureByIndex(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string resRef = "";
    float cr = 0.0; 
    int32_t unique = 0;

    if (auto *pEncounter = encounter(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        
        if (index < pEncounter->m_nNumEncounterListEntries)
        {          
            resRef = pEncounter->m_pEncounterList[index].m_cCreatureResRef.GetResRefStr();
            cr = pEncounter->m_pEncounterList[index].m_fCR;
            unique = pEncounter->m_pEncounterList[index].m_bUnique;
        }
    }
    
    Services::Events::InsertArgument(stack, resRef);
    Services::Events::InsertArgument(stack, cr);
    Services::Events::InsertArgument(stack, unique);

    return stack;
}

}
