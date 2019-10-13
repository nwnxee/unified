#include "Appearance.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
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
        static AppearanceOverrideData *pAOD;

        if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        {
            if (auto appearanceOverrideData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidObjectToUpdate,
                    Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                pAOD = static_cast<AppearanceOverrideData*>(*appearanceOverrideData);
            }
            else
            {
                pAOD = nullptr;
            }
        }

        if (pAOD)
        {
            SwapIntValue(pAOD->bitSet[AppearanceType], pAOD->appearanceType, pCreature->m_cAppearance.m_nAppearanceType);
            SwapIntValue(pAOD->bitSet[Gender], pAOD->gender, pCreature->m_cAppearance.m_nGender);
            SwapIntValue(pAOD->bitSet[HitPoints], pAOD->currentHitPoints, pCreature->m_nCurrentHitPoints);
            SwapIntValue(pAOD->bitSet[HairColor], pAOD->hairColor, pCreature->m_cAppearance.m_nHairColor);
            SwapIntValue(pAOD->bitSet[SkinColor], pAOD->skinColor, pCreature->m_cAppearance.m_nSkinColor);
            SwapIntValue(pAOD->bitSet[PhenoType], pAOD->phenoType, pCreature->m_cAppearance.m_nPhenoType);
            SwapIntValue(pAOD->bitSet[HeadType], pAOD->headType, pCreature->m_cAppearance.m_nHeadVariation);
            SwapIntValue(pAOD->bitSet[SoundSet], pAOD->soundSet, pCreature->m_nSoundSet);
            SwapIntValue(pAOD->bitSet[TailType], pAOD->tailType, pCreature->m_cAppearance.m_nTailVariation);
            SwapIntValue(pAOD->bitSet[WingType], pAOD->wingType, pCreature->m_cAppearance.m_nWingVariation);
            SwapIntValue(pAOD->bitSet[FootstepSound], pAOD->footstepSound, pCreature->m_nFootstepType);
            SwapIntValue(pAOD->bitSet[Portrait], pAOD->portraitId, pCreature->m_nPortraitId);
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

        AppearanceOverrideData* pAOD;
        if (auto appearanceOverrideData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidCreature, Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
        {
            pAOD = static_cast<AppearanceOverrideData*>(*appearanceOverrideData);
        }
        else
        {
            auto *pAppearanceOverrideData = new AppearanceOverrideData();
            g_plugin->GetServices()->m_perObjectStorage->Set(oidCreature, Utils::ObjectIDToString(pPlayer->m_oidNWSObject), pAppearanceOverrideData,
                                                             [](void*p) { delete static_cast<AppearanceOverrideData*>(p); });
            pAOD = pAppearanceOverrideData;
        }

        switch(type)
        {
            case AppearanceType:
                SetIntValue(type, value, pAOD->bitSet, pAOD->appearanceType);
                break;

            case Gender:
                SetIntValue(type, value, pAOD->bitSet, pAOD->gender);
                break;

            case HitPoints:
                SetIntValue(type, value, pAOD->bitSet, pAOD->currentHitPoints);
                break;

            case HairColor:
                SetIntValue(type, value, pAOD->bitSet, pAOD->hairColor);
                break;

            case SkinColor:
                SetIntValue(type, value, pAOD->bitSet, pAOD->skinColor);
                break;

            case PhenoType:
                SetIntValue(type, value, pAOD->bitSet, pAOD->phenoType);
                break;

            case HeadType:
                SetIntValue(type, value, pAOD->bitSet, pAOD->headType);
                break;

            case SoundSet:
                SetIntValue(type, value, pAOD->bitSet, pAOD->soundSet);
                break;

            case TailType:
                SetIntValue(type, value, pAOD->bitSet, pAOD->tailType);
                break;

            case WingType:
                SetIntValue(type, value, pAOD->bitSet, pAOD->wingType);
                break;

            case FootstepSound:
                SetIntValue(type, value, pAOD->bitSet, pAOD->footstepSound);
                break;

            case Portrait:
                SetIntValue(type, value, pAOD->bitSet, pAOD->portraitId);
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

        if (auto appearanceOverrideData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidCreature,
                Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
        {
            auto *pAOD = static_cast<AppearanceOverrideData*>(*appearanceOverrideData);

            if(pAOD->bitSet[type])
            {
                switch(type)
                {
                    case AppearanceType:
                        retVal = pAOD->appearanceType;
                        break;

                    case Gender:
                        retVal = pAOD->gender;
                        break;

                    case HitPoints:
                        retVal = pAOD->currentHitPoints;
                        break;

                    case HairColor:
                        retVal = pAOD->hairColor;
                        break;

                    case SkinColor:
                        retVal = pAOD->skinColor;
                        break;

                    case PhenoType:
                        retVal = pAOD->phenoType;
                        break;

                    case HeadType:
                        retVal = pAOD->headType;
                        break;

                    case SoundSet:
                        retVal = pAOD->soundSet;
                        break;

                    case TailType:
                        retVal = pAOD->tailType;
                        break;

                    case WingType:
                        retVal = pAOD->wingType;
                        break;

                    case FootstepSound:
                        retVal = pAOD->footstepSound;
                        break;

                    case Portrait:
                        retVal = pAOD->portraitId;
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
