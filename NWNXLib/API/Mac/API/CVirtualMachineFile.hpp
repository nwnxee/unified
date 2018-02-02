#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResNCS2010u.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CVirtualMachineFile
    : CResHelperTemplatedCResNCS2010u
{

    // The below are auto generated stubs.
    CVirtualMachineFile(const CVirtualMachineFile&) = default;
    CVirtualMachineFile& operator=(const CVirtualMachineFile&) = default;

    CVirtualMachineFile();
    ~CVirtualMachineFile();
    void GetData(char**, uint32_t&);
    int32_t LoadFile(const CExoString&);
    void UnloadFile();
};

void CVirtualMachineFile__CVirtualMachineFileCtor__0(CVirtualMachineFile* thisPtr);
void CVirtualMachineFile__CVirtualMachineFileDtor__0(CVirtualMachineFile* thisPtr);
void CVirtualMachineFile__GetData(CVirtualMachineFile* thisPtr, char**, uint32_t&);
int32_t CVirtualMachineFile__LoadFile(CVirtualMachineFile* thisPtr, const CExoString&);
void CVirtualMachineFile__UnloadFile(CVirtualMachineFile* thisPtr);

}

}
