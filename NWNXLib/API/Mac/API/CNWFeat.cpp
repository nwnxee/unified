#include "CNWFeat.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWFeat::CNWFeat()
{
    CNWFeat__CNWFeatCtor__0(this);
}

CNWFeat::~CNWFeat()
{
    CNWFeat__CNWFeatDtor__0(this);
}

CExoString CNWFeat::GetDescriptionText()
{
    return CNWFeat__GetDescriptionText(this);
}

CExoString CNWFeat::GetNameText()
{
    return CNWFeat__GetNameText(this);
}

void CNWFeat__CNWFeatCtor__0(CNWFeat* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWFeat*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWFeat__CNWFeatCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWFeat__CNWFeatDtor__0(CNWFeat* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWFeat*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWFeat__CNWFeatDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString CNWFeat__GetDescriptionText(CNWFeat* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWFeat*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWFeat__GetDescriptionText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWFeat__GetNameText(CNWFeat* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWFeat*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWFeat__GetNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
