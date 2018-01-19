#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSStats_SpellLikeAbility;

struct CExoArrayListTemplatedCNWSStats_SpellLikeAbility
{
    CNWSStats_SpellLikeAbility* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Allocate(CExoArrayListTemplatedCNWSStats_SpellLikeAbility* thisPtr, int32_t);

}

}
