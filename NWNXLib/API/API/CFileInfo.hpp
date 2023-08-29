#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CFileInfo)
#endif





class CFileInfo
{
public:
    CExoString sFileName;
    uint16_t nYear;
    uint16_t nMonth;
    uint16_t nDay;
    uint16_t nHour;
    uint16_t nMinute;
    uint16_t nSecond;



#ifdef NWN_CLASS_EXTENSION_CFileInfo
    NWN_CLASS_EXTENSION_CFileInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CFileInfo)
#endif

