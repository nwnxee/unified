#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameEffect;

struct CExoArrayListTemplatedCGameEffectPtr
{
    CGameEffect** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCGameEffectPtr() = default;
    CExoArrayListTemplatedCGameEffectPtr(const CExoArrayListTemplatedCGameEffectPtr&) = default;
    CExoArrayListTemplatedCGameEffectPtr& operator=(const CExoArrayListTemplatedCGameEffectPtr&) = default;

    ~CExoArrayListTemplatedCGameEffectPtr();
};

void CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrDtor(CExoArrayListTemplatedCGameEffectPtr* thisPtr);

}

}
