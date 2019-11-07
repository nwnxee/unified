#pragma once
#include "nwn_api.hpp"

#include "CNWTileSet.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSTileSet)
#endif

struct CNWSTileData;


typedef int BOOL;


struct CNWSTileSet : CNWTileSet
{
    CNWSTileData * m_pTileData;

    CNWSTileSet(CResRef cResRef, BOOL bSetAutoRequest);
    ~CNWSTileSet();
    CNWSTileData * GetTileData(int32_t nTile);
    BOOL LoadTileSet();
    void UnloadTileSet();
    BOOL ParseLine(char * pLine);
    BOOL SetTileValue(char * pVariable, char * pValue);


#ifdef NWN_CLASS_EXTENSION_CNWSTileSet
    NWN_CLASS_EXTENSION_CNWSTileSet
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSTileSet)
#endif

