#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineCache)
#endif

struct CExoString;
struct CVirtualMachineFile;




struct CVirtualMachineCache
{
    CExoArrayList<CVirtualMachineFile *> m_aFiles;

    ~CVirtualMachineCache();
    void PrecacheFile(const CExoString & sFileName);
    void ClearAllFiles();


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineCache
    NWN_CLASS_EXTENSION_CVirtualMachineCache
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineCache)
#endif

