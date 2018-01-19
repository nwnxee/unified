#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameObject;

struct CExoArrayListTemplatedCGameObjectPtr
{
    CGameObject** element;
    int32_t num;
    int32_t array_size;

    void Add(CGameObject*);
};

void CExoArrayListTemplatedCGameObjectPtr__Add(CExoArrayListTemplatedCGameObjectPtr* thisPtr, CGameObject*);

}

}
