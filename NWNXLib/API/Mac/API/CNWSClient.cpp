#include "CNWSClient.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSDungeonMaster.hpp"
#include "CNWSPlayer.hpp"

namespace NWNXLib {

namespace API {

CNWSClient::CNWSClient(uint32_t a0)
{
    CNWSClient__CNWSClientCtor__0(this, a0);
}

CNWSClient::~CNWSClient()
{
    CNWSClient__CNWSClientDtor__0(this);
}

CNWSDungeonMaster* CNWSClient::AsNWSDungeonMaster()
{
    return CNWSClient__AsNWSDungeonMaster(this);
}

CNWSPlayer* CNWSClient::AsNWSPlayer()
{
    return CNWSClient__AsNWSPlayer(this);
}

void CNWSClient__CNWSClientCtor__0(CNWSClient* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSClient*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSClient__CNWSClientCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSClient__CNWSClientDtor__0(CNWSClient* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSClient*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSClient__CNWSClientDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CNWSDungeonMaster* CNWSClient__AsNWSDungeonMaster(CNWSClient* thisPtr)
{
    using FuncPtrType = CNWSDungeonMaster*(__attribute__((cdecl)) *)(CNWSClient*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSClient__AsNWSDungeonMaster);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlayer* CNWSClient__AsNWSPlayer(CNWSClient* thisPtr)
{
    using FuncPtrType = CNWSPlayer*(__attribute__((cdecl)) *)(CNWSClient*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSClient__AsNWSPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
