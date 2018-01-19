#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedchar
{
    char* element;
    int32_t num;
    int32_t array_size;

    void Add(char);
};

void CExoArrayListTemplatedchar__Add(CExoArrayListTemplatedchar* thisPtr, char);

}

}
