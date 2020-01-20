#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoEncrypt)
#endif





struct CExoEncrypt
{
    uint32_t m_anI[2];
    uint32_t m_aBuf[4];
    uint8_t m_aIn[128];
    uint8_t m_aDigest[16];

    CExoString EncryptString(const CExoString & sInput);
    CExoString GenerateChallenge(uint16_t nLength = 32);
    void MD5Init();
    void MD5Update(uint8_t * inBuf, uint32_t inLen);
    void MD5Final();
    void Transform(uint32_t * buf, uint32_t * in);


#ifdef NWN_CLASS_EXTENSION_CExoEncrypt
    NWN_CLASS_EXTENSION_CExoEncrypt
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoEncrypt)
#endif

