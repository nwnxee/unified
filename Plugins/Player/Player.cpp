#include "Player.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoArrayListTemplatedCNWSScriptVar.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSQuickbarButton.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayerCharSheetGUI.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSJournal.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CExoArrayListTemplatedSJournalEntry.hpp"
#include "API/C2DA.hpp"
#include "API/ObjectVisualTransformData.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Encoding.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Player::Player> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Player",
        "Functions exposing additional player properties and commands",
        "various / sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Player::Player(params);
    return g_plugin;
}


namespace Player {

Player::Player(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
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

#undef REGISTER

}

Player::~Player()
{
}

CNWSPlayer *Player::player(ArgumentStack& args)
{
    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);

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
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto placeableId = Services::Events::ExtractArgument<Types::ObjectID>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerExamineGui_PlaceableData(pPlayer, placeableId);
        }
        else
        {
            LOG_ERROR("Unable to get CNWSMessage");
        }
    }

    return stack;
}

ArgumentStack Player::ForcePlaceableInventoryWindow(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);
        const auto oidPlayer = pPlayer->m_oidNWSObject;

        if (auto *pPlaceable = Utils::AsNWSPlaceable(Utils::GetGameObject(oidTarget)))
        {
            pPlaceable->OpenInventory(oidPlayer);
        }
    }

    return stack;
}

ArgumentStack Player::StartGuiTimingBar(ArgumentStack&& args)
{
    static bool bHandlePlayerToServerInputCancelGuiTimingEventHook;

    if (!bHandlePlayerToServerInputCancelGuiTimingEventHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent, int32_t>(
                +[](Services::Hooks::CallType type, CNWSMessage* pMessage, CNWSPlayer* pPlayer) -> void
                {
                    // Before or after doesn't matter, just pick one so it happens only once
                    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
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
                    }
                });
        bHandlePlayerToServerInputCancelGuiTimingEventHook = true;
    }

    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto seconds = Services::Events::ExtractArgument<float>(args);
        const auto milliseconds = static_cast<uint32_t>(seconds * 1000.0f); // NWN expects milliseconds.

        int32_t type;

        //TODO-64Bit: Remove this try/catch block
        try
        {
            type = Services::Events::ExtractArgument<int32_t>(args);
        }
        catch(...)
        {
            type = 10;
        }

        ASSERT_OR_THROW(type > 0);
        ASSERT_OR_THROW(type <= 10);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, true, type, milliseconds);
        }
        else
        {
            LOG_ERROR("Unable to get CNWSMessage");
        }
    }

    return stack;
}

ArgumentStack Player::StopGuiTimingBar(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
        }
        else
        {
            LOG_ERROR("Unable to get CNWSMessage");
        }

    }

    return stack;
}

ArgumentStack Player::SetAlwaysWalk(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pOnRemoveLimitMovementSpeed_hook;

    if (!pOnRemoveLimitMovementSpeed_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSEffectListHandler__OnRemoveLimitMovementSpeed>(
            +[](CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pEffect) -> int32_t
            {
                // Don't remove the forced walk flag when various slowdown effects expire
                auto walk = g_plugin->GetServices()->m_perObjectStorage->Get<int>(pObject->m_idSelf, "ALWAYS_WALK");
                if (walk && *walk)
                    return 1;

                return pOnRemoveLimitMovementSpeed_hook->CallOriginal<int32_t>(pThis, pObject, pEffect);
            });
        pOnRemoveLimitMovementSpeed_hook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSEffectListHandler__OnRemoveLimitMovementSpeed);
    }

    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (!pCreature)
        {
            LOG_ERROR("No creature object found for Player ID %x, oidNWSObject %x",
                pPlayer->m_oidPCObject, pPlayer->m_oidNWSObject);
            return stack;
        }

        const auto bSetCap = Services::Events::ExtractArgument<int32_t>(args);
        if (bSetCap)
        {
            pCreature->m_bForcedWalk = true;
            g_plugin->GetServices()->m_perObjectStorage->Set(pPlayer->m_oidNWSObject, "ALWAYS_WALK", 1);
        }
        else // remove the override
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pPlayer->m_oidNWSObject, "ALWAYS_WALK");

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

    return stack;
}

