#pragma once

#include <cstdint>

#include "B4NODE_HEADER.hpp"
#include "B4STD_HEADER.hpp"
#include "STRUCT_B4NODE.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct B4KEY_DATA;
struct TAG4FILESt;

struct B4BLOCK
{
    l4linkSt link;
    TAG4FILESt* tag;
    int32_t changed;
    STRUCT_B4NODE fileBlock;
    int32_t keyOn;
    int32_t curTrailCnt;
    int32_t curDupCnt;
    int32_t dupPos;
    int32_t trailPos;
    int32_t recPos;
    char* curPos;
    int32_t builtOn;
    char* builtPos;
    B4KEY_DATA* builtKey;
    B4STD_HEADER header;
    B4NODE_HEADER nodeHdr;
    char data[1];
};

}

}
