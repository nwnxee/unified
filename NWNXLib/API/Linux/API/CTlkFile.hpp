#pragma once

#include <cstdint>

#include "CExoFile.hpp"
#include "CExoString.hpp"
#include "TLK_FILE_HEADER.hpp"

namespace NWNXLib {

namespace API {

struct CTlkFile
    : CExoFile
{
    TLK_FILE_HEADER m_header;

    // The below are auto generated stubs.
    CTlkFile() = default;
    CTlkFile(const CTlkFile&) = default;
    CTlkFile& operator=(const CTlkFile&) = default;

    CTlkFile(CExoString);
    CTlkFile(const void*, int32_t);
    ~CTlkFile();
    int32_t ReadHeader();
};

void CTlkFile__CTlkFileCtor__0(CTlkFile* thisPtr, CExoString);
void CTlkFile__CTlkFileCtor__1(CTlkFile* thisPtr, const void*, int32_t);
void CTlkFile__CTlkFileDtor__0(CTlkFile* thisPtr);
int32_t CTlkFile__ReadHeader(CTlkFile* thisPtr);

}

}