ArgumentStack Player::GetQuickBarSlot(ArgumentStack&& args)
{
    ArgumentStack stack;
    CNWSQuickbarButton qbs;
    if (auto *pPlayer = player(args))
    {
        auto slot = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(slot < 36);

        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (!pCreature->m_pQuickbarButton)
            pCreature->InitializeQuickbar();

        qbs = pCreature->m_pQuickbarButton[slot];
    }

    Services::Events::InsertArgument(stack, (Types::ObjectID)qbs.m_oidItem);
    Services::Events::InsertArgument(stack, (Types::ObjectID)qbs.m_oidSecondaryItem);
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nObjectType);
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nMultiClass);
    Services::Events::InsertArgument(stack, std::string(qbs.m_cResRef.GetResRefStr()));
    Services::Events::InsertArgument(stack, std::string(qbs.m_sCommandLabel.CStr()));
    Services::Events::InsertArgument(stack, std::string(qbs.m_sCommandLine.CStr()));
    Services::Events::InsertArgument(stack, std::string(qbs.m_sToolTip.CStr()));
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nINTParam1);
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nMetaType);
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nDomainLevel);
    Services::Events::InsertArgument(stack, (int32_t)qbs.m_nAssociateType);
    Services::Events::InsertArgument(stack, (Types::ObjectID)qbs.m_oidAssociate);
    return stack;
}

ArgumentStack Player::SetQuickBarSlot(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        auto slot = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(slot >= 0);
          ASSERT_OR_THROW(slot < 36);

        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        if (!pCreature->m_pQuickbarButton)
            pCreature->InitializeQuickbar();

        pCreature->m_pQuickbarButton[slot].m_oidAssociate     = Services::Events::ExtractArgument<Types::ObjectID>(args);
        pCreature->m_pQuickbarButton[slot].m_nAssociateType   = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nDomainLevel     = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nMetaType        = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nINTParam1       = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_sToolTip         = Services::Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_sCommandLine     = Services::Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_sCommandLabel    = Services::Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_cResRef          = Services::Events::ExtractArgument<std::string>(args).c_str();
        pCreature->m_pQuickbarButton[slot].m_nMultiClass      = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_nObjectType      = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pQuickbarButton[slot].m_oidSecondaryItem = Services::Events::ExtractArgument<Types::ObjectID>(args);
        pCreature->m_pQuickbarButton[slot].m_oidItem          = Services::Events::ExtractArgument<Types::ObjectID>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, slot, 0);
    }
    return stack;
}

ArgumentStack Player::GetBicFileName(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        Services::Events::InsertArgument(stack, std::string(pPlayer->m_resFileName.GetResRef(), pPlayer->m_resFileName.GetLength()));
    }
    return stack;
}

ArgumentStack Player::ShowVisualEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        Vector pos;
        auto effectId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(effectId >= 0);
          ASSERT_OR_THROW(effectId <= 0xFFFF);
        pos.z = Services::Events::ExtractArgument<float>(args);
        pos.y = Services::Events::ExtractArgument<float>(args);
        pos.x = Services::Events::ExtractArgument<float>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerArea_VisualEffect(pPlayer, effectId, pos);
        }
    }
    return stack;
}

ArgumentStack Player::ChangeBackgroundMusic(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto day   = Services::Events::ExtractArgument<int32_t>(args);
        auto track = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(track >= 0);
          ASSERT_OR_THROW(track <= 0xFFFF);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerAmbientMusicChangeTrack(oidPlayer, day, track);
        }
    }
    return stack;
}

ArgumentStack Player::PlayBackgroundMusic(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto play = Services::Events::ExtractArgument<int32_t>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerAmbientMusicPlay(oidPlayer, play);
        }
    }
    return stack;
}

