#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSFaction;

struct CExoArrayListTemplatedCNWSFactionPtr
{
    CNWSFaction** element;
    int32_t num;
    int32_t array_size;

    void Add(CNWSFaction*);
};

void CExoArrayListTemplatedCNWSFactionPtr__Add(CExoArrayListTemplatedCNWSFactionPtr* thisPtr, CNWSFaction*);

}

}
