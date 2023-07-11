#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWDomain)
#endif



typedef int BOOL;


class CNWDomain
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    CResRef m_cIcon;
    uint32_t m_lstSpells[10];
    uint16_t m_nGrantedFeat;
    BOOL m_bValidDomain;
    BOOL m_bCastableFeat;

    CNWDomain();
    ~CNWDomain();
    CExoString GetNameText();
    CExoString GetDescriptionText();


#ifdef NWN_CLASS_EXTENSION_CNWDomain
    NWN_CLASS_EXTENSION_CNWDomain
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWDomain)
#endif

