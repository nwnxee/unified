#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"
#include "ScriptParam.hpp"
#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogLinkReply)
#endif



typedef int BOOL;


struct CNWSDialogLinkReply
{
    CResRef m_sActive;
    CExoArrayList<ScriptParam> m_lConditionParams;
    uint32_t m_nIndex;
    BOOL m_bDisplayInactive;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogLinkReply
    NWN_CLASS_EXTENSION_CNWSDialogLinkReply
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogLinkReply)
#endif

