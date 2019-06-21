#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3InitInfo
{
    int32_t newTnum;
    uint8_t iDb;
    uint8_t busy;
    uint32_t orphanTrigger : 1;
    uint32_t imposterTable : 1;
    uint32_t reopenMemdb : 1;
};

}

}
