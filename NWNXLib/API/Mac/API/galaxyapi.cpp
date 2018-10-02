#include "galaxyapi.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

galaxyapiIApps* galaxyapi::Apps()
{
    return galaxyapi__Apps(this);
}

galaxyapiIFriends* galaxyapi::Friends()
{
    return galaxyapi__Friends(this);
}

const galaxyapiIError* galaxyapi::GetError()
{
    return galaxyapi__GetError(this);
}

galaxyapiIListenerRegistrar* galaxyapi::ListenerRegistrar()
{
    return galaxyapi__ListenerRegistrar(this);
}

void galaxyapi::ProcessData()
{
    return galaxyapi__ProcessData(this);
}

void galaxyapi::Shutdown()
{
    return galaxyapi__Shutdown(this);
}

galaxyapiIUser* galaxyapi::User()
{
    return galaxyapi__User(this);
}

galaxyapiIApps* galaxyapi__Apps(galaxyapi* thisPtr)
{
    using FuncPtrType = galaxyapiIApps*(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__Apps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIFriends* galaxyapi__Friends(galaxyapi* thisPtr)
{
    using FuncPtrType = galaxyapiIFriends*(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__Friends);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

const galaxyapiIError* galaxyapi__GetError(galaxyapi* thisPtr)
{
    using FuncPtrType = const galaxyapiIError*(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__GetError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIListenerRegistrar* galaxyapi__ListenerRegistrar(galaxyapi* thisPtr)
{
    using FuncPtrType = galaxyapiIListenerRegistrar*(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__ListenerRegistrar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void galaxyapi__ProcessData(galaxyapi* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__ProcessData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void galaxyapi__Shutdown(galaxyapi* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__Shutdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIUser* galaxyapi__User(galaxyapi* thisPtr)
{
    using FuncPtrType = galaxyapiIUser*(__attribute__((cdecl)) *)(galaxyapi*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxyapi__User);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
