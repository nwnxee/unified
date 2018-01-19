#include "CResGFFFieldIDHash.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

uint32_t CResGFFFieldIDHash::Hash(const char* a0, uint32_t a1)
{
    return CResGFFFieldIDHash__Hash(a0, a1);
}

void CResGFFFieldIDHash::Initialize()
{
    return CResGFFFieldIDHash__Initialize();
}

uint32_t CResGFFFieldIDHash__Hash(const char* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(*)(const char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFFFieldIDHash__Hash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1);
}

void CResGFFFieldIDHash__Initialize()
{
    using FuncPtrType = void(*)();
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFFFieldIDHash__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func();
}

}

}
