#include "CNWSJournal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSCreature.hpp"

namespace NWNXLib {

namespace API {

CNWSJournal::CNWSJournal()
{
    CNWSJournal__CNWSJournalCtor(this);
}

CNWSJournal::~CNWSJournal()
{
    CNWSJournal__CNWSJournalDtor(this);
}

void CNWSJournal::Destroy(CExoString a0)
{
    return CNWSJournal__Destroy(this, a0);
}

void CNWSJournal::SetDate(CExoString a0, uint32_t a1, int32_t a2)
{
    return CNWSJournal__SetDate(this, a0, a1, a2);
}

void CNWSJournal::SetPicture(CExoString a0, int32_t a1, int32_t a2)
{
    return CNWSJournal__SetPicture(this, a0, a1, a2);
}

void CNWSJournal::SetState(CExoString a0, uint32_t a1, int32_t a2)
{
    return CNWSJournal__SetState(this, a0, a1, a2);
}

void CNWSJournal::SetTime(CExoString a0, uint32_t a1, int32_t a2)
{
    return CNWSJournal__SetTime(this, a0, a1, a2);
}

void CNWSJournal__CNWSJournalCtor(CNWSJournal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__CNWSJournalCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSJournal__CNWSJournalDtor(CNWSJournal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__CNWSJournalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSJournal__Destroy(CNWSJournal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__Destroy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSJournal__SetDate(CNWSJournal* thisPtr, CExoString a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, CExoString, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__SetDate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSJournal__SetPicture(CNWSJournal* thisPtr, CExoString a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, CExoString, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__SetPicture);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSJournal__SetState(CNWSJournal* thisPtr, CExoString a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, CExoString, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__SetState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSJournal__SetTime(CNWSJournal* thisPtr, CExoString a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSJournal*, CExoString, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSJournal__SetTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
