#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4FILESt;
struct DATA4St;
struct E4INFOSt;
struct TAG4FILESt;

struct e4exprSt
{
    E4INFOSt* info;
    int32_t infoN;
    const char* source;
    char* constants;
    int32_t len;
    int32_t type;
    TAG4FILESt* tagPtr;
    DATA4St* data;
    DATA4FILESt* dataFile;
    CODE4St* codeBase;
    uint32_t lenEval;
    int32_t numParms;
    char hasTrim;
    int32_t space2;
    int32_t space3;
    uint32_t exprBufLen;
    char* exprWorkBuf;
};

}

}
