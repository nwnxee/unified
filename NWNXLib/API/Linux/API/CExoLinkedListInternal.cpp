#include "CExoLinkedListInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListNode.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListInternal::~CExoLinkedListInternal()
{
    CExoLinkedListInternal__CExoLinkedListInternalDtor(this);
}

CExoLinkedListNode* CExoLinkedListInternal::AddAfter(void* a0, CExoLinkedListNode* a1)
{
    return CExoLinkedListInternal__AddAfter(this, a0, a1);
}

CExoLinkedListNode* CExoLinkedListInternal::AddBefore(void* a0, CExoLinkedListNode* a1)
{
    return CExoLinkedListInternal__AddBefore(this, a0, a1);
}

CExoLinkedListNode* CExoLinkedListInternal::AddHead(void* a0)
{
    return CExoLinkedListInternal__AddHead(this, a0);
}

CExoLinkedListNode* CExoLinkedListInternal::AddTail(void* a0)
{
    return CExoLinkedListInternal__AddTail(this, a0);
}

void* CExoLinkedListInternal::GetAtPos(CExoLinkedListNode* a0)
{
    return CExoLinkedListInternal__GetAtPos(this, a0);
}

void* CExoLinkedListInternal::GetNext(CExoLinkedListNode* a0)
{
    return CExoLinkedListInternal__GetNext(this, a0);
}

void* CExoLinkedListInternal::GetPrev(CExoLinkedListNode* a0)
{
    return CExoLinkedListInternal__GetPrev(this, a0);
}

void* CExoLinkedListInternal::Remove(CExoLinkedListNode* a0)
{
    return CExoLinkedListInternal__Remove(this, a0);
}

void* CExoLinkedListInternal::RemoveHead()
{
    return CExoLinkedListInternal__RemoveHead(this);
}

void* CExoLinkedListInternal::RemoveTail()
{
    return CExoLinkedListInternal__RemoveTail(this);
}

void CExoLinkedListInternal__CExoLinkedListInternalDtor(CExoLinkedListInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__CExoLinkedListInternalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoLinkedListNode* CExoLinkedListInternal__AddAfter(CExoLinkedListInternal* thisPtr, void* a0, CExoLinkedListNode* a1)
{
    using FuncPtrType = CExoLinkedListNode*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, void*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__AddAfter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoLinkedListNode* CExoLinkedListInternal__AddBefore(CExoLinkedListInternal* thisPtr, void* a0, CExoLinkedListNode* a1)
{
    using FuncPtrType = CExoLinkedListNode*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, void*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__AddBefore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoLinkedListNode* CExoLinkedListInternal__AddHead(CExoLinkedListInternal* thisPtr, void* a0)
{
    using FuncPtrType = CExoLinkedListNode*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__AddHead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLinkedListNode* CExoLinkedListInternal__AddTail(CExoLinkedListInternal* thisPtr, void* a0)
{
    using FuncPtrType = CExoLinkedListNode*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__AddTail);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoLinkedListInternal__GetAtPos(CExoLinkedListInternal* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__GetAtPos);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoLinkedListInternal__GetNext(CExoLinkedListInternal* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__GetNext);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoLinkedListInternal__GetPrev(CExoLinkedListInternal* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__GetPrev);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoLinkedListInternal__Remove(CExoLinkedListInternal* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__Remove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoLinkedListInternal__RemoveHead(CExoLinkedListInternal* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__RemoveHead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void* CExoLinkedListInternal__RemoveTail(CExoLinkedListInternal* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoLinkedListInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListInternal__RemoveTail);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
