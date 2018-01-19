#include "CExoArrayListTemplatedNWPlayerCharacterListClass_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedNWPlayerCharacterListClass_st::Add(NWPlayerCharacterListClass_st a0)
{
    return CExoArrayListTemplatedNWPlayerCharacterListClass_st__Add(this, a0);
}

void CExoArrayListTemplatedNWPlayerCharacterListClass_st__Add(CExoArrayListTemplatedNWPlayerCharacterListClass_st* thisPtr, NWPlayerCharacterListClass_st a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedNWPlayerCharacterListClass_st*, NWPlayerCharacterListClass_st);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedNWPlayerCharacterListClass_st__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
