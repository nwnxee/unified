#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SRecord
{
    CExoString sVarName;
    CExoString sPlayerId;
    CExoString sTimeStamp;
    char cVarType;
    double nVarNum1;
    double nVarNum2;
    double nVarNum3;
    double nVarNum4;
    double nVarNum5;
    double nVarNum6;
    int32_t nVarInt;
    void* pVarData;
    uint32_t nVarDataLength;
};

}

}