ArgumentStack Player::ChangeBattleMusic(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto track = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(track >= 0);
          ASSERT_OR_THROW(track <= 0xFFFF);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerAmbientBattleMusicChange(oidPlayer, track);
        }
    }
    return stack;
}

ArgumentStack Player::PlayBattleMusic(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidPlayer = pPlayer->m_nPlayerID;

        auto play = Services::Events::ExtractArgument<int32_t>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerAmbientBattleMusicPlay(oidPlayer, play);
        }
    }
    return stack;
}

ArgumentStack Player::PlaySound(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto playerID = pPlayer->m_nPlayerID;

        auto sound = Services::Events::ExtractArgument<std::string>(args);

        auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);

        if (oidTarget == Constants::OBJECT_INVALID)
        {
            oidTarget = pPlayer->m_oidNWSObject;
        }

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerAIActionPlaySound(playerID, oidTarget, sound.c_str());
        }
    }
    return stack;
}

ArgumentStack Player::SetPlaceableUsable(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto oidPlaceable = Services::Events::ExtractArgument<Types::ObjectID>(args);
        const auto bUsable = Services::Events::ExtractArgument<int32_t>(args);

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
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
    return stack;
}

ArgumentStack Player::SetRestDuration(ArgumentStack&& args)
{
    static bool bAIActionRestHook;

    if (!bAIActionRestHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__AIActionRest, int32_t>(
            +[](Services::Hooks::CallType type, CNWSCreature* pCreature, CNWSObjectActionNode*) -> void
            {
                static int32_t creatureLevel;
                static int32_t originalValue;

                if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
                {
                    creatureLevel = pCreature->m_pStats->GetLevel(0);

                    Globals::Rules()->m_p2DArrays->m_pRestDurationTable->GetINTEntry(creatureLevel, "DURATION", &originalValue);

                    if (auto restDuration = g_plugin->GetServices()->m_perObjectStorage->Get<int>(pCreature->m_idSelf, "REST_DURATION"))
                    {
                        Globals::Rules()->m_p2DArrays->m_pRestDurationTable->SetINTEntry(creatureLevel, "DURATION", *restDuration);
                    }
                }
                else
                {
                    Globals::Rules()->m_p2DArrays->m_pRestDurationTable->SetINTEntry(creatureLevel, "DURATION", originalValue);
                }
            });
        bAIActionRestHook = true;
    }

    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        auto duration = Services::Events::ExtractArgument<int32_t>(args);

        if (duration < 0)
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pPlayer->m_oidNWSObject, "REST_DURATION");
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(pPlayer->m_oidNWSObject, "REST_DURATION", duration < 10 ? 10 : duration);
        }
    }

    return stack;
}

ArgumentStack Player::ApplyInstantVisualEffectToObject(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto visualEffect = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(visualEffect >= 0); ASSERT_OR_THROW(visualEffect <= 65535);

        Vector vTargetPosition;
        vTargetPosition.x = 0.0f;
        vTargetPosition.y = 0.0f;
        vTargetPosition.z = 0.0f;

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if (pMessage)
        {
            pMessage->SendServerToPlayerGameObjUpdateVisEffect(
                    pPlayer,
                    visualEffect,                 // nVisualEffectID
                    oidTarget,                    // oidTarget
                    Utils::GetModule()->m_idSelf, // oidSource
                    0,                            // nSourceNode
                    0,                            // nTargetNode
                    vTargetPosition,              // vTargetPosition
                    0.0f);                        // fDuration
        }
    }
    return stack;
}

ArgumentStack Player::UpdateCharacterSheet(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        const auto charSheet = pPlayer->m_pCharSheetGUI;
        uint32_t msg = charSheet->ComputeCharacterSheetUpdateRequired(pPlayer);
        if (msg)
        {
            auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
            if (pMessage)
                pMessage->WriteGameObjUpdate_CharacterSheet(pPlayer, msg);
        }
    }
    return stack;
}

