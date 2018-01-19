#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWItemProperty
{
    uint16_t m_nPropertyName;
    uint16_t m_nSubType;
    uint8_t m_nCostTable;
    uint16_t m_nCostTableValue;
    uint8_t m_nParam1;
    uint8_t m_nParam1Value;
    uint8_t m_nChanceOfAppearing;
    int32_t m_bUseable;
    uint8_t m_nUsesPerDay;
    uint8_t m_nDurationType;
    CExoString m_sCustomTag;
    uint64_t m_nID;
};

}

}
