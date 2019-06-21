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
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"
#include "Utils.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Dialog::Dialog> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Dialog",
        "Functions exposing additional dialog properties",
        "sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Dialog::Dialog(params);
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

void Dialog::Hooks::GetStartEntry(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        statestack[++ssp] = DIALOG_STATE_START;
    else ssp--;
}

void Dialog::Hooks::GetStartEntryOneLiner(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, CExoLocString* sOneLiner, CResRef* sSound, CResRef* sScript)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    (void)sOneLiner; (void)sSound; (void)sScript;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        statestack[++ssp] = DIALOG_STATE_START;
    else ssp--;
}

void Dialog::Hooks::SendDialogEntry(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, int32_t bPlayHelloSound)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    (void)nPlayerIdGUIOnly; (void)bPlayHelloSound;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        statestack[++ssp] = DIALOG_STATE_SEND_ENTRY;
        idxEntry = iEntry;
    }
    else ssp--;
}

void Dialog::Hooks::SendDialogReplies(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    (void)nPlayerIdGUIOnly;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        statestack[++ssp] = DIALOG_STATE_SEND_REPLIES;
    else ssp--;
}

void Dialog::Hooks::HandleReply(Services::Hooks::CallType type, CNWSDialog *pThis,
    uint32_t nPlayerID, CNWSObject* pNWSObjectOwner, uint32_t nReplyIndex, int32_t bEscapeDialog, uint32_t currentEntryIndex)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    loopCount = 0;
    (void)bEscapeDialog; (void)nPlayerID;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        statestack[++ssp] = DIALOG_STATE_HANDLE_REPLY;
        idxEntry = currentEntryIndex;
        idxReply = nReplyIndex;
    }
    else ssp--;
}

void Dialog::Hooks::CheckScript(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, const CResRef* sActive)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    (void)sActive;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
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

void Dialog::Hooks::RunScript(Services::Hooks::CallType type, CNWSDialog *pThis,
    CNWSObject* pNWSObjectOwner, const CResRef* sScript)
{
    pDialog = pThis;
    pOwner = pNWSObjectOwner;
    (void)sScript;
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        scriptType = SCRIPT_TYPE_ACTION_TAKEN;
    else
        scriptType = SCRIPT_TYPE_OTHER;
}

Dialog::Dialog(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Dialog::func, this, std::placeholders::_1))

    REGISTER(GetCurrentNodeType);
    REGISTER(GetCurrentScriptType);
    REGISTER(GetCurrentNodeID);
    REGISTER(GetCurrentNodeIndex);
    REGISTER(GetCurrentNodeText);
    REGISTER(SetCurrentNodeText);
#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__GetStartEntry,
            uint32_t, CNWSDialog*, CNWSObject*>(&Hooks::GetStartEntry);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__GetStartEntryOneLiner,
            int32_t, CNWSDialog*, CNWSObject*, CExoLocString*, CResRef*, CResRef*>(&Hooks::GetStartEntryOneLiner);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__SendDialogEntry,
            int32_t, CNWSDialog*, CNWSObject*, uint32_t, uint32_t, int32_t>(&Hooks::SendDialogEntry);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__SendDialogReplies,
            int32_t, CNWSDialog*, CNWSObject*, uint32_t>(&Hooks::SendDialogReplies);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__HandleReply,
            int32_t, CNWSDialog*, uint32_t , CNWSObject*, uint32_t, int32_t, uint32_t>(&Hooks::HandleReply);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__CheckScript,
        int32_t, CNWSDialog *, CNWSObject*, const CResRef*>(&Hooks::CheckScript);
    GetServices()->m_hooks->RequestSharedHook
        <Functions::CNWSDialog__RunScript,
        void, CNWSDialog *, CNWSObject*, const CResRef*>(&Hooks::RunScript);
}

Dialog::~Dialog()
{
}

ArgumentStack Dialog::GetCurrentNodeType(ArgumentStack&& args)
{
    (void)args;
    ArgumentStack stack;
    int32_t retval;
    switch (statestack[ssp])
    {
        case DIALOG_STATE_START:        retval = NODE_TYPE_STARTING_NODE; break;
        case DIALOG_STATE_SEND_ENTRY:   retval = NODE_TYPE_ENTRY_NODE;    break;
        case DIALOG_STATE_HANDLE_REPLY: retval = NODE_TYPE_REPLY_NODE;    break;
        case DIALOG_STATE_SEND_REPLIES: retval = NODE_TYPE_REPLY_NODE;    break;
        default: retval = NODE_TYPE_INVALID;                              break;
    }

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Dialog::GetCurrentScriptType(ArgumentStack&& args)
{
    (void)args;
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, scriptType);
    return stack;
}

ArgumentStack Dialog::GetCurrentNodeID(ArgumentStack&& args)
{
    (void)args;
    ArgumentStack stack;
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

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Dialog::GetCurrentNodeIndex(ArgumentStack&& args)
{
    (void)args;
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, loopCount);
    return stack;
}

ArgumentStack Dialog::GetCurrentNodeText(ArgumentStack&& args)
{
    ArgumentStack stack;
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

    Services::Events::InsertArgument(stack, std::string(str.CStr()));
    return stack;
}

ArgumentStack Dialog::SetCurrentNodeText(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}



}
