#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"
#include "RESID.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CKeyTableEntry)
#endif

struct CRes;


typedef uint16_t RESTYPE;


struct CKeyTableEntry
{
    CResRef m_cResRef;
    CRes * m_pRes;
    RESID m_nID;
    uint16_t m_nRefCount;
    RESTYPE m_nType;



#ifdef NWN_CLASS_EXTENSION_CKeyTableEntry
    NWN_CLASS_EXTENSION_CKeyTableEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CKeyTableEntry)
#endif

