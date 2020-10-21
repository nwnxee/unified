#pragma once
#include "nwn_api.hpp"

#include "CResStruct.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResList)
#endif


struct CResList : CResStruct
{
    char m_pLabel[16];



#ifdef NWN_CLASS_EXTENSION_CResList
    NWN_CLASS_EXTENSION_CResList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResList)
#endif
