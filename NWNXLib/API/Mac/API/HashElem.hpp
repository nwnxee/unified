#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct HashElem
{
    HashElem* next;
    HashElem* prev;
    void* data;
    const char* pKey;
};

}

}
