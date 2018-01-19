#pragma once

#include <cstdint>

#include "CNWItemProperty.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCNWItemProperty
{
    CNWItemProperty* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCNWItemProperty() = default;
    CExoArrayListTemplatedCNWItemProperty(const CExoArrayListTemplatedCNWItemProperty&) = default;

    ~CExoArrayListTemplatedCNWItemProperty();
    void Add(CNWItemProperty);
    void Allocate(int32_t);
    CExoArrayListTemplatedCNWItemProperty& operator=(const CExoArrayListTemplatedCNWItemProperty&);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedCNWItemProperty__CExoArrayListTemplatedCNWItemPropertyDtor(CExoArrayListTemplatedCNWItemProperty* thisPtr);
void CExoArrayListTemplatedCNWItemProperty__Add(CExoArrayListTemplatedCNWItemProperty* thisPtr, CNWItemProperty);
void CExoArrayListTemplatedCNWItemProperty__Allocate(CExoArrayListTemplatedCNWItemProperty* thisPtr, int32_t);
CExoArrayListTemplatedCNWItemProperty& CExoArrayListTemplatedCNWItemProperty__OperatorAssignment(CExoArrayListTemplatedCNWItemProperty* thisPtr, const CExoArrayListTemplatedCNWItemProperty&);
void CExoArrayListTemplatedCNWItemProperty__SetSize(CExoArrayListTemplatedCNWItemProperty* thisPtr, int32_t);

}

}
