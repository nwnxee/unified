#include "CExtendedServerInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNetLayerSessionInfo.hpp"

namespace NWNXLib {

namespace API {

CExtendedServerInfo* CExtendedServerInfo::operator=(CNetLayerSessionInfo& a0)
{
    return CExtendedServerInfo__OperatorAssignment(this, a0);
}

CExtendedServerInfo* CExtendedServerInfo__OperatorAssignment(CExtendedServerInfo* thisPtr, CNetLayerSessionInfo& a0)
{
    using FuncPtrType = CExtendedServerInfo*(__attribute__((cdecl)) *)(CExtendedServerInfo*, CNetLayerSessionInfo&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExtendedServerInfo__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
