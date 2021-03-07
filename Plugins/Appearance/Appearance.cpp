#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"

#include <map>
#include <bitset>

using namespace NWNXLib;
using namespace NWNXLib::API;

enum OverrideType {
    AppearanceType  = 0,
    Gender          = 1,
    HitPoints       = 2,
    HairColor       = 3,
    SkinColor       = 4,
    PhenoType       = 5,
    HeadType        = 6,
    SoundSet        = 7,
    TailType        = 8,
    WingType        = 9,
    FootstepSound   = 10,
    Portrait        = 11,
    OverrideType_MAX // Keep as last
};

struct AppearanceOverrideData
{
    std::bitset<OverrideType_MAX> bitSet;

    uint16_t appearanceType     = 0;
    uint8_t gender              = 0;
    int32_t currentHitPoints    = 0;
    uint8_t hairColor           = 0;
    uint8_t skinColor           = 0;
    uint8_t phenoType           = 0;
    uint8_t headType            = 0;
    uint16_t soundSet           = 0;
    uint32_t tailType           = 0;
    uint32_t wingType           = 0;
    int32_t footstepSound       = 0;
    uint16_t portraitId         = 0;
};

template <typename T>
static void SwapIntValue(bool isSet, T &overrideValueVar, T &creatureValueVar)
{
    if(isSet)
    {
        std::swap(overrideValueVar, creatureValueVar);
    }
}

template <typename T>
static void SetIntValue(int32_t type, int32_t value, std::bitset<OverrideType_MAX> &aodBitSet, T &aodVar)
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

static Hooks::Hook s_ComputeGameObjectUpdateForObjectHook =
    Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
        (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject,
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
        }, Hooks::Order::Early);


NWNX_EXPORT ArgumentStack SetOverride(ArgumentStack&& args)
{
    if (auto *pPlayer = Utils::PopPlayer(args))
    {
        const auto oidCreature = args.extract<ObjectID>();
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = args.extract<int32_t>();
          ASSERT_OR_THROW(type < OverrideType_MAX);
        const auto value = args.extract<int32_t>();

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

    return {};
}

NWNX_EXPORT ArgumentStack GetOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pPlayer = Utils::PopPlayer(args))
    {
        const auto oidCreature = args.extract<ObjectID>();
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        const auto type = args.extract<int32_t>();
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

    return retVal;
}
