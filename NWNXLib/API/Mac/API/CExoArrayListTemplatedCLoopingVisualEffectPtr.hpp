#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CLoopingVisualEffect;

struct CExoArrayListTemplatedCLoopingVisualEffectPtr
{
    CLoopingVisualEffect** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCLoopingVisualEffectPtr() = default;
    CExoArrayListTemplatedCLoopingVisualEffectPtr(const CExoArrayListTemplatedCLoopingVisualEffectPtr&) = default;
    CExoArrayListTemplatedCLoopingVisualEffectPtr& operator=(const CExoArrayListTemplatedCLoopingVisualEffectPtr&) = default;

    ~CExoArrayListTemplatedCLoopingVisualEffectPtr();
};

void CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrDtor(CExoArrayListTemplatedCLoopingVisualEffectPtr* thisPtr);

}

}
