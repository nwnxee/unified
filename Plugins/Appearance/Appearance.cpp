#include "Appearance.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreatureAppearanceInfo.hpp"
#include "API/CNWSCreature.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Appearance::Appearance> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Appearance",
        "Allows the appearance and some other things of creatures to be overridden per player",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Appearance::Appearance(params);
    return g_plugin;
}


namespace Appearance {

Appearance::Appearance(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })
        
    REGISTER(SetOverride);
    REGISTER(GetOverride);

#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__ComputeGameObjectUpdateForObject, int32_t>
            (&ComputeGameObjectUpdateForObjectHook);

}

Appearance::~Appearance()
{
}

CNWSPlayer *Appearance::Player(ArgumentStack& args)
{
    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Appearance function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerId);
    if (!pPlayer)
    {
        LOG_NOTICE("NWNX_Appearance function called on non-player object %x", playerId);
    }

    return pPlayer;
}

void Appearance::ComputeGameObjectUpdateForObjectHook(Services::Hooks::CallType type, CNWSMessage*,
        CNWSPlayer *pPlayer, CNWSObject*, CGameObjectArray*, Types::ObjectID oidObjectToUpdate)
{
    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidObjectToUpdate)))
    {
        static AppearanceOverrideData *aod;

        if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        {
            auto search = g_plugin->m_AppearanceOverrideData.find(
                    Utils::ObjectIDToString(pPlayer->m_oidNWSObject) + "_" + Utils::ObjectIDToString(oidObjectToUpdate));

            aod = search != g_plugin->m_AppearanceOverrideData.end() ? &search->second : nullptr;
        }

        if (aod)
        {
            SwapIntValue(aod->bitSet[AppearanceType], aod->appearanceType, pCreature->m_cAppearance.m_nAppearanceType);
            SwapIntValue(aod->bitSet[Gender], aod->gender, pCreature->m_cAppearance.m_nGender);
            SwapIntValue(aod->bitSet[HitPoints], aod->currentHitPoints, pCreature->m_nCurrentHitPoints);
            SwapIntValue(aod->bitSet[HairColor], aod->hairColor, pCreature->m_cAppearance.m_nHairColor);
            SwapIntValue(aod->bitSet[SkinColor], aod->skinColor, pCreature->m_cAppearance.m_nSkinColor);
            SwapIntValue(aod->bitSet[PhenoType], aod->phenoType, pCreature->m_cAppearance.m_nPhenoType);
            SwapIntValue(aod->bitSet[HeadType], aod->headType, pCreature->m_cAppearance.m_nHeadVariation);
            SwapIntValue(aod->bitSet[SoundSet], aod->soundSet, pCreature->m_nSoundSet);
            SwapIntValue(aod->bitSet[TailType], aod->tailType, pCreature->m_cAppearance.m_nTailVariation);
            SwapIntValue(aod->bitSet[WingType], aod->wingType, pCreature->m_cAppearance.m_nWingVariation);
            SwapIntValue(aod->bitSet[FootstepSound], aod->footstepSound, pCreature->m_nFootstepType);
            SwapIntValue(aod->bitSet[Portrait], aod->portraitId, pCreature->m_nPortraitId);
        }
    }
}

template <typename T>
void Appearance::SwapIntValue(bool isSet, T &overrideValueVar, T &creatureValueVar)
{
    if(isSet)
    {
        std::swap(overrideValueVar, creatureValueVar);
    }
}

template <typename T>
void Appearance::SetIntValue(int32_t type, int32_t value, std::bitset<OverrideType_MAX> &aodBitSet, T &aodVar)
{
    if (value < 0)
    {
        aodBitSet[type] = false;
    }
    else
    {
        aodBitSet[type] = true;
        aodVar = static_cast<T>(value);
    }
}

ArgumentStack Appearance::SetOverride(ArgumentStack&& args)
{
    ArgumentStack stack;

    if (auto *pPlayer = Player(args))
    {
        const auto oidCreature = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type < OverrideType_MAX);
        const auto value = Services::Events::ExtractArgument<int32_t>(args);

        const std::string key = Utils::ObjectIDToString(pPlayer->m_oidNWSObject) + "_" + Utils::ObjectIDToString(oidCreature);
        AppearanceOverrideData *aod = &m_AppearanceOverrideData[key];

        switch(type)
        {
            case AppearanceType:
                SetIntValue(type, value, aod->bitSet, aod->appearanceType);
                break;

            case Gender:
                SetIntValue(type, value, aod->bitSet, aod->gender);
                break;

            case HitPoints:
                SetIntValue(type, value, aod->bitSet, aod->currentHitPoints);
                break;

            case HairColor:
                SetIntValue(type, value, aod->bitSet, aod->hairColor);
                break;

            case SkinColor:
                SetIntValue(type, value, aod->bitSet, aod->skinColor);
                break;

            case PhenoType:
                SetIntValue(type, value, aod->bitSet, aod->phenoType);
                break;

            case HeadType:
                SetIntValue(type, value, aod->bitSet, aod->headType);
                break;

            case SoundSet:
                SetIntValue(type, value, aod->bitSet, aod->soundSet);
                break;

            case TailType:
                SetIntValue(type, value, aod->bitSet, aod->tailType);
                break;

            case WingType:
                SetIntValue(type, value, aod->bitSet, aod->wingType);
                break;

            case FootstepSound:
                SetIntValue(type, value, aod->bitSet, aod->footstepSound);
                break;

            case Portrait:
                SetIntValue(type, value, aod->bitSet, aod->portraitId);
                break;

            default:
                break;
        }

    }

    return stack;
}

ArgumentStack Appearance::GetOverride(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;

    if (auto *pPlayer = Player(args))
    {
        const auto oidCreature = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type < OverrideType_MAX);

        const std::string key = Utils::ObjectIDToString(pPlayer->m_oidNWSObject) + "_" + Utils::ObjectIDToString(oidCreature);

        if (m_AppearanceOverrideData.find(key) != m_AppearanceOverrideData.end())
        {
            AppearanceOverrideData *aod = &m_AppearanceOverrideData[key];

            if(aod->bitSet[type])
            {
                switch(type)
                {
                    case AppearanceType:
                        retVal = aod->appearanceType;
                        break;

                    case Gender:
                        retVal = aod->gender;
                        break;

                    case HitPoints:
                        retVal = aod->currentHitPoints;
                        break;

                    case HairColor:
                        retVal = aod->hairColor;
                        break;

                    case SkinColor:
                        retVal = aod->skinColor;
                        break;

                    case PhenoType:
                        retVal = aod->phenoType;
                        break;

                    case HeadType:
                        retVal = aod->headType;
                        break;

                    case SoundSet:
                        retVal = aod->soundSet;
                        break;

                    case TailType:
                        retVal = aod->tailType;
                        break;

                    case WingType:
                        retVal = aod->wingType;
                        break;

                    case FootstepSound:
                        retVal = aod->footstepSound;
                        break;

                    case Portrait:
                        retVal = aod->portraitId;
                        break;

                    default:
                        break;
                }
            }
        }
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

}
