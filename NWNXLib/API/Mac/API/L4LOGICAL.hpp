#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct E4INFO_REPORT;
struct RELATION4St;
struct e4exprSt;

struct L4LOGICAL
{
    e4exprSt* expr;
    E4INFO_REPORT* infoReport;
    RELATION4St* relation;
    CODE4St* codeBase;
    char* buf;
    uint32_t bufPos;
    uint32_t bufLen;
};

}

}
