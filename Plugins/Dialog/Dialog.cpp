#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSDialog.hpp"
#include "API/CNWSDialogEntry.hpp"
#include "API/CNWSDialogReply.hpp"
#include "API/CNWSDialogLinkEntry.hpp"
#include "API/CNWSDialogLinkReply.hpp"
#include "API/CExoLocString.hpp"
#include "API/CExoString.hpp"
#include "API/CResRef.hpp"
#include "API/CExoArrayList.hpp"
#include "API/ScriptParam.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

// Constants mirrored from NSS
constexpr int32_t NODE_TYPE_INVALID       = -1;
constexpr int32_t NODE_TYPE_STARTING_NODE = 0;
constexpr int32_t NODE_TYPE_ENTRY_NODE    = 1;
constexpr int32_t NODE_TYPE_REPLY_NODE    = 2;

constexpr int32_t SCRIPT_TYPE_OTHER = 0;
constexpr int32_t SCRIPT_TYPE_STARTING_CONDITIONAL = 1;
constexpr int32_t SCRIPT_TYPE_ACTION_TAKEN = 2;

//
// Hooks to maintain the state stack
//
static enum State {
    DIALOG_STATE_INVALID,
    DIALOG_STATE_START,
    DIALOG_STATE_SEND_ENTRY,
    DIALOG_STATE_SEND_REPLIES,
    DIALOG_STATE_HANDLE_REPLY
} s_statestack[16];
static int32_t s_ssp;
static CNWSDialog *s_pDialog;
static CNWSObject *s_pOwner;
static uint32_t s_idxEntry;
static uint32_t s_idxReply;
static int32_t  s_scriptType;
static int32_t  s_loopCount;

static uint32_t GetStartEntry(CNWSDialog*, CNWSObject*);
static int32_t GetStartEntryOneLiner(CNWSDialog*, CNWSObject*, CExoLocString*, CResRef*, CResRef*, const CExoArrayList<ScriptParam>&);
static int32_t SendDialogEntry(CNWSDialog*, CNWSObject*, uint32_t, uint32_t, int32_t);
static int32_t SendDialogReplies(CNWSDialog*, CNWSObject*, uint32_t);
static int32_t HandleReply(CNWSDialog*, uint32_t, CNWSObject* pNWSObjectOwner, uint32_t, int32_t, uint32_t);
static int32_t CheckScript(CNWSDialog*, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);
static void RunScript(CNWSDialog*, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);

static Hooks::Hook s_GetStartEntryHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog13GetStartEntryEP10CNWSObject,
    (void*)&GetStartEntry, Hooks::Order::Early);
static Hooks::Hook s_GetStartEntryOneLinerHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog21GetStartEntryOneLinerEP10CNWSObjectR13CExoLocStringR7CResRefS5_R13CExoArrayListI11ScriptParamE,
    (void*)&GetStartEntryOneLiner, Hooks::Order::Early);
static Hooks::Hook s_SendDialogEntryHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog15SendDialogEntryEP10CNWSObjectjji,
    (void*)&SendDialogEntry, Hooks::Order::Early);
static Hooks::Hook s_SendDialogRepliesHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog17SendDialogRepliesEP10CNWSObjectj,
    (void*)&SendDialogReplies, Hooks::Order::Early);
static Hooks::Hook s_HandleReplyHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog11HandleReplyEjP10CNWSObjectjij,
    (void*)&HandleReply, Hooks::Order::Early);
static Hooks::Hook s_CheckScriptHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog11CheckScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
    (void*)&CheckScript, Hooks::Order::Early);
static Hooks::Hook s_RunScriptHook = Hooks::HookFunction(
    Functions::_ZN10CNWSDialog9RunScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
    (void*)&RunScript, Hooks::Order::Early);

static uint32_t GetStartEntry(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;
    s_loopCount = 0;

    s_statestack[++s_ssp] = DIALOG_STATE_START;
    auto retVal = s_GetStartEntryHook->CallOriginal<uint32_t>(pThis, pNWSObjectOwner);
    s_ssp--;

    return retVal;
}

