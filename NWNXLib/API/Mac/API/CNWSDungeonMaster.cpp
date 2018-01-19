#include "CNWSDungeonMaster.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSDungeonMaster::CNWSDungeonMaster(uint32_t a0)
{
    CNWSDungeonMaster__CNWSDungeonMasterCtor__0(this, a0);
}

CNWSDungeonMaster::~CNWSDungeonMaster()
{
    CNWSDungeonMaster__CNWSDungeonMasterDtor__0(this);
}

CNWSDungeonMaster* CNWSDungeonMaster::AsNWSDungeonMaster()
{
    return CNWSDungeonMaster__AsNWSDungeonMaster(this);
}

void CNWSDungeonMaster::PossessCreature(uint32_t a0, unsigned char a1)
{
    return CNWSDungeonMaster__PossessCreature(this, a0, a1);
}

void CNWSDungeonMaster__CNWSDungeonMasterCtor__0(CNWSDungeonMaster* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDungeonMaster*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDungeonMaster__CNWSDungeonMasterCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSDungeonMaster__CNWSDungeonMasterDtor__0(CNWSDungeonMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDungeonMaster*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDungeonMaster__CNWSDungeonMasterDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CNWSDungeonMaster* CNWSDungeonMaster__AsNWSDungeonMaster(CNWSDungeonMaster* thisPtr)
{
    using FuncPtrType = CNWSDungeonMaster*(__attribute__((cdecl)) *)(CNWSDungeonMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDungeonMaster__AsNWSDungeonMaster);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSDungeonMaster__PossessCreature(CNWSDungeonMaster* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDungeonMaster*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDungeonMaster__PossessCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
