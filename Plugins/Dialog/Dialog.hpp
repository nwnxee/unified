#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/Types.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Dialog {

class Dialog : public NWNXLib::Plugin
{
public:
    Dialog(const Plugin::CreateParams& params);
    virtual ~Dialog();

private:
    struct Hooks {
        static void GetStartEntry(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject* pNWSObjectOwner);
        static void GetStartEntryOneLiner(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject* pNWSObjectOwner, NWNXLib::API::CExoLocString& sOneLiner, NWNXLib::API::CResRef* sSound, NWNXLib::API::CResRef* sScript);
        static void SendDialogEntry(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, int32_t bPlayHelloSound);
        static void SendDialogReplies(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly);
        static void HandleReply(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            uint32_t nPlayerID, NWNXLib::API::CNWSObject* pNWSObjectOwner, uint32_t nReplyIndex, int32_t bEscapeDialog, uint32_t currentEntryIndex);
        static void CheckScript(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject*, const NWNXLib::API::CResRef*);
        static void RunScript(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSDialog *pThis,
            NWNXLib::API::CNWSObject*, const NWNXLib::API::CResRef*);
    };
    static enum State {
        DIALOG_STATE_INVALID,
        DIALOG_STATE_START,
        DIALOG_STATE_SEND_ENTRY,
        DIALOG_STATE_SEND_REPLIES,
        DIALOG_STATE_HANDLE_REPLY
    } statestack[16];
    static int32_t ssp;
    static NWNXLib::API::CNWSDialog *pDialog;
    static NWNXLib::API::CNWSObject *pOwner;
    static uint32_t idxEntry;
    static uint32_t idxReply;
    static int32_t  scriptType;
    static int32_t  loopCount;

    ArgumentStack GetCurrentNodeType   (ArgumentStack&& args);
    ArgumentStack GetCurrentScriptType (ArgumentStack&& args);
    ArgumentStack GetCurrentNodeID     (ArgumentStack&& args);
    ArgumentStack GetCurrentNodeIndex  (ArgumentStack&& args);
    ArgumentStack GetCurrentNodeText   (ArgumentStack&& args);
    ArgumentStack SetCurrentNodeText   (ArgumentStack&& args);
};

}
