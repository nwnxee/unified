#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWClass_Feat
{
    uint16_t nFeat;
    uint8_t nLevelGranted;
    uint8_t nListType;
    int32_t nTalentCategory;
    int32_t nMaxCR;
    int32_t nOnClassRadial;
};

}

}
