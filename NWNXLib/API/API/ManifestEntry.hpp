#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ManifestEntry)
#endif



typedef uint16_t RESTYPE;


struct ManifestEntry
{
    CExoString m_sha1;
    CExoString m_resref;
    RESTYPE m_restype;
    int m_size;



#ifdef NWN_CLASS_EXTENSION_ManifestEntry
    NWN_CLASS_EXTENSION_ManifestEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ManifestEntry)
#endif

