#include "CExoArrayListTemplatedCNWItemProperty.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWItemProperty.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWItemProperty::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNWItemProperty__Allocate(this, a0);
}

CExoArrayListTemplatedCNWItemProperty& CExoArrayListTemplatedCNWItemProperty::operator=(const CExoArrayListTemplatedCNWItemProperty& a0)
{
    return CExoArrayListTemplatedCNWItemProperty__OperatorAssignment(this, a0);
}

void CExoArrayListTemplatedCNWItemProperty__Allocate(CExoArrayListTemplatedCNWItemProperty* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWItemProperty*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWItemProperty__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoArrayListTemplatedCNWItemProperty& CExoArrayListTemplatedCNWItemProperty__OperatorAssignment(CExoArrayListTemplatedCNWItemProperty* thisPtr, const CExoArrayListTemplatedCNWItemProperty& a0)
{
    using FuncPtrType = CExoArrayListTemplatedCNWItemProperty&(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWItemProperty*, const CExoArrayListTemplatedCNWItemProperty&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWItemProperty__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
