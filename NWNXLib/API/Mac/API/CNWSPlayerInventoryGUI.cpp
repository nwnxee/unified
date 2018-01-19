#include "CNWSPlayerInventoryGUI.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPlayer.hpp"
#include "CNWSPlayerContainerGUI.hpp"
#include "CNWSPlayerLUOInventory.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerInventoryGUI::CNWSPlayerInventoryGUI()
{
    CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUICtor__0(this);
}

CNWSPlayerInventoryGUI::~CNWSPlayerInventoryGUI()
{
    CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUIDtor__0(this);
}

void CNWSPlayerInventoryGUI::SetOpen(int32_t a0, int32_t a1)
{
    return CNWSPlayerInventoryGUI__SetOpen(this, a0, a1);
}

void CNWSPlayerInventoryGUI::SetOwner(uint32_t a0)
{
    return CNWSPlayerInventoryGUI__SetOwner(this, a0);
}

void CNWSPlayerInventoryGUI::SetPanel(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSPlayerInventoryGUI__SetPanel(this, a0, a1);
}

void CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUICtor__0(CNWSPlayerInventoryGUI* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerInventoryGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUICtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUIDtor__0(CNWSPlayerInventoryGUI* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerInventoryGUI*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUIDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSPlayerInventoryGUI__SetOpen(CNWSPlayerInventoryGUI* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerInventoryGUI*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerInventoryGUI__SetOpen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerInventoryGUI__SetOwner(CNWSPlayerInventoryGUI* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerInventoryGUI*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerInventoryGUI__SetOwner);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerInventoryGUI__SetPanel(CNWSPlayerInventoryGUI* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerInventoryGUI*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerInventoryGUI__SetPanel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
