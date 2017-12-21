#include "CVirtualMachineScript.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CVirtualMachineStack.hpp"

namespace NWNXLib {

namespace API {

CVirtualMachineScript::CVirtualMachineScript()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CVirtualMachineScript::CVirtualMachineScript(const CVirtualMachineScript&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CVirtualMachineScript& CVirtualMachineScript::operator=(const CVirtualMachineScript&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CVirtualMachineScript::~CVirtualMachineScript()
{
    CVirtualMachineScript__CVirtualMachineScriptDtor(this);
}

void CVirtualMachineScript__CVirtualMachineScriptDtor(CVirtualMachineScript* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CVirtualMachineScript*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CVirtualMachineScript__CVirtualMachineScriptDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
