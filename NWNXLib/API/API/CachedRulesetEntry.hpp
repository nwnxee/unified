#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CachedRulesetEntry)
#endif





class CachedRulesetEntry
{
public:
    CExoString s;
    int32_t i;
    float f;



#ifdef NWN_CLASS_EXTENSION_CachedRulesetEntry
    NWN_CLASS_EXTENSION_CachedRulesetEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CachedRulesetEntry)
#endif

