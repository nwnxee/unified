#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResGenericFileHeader)
#endif





class CResGenericFileHeader
{
    uint32_t m_nFileType;
    uint32_t m_nVersion;



#ifdef NWN_CLASS_EXTENSION_CResGenericFileHeader
    NWN_CLASS_EXTENSION_CResGenericFileHeader
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResGenericFileHeader)
#endif

