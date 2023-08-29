#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResetOption)
#endif



typedef int BOOL;


class CResetOption
{
public:
    BOOL bOnVacant;
    BOOL bOnVictory;
    BOOL bOnFailure;
    BOOL bOnDeath;
    BOOL bOnPartyDeath;



#ifdef NWN_CLASS_EXTENSION_CResetOption
    NWN_CLASS_EXTENSION_CResetOption
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResetOption)
#endif

