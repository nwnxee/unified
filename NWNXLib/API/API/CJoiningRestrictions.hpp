#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CJoiningRestrictions)
#endif



typedef int BOOL;


class CJoiningRestrictions
{
public:
    BOOL bAllowLocal;
    BOOL bAllowServer;
    BOOL bAllowVault;
    BOOL bFixedParties;
    BOOL bAllowFighter;
    BOOL bAllowBarbarian;
    BOOL bAllowRanger;
    BOOL bAllowPaladin;
    BOOL bAllowWizard;
    BOOL bAllowSorcerer;
    BOOL bAllowCleric;
    BOOL bAllowDruid;
    BOOL bAllowRogue;
    BOOL bAllowBard;
    BOOL bAllowMonk;
    BOOL bAllowHuman;
    BOOL bAllowElf;
    BOOL bAllowDwarf;
    BOOL bAllowGnome;
    BOOL bAllowHalfling;
    BOOL bAllowHalfOrc;
    BOOL bAllowHalfElf;
    int32_t nMaxPlayers;
    int32_t nMaxParties;
    int32_t nMaxItemPoints;
    int32_t nMaxStatTotal;
    int32_t nMinLevel;
    int32_t nMaxLevel;
    BOOL bAllowLocalVaultChars;



#ifdef NWN_CLASS_EXTENSION_CJoiningRestrictions
    NWN_CLASS_EXTENSION_CJoiningRestrictions
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CJoiningRestrictions)
#endif

