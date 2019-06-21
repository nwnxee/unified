#include "galaxy__api.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

galaxyapiIApps* galaxy__api::Apps()
{
    return galaxy__api__Apps(this);
}

galaxyapiIFriends* galaxy__api::Friends()
{
    return galaxy__api__Friends(this);
}

const galaxyapiIError* galaxy__api::GetError()
{
    return galaxy__api__GetError(this);
}

galaxyapiIListenerRegistrar* galaxy__api::ListenerRegistrar()
{
    return galaxy__api__ListenerRegistrar(this);
}

void galaxy__api::ProcessData()
{
    return galaxy__api__ProcessData(this);
}

void galaxy__api::Shutdown()
{
    return galaxy__api__Shutdown(this);
}

galaxyapiIStats* galaxy__api::Stats()
{
    return galaxy__api__Stats(this);
}

galaxyapiIUser* galaxy__api::User()
{
    return galaxy__api__User(this);
}

galaxyapiIApps* galaxy__api__Apps(galaxy__api* thisPtr)
{
    using FuncPtrType = galaxyapiIApps*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__Apps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIFriends* galaxy__api__Friends(galaxy__api* thisPtr)
{
    using FuncPtrType = galaxyapiIFriends*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__Friends);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

const galaxyapiIError* galaxy__api__GetError(galaxy__api* thisPtr)
{
    using FuncPtrType = const galaxyapiIError*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__GetError);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIListenerRegistrar* galaxy__api__ListenerRegistrar(galaxy__api* thisPtr)
{
    using FuncPtrType = galaxyapiIListenerRegistrar*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__ListenerRegistrar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void galaxy__api__ProcessData(galaxy__api* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__ProcessData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void galaxy__api__Shutdown(galaxy__api* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__Shutdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIStats* galaxy__api__Stats(galaxy__api* thisPtr)
{
    using FuncPtrType = galaxyapiIStats*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__Stats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

galaxyapiIUser* galaxy__api__User(galaxy__api* thisPtr)
{
    using FuncPtrType = galaxyapiIUser*(__attribute__((cdecl)) *)(galaxy__api*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::galaxy__api__User);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
