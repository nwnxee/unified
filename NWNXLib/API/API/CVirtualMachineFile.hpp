#pragma once
#include "nwn_api.hpp"

#include "CResNCS.hpp"
#include "CResHelper.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineFile)
#endif

struct CExoString;


typedef int BOOL;


struct CVirtualMachineFile : CResHelper<CResNCS, 2010>
{

    CVirtualMachineFile();
    ~CVirtualMachineFile();
    BOOL LoadFile(const CExoString & sFileName);
    void UnloadFile();
    void GetData(char * * pData, uint32_t & nSize);


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineFile
    NWN_CLASS_EXTENSION_CVirtualMachineFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineFile)
#endif

