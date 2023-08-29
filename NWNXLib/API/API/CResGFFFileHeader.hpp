#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResGFFFileHeader)
#endif





class CResGFFFileHeader
{
public:
    uint32_t m_nFileType;
    uint32_t m_nFileVersion;
    uint32_t m_nStructOffset;
    uint32_t m_nStructCount;
    uint32_t m_nFieldOffset;
    uint32_t m_nFieldCount;
    uint32_t m_nLabelOffset;
    uint32_t m_nLabelCount;
    uint32_t m_nDataFieldOffset;
    uint32_t m_nDataFieldCount;
    uint32_t m_nDataLayoutFieldOffset;
    uint32_t m_nDataLayoutFieldCount;
    uint32_t m_nDataLayoutListOffset;
    uint32_t m_nDataLayoutListCount;



#ifdef NWN_CLASS_EXTENSION_CResGFFFileHeader
    NWN_CLASS_EXTENSION_CResGFFFileHeader
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResGFFFileHeader)
#endif

