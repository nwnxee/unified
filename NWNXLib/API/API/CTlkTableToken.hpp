#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkTableToken)
#endif





class CTlkTableToken
{
    uint32_t m_nHash;
    CExoString m_sToken;
    uint32_t m_nActionCode;
    uint32_t m_nStrRef[4];
    uint32_t m_nStrRefDefault;



#ifdef NWN_CLASS_EXTENSION_CTlkTableToken
    NWN_CLASS_EXTENSION_CTlkTableToken
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTlkTableToken)
#endif

