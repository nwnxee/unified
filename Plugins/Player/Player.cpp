#include "Player.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSQuickbarButton.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayerCharSheetGUI.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSJournal.hpp"
#include "API/CNWSPlayerJournalQuest.hpp"
#include "API/CNWSPlayerJournalQuestUpdates.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/C2DA.hpp"
#include "API/ObjectVisualTransformData.hpp"
#include "API/CLastUpdateObject.hpp"
#include "API/CWorldTimer.hpp"
#include "API/CExoLocString.hpp"
#include "API/CNWSPlayerStoreGUI.hpp"
#include "API/CExoResMan.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Player::Player* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Player::Player(services);
    return g_plugin;
}


namespace Player {

Player::Player(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(ForcePlaceableExamineWindow);
    REGISTER(ForcePlaceableInventoryWindow);
    REGISTER(StartGuiTimingBar);
    REGISTER(StopGuiTimingBar);
    REGISTER(SetAlwaysWalk);
    REGISTER(GetQuickBarSlot);
    REGISTER(SetQuickBarSlot);
    REGISTER(GetBicFileName);
    REGISTER(ShowVisualEffect);
    REGISTER(ChangeBackgroundMusic);
    REGISTER(PlayBackgroundMusic);
    REGISTER(ChangeBattleMusic);
    REGISTER(PlayBattleMusic);
    REGISTER(PlaySound);
    REGISTER(SetPlaceableUsable);
    REGISTER(SetRestDuration);
    REGISTER(ApplyInstantVisualEffectToObject);
    REGISTER(UpdateCharacterSheet);
    REGISTER(OpenInventory);
    REGISTER(GetAreaExplorationState);
    REGISTER(SetAreaExplorationState);
    REGISTER(SetRestAnimation);
    REGISTER(SetObjectVisualTransformOverride);
    REGISTER(ApplyLoopingVisualEffectToObject);
    REGISTER(SetPlaceableNameOverride);
    REGISTER(GetQuestCompleted);
    REGISTER(SetPersistentLocation);
    REGISTER(UpdateItemName);
    REGISTER(PossessCreature);
    REGISTER(GetPlatformId);
    REGISTER(GetLanguage);
    REGISTER(SetResManOverride);
    REGISTER(SetCustomToken);
    REGISTER(SetCreatureNameOverride);
    REGISTER(FloatingTextStringOnCreature);
    REGISTER(ToggleDM);
    REGISTER(SetObjectMouseCursorOverride);
    REGISTER(SetObjectHiliteColorOverride);
    REGISTER(RemoveEffectFromTURD);
    REGISTER(SetSpawnLocation);
    REGISTER(SendDMAllCreatorLists);
    REGISTER(AddCustomJournalEntry);
    REGISTER(GetJournalEntry);
    REGISTER(CloseStore);

#undef REGISTER

}

Player::~Player()
{
}

CNWSPlayer *Player::player(ArgumentStack& args)
{
    const auto playerId = Events::ExtractArgument<ObjectID>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Player function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerId);
    if (!pPlayer)
    {
        LOG_NOTICE("NWNX_Player function called on non-player object %x", playerId);
    }
    return pPlayer;
}

ArgumentStack Player::ForcePlaceableExamineWindow(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto placeableId = Events::ExtractArgument<ObjectID>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerExamineGui_PlaceableData(pPlayer, placeableId);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::ForcePlaceableInventoryWindow(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidTarget = Events::ExtractArgument<ObjectID>(args);
        const auto oidPlayer = pPlayer->m_oidNWSObject;

        if (auto *pPlaceable = Utils::AsNWSPlaceable(Utils::GetGameObject(oidTarget)))
        {
            pPlaceable->m_bHasInventory = 1;
            pPlaceable->OpenInventory(oidPlayer);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::StartGuiTimingBar(ArgumentStack&& args)
{
    static Hooks::Hook pHandlePlayerToServerInputCancelGuiTimingEventHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage45HandlePlayerToServerInputCancelGuiTimingEventEP10CNWSPlayer,
                (void*)+[](CNWSMessage* pMessage, CNWSPlayer* pPlayer) -> int32_t
                {
                    CNWSScriptVarTable *pScriptVarTable = Utils::GetScriptVarTable(Utils::GetGameObject(pPlayer->m_oidPCObject));

                    if (pScriptVarTable)
                    {
                        CExoString varName = "NWNX_PLAYER_GUI_TIMING_ACTIVE";
                        int32_t id = pScriptVarTable->GetInt(varName);

                        if (id > 0)
                        {
                            LOG_DEBUG("Cancelling GUI timing event id %d...", id);
                            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
                            pScriptVarTable->DestroyInt(varName);
                        }
                    }

                    return pHandlePlayerToServerInputCancelGuiTimingEventHook->CallOriginal<int32_t>(pMessage, pPlayer);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        const auto seconds = Events::ExtractArgument<float>(args);
        const auto milliseconds = static_cast<uint32_t>(seconds * 1000.0f); // NWN expects milliseconds.
        const auto type = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(type > 0);
          ASSERT_OR_THROW(type <= 10);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, true, type, milliseconds);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::StopGuiTimingBar(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SetAlwaysWalk(ArgumentStack&& args)
{
    static NWNXLib::Hooks::Hook pOnRemoveLimitMovementSpeed_hook =
            Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler26OnRemoveLimitMovementSpeedEP10CNWSObjectP11CGameEffect,
                (void*)+[](CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pEffect) -> int32_t
                {
                    // Don't remove the forced walk flag when various slowdown effects expire
                    auto walk = pObject->nwnxGet<int>("ALWAYS_WALK");
                    if (walk && *walk)
                        return 1;

                    return pOnRemoveLimitMovementSpeed_hook->CallOriginal<int32_t>(pThis, pObject, pEffect);
                }, Hooks::Order::Late);

    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (!pCreature)
        {
            LOG_ERROR("No creature object found for Player ID %x, oidNWSObject %x",
                pPlayer->m_oidPCObject, pPlayer->m_oidNWSObject);
            return Events::Arguments();
        }

        const auto bSetCap = Events::ExtractArgument<int32_t>(args);
        if (bSetCap)
        {
            pCreature->m_bForcedWalk = true;
            pCreature->nwnxSet("ALWAYS_WALK", 1, true);
        }
        else // remove the override
        {
            pCreature->nwnxRemove("ALWAYS_WALK");

            // Fake effect object for bsearch. Don't want to deal with alloc/free from real one..
            uint8_t key[sizeof(CGameEffect)];
            CGameEffect *pkey = (CGameEffect*)key;
            pkey->m_nType = 59; // NOTE: different from nwscript.nss

            // Check for any other effects that limit movement speed
            pCreature->m_bForcedWalk = !!std::bsearch(&pkey, pCreature->m_appliedEffects.element, pCreature->m_appliedEffects.num, sizeof(pkey),
                                            +[](const void *a, const void *b){ return ((CGameEffect*)a)->m_nType - ((CGameEffect*)b)->m_nType; });
            if (!pCreature->m_bForcedWalk)
            {
                pCreature->UpdateEncumbranceState(false);
                pCreature->m_bForcedWalk = (pCreature->m_nEncumbranceState != 0);
            }

        }
    }
    return Events::Arguments();
}

ArgumentStack Player::GetQuickBarSlot(ArgumentStack&& args)
{
    CNWSQuickbarButton qbs;
    if (auto *pPlayer = player(args))
    {
        auto slot = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(slot < 36);

        if (auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject))
        {
            if (!pCreature->m_pQuickbarButton)
                pCreature->InitializeQuickbar();

            qbs = pCreature->m_pQuickbarButton[slot];
        }
    }

    return Events::Arguments
    (
        (ObjectID)qbs.m_oidItem,
        (ObjectID)qbs.m_oidSecondaryItem,
        (int32_t)qbs.m_nObjectType,
        (int32_t)qbs.m_nMultiClass,
        std::string(qbs.m_cResRef.GetResRefStr()),
        std::string(qbs.m_sCommandLabel.CStr()),
        std::string(qbs.m_sCommandLine.CStr()),
        std::string(qbs.m_sToolTip.CStr()),
        (int32_t)qbs.m_nINTParam1,
        (int32_t)qbs.m_nMetaType,
        (int32_t)qbs.m_nDomainLevel,
        (int32_t)qbs.m_nAssociateType,
        (ObjectID)qbs.m_oidAssociate
    );
}

ArgumentStack Player::SetQuickBarSlot(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto slot = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(slot >= 0);
          ASSERT_OR_THROW(slot < 36);

        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (!pCreature->m_pQuickbarButton)
            pCreature->InitializeQuickbar();

        pCreature->m_pQuickbarButton[slot].m_oidAssociate     = Events::ExtractArgument<ObjectID>(args);
        pCreature->m_pQuickbarButton[slot].m_nAssociateType   = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nDomainLevel     = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nMetaType        = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nINTParam1       = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_sToolTip         = Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_sCommandLine     = Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_sCommandLabel    = Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_cResRef          = Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_nMultiClass      = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nObjectType      = Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_oidSecondaryItem = Events::ExtractArgument<ObjectID>(args);
        pCreature->m_pQuickbarButton[slot].m_oidItem          = Events::ExtractArgument<ObjectID>(args);

        auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
        pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, slot, 0);
    }
    return Events::Arguments();
}

