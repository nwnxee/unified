#include "CNWSBarter.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CItemRepository.hpp"
#include "CNWSCreature.hpp"
#include "CNWSPlayerLUOInventory.hpp"

namespace NWNXLib {

namespace API {

CNWSBarter::CNWSBarter(CNWSCreature* a0)
{
    CNWSBarter__CNWSBarterCtor__0(this, a0);
}

CNWSBarter::~CNWSBarter()
{
    CNWSBarter__CNWSBarterDtor__0(this);
}

int32_t CNWSBarter::AddItem(uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    return CNWSBarter__AddItem(this, a0, a1, a2);
}

void CNWSBarter::CleanUp()
{
    return CNWSBarter__CleanUp(this);
}

unsigned char CNWSBarter::GetState()
{
    return CNWSBarter__GetState(this);
}

int32_t CNWSBarter::MoveItem(uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    return CNWSBarter__MoveItem(this, a0, a1, a2);
}

int32_t CNWSBarter::PullItemOut(uint32_t a0)
{
    return CNWSBarter__PullItemOut(this, a0);
}

int32_t CNWSBarter::RemoveItem(uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    return CNWSBarter__RemoveItem(this, a0, a1, a2);
}

void CNWSBarter::Reset(uint32_t a0, int32_t a1)
{
    return CNWSBarter__Reset(this, a0, a1);
}

int32_t CNWSBarter::SetListAccepted(int32_t a0)
{
    return CNWSBarter__SetListAccepted(this, a0);
}

int32_t CNWSBarter::SetListLocked(int32_t a0)
{
    return CNWSBarter__SetListLocked(this, a0);
}

void CNWSBarter__CNWSBarterCtor__0(CNWSBarter* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSBarter*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__CNWSBarterCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSBarter__CNWSBarterDtor__0(CNWSBarter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSBarter*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__CNWSBarterDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSBarter__AddItem(CNWSBarter* thisPtr, uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, uint32_t, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__AddItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSBarter__CleanUp(CNWSBarter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSBarter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__CleanUp);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSBarter__GetState(CNWSBarter* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSBarter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__GetState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSBarter__MoveItem(CNWSBarter* thisPtr, uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, uint32_t, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__MoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSBarter__PullItemOut(CNWSBarter* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__PullItemOut);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSBarter__RemoveItem(CNWSBarter* thisPtr, uint32_t a0, unsigned char& a1, unsigned char& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, uint32_t, unsigned char&, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSBarter__Reset(CNWSBarter* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSBarter*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__Reset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSBarter__SetListAccepted(CNWSBarter* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__SetListAccepted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSBarter__SetListLocked(CNWSBarter* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSBarter*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSBarter__SetListLocked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
