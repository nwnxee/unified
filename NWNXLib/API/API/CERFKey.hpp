#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CERFKey)
#endif

class CExoFile;
class CExoString;


typedef int BOOL;


class CERFKey
{
    char m_sName[16];
    uint32_t m_nID;
    uint16_t m_nType;
    uint8_t m_nUnused[2];

    CERFKey();
    ~CERFKey();
    void SetName(CExoString & sData);
    BOOL Read();
    BOOL Reset();
    BOOL Write(CExoFile & cOutFile);


#ifdef NWN_CLASS_EXTENSION_CERFKey
    NWN_CLASS_EXTENSION_CERFKey
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CERFKey)
#endif

