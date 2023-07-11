#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CAutoSave)
#endif



typedef int BOOL;


class CAutoSave
{
public:
    BOOL bAtIntervals;
    BOOL bAtSavePoints;
    BOOL bOnPlayerChange;
    int32_t nInterval;



#ifdef NWN_CLASS_EXTENSION_CAutoSave
    NWN_CLASS_EXTENSION_CAutoSave
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAutoSave)
#endif

