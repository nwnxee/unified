#include "CFriendPresenceInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CFriendPresenceInfo::CFriendPresenceInfo()
{
    CFriendPresenceInfo__CFriendPresenceInfoCtor(this);
}

CFriendPresenceInfo::~CFriendPresenceInfo()
{
    CFriendPresenceInfo__CFriendPresenceInfoDtor(this);
}

void CFriendPresenceInfo::Decode(CExoString a0)
{
    return CFriendPresenceInfo__Decode(this, a0);
}

CExoString CFriendPresenceInfo::Encode(CExtendedServerInfo* a0)
{
    return CFriendPresenceInfo__Encode(a0);
}

void CFriendPresenceInfo__CFriendPresenceInfoCtor(CFriendPresenceInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFriendPresenceInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFriendPresenceInfo__CFriendPresenceInfoCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CFriendPresenceInfo__CFriendPresenceInfoDtor(CFriendPresenceInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFriendPresenceInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFriendPresenceInfo__CFriendPresenceInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CFriendPresenceInfo__Decode(CFriendPresenceInfo* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFriendPresenceInfo*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFriendPresenceInfo__Decode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CFriendPresenceInfo__Encode(CExtendedServerInfo* a0)
{
    using FuncPtrType = CExoString(*)(CExtendedServerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFriendPresenceInfo__Encode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0);
}

}

}
