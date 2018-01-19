#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct EncapsulatedHeader_st
{
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nNumLanguages;
    uint32_t nLocalizedStringSize;
    uint32_t nEntries;
    uint32_t nOffsetToLocalizedString;
    uint32_t nOffsetToKeyList;
    uint32_t nOffsetToResourceList;
    uint32_t nBuildYear;
    uint32_t nBuildDay;
    uint32_t nDescriptionStringRef;
    uint8_t pMD5[16];
    uint8_t pUnused[100];
};

}

}
