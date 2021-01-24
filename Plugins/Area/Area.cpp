#include "Area.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSTile.hpp"
#include "API/CNWTileData.hpp"
#include "API/CNWSAmbientSound.hpp"
#include "API/CResStruct.hpp"
#include "API/CResList.hpp"
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
    Events::RegisterEvent(PLUGIN_NAME, #func, \
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
    REGISTER(ExportARE);
    REGISTER(GetAmbientSoundDay);
    REGISTER(GetAmbientSoundNight);
    REGISTER(GetAmbientSoundDayVolume);
    REGISTER(GetAmbientSoundNightVolume);

#undef REGISTER
}

Area::~Area()
{
}

CNWSArea *Area::area(ArgumentStack& args)
{
    const auto areaId = Events::ExtractArgument<ObjectID>(args);

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

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetLastEntered(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_oidLastEntered;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetLastLeft(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_oidLastLeft;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetPVPSetting(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nPVPSetting;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetPVPSetting(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto pvpSetting = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(pvpSetting >= Constants::PvPSetting::MIN);
          ASSERT_OR_THROW(pvpSetting <= Constants::PvPSetting::MAX);

        pArea->m_nPVPSetting = pvpSetting;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetAreaSpotModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaSpotModifier;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetAreaSpotModifier(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto spotModifier = Events::ExtractArgument<int32_t>(args);

        pArea->m_nAreaSpotModifier = spotModifier;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetAreaListenModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaListenModifier;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetAreaListenModifier(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto listenModifier = Events::ExtractArgument<int32_t>(args);

        pArea->m_nAreaListenModifier = listenModifier;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetNoRestingAllowed(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_bNoRestingAllowed;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetNoRestingAllowed(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto noRestingAllowed = Events::ExtractArgument<int32_t>(args);

        pArea->m_bNoRestingAllowed = !!noRestingAllowed;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetWindPower(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nWindAmount;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetWindPower(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto windPower = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(windPower >= 0);
          ASSERT_OR_THROW(windPower <= 2);

        pArea->m_nWindAmount = windPower;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetWeatherChance(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        const auto type = Events::ExtractArgument<int32_t>(args);

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

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetWeatherChance(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto type = Events::ExtractArgument<int32_t>(args);

        auto chance = Events::ExtractArgument<int32_t>(args);
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

    return Events::Arguments();
}

ArgumentStack Area::GetFogClipDistance(ArgumentStack&& args)
{
    float retVal = 0.0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_fFogClipDistance;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetFogClipDistance(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto distance = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(distance >= 0.0);

        pArea->m_fFogClipDistance = distance;
    }

    return Events::Arguments();
}

ArgumentStack Area::GetShadowOpacity(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nShadowOpacity;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetShadowOpacity(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto shadowOpacity = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(shadowOpacity >= 0);
          ASSERT_OR_THROW(shadowOpacity <= 100);

        pArea->m_nShadowOpacity = shadowOpacity;
    }

    return Events::Arguments();
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetDayNightCycle(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto type = Events::ExtractArgument<int32_t>(args);

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

    return Events::Arguments();
}

ArgumentStack Area::GetSunMoonColors(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pArea = area(args))
    {
        auto type = Events::ExtractArgument<int32_t>(args);
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetSunMoonColors(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        auto type = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type <= 3);
        auto color = Events::ExtractArgument<int32_t>(args);
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

    return Events::Arguments();
}

ArgumentStack Area::CreateTransition(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;
    if (auto *pArea = area(args))
    {
        auto targetOid = Events::ExtractArgument<ObjectID>(args);
        auto *pTargetObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(targetOid));
        if (pTargetObject == nullptr ||
            (pTargetObject->m_nObjectType != Constants::ObjectType::Door &&
             pTargetObject->m_nObjectType != Constants::ObjectType::Waypoint))
        {
            LOG_ERROR("Transition destination object is not valid. Valid targets are doors or waypoints.");
            return Events::Arguments(retVal);
        }

        Vector vTransitionPosition;
        vTransitionPosition.x = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(vTransitionPosition.x >= 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.x < pArea->m_nWidth * 10.0f);
        vTransitionPosition.y = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(vTransitionPosition.y >= 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.y < pArea->m_nHeight * 10.0f);
        vTransitionPosition.z = Events::ExtractArgument<float>(args);

        const auto size = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(size > 0.0f);
        ASSERT_OR_THROW(vTransitionPosition.x + size < pArea->m_nWidth * 10.0f);
        ASSERT_OR_THROW(vTransitionPosition.y + size < pArea->m_nHeight * 10.0f);

        // Create our trigger
        auto *trigger = new CNWSTrigger(API::Constants::OBJECT_INVALID);
        trigger->LoadFromTemplate(CResRef("newtransition")); // Stock nwn Area Transition resRef
        trigger->SetPosition(vTransitionPosition, 0);
        trigger->CreateNewGeometry(size, vTransitionPosition, pArea);

        // Set its tag if supplied
        const auto tag = Events::ExtractArgument<std::string>(args);
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetTileAnimationLoop(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pArea = area(args))
    {
        const auto tileX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileY >= 0.0f);
        const auto tileAnimLoop = Events::ExtractArgument<int32_t>(args);
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::SetTileAnimationLoop(ArgumentStack&& args)
{
    if (auto *pArea = area(args))
    {
        const auto tileX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileY >= 0.0f);
        const auto tileAnimLoop = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(tileAnimLoop >= 1);
          ASSERT_OR_THROW(tileAnimLoop <= 3);
        const auto tileEnabled = !!Events::ExtractArgument<int32_t>(args);

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

    return Events::Arguments();
}

ArgumentStack Area::GetTileModelResRef(ArgumentStack&& args)
{
    std::string retVal = "";
    if (auto* pArea = area(args))
    {
        const auto tileX = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Events::ExtractArgument<float>(args);
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::TestDirectLine(ArgumentStack&& args)
{
    int32_t retVal = false;
    if (auto *pArea = area(args))
    {
        const auto fStartX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fStartX >= 0.0f);
        const auto fStartY = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fStartY >= 0.0f);
        const auto fEndX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fEndX >= 0.0f);
        const auto fEndY = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fEndY >= 0.0f);
        const auto fPerSpace = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fPerSpace >= 0.0f);
        const auto fHeight = Events::ExtractArgument<float>(args);
            ASSERT_OR_THROW(fHeight >= 0.0f);
        const auto bIgnoreDoors = Events::ExtractArgument<int32_t>(args);

        retVal = pArea->TestDirectLine(fStartX, fStartY, fEndX, fEndY, fPerSpace, fHeight, bIgnoreDoors);
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetMusicIsPlaying(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pArea = area(args))
    {
        const auto bBattleMusic = Events::ExtractArgument<int32_t>(args) != 0;

        retVal = bBattleMusic ? pArea->m_pAmbientSound->m_bBattlePlaying : pArea->m_pAmbientSound->m_bMusicPlaying;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::CreateGenericTrigger(ArgumentStack&& args)
{
    ObjectID oidTrigger = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        const auto fX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fX >= 0.0f);
        const auto fY = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fY >= 0.0f);
        const auto fZ = Events::ExtractArgument<float>(args);
        const auto tag = Events::ExtractArgument<std::string>(args);
        const auto fSize = Events::ExtractArgument<float>(args);
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

    return Events::Arguments(oidTrigger);
}

ArgumentStack Area::AddObjectToExclusionList(ArgumentStack&& args)
{
    const auto oidObject = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    m_ExportExclusionList.emplace(oidObject);

    return Events::Arguments();
}

ArgumentStack Area::RemoveObjectFromExclusionList(ArgumentStack&& args)
{
    const auto oidObject = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    m_ExportExclusionList.erase(oidObject);

    return Events::Arguments();
}

ArgumentStack Area::ExportGIT(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pArea = area(args))
    {
        auto fileName = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(fileName.size() <= 16);
        if (fileName.empty())
            fileName = pArea->m_cResRef.GetResRefStr();

        const auto exportVarTable = !!Events::ExtractArgument<int32_t>(args);
        const auto exportUUID = !!Events::ExtractArgument<int32_t>(args);
        const auto objectFilter = Events::ExtractArgument<int32_t>(args);

        std::string alias;
        try
        {
            alias = Events::ExtractArgument<std::string>(args);
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

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetTileInfo(ArgumentStack&& args)
{
    int32_t id = -1, height = -1, orientation = -1, x = -1, y = -1;

    if (auto *pArea = area(args))
    {
        const auto tileX = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(tileX >= 0.0f);
        const auto tileY = Events::ExtractArgument<float>(args);
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

    return Events::Arguments(id, height, orientation, x, y);
}

ArgumentStack Area::ExportARE(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pArea = area(args))
    {
        const auto fileName = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!fileName.empty());
          ASSERT_OR_THROW(fileName.size() <= 16);
        const auto newName = Events::ExtractArgument<std::string>(args);
        const auto newTag = Events::ExtractArgument<std::string>(args);
        auto alias = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!alias.empty());

        if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
        {
            LOG_WARNING("NWNX_Area_ExportARE() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
            alias = "NWNX";
        }

        CResGFF    resGff;
        CResStruct resStruct{};

        if (resGff.CreateGFFFile(&resStruct, "ARE ", "V3.2"))
        {
            char field[32];

            // Important Stuff
            std::sprintf(field, "Name");
            resGff.WriteFieldCExoLocString(&resStruct, newName.empty() ? pArea->m_lsName : Utils::CreateLocString(newName), field);
            std::sprintf(field, "Tag");
            resGff.WriteFieldCExoString(&resStruct, newTag.empty() ? pArea->m_sTag : CExoString(newTag).AsTAG(), field);
            std::sprintf(field, "ResRef");
            resGff.WriteFieldCExoString(&resStruct, CResRef(fileName), field);
            std::sprintf(field, "Width");
            resGff.WriteFieldINT(&resStruct, pArea->m_nWidth, field);
            std::sprintf(field, "Height");
            resGff.WriteFieldINT(&resStruct, pArea->m_nHeight, field);
            std::sprintf(field, "Tileset");
            resGff.WriteFieldCResRef(&resStruct, pArea->m_refTileSet, field);

            // Less Important Stuff
            std::sprintf(field, "ChanceLightning");
            resGff.WriteFieldINT(&resStruct, pArea->m_nChanceOfLightning, field);
            std::sprintf(field, "ChanceRain");
            resGff.WriteFieldINT(&resStruct, pArea->m_nChanceOfRain, field);
            std::sprintf(field, "ChanceSnow");
            resGff.WriteFieldINT(&resStruct, pArea->m_nChanceOfSnow, field);
            std::sprintf(field, "DayNightCycle");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_bUseDayNightCycle, field);
            std::sprintf(field, "Flags");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nFlags, field);
            std::sprintf(field, "FogClipDist");
            resGff.WriteFieldFLOAT(&resStruct, pArea->m_fFogClipDistance, field);
            std::sprintf(field, "IsNight");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_bIsNight, field);
            std::sprintf(field, "LightingScheme");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nLightingScheme, field);
            std::sprintf(field, "LoadScreenID");
            resGff.WriteFieldWORD(&resStruct, pArea->m_nLoadScreenID, field);
            std::sprintf(field, "ModListenCheck");
            resGff.WriteFieldINT(&resStruct, pArea->m_nAreaListenModifier, field);
            std::sprintf(field, "ModSpotCheck");
            resGff.WriteFieldINT(&resStruct, pArea->m_nAreaSpotModifier, field);
            std::sprintf(field, "MoonAmbientColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nMoonAmbientColor, field);
            std::sprintf(field, "MoonDiffuseColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nMoonDiffuseColor, field);
            std::sprintf(field, "MoonFogAmount");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nMoonFogAmount, field);
            std::sprintf(field, "MoonFogColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nMoonFogColor, field);
            std::sprintf(field, "MoonShadows");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_bMoonShadows, field);
            std::sprintf(field, "NoRest");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_bNoRestingAllowed, field);
            std::sprintf(field, "OnHeartbeat");
            resGff.WriteFieldCResRef(&resStruct, pArea->m_sScripts[0], field);
            std::sprintf(field, "OnUserDefined");
            resGff.WriteFieldCResRef(&resStruct, pArea->m_sScripts[1], field);
            std::sprintf(field, "OnEnter");
            resGff.WriteFieldCResRef(&resStruct, pArea->m_sScripts[2], field);
            std::sprintf(field, "OnExit");
            resGff.WriteFieldCResRef(&resStruct, pArea->m_sScripts[3], field);
            std::sprintf(field, "PlayerVsPlayer");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nPVPSetting, field);
            std::sprintf(field, "ShadowOpacity");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nShadowOpacity, field);
            std::sprintf(field, "SkyBox");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nSkyBox, field);
            std::sprintf(field, "SunAmbientColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nSunAmbientColor, field);
            std::sprintf(field, "SunDiffuseColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nSunDiffuseColor, field);
            std::sprintf(field, "SunFogAmount");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_nSunFogAmount, field);
            std::sprintf(field, "SunFogColor");
            resGff.WriteFieldDWORD(&resStruct, pArea->m_nSunFogColor, field);
            std::sprintf(field, "SunShadows");
            resGff.WriteFieldBYTE(&resStruct, pArea->m_bSunShadows, field);
            std::sprintf(field, "WindPower");
            resGff.WriteFieldINT(&resStruct, pArea->m_nWindAmount, field);

            // Tile Stuff
            CResList resList{};
            std::sprintf(field, "Tile_List");
            resGff.AddList(&resList, &resStruct, field);
            auto numTiles = pArea->m_nWidth * pArea->m_nHeight;

            for (int tileNum = 0; tileNum < numTiles; tileNum++)
            {
                auto *pTile = &pArea->m_pTile[tileNum];

                resGff.AddListElement(&resStruct, &resList, 1);

                std::sprintf(field, "Tile_ID");
                resGff.WriteFieldINT(&resStruct, pTile->m_nID, field);
                std::sprintf(field, "Tile_Orientation");
                resGff.WriteFieldINT(&resStruct, pTile->m_nOrientation, field);
                std::sprintf(field, "Tile_Height");
                resGff.WriteFieldINT(&resStruct, pTile->m_nHeight, field);

                std::sprintf(field, "Tile_MainLight1");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nMainLight1Color == 255 ? 0 : pTile->m_nMainLight1Color, field);
                std::sprintf(field, "Tile_MainLight2");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nMainLight2Color == 255 ? 0 : pTile->m_nMainLight2Color, field);

                std::sprintf(field, "Tile_SrcLight1");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nSourceLight1Color == 255 ? 0 : pTile->m_nSourceLight1Color, field);
                std::sprintf(field, "Tile_SrcLight2");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nSourceLight2Color == 255 ? 0 : pTile->m_nSourceLight2Color, field);

                std::sprintf(field, "Tile_AnimLoop1");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nAnimLoop1, field);
                std::sprintf(field, "Tile_AnimLoop2");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nAnimLoop2, field);
                std::sprintf(field, "Tile_AnimLoop3");
                resGff.WriteFieldBYTE(&resStruct, pTile->m_nAnimLoop3, field);
            }

            retVal = resGff.WriteGFFFile(alias + ":" + fileName, Constants::ResRefType::ARE);
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetAmbientSoundDay(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        if (pArea->m_pAmbientSound != nullptr)
        {
            retVal = pArea->m_pAmbientSound->m_nSoundDayTrack;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetAmbientSoundNight(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        if (pArea->m_pAmbientSound != nullptr)
        {
            retVal = pArea->m_pAmbientSound->m_nSoundNightTrack;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetAmbientSoundDayVolume(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        if (pArea->m_pAmbientSound != nullptr)
        {
            retVal = pArea->m_pAmbientSound->m_nDayVolume;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Area::GetAmbientSoundNightVolume(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pArea = area(args))
    {
        if (pArea->m_pAmbientSound != nullptr)
        {
            retVal = pArea->m_pAmbientSound->m_nNightVolume;
        }
    }

    return Events::Arguments(retVal);
}

}
