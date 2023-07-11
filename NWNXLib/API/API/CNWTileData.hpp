#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileData)
#endif

class CNWTileSurfaceMesh;


typedef int BOOL;


class CNWTileData
{
public:
    CExoLinkedList<CExoString> * m_pMethodStringList;
    CNWTileSurfaceMesh * m_pSurfaceMesh;
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

    CNWTileData();
    virtual ~CNWTileData();
    BOOL AddPropertyMethodString(uint32_t nProperty, CExoString sMethodString);
    CExoLinkedList<CExoString> * GetPropertyMethodStringList(uint32_t nProperty);
    CResRef GetModelResRef();
    void SetModelResRef(CResRef refModel);
    CResRef GetMapIcon();
    void SetMapIcon(CResRef refMapIcon);
    void SetCornerType(uint8_t nCorner, CExoString sType, BOOL bHeight);
    CExoString GetCornerType(uint8_t nCorner);
    void SetEdgeType(uint8_t nEdge, CExoString sType);
    CExoString GetEdgeType(uint8_t nEdge);


#ifdef NWN_CLASS_EXTENSION_CNWTileData
    NWN_CLASS_EXTENSION_CNWTileData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileData)
#endif

