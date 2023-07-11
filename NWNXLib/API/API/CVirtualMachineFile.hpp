#pragma once
#include "nwn_api.hpp"

#include "CResHelper.hpp"
#include "CResNCS.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineFile)
#endif

class CExoString;


typedef int BOOL;


class CVirtualMachineFile : public CResHelper<CResNCS, 2010>
{
public:

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

