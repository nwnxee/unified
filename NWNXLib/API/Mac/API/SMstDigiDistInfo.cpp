#include "SMstDigiDistInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "MS_RSAPrivateKey.hpp"

namespace NWNXLib {

namespace API {

SMstDigiDistInfo::SMstDigiDistInfo()
{
    SMstDigiDistInfo__SMstDigiDistInfoCtor(this);
}

SMstDigiDistInfo::~SMstDigiDistInfo()
{
    SMstDigiDistInfo__SMstDigiDistInfoDtor(this);
}

void SMstDigiDistInfo__SMstDigiDistInfoCtor(SMstDigiDistInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(SMstDigiDistInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::SMstDigiDistInfo__SMstDigiDistInfoCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void SMstDigiDistInfo__SMstDigiDistInfoDtor(SMstDigiDistInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(SMstDigiDistInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::SMstDigiDistInfo__SMstDigiDistInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