ArgumentStack Player::GetBicFileName(ArgumentStack&& args)
{
    std::string retVal;
    if (auto *pPlayer = player(args))
    {
        retVal = std::string(pPlayer->m_resFileName.GetResRef(), pPlayer->m_resFileName.GetLength());
    }
    return Events::Arguments(retVal);
}

ArgumentStack Player::ShowVisualEffect(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        Vector pos;
        auto effectId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(effectId >= 0);
          ASSERT_OR_THROW(effectId <= 0xFFFF);
        pos.z = Events::ExtractArgument<float>(args);
        pos.y = Events::ExtractArgument<float>(args);
        pos.x = Events::ExtractArgument<float>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            ObjectVisualTransformData ovtd;
            pMessage->SendServerToPlayerArea_VisualEffect(pPlayer, effectId, pos, ovtd);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::ChangeBackgroundMusic(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto day   = Events::ExtractArgument<int32_t>(args);
        auto track = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(track >= 0);
          ASSERT_OR_THROW(track <= 0xFFFF);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerAmbientMusicChangeTrack(oidPlayer, day, track);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::PlayBackgroundMusic(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto play = Events::ExtractArgument<int32_t>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerAmbientMusicPlay(oidPlayer, play);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::ChangeBattleMusic(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto track = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(track >= 0);
          ASSERT_OR_THROW(track <= 0xFFFF);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerAmbientBattleMusicChange(oidPlayer, track);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::PlayBattleMusic(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto play = Events::ExtractArgument<int32_t>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerAmbientBattleMusicPlay(oidPlayer, play);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::PlaySound(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto playerID = pPlayer->m_nPlayerID;

        auto sound = Events::ExtractArgument<std::string>(args);

        auto oidTarget = Events::ExtractArgument<ObjectID>(args);

        if (oidTarget == Constants::OBJECT_INVALID)
        {
            oidTarget = pPlayer->m_oidNWSObject;
        }

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerAIActionPlaySound(playerID, oidTarget, sound.c_str());
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::SetPlaceableUsable(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto oidPlaceable = Events::ExtractArgument<ObjectID>(args);
        const auto bUsable = Events::ExtractArgument<int32_t>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->CreateWriteMessage(sizeof(bUsable) + sizeof(oidPlaceable), pPlayer->m_nPlayerID, 1);

            pMessage->WriteOBJECTIDServer(oidPlaceable);
            pMessage->WriteBOOL(bUsable);
            uint8_t *buffer;
            uint32_t size;

            if (pMessage->GetWriteMessage(&buffer, &size))
            {
                pMessage->SendServerToPlayerMessage(pPlayer->m_nPlayerID,
                                                    Constants::MessageMajor::GameObjectUpdate,
                                                    Constants::MessageGameObjectUpdateMinor::PlaceableUseable,
                                                    buffer, size);
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::SetRestDuration(ArgumentStack&& args)
{
    static Hooks::Hook pAIActionRestHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature12AIActionRestEP20CNWSObjectActionNode,
    (void*)+[](CNWSCreature* pCreature, CNWSObjectActionNode *pNode) -> uint32_t
            {
                if (auto restDuration = pCreature->nwnxGet<int>("REST_DURATION"))
                {
                    uint8_t creatureLevel = pCreature->m_pStats->GetLevel(0);
                    int32_t originalValue;
                    Globals::Rules()->m_p2DArrays->m_pRestDurationTable->GetINTEntry(creatureLevel, "DURATION", &originalValue);
                    Globals::Rules()->m_p2DArrays->m_pRestDurationTable->SetINTEntry(creatureLevel, "DURATION", *restDuration);
                    auto retVal = pAIActionRestHook->CallOriginal<uint32_t>(pCreature, pNode);
                    Globals::Rules()->m_p2DArrays->m_pRestDurationTable->SetINTEntry(creatureLevel, "DURATION", originalValue);
                    return retVal;
                }
                else
                    return pAIActionRestHook->CallOriginal<uint32_t>(pCreature, pNode);
            }, Hooks::Order::Late);

    if (auto *pPlayer = player(args))
    {
        auto duration = Events::ExtractArgument<int32_t>(args);

        auto playerObj = Utils::GetGameObject(pPlayer->m_oidNWSObject);
        if (duration < 0)
        {
            playerObj->nwnxRemove("REST_DURATION");
        }
        else
        {
            playerObj->nwnxSet("REST_DURATION", duration < 10 ? 10 : duration, true);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::ApplyInstantVisualEffectToObject(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto visualEffect = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(visualEffect >= 0); ASSERT_OR_THROW(visualEffect <= 65535);

        Vector vTargetPosition {};

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerGameObjUpdateVisEffect(pPlayer, visualEffect, oidTarget, Utils::GetModule()->m_idSelf,
                                                               0, 0, vTargetPosition, 0.0f);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::UpdateCharacterSheet(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto charSheet = pPlayer->m_pCharSheetGUI;
        uint32_t msg = charSheet->ComputeCharacterSheetUpdateRequired(pPlayer);
        if (msg)
        {
            if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
                pMessage->WriteGameObjUpdate_CharacterSheet(pPlayer, msg);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::OpenInventory(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto open = !!Events::ExtractArgument<int32_t>(args);

        CNWSPlayerInventoryGUI *pInventory = pPlayer->m_oidNWSObject == oidTarget ? pPlayer->m_pInventoryGUI :
                                                                                    pPlayer->m_pOtherInventoryGUI;

        auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
        if (pMessage && pInventory)
        {
            pMessage->SendPlayerToServerGuiInventory_Status(pPlayer, open, oidTarget);
            pInventory->SetOpen(open, 0/*bClientDirected*/);

            if (open)
            {
                pInventory->SetOwner(oidTarget);
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::GetAreaExplorationState(ArgumentStack&& args)
{
    std::string encString;

    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto areaId = Events::ExtractArgument<ObjectID>(args);
        if (pCreature && areaId != Constants::OBJECT_INVALID)
        {
            const auto pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaId);
            if (pArea)
            {
                uint32_t *p_oidArea = pCreature->m_oidAutoMapAreaList.element;
                for (int k = 0; k<pCreature->m_oidAutoMapAreaList.num; k++, p_oidArea++)
                {
                    if (*p_oidArea == areaId)
                    {
                        uint8_t *pTileData = *(pCreature->m_nAutoMapTileData + k);
                        if (pTileData)
                        {
                            std::vector<uint8_t> tileDataVector(&pTileData[0], &pTileData[pArea->m_nMapSize]);
                            encString = NWNXLib::String::ToBase64(tileDataVector);
                        }
                        break;
                    }
                }
            }
        }
    }
    return Events::Arguments(encString);
}

ArgumentStack Player::SetAreaExplorationState(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto areaId = Events::ExtractArgument<ObjectID>(args);
        if (pCreature && areaId != Constants::OBJECT_INVALID)
        {
            const auto pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaId);
            if (pArea)
            {
                auto encString = Events::ExtractArgument<std::string>(args);

                uint32_t *p_oidArea = pCreature->m_oidAutoMapAreaList.element;
                for (int k = 0; k<pCreature->m_oidAutoMapAreaList.num; k++, p_oidArea++)
                {
                    if (*p_oidArea == areaId)
                    {
                        uint8_t *pTileData = *(pCreature->m_nAutoMapTileData + k);
                        if (pTileData)
                        {
                            std::vector<uint8_t> tileDataVector = NWNXLib::String::FromBase64(encString);
                            std::copy(tileDataVector.begin(), tileDataVector.begin() + pArea->m_nMapSize, pTileData);
                        }
                        break;
                    }
                }
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::SetRestAnimation(ArgumentStack&& args)
{
    static Hooks::Hook pAIActionRestHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature12AIActionRestEP20CNWSObjectActionNode,
            (void*)+[](CNWSCreature* pCreature, CNWSObjectActionNode *pNode) -> uint32_t
            {
                auto retVal = pAIActionRestHook->CallOriginal<uint32_t>(pCreature, pNode);

                if (auto animation = pCreature->nwnxGet<int>("REST_ANIMATION"))
                {
                    if (retVal == 1/* In Progress*/)
                        pCreature->SetAnimation(*animation);
                }

                return retVal;
            }, Hooks::Order::Late);

    if (auto *pPlayer = player(args))
    {
        auto animation = Events::ExtractArgument<int32_t>(args);

        auto playerObj = Utils::GetGameObject(pPlayer->m_oidNWSObject);
        if (animation < 0)
        {
            playerObj->nwnxRemove("REST_ANIMATION");
        }
        else
        {
            playerObj->nwnxSet("REST_ANIMATION", animation, true);
        }
    }

    return Events::Arguments();
}


ArgumentStack Player::SetObjectVisualTransformOverride(ArgumentStack&& args)
{
    static Hooks::Hook pSetObjectVisualTransformOverrideHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        if (pObject->m_nObjectType == Constants::ObjectType::Creature ||
                            pObject->m_nObjectType == Constants::ObjectType::Placeable ||
                            pObject->m_nObjectType == Constants::ObjectType::Item ||
                            pObject->m_nObjectType == Constants::ObjectType::Door)
                        {
                            if (auto objectVisualTransformData = pObject->nwnxGet<void*>("OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                            {
                                auto *pObjectVisualTransformData = static_cast<ObjectVisualTransformData*>(*objectVisualTransformData);

                                std::swap(*pObjectVisualTransformData, pObject->m_pVisualTransformData);
                                pSetObjectVisualTransformOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                                std::swap(*pObjectVisualTransformData, pObject->m_pVisualTransformData);

                                return;
                            }
                        }
                    }
                    pSetObjectVisualTransformOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        const auto oidObject = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
        const auto transform = Events::ExtractArgument<int32_t>(args);
        const auto value = Events::ExtractArgument<float>(args);

        auto obj = Utils::GetGameObject(oidObject);
        if (transform < 0)
        {
            if (auto objectVisualTransformData = obj->nwnxGet<void*>("OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                auto pObjectVisualTransformData = static_cast<ObjectVisualTransformData*>(*objectVisualTransformData);

                obj->nwnxRemove("OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));

                delete pObjectVisualTransformData;
            }
        }
        else
        {
            ObjectVisualTransformData *pObjectVisualTransformData;

            if (auto objectVisualTransformData = obj->nwnxGet<void*>("OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                pObjectVisualTransformData = static_cast<ObjectVisualTransformData*>(*objectVisualTransformData);
            }
            else
            {
                pObjectVisualTransformData = new ObjectVisualTransformData();
                pObjectVisualTransformData->m_scale = Vector{1.0f, 1.0f, 1.0f};
                pObjectVisualTransformData->m_rotate = Vector{0.0f, 0.0f, 0.0f};
                pObjectVisualTransformData->m_translate = Vector{0.0f, 0.0f, 0.0f};
                pObjectVisualTransformData->m_animationSpeed = 1.0f;

                obj->nwnxSet("OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject),
                        pObjectVisualTransformData, [](void*p) { delete static_cast<ObjectVisualTransformData*>(p); });
            }

            switch (transform)
            {
                case Constants::ObjectVisualTransform::Scale:
                    pObjectVisualTransformData->m_scale.x = value;
                    break;

                case Constants::ObjectVisualTransform::RotateX:
                    pObjectVisualTransformData->m_rotate.x = value;
                    break;

                case Constants::ObjectVisualTransform::RotateY:
                    pObjectVisualTransformData->m_rotate.y = value;
                    break;

                case Constants::ObjectVisualTransform::RotateZ:
                    pObjectVisualTransformData->m_rotate.z = value;
                    break;

                case Constants::ObjectVisualTransform::TranslateX:
                    pObjectVisualTransformData->m_translate.x = value;
                    break;

                case Constants::ObjectVisualTransform::TranslateY:
                    pObjectVisualTransformData->m_translate.y = value;
                    break;

                case Constants::ObjectVisualTransform::TranslateZ:
                    pObjectVisualTransformData->m_translate.z = value;
                    break;

                case Constants::ObjectVisualTransform::AnimationSpeed:
                    pObjectVisualTransformData->m_animationSpeed = value;
                    break;

                default:
                    LOG_WARNING("NWNX_Player_SetObjectVisualTransformOverride called with invalid transform!");
                    break;
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::ApplyLoopingVisualEffectToObject(ArgumentStack&& args)
{
    static Hooks::Hook pApplyLoopingVisualEffectToObjectHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                            if (auto loopingVisualEffectSet = pObject->nwnxGet<void*>("LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                            {
                                auto *pLoopingVisualEffectSet = static_cast<std::set<uint16_t> *>(*loopingVisualEffectSet);

                                for(auto visualEffect : *pLoopingVisualEffectSet)
                                {
                                    pObject->AddLoopingVisualEffect(visualEffect, Constants::OBJECT_INVALID, 0);
                                }

                                pApplyLoopingVisualEffectToObjectHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);

                                for(auto visualEffect : *pLoopingVisualEffectSet)
                                {
                                    pObject->RemoveLoopingVisualEffect(visualEffect);
                                }

                                return;
                            }
                    }
                    pApplyLoopingVisualEffectToObjectHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto visualEffect = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(visualEffect <= 65535);

        auto target = Utils::GetGameObject(oidTarget);
        if (visualEffect < 0)
        {
            if (auto loopingVisualEffectSet = target->nwnxGet<void*>("LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                auto pLoopingVisualEffectSet = static_cast<std::set<uint16_t>*>(*loopingVisualEffectSet);

                target->nwnxRemove("LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));

                delete pLoopingVisualEffectSet;
            }
        }
        else
        {
            std::set<uint16_t> *pLoopingVisualEffectSet;

            if (auto loopingVisualEffectSet = target->nwnxGet<void*>("LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                pLoopingVisualEffectSet = static_cast<std::set<uint16_t>*>(*loopingVisualEffectSet);
            }
            else
            {
                pLoopingVisualEffectSet = new std::set<uint16_t>();

                target->nwnxSet("LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject),
                        pLoopingVisualEffectSet, [](void*p) { delete static_cast<std::set<uint16_t>*>(p); });
            }

            if (pLoopingVisualEffectSet->find(visualEffect) != pLoopingVisualEffectSet->end())
            {
                pLoopingVisualEffectSet->erase(visualEffect);
            }
            else
            {
                pLoopingVisualEffectSet->insert(visualEffect);
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::SetPlaceableNameOverride(ArgumentStack&& args)
{
    static Hooks::Hook pSetPlaceableNameOverrideHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pPlaceable = Utils::AsNWSPlaceable(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        if (auto name = pPlaceable->nwnxGet<std::string>("PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                        {
                            CExoString swapName = CExoString(*name);

                            std::swap(swapName, pPlaceable->m_sDisplayName);
                            pSetPlaceableNameOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                            std::swap(swapName, pPlaceable->m_sDisplayName);
                            return;
                        }
                    }
                    pSetPlaceableNameOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto name = Events::ExtractArgument<std::string>(args);

        if (auto *pPlaceable = Utils::AsNWSPlaceable(Utils::GetGameObject(oidTarget)))
        {
            if (name.empty())
            {
                pPlaceable->nwnxRemove("PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
            }
            else
            {
                pPlaceable->nwnxSet("PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject), name);
            }

            if (auto *pLastUpdateObject = pPlayer->GetLastUpdateObject(pPlaceable->m_idSelf))
            {
                pLastUpdateObject->m_nUpdateDisplayNameSeq--;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::GetQuestCompleted(ArgumentStack&& args)
{
    int32_t retval = -1;

    if (auto *pPlayer = player(args))
    {
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto questTag = Events::ExtractArgument<std::string>(args);

        if (pCreature && pCreature->m_pJournal)
        {
            auto entries = pCreature->m_pJournal->m_lstEntries;
            if (entries.num > 0)
            {
                auto pEntry = entries.element;
                for (int i = 0; i < entries.num; i++, pEntry++)
                {
                    if (pEntry->szPlot_Id.CStr() == questTag)
                    {
                        retval = pEntry->bQuestCompleted;
                        break;
                    }
                }
            }
        }
    }

    return Events::Arguments(retval);
}

ArgumentStack Player::SetPersistentLocation(ArgumentStack&& args)
{
    static Hooks::Hook pSetPersistentLocationHook =
        Hooks::HookFunction(API::Functions::_ZN21CServerExoAppInternal19LoadCharacterFinishEP10CNWSPlayerii,
                (void*)+[](CServerExoAppInternal *pServerExoAppInternal, CNWSPlayer *pPlayer, int32_t bUseSaveGameCharacter, int32_t bUseStateDataInSaveGame ) -> int32_t
                {
                    auto retVal = pSetPersistentLocationHook->CallOriginal<int32_t>(pServerExoAppInternal, pPlayer, bUseSaveGameCharacter, bUseStateDataInSaveGame);

                    std::string sKey;
                    std::string sBicFileName = std::string(pPlayer->m_resFileName.GetResRef(), pPlayer->m_resFileName.GetLength());
                    if (Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PersistantWorldOptions.bServerVaultByPlayerName)
                    {
                        std::string sCommunityName = pPlayer->GetPlayerName().CStr();
                        sKey = sCommunityName + "!" + sBicFileName;
                    }
                    else
                    {
                        auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
                        auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID);
                        std::string sCDKey = pPlayerInfo->m_lstKeys[0].sPublic.CStr();
                        sKey = sCDKey + "!" + sBicFileName;
                    }
                    auto wpOID = g_plugin->m_PersistentLocationWP[sKey].first;
                    if (!wpOID)
                        return retVal;

                    auto bFirstConnectOnly = g_plugin->m_PersistentLocationWP[sKey].second;

                    // Delete the key if this is the first connect and we're only setting the location on first connect
                    if (bFirstConnectOnly && !Utils::GetModule()->GetPlayerTURDFromList(pPlayer))
                    {
                        g_plugin->m_PersistentLocationWP.erase(sKey);
                    }
                        // The TURD exists already meaning its not the first connect
                    else if (bFirstConnectOnly)
                        return retVal;

                    // Fake some changes to their area/position as though they had a TURD
                    auto *pWP = Utils::AsNWSWaypoint(Utils::GetGameObject(wpOID));
                    if (pWP)
                    {
                        auto pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject));
                        pCreature->m_oidDesiredArea = pWP->m_oidArea;
                        pCreature->m_vDesiredAreaLocation = pWP->m_vPosition;
                        pCreature->m_bDesiredAreaUpdateComplete = false;
                        pCreature->m_vOrientation = pWP->m_vOrientation;
                        pPlayer->m_bFromTURD = true;
                        // We don't need the WP any more if we're only setting the location on first connect
                        if (bFirstConnectOnly)
                        {
                            Utils::AddDestroyObjectEvent(pWP->m_idSelf);
                        }
                    }
                    return retVal;
                }, Hooks::Order::Early);

    const auto sCDKeyOrCommunityName = Events::ExtractArgument<std::string>(args);
    const auto sBicFileName = Events::ExtractArgument<std::string>(args);
    const auto wpOid = Events::ExtractArgument<ObjectID>(args);
    const auto bFirstConnectOnly = Events::ExtractArgument<int32_t>(args);

    std::string sKey = sCDKeyOrCommunityName + "!" + sBicFileName;
    g_plugin->m_PersistentLocationWP[sKey] = std::make_pair(wpOid, bFirstConnectOnly);

    return Events::Arguments();
}

ArgumentStack Player::UpdateItemName(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto oidItem = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidItem != Constants::OBJECT_INVALID);

        auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItem));
        auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();

        if (pItem && pMessage)
        {
            pMessage->SendServerToPlayerUpdateItemName(pPlayer, pItem);
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::PossessCreature(ArgumentStack&& args)
{
    const auto possessorId = Events::ExtractArgument<ObjectID>(args);
    const auto possessedId = Events::ExtractArgument<ObjectID>(args);
    const auto bMindImmune = Events::ExtractArgument<int>(args);
    const auto bCreateQB = Events::ExtractArgument<int>(args);

    auto pServer = Globals::AppManager()->m_pServerExoApp;
    auto *pPossessor = pServer->GetCreatureByGameObjectID(possessorId);
    if (!pPossessor || !pPossessor->m_bPlayerCharacter)
    {
        LOG_ERROR("Attempt to possess a creature with an invalid possessor.");
        return Events::Arguments(0);
    }
    auto *pPossessed = pServer->GetCreatureByGameObjectID(possessedId);
    if (!pPossessed || pPossessed->m_bPlayerCharacter)
    {
        LOG_ERROR("Attempt to possess an invalid creature.");
        return Events::Arguments(0);
    }
    if (pPossessor->m_oidArea != pPossessed->m_oidArea)
    {
        LOG_ERROR("Attempt to possess a creature not in the current area.");
        return Events::Arguments(0);
    }
    if (pServer->GetIsControlledByPlayer(possessedId))
    {
        LOG_ERROR("Attempt to possess a creature already possessed.");
        return Events::Arguments(0);
    }
    auto possessedOidPOS = pPossessor->nwnxGet<int>("possessedOid");
    if (possessedOidPOS)
    {
        LOG_ERROR("Attempt to possess a creature while already possessing.");
        return Events::Arguments(0);
    }

    // When a PC is logging off we don't want this creature to unsummon themselves (unless crashed in AT)
    static NWNXLib::Hooks::Hook pUnsummonMyselfHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature14UnsummonMyselfEv,
            (void*)+[](CNWSCreature *pPossessed) -> void
            {
                auto possessorOidPOS = pPossessed->nwnxGet<int>("possessorOid");
                auto pServer = Globals::AppManager()->m_pServerExoApp;
                auto *pPossessor = possessorOidPOS ? pServer->GetCreatureByGameObjectID(*possessorOidPOS) : nullptr;

                //Possessed, not in limbo
                if (pPossessor && pPossessed->m_oidArea != Constants::OBJECT_INVALID)
                {
                    pPossessor->UnpossessFamiliar();
                }
                else
                {
                    pUnsummonMyselfHook->CallOriginal<void>(pPossessed);
                    // Remove the mind immunity effect from the possessor if they were in limbo
                    if (pPossessor && pPossessed->m_oidArea == Constants::OBJECT_INVALID)
                    {
                        for (int i = 0; i < pPossessor->m_appliedEffects.num; i++)
                        {
                            auto *eff = pPossessor->m_appliedEffects.element[i];
                            if (eff->m_nType == Constants::EffectTrueType::Immunity &&
                                eff->m_nSubType == Constants::EffectSubType::Magical &&
                                eff->m_oidCreator == pPossessor->m_idSelf &&
                                eff->m_fDuration == 4.0f &&
                                eff->m_nCasterLevel == -1 &&
                                eff->m_nParamInteger[0] == Constants::ImmunityType::MindSpells &&
                                eff->m_nParamInteger[1] == Constants::RacialType::Invalid)
                            {
                                pPossessor->RemoveEffectById(eff->m_nID);
                                break;
                            }
                        }
                    }
                }
            }, Hooks::Order::Late);

    static NWNXLib::Hooks::Hook pPossessFamiliarHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature15PossessFamiliarEv,
                (void*)+[](CNWSCreature *pPossessor) -> void
                {
                    auto possessorOidPOS = pPossessor->nwnxGet<int>("possessorOid");
                    if (possessorOidPOS)
                    {
                        LOG_ERROR("Attempt to possess a familiar while already possessing.");
                    }
                    else
                    {
                        pPossessFamiliarHook->CallOriginal<void>(pPossessor);
                    }
                }, Hooks::Order::Late);

    static NWNXLib::Hooks::Hook pUnpossessFamiliarHook =
            Hooks::HookFunction(Functions::_ZN12CNWSCreature17UnpossessFamiliarEv,
                (void*)+[](CNWSCreature *pPossessor) -> void
                {
                    pUnpossessFamiliarHook->CallOriginal<void>(pPossessor);

                    auto possessedOidPOS = pPossessor->nwnxGet<int>("possessedOid");
                    if (possessedOidPOS)
                    {
                        pPossessor->RemoveAssociate(*possessedOidPOS);
                        pPossessor->nwnxRemove("possessedOid");
                        Utils::GetGameObject(*possessedOidPOS)->nwnxRemove("possessorOid");

                        auto possessedAssociateType = pPossessor->nwnxGet<int>("possessedAssociateType");
                        if (possessedAssociateType && *possessedAssociateType != Constants::AssociateType::None)
                        {
                            pPossessor->AddAssociate(*possessedOidPOS, *possessedAssociateType);
                            pPossessor->nwnxRemove("possessedAssociateType");
                        }
                    }
                }, Hooks::Order::Early);

    // Save previous associate type so it can be set back after unpossess
    pPossessor->nwnxSet("possessedAssociateType", (int32_t)pPossessed->m_nAssociateType);

    // If they already have a familiar we temporarily remove it as an associate
    // then we add the possessed creature as a familiar. We then add the regular familiar back.
    // This is because PossessFamiliar looks for the first associate of type familiar.
    auto pFamiliarId = pPossessor->GetAssociateId(Constants::AssociateType::Familiar, 1);
    if (pFamiliarId)
        pPossessor->RemoveAssociate(pFamiliarId);

    pPossessor->AddAssociate(possessedId, Constants::AssociateType::Familiar);
    pPossessor->PossessFamiliar();

    if (pFamiliarId)
        pPossessor->AddAssociate(pFamiliarId, Constants::AssociateType::Familiar);

    if (bCreateQB)
        pPossessed->CreateDefaultQuickButtons();

    pPossessor->nwnxSet("possessedOid", (int32_t)possessedId);
    pPossessed->nwnxSet("possessorOid", (int32_t)possessorId);

    // Familiar possession gives the possessor mind immunity, we remove it if we don't want that
    if (!bMindImmune)
    {
        for (int i = 0; i < pPossessor->m_appliedEffects.num; i++)
        {
            auto *eff = pPossessor->m_appliedEffects.element[i];
            if (eff->m_nType == Constants::EffectTrueType::Immunity &&
                eff->m_nSubType == Constants::EffectSubType::Magical &&
                eff->m_oidCreator == pPossessor->m_idSelf &&
                eff->m_fDuration == 4.0f &&
                eff->m_nCasterLevel == -1 &&
                eff->m_nParamInteger[0] == Constants::ImmunityType::MindSpells &&
                eff->m_nParamInteger[1] == Constants::RacialType::Invalid)
            {
                pPossessor->RemoveEffectById(eff->m_nID);
                break;
            }
        }
    }
    return Events::Arguments(1);
}

ArgumentStack Player::GetPlatformId(ArgumentStack&& args)
{
    int32_t id = 0;
    if (auto *pPlayer = player(args))
    {
        auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
        if (auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID))
            id = pPlayerInfo->m_nPlatformId;
    }
    return Events::Arguments(id);
}

ArgumentStack Player::GetLanguage(ArgumentStack&& args)
{
    int32_t id = 0;
    if (auto *pPlayer = player(args))
    {
        auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();
        if (auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID))
            id = pPlayerInfo->m_nPlayerLanguage;
    }
    return Events::Arguments(id);
}

ArgumentStack Player::SetResManOverride(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto resType = Events::ExtractArgument<int32_t>(args);
        const auto oldResName = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!oldResName.empty());
          ASSERT_OR_THROW(oldResName.size() <= 16);
        const auto newResName = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(newResName.size() <= 16);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerResmanOverride(pPlayer->m_nPlayerID, resType, oldResName.c_str(), newResName.c_str());
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SetCustomToken(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        const auto tokenNumber = Events::ExtractArgument<int32_t>(args);
        const auto tokenText = Events::ExtractArgument<std::string>(args);

        if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
        {
            pMessage->SendServerToPlayerSetCustomToken(pPlayer->m_nPlayerID, tokenNumber, tokenText.c_str());
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SetCreatureNameOverride(ArgumentStack&& args)
{
    static Hooks::Hook pSetCreatureNameOverrideHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                 (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                 {
                     if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidObjectToUpdate)))
                     {
                         if (auto name = pCreature->nwnxGet<std::string>("CRENO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                         {
                             CExoString swapName = CExoString(*name);

                             std::swap(swapName, pCreature->m_sDisplayName);
                             pSetCreatureNameOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                             std::swap(swapName, pCreature->m_sDisplayName);
                             return;
                         }
                     }
                     pSetCreatureNameOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                 }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto name = Events::ExtractArgument<std::string>(args);

        if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidTarget)))
        {
            if (name.empty())
            {
                pCreature->nwnxRemove("CRENO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
            }
            else
            {
                pCreature->nwnxSet("CRENO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject), name);
            }

            if (auto *pLastUpdateObject = pPlayer->GetLastUpdateObject(pCreature->m_idSelf))
            {
                pLastUpdateObject->m_nUpdateDisplayNameSeq--;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::FloatingTextStringOnCreature(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto oidCreature = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidCreature != Constants::OBJECT_INVALID);
        auto text = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!text.empty());

        if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidCreature)))
        {
            if (auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
            {
                CNWCCMessageData messageData;
                messageData.SetObjectID(0, pCreature->m_idSelf);
                messageData.SetInteger(9, 94);
                messageData.SetString(0, text);

                pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID, Constants::MessageClientSideMsgMinor::Feedback, &messageData, nullptr);
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::ToggleDM(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto isDM = !!Events::ExtractArgument<int32_t>(args);
        auto *pNetLayer = Globals::AppManager()->m_pServerExoApp->GetNetLayer();

        if (auto *pPlayerInfo = pNetLayer->GetPlayerInfo(pPlayer->m_nPlayerID))
        {
            if (!pPlayerInfo->SatisfiesBuild(8193, 14))
            {
                LOG_WARNING("ToggleDM: Target player's client does not support PlayerDM functionality");
                return Events::Arguments();
            }

            if (pPlayerInfo->m_bGameMasterPrivileges && !pPlayerInfo->m_bGameMasterIsPlayerLogin)
            {
                LOG_WARNING("ToggleDM: Called on a DMClient DM");
                return Events::Arguments();
            }

            if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            {
                bool currentlyPlayerDM = pPlayerInfo->m_bGameMasterPrivileges && pPlayerInfo->m_bGameMasterIsPlayerLogin;

                if (isDM && !currentlyPlayerDM)
                {
                    pPlayerInfo->m_bGameMasterPrivileges = true;
                    pPlayerInfo->m_bGameMasterIsPlayerLogin = true;
                    pMessage->SendServerToPlayerDungeonMasterLoginState(pPlayer, true, true);

                    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
                    {
                    	pCreature->m_pStats->m_bDMManifested = true;
                    	pCreature->UpdateVisibleList();
                    }

                    Globals::AppManager()->m_pServerExoApp->AddToExclusionList(pPlayer->m_oidNWSObject, 1/*Timestop*/);
                    Globals::AppManager()->m_pServerExoApp->AddToExclusionList(pPlayer->m_oidNWSObject, 2/*Pause*/);
                    uint8_t nActivePauseState = Globals::AppManager()->m_pServerExoApp->GetActivePauseState();
                    pMessage->SendServerToPlayerModule_SetPauseState(nActivePauseState, nActivePauseState > 0);

                    pMessage->SendServerToPlayerDungeonMasterAreaList(pPlayer->m_nPlayerID);
                    pMessage->SendServerToPlayerDungeonMasterCreatorLists(pPlayer);
                }
                else if (!isDM && currentlyPlayerDM)
                {
                    pPlayer->PossessCreature(Constants::OBJECT_INVALID, Constants::AssociateType::None);

                    pPlayerInfo->m_bGameMasterPrivileges = false;
                    pPlayerInfo->m_bGameMasterIsPlayerLogin = false;
                    pMessage->SendServerToPlayerDungeonMasterLoginState(pPlayer, false, true);

                    if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
                    {
                        pCreature->m_pStats->m_bDMManifested = true;
                        pCreature->UpdateVisibleList();
                    }

                    Globals::AppManager()->m_pServerExoApp->RemoveFromExclusionList(pPlayer->m_oidNWSObject, 1/*Timestop*/);
                    Globals::AppManager()->m_pServerExoApp->RemoveFromExclusionList(pPlayer->m_oidNWSObject, 2/*Pause*/);
                    uint8_t nActivePauseState = Globals::AppManager()->m_pServerExoApp->GetActivePauseState();
                    pMessage->SendServerToPlayerModule_SetPauseState(nActivePauseState, nActivePauseState > 0);
                }
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SetObjectMouseCursorOverride(ArgumentStack&& args)
{
    static Hooks::Hook pSetObjectMouseCursorOverrideHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        if (auto cursorId = pObject->nwnxGet<int32_t>("OBJCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                        {
                            std::swap(*cursorId, pObject->m_nMouseCursor);
                            pSetObjectMouseCursorOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                            std::swap(*cursorId, pObject->m_nMouseCursor);
                            return;
                        }
                    }
                    pSetObjectMouseCursorOverrideHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto cursorId = Events::ExtractArgument<int32_t>(args);

        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidTarget)))
        {
            if (cursorId < 0)
            {
                pObject->nwnxRemove("OBJCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
            }
            else
            {
                pObject->nwnxSet("OBJCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject), cursorId);
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::SetObjectHiliteColorOverride(ArgumentStack&& args)
{
    static Hooks::Hook pSetObjectHiliteColorHook =
            Hooks::HookFunction(Functions::_ZN11CNWSMessage32ComputeGameObjectUpdateForObjectEP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayj,
                (void*)+[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray, ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        if (auto hiliteColor = pObject->nwnxGet<int32_t>("OBJHCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                        {
                            Vector vHiliteColor = {};
                            vHiliteColor.x = (float)((*hiliteColor >> 16) & 0xFF) / 255.0f; // R
                            vHiliteColor.y = (float)((*hiliteColor >> 8) & 0xFF) / 255.0f;  // G
                            vHiliteColor.z = (float)(*hiliteColor & 0xFF) / 255.0f;         // B

                            std::swap(vHiliteColor, pObject->m_vHiliteColor);
                            pSetObjectHiliteColorHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                            std::swap(vHiliteColor, pObject->m_vHiliteColor);
                            return;
                        }
                    }
                    pSetObjectHiliteColorHook->CallOriginal<void>(pMessage, pPlayer, pPlayerGameObject, pGameObjectArray, oidObjectToUpdate);
                }, Hooks::Order::Early);

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto hiliteColor = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(hiliteColor <= 0xFFFFFF);

        if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidTarget)))
        {
            if (hiliteColor < 0)
            {
                pObject->nwnxRemove("OBJHCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
            }
            else
            {
                pObject->nwnxSet("OBJHCO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject), hiliteColor);
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Player::RemoveEffectFromTURD(ArgumentStack&& args)
{
    const auto oidPlayer = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidPlayer != Constants::OBJECT_INVALID);
    const auto effectTag = Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!effectTag.empty());

    auto *pTURDList = Utils::GetModule()->m_lstTURDList.m_pcExoLinkedListInternal;
    if (!pTURDList)
        return Events::Arguments();

    for (auto *pNode = pTURDList->pHead; pNode; pNode = pNode->pNext)
    {
        auto *pTURD = static_cast<CNWSPlayerTURD*>(pNode->pObject);

        if (pTURD && pTURD->m_oidPlayer == oidPlayer)
        {
            std::vector<uint64_t> remove(128);
            for (int i = 0; i < pTURD->m_appliedEffects.num; i++)
            {
                auto *pEffect = pTURD->m_appliedEffects.element[i];

                if (pEffect->m_sCustomTag == effectTag)
                    remove.push_back(pEffect->m_nID);
            }
            for (auto id: remove)
                pTURD->RemoveEffectById(id);
            break;
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SetSpawnLocation(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto oidArea = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidArea != Constants::OBJECT_INVALID);
          ASSERT_OR_THROW(Utils::AsNWSArea(Utils::GetGameObject(oidArea)));
        auto x = Events::ExtractArgument<float>(args);
        auto y = Events::ExtractArgument<float>(args);
        auto z = Events::ExtractArgument<float>(args);
        auto facing = Events::ExtractArgument<float>(args);

        if (auto pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
        {
            pPlayer->m_bFromTURD = true;

            pCreature->m_oidDesiredArea = oidArea;
            pCreature->m_vDesiredAreaLocation = {x, y, z};
            pCreature->m_bDesiredAreaUpdateComplete = false;
            Utils::SetOrientation(pCreature, facing);
        }
    }

    return Events::Arguments();
}

ArgumentStack Player::SendDMAllCreatorLists(ArgumentStack&& args)
{
    if(auto *pPlayer = player(args))
    {
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);

        if(pCreature && pCreature->m_pStats->GetIsDM())
        {
            if (auto* pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            {
                auto original = pPlayer->m_bWasSentITP;
                pPlayer->m_bWasSentITP=false;
                pMessage->SendServerToPlayerDungeonMasterCreatorLists(pPlayer);
                pPlayer->m_bWasSentITP=original;
            }

        }
    }

    return Events::Arguments();
}

ArgumentStack Player::AddCustomJournalEntry(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pPlayer = player(args))
    {
        if (auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject))
        {
            const auto questName = Events::ExtractArgument<std::string>(args);
            const auto questText = Events::ExtractArgument<std::string>(args);
            const auto tag = Events::ExtractArgument<std::string>(args);

            ASSERT_OR_THROW(!tag.empty());

            const auto state = Events::ExtractArgument<int32_t>(args);
            const auto priority = Events::ExtractArgument<int32_t>(args);
            const auto completed = Events::ExtractArgument<int32_t>(args);
            const auto displayed = Events::ExtractArgument<int32_t>(args);
            const auto updated = Events::ExtractArgument<int32_t>(args);

            auto calDay = Events::ExtractArgument<int32_t>(args);
            auto timeDay = Events::ExtractArgument<int32_t>(args);
            auto silentUpdate = Events::ExtractArgument<int32_t>(args);

            ASSERT_OR_THROW(state >= 0);
            ASSERT_OR_THROW(priority >= 0);
            ASSERT_OR_THROW(completed >= 0);
            ASSERT_OR_THROW(displayed >= 0);
            ASSERT_OR_THROW(updated >= 0);
            ASSERT_OR_THROW(silentUpdate >= 0);

            CNWSJournal *pJournal = pCreature->GetJournal();
              ASSERT_OR_THROW(pJournal);// Should never happen, but still.

            // If server owner leaves this 0 - the entry will be added with today's date
            if (calDay <= 0)
            {
                calDay = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetWorldTimeCalendarDay();
            }
            //If server owner leaves this 0 - the entry will be added with now() time
            if (timeDay <= 0)
            {
                timeDay = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetWorldTimeTimeOfDay();
            }

            if (auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage())
            {
                auto entries = pJournal->m_lstEntries;
                SJournalEntry newJournal; // Only instantiate the struct if the message was created
                newJournal.szName          = Utils::CreateLocString(questName,0,0);
                newJournal.szText          = Utils::CreateLocString(questText,0,0);
                newJournal.nCalendarDay    = calDay;
                newJournal.nTimeOfDay      = timeDay;
                newJournal.szPlot_Id       = CExoString(tag.c_str());
                newJournal.nState          = state;
                newJournal.nPriority       = priority;
                newJournal.nPictureIndex   = 0; // Not implemented by bioware/beamdog
                newJournal.bQuestCompleted = completed;
                newJournal.bQuestDisplayed = displayed;
                newJournal.bUpdated        = updated;
                int overwrite = -1;
                if (entries.num > 0)
                {
                    for (int i = entries.num - 1; i >= 0; i--)
                    {
                        auto pEntry = entries.element[i];
                        if (pEntry.szPlot_Id.CStr() == tag)
                        {
                            overwrite = i;
                            // Overwrite existing entry
                            pJournal->m_lstEntries[i] = newJournal;
                            break;
                        }
                    }
                }
                // If we have overwritten an existing entry - we don't need to perform an add -
                // Instead we perform an update only
                if(overwrite == -1)
                {
                    // New entry added
                    pJournal->m_lstEntries.Add(newJournal);
                }
                pMessage->SendServerToPlayerJournalAddQuest(pPlayer,
                                                            newJournal.szPlot_Id,
                                                            newJournal.nState,
                                                            newJournal.nPriority,
                                                            newJournal.nPictureIndex,
                                                            newJournal.bQuestCompleted,
                                                            newJournal.nCalendarDay,
                                                            newJournal.nTimeOfDay,
                                                            newJournal.szName,
                                                            newJournal.szText);
                retval = pJournal->m_lstEntries.num; // Success

                //If no update message is desired, we can keep it silent.
                if(!silentUpdate)
                {
                    pMessage->SendServerToPlayerJournalUpdated(pPlayer,1,newJournal.bQuestCompleted,newJournal.szName);
                }
            }
            else
            {
                LOG_ERROR("Unable to get CNWSMessage");
            }
        }
    }
    return Events::Arguments(retval);
}

ArgumentStack Player::GetJournalEntry(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (pCreature && pCreature->m_pJournal)
        {
            auto entries = pCreature->m_pJournal->m_lstEntries;
            const auto tag = Events::ExtractArgument<std::string>(args);
            ASSERT_OR_THROW(!tag.empty());
            if (entries.num > 0)
            {
                for (int i = entries.num - 1; i >= 0; i--)
                {
                    auto pEntry = entries.element[i];
                    if (pEntry.szPlot_Id.CStr() == tag)
                    {
                        SJournalEntry lastJournalEntry = entries[i];
                        return Events::Arguments
                        (
                            std::string(Utils::ExtractLocString(lastJournalEntry.szText)),
                            std::string(Utils::ExtractLocString(lastJournalEntry.szName)),
                            (int32_t)lastJournalEntry.nCalendarDay,
                            (int32_t)lastJournalEntry.nTimeOfDay,
                            (int32_t)lastJournalEntry.nState,
                            (int32_t)lastJournalEntry.nPriority,
                            (int32_t)lastJournalEntry.bQuestCompleted,
                            (int32_t)lastJournalEntry.bQuestDisplayed,
                            (int32_t)lastJournalEntry.bUpdated
                        );
                    }
                }
            }
        }
    }
    return Events::Arguments(-1);
}

ArgumentStack Player::CloseStore(ArgumentStack&& args)
{
    if (auto *pPlayer = player(args))
    {
        if (auto *pPlayerStoreGUI = pPlayer->m_pStoreGUI)
        {
            pPlayerStoreGUI->CloseStore(pPlayer, true);
        }
    }

    return Events::Arguments();
}

}
