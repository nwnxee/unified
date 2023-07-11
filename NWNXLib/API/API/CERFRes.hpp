#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CERFRes)
#endif

class CExoFile;


typedef int BOOL;


class CERFRes
{
public:
    uint32_t m_nOffset;
    uint32_t m_nSize;
    uint8_t * m_pData;

    CERFRes();
    ~CERFRes();
    BOOL Read();
    BOOL Reset();
    BOOL Write(CExoFile & cOutFile, uint32_t nTablePosition);


#ifdef NWN_CLASS_EXTENSION_CERFRes
    NWN_CLASS_EXTENSION_CERFRes
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CERFRes)
#endif

