#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCVirtualMachineFilePtr.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CVirtualMachineCache
{
    CExoArrayListTemplatedCVirtualMachineFilePtr m_aFiles;

    // The below are auto generated stubs.
    CVirtualMachineCache();
    CVirtualMachineCache(const CVirtualMachineCache&);
    CVirtualMachineCache& operator=(const CVirtualMachineCache&);

    ~CVirtualMachineCache();
    void ClearAllFiles();
    void PrecacheFile(const CExoString&);
};

void CVirtualMachineCache__CVirtualMachineCacheDtor__0(CVirtualMachineCache* thisPtr);
void CVirtualMachineCache__ClearAllFiles(CVirtualMachineCache* thisPtr);
void CVirtualMachineCache__PrecacheFile(CVirtualMachineCache* thisPtr, const CExoString&);

}

}
