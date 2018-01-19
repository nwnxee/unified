#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CSpell_Add;

struct CExoArrayListTemplatedCSpell_AddPtr
{
    CSpell_Add** element;
    int32_t num;
    int32_t array_size;

    void Add(CSpell_Add*);
};

void CExoArrayListTemplatedCSpell_AddPtr__Add(CExoArrayListTemplatedCSpell_AddPtr* thisPtr, CSpell_Add*);

}

}
