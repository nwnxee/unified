#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SETSection)
#endif

class SETEntry;




class SETSection
{
    CExoString m_sSection;
    SETEntry * m_pEntry;
    uint32_t m_nNumEntries;



#ifdef NWN_CLASS_EXTENSION_SETSection
    NWN_CLASS_EXTENSION_SETSection
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SETSection)
#endif

