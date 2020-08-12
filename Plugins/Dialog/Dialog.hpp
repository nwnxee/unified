#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Dialog {

class Dialog : public NWNXLib::Plugin
{
public:
    Dialog(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Dialog();

private:
    struct Hooks {
        static void GetStartEntry(bool, CNWSDialog *pThis, CNWSObject* pNWSObjectOwner);
        static void GetStartEntryOneLiner(bool, CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, CExoLocString* sOneLiner, CResRef* sSound, CResRef* sScript, const CExoArrayList<ScriptParam>&);
        static void SendDialogEntry(bool, CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, int32_t bPlayHelloSound);
        static void SendDialogReplies(bool, CNWSDialog *pThis, CNWSObject* pNWSObjectOwner, uint32_t nPlayerIdGUIOnly);
        static void HandleReply(bool, CNWSDialog *pThis, uint32_t nPlayerID, CNWSObject* pNWSObjectOwner, uint32_t nReplyIndex, int32_t bEscapeDialog, uint32_t currentEntryIndex);
        static void CheckScript(bool, CNWSDialog *pThis, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);
        static void RunScript(bool, CNWSDialog *pThis, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);
    };
    static enum State {
        DIALOG_STATE_INVALID,
        DIALOG_STATE_START,
        DIALOG_STATE_SEND_ENTRY,
        DIALOG_STATE_SEND_REPLIES,
        DIALOG_STATE_HANDLE_REPLY
    } statestack[16];
    static int32_t ssp;
    static CNWSDialog *pDialog;
    static CNWSObject *pOwner;
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
    ArgumentStack End                  (ArgumentStack&& args);
};

}
