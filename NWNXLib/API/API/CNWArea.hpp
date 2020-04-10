#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWArea)
#endif

struct CGameObject;
struct CPathfindInformation;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWArea
{
    uint32_t m_nFlags;
    int32_t m_nWidth;
    int32_t m_nHeight;
    int32_t m_nStaticObjects;
    int32_t m_nStaticObjectsFilled;
    OBJECT_ID * m_poidStaticObjectsObjectIds;
    int32_t * m_pnStaticObjectsTriangleStart;
    int32_t * m_pnStaticObjectsTriangleCount;
    int32_t * m_pnStaticObjectsVertexStart;
    int32_t * m_pnStaticObjectsVertexCount;
    int32_t m_nStaticObjectTriangleArraySize;
    int32_t m_nStaticObjectTriangles;
    int32_t * m_pnStaticObjectTriangles;
    int32_t m_nStaticObjectVertexArraySize;
    int32_t m_nStaticObjectVertices;
    Vector * m_pvStaticObjectVertices;
    Vector * m_pvStaticObjectBoundingBoxes;
    int32_t m_nStaticBoundingBoxes;
    int32_t m_nStaticBoundingBoxesFilled;
    Vector * m_pvStaticBoundingBoxes;
    OBJECT_ID * m_poidStaticBBObjectIds;
    Vector m_vFogColor;
    uint8_t m_nFogValue;
    uint32_t m_nMoonAmbientColor;
    uint32_t m_nMoonDiffuseColor;
    uint32_t m_nMoonFogColor;
    uint8_t m_nMoonFogAmount;
    BOOL m_bMoonShadows;
    uint32_t m_nSunAmbientColor;
    uint32_t m_nSunDiffuseColor;
    uint32_t m_nSunFogColor;
    uint8_t m_nSunFogAmount;
    BOOL m_bSunShadows;
    BOOL m_bUseDayNightCycle;
    BOOL m_bIsNight;
    uint8_t m_nSkyBox;
    uint8_t m_nChanceOfRain;
    uint8_t m_nChanceOfSnow;
    uint8_t m_nChanceOfLightning;
    uint8_t m_nWindAmount;
    BOOL m_bNoRestingAllowed;
    uint8_t m_nShadowOpacity;
    float m_fFogClipDistance;

    CNWArea();
    virtual ~CNWArea();
    int32_t AddStaticObject(OBJECT_ID oidObject, const Vector & vOrientation, const Vector & vPosition, int32_t nVertices, Vector * pvVertices, int32_t nTriangles, int32_t * pnTriangles);
    void ReplaceStaticObject(int32_t nObjectPosition, OBJECT_ID oidObject, const Vector & vOrientation, const Vector & vPosition, int32_t nVertices, Vector * pvVertices, int32_t nTriangles, int32_t * pnTriangles);
    int32_t AddStaticBoundingBox(OBJECT_ID oidObject, const Vector & vMinimum, const Vector & vMaximum);
    int32_t RemoveStaticBoundingBox(OBJECT_ID oidObject);
    virtual BOOL NoCreaturesOnLine(float fSourceX, float fSourceY, float fTargetX, float fTargetY, CPathfindInformation * pPathfindInfo, BOOL bCheckSourceOccluded = true, BOOL bIgnoreAssociates = false, OBJECT_ID * poidBlockingCreature = nullptr, BOOL bEvaluateOverlappingTarget = false);
    void GrowStaticObjectArray();
    void GrowStaticObjectVertices(int32_t nNewVertices);
    void GrowStaticObjectTriangles(int32_t nNewTriangles);
    void InitializeStaticObjects();
    int32_t IntersectLineSegments(float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, float fX4, float fY4, float * fXIntersect, float * fYIntersect);
    int32_t NoNonWalkPolys(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor = 0x7f000000);
    int32_t NoNonWalkPolysDetailed(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, OBJECT_ID & oidBlockingDoor, BOOL bWalking, CExoArrayList<CGameObject *> * pExcludeList = nullptr, BOOL bIgnoreTransDoors = false);
    int32_t NoNonWalkPolysInDoors(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, OBJECT_ID & oidBlockingDoor, BOOL bWalking, CExoArrayList<CGameObject *> * pExcludeList = nullptr, BOOL bIgnoreTransDoors = false);
    virtual BOOL HandleTransparentDoors(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, OBJECT_ID & oidBlockingDoor, BOOL bWalking, CExoArrayList<CGameObject *> * pExcludeList = nullptr, BOOL bIgnoreTransDoors = false);
    virtual BOOL GetIsIDInExcludeList(OBJECT_ID oidID, CExoArrayList<CGameObject *> * pExcludeList = nullptr);
    virtual BOOL NoNoneWalkPolysInStaticObject(OBJECT_ID oidObject, float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace, OBJECT_ID oidDeniedDoor, BOOL bWalking = false);
    void RemoveStaticObject(int32_t nObjectIndex);
    void GetFog(int32_t * pFogValue, Vector * pColor);
    BOOL GetIsNight();
    virtual BOOL SetFog(int32_t nFogValue, Vector vColor);
    virtual BOOL SetIsNight(BOOL bIsNight);
    virtual BOOL SetWind(uint8_t nAmount);


#ifdef NWN_CLASS_EXTENSION_CNWArea
    NWN_CLASS_EXTENSION_CNWArea
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWArea)
#endif

