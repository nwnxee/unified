#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResNDB
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nNDBNormalSize;
    uint8_t* m_pNDBData;

    // The below are auto generated stubs.
    CResNDB(const CResNDB&) = default;
    CResNDB& operator=(const CResNDB&) = default;

    CResNDB();
    ~CResNDB();
    unsigned char* GetNDBDataPtr();
    uint32_t GetNDBSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResNDB__CResNDBCtor__0(CResNDB* thisPtr);
void CResNDB__CResNDBDtor__0(CResNDB* thisPtr);
unsigned char* CResNDB__GetNDBDataPtr(CResNDB* thisPtr);
uint32_t CResNDB__GetNDBSize(CResNDB* thisPtr);
int32_t CResNDB__IsLoaded(CResNDB* thisPtr);
int32_t CResNDB__OnResourceFreed(CResNDB* thisPtr);
int32_t CResNDB__OnResourceServiced(CResNDB* thisPtr);

}

}
