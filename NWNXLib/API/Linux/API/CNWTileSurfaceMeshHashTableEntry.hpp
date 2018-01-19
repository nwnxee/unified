#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWTileSurfaceMeshHashTableEntry
{
    int32_t m_nBestTriangle;
    int32_t m_nRecentTriangle;
    float m_fBestAttemptedDepth;
    float m_fRecentAttemptedDepth;

    // The below are auto generated stubs.
    CNWTileSurfaceMeshHashTableEntry(const CNWTileSurfaceMeshHashTableEntry&) = default;
    CNWTileSurfaceMeshHashTableEntry& operator=(const CNWTileSurfaceMeshHashTableEntry&) = default;

    CNWTileSurfaceMeshHashTableEntry();
    float Fetch(int32_t);
    void Store(int32_t, float);
};

void CNWTileSurfaceMeshHashTableEntry__CNWTileSurfaceMeshHashTableEntryCtor(CNWTileSurfaceMeshHashTableEntry* thisPtr);
float CNWTileSurfaceMeshHashTableEntry__Fetch(CNWTileSurfaceMeshHashTableEntry* thisPtr, int32_t);
void CNWTileSurfaceMeshHashTableEntry__Store(CNWTileSurfaceMeshHashTableEntry* thisPtr, int32_t, float);

}

}
