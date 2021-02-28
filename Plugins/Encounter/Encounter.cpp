#include "Encounter.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CEncounterSpawnPoint.hpp"
#include "API/CEncounterListEntry.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Encounter::Encounter* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Encounter::Encounter(services);
    return g_plugin;
}


namespace Encounter {

Encounter::Encounter(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetNumberOfCreaturesInEncounterList);
    REGISTER(GetEncounterCreatureByIndex);
    REGISTER(SetEncounterCreatureByIndex);
    REGISTER(GetFactionId);
    REGISTER(SetFactionId);
    REGISTER(GetPlayerTriggeredOnly);
    REGISTER(SetPlayerTriggeredOnly);
    REGISTER(GetCanReset);
    REGISTER(SetCanReset);
    REGISTER(GetResetTime);
    REGISTER(SetResetTime);
    REGISTER(GetNumberOfSpawnPoints);
    REGISTER(GetSpawnPointByIndex);
    REGISTER(GetMinNumSpawned);
    REGISTER(GetMaxNumSpawned);
    REGISTER(GetCurrentNumSpawned);
    REGISTER(GetGeometry);
    REGISTER(SetGeometry);

#undef REGISTER
}

Encounter::~Encounter()
{
}

CNWSEncounter *Encounter::encounter(ArgumentStack& args)
{
    const auto encounterId = Events::ExtractArgument<ObjectID>(args);

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

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::GetEncounterCreatureByIndex(ArgumentStack&& args)
{
    std::string resRef = "";
    float cr = 0.0;
    int32_t unique = 0;
    int32_t alreadyUsed = 0;

    if (auto *pEncounter = encounter(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(index >= 0.0);

        if (index < pEncounter->m_nNumEncounterListEntries)
        {
            resRef = pEncounter->m_pEncounterList[index].m_cCreatureResRef.GetResRefStr();
            cr = pEncounter->m_pEncounterList[index].m_fCR;
            unique = pEncounter->m_pEncounterList[index].m_bUnique;
            alreadyUsed = pEncounter->m_pEncounterList[index].m_bAlreadyUsed;
        }
    }

    return Events::Arguments(resRef, cr, unique, alreadyUsed);
}

ArgumentStack Encounter::SetEncounterCreatureByIndex(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);
        const auto resRef = Events::ExtractArgument<std::string>(args);
        auto cr = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(cr >= 0.0);
        auto unique = Events::ExtractArgument<int32_t>(args);
        unique = !!unique;
        auto alreadyUsed = Events::ExtractArgument<int32_t>(args);
        alreadyUsed = !!alreadyUsed;

        if (index < pEncounter->m_nNumEncounterListEntries)
        {
            pEncounter->m_pEncounterList[index].m_cCreatureResRef = resRef.c_str();
            pEncounter->m_pEncounterList[index].m_fCR = cr;
            pEncounter->m_pEncounterList[index].m_fCreaturePoints = pEncounter->CalculatePointsFromCR(cr);
            pEncounter->m_pEncounterList[index].m_bAlreadyUsed = alreadyUsed;
            pEncounter->m_pEncounterList[index].m_bUnique = unique;
        }
    }

    return Events::Arguments();
}

ArgumentStack Encounter::GetFactionId(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nFactionId;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::SetFactionId(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto factionId = Events::ExtractArgument<int32_t>(args);

        ASSERT_OR_THROW(factionId >= 0);

        pEncounter->m_nFactionId = factionId;
    }

    return Events::Arguments();
}

ArgumentStack Encounter::GetPlayerTriggeredOnly(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_bPlayerTriggeredOnly;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::SetPlayerTriggeredOnly(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto playerTriggeredOnly = Events::ExtractArgument<int32_t>(args);

        playerTriggeredOnly = !!playerTriggeredOnly;

        pEncounter->m_bPlayerTriggeredOnly = playerTriggeredOnly;
    }

    return Events::Arguments();
}

ArgumentStack Encounter::GetCanReset(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_bReset;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::SetCanReset(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto reset = Events::ExtractArgument<int32_t>(args);
        pEncounter->m_bReset = !!reset;
    }

    return Events::Arguments();
}

