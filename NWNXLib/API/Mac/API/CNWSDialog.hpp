#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCNWSDialogPlayer.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSDialogEntry;
struct CNWSDialogLinkEntry;
struct CNWSDialogReply;
struct CNWSDialogSpeaker;
struct CNWSObject;
struct CResGFF;

struct CNWSDialog
{
    void** m_vtable;
    uint32_t m_nEntries;
    CNWSDialogEntry* m_pEntries;
    uint32_t m_nReplies;
    CNWSDialogReply* m_pReplies;
    uint32_t m_nStartingEntries;
    CNWSDialogLinkEntry* m_pStartingEntries;
    CResRef m_refEndDialogNormal;
    CResRef m_refEndDialogAbort;
    CExoLinkedListTemplatedCNWSDialogPlayer m_lPlayers;
    int32_t m_bRepliesSent;
    int32_t m_bEndOfDialog;
    uint32_t m_currentEntryIndex;
    uint32_t m_nReplyIndex;
    uint8_t m_lastGender;
    uint32_t m_oidLastObject;
    uint32_t m_oidDialogOwner;
    CNWSDialogSpeaker* m_pSpeakerMap;
    uint32_t m_nSpeakerMap;
    int32_t m_bMultiPCDialogViewOnly;
    int32_t m_bPrivate;
    uint32_t m_oidLastEntrySpeaker;
    uint32_t m_oidLastReplySpeaker;
    int32_t m_bDisableCameraZoom;

    // The below are auto generated stubs.
    CNWSDialog(const CNWSDialog&) = default;
    CNWSDialog& operator=(const CNWSDialog&) = default;

    CNWSDialog();
    ~CNWSDialog();
    void AddJournalEntry(const CExoString&, uint32_t, uint32_t);
    int32_t CheckScript(CNWSObject*, const CResRef&);
    void Cleanup();
    void ClearDialogOwnerInObject(uint32_t);
    CNWSObject* GetSpeaker(CNWSObject*, const CExoString&);
    uint32_t GetStartEntry(CNWSObject*);
    int32_t GetStartEntryOneLiner(CNWSObject*, CExoLocString&, CResRef&, CResRef&);
    int32_t HandleReply(uint32_t, CNWSObject*, uint32_t, int32_t, uint32_t);
    int32_t IsPlayerInDialog(uint32_t);
    int32_t LoadDialog(CResGFF*, int32_t);
    int32_t RemovePlayer(uint32_t);
    void RunScript(CNWSObject*, const CResRef&);
    int32_t SendDialogEntry(CNWSObject*, uint32_t, uint32_t, int32_t);
    int32_t SendDialogReplies(CNWSObject*, uint32_t);
    float SetDialogDelay(CNWSObject*, CExoLocString, uint32_t, int32_t);
};

void CNWSDialog__CNWSDialogCtor__0(CNWSDialog* thisPtr);
void CNWSDialog__CNWSDialogDtor__0(CNWSDialog* thisPtr);
void CNWSDialog__AddJournalEntry(CNWSDialog* thisPtr, const CExoString&, uint32_t, uint32_t);
int32_t CNWSDialog__CheckScript(CNWSDialog* thisPtr, CNWSObject*, const CResRef&);
void CNWSDialog__Cleanup(CNWSDialog* thisPtr);
void CNWSDialog__ClearDialogOwnerInObject(CNWSDialog* thisPtr, uint32_t);
CNWSObject* CNWSDialog__GetSpeaker(CNWSDialog* thisPtr, CNWSObject*, const CExoString&);
uint32_t CNWSDialog__GetStartEntry(CNWSDialog* thisPtr, CNWSObject*);
int32_t CNWSDialog__GetStartEntryOneLiner(CNWSDialog* thisPtr, CNWSObject*, CExoLocString&, CResRef&, CResRef&);
int32_t CNWSDialog__HandleReply(CNWSDialog* thisPtr, uint32_t, CNWSObject*, uint32_t, int32_t, uint32_t);
int32_t CNWSDialog__IsPlayerInDialog(CNWSDialog* thisPtr, uint32_t);
int32_t CNWSDialog__LoadDialog(CNWSDialog* thisPtr, CResGFF*, int32_t);
int32_t CNWSDialog__RemovePlayer(CNWSDialog* thisPtr, uint32_t);
void CNWSDialog__RunScript(CNWSDialog* thisPtr, CNWSObject*, const CResRef&);
int32_t CNWSDialog__SendDialogEntry(CNWSDialog* thisPtr, CNWSObject*, uint32_t, uint32_t, int32_t);
int32_t CNWSDialog__SendDialogReplies(CNWSDialog* thisPtr, CNWSObject*, uint32_t);
float CNWSDialog__SetDialogDelay(CNWSDialog* thisPtr, CNWSObject*, CExoLocString, uint32_t, int32_t);

}

}
