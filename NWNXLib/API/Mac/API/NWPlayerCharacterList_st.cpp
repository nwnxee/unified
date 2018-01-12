#include "NWPlayerCharacterList_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

NWPlayerCharacterList_st::NWPlayerCharacterList_st()
{
    NWPlayerCharacterList_st__NWPlayerCharacterList_stCtor(this);
}

void NWPlayerCharacterList_st__NWPlayerCharacterList_stCtor(NWPlayerCharacterList_st* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(NWPlayerCharacterList_st*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::NWPlayerCharacterList_st__NWPlayerCharacterList_stCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