ArgumentStack Player::OpenInventory(ArgumentStack&& args)
{
    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto open = !!Services::Events::ExtractArgument<int32_t>(args);

        CNWSPlayerInventoryGUI *pInventory = pPlayer->m_oidNWSObject == oidTarget ? pPlayer->m_pInventoryGUI :
                                                                                    pPlayer->m_pOtherInventoryGUI;

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
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

    return stack;
}

ArgumentStack Player::GetAreaExplorationState(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string encString = "";

    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto areaId = Services::Events::ExtractArgument<Types::ObjectID>(args);
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
                            encString = NWNXLib::Encoding::ToBase64(tileDataVector);
                        }
                        break;
                    }
                }
            }
        }
    }
    Services::Events::InsertArgument(stack, encString);
    return stack;
}

ArgumentStack Player::SetAreaExplorationState(ArgumentStack&& args)
{
    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto areaId = Services::Events::ExtractArgument<Types::ObjectID>(args);
        if (pCreature && areaId != Constants::OBJECT_INVALID)
        {
            const auto pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaId);
            if (pArea)
            {
                auto encString = Services::Events::ExtractArgument<std::string>(args);

                uint32_t *p_oidArea = pCreature->m_oidAutoMapAreaList.element;
                for (int k = 0; k<pCreature->m_oidAutoMapAreaList.num; k++, p_oidArea++)
                {
                    if (*p_oidArea == areaId)
                    {
                        uint8_t *pTileData = *(pCreature->m_nAutoMapTileData + k);
                        if (pTileData)
                        {
                            std::vector<uint8_t> tileDataVector = NWNXLib::Encoding::FromBase64(encString);
                            std::copy(tileDataVector.begin(), tileDataVector.begin() + pArea->m_nMapSize, pTileData);
                        }
                        break;
                    }
                }
            }
        }
    }
    return stack;
}

ArgumentStack Player::SetRestAnimation(ArgumentStack&& args)
{
    static bool bAIActionRestHook;

    if (!bAIActionRestHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__AIActionRest, int32_t>(
                +[](Services::Hooks::CallType type, CNWSCreature* pCreature, CNWSObjectActionNode*) -> void
                {
                    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
                    {
                        if (auto animation = g_plugin->GetServices()->m_perObjectStorage->Get<int>(pCreature->m_idSelf, "REST_ANIMATION"))
                        {
                            pCreature->SetAnimation(*animation);
                        }
                    }
                });
        bAIActionRestHook = true;
    }

    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        auto animation = Services::Events::ExtractArgument<int32_t>(args);

        if (animation < 0)
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pPlayer->m_oidNWSObject, "REST_ANIMATION");
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(pPlayer->m_oidNWSObject, "REST_ANIMATION", animation);
        }
    }

    return stack;
    }


