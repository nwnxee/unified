#include "CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNetLayerPlayerCDKeyInfo.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate(this, a0);
}

void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
