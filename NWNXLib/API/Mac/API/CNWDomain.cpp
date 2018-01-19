#include "CNWDomain.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWDomain::CNWDomain()
{
    CNWDomain__CNWDomainCtor__0(this);
}

CNWDomain::~CNWDomain()
{
    CNWDomain__CNWDomainDtor__0(this);
}

CExoString CNWDomain::GetDescriptionText()
{
    return CNWDomain__GetDescriptionText(this);
}

CExoString CNWDomain::GetNameText()
{
    return CNWDomain__GetNameText(this);
}

void CNWDomain__CNWDomainCtor__0(CNWDomain* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWDomain*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDomain__CNWDomainCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWDomain__CNWDomainDtor__0(CNWDomain* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWDomain*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDomain__CNWDomainDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString CNWDomain__GetDescriptionText(CNWDomain* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWDomain*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDomain__GetDescriptionText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWDomain__GetNameText(CNWDomain* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWDomain*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDomain__GetNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
