#pragma once
#include "nwn_api.hpp"

#include "CCallbackHandlerBase.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTile)
#endif





class CNWTile : CCallbackHandlerBase
{
    Vector m_vModelPosition;
    int32_t m_nID;
    int32_t m_nHeight;
    int32_t m_nGridX;
    int32_t m_nGridY;
    int32_t m_nOrientation;
    uint8_t m_nMainLight1Color;
    uint8_t m_nMainLight2Color;
    uint8_t m_nSourceLight1Color;
    uint8_t m_nSourceLight2Color;
    uint8_t m_nReplaceTexture;
    uint8_t m_nAnimLoop1;
    uint8_t m_nAnimLoop2;
    uint8_t m_nAnimLoop3;

    CNWTile();
    virtual ~CNWTile();
    void GetLocation(int32_t * pX, int32_t * pY);
    void SetID(int32_t nID);
    void SetPosition(int32_t nX, int32_t nY, int32_t nHeight, float fHeightInc);
    void SetOrientation(int32_t nOrientation);
    void RotateCanonicalToRealTile(float fX, float fY, float * fNewX, float * fNewY);
    void RotateRealToCanonicalTile(float fX, float fY, float * fNewX, float * fNewY);
    void RotateCanonicalToReal(float fX, float fY, float * fNewX, float * fNewY);
    void RotateRealToCanonical(float fX, float fY, float * fNewX, float * fNewY);
    void GetMainLightColor(uint8_t * pMainLight1Color, uint8_t * pMainLight2Color);
    void GetSourceLightColor(uint8_t * pSourceLight1Color, uint8_t * pSourceLight2Color);
    void GetAnimLoop(uint8_t * pAnimLoop1, uint8_t * pAnimLoop2, uint8_t * pAnimLoop3);
    void SetMainLightColor(uint8_t nMainLight1Color, uint8_t nMainLight2Color);
    void SetSourceLightColor(uint8_t nSourceLight1Color, uint8_t nSourceLight2Color);
    void SetReplaceTexture(uint8_t nValue);
    void SetAnimLoop(uint8_t nAnimLoop1, uint8_t nAnimLoop2, uint8_t nAnimLoop3);


#ifdef NWN_CLASS_EXTENSION_CNWTile
    NWN_CLASS_EXTENSION_CNWTile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTile)
#endif

