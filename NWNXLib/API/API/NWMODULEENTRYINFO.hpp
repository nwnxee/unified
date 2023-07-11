#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWMODULEENTRYINFO)
#endif





class NWMODULEENTRYINFO
{
public:
    CResRef refArea;
    float nX;
    float nY;
    float nZ;
    float fDirX;
    float fDirY;



#ifdef NWN_CLASS_EXTENSION_NWMODULEENTRYINFO
    NWN_CLASS_EXTENSION_NWMODULEENTRYINFO
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWMODULEENTRYINFO)
#endif

