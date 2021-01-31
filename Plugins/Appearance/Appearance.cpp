#include "Appearance.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Appearance::Appearance* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Appearance::Appearance(services);
    return g_plugin;
}


namespace Appearance {

static Hooks::Hook s_ComputeGameObjectUpdateForObjectHook = nullptr;

Appearance::Appearance(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetOverride);
    REGISTER(GetOverride);

#undef REGISTER

    s_ComputeGameObjectUpdateForObjectHook = Hooks::HookFunction(
        Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
        (void*)&ComputeGameObjectUpdateForObjectHook, Hooks::Order::Early);
}

Appearance::~Appearance()
{
}

CNWSPlayer *Appearance::Player(ArgumentStack& args)
{
    const auto playerId = Events::ExtractArgument<ObjectID>(args);

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

void Appearance::ComputeGameObjectUpdateForObjectHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject,
                                                      CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate)
{
    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidObjectToUpdate)))
    {
        if (auto appearanceOverrideData = pCreature->nwnxGet<void *>(Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
        {
            auto *pAOD = static_cast<AppearanceOverrideData *>(*appearanceOverrideData);

            auto SwapValues = [&]() -> void
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
            };

            SwapValues();

            s_ComputeGameObjectUpdateForObjectHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);

            SwapValues();

            return;
        }
    }

    s_ComputeGameObjectUpdateForObjectHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
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
    if (auto *pPlayer = Player(args))
    {
        const auto oidCreature = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type < OverrideType_MAX);
        const auto value = Events::ExtractArgument<int32_t>(args);

        auto pCreature = Utils::GetGameObject(oidCreature);
        if (type < 0)
        {
            if (auto appearanceOverrideData = pCreature->nwnxGet<void *>(Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                auto *pAOD = static_cast<AppearanceOverrideData *>(*appearanceOverrideData);
                pCreature->nwnxRemove(Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
                delete pAOD;
            }
        }
        else
        {
            AppearanceOverrideData *pAOD;
            if (auto appearanceOverrideData = pCreature->nwnxGet<void *>(Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                pAOD = static_cast<AppearanceOverrideData *>(*appearanceOverrideData);
            }
            else
            {
                auto *pAppearanceOverrideData = new AppearanceOverrideData();
                pCreature->nwnxSet(Utils::ObjectIDToString(pPlayer->m_oidNWSObject),
                                   pAppearanceOverrideData,
                                   [](void *p)
                                   { delete static_cast<AppearanceOverrideData *>(p); });
                pAOD = pAppearanceOverrideData;
            }

            switch (type)
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
    }

    return Events::Arguments();
}

ArgumentStack Appearance::GetOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pPlayer = Player(args))
    {
        const auto oidCreature = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type >= 0);
          ASSERT_OR_THROW(type < OverrideType_MAX);

        auto pCreature = Utils::GetGameObject(oidCreature);
        if (auto appearanceOverrideData = pCreature->nwnxGet<void*>(Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
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

    return Events::Arguments(retVal);
}

}
