#include "CNWTileSet.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWTileData.hpp"

namespace NWNXLib {

namespace API {

CNWTileSet::CNWTileSet(CResRef a0, int32_t a1)
{
    CNWTileSet__CNWTileSetCtor__0(this, a0, a1);
}

CNWTileSet::~CNWTileSet()
{
    CNWTileSet__CNWTileSetDtor__0(this);
}

CExoString CNWTileSet::GetCornerType(int32_t a0, unsigned char a1, unsigned char a2)
{
    return CNWTileSet__GetCornerType(this, a0, a1, a2);
}

CExoString CNWTileSet::GetEdgeType(int32_t a0, unsigned char a1, unsigned char a2)
{
    return CNWTileSet__GetEdgeType(this, a0, a1, a2);
}

CResRef CNWTileSet::GetEnvMapResRef()
{
    return CNWTileSet__GetEnvMapResRef(this);
}

float CNWTileSet::GetHeightTransition()
{
    return CNWTileSet__GetHeightTransition(this);
}

CNWTileData* CNWTileSet::GetTileData(int32_t a0)
{
    return CNWTileSet__GetTileData(this, a0);
}

int32_t CNWTileSet::LoadTileSet()
{
    return CNWTileSet__LoadTileSet(this);
}

int32_t CNWTileSet::ParseLine(char* a0)
{
    return CNWTileSet__ParseLine(this, a0);
}

int32_t CNWTileSet::SetTileValue(char* a0, char* a1)
{
    return CNWTileSet__SetTileValue(this, a0, a1);
}

void CNWTileSet::UnloadTileSet()
{
    return CNWTileSet__UnloadTileSet(this);
}

void CNWTileSet__CNWTileSetCtor__0(CNWTileSet* thisPtr, CResRef a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSet*, CResRef, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__CNWTileSetCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CNWTileSet__CNWTileSetDtor__0(CNWTileSet* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSet*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__CNWTileSetDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString CNWTileSet__GetCornerType(CNWTileSet* thisPtr, int32_t a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWTileSet*, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__GetCornerType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CNWTileSet__GetEdgeType(CNWTileSet* thisPtr, int32_t a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWTileSet*, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__GetEdgeType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResRef CNWTileSet__GetEnvMapResRef(CNWTileSet* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWTileSet*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__GetEnvMapResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWTileSet__GetHeightTransition(CNWTileSet* thisPtr)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWTileSet*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__GetHeightTransition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWTileData* CNWTileSet__GetTileData(CNWTileSet* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWTileData*(__attribute__((cdecl)) *)(CNWTileSet*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__GetTileData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWTileSet__LoadTileSet(CNWTileSet* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSet*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__LoadTileSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWTileSet__ParseLine(CNWTileSet* thisPtr, char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSet*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__ParseLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWTileSet__SetTileValue(CNWTileSet* thisPtr, char* a0, char* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWTileSet*, char*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__SetTileValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTileSet__UnloadTileSet(CNWTileSet* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSet*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSet__UnloadTileSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
