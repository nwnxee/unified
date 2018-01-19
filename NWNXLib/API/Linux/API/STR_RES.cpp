#include "STR_RES.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

STR_RES::STR_RES()
{
    STR_RES__STR_RESCtor(this);
}

void STR_RES__STR_RESCtor(STR_RES* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(STR_RES*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::STR_RES__STR_RESCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
