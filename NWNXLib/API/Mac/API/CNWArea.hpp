#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCGameObjectPtr;
struct CPathfindInformation;

struct CNWArea
{
    void** m_vtable;
    uint32_t m_nFlags;
    int32_t m_nWidth;
    int32_t m_nHeight;
    int32_t m_nStaticObjects;
    int32_t m_nStaticObjectsFilled;
    uint32_t* m_poidStaticObjectsObjectIds;
    int32_t* m_pnStaticObjectsTriangleStart;
    int32_t* m_pnStaticObjectsTriangleCount;
    int32_t* m_pnStaticObjectsVertexStart;
    int32_t* m_pnStaticObjectsVertexCount;
    int32_t m_nStaticObjectTriangleArraySize;
    int32_t m_nStaticObjectTriangles;
    int32_t* m_pnStaticObjectTriangles;
    int32_t m_nStaticObjectVertexArraySize;
    int32_t m_nStaticObjectVertices;
    Vector* m_pvStaticObjectVertices;
    int32_t m_nStaticBoundingBoxes;
    int32_t m_nStaticBoundingBoxesFilled;
    Vector* m_pvStaticBoundingBoxes;
    uint32_t* m_poidStaticBBObjectIds;
    Vector m_vFogColor;
    uint8_t m_nFogValue;
    uint32_t m_nMoonAmbientColor;
    uint32_t m_nMoonDiffuseColor;
    uint32_t m_nMoonFogColor;
    uint8_t m_nMoonFogAmount;
    int32_t m_bMoonShadows;
    uint32_t m_nSunAmbientColor;
    uint32_t m_nSunDiffuseColor;
    uint32_t m_nSunFogColor;
    uint8_t m_nSunFogAmount;
    int32_t m_bSunShadows;
    int32_t m_bUseDayNightCycle;
    int32_t m_bIsNight;
    uint8_t m_nSkyBox;
    uint8_t m_nChanceOfRain;
    uint8_t m_nChanceOfSnow;
    uint8_t m_nChanceOfLightning;
    uint8_t m_nWindAmount;
    int32_t m_bNoRestingAllowed;
    uint8_t m_nShadowOpacity;
    float m_fFogClipDistance;

    // The below are auto generated stubs.
    CNWArea(const CNWArea&) = default;
    CNWArea& operator=(const CNWArea&) = default;

    CNWArea();
    ~CNWArea();
    int32_t AddStaticBoundingBox(uint32_t, const Vector&, const Vector&);
    int32_t AddStaticObject(uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
    void GetFog(int32_t*, Vector*);
    int32_t GetIsIDInExcludeList(uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
    int32_t GetIsNight();
    void GrowStaticObjectArray();
    void GrowStaticObjectTriangles(int32_t);
    void GrowStaticObjectVertices(int32_t);
    int32_t HandleTransparentDoors(float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    void InitializeStaticObjects();
    int32_t IntersectLineSegments(float, float, float, float, float, float, float, float, float*, float*);
    int32_t NoCreaturesOnLine(float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
    int32_t NoNonWalkPolys(float, float, float, float, float, float, float, uint32_t);
    int32_t NoNonWalkPolysDetailed(float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    int32_t NoNonWalkPolysInDoors(float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    int32_t RemoveStaticBoundingBox(uint32_t);
    void RemoveStaticObject(int32_t);
    void ReplaceStaticObject(int32_t, uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
    int32_t SetFog(int32_t, Vector);
    int32_t SetIsNight(int32_t);
    int32_t SetWind(unsigned char);
};

void CNWArea__CNWAreaCtor(CNWArea* thisPtr);
void CNWArea__CNWAreaDtor__0(CNWArea* thisPtr);
int32_t CNWArea__AddStaticBoundingBox(CNWArea* thisPtr, uint32_t, const Vector&, const Vector&);
int32_t CNWArea__AddStaticObject(CNWArea* thisPtr, uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
void CNWArea__GetFog(CNWArea* thisPtr, int32_t*, Vector*);
int32_t CNWArea__GetIsIDInExcludeList(CNWArea* thisPtr, uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
int32_t CNWArea__GetIsNight(CNWArea* thisPtr);
void CNWArea__GrowStaticObjectArray(CNWArea* thisPtr);
void CNWArea__GrowStaticObjectTriangles(CNWArea* thisPtr, int32_t);
void CNWArea__GrowStaticObjectVertices(CNWArea* thisPtr, int32_t);
int32_t CNWArea__HandleTransparentDoors(CNWArea* thisPtr, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
void CNWArea__InitializeStaticObjects(CNWArea* thisPtr);
int32_t CNWArea__IntersectLineSegments(CNWArea* thisPtr, float, float, float, float, float, float, float, float, float*, float*);
int32_t CNWArea__NoCreaturesOnLine(CNWArea* thisPtr, float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
int32_t CNWArea__NoNonWalkPolys(CNWArea* thisPtr, float, float, float, float, float, float, float, uint32_t);
int32_t CNWArea__NoNonWalkPolysDetailed(CNWArea* thisPtr, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
int32_t CNWArea__NoNonWalkPolysInDoors(CNWArea* thisPtr, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
int32_t CNWArea__RemoveStaticBoundingBox(CNWArea* thisPtr, uint32_t);
void CNWArea__RemoveStaticObject(CNWArea* thisPtr, int32_t);
void CNWArea__ReplaceStaticObject(CNWArea* thisPtr, int32_t, uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
int32_t CNWArea__SetFog(CNWArea* thisPtr, int32_t, Vector);
int32_t CNWArea__SetIsNight(CNWArea* thisPtr, int32_t);
int32_t CNWArea__SetWind(CNWArea* thisPtr, unsigned char);

}

}
