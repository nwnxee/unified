#pragma once

#include <cstdint>

#include "FILE4St.hpp"
#include "L4LOGICAL.hpp"
#include "LIST4.hpp"
#include "RELATE4St.hpp"
#include "SORT4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

struct RELATION4St
{
    l4linkSt link;
    RELATE4St relate;
    char* exprSource;
    char locked;
    char* sortSource;
    char sortEofFlag;
    int16_t bitmapDisable;
    char inSort;
    LIST4 sortDataList;
    L4LOGICAL log;
    char* otherData;
    char bitmapsFreed;
    char sortDoneFlag;
    SORT4 sort;
    FILE4St sortedFile;
    int32_t sortOtherLen;
    int32_t sortRecTo;
    int32_t sortRecOn;
    int32_t sortFilePos;
    int32_t sortRecCount;
    int32_t isInitialized;
    char skipBackwards;
    uint32_t relationId;
    RELATE4St* currentRelateLevel;
};

}

}
