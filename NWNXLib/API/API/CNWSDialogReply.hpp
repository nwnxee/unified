#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"
#include "ScriptParam.hpp"
#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogReply)
#endif

struct CNWSDialogLinkEntry;




struct CNWSDialogReply
{
    uint32_t m_nAnimation;
    uint8_t m_bAnimationLoop;
    CExoLocString m_sText;
    CNWSDialogLinkEntry * m_pEntries;
    uint32_t m_nEntries;
    CResRef m_sScript;
    CExoArrayList<ScriptParam> m_lActionParams;
    uint32_t m_nDelay;
    CResRef m_sSound;
    CExoString m_sQuestTag;
    uint32_t m_nQuestId;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogReply
    NWN_CLASS_EXTENSION_CNWSDialogReply
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogReply)
#endif

