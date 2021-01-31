#include "Dialog.hpp"

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

static Dialog::Dialog* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Dialog::Dialog(services);
    return g_plugin;
}

namespace Dialog {

//
// Constants mirrored from NSS
const int32_t NODE_TYPE_INVALID       = -1;
const int32_t NODE_TYPE_STARTING_NODE = 0;
const int32_t NODE_TYPE_ENTRY_NODE    = 1;
const int32_t NODE_TYPE_REPLY_NODE    = 2;

const int32_t SCRIPT_TYPE_OTHER = 0;
const int32_t SCRIPT_TYPE_STARTING_CONDITIONAL = 1;
const int32_t SCRIPT_TYPE_ACTION_TAKEN = 2;

//
// Hooks to maintain the state stack
//
Dialog::State Dialog::statestack[16];
int32_t Dialog::ssp;
CNWSDialog *Dialog::pDialog;
CNWSObject *Dialog::pOwner;
uint32_t Dialog::idxEntry;
uint32_t Dialog::idxReply;
int32_t  Dialog::scriptType;
int32_t  Dialog::loopCount;

static NWNXLib::Hooks::Hook s_GetStartEntryHook;
static NWNXLib::Hooks::Hook s_GetStartEntryOneLinerHook;
static NWNXLib::Hooks::Hook s_SendDialogEntryHook;
static NWNXLib::Hooks::Hook s_SendDialogRepliesHook;
static NWNXLib::Hooks::Hook s_HandleReplyHook;
static NWNXLib::Hooks::Hook s_CheckScriptHook;
static NWNXLib::Hooks::Hook s_RunScriptHook;

uint32_t Dialog::Hooks::GetStartEntry(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;

    statestack[++ssp] = DIALOG_STATE_START;
    auto retVal = s_GetStartEntryHook->CallOriginal<uint32_t>(pThis, pNWSObjectOwner);
    ssp--;

    return retVal;
}

int32_t Dialog::Hooks::GetStartEntryOneLiner(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, CExoLocString *sOneLiner,
                                          CResRef *sSound, CResRef *sScript, const CExoArrayList<ScriptParam> &scriptParams)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;

    statestack[++ssp] = DIALOG_STATE_START;
    auto retVal = s_GetStartEntryOneLinerHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, sOneLiner, sSound, sScript, scriptParams);
    ssp--;

    return retVal;
}

int32_t Dialog::Hooks::SendDialogEntry(CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, BOOL bPlayHelloSound)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;

    statestack[++ssp] = DIALOG_STATE_SEND_ENTRY;
    idxEntry = iEntry;
    auto retVal = s_SendDialogEntryHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, nPlayerIdGUIOnly, iEntry, bPlayHelloSound);
    ssp--;

    return retVal;
}

int32_t Dialog::Hooks::SendDialogReplies(CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;

    statestack[++ssp] = DIALOG_STATE_SEND_REPLIES;
    auto retVal = s_SendDialogRepliesHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, nPlayerIdGUIOnly);
    ssp--;

    return retVal;
}

int32_t Dialog::Hooks::HandleReply(CNWSDialog *pThis, uint32_t nPlayerID, CNWSObject *pNWSObjectOwner, uint32_t nReplyIndex,
                                   BOOL bEscapeDialog, uint32_t currentEntryIndex)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;

    statestack[++ssp] = DIALOG_STATE_HANDLE_REPLY;
    idxEntry = currentEntryIndex;
    idxReply = nReplyIndex;
    auto retVal = s_HandleReplyHook->CallOriginal<int32_t>(pThis, nPlayerID, pNWSObjectOwner, nReplyIndex, bEscapeDialog, currentEntryIndex);
    ssp--;
    return retVal;
}

int32_t Dialog::Hooks::CheckScript(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, const CResRef *sActive, const CExoArrayList<ScriptParam> &scriptParams)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;

    if (statestack[ssp] == DIALOG_STATE_HANDLE_REPLY)
    {
        statestack[ssp] = DIALOG_STATE_SEND_ENTRY;
        idxReply = pDialog->m_pEntries[idxEntry].m_pReplies[idxReply].m_nIndex;
        idxEntry = pDialog->m_pReplies[idxReply].m_pEntries[loopCount].m_nIndex;
    }
    scriptType = SCRIPT_TYPE_STARTING_CONDITIONAL;
    auto retVal = s_CheckScriptHook->CallOriginal<int32_t>(pThis, pNWSObjectOwner, sActive, scriptParams);
    loopCount++;
    scriptType = SCRIPT_TYPE_OTHER;

    return retVal;
}

void Dialog::Hooks::RunScript(CNWSDialog *pThis, CNWSObject *pNWSObjectOwner, const CResRef *sScript, const CExoArrayList<ScriptParam> &scriptParams)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;

    scriptType = SCRIPT_TYPE_ACTION_TAKEN;
    s_RunScriptHook->CallOriginal<void>(pThis, pNWSObjectOwner, sScript, scriptParams);
    scriptType = SCRIPT_TYPE_OTHER;
}

Dialog::Dialog(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetCurrentNodeType);
    REGISTER(GetCurrentScriptType);
    REGISTER(GetCurrentNodeID);
    REGISTER(GetCurrentNodeIndex);
    REGISTER(GetCurrentNodeText);
    REGISTER(SetCurrentNodeText);
    REGISTER(End);

