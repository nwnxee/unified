#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWPlayerCharacterListClass_st)
#endif





class NWPlayerCharacterListClass_st
{
    int32_t nClass;
    uint8_t nClassLevel;



#ifdef NWN_CLASS_EXTENSION_NWPlayerCharacterListClass_st
    NWN_CLASS_EXTENSION_NWPlayerCharacterListClass_st
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWPlayerCharacterListClass_st)
#endif

