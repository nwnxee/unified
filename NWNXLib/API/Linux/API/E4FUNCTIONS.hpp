#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct E4FUNCTIONS
{
    void** m_funcPtrPlaceholder__0;
    char* name;
    int16_t code;
    uint8_t nameLen;
    char priority;
    char returnType;
    char numParms;
    char type[3];
};

}

}
