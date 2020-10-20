#include "Area.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSTile.hpp"
#include "API/CNWTileData.hpp"
#include "API/CNWSAmbientSound.hpp"
#include "API/CResStruct.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Area::Area* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Area::Area(services);
    return g_plugin;
}


namespace Area {

Area::Area(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetNumberOfPlayersInArea);
    REGISTER(GetLastEntered);
    REGISTER(GetLastLeft);
    REGISTER(GetPVPSetting);
    REGISTER(SetPVPSetting);
    REGISTER(GetAreaSpotModifier);
    REGISTER(SetAreaSpotModifier);
    REGISTER(GetAreaListenModifier);
    REGISTER(SetAreaListenModifier);
    REGISTER(GetNoRestingAllowed);
    REGISTER(SetNoRestingAllowed);
    REGISTER(GetWindPower);
    REGISTER(SetWindPower);
    REGISTER(GetWeatherChance);
    REGISTER(SetWeatherChance);
    REGISTER(GetFogClipDistance);
    REGISTER(SetFogClipDistance);
    REGISTER(GetShadowOpacity);
    REGISTER(SetShadowOpacity);
    REGISTER(GetDayNightCycle);
    REGISTER(SetDayNightCycle);
    REGISTER(GetSunMoonColors);
    REGISTER(SetSunMoonColors);
    REGISTER(CreateTransition);
    REGISTER(GetTileAnimationLoop);
    REGISTER(SetTileAnimationLoop);
    REGISTER(GetTileModelResRef);
    REGISTER(TestDirectLine);
    REGISTER(GetMusicIsPlaying);
    REGISTER(CreateGenericTrigger);
    REGISTER(AddObjectToExclusionList);
    REGISTER(RemoveObjectFromExclusionList);
    REGISTER(ExportGIT);
    REGISTER(GetTileInfo);

#undef REGISTER
}

Area::~Area()
{
}

CNWSArea *Area::area(ArgumentStack& args)
{
    const auto areaId = Services::Events::ExtractArgument<ObjectID>(args);

    if (areaId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Area function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaId);

    if (!pArea)
    {
        LOG_NOTICE("NWNX_Area function called on non-area object %x", areaId);
    }

    return pArea;
}

