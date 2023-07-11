#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResStructLookUp)
#endif





class CResStructLookUp
{
public:
    uint32_t m_nType;
    uint32_t m_nSize;
    uint32_t m_nOffset;



#ifdef NWN_CLASS_EXTENSION_CResStructLookUp
    NWN_CLASS_EXTENSION_CResStructLookUp
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResStructLookUp)
#endif

