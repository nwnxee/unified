#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(RESID)
#endif





class RESID
{
public:
    uint32_t m_resFileSource;
    uint32_t m_resFileId;
    uint32_t m_resTableId;
    uint32_t m_resItemId;



#ifdef NWN_CLASS_EXTENSION_RESID
    NWN_CLASS_EXTENSION_RESID
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(RESID)
#endif

