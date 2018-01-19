#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListTemplatedCExoString;
struct CNWTileSurfaceMesh;

struct CNWTileData
{
    void** m_vtable;
    CExoLinkedListTemplatedCExoString* m_pMethodStringList;
    CNWTileSurfaceMesh* m_pSurfaceMesh;
    CResRef m_refModel;
    CResRef m_refMapIcon;
    uint8_t m_nNumDoors;
    CExoString m_sCornerTopLeft;
    CExoString m_sCornerTopRight;
    CExoString m_sCornerBottomLeft;
    CExoString m_sCornerBottomRight;
    CExoString m_sEdgeTop;
    CExoString m_sEdgeBottom;
    CExoString m_sEdgeLeft;
    CExoString m_sEdgeRight;

    // The below are auto generated stubs.
    CNWTileData(const CNWTileData&) = default;
    CNWTileData& operator=(const CNWTileData&) = default;

    CNWTileData();
    ~CNWTileData();
    int32_t AddPropertyMethodString(uint32_t, CExoString);
    CExoString GetCornerType(unsigned char);
    CExoString GetEdgeType(unsigned char);
    CResRef GetMapIcon();
    CResRef GetModelResRef();
    CExoLinkedListTemplatedCExoString* GetPropertyMethodStringList(uint32_t);
    void SetCornerType(unsigned char, CExoString, int32_t);
    void SetEdgeType(unsigned char, CExoString);
    void SetMapIcon(CResRef);
    void SetModelResRef(CResRef);
};

void CNWTileData__CNWTileDataCtor__0(CNWTileData* thisPtr);
void CNWTileData__CNWTileDataDtor__0(CNWTileData* thisPtr);
int32_t CNWTileData__AddPropertyMethodString(CNWTileData* thisPtr, uint32_t, CExoString);
CExoString CNWTileData__GetCornerType(CNWTileData* thisPtr, unsigned char);
CExoString CNWTileData__GetEdgeType(CNWTileData* thisPtr, unsigned char);
CResRef CNWTileData__GetMapIcon(CNWTileData* thisPtr);
CResRef CNWTileData__GetModelResRef(CNWTileData* thisPtr);
CExoLinkedListTemplatedCExoString* CNWTileData__GetPropertyMethodStringList(CNWTileData* thisPtr, uint32_t);
void CNWTileData__SetCornerType(CNWTileData* thisPtr, unsigned char, CExoString, int32_t);
void CNWTileData__SetEdgeType(CNWTileData* thisPtr, unsigned char, CExoString);
void CNWTileData__SetMapIcon(CNWTileData* thisPtr, CResRef);
void CNWTileData__SetModelResRef(CNWTileData* thisPtr, CResRef);

}

}
