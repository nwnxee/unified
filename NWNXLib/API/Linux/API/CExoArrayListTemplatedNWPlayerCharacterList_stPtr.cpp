#include "CExoArrayListTemplatedNWPlayerCharacterList_stPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "NWPlayerCharacterList_st.hpp"

namespace NWNXLib {

namespace API {

int32_t CExoArrayListTemplatedNWPlayerCharacterList_stPtr::AddUnique(NWPlayerCharacterList_st* a0)
{
    return CExoArrayListTemplatedNWPlayerCharacterList_stPtr__AddUnique(this, a0);
}

int32_t CExoArrayListTemplatedNWPlayerCharacterList_stPtr__AddUnique(CExoArrayListTemplatedNWPlayerCharacterList_stPtr* thisPtr, NWPlayerCharacterList_st* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoArrayListTemplatedNWPlayerCharacterList_stPtr*, NWPlayerCharacterList_st*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedNWPlayerCharacterList_stPtr__AddUnique);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
