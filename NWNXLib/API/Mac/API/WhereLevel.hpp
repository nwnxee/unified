#pragma once

#include <cstdint>

#include "unknown_TLS_3F16651113D4B959B261AA7F63ECBF0D.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct WhereLoop;

struct WhereLevel
{
    int32_t iLeftJoin;
    int32_t iTabCur;
    int32_t iIdxCur;
    int32_t addrBrk;
    int32_t addrNxt;
    int32_t addrSkip;
    int32_t addrCont;
    int32_t addrFirst;
    int32_t addrBody;
    uint32_t iLikeRepCntr;
    int32_t addrLikeRep;
    uint8_t iFrom;
    uint8_t op;
    uint8_t p3;
    uint8_t p5;
    int32_t p1;
    int32_t p2;
    TLS_3F16651113D4B959B261AA7F63ECBF0D u;
    WhereLoop* pWLoop;
    u64 notReady;
};

}

}
