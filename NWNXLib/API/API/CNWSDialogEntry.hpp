#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CExoArrayList.hpp"
#include "CResRef.hpp"
#include "ScriptParam.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogEntry)
#endif

struct CNWSDialogLinkReply;




struct CNWSDialogEntry
{
    CExoString m_sSpeaker;
    uint32_t m_nAnimation;
    uint8_t m_bAnimationLoop;
    CExoLocString m_sText;
    CNWSDialogLinkReply * m_pReplies;
    uint32_t m_nReplies;
    CResRef m_sScript;
    CExoArrayList<ScriptParam> m_lActionParams;
    uint32_t m_nDelay;
    CResRef m_sSound;
    CExoString m_sQuestTag;
    uint32_t m_nQuestId;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogEntry
    NWN_CLASS_EXTENSION_CNWSDialogEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogEntry)
#endif

