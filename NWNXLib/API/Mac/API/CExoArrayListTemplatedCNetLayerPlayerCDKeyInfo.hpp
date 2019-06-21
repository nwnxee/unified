#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNetLayerPlayerCDKeyInfo;

struct CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo
{
    CNetLayerPlayerCDKeyInfo* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
};

void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo* thisPtr, int32_t);

}

}
