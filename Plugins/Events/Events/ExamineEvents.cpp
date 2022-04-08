#include "Events.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerCharSheetGUI.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWCreatureStatsUpdate.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SendServerToPlayerExamineGui_TrapDataHook;
static Hooks::Hook s_PermittedToDisplayCharacterSheetHook;

static void HandleExamine(bool, ObjectID, ObjectID);
static int32_t ExamineTrapHook(CNWSMessage*, CNWSPlayer*, ObjectID, CNWSCreature*, int32_t);
static int32_t PermittedToDisplayCharacterSheetHook(CNWSPlayer*, ObjectID);
static int32_t HandlePlayerToServerCharacterSheetMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void ExamineEvents() __attribute__((constructor));
void ExamineEvents()
{
    InitOnFirstSubscribe("NWNX_ON_EXAMINE_OBJECT_.*", []() {

        #define HOOK_EXAMINE(_address) \
            static Hooks::Hook CAT(pExamineHook, __LINE__) = Hooks::HookFunction(_address, \
            (void*)+[](CNWSMessage *pMessage, CNWSPlayer* pPlayer, ObjectID oidObject) -> int32_t \
            { \
                HandleExamine(true, pPlayer->m_oidNWSObject, oidObject); \
                auto retVal = CAT(pExamineHook, __LINE__)->CallOriginal<int32_t>(pMessage, pPlayer, oidObject); \
                HandleExamine(false, pPlayer->m_oidNWSObject, oidObject);  \
                return retVal; \
            }, Hooks::Order::Earliest)

                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage41SendServerToPlayerExamineGui_CreatureDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_DoorDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_ItemDataEP10CNWSPlayerj);
                HOOK_EXAMINE(API::Functions::_ZN11CNWSMessage42SendServerToPlayerExamineGui_PlaceableDataEP10CNWSPlayerj);

        #undef HOOK_EXAMINE

        s_SendServerToPlayerExamineGui_TrapDataHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage37SendServerToPlayerExamineGui_TrapDataEP10CNWSPlayerjP12CNWSCreaturei,
                (void*)&ExamineTrapHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_CHARACTER_SHEET_PERMITTED_.*", []() {
        s_PermittedToDisplayCharacterSheetHook = Hooks::HookFunction(
                API::Functions::_ZN10CNWSPlayer32PermittedToDisplayCharacterSheetEj,
                (void*)&PermittedToDisplayCharacterSheetHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CHARACTER_SHEET_(OPEN|CLOSE)_.*", []() {
        static Hooks::Hook s_HandlePlayerToServerCharacterSheetMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage41HandlePlayerToServerCharacterSheetMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerCharacterSheetMessageHook, Hooks::Order::Final);
    });
}

void HandleExamine(bool before, ObjectID examiner, ObjectID examinee)
{
    PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(examinee));
    SignalEvent(before ? "NWNX_ON_EXAMINE_OBJECT_BEFORE" : "NWNX_ON_EXAMINE_OBJECT_AFTER", examiner);
}

int32_t ExamineTrapHook(CNWSMessage *pMessage, CNWSPlayer* pPlayer, ObjectID oidTrapID, CNWSCreature *pCreature, int32_t bSuccess)
{
    PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(oidTrapID));
    PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(bSuccess));
    SignalEvent("NWNX_ON_EXAMINE_OBJECT_BEFORE", pPlayer->m_oidNWSObject);
    auto retVal = s_SendServerToPlayerExamineGui_TrapDataHook->CallOriginal<int32_t>(pMessage, pPlayer, oidTrapID, pCreature, bSuccess);
    PushEventData("EXAMINEE_OBJECT_ID", Utils::ObjectIDToString(oidTrapID));
    PushEventData("TRAP_EXAMINE_SUCCESS", std::to_string(bSuccess));
    SignalEvent("NWNX_ON_EXAMINE_OBJECT_AFTER", pPlayer->m_oidNWSObject);
    return retVal;
}

int32_t PermittedToDisplayCharacterSheetHook(CNWSPlayer *pPlayer, ObjectID oidCreature)
{
    auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidCreature));

    if (!pCreature)
        return s_PermittedToDisplayCharacterSheetHook->CallOriginal<int32_t>(pPlayer, oidCreature);

    int32_t retVal;
    std::string result;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET", Utils::ObjectIDToString(oidCreature));
        return SignalEvent(ev, pPlayer->m_oidNWSObject, &result);
    };

    if (PushAndSignal("NWNX_ON_CHARACTER_SHEET_PERMITTED_BEFORE"))
    {
        retVal = s_PermittedToDisplayCharacterSheetHook->CallOriginal<int32_t>(pPlayer, oidCreature);
    }
    else
    {
        retVal = result == "1";
    }

    PushAndSignal("NWNX_ON_CHARACTER_SHEET_PERMITTED_AFTER");

    return retVal;
}

int32_t HandlePlayerToServerCharacterSheetMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    char nActivePanel = pMessage->ReadCHAR();
    ObjectID oidCharSheetCreature = pMessage->ReadOBJECTIDServer();

    if (pMessage->MessageReadOverflow() || pMessage->MessageReadUnderflow())
        return false;

    if (nMinor == Constants::MessageGuiCharacterSheetMinor::Status)
    {
        auto PushAndSignal = [&](const std::string& ev) -> bool {
            PushEventData("TARGET", Utils::ObjectIDToString(oidCharSheetCreature));
            return SignalEvent(ev, pPlayer->m_oidNWSObject);
        };

        if (!pPlayer->PermittedToDisplayCharacterSheet(oidCharSheetCreature))
        {
            nActivePanel = -1;
            pMessage->SendServerToPlayerGUICharacterSheet_NotPermitted(pPlayer->m_nPlayerID, oidCharSheetCreature);
            oidCharSheetCreature = Constants::OBJECT_INVALID;
        }

        if (nActivePanel == 0 && oidCharSheetCreature != Constants::OBJECT_INVALID)
            PushAndSignal("NWNX_ON_CHARACTER_SHEET_OPEN_BEFORE");
        else if (nActivePanel == -1 && oidCharSheetCreature != Constants::OBJECT_INVALID)
            PushAndSignal("NWNX_ON_CHARACTER_SHEET_CLOSE_BEFORE");

        if (auto *pOldCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_pCharSheetGUI->m_oidCreatureDisplayed)))
        {
            pOldCreature->m_nNumCharSheetViewers = pOldCreature->m_nNumCharSheetViewers - 1;
        }

        if (auto *pNewCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidCharSheetCreature)))
        {
            pNewCreature->m_nNumCharSheetViewers = pNewCreature->m_nNumCharSheetViewers + 1;
        }

        pPlayer->m_pCharSheetGUI->SetCreatureDisplayed(oidCharSheetCreature);
        pPlayer->m_pCharSheetGUI->m_nActivePanel = nActivePanel;

        if (nActivePanel == -1)
            pPlayer->m_pCharSheetGUI->m_pLastStatsUpdate->ClearEffectIcons();

        if (nActivePanel == 0 && oidCharSheetCreature != Constants::OBJECT_INVALID)
            PushAndSignal("NWNX_ON_CHARACTER_SHEET_OPEN_AFTER");
        else if (nActivePanel == -1 && oidCharSheetCreature != Constants::OBJECT_INVALID)
            PushAndSignal("NWNX_ON_CHARACTER_SHEET_CLOSE_AFTER");
    }

    return true;
}

}
