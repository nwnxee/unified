#include "CLastUpdateObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPlayerLUOQuickbarItemButton.hpp"

namespace NWNXLib {

namespace API {

CLastUpdateObject::CLastUpdateObject()
{
    CLastUpdateObject__CLastUpdateObjectCtor__0(this);
}

CLastUpdateObject::~CLastUpdateObject()
{
    CLastUpdateObject__CLastUpdateObjectDtor__0(this);
}

void CLastUpdateObject::InitializeQuickbar()
{
    return CLastUpdateObject__InitializeQuickbar(this);
}

void CLastUpdateObject__CLastUpdateObjectCtor__0(CLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CLastUpdateObject__CLastUpdateObjectCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CLastUpdateObject__CLastUpdateObjectDtor__0(CLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CLastUpdateObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CLastUpdateObject__CLastUpdateObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CLastUpdateObject__InitializeQuickbar(CLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CLastUpdateObject__InitializeQuickbar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
