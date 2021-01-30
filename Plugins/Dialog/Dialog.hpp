#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Dialog {

class Dialog : public NWNXLib::Plugin
{
public:
    Dialog(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Dialog();

private:
    struct Hooks {
        static uint32_t GetStartEntry(CNWSDialog*, CNWSObject*);
        static int32_t GetStartEntryOneLiner(CNWSDialog*, CNWSObject*, CExoLocString*, CResRef*, CResRef*, const CExoArrayList<ScriptParam>&);
        static int32_t SendDialogEntry(CNWSDialog*, CNWSObject*, uint32_t, uint32_t, int32_t);
        static int32_t SendDialogReplies(CNWSDialog*, CNWSObject*, uint32_t);
        static int32_t HandleReply(CNWSDialog*, uint32_t, CNWSObject* pNWSObjectOwner, uint32_t, int32_t, uint32_t);
        static int32_t CheckScript(CNWSDialog*, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);
        static void RunScript(CNWSDialog*, CNWSObject*, const CResRef*, const CExoArrayList<ScriptParam>&);
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
