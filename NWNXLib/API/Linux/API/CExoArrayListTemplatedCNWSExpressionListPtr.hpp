#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSExpressionList;

struct CExoArrayListTemplatedCNWSExpressionListPtr
{
    CNWSExpressionList** element;
    int32_t num;
    int32_t array_size;

    void Add(CNWSExpressionList*);
};

void CExoArrayListTemplatedCNWSExpressionListPtr__Add(CExoArrayListTemplatedCNWSExpressionListPtr* thisPtr, CNWSExpressionList*);

}

}
