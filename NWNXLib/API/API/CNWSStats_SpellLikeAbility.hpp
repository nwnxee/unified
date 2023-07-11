#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSStats_SpellLikeAbility)
#endif



typedef int BOOL;


class CNWSStats_SpellLikeAbility
{
    uint32_t m_nSpellId;
    BOOL m_bReadied;
    uint8_t m_nCasterLevel;

    CNWSStats_SpellLikeAbility();


#ifdef NWN_CLASS_EXTENSION_CNWSStats_SpellLikeAbility
    NWN_CLASS_EXTENSION_CNWSStats_SpellLikeAbility
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSStats_SpellLikeAbility)
#endif

