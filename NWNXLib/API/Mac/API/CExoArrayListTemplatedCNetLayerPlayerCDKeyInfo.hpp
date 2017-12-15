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

    // The below are auto generated stubs.
    CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo();
    CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo(const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo&);
    CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo& operator=(const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo&);

    ~CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo();
    void Allocate(int32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__CExoArrayListTemplatedCNetLayerPlayerCDKeyInfoDtor(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo* thisPtr);
void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo* thisPtr, int32_t);
void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__SetSize(CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo* thisPtr, int32_t);

}

}
