#include "CNWSPlayerStoreGUI.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPlayer.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerStoreGUI::CNWSPlayerStoreGUI()
{
    CNWSPlayerStoreGUI__CNWSPlayerStoreGUICtor__0(this);
}

void CNWSPlayerStoreGUI::CloseStore(CNWSPlayer* a0, int32_t a1)
{
    return CNWSPlayerStoreGUI__CloseStore(this, a0, a1);
}

void CNWSPlayerStoreGUI::OpenStore(CNWSPlayer* a0, uint32_t a1, char a2, char a3)
{
    return CNWSPlayerStoreGUI__OpenStore(this, a0, a1, a2, a3);
}

void CNWSPlayerStoreGUI__CNWSPlayerStoreGUICtor__0(CNWSPlayerStoreGUI* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerStoreGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerStoreGUI__CNWSPlayerStoreGUICtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSPlayerStoreGUI__CloseStore(CNWSPlayerStoreGUI* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerStoreGUI*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerStoreGUI__CloseStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerStoreGUI__OpenStore(CNWSPlayerStoreGUI* thisPtr, CNWSPlayer* a0, uint32_t a1, char a2, char a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerStoreGUI*, CNWSPlayer*, uint32_t, char, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerStoreGUI__OpenStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
