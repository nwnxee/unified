#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct NWPlayerCharacterList_st;

struct CExoArrayListTemplatedNWPlayerCharacterList_stPtr
{
    NWPlayerCharacterList_st** element;
    int32_t num;
    int32_t array_size;

    int32_t AddUnique(NWPlayerCharacterList_st*);
};

int32_t CExoArrayListTemplatedNWPlayerCharacterList_stPtr__AddUnique(CExoArrayListTemplatedNWPlayerCharacterList_stPtr* thisPtr, NWPlayerCharacterList_st*);

}

}
