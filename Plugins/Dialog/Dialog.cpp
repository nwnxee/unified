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
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

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

void Dialog::Hooks::GetStartEntry(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (before)
        statestack[++ssp] = DIALOG_STATE_START;
    else ssp--;
}

void Dialog::Hooks::GetStartEntryOneLiner(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, CExoLocString*, CResRef*, CResRef*, const CExoArrayList<ScriptParam>&)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (before)
        statestack[++ssp] = DIALOG_STATE_START;
    else ssp--;
}

void Dialog::Hooks::SendDialogEntry(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, uint32_t, uint32_t iEntry, int32_t)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (before)
    {
        statestack[++ssp] = DIALOG_STATE_SEND_ENTRY;
        idxEntry = iEntry;
    }
    else ssp--;
}

void Dialog::Hooks::SendDialogReplies(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, uint32_t)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (before)
        statestack[++ssp] = DIALOG_STATE_SEND_REPLIES;
    else ssp--;
}

void Dialog::Hooks::HandleReply(bool before, CNWSDialog *pThis,
    uint32_t, CNWSObject* pNWSObjectOwner, uint32_t nReplyIndex, int32_t, uint32_t currentEntryIndex)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (before)
    {
        statestack[++ssp] = DIALOG_STATE_HANDLE_REPLY;
        idxEntry = currentEntryIndex;
        idxReply = nReplyIndex;
    }
    else ssp--;
}

void Dialog::Hooks::CheckScript(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, const CResRef*, const CExoArrayList<ScriptParam>&)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    if (before)
    {
        if (statestack[ssp] == DIALOG_STATE_HANDLE_REPLY)
        {
            statestack[ssp] = DIALOG_STATE_SEND_ENTRY;
            idxReply = pDialog->m_pEntries[idxEntry].m_pReplies[idxReply].m_nIndex;
            idxEntry = pDialog->m_pReplies[idxReply].m_pEntries[loopCount].m_nIndex;
        }
        scriptType = SCRIPT_TYPE_STARTING_CONDITIONAL;
    }
    else
    {
        loopCount++;
        scriptType = SCRIPT_TYPE_OTHER;
    }
}

void Dialog::Hooks::RunScript(bool before, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, const CResRef*, const CExoArrayList<ScriptParam>&)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    if (before)
        scriptType = SCRIPT_TYPE_ACTION_TAKEN;
    else
        scriptType = SCRIPT_TYPE_OTHER;
}

Dialog::Dialog(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetCurrentNodeType);
    REGISTER(GetCurrentScriptType);
    REGISTER(GetCurrentNodeID);
    REGISTER(GetCurrentNodeIndex);
    REGISTER(GetCurrentNodeText);
    REGISTER(SetCurrentNodeText);
    REGISTER(End);

#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog13GetStartEntryEP10CNWSObject,
            uint32_t, CNWSDialog*, CNWSObject*>(&Hooks::GetStartEntry);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog21GetStartEntryOneLinerEP10CNWSObjectR13CExoLocStringR7CResRefS5_R13CExoArrayListI11ScriptParamE,
            int32_t, CNWSDialog*, CNWSObject*, CExoLocString*, CResRef*, CResRef*, const CExoArrayList<ScriptParam>&>(&Hooks::GetStartEntryOneLiner);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog15SendDialogEntryEP10CNWSObjectjji,
            int32_t, CNWSDialog*, CNWSObject*, uint32_t, uint32_t, int32_t>(&Hooks::SendDialogEntry);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog17SendDialogRepliesEP10CNWSObjectj,
            int32_t, CNWSDialog*, CNWSObject*, uint32_t>(&Hooks::SendDialogReplies);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog11HandleReplyEjP10CNWSObjectjij,
            int32_t, CNWSDialog*, uint32_t , CNWSObject*, uint32_t, int32_t, uint32_t>(&Hooks::HandleReply);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog11CheckScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
        int32_t, CNWSDialog *, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&>(&Hooks::CheckScript);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::_ZN10CNWSDialog9RunScriptEP10CNWSObjectRK7CResRefRK13CExoArrayListI11ScriptParamE,
        void, CNWSDialog *, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&>(&Hooks::RunScript);
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

    return Services::Events::Arguments(retval);
}

ArgumentStack Dialog::GetCurrentScriptType(ArgumentStack&&)
{
    return Services::Events::Arguments(scriptType);
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

    return Services::Events::Arguments(retval);
}

ArgumentStack Dialog::GetCurrentNodeIndex(ArgumentStack&&)
{
    return Services::Events::Arguments(loopCount);
}

ArgumentStack Dialog::GetCurrentNodeText(ArgumentStack&& args)
{
    CExoString str;

    auto language = Services::Events::ExtractArgument<int32_t>(args);
    auto gender = Services::Events::ExtractArgument<int32_t>(args);
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

    return Services::Events::Arguments(std::string(str.CStr()));
}

ArgumentStack Dialog::SetCurrentNodeText(ArgumentStack&& args)
{
    auto str = Services::Events::ExtractArgument<std::string>(args);
    auto language = Services::Events::ExtractArgument<int32_t>(args);
    auto gender = Services::Events::ExtractArgument<int32_t>(args);
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

    return Services::Events::Arguments();
}

ArgumentStack Dialog::End(ArgumentStack&& args)
{
    auto oidObject = Services::Events::ExtractArgument<ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    if (auto *pObject = Utils::AsNWSObject(Utils::GetGameObject(oidObject)))
    {
        pObject->StopDialog();
    }

    return Services::Events::Arguments();
}

}
