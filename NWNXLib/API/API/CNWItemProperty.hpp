#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWItemProperty)
#endif



typedef int BOOL;


class CNWItemProperty
{
    uint16_t m_nPropertyName;
    uint16_t m_nSubType;
    uint8_t m_nCostTable;
    uint16_t m_nCostTableValue;
    uint8_t m_nParam1;
    uint8_t m_nParam1Value;
    uint8_t m_nChanceOfAppearing;
    BOOL m_bUseable;
    uint8_t m_nUsesPerDay;
    uint8_t m_nDurationType;
    CExoString m_sCustomTag;
    uint64_t m_nID;



#ifdef NWN_CLASS_EXTENSION_CNWItemProperty
    NWN_CLASS_EXTENSION_CNWItemProperty
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWItemProperty)
#endif