ArgumentStack Player::SetObjectVisualTransformOverride(ArgumentStack&& args)
{
    static bool bSetObjectVisualTransformOverrideHook;

    if (!bSetObjectVisualTransformOverrideHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__ComputeGameObjectUpdateForObject, int32_t>(
                +[](Services::Hooks::CallType type, CNWSMessage*, CNWSPlayer *pPlayer, CNWSObject*,
                    CGameObjectArray*, Types::ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        static ObjectVisualTransformData *pObjectVisualTransformData;

                        if (pObject->m_nObjectType == Constants::ObjectType::Creature ||
                            pObject->m_nObjectType == Constants::ObjectType::Placeable ||
                            pObject->m_nObjectType == Constants::ObjectType::Item ||
                            pObject->m_nObjectType == Constants::ObjectType::Door)
                        {
                            if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
                            {
                                if (auto objectVisualTransformData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidObjectToUpdate,
                                        "OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                                {
                                    pObjectVisualTransformData = static_cast<ObjectVisualTransformData*>(*objectVisualTransformData);
                                }
                                else
                                {
                                    pObjectVisualTransformData = nullptr;
                                }
                            }

                            if (pObjectVisualTransformData)
                            {
                                // Note: pObject->m_pVisualTransformData is pretending to be a pointer
                                std::swap(*pObjectVisualTransformData, pObject->m_pVisualTransformData);
                            }
                        }
                    }
                });

        bSetObjectVisualTransformOverrideHook = true;
    }

    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
        const auto transform = Services::Events::ExtractArgument<int32_t>(args);
        const auto value = Services::Events::ExtractArgument<float>(args);

        if (transform < 0)
        {
            if (auto objectVisualTransformData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidObject,
                    "OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                auto pObjectVisualTransformData = static_cast<ObjectVisualTransformData*>(*objectVisualTransformData);

                g_plugin->GetServices()->m_perObjectStorage->Remove(oidObject, "OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));

                delete pObjectVisualTransformData;
            }
        }
        else
        {
            ObjectVisualTransformData *pObjectVisualTransformData;

            if (auto objectVisualTransformData = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidObject,
                    "OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
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

                g_plugin->GetServices()->m_perObjectStorage->Set(oidObject, "OVTO!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject),
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

    return stack;
}

ArgumentStack Player::ApplyLoopingVisualEffectToObject(ArgumentStack&& args)
{
    static bool bApplyLoopingVisualEffectToObjectHook;

    if (!bApplyLoopingVisualEffectToObjectHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__ComputeGameObjectUpdateForObject, int32_t>(
                +[](Services::Hooks::CallType type, CNWSMessage*, CNWSPlayer *pPlayer, CNWSObject*,
                    CGameObjectArray*, Types::ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        static std::set<uint16_t> *pLoopingVisualEffectSet;

                        if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
                        {
                            if (auto loopingVisualEffectSet = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidObjectToUpdate,
                                    "LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
                            {
                                pLoopingVisualEffectSet = static_cast<std::set<uint16_t> *>(*loopingVisualEffectSet);
                            }
                            else
                            {
                                pLoopingVisualEffectSet = nullptr;
                            }

                            if (pLoopingVisualEffectSet)
                            {
                                for(auto visualEffect : *pLoopingVisualEffectSet)
                                {
                                    pObject->AddLoopingVisualEffect(visualEffect, Constants::OBJECT_INVALID, 0);
                                }
                            }
                        }
                        else
                        {
                            if (pLoopingVisualEffectSet)
                            {
                                for(auto visualEffect : *pLoopingVisualEffectSet)
                                {
                                    pObject->RemoveLoopingVisualEffect(visualEffect);
                                }
                            }
                        }
                    }
                });

        bApplyLoopingVisualEffectToObjectHook = true;
    }
    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto visualEffect = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(visualEffect <= 65535);

        if (visualEffect < 0)
        {
            if (auto loopingVisualEffectSet = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidTarget,
                    "LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                auto pLoopingVisualEffectSet = static_cast<std::set<uint16_t>*>(*loopingVisualEffectSet);

                g_plugin->GetServices()->m_perObjectStorage->Remove(oidTarget, "LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));

                delete pLoopingVisualEffectSet;
            }
        }
        else
        {
            std::set<uint16_t> *pLoopingVisualEffectSet;

            if (auto loopingVisualEffectSet = g_plugin->GetServices()->m_perObjectStorage->Get<void*>(oidTarget,
                    "LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject)))
            {
                pLoopingVisualEffectSet = static_cast<std::set<uint16_t>*>(*loopingVisualEffectSet);
            }
            else
            {
                pLoopingVisualEffectSet = new std::set<uint16_t>();

                g_plugin->GetServices()->m_perObjectStorage->Set(oidTarget, "LVES!" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject),
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
    return stack;
}

ArgumentStack Player::SetPlaceableNameOverride(ArgumentStack&& args)
{
    static bool bSetPlaceableNameOverrideHook;

    if (!bSetPlaceableNameOverrideHook)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__ComputeGameObjectUpdateForObject, int32_t>(
                +[](Services::Hooks::CallType type, CNWSMessage*, CNWSPlayer *pPlayer, CNWSObject*,
                    CGameObjectArray*, Types::ObjectID oidObjectToUpdate) -> void
                {
                    if (auto *pPlaceable = Utils::AsNWSPlaceable(Utils::GetGameObject(oidObjectToUpdate)))
                    {
                        static Maybe<std::string> name;
                        static CExoString swapName;

                        if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
                        {
                            name = g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(oidObjectToUpdate,
                                    "PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));

                            if (name)
                            {
                                std::string newName = *name;
                                swapName = newName.c_str();

                                std::swap(swapName, pPlaceable->m_sDisplayName);

                                // TODO: This might get removed next patch?
                                pPlaceable->m_bUpdateDisplayName = true;
                            }
                        }
                        else
                        {
                            if (name)
                            {
                                std::swap(swapName, pPlaceable->m_sDisplayName);

                                // TODO: This might get removed next patch?
                                pPlaceable->m_bUpdateDisplayName = true;
                            }
                        }
                    }
                });

        bSetPlaceableNameOverrideHook = true;
    }
    ArgumentStack stack;

    if (auto *pPlayer = player(args))
    {
        auto oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
        auto name = Services::Events::ExtractArgument<std::string>(args);

        if (name.empty())
        {
            GetServices()->m_perObjectStorage->Remove(oidTarget,
                                                      "PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject));
        }
        else
        {
            GetServices()->m_perObjectStorage->Set(oidTarget,
                                                   "PLCNO_" + Utils::ObjectIDToString(pPlayer->m_oidNWSObject), name);
        }
    }
    return stack;
}

ArgumentStack Player::GetQuestCompleted(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;

    if (auto *pPlayer = player(args))
    {
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        const auto questTag = Services::Events::ExtractArgument<std::string>(args);

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

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Player::SetPersistentLocation(ArgumentStack&& args)
{
    static bool bSetPersistentLocationHook;
    if (!bSetPersistentLocationHook)
    {
        GetServices()->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__LoadCharacterFinish, void>(
                +[](Services::Hooks::CallType cType, CServerExoAppInternal*, CNWSPlayer *pPlayer, int32_t, int32_t) -> void
                {
                    if (cType == Services::Hooks::CallType::AFTER_ORIGINAL)
                    {
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
                            std::string sCDKey = pPlayerInfo->GetPublicCDKey(0).CStr();
                            sKey = sCDKey + "!" + sBicFileName;
                        }
                        auto wpOID = g_plugin->m_PersistentLocationWP[sKey].first;
                        if (!wpOID)
                            return;

                        auto bFirstConnectOnly = g_plugin->m_PersistentLocationWP[sKey].second;

                        // Delete the key if this is the first connect and we're only setting the location on first connect
                        if (bFirstConnectOnly && !Utils::GetModule()->GetPlayerTURDFromList(pPlayer))
                        {
                            g_plugin->m_PersistentLocationWP.erase(sKey);
                        }
                            // The TURD exists already meaning its not the first connect
                        else if (bFirstConnectOnly)
                            return;

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
                    }
                });

        bSetPersistentLocationHook = true;
    }

    ArgumentStack stack;
    const auto sCDKeyOrCommunityName = Services::Events::ExtractArgument<std::string>(args);
    const auto sBicFileName = Services::Events::ExtractArgument<std::string>(args);
    const auto wpOid = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto bFirstConnectOnly = Services::Events::ExtractArgument<int32_t>(args);

    std::string sKey = sCDKeyOrCommunityName + "!" + sBicFileName;
    g_plugin->m_PersistentLocationWP[sKey] = std::make_pair(wpOid, bFirstConnectOnly);

    return stack;
}

ArgumentStack Player::UpdateItemName(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlayer = player(args))
    {
        auto oidItem = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidItem != Constants::OBJECT_INVALID);

        auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItem));
        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());

        if (pItem && pMessage)
        {
            pMessage->SendServerToPlayerUpdateItemName(pPlayer, pItem);
        }
    }
    return stack;
}

}