static int32_t GetStartEntryOneLiner(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, CExoLocString *sOneLiner,
                                          CResRef *sSound, CResRef *sScript, const CExoArrayList<ScriptParam> &scriptParams)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;
    s_loopCount = 0;

    s_statestack[++s_ssp] = DIALOG_STATE_START;
    auto retVal = s_GetStartEntryOneLinerHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, sOneLiner, sSound, sScript, scriptParams);
    s_ssp--;

    return retVal;
}

static int32_t SendDialogEntry(CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, BOOL bPlayHelloSound)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;
    s_loopCount = 0;

    s_statestack[++s_ssp] = DIALOG_STATE_SEND_ENTRY;
    s_idxEntry = iEntry;
    auto retVal = s_SendDialogEntryHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, nPlayerIdGUIOnly, iEntry, bPlayHelloSound);
    s_ssp--;

    return retVal;
}

static int32_t SendDialogReplies(CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;
    s_loopCount = 0;

    s_statestack[++s_ssp] = DIALOG_STATE_SEND_REPLIES;
    auto retVal = s_SendDialogRepliesHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, nPlayerIdGUIOnly);
    s_ssp--;

    return retVal;
}

static int32_t HandleReply(CNWSDialog *pThis, uint32_t nPlayerID, CNWSObject *pNWSObjectOwner, uint32_t nReplyIndex,
                                   BOOL bEscapeDialog, uint32_t currentEntryIndex)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;
    s_loopCount = 0;

    s_statestack[++s_ssp] = DIALOG_STATE_HANDLE_REPLY;
    s_idxEntry = currentEntryIndex;
    s_idxReply = nReplyIndex;
    auto retVal = s_HandleReplyHook->CallOriginal<int32_t>(pThis, nPlayerID, pNWSObjectOwner, nReplyIndex, bEscapeDialog, currentEntryIndex);
    s_ssp--;
    return retVal;
}

static int32_t CheckScript(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, const CResRef *sActive, const CExoArrayList<ScriptParam> &scriptParams)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;

    if (s_statestack[s_ssp] == DIALOG_STATE_HANDLE_REPLY)
    {
        s_statestack[s_ssp] = DIALOG_STATE_SEND_ENTRY;
        s_idxReply = s_pDialog->m_pEntries[s_idxEntry].m_pReplies[s_idxReply].m_nIndex;
        s_idxEntry = s_pDialog->m_pReplies[s_idxReply].m_pEntries[s_loopCount].m_nIndex;
    }
    s_scriptType = SCRIPT_TYPE_STARTING_CONDITIONAL;
    auto retVal = s_CheckScriptHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, sActive, scriptParams);
    s_loopCount++;
    s_scriptType = SCRIPT_TYPE_OTHER;

    return retVal;
}

static void RunScript(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, const CResRef *sScript, const CExoArrayList<ScriptParam> &scriptParams)
{
    s_pDialog = pThis;
    s_pOwner = pNWSObjectOwner;

    s_scriptType = SCRIPT_TYPE_ACTION_TAKEN;
    s_RunScriptHook->CallOriginal<void>(pThis, pNWSObjectOwner, sScript, scriptParams);
    s_scriptType = SCRIPT_TYPE_OTHER;
}


NWNX_EXPORT ArgumentStack GetCurrentNodeType(ArgumentStack&&)
{
    switch (s_statestack[s_ssp])
    {
        case DIALOG_STATE_START:        return NODE_TYPE_STARTING_NODE;
        case DIALOG_STATE_SEND_ENTRY:   return NODE_TYPE_ENTRY_NODE;
        case DIALOG_STATE_HANDLE_REPLY: return NODE_TYPE_REPLY_NODE;
        case DIALOG_STATE_SEND_REPLIES: return NODE_TYPE_REPLY_NODE;
        default:                        return NODE_TYPE_INVALID;
    }
}

NWNX_EXPORT ArgumentStack GetCurrentScriptType(ArgumentStack&&)
{
    return s_scriptType;
}

