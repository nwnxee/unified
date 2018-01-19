#include "CGameObjectArray.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CGameObject.hpp"
#include "CGameObjectArrayNode.hpp"

namespace NWNXLib {

namespace API {

CGameObjectArray::CGameObjectArray(int32_t a0)
{
    CGameObjectArray__CGameObjectArrayCtor(this, a0);
}

CGameObjectArray::~CGameObjectArray()
{
    CGameObjectArray__CGameObjectArrayDtor(this);
}

unsigned char CGameObjectArray::AddCharacterObjectAtPos(uint32_t a0, CGameObject* a1)
{
    return CGameObjectArray__AddCharacterObjectAtPos(this, a0, a1);
}

unsigned char CGameObjectArray::AddExternalObject(uint32_t& a0, CGameObject* a1, int32_t a2)
{
    return CGameObjectArray__AddExternalObject(this, a0, a1, a2);
}

unsigned char CGameObjectArray::AddInternalObject(uint32_t& a0, CGameObject* a1, int32_t a2)
{
    return CGameObjectArray__AddInternalObject(this, a0, a1, a2);
}

unsigned char CGameObjectArray::AddObjectAtPos(uint32_t a0, CGameObject* a1)
{
    return CGameObjectArray__AddObjectAtPos(this, a0, a1);
}

void CGameObjectArray::Clean(uint16_t a0)
{
    return CGameObjectArray__Clean(this, a0);
}

unsigned char CGameObjectArray::Delete(uint32_t a0)
{
    return CGameObjectArray__Delete__0(this, a0);
}

unsigned char CGameObjectArray::Delete(uint32_t a0, CGameObject** a1)
{
    return CGameObjectArray__Delete__1(this, a0, a1);
}

unsigned char CGameObjectArray::GetGameObject(uint32_t a0, CGameObject** a1)
{
    return CGameObjectArray__GetGameObject(this, a0, a1);
}

void CGameObjectArray__CGameObjectArrayCtor(CGameObjectArray* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObjectArray*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__CGameObjectArrayCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CGameObjectArray__CGameObjectArrayDtor(CGameObjectArray* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObjectArray*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__CGameObjectArrayDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char CGameObjectArray__AddCharacterObjectAtPos(CGameObjectArray* thisPtr, uint32_t a0, CGameObject* a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t, CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__AddCharacterObjectAtPos);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CGameObjectArray__AddExternalObject(CGameObjectArray* thisPtr, uint32_t& a0, CGameObject* a1, int32_t a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t&, CGameObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__AddExternalObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CGameObjectArray__AddInternalObject(CGameObjectArray* thisPtr, uint32_t& a0, CGameObject* a1, int32_t a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t&, CGameObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__AddInternalObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CGameObjectArray__AddObjectAtPos(CGameObjectArray* thisPtr, uint32_t a0, CGameObject* a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t, CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__AddObjectAtPos);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameObjectArray__Clean(CGameObjectArray* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObjectArray*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__Clean);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CGameObjectArray__Delete__0(CGameObjectArray* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__Delete__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CGameObjectArray__Delete__1(CGameObjectArray* thisPtr, uint32_t a0, CGameObject** a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t, CGameObject**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__Delete__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CGameObjectArray__GetGameObject(CGameObjectArray* thisPtr, uint32_t a0, CGameObject** a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CGameObjectArray*, uint32_t, CGameObject**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObjectArray__GetGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
