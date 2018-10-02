#include "CGOGFriendRichPresence.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CGOGFriendRichPresence::CGOGFriendRichPresence()
{
    CGOGFriendRichPresence__CGOGFriendRichPresenceCtor(this);
}

CGOGFriendRichPresence::~CGOGFriendRichPresence()
{
    CGOGFriendRichPresence__CGOGFriendRichPresenceDtor(this);
}

void CGOGFriendRichPresence__CGOGFriendRichPresenceCtor(CGOGFriendRichPresence* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGFriendRichPresence*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGFriendRichPresence__CGOGFriendRichPresenceCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CGOGFriendRichPresence__CGOGFriendRichPresenceDtor(CGOGFriendRichPresence* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGFriendRichPresence*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGFriendRichPresence__CGOGFriendRichPresenceDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