NWNX_EXPORT ArgumentStack GetCurrentNodeID(ArgumentStack&&)
{
    switch (s_statestack[s_ssp])
    {
        case DIALOG_STATE_START:
            return s_pDialog->m_pStartingEntries[s_loopCount].m_nIndex;
        case DIALOG_STATE_SEND_ENTRY:
            return s_idxEntry;
        case DIALOG_STATE_HANDLE_REPLY:
            return s_pDialog->m_pEntries[s_idxEntry].m_pReplies[s_idxReply].m_nIndex;
        case DIALOG_STATE_SEND_REPLIES:
            return s_pDialog->m_pEntries[s_pDialog->m_currentEntryIndex].m_pReplies[s_loopCount].m_nIndex;
        default:
            return -1;
    }
}

NWNX_EXPORT ArgumentStack GetCurrentNodeIndex(ArgumentStack&&)
{
    return s_loopCount;
}

NWNX_EXPORT ArgumentStack GetCurrentNodeText(ArgumentStack&& args)
{
    CExoString str;

    auto language = args.extract<int32_t>();
    auto gender = args.extract<int32_t>();
    CExoLocString *pLocString;

    switch (s_statestack[s_ssp])
    {
        case DIALOG_STATE_START:
            pLocString = &s_pDialog->m_pEntries[s_pDialog->m_pStartingEntries[s_loopCount].m_nIndex].m_sText;
            break;
        case DIALOG_STATE_SEND_ENTRY:
            pLocString = &s_pDialog->m_pEntries[s_idxEntry].m_sText;
            break;
        case DIALOG_STATE_HANDLE_REPLY:
        {
            auto idx = s_pDialog->m_pEntries[s_idxEntry].m_pReplies[s_idxReply].m_nIndex;
            pLocString = &s_pDialog->m_pReplies[idx].m_sText;
            break;
        }
        case DIALOG_STATE_SEND_REPLIES:
        {
            auto idx = s_pDialog->m_pEntries[s_pDialog->m_currentEntryIndex].m_pReplies[s_loopCount].m_nIndex;
            pLocString = &s_pDialog->m_pReplies[idx].m_sText;
            break;
        }
        default:
            pLocString = nullptr;
            break;
    }

    if (pLocString)
    {
        gender = !!gender; // Only male/female supported; CExoLocString is traditional that way.
        pLocString->GetString(language, &str, gender, true);
    }

    return std::string(str.CStr());
}

NWNX_EXPORT ArgumentStack SetCurrentNodeText(ArgumentStack&& args)
{
    auto str = args.extract<std::string>();
    auto language = args.extract<int32_t>();
    auto gender = args.extract<int32_t>();
    CExoLocString *pLocString;

    switch (s_statestack[s_ssp])
    {
        case DIALOG_STATE_START:
            pLocString = &s_pDialog->m_pEntries[s_pDialog->m_pStartingEntries[s_loopCount].m_nIndex].m_sText;
            break;
        case DIALOG_STATE_SEND_ENTRY:
            pLocString = &s_pDialog->m_pEntries[s_idxEntry].m_sText;
            break;
        case DIALOG_STATE_HANDLE_REPLY:
        {
            auto idx = s_pDialog->m_pEntries[s_idxEntry].m_pReplies[s_idxReply].m_nIndex;
            pLocString = &s_pDialog->m_pReplies[idx].m_sText;
            break;
        }
        case DIALOG_STATE_SEND_REPLIES:
        {
            auto idx = s_pDialog->m_pEntries[s_pDialog->m_currentEntryIndex].m_pReplies[s_loopCount].m_nIndex;
            pLocString = &s_pDialog->m_pReplies[idx].m_sText;
            break;
        }
        default:
            pLocString = nullptr;
            break;
    }

    if (pLocString)
    {
        CExoString cexostr = str.c_str();
        gender = !!gender; // Only male/female supported; CExoLocString is traditional that way.
        pLocString->AddString(language, cexostr, gender);
    }

    return {};
}

NWNX_EXPORT ArgumentStack End(ArgumentStack&& args)
{
    auto oidObject = args.extract<ObjectID >();
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObject)))
        pObject->StopDialog();

    return {};
}