ArgumentStack Encounter::GetResetTime(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nResetTime;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::SetResetTime(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        auto resetTime = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(resetTime >= 0);

        pEncounter->m_nResetTime = resetTime;
    }

    return Events::Arguments();
}

ArgumentStack Encounter::GetNumberOfSpawnPoints(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nNumSpawnPoints;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::GetSpawnPointByIndex(ArgumentStack&& args)
{
    float x = 0.0, y = 0.0, z = 0.0, o = 0.0;

    if (auto *pEncounter = encounter(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(index >= 0);

        if (index < pEncounter->m_nNumSpawnPoints)
        {
            x = pEncounter->m_pSpawnPointList[index].m_vPosition.x;
            y = pEncounter->m_pSpawnPointList[index].m_vPosition.y;
            z = pEncounter->m_pSpawnPointList[index].m_vPosition.z;
            o = pEncounter->m_pSpawnPointList[index].m_fOrientation;
        }
    }

    return Events::Arguments(x, y, z, o);
}

ArgumentStack Encounter::GetMinNumSpawned(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nMinNumSpawnedCreatures;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::GetMaxNumSpawned(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nMaxSpawnedCreatures;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::GetCurrentNumSpawned(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pEncounter = encounter(args))
    {
        retVal = pEncounter->m_nNumSpawnedCreatures;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Encounter::GetGeometry(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pEncounter = encounter(args))
    {
        retVal.reserve(32 * pEncounter->m_nNumActivateVertices);

        for(int i = 0; i < pEncounter->m_nNumActivateVertices; i++)
        {
            retVal += "{" + std::to_string(pEncounter->m_pvActivateVertices[i].x) + ", " +
                            std::to_string(pEncounter->m_pvActivateVertices[i].y) + ", " +
                            std::to_string(pEncounter->m_pvActivateVertices[i].z) + "}";
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Encounter::SetGeometry(ArgumentStack&& args)
{
    if (auto *pEncounter = encounter(args))
    {
        const auto sGeometry = Events::ExtractArgument<std::string>(args);

        auto str = sGeometry.c_str();
        std::vector<Vector> vecVerts;
        Vector vec = {};

        do {
            int cnt = std::sscanf(str, "{%f,%f,%f", &vec.x, &vec.y, &vec.z);

            if (cnt != 2 && cnt != 3)
            {
                LOG_NOTICE("NWNX_Encounter_SetGeometry() invalid geometry string at: %s", str);
                break;
            }

            if (cnt == 2)
                vec.z = pEncounter->GetArea()->ComputeHeight(vec);

            vecVerts.push_back(vec);
        } while ((str = std::strstr(str + 1, "{")));

        if (vecVerts.size() > 2)
        {
            CNWSArea *pArea = pEncounter->GetArea();
            pEncounter->RemoveFromArea();

            delete[] pEncounter->m_pvActivateVertices;
            delete[] pEncounter->m_pnOutlineVertices;
            
            pEncounter->m_nNumActivateVertices = vecVerts.size();
            pEncounter->m_nNumOutlineVertices = vecVerts.size();

            pEncounter->m_pvActivateVertices = new Vector[pEncounter->m_nNumActivateVertices];
            pEncounter->m_pnOutlineVertices = new int32_t[pEncounter->m_nNumActivateVertices];

            for(int i = 0; i < pEncounter->m_nNumActivateVertices; i++)
            {
                pEncounter->m_pvActivateVertices[i] = vecVerts[i];
                pEncounter->m_pnOutlineVertices[i] = i;
            }

            Utils::AddToArea(pEncounter, pArea, pEncounter->m_pvActivateVertices[0].x, pEncounter->m_pvActivateVertices[0].y, pEncounter->m_pvActivateVertices[0].z);
        }
        else
        {
            LOG_WARNING("NWNX_Encounter_SetGeometry() called with less than 3 vertices.");
        }
    }
    return Events::Arguments();
}

}
