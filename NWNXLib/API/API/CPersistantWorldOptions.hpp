#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CPersistantWorldOptions)
#endif



typedef int BOOL;


class CPersistantWorldOptions
{
public:
    BOOL bVaultCharsOnly;
    BOOL bSaveCharsInSaveGame;
    BOOL bSuppressBaseServerVault;
    BOOL bStickyPlayerNames;
    BOOL bServerVaultByPlayerName;



#ifdef NWN_CLASS_EXTENSION_CPersistantWorldOptions
    NWN_CLASS_EXTENSION_CPersistantWorldOptions
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CPersistantWorldOptions)
#endif

