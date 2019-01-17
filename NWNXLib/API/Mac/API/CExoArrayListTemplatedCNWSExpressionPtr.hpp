#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSExpression;

struct CExoArrayListTemplatedCNWSExpressionPtr
{
    CNWSExpression** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCNWSExpressionPtr() = default;
    CExoArrayListTemplatedCNWSExpressionPtr(const CExoArrayListTemplatedCNWSExpressionPtr&) = default;
    CExoArrayListTemplatedCNWSExpressionPtr& operator=(const CExoArrayListTemplatedCNWSExpressionPtr&) = default;

    ~CExoArrayListTemplatedCNWSExpressionPtr();
};

void CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrDtor(CExoArrayListTemplatedCNWSExpressionPtr* thisPtr);

}

}
