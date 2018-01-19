#include "CNetLayerPlayerCDKeyInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

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
