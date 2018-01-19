#include "CExoStringList.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CExoStringList::CExoStringList()
{
    CExoStringList__CExoStringListCtor__0(this);
}

CExoStringList::CExoStringList(CExoStringList* a0)
{
    CExoStringList__CExoStringListCtor__1(this, a0);
}

CExoStringList::CExoStringList(int32_t a0, int32_t a1, int32_t a2)
{
    CExoStringList__CExoStringListCtor__2(this, a0, a1, a2);
}

CExoStringList::~CExoStringList()
{
    CExoStringList__CExoStringListDtor(this);
}

void CExoStringList::Add(CExoString* a0)
{
    return CExoStringList__Add(this, a0);
}

void CExoStringList::AddSorted(CExoString* a0)
{
    return CExoStringList__AddSorted(this, a0);
}

void CExoStringList::Clear()
{
    return CExoStringList__Clear(this);
}

void CExoStringList::Delete(CExoString* a0)
{
    return CExoStringList__Delete(this, a0);
}

int32_t CExoStringList::GetCount()
{
    return CExoStringList__GetCount(this);
}

int32_t CExoStringList::GetDuplicate()
{
    return CExoStringList__GetDuplicate(this);
}

int32_t CExoStringList::GetSize()
{
    return CExoStringList__GetSize(this);
}

int32_t CExoStringList::GetSorted()
{
    return CExoStringList__GetSorted(this);
}

CExoString* CExoStringList::GetString(int32_t a0)
{
    return CExoStringList__GetString(this, a0);
}

void CExoStringList::Insert(CExoString* a0, int32_t a1)
{
    return CExoStringList__Insert(this, a0, a1);
}

void CExoStringList::Introduce(CExoString* a0, int32_t a1)
{
    return CExoStringList__Introduce(this, a0, a1);
}

CExoStringList* CExoStringList::Merge(CExoStringList* a0, int32_t a1, int32_t a2)
{
    return CExoStringList__Merge(this, a0, a1, a2);
}

CExoString* CExoStringList::operator*(int32_t a0)
{
    return CExoStringList__OperatorMultiplication(this, a0);
}

CExoStringList& CExoStringList::operator=(CExoStringList& a0)
{
    return CExoStringList__OperatorAssignment(this, a0);
}

void CExoStringList::Remove(int32_t a0)
{
    return CExoStringList__Remove(this, a0);
}

void CExoStringList__CExoStringListCtor__0(CExoStringList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__CExoStringListCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoStringList__CExoStringListCtor__1(CExoStringList* thisPtr, CExoStringList* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__CExoStringListCtor__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoStringList__CExoStringListCtor__2(CExoStringList* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__CExoStringListCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CExoStringList__CExoStringListDtor(CExoStringList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__CExoStringListDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoStringList__Add(CExoStringList* thisPtr, CExoString* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoStringList__AddSorted(CExoStringList* thisPtr, CExoString* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__AddSorted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoStringList__Clear(CExoStringList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Clear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoStringList__Delete(CExoStringList* thisPtr, CExoString* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Delete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoStringList__GetCount(CExoStringList* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__GetCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoStringList__GetDuplicate(CExoStringList* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__GetDuplicate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoStringList__GetSize(CExoStringList* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__GetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoStringList__GetSorted(CExoStringList* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoStringList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__GetSorted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString* CExoStringList__GetString(CExoStringList* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CExoStringList*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoStringList__Insert(CExoStringList* thisPtr, CExoString* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Insert);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoStringList__Introduce(CExoStringList* thisPtr, CExoString* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, CExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Introduce);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoStringList* CExoStringList__Merge(CExoStringList* thisPtr, CExoStringList* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = CExoStringList*(__attribute__((cdecl)) *)(CExoStringList*, CExoStringList*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Merge);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString* CExoStringList__OperatorMultiplication(CExoStringList* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CExoStringList*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__OperatorMultiplication);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoStringList& CExoStringList__OperatorAssignment(CExoStringList* thisPtr, CExoStringList& a0)
{
    using FuncPtrType = CExoStringList&(__attribute__((cdecl)) *)(CExoStringList*, CExoStringList&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoStringList__Remove(CExoStringList* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoStringList*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoStringList__Remove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
