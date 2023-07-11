#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResGFFStruct)
#endif





class CResGFFStruct
{
public:
    uint32_t m_nType;
    uint32_t m_nDataOrDataOffset;
    uint32_t m_nFieldCount;



#ifdef NWN_CLASS_EXTENSION_CResGFFStruct
    NWN_CLASS_EXTENSION_CResGFFStruct
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResGFFStruct)
#endif

