#include "CNWSSysAdmin.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSSysAdmin::CNWSSysAdmin(uint32_t a0)
{
    CNWSSysAdmin__CNWSSysAdminCtor(this, a0);
}

CNWSSysAdmin::~CNWSSysAdmin()
{
    CNWSSysAdmin__CNWSSysAdminDtor__0(this);
}

CNWSSysAdmin* CNWSSysAdmin::AsNWSSysAdmin()
{
    return CNWSSysAdmin__AsNWSSysAdmin(this);
}

void CNWSSysAdmin__CNWSSysAdminCtor(CNWSSysAdmin* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSysAdmin*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSysAdmin__CNWSSysAdminCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSSysAdmin__CNWSSysAdminDtor__0(CNWSSysAdmin* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSysAdmin*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSysAdmin__CNWSSysAdminDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CNWSSysAdmin* CNWSSysAdmin__AsNWSSysAdmin(CNWSSysAdmin* thisPtr)
{
    using FuncPtrType = CNWSSysAdmin*(__attribute__((cdecl)) *)(CNWSSysAdmin*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSysAdmin__AsNWSSysAdmin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
