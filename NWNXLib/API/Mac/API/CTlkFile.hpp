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
    int32_t ReadHeader();
};

void CTlkFile__CTlkFileCtor__0(CTlkFile* thisPtr, CExoString);
int32_t CTlkFile__ReadHeader(CTlkFile* thisPtr);

}

}
