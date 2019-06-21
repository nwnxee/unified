#include "CExtendedServerInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNetLayerSessionInfo.hpp"

namespace NWNXLib {

namespace API {

CExtendedServerInfo::CExtendedServerInfo()
{
    CExtendedServerInfo__CExtendedServerInfoCtor(this);
}

CExtendedServerInfo* CExtendedServerInfo::operator=(CNetLayerSessionInfo& a0)
{
    return CExtendedServerInfo__OperatorAssignment(this, a0);
}

void CExtendedServerInfo__CExtendedServerInfoCtor(CExtendedServerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExtendedServerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExtendedServerInfo__CExtendedServerInfoCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
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
