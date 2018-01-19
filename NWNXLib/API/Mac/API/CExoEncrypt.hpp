#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoEncrypt
{
    uint32_t m_anI[2];
    uint32_t m_aBuf[4];
    uint8_t m_aIn[128];
    uint8_t m_aDigest[16];

    CExoString EncryptString(const CExoString&);
    CExoString GenerateChallenge(uint16_t);
};

CExoString CExoEncrypt__EncryptString(CExoEncrypt* thisPtr, const CExoString&);
CExoString CExoEncrypt__GenerateChallenge(CExoEncrypt* thisPtr, uint16_t);

}

}
