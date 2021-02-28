#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "ScriptParam.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CNWSDialogPlayer.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialog)
#endif

struct CExoString;
struct CNWSDialogEntry;
struct CNWSDialogLinkEntry;
struct CNWSDialogReply;
struct CNWSDialogSpeaker;
struct CNWSObject;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSDialog
{
    uint32_t m_nEntries;
    CNWSDialogEntry * m_pEntries;
    uint32_t m_nReplies;
    CNWSDialogReply * m_pReplies;
    uint32_t m_nStartingEntries;
    CNWSDialogLinkEntry * m_pStartingEntries;
    CResRef m_refEndDialogNormal;
    CResRef m_refEndDialogAbort;
    CExoLinkedList<CNWSDialogPlayer> m_lPlayers;
    BOOL m_bRepliesSent;
    BOOL m_bEndOfDialog;
    uint32_t m_currentEntryIndex;
    uint32_t m_nReplyIndex;
    uint8_t m_lastGender;
    OBJECT_ID m_oidLastObject;
    OBJECT_ID m_oidDialogOwner;
    CNWSDialogSpeaker * m_pSpeakerMap;
    uint32_t m_nSpeakerMap;
    BOOL m_bMultiPCDialogViewOnly;
    BOOL m_bPrivate;
    OBJECT_ID m_oidLastEntrySpeaker;
    OBJECT_ID m_oidLastReplySpeaker;
    BOOL m_bDisableCameraZoom;

    CNWSDialog();
    virtual ~CNWSDialog();
    void ClearDialogOwnerInObject(OBJECT_ID oidObject);
    void Cleanup();
    BOOL LoadDialog(CResGFF * pRes, BOOL bLoadReplies);
    CNWSObject * GetSpeaker(CNWSObject * pNWSObjectOwner, const CExoString & sSpeaker);
    BOOL CheckScript(CNWSObject* pNWSObjectSpeaker, const CResRef& sActive, const CExoArrayList<ScriptParam>& scriptParams);
    void RunScript(CNWSObject* pNWSObjectSpeaker, const CResRef& sScript, const CExoArrayList<ScriptParam>& scriptParams);
    uint32_t GetStartEntry(CNWSObject * pNWSObjectOwner);
    BOOL GetStartEntryOneLiner(CNWSObject * pNWSObjectOwner, CExoLocString & sOneLiner, CResRef & sSound, CResRef & sScript, CExoArrayList<ScriptParam> & scriptParams);
    float SetDialogDelay(CNWSObject * pNWSObjectOwner, CExoLocString sLocText, uint32_t nMinSeconds, BOOL bEnableNPCTiming);
    void AddJournalEntry(const CExoString & szPlotID, uint32_t nState, uint32_t nPlayerId);
    BOOL SendDialogEntry(CNWSObject * pNWSObjectOwner, uint32_t nPlayerIdGUIOnly, uint32_t iEntry, BOOL bPlayHelloSound);
    BOOL SendDialogReplies(CNWSObject * pNWSObjectOwner, uint32_t nPlayerIdGUIOnly);
    BOOL HandleReply(uint32_t nPlayerID, CNWSObject * pNWSObjectOwner, uint32_t nReplyIndex, BOOL bEscapeDialog, uint32_t currentEntryIndex);
    BOOL RemovePlayer(OBJECT_ID oidRemove);
    BOOL IsPlayerInDialog(OBJECT_ID oidPlayer);
    void LoadScriptParams(CResGFF * pRes, CExoArrayList<ScriptParam> & paramsList, CResStruct * pStructure, char * szFieldID);


#ifdef NWN_CLASS_EXTENSION_CNWSDialog
    NWN_CLASS_EXTENSION_CNWSDialog
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialog)
#endif