#undef REGISTER

    s_GetStartEntryHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog13GetStartEntryEP10CNWSObject,
                                                       (void*)&Hooks::GetStartEntry, NWNXLib::Hooks::Order::Early);
    s_GetStartEntryOneLinerHook = NWNXLib::Hooks::HookFunction(
            Functions::_ZN10CNWSDialog21GetStartEntryOneLinerEP10CNWSObjectR13CExoLocStringR7CResRefS5_R13CExoArrayListI11ScriptParamE,
            (void*)&Hooks::GetStartEntryOneLiner, NWNXLib::Hooks::Order::Early);
    s_SendDialogEntryHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog15SendDialogEntryEP10CNWSObjectjji,
                                                         (void*)&Hooks::SendDialogEntry, NWNXLib::Hooks::Order::Early);
    s_SendDialogRepliesHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog17SendDialogRepliesEP10CNWSObjectj,
                                                           (void*)&Hooks::SendDialogReplies, NWNXLib::Hooks::Order::Early);
    s_HandleReplyHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog11HandleReplyEjP10CNWSObjectjij,
                                                     (void*)&Hooks::HandleReply, NWNXLib::Hooks::Order::Early);
    s_CheckScriptHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog11CheckScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
                                                     (void*)&Hooks::CheckScript, NWNXLib::Hooks::Order::Early);
    s_RunScriptHook = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSDialog9RunScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
                                                   (void*)&Hooks::RunScript, NWNXLib::Hooks::Order::Early);
}

Dialog::~Dialog()
{
}

ArgumentStack Dialog::GetCurrentNodeType(ArgumentStack&&)
{
    int32_t retval;
    switch (statestack[ssp])
    {
        case DIALOG_STATE_START:        retval = NODE_TYPE_STARTING_NODE; break;
        case DIALOG_STATE_SEND_ENTRY:   retval = NODE_TYPE_ENTRY_NODE;    break;
        case DIALOG_STATE_HANDLE_REPLY: retval = NODE_TYPE_REPLY_NODE;    break;
        case DIALOG_STATE_SEND_REPLIES: retval = NODE_TYPE_REPLY_NODE;    break;
        default: retval = NODE_TYPE_INVALID;                              break;
    }

    return Events::Arguments(retval);
}

ArgumentStack Dialog::GetCurrentScriptType(ArgumentStack&&)
{
    return Events::Arguments(scriptType);
}

ArgumentStack Dialog::GetCurrentNodeID(ArgumentStack&&)
{
    int32_t retval;

    switch (statestack[ssp])
    {
        case DIALOG_STATE_START:
            retval = pDialog->m_pStartingEntries[loopCount].m_nIndex;
            break;
        case DIALOG_STATE_SEND_ENTRY:
            retval = idxEntry;
            break;
        case DIALOG_STATE_HANDLE_REPLY:
            retval = pDialog->m_pEntries[idxEntry].m_pReplies[idxReply].m_nIndex;
            break;
        case DIALOG_STATE_SEND_REPLIES:
            retval = pDialog->m_pEntries[pDialog->m_currentEntryIndex].m_pReplies[loopCount].m_nIndex;
            break;
        default:
            retval = -1;
            break;
    }

    return Events::Arguments(retval);
}

ArgumentStack Dialog::GetCurrentNodeIndex(ArgumentStack&&)
{
    return Events::Arguments(loopCount);
}

ArgumentStack Dialog::GetCurrentNodeText(ArgumentStack&& args)
{
    CExoString str;

    auto language = Events::ExtractArgument<int32_t>(args);
    auto gender = Events::ExtractArgument<int32_t>(args);
    CExoLocString *pLocString;

    switch (statestack[ssp])
    {
        case DIALOG_STATE_START:
            pLocString = &pDialog->m_pEntries[pDialog->m_pStartingEntries[loopCount].m_nIndex].m_sText;
            break;
        case DIALOG_STATE_SEND_ENTRY:
            pLocString = &pDialog->m_pEntries[idxEntry].m_sText;
            break;
        case DIALOG_STATE_HANDLE_REPLY:
        {
            auto idx = pDialog->m_pEntries[idxEntry].m_pReplies[idxReply].m_nIndex;
            pLocString = &pDialog->m_pReplies[idx].m_sText;
            break;
        }
        case DIALOG_STATE_SEND_REPLIES:
        {
            auto idx = pDialog->m_pEntries[pDialog->m_currentEntryIndex].m_pReplies[loopCount].m_nIndex;
            pLocString = &pDialog->m_pReplies[idx].m_sText;
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

    return Events::Arguments(std::string(str.CStr()));
}

ArgumentStack Dialog::SetCurrentNodeText(ArgumentStack&& args)
{
    auto str = Events::ExtractArgument<std::string>(args);
    auto language = Events::ExtractArgument<int32_t>(args);
    auto gender = Events::ExtractArgument<int32_t>(args);
    CExoLocString *pLocString;

    switch (statestack[ssp])
    {
        case DIALOG_STATE_START:
            pLocString = &pDialog->m_pEntries[pDialog->m_pStartingEntries[loopCount].m_nIndex].m_sText;
            break;
        case DIALOG_STATE_SEND_ENTRY:
            pLocString = &pDialog->m_pEntries[idxEntry].m_sText;
            break;
        case DIALOG_STATE_HANDLE_REPLY:
        {
            auto idx = pDialog->m_pEntries[idxEntry].m_pReplies[idxReply].m_nIndex;
            pLocString = &pDialog->m_pReplies[idx].m_sText;
            break;
        }
        case DIALOG_STATE_SEND_REPLIES:
        {
            auto idx = pDialog->m_pEntries[pDialog->m_currentEntryIndex].m_pReplies[loopCount].m_nIndex;
            pLocString = &pDialog->m_pReplies[idx].m_sText;
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

    return Events::Arguments();
}

ArgumentStack Dialog::End(ArgumentStack&& args)
{
    auto oidObject = Events::ExtractArgument<ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObject)))
    {
        pObject->StopDialog();
    }

    return Events::Arguments();
}

}
