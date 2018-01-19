#include "CExoEncrypt.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoString CExoEncrypt::EncryptString(const CExoString& a0)
{
    return CExoEncrypt__EncryptString(this, a0);
}

CExoString CExoEncrypt::GenerateChallenge(uint16_t a0)
{
    return CExoEncrypt__GenerateChallenge(this, a0);
}

CExoString CExoEncrypt__EncryptString(CExoEncrypt* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoEncrypt*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncrypt__EncryptString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CExoEncrypt__GenerateChallenge(CExoEncrypt* thisPtr, uint16_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoEncrypt*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncrypt__GenerateChallenge);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
