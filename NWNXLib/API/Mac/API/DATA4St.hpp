#pragma once

#include <cstdint>

#include "LIST4.hpp"
#include "Single4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4FILESt;
struct F4MEMOSt;
struct FIELD4St;
struct TAG4St;
struct TRAN4St;

struct DATA4St
{
    l4linkSt link;
    l4linkSt dataFileLink;
    int32_t bofFlag;
    int32_t eofFlag;
    int32_t readOnly;
    int32_t recordChanged;
    int32_t count;
    int32_t recNum;
    int32_t recNumOld;
    char alias[33];
    CODE4St* codeBase;
    TRAN4St* trans;
    FIELD4St* fields;
    LIST4 indexes;
    TAG4St* tagSelected;
    DATA4FILESt* dataFile;
    char* groupRecordAlloc;
    char* record;
    char* recordOld;
    char* recordBlank;
    F4MEMOSt* fieldsMemo;
    char memoValidated;
    int32_t logVal;
    char transChanged;
    int32_t clientId;
    Single4 lockedRecords;
};

}

}
