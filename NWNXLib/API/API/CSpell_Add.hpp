#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CSpell_Add)
#endif



typedef int BOOL;


class CSpell_Add
{
    uint32_t m_nSpellID;
    BOOL m_bReadied;
    BOOL m_bDomainSpell;
    uint8_t m_nMetaType;
    uint8_t m_nSpellSlot;
    uint8_t m_nSpellLevel;



#ifdef NWN_CLASS_EXTENSION_CSpell_Add
    NWN_CLASS_EXTENSION_CSpell_Add
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CSpell_Add)
#endif

