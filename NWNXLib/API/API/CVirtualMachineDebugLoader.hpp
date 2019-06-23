#pragma once
#include "nwn_api.hpp"

#include "CResNDB.hpp"
#include "CResHelper.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineDebugLoader)
#endif

struct CExoString;


typedef int BOOL;


struct CVirtualMachineDebugLoader : CResHelper<CResNDB, 2064>
{
    BOOL m_bLoaded;

    int32_t DemandDebugInfo(CExoString * psFileName);
    uint8_t * GetDataPtr();
    uint32_t GetSize();
    int32_t ReleaseDebugInfo();


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineDebugLoader
    NWN_CLASS_EXTENSION_CVirtualMachineDebugLoader
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineDebugLoader)
#endif

