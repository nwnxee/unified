#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWItemProperty;

struct CExoArrayListTemplatedCNWItemProperty
{
    CNWItemProperty* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCNWItemProperty() = default;
    CExoArrayListTemplatedCNWItemProperty(const CExoArrayListTemplatedCNWItemProperty&) = default;

    ~CExoArrayListTemplatedCNWItemProperty();
    void Allocate(int32_t);
    CExoArrayListTemplatedCNWItemProperty& operator=(const CExoArrayListTemplatedCNWItemProperty&);
};

void CExoArrayListTemplatedCNWItemProperty__CExoArrayListTemplatedCNWItemPropertyDtor(CExoArrayListTemplatedCNWItemProperty* thisPtr);
void CExoArrayListTemplatedCNWItemProperty__Allocate(CExoArrayListTemplatedCNWItemProperty* thisPtr, int32_t);
CExoArrayListTemplatedCNWItemProperty& CExoArrayListTemplatedCNWItemProperty__OperatorAssignment(CExoArrayListTemplatedCNWItemProperty* thisPtr, const CExoArrayListTemplatedCNWItemProperty&);

}

}