ArgumentStack Area::GetNumberOfPlayersInArea(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nPlayersInArea;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetLastEntered(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = static_cast<ObjectID>(pArea->m_oidLastEntered);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetLastLeft(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = static_cast<ObjectID>(pArea->m_oidLastLeft);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetPVPSetting(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nPVPSetting;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetPVPSetting(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto pvpSetting = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(pvpSetting >= Constants::PvPSetting::MIN);
          ASSERT_OR_THROW(pvpSetting <= Constants::PvPSetting::MAX);

        pArea->m_nPVPSetting = pvpSetting;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetAreaSpotModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaSpotModifier;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetAreaSpotModifier(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto spotModifier = Services::Events::ExtractArgument<int32_t>(args);

        pArea->m_nAreaSpotModifier = spotModifier;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetAreaListenModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaListenModifier;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetAreaListenModifier(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto listenModifier = Services::Events::ExtractArgument<int32_t>(args);

        pArea->m_nAreaListenModifier = listenModifier;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetNoRestingAllowed(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_bNoRestingAllowed;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetNoRestingAllowed(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto noRestingAllowed = Services::Events::ExtractArgument<int32_t>(args);

        pArea->m_bNoRestingAllowed = !!noRestingAllowed;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetWindPower(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nWindAmount;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetWindPower(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto windPower = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(windPower >= 0);
          ASSERT_OR_THROW(windPower <= 2);

        pArea->m_nWindAmount = windPower;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetWeatherChance(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);

        switch (type)
        {
            case 0:
                retVal = pArea->m_nChanceOfRain;
                break;

            case 1:
                retVal = pArea->m_nChanceOfSnow;
                break;

            case 2:
                retVal = pArea->m_nChanceOfLightning;
                break;

            default:
                retVal = 0;
                break;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetWeatherChance(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);

        auto chance = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(chance >= 0);
          ASSERT_OR_THROW(chance <= 100);

        switch (type)
        {
            case 0:
                pArea->m_nChanceOfRain = chance;
                break;

            case 1:
                pArea->m_nChanceOfSnow = chance;
                break;

            case 2:
                pArea->m_nChanceOfLightning = chance;
                break;

            default:
                break;
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetFogClipDistance(ArgumentStack&& args)
{
    float retVal = 0.0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_fFogClipDistance;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetFogClipDistance(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto distance = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(distance >= 0.0);

        pArea->m_fFogClipDistance = distance;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetShadowOpacity(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nShadowOpacity;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetShadowOpacity(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto shadowOpacity = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(shadowOpacity >= 0);
          ASSERT_OR_THROW(shadowOpacity <= 100);

        pArea->m_nShadowOpacity = shadowOpacity;
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetDayNightCycle(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        if (pArea->m_bUseDayNightCycle)
        {
            retVal = 0;
        }
        else
        {
            retVal = pArea->m_bIsNight + 1;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetDayNightCycle(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);

        switch (type)
        {
            case 0:
                pArea->m_bUseDayNightCycle = 1;
                pArea->m_bIsNight = 0;
                break;

            case 1:
                pArea->m_bUseDayNightCycle = 0;
                pArea->m_bIsNight = 0;
                break;

            case 2:
                pArea->m_bUseDayNightCycle = 0;
                pArea->m_bIsNight = 1;
                break;

            default:
                break;
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetSunMoonColors(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pArea = area(args))
    {
        auto type = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type <= 3);

        switch (type)
        {
            case 0:
                retVal = pArea->m_nMoonAmbientColor;
                break;

            case 1:
                retVal = pArea->m_nMoonDiffuseColor;
                break;

            case 2:
                retVal = pArea->m_nSunAmbientColor;
                break;

            case 3:
                retVal = pArea->m_nSunDiffuseColor;
                break;

            default:
                break;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetSunMoonColors(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto type = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type <= 3);
        auto color = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(color >= 0);

        // Switch from RGB to BGR
        auto swappedColor = (uint32_t)(((color & 0x000000FF) << 16) | (color & 0x0000FF00) | ((color & 0x00FF0000) >> 16));

        switch (type)
        {
            case 0:
                pArea->m_nMoonAmbientColor = swappedColor;
                break;

            case 1:
                pArea->m_nMoonDiffuseColor = swappedColor;
                break;

            case 2:
                pArea->m_nSunAmbientColor = swappedColor;
                break;

            case 3:
                pArea->m_nSunDiffuseColor = swappedColor;
                break;

            default:
                break;
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::CreateTransition(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;
    if (auto *pArea = area(args))
    {
        auto targetOid = Services::Events::ExtractArgument<ObjectID>(args);
        auto *pTargetObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(targetOid));
        if (pTargetObject == nullptr ||
            (pTargetObject->m_nObjectType != Constants::ObjectType::Door &&
             pTargetObject->m_nObjectType != Constants::ObjectType::Waypoint))
        {
            LOG_ERROR("Transition destination object is not valid. Valid targets are doors or waypoints.");
            return Services::Events::Arguments(retVal);
        }

        Vector vTransitionPosition;
        vTransitionPosition.x = Services::Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(vTransitionPosition.x >= 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.x < pArea->m_nWidth * 10.0f);
        vTransitionPosition.y = Services::Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(vTransitionPosition.y >= 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.y < pArea->m_nHeight * 10.0f);
        vTransitionPosition.z = Services::Events::ExtractArgument<float>(args);

        const auto size = Services::Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(size > 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.x + size < pArea->m_nWidth * 10.0f);
        ASSERT_OR_THROW(vTransitionPosition.y + size < pArea->m_nHeight * 10.0f);

        // Create our trigger
        auto *trigger = new CNWSTrigger(API::Constants::OBJECT_INVALID);
        trigger->LoadFromTemplate(CResRef("newtransition")); // Stock nwn Area Transition resRef
        trigger->SetPosition(vTransitionPosition, 0);
        trigger->CreateNewGeometry(size, vTransitionPosition, pArea);

        // Set its tag if supplied
        const auto tag = Services::Events::ExtractArgument<std::string>(args);
        if (!tag.empty())
        {
            trigger->m_sTag = CExoString(tag.c_str());
            Utils::GetModule()->AddObjectToLookupTable(trigger->m_sTag, trigger->m_idSelf);
        }

        // Create and assign our transition to the trigger
        auto *transition = new CNWSTransition();
        transition->SetTarget(pTargetObject);
        trigger->m_pTransition = *transition;

        // And add to area
        trigger->AddToArea(pArea, vTransitionPosition.x, vTransitionPosition.y, vTransitionPosition.z, false);
        retVal = trigger->m_idSelf;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetTileAnimationLoop(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pArea = area(args))
    {
        const auto tileX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileY >= 0.0f);
        const auto tileAnimLoop = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(tileAnimLoop >= 1);
          ASSERT_OR_THROW(tileAnimLoop <= 3);

        if (auto *pTile = pArea->GetTile({tileX, tileY, 0.0f}))
        {
            switch(tileAnimLoop)
            {
                case 1:
                    retVal = pTile->m_nAnimLoop1;
                    break;

                case 2:
                    retVal = pTile->m_nAnimLoop2;
                    break;

                case 3:
                    retVal = pTile->m_nAnimLoop3;
                    break;

                default:
                    break;
            }
        }
        else
        {
            LOG_ERROR("NWNX_Area_GetTileAnimationLoop: invalid tile specified");
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::SetTileAnimationLoop(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto tileX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileY >= 0.0f);
        const auto tileAnimLoop = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(tileAnimLoop >= 1);
          ASSERT_OR_THROW(tileAnimLoop <= 3);
        const auto tileEnabled = !!Services::Events::ExtractArgument<int32_t>(args);

        if (auto *pTile = pArea->GetTile({tileX, tileY, 0.0f}))
        {
            switch(tileAnimLoop)
            {
                case 1:
                    pTile->m_nAnimLoop1 = tileEnabled;
                    break;

                case 2:
                    pTile->m_nAnimLoop2 = tileEnabled;
                    break;

                case 3:
                    pTile->m_nAnimLoop3 = tileEnabled;
                    break;

                default:
                    break;
            }
        }
        else
        {
            LOG_ERROR("NWNX_Area_SetTileAnimationLoop: invalid tile specified");
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Area::GetTileModelResRef(ArgumentStack&& args)
{
    std::string retVal = "";
    if (auto* pArea = area(args))
    {
        const auto tileX = Services::Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Services::Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(tileY >= 0.0f);

        if (auto *pTile = pArea->GetTile({tileX, tileY, 0.0f}))
        {
            retVal = pTile->m_pTileData->GetModelResRef().GetResRefStr();
        }
        else
        {
            LOG_ERROR("NWNX_Area_GetTileModelResRef: invalid tile specified");
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::TestDirectLine(ArgumentStack&& args)
{
    int32_t retVal = false;
    if (auto *pArea = area(args))
    {
        const auto fStartX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fStartX >= 0.0f);
        const auto fStartY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fStartY >= 0.0f);
        const auto fEndX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fEndX >= 0.0f);
        const auto fEndY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fEndY >= 0.0f);
        const auto fPerSpace = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fPerSpace >= 0.0f);
        const auto fHeight = Services::Events::ExtractArgument<float>(args);
            ASSERT_OR_THROW(fHeight >= 0.0f);
        const auto bIgnoreDoors = Services::Events::ExtractArgument<int32_t>(args);

        retVal = pArea->TestDirectLine(fStartX, fStartY, fEndX, fEndY, fPerSpace, fHeight, bIgnoreDoors);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetMusicIsPlaying(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pArea = area(args))
    {
        const auto bBattleMusic = Services::Events::ExtractArgument<int32_t>(args) != 0;

        retVal = bBattleMusic ? pArea->m_pAmbientSound->m_bBattlePlaying : pArea->m_pAmbientSound->m_bMusicPlaying;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::CreateGenericTrigger(ArgumentStack&& args)
{
    ObjectID oidTrigger = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        const auto fX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fX >= 0.0f);
        const auto fY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fY >= 0.0f);
        const auto fZ = Services::Events::ExtractArgument<float>(args);
        const auto tag = Services::Events::ExtractArgument<std::string>(args);
        const auto fSize = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fSize >= 0.0f);

        Vector vPosition = {fX, fY, fZ};

        auto *pTrigger = new CNWSTrigger();
        pTrigger->LoadFromTemplate(CResRef("newgeneric"));
        pTrigger->m_oidCreator = Constants::OBJECT_INVALID;
        pTrigger->SetPosition(vPosition, 0);
        pTrigger->CreateNewGeometry(fSize, vPosition, pArea);

        if (!tag.empty())
        {
            pTrigger->m_sTag = CExoString(tag.c_str());
            Utils::GetModule()->AddObjectToLookupTable(pTrigger->m_sTag, pTrigger->m_idSelf);
        }

        pTrigger->AddToArea(pArea, vPosition.x, vPosition.y, vPosition.z);

        oidTrigger = pTrigger->m_idSelf;
    }

    return Services::Events::Arguments(oidTrigger);
}

ArgumentStack Area::AddObjectToExclusionList(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    m_ExportExclusionList.emplace(oidObject);

    return Services::Events::Arguments();
}

ArgumentStack Area::RemoveObjectFromExclusionList(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    m_ExportExclusionList.erase(oidObject);

    return Services::Events::Arguments();
}

ArgumentStack Area::ExportGIT(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pArea = area(args))
    {
        auto fileName = Services::Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(fileName.size() <= 16);
        if (fileName.empty())
            fileName = pArea->m_cResRef.GetResRefStr();

        const auto exportVarTable = !!Services::Events::ExtractArgument<int32_t>(args);
        const auto exportUUID = !!Services::Events::ExtractArgument<int32_t>(args);
        const auto objectFilter = Services::Events::ExtractArgument<int32_t>(args);

        std::string alias;
        try
        {
            alias = Services::Events::ExtractArgument<std::string>(args);
        }
        catch (const std::runtime_error& e)
        {
            LOG_WARNING("NWNX_Area_ExportGIT() called without alias parameter, please update nwnx_area.nss");
            alias = "NWNX";
        }

        if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
        {
            LOG_WARNING("NWNX_Area_ExportGIT() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
            alias = "NWNX";
        }

        CResGFF    resGff;
        CResStruct resStruct{};

        if (resGff.CreateGFFFile(&resStruct, "GIT ", "V3.2"))
        {
            CExoArrayList<ObjectID> creatures, items, doors, triggers, encounters, waypoints, sounds, placeables, stores, aoes;
            std::unordered_map<ObjectID, ObjectID> creatureAreaMap;

            for (int i = 0; i < pArea->m_aGameObjects.num; i++)
            {
                if (auto *pGameObject = Utils::GetGameObject(pArea->m_aGameObjects[i]))
                {
                    if (m_ExportExclusionList.find(pGameObject->m_idSelf) != m_ExportExclusionList.end())
                        continue;

                    if (auto *pCreature = Utils::AsNWSCreature(pGameObject))
                    {
                        if (pCreature->m_pStats->m_bIsPC ||
                            pCreature->m_pStats->GetIsDM() ||
                            (pCreature->m_nAssociateType > Constants::AssociateType::None &&
                            pCreature->m_nAssociateType < Constants::AssociateType::Dominated))
                            continue;

                        // Temporarily set pCreature's areaID to OBJECT_INVALID
                        // When loading the creatures from the GIT, if the creature's areaID is the same as pArea's it
                        // won't call AddToArea() which leaves all the creatures in limbo.
                        creatureAreaMap.emplace(pGameObject->m_idSelf, pCreature->m_oidArea);
                        pCreature->m_oidArea = Constants::OBJECT_INVALID;

                        creatures.Add(pGameObject->m_idSelf);
                    }
                    else if (Utils::AsNWSItem(pGameObject))
                        items.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSDoor(pGameObject))
                        doors.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSTrigger(pGameObject))
                        triggers.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSEncounter(pGameObject))
                        encounters.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSWaypoint(pGameObject))
                        waypoints.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSSoundObject(pGameObject))
                        sounds.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSPlaceable(pGameObject))
                        placeables.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSStore(pGameObject))
                        stores.Add(pGameObject->m_idSelf);
                    else if (Utils::AsNWSAreaOfEffectObject(pGameObject))
                        aoes.Add(pGameObject->m_idSelf);
                    else
                        continue;
                }
            }

            if (objectFilter != 32767)
            {
                if (!(objectFilter & 1))
                    pArea->SaveCreatures(&resGff, &resStruct, creatures, false);
                if (!(objectFilter & 2))
                    pArea->SaveItems(&resGff, &resStruct, items, false);
                if (!(objectFilter & 4))
                    pArea->SaveTriggers(&resGff, &resStruct, triggers, false);
                if (!(objectFilter & 8))
                    pArea->SaveDoors(&resGff, &resStruct, doors, false);
                if (!(objectFilter & 16))
                    pArea->SaveAreaEffects(&resGff, &resStruct, aoes, false);
                if (!(objectFilter & 32))
                    pArea->SaveWaypoints(&resGff, &resStruct, waypoints, false);
                if (!(objectFilter & 64))
                    pArea->SavePlaceables(&resGff, &resStruct, placeables, false);
                if (!(objectFilter & 128))
                    pArea->SaveStores(&resGff, &resStruct, stores, false);
                if (!(objectFilter & 256))
                    pArea->SaveEncounters(&resGff, &resStruct, encounters, false);

                // No NWScript OBJECT_TYPE_* constant for Sound Objects
                pArea->SaveSounds(&resGff, &resStruct, sounds, false);
            }

            pArea->SaveProperties(&resGff, &resStruct);

            if (exportVarTable)
                pArea->m_ScriptVars.SaveVarTable(&resGff, &resStruct);
            if (exportUUID)
                pArea->m_pUUID.SaveToGff(&resGff, &resStruct);

            retVal = resGff.WriteGFFFile(alias + ":" + fileName, Constants::ResRefType::GIT);

            // Restore the areaIDs of all creatures
            for (auto pair : creatureAreaMap)
            {
                if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pair.first)))
                    pCreature->m_oidArea = pair.second;
            }
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetTileInfo(ArgumentStack&& args)
{
    int32_t id = -1, height = -1, orientation = -1, x = -1, y = -1;

    if (auto *pArea = area(args))
    {
        const auto tileX = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileY >= 0.0f);

        if (auto *pTile = pArea->GetTile({tileX, tileY, 0.0f}))
        {
            id = pTile->m_nID;
            height = pTile->m_nHeight;
            orientation = pTile->m_nOrientation;
            x = pTile->m_nGridX;
            y = pTile->m_nGridY;
        }
    }

    return Services::Events::Arguments(id, height, orientation, x, y);
}


}
