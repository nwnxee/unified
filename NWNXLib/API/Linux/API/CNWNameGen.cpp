#include "CNWNameGen.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWNameGen::CNWNameGen()
{
    CNWNameGen__CNWNameGenCtor(this);
}

CNWNameGen::~CNWNameGen()
{
    CNWNameGen__CNWNameGenDtor__0(this);
}

CExoString CNWNameGen::GetRandomName()
{
    return CNWNameGen__GetRandomName__0(this);
}

CExoString CNWNameGen::GetRandomName(uint16_t a0, unsigned char a1)
{
    return CNWNameGen__GetRandomName__1(this, a0, a1);
}

int32_t CNWNameGen::LoadNameTable(CExoString a0)
{
    return CNWNameGen__LoadNameTable(this, a0);
}

void CNWNameGen::UnloadNameTable()
{
    return CNWNameGen__UnloadNameTable(this);
}

void CNWNameGen__CNWNameGenCtor(CNWNameGen* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWNameGen*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__CNWNameGenCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWNameGen__CNWNameGenDtor__0(CNWNameGen* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWNameGen*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__CNWNameGenDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString CNWNameGen__GetRandomName__0(CNWNameGen* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWNameGen*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__GetRandomName__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWNameGen__GetRandomName__1(CNWNameGen* thisPtr, uint16_t a0, unsigned char a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWNameGen*, uint16_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__GetRandomName__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWNameGen__LoadNameTable(CNWNameGen* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWNameGen*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__LoadNameTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWNameGen__UnloadNameTable(CNWNameGen* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWNameGen*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWNameGen__UnloadNameTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
