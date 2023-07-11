#pragma once
#include "nwn_api.hpp"

#include "CNWSpell.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSpellArray)
#endif





class CNWSpellArray
{
    int32_t m_nNumSpells;
    CNWSpell * m_pSpells;

    CNWSpellArray();
    ~CNWSpellArray();
    CNWSpell * GetSpell(int32_t nSpellID) const;
    void Load();
    CNWSpell operator[](int32_t position) const;


#ifdef NWN_CLASS_EXTENSION_CNWSpellArray
    NWN_CLASS_EXTENSION_CNWSpellArray
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSpellArray)
#endif

