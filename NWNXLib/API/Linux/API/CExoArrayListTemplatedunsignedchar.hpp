#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedunsignedchar
{
    uint8_t* element;
    int32_t num;
    int32_t array_size;

    void Add(unsigned char);
};

void CExoArrayListTemplatedunsignedchar__Add(CExoArrayListTemplatedunsignedchar* thisPtr, unsigned char);

}

}
