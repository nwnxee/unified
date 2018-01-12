#include "CTwoDimArrays.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "C2DA.hpp"
#include "CExoLinkedListTemplatedC2DA.hpp"

namespace NWNXLib {

namespace API {

CTwoDimArrays::CTwoDimArrays()
{
    CTwoDimArrays__CTwoDimArraysCtor__0(this);
}

CTwoDimArrays::~CTwoDimArrays()
{
    CTwoDimArrays__CTwoDimArraysDtor__0(this);
}

void CTwoDimArrays::ClearCached2DAs()
{
    return CTwoDimArrays__ClearCached2DAs(this);
}

C2DA* CTwoDimArrays::GetCached2DA(CExoString a0, int32_t a1)
{
    return CTwoDimArrays__GetCached2DA(this, a0, a1);
}

unsigned char CTwoDimArrays::GetEpicAttackBonus(unsigned char a0)
{
    return CTwoDimArrays__GetEpicAttackBonus(this, a0);
}

unsigned char CTwoDimArrays::GetEpicFortSaveBonus(unsigned char a0)
{
    return CTwoDimArrays__GetEpicFortSaveBonus(this, a0);
}

unsigned char CTwoDimArrays::GetEpicRefSaveBonus(unsigned char a0)
{
    return CTwoDimArrays__GetEpicRefSaveBonus(this, a0);
}

unsigned char CTwoDimArrays::GetEpicWillSaveBonus(unsigned char a0)
{
    return CTwoDimArrays__GetEpicWillSaveBonus(this, a0);
}

C2DA* CTwoDimArrays::GetIPRPCostTable(unsigned char a0)
{
    return CTwoDimArrays__GetIPRPCostTable(this, a0);
}

int32_t CTwoDimArrays::Load2DArrays()
{
    return CTwoDimArrays__Load2DArrays(this);
}

int32_t CTwoDimArrays::LoadEpicAttacks()
{
    return CTwoDimArrays__LoadEpicAttacks(this);
}

int32_t CTwoDimArrays::LoadEpicSaves()
{
    return CTwoDimArrays__LoadEpicSaves(this);
}

int32_t CTwoDimArrays::LoadIPRPCostTables()
{
    return CTwoDimArrays__LoadIPRPCostTables(this);
}

int32_t CTwoDimArrays::UnLoad2DArrays()
{
    return CTwoDimArrays__UnLoad2DArrays(this);
}

int32_t CTwoDimArrays::UnLoadIPRPCostTables()
{
    return CTwoDimArrays__UnLoadIPRPCostTables(this);
}

void CTwoDimArrays::Update2DACache(CExoLinkedListTemplatedC2DA* a0, int32_t a1, C2DA* a2)
{
    return CTwoDimArrays__Update2DACache(this, a0, a1, a2);
}

void CTwoDimArrays__CTwoDimArraysCtor__0(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__CTwoDimArraysCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CTwoDimArrays__CTwoDimArraysDtor__0(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTwoDimArrays*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__CTwoDimArraysDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CTwoDimArrays__ClearCached2DAs(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__ClearCached2DAs);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

C2DA* CTwoDimArrays__GetCached2DA(CTwoDimArrays* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = C2DA*(__attribute__((cdecl)) *)(CTwoDimArrays*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetCached2DA);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CTwoDimArrays__GetEpicAttackBonus(CTwoDimArrays* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CTwoDimArrays*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetEpicAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CTwoDimArrays__GetEpicFortSaveBonus(CTwoDimArrays* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CTwoDimArrays*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetEpicFortSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CTwoDimArrays__GetEpicRefSaveBonus(CTwoDimArrays* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CTwoDimArrays*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetEpicRefSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CTwoDimArrays__GetEpicWillSaveBonus(CTwoDimArrays* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CTwoDimArrays*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetEpicWillSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

C2DA* CTwoDimArrays__GetIPRPCostTable(CTwoDimArrays* thisPtr, unsigned char a0)
{
    using FuncPtrType = C2DA*(__attribute__((cdecl)) *)(CTwoDimArrays*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__GetIPRPCostTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CTwoDimArrays__Load2DArrays(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__Load2DArrays);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTwoDimArrays__LoadEpicAttacks(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__LoadEpicAttacks);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTwoDimArrays__LoadEpicSaves(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__LoadEpicSaves);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTwoDimArrays__LoadIPRPCostTables(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__LoadIPRPCostTables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTwoDimArrays__UnLoad2DArrays(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__UnLoad2DArrays);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTwoDimArrays__UnLoadIPRPCostTables(CTwoDimArrays* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTwoDimArrays*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__UnLoadIPRPCostTables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CTwoDimArrays__Update2DACache(CTwoDimArrays* thisPtr, CExoLinkedListTemplatedC2DA* a0, int32_t a1, C2DA* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTwoDimArrays*, CExoLinkedListTemplatedC2DA*, int32_t, C2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTwoDimArrays__Update2DACache);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
