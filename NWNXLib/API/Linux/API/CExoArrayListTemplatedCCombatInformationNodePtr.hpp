#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CCombatInformationNode;

struct CExoArrayListTemplatedCCombatInformationNodePtr
{
    CCombatInformationNode** element;
    int32_t num;
    int32_t array_size;

    void Add(CCombatInformationNode*);
};

void CExoArrayListTemplatedCCombatInformationNodePtr__Add(CExoArrayListTemplatedCCombatInformationNodePtr* thisPtr, CCombatInformationNode*);

}

}
