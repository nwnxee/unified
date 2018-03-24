#include "Player.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CExoArrayListTemplatedCNWSScriptVar.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSQuickbarButton.hpp"
//#include "API/CNWSStats_Spell.hpp"
//#include "API/CNWSStats_SpellLikeAbility.hpp"
//#include "API/CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
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
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Player::func, this, std::placeholders::_1))

    REGISTER(ForcePlaceableExamineWindow);
    REGISTER(StartGuiTimingBar);
    REGISTER(StopGuiTimingBar);
    REGISTER(SetAlwaysWalk);
    REGISTER(GetQuickBarSlot);
    REGISTER(SetQuickBarSlot);

#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent,
            void, CNWSMessage*, CNWSPlayer*>(&HandlePlayerToServerInputCancelGuiTimingEventHook);

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

ArgumentStack Player::StartGuiTimingBar(ArgumentStack&& args)
{
    ArgumentStack stack;
    if(auto *pPlayer = player(args))
    {
        const float seconds = Services::Events::ExtractArgument<float>(args);
        const uint32_t milliseconds = static_cast<uint32_t>(seconds * 1000.0f); // NWN expects milliseconds.

        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if(pMessage)
        {
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, true, 10, milliseconds);
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
    if(auto *pPlayer = player(args))
    {
        auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
        if(pMessage)
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


void Player::HandlePlayerToServerInputCancelGuiTimingEventHook(Services::Hooks::CallType type, CNWSMessage* pMessage, CNWSPlayer* pPlayer)
{
    // Before or after doesn't matter, just pick one so it happens only once
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        CNWSObject *pGameObject = static_cast<CNWSObject*>(Globals::AppManager()->m_pServerExoApp->GetGameObject(pPlayer->m_oidPCObject));

        CExoString varName = "NWNX_PLAYER_GUI_TIMING_ACTIVE";
        int32_t id = pGameObject->m_ScriptVars.GetInt(varName);

        if (id > 0)
        {
            LOG_DEBUG("Cancelling GUI timing event id %d...", id);
            pMessage->SendServerToPlayerGuiTimingEvent(pPlayer, false, 10, 0);
            pGameObject->m_ScriptVars.DestroyInt(varName);
        }
    }
}

ArgumentStack Player::SetAlwaysWalk(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pAddMoveToPointAction_hook;

    if (!pAddMoveToPointAction_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__AddMoveToPointAction>(
            +[](
                    CNWSCreature *pThis,
                    uint16_t nGroupId,
                    Vector vNewWalkPosition,
                    uint32_t oidNewWalkArea,
                    uint32_t oidObjectMovingTo,
                    int32_t bRunToPoint,
                    float fRange,
                    float fTimeout,
                    int32_t bClientMoving,
                    int32_t nClientPathNumber,
                    int32_t nMoveToPosition,
                    int32_t nMoveMode,
                    int32_t bStraightLine,
                    int32_t bCheckedActionPoint
            ) -> int32_t
            {
                auto walk = g_plugin->GetServices()->m_perObjectStorage->Get<int>(pThis->m_idSelf, "ALWAYS_WALK");
                if (walk && *walk)
                    bRunToPoint = 0;

                return pAddMoveToPointAction_hook->CallOriginal<int32_t>
                        (pThis,nGroupId,vNewWalkPosition,oidNewWalkArea,
                         oidObjectMovingTo,bRunToPoint,fRange,fTimeout,
                         bClientMoving,nClientPathNumber,nMoveToPosition,
                         nMoveMode,bStraightLine,bCheckedActionPoint);
            });
        pAddMoveToPointAction_hook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__AddMoveToPointAction);
    }

    if (auto *pPlayer = player(args))
    {
        const auto bSetCap = Services::Events::ExtractArgument<int32_t>(args);

        if (bSetCap)
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(pPlayer->m_oidNWSObject, "ALWAYS_WALK", 1);
        }
        else // remove the override
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pPlayer->m_oidNWSObject, "ALWAYS_WALK");
        }
    }

    ArgumentStack stack;
    return stack;
}


ArgumentStack Player::GetQuickBarSlot(ArgumentStack&& args)
{
    ArgumentStack stack;
    CNWSQuickbarButton qbs;
    if (auto *pPlayer = player(args))
    {
        auto slot = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(slot < 36);

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
        ASSERT(slot < 36);

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

}
