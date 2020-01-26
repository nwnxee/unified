#include "Encounter.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CEncounterListEntry.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Events/Events.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Encounter::Encounter* g_plugin;

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
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetNumberOfCreaturesInEncounterList);
    REGISTER(GetEncounterCreatureByIndex);
    REGISTER(SetEncounterCreatureByIndex);
    REGISTER(GetFactionId);
    REGISTER(SetFactionId);
    REGISTER(GetPlayerTriggeredOnly);
    REGISTER(SetPlayerTriggeredOnly);
    REGISTER(GetResetTime);
    REGISTER(SetResetTime);

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
        LOG_NOTICE("NWNX_Encounter function called on non-encounter object %x", encounterId);
    }

    return pEncounter;
}

ArgumentStack Encounter::GetNumberOfCreaturesInEncounterList(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nNumEncounterListEntries;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Encounter::GetEncounterCreatureByIndex(ArgumentStack&& args)
{
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

    return Services::Events::Arguments(resRef, cr, unique);
}

ArgumentStack Encounter::SetEncounterCreatureByIndex(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        const auto resRef = Services::Events::ExtractArgument<std::string>(args);
        auto cr = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(cr >= 0.0);
        auto unique = Services::Events::ExtractArgument<int32_t>(args);
        unique = !!unique;

        if (index < pEncounter->m_nNumEncounterListEntries)
        {
            pEncounter->m_pEncounterList[index].m_cCreatureResRef = resRef.c_str();
            pEncounter->m_pEncounterList[index].m_fCR = cr;
            pEncounter->m_pEncounterList[index].m_fCreaturePoints = pEncounter->CalculatePointsFromCR(cr);
            pEncounter->m_pEncounterList[index].m_bUnique = unique;
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Encounter::GetFactionId(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nFactionId;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Encounter::SetFactionId(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto factionId = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT_OR_THROW(factionId >= 0);

        pEncounter->m_nFactionId = factionId;
    }

    return Services::Events::Arguments();
}

ArgumentStack Encounter::GetPlayerTriggeredOnly(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_bPlayerTriggeredOnly;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Encounter::SetPlayerTriggeredOnly(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto playerTriggeredOnly = Services::Events::ExtractArgument<int32_t>(args);

        playerTriggeredOnly = !!playerTriggeredOnly;

        pEncounter->m_bPlayerTriggeredOnly = playerTriggeredOnly;
    }

    return Services::Events::Arguments();
}

ArgumentStack Encounter::GetResetTime(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nResetTime;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Encounter::SetResetTime(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto resetTime = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(resetTime >= 0);

        pEncounter->m_nResetTime = resetTime;
    }

    return Services::Events::Arguments();
}

}
