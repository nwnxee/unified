#pragma once

#include <cstdint>

#include "LIST4.hpp"
#include "LOG4HEADER.hpp"
#include "s4singleDistantSt.hpp"
#include "s4singleSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4TRANSSt;

struct TRAN4St
{
    CODE4TRANSSt* c4trans;
    LIST4* dataList;
    LIST4 localDataList;
    char dateFormat[20];
    int32_t currentTranStatus;
    int16_t unlockAuto;
    int16_t savedUnlockAuto;
    s4singleDistantSt toLock;
    s4singleSt locks;
    int32_t transId;
    uint32_t pos;
    LOG4HEADER header;
    uint32_t dataPos;
    int32_t userIdNo;
    LIST4 closedDataFiles;
    char userId[11];
    char netId[21];
};

}

}
