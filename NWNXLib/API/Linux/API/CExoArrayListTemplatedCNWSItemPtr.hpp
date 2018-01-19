#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSItem;

struct CExoArrayListTemplatedCNWSItemPtr
{
    CNWSItem** element;
    int32_t num;
    int32_t array_size;

    void Add(CNWSItem*);
};

void CExoArrayListTemplatedCNWSItemPtr__Add(CExoArrayListTemplatedCNWSItemPtr* thisPtr, CNWSItem*);

}

}
