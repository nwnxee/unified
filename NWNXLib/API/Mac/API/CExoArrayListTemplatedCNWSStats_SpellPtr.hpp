#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSStats_Spell;

struct CExoArrayListTemplatedCNWSStats_SpellPtr
{
    CNWSStats_Spell** element;
    int32_t num;
    int32_t array_size;
};

}

}
