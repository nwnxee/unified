#include "CNWSpell.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSpell::CNWSpell()
{
    CNWSpell__CNWSpellCtor(this);
}

CNWSpell::~CNWSpell()
{
    CNWSpell__CNWSpellDtor(this);
}

int32_t CNWSpell::GetSpellHasSomaticComponent()
{
    return CNWSpell__GetSpellHasSomaticComponent(this);
}

int32_t CNWSpell::GetSpellHasVerbalComponent()
{
    return CNWSpell__GetSpellHasVerbalComponent(this);
}

unsigned char CNWSpell::GetSpellLevel(unsigned char a0)
{
    return CNWSpell__GetSpellLevel(this, a0);
}

CExoString CNWSpell::GetSpellNameText()
{
    return CNWSpell__GetSpellNameText(this);
}

uint32_t CNWSpell::GetSubRadialSpell(unsigned char a0)
{
    return CNWSpell__GetSubRadialSpell(this, a0);
}

void CNWSpell::SetSubRadialSpell(unsigned char a0, uint32_t a1)
{
    return CNWSpell__SetSubRadialSpell(this, a0, a1);
}

void CNWSpell::SetSubRadialSpellCount(unsigned char a0)
{
    return CNWSpell__SetSubRadialSpellCount(this, a0);
}

void CNWSpell__CNWSpellCtor(CNWSpell* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpell*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__CNWSpellCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSpell__CNWSpellDtor(CNWSpell* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpell*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__CNWSpellDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSpell__GetSpellHasSomaticComponent(CNWSpell* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSpell*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__GetSpellHasSomaticComponent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSpell__GetSpellHasVerbalComponent(CNWSpell* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSpell*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__GetSpellHasVerbalComponent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSpell__GetSpellLevel(CNWSpell* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSpell*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__GetSpellLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSpell__GetSpellNameText(CNWSpell* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSpell*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__GetSpellNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSpell__GetSubRadialSpell(CNWSpell* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSpell*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__GetSubRadialSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSpell__SetSubRadialSpell(CNWSpell* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpell*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__SetSubRadialSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSpell__SetSubRadialSpellCount(CNWSpell* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSpell*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSpell__SetSubRadialSpellCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
