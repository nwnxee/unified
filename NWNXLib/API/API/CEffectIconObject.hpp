#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CEffectIconObject)
#endif



typedef int BOOL;


struct CEffectIconObject
{
    uint16_t m_nIcon;
    BOOL m_bFlashing;
    BOOL m_nPlayerBar;



#ifdef NWN_CLASS_EXTENSION_CEffectIconObject
    NWN_CLASS_EXTENSION_CEffectIconObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CEffectIconObject)
#endif

