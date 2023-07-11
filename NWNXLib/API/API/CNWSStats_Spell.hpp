#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSStats_Spell)
#endif



typedef int BOOL;


class CNWSStats_Spell
{
    uint32_t m_nSpellId;
    BOOL m_bReadied;
    uint8_t m_nMetaType;
    BOOL m_bDomainSpell;

    CNWSStats_Spell();


#ifdef NWN_CLASS_EXTENSION_CNWSStats_Spell
    NWN_CLASS_EXTENSION_CNWSStats_Spell
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSStats_Spell)
#endif

