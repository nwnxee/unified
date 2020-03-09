#include "Area.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSTransition.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSTile.hpp"
#include "API/CNWTileData.hpp"
#include "API/CNWSAmbientSound.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Events/Events.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Area::Area* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Area",
        "Functions exposing additional area properties",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Area::Area(params);
    return g_plugin;
}


namespace Area {

Area::Area(const Plugin::CreateParams& params)
    : Plugin(params)
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

#undef REGISTER
}

Area::~Area()
{
}

CNWSArea *Area::area(ArgumentStack& args)
{
    const auto areaId = Services::Events::ExtractArgument<Types::ObjectID>(args);

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

CNWSTile *Area::GetTile(CNWSArea *pArea, float x, float y)
{
    int nTile = (int)(y / 10) * pArea->m_nWidth + (int)(x / 10);

    if (nTile >= 0 && nTile < (pArea->m_nWidth * pArea->m_nHeight))
        return &pArea->m_pTile[nTile];
    else
        return nullptr;
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
    Types::ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = static_cast<Types::ObjectID>(pArea->m_oidLastEntered);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Area::GetLastLeft(ArgumentStack&& args)
{
    Types::ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto *pArea = area(args))
    {
        retVal = static_cast<Types::ObjectID>(pArea->m_oidLastLeft);
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
    Types::ObjectID retVal = Constants::OBJECT_INVALID;
    if (auto *pArea = area(args))
    {
        auto targetOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
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
        ASSERT_OR_THROW(vTransitionPosition.x < pArea->m_nHeight * 10.0f);
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

        CNWSTile *pTile = GetTile(pArea, tileX, tileY);

        if (pTile)
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

        CNWSTile *pTile = GetTile(pArea, tileX, tileY);

        if (pTile)
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

        CNWSTile* pTile = GetTile(pArea, tileX, tileY);

        if (pTile)
        {
            retVal = pTile->m_pTileData->GetModelResRef().GetResRefStr();
        }
        else
        {
            LOG_ERROR("NWNX_Area_GetTileName: invalid tile specified");
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
    Types::ObjectID oidTrigger = Constants::OBJECT_INVALID;

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

}
