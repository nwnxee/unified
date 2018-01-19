#include "CNWSPlayerContainerGUI.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPlayer.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerContainerGUI::CNWSPlayerContainerGUI()
{
    CNWSPlayerContainerGUI__CNWSPlayerContainerGUICtor__0(this);
}

void CNWSPlayerContainerGUI::SetNextPage(CNWSPlayer* a0)
{
    return CNWSPlayerContainerGUI__SetNextPage(this, a0);
}

void CNWSPlayerContainerGUI::SetOpen(CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    return CNWSPlayerContainerGUI__SetOpen(this, a0, a1, a2);
}

void CNWSPlayerContainerGUI::SetPreviousPage(CNWSPlayer* a0)
{
    return CNWSPlayerContainerGUI__SetPreviousPage(this, a0);
}

void CNWSPlayerContainerGUI__CNWSPlayerContainerGUICtor__0(CNWSPlayerContainerGUI* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerContainerGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerContainerGUI__CNWSPlayerContainerGUICtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSPlayerContainerGUI__SetNextPage(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerContainerGUI*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerContainerGUI__SetNextPage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerContainerGUI__SetOpen(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerContainerGUI*, CNWSPlayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerContainerGUI__SetOpen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlayerContainerGUI__SetPreviousPage(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerContainerGUI*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerContainerGUI__SetPreviousPage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
