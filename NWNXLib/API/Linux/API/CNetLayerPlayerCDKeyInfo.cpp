#include "CNetLayerPlayerCDKeyInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNetLayerPlayerCDKeyInfo::CNetLayerPlayerCDKeyInfo()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CNetLayerPlayerCDKeyInfo::CNetLayerPlayerCDKeyInfo(const CNetLayerPlayerCDKeyInfo&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CNetLayerPlayerCDKeyInfo& CNetLayerPlayerCDKeyInfo::operator=(const CNetLayerPlayerCDKeyInfo&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CNetLayerPlayerCDKeyInfo::~CNetLayerPlayerCDKeyInfo()
{
    CNetLayerPlayerCDKeyInfo__CNetLayerPlayerCDKeyInfoDtor(this);
}

void CNetLayerPlayerCDKeyInfo__CNetLayerPlayerCDKeyInfoDtor(CNetLayerPlayerCDKeyInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerCDKeyInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerCDKeyInfo__CNetLayerPlayerCDKeyInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
