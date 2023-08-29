#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(EXOLTRHEADER)
#endif





class EXOLTRHEADER
{
public:
    uint32_t m_nType;
    uint32_t m_nVersion;
    uint8_t m_nNumLetters;



#ifdef NWN_CLASS_EXTENSION_EXOLTRHEADER
    NWN_CLASS_EXTENSION_EXOLTRHEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(EXOLTRHEADER)
#endif

