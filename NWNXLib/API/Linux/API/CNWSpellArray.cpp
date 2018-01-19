#include "CNWSpellArray.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSpellArray::CNWSpellArray()
{
    CNWSpellArray__CNWSpellArrayCtor(this);
}

CNWSpellArray::~CNWSpellArray()
{
    CNWSpellArray__CNWSpellArrayDtor(this);
}

CNWSpell* CNWSpellArray::GetSpell(int32_t a0)
{
    return CNWSpellArray__GetSpell(this, a0);
}

void CNWSpellArray::Load()
{
    return CNWSpellArray__Load(this);
}

CNWSpell CNWSpellArray::operator*(int32_t a0)
{
    return CNWSpellArray__OperatorMultiplication(this, a0);
}

void CNWSpellArray__CNWSpellArrayCtor(CNWSpellArray* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpellArray*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpellArray__CNWSpellArrayCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSpellArray__CNWSpellArrayDtor(CNWSpellArray* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpellArray*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpellArray__CNWSpellArrayDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CNWSpell* CNWSpellArray__GetSpell(CNWSpellArray* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSpell*(__attribute__((cdecl)) *)(CNWSpellArray*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpellArray__GetSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSpellArray__Load(CNWSpellArray* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpellArray*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpellArray__Load);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSpell CNWSpellArray__OperatorMultiplication(CNWSpellArray* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSpell(__attribute__((cdecl)) *)(CNWSpellArray*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpellArray__OperatorMultiplication);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
