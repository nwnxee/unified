#include "nwnx.hpp"

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

NWNX_EXPORT ArgumentStack Destroy(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        pEncounter->RemoveFromArea();
        delete pEncounter;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetNumberOfCreaturesInEncounterList(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nNumEncounterListEntries;

    return 0;
}

NWNX_EXPORT ArgumentStack GetEncounterCreatureByIndex(ArgumentStack&& args)
{
    std::string resRef = "";
    float cr = 0.0;
    int32_t unique = 0;
    int32_t alreadyUsed = 0;

    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        const auto index = args.extract<int32_t>();
        ASSERT_OR_THROW(index >= 0.0);

        if (index < pEncounter->m_nNumEncounterListEntries)
        {
            resRef = pEncounter->m_pEncounterList[index].m_cCreatureResRef.GetResRefStr();
            cr = pEncounter->m_pEncounterList[index].m_fCR;
            unique = pEncounter->m_pEncounterList[index].m_bUnique;
            alreadyUsed = pEncounter->m_pEncounterList[index].m_bAlreadyUsed;
        }
    }

    return {resRef, cr, unique, alreadyUsed};
}

NWNX_EXPORT ArgumentStack SetEncounterCreatureByIndex(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        const auto index = args.extract<int32_t>();
        const auto resRef = args.extract<std::string>();
        auto cr = args.extract<float>();
        ASSERT_OR_THROW(cr >= 0.0);
        auto unique = args.extract<int32_t>();
        unique = !!unique;
        auto alreadyUsed = args.extract<int32_t>();
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

    return {};
}

NWNX_EXPORT ArgumentStack GetFactionId(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nFactionId;

    return 0;
}

NWNX_EXPORT ArgumentStack SetFactionId(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        auto factionId = args.extract<int32_t>();
          ASSERT_OR_THROW(factionId >= 0);
        pEncounter->m_nFactionId = factionId;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetPlayerTriggeredOnly(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_bPlayerTriggeredOnly;

    return 0;
}

NWNX_EXPORT ArgumentStack SetPlayerTriggeredOnly(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        pEncounter->m_bPlayerTriggeredOnly = !!args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetCanReset(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_bReset;

    return 0;
}

NWNX_EXPORT ArgumentStack SetCanReset(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        pEncounter->m_bReset = !!args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetResetTime(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nResetTime;

    return 0;
}

NWNX_EXPORT ArgumentStack SetResetTime(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        auto resetTime = args.extract<int32_t>();
          ASSERT_OR_THROW(resetTime >= 0);

        pEncounter->m_nResetTime = resetTime;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetNumberOfSpawnPoints(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nNumSpawnPoints;

    return 0;
}

NWNX_EXPORT ArgumentStack GetSpawnPointByIndex(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        const auto index = args.extract<int32_t>();
        ASSERT_OR_THROW(index >= 0);

        if (index < pEncounter->m_nNumSpawnPoints)
        {
            return {pEncounter->m_pSpawnPointList[index].m_vPosition, pEncounter->m_pSpawnPointList[index].m_fOrientation};
        }
    }
    return {Vector(), 0.0f};
}

NWNX_EXPORT ArgumentStack GetMinNumSpawned(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nMinNumSpawnedCreatures;

    return 0;
}

NWNX_EXPORT ArgumentStack GetMaxNumSpawned(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nMaxSpawnedCreatures;

    return 0;
}

NWNX_EXPORT ArgumentStack GetCurrentNumSpawned(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
        return pEncounter->m_nNumSpawnedCreatures;

    return 0;
}

NWNX_EXPORT ArgumentStack GetGeometry(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        retVal.reserve(32 * pEncounter->m_nNumActivateVertices);

        for(int i = 0; i < pEncounter->m_nNumActivateVertices; i++)
        {
            retVal += "{" + std::to_string(pEncounter->m_pvActivateVertices[i].x) + ", " +
                            std::to_string(pEncounter->m_pvActivateVertices[i].y) + ", " +
                            std::to_string(pEncounter->m_pvActivateVertices[i].z) + "}";
        }
    }
    return retVal;
}

NWNX_EXPORT ArgumentStack SetGeometry(ArgumentStack&& args)
{
    if (auto *pEncounter = Utils::PopEncounter(args))
    {
        const auto sGeometry = args.extract<std::string>();

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

            pEncounter->m_nNumActivateVertices = vecVerts.size();

            pEncounter->m_pvActivateVertices = new Vector[pEncounter->m_nNumActivateVertices];

            for(int i = 0; i < pEncounter->m_nNumActivateVertices; i++)
            {
                pEncounter->m_pvActivateVertices[i] = vecVerts[i];
            }

            Utils::AddToArea(pEncounter, pArea, pEncounter->m_pvActivateVertices[0].x, pEncounter->m_pvActivateVertices[0].y, pEncounter->m_pvActivateVertices[0].z);
        }
        else
        {
            LOG_WARNING("NWNX_Encounter_SetGeometry() called with less than 3 vertices.");
        }
    }
    return {};
}
