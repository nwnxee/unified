#include "CExoArrayListTemplatedCNWSInvitationDetails.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSInvitationDetails::Add(CNWSInvitationDetails a0)
{
    return CExoArrayListTemplatedCNWSInvitationDetails__Add(this, a0);
}

void CExoArrayListTemplatedCNWSInvitationDetails__Add(CExoArrayListTemplatedCNWSInvitationDetails* thisPtr, CNWSInvitationDetails a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSInvitationDetails*, CNWSInvitationDetails);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSInvitationDetails__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
