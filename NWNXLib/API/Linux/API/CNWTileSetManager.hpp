#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWTilePathNode;
struct CNWTileSet;

struct CNWTileSetManager
{
    CNWTileSet* m_apTileSets[100];
    int32_t m_anTileSetRegistered[100];
    CNWTilePathNode* m_apTileNodes[50][4];

    // The below are auto generated stubs.
    CNWTileSetManager(const CNWTileSetManager&) = default;
    CNWTileSetManager& operator=(const CNWTileSetManager&) = default;

    CNWTileSetManager();
    ~CNWTileSetManager();
    void ClearTilePathNodes();
    void ComputePathNodeInformation(unsigned char, int32_t, int32_t&, int32_t&, float**, float**, int32_t**);
    void ComputePathNodeRotation(int32_t, float*, float*);
    CNWTilePathNode* GetTilePathNode(unsigned char, unsigned char);
    void InitializeTilePathNodes();
    CNWTileSet* RegisterTileSet(CResRef);
    void UnregisterTileSet(CNWTileSet*);
};

void CNWTileSetManager__CNWTileSetManagerCtor(CNWTileSetManager* thisPtr);
void CNWTileSetManager__CNWTileSetManagerDtor(CNWTileSetManager* thisPtr);
void CNWTileSetManager__ClearTilePathNodes(CNWTileSetManager* thisPtr);
void CNWTileSetManager__ComputePathNodeInformation(CNWTileSetManager* thisPtr, unsigned char, int32_t, int32_t&, int32_t&, float**, float**, int32_t**);
void CNWTileSetManager__ComputePathNodeRotation(CNWTileSetManager* thisPtr, int32_t, float*, float*);
CNWTilePathNode* CNWTileSetManager__GetTilePathNode(CNWTileSetManager* thisPtr, unsigned char, unsigned char);
void CNWTileSetManager__InitializeTilePathNodes(CNWTileSetManager* thisPtr);
CNWTileSet* CNWTileSetManager__RegisterTileSet(CNWTileSetManager* thisPtr, CResRef);
void CNWTileSetManager__UnregisterTileSet(CNWTileSetManager* thisPtr, CNWTileSet*);

}

}
