#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResHelperTemplatedCResSET2013u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWTileData;

struct CNWTileSet
    : CResHelperTemplatedCResSET2013u
{
    CResRef m_resrefName;
    CResRef m_cEnvMap;
    float m_fHeightTransition;
    int32_t m_nProperty;
    int32_t m_nNumTileData;
    int32_t m_nCurrentTileData;
    CNWTileData* m_pTileData;
    int32_t m_bHasGrass;
    float m_fGrassDensity;
    float m_fGrassHeight;
    Vector m_vGrassAmbientColor;
    Vector m_vGrassDiffuseColor;
    CExoString m_sGrassTexture;

    // The below are auto generated stubs.
    CNWTileSet() = default;
    CNWTileSet(const CNWTileSet&) = default;
    CNWTileSet& operator=(const CNWTileSet&) = default;

    CNWTileSet(CResRef, int32_t);
    ~CNWTileSet();
    CExoString GetCornerType(int32_t, unsigned char, unsigned char);
    CExoString GetEdgeType(int32_t, unsigned char, unsigned char);
    CResRef GetEnvMapResRef();
    float GetHeightTransition();
    CNWTileData* GetTileData(int32_t);
    int32_t LoadTileSet();
    int32_t ParseLine(char*);
    int32_t SetTileValue(char*, char*);
    void UnloadTileSet();
};

void CNWTileSet__CNWTileSetCtor__0(CNWTileSet* thisPtr, CResRef, int32_t);
void CNWTileSet__CNWTileSetDtor__0(CNWTileSet* thisPtr);
CExoString CNWTileSet__GetCornerType(CNWTileSet* thisPtr, int32_t, unsigned char, unsigned char);
CExoString CNWTileSet__GetEdgeType(CNWTileSet* thisPtr, int32_t, unsigned char, unsigned char);
CResRef CNWTileSet__GetEnvMapResRef(CNWTileSet* thisPtr);
float CNWTileSet__GetHeightTransition(CNWTileSet* thisPtr);
CNWTileData* CNWTileSet__GetTileData(CNWTileSet* thisPtr, int32_t);
int32_t CNWTileSet__LoadTileSet(CNWTileSet* thisPtr);
int32_t CNWTileSet__ParseLine(CNWTileSet* thisPtr, char*);
int32_t CNWTileSet__SetTileValue(CNWTileSet* thisPtr, char*, char*);
void CNWTileSet__UnloadTileSet(CNWTileSet* thisPtr);

}

}
