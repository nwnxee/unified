#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWTile
{
    void** m_vtable;
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

    // The below are auto generated stubs.
    CNWTile(const CNWTile&) = default;
    CNWTile& operator=(const CNWTile&) = default;

    CNWTile();
    ~CNWTile();
    void GetAnimLoop(unsigned char*, unsigned char*, unsigned char*);
    void GetLocation(int32_t*, int32_t*);
    void GetMainLightColor(unsigned char*, unsigned char*);
    void GetSourceLightColor(unsigned char*, unsigned char*);
    void RotateCanonicalToReal(float, float, float*, float*);
    void RotateCanonicalToRealTile(float, float, float*, float*);
    void RotateRealToCanonical(float, float, float*, float*);
    void RotateRealToCanonicalTile(float, float, float*, float*);
    void SetAnimLoop(unsigned char, unsigned char, unsigned char);
    void SetID(int32_t);
    void SetMainLightColor(unsigned char, unsigned char);
    void SetOrientation(int32_t);
    void SetPosition(int32_t, int32_t, int32_t, float);
    void SetReplaceTexture(unsigned char);
    void SetSourceLightColor(unsigned char, unsigned char);
};

void CNWTile__CNWTileCtor(CNWTile* thisPtr);
void CNWTile__CNWTileDtor__0(CNWTile* thisPtr);
void CNWTile__GetAnimLoop(CNWTile* thisPtr, unsigned char*, unsigned char*, unsigned char*);
void CNWTile__GetLocation(CNWTile* thisPtr, int32_t*, int32_t*);
void CNWTile__GetMainLightColor(CNWTile* thisPtr, unsigned char*, unsigned char*);
void CNWTile__GetSourceLightColor(CNWTile* thisPtr, unsigned char*, unsigned char*);
void CNWTile__RotateCanonicalToReal(CNWTile* thisPtr, float, float, float*, float*);
void CNWTile__RotateCanonicalToRealTile(CNWTile* thisPtr, float, float, float*, float*);
void CNWTile__RotateRealToCanonical(CNWTile* thisPtr, float, float, float*, float*);
void CNWTile__RotateRealToCanonicalTile(CNWTile* thisPtr, float, float, float*, float*);
void CNWTile__SetAnimLoop(CNWTile* thisPtr, unsigned char, unsigned char, unsigned char);
void CNWTile__SetID(CNWTile* thisPtr, int32_t);
void CNWTile__SetMainLightColor(CNWTile* thisPtr, unsigned char, unsigned char);
void CNWTile__SetOrientation(CNWTile* thisPtr, int32_t);
void CNWTile__SetPosition(CNWTile* thisPtr, int32_t, int32_t, int32_t, float);
void CNWTile__SetReplaceTexture(CNWTile* thisPtr, unsigned char);
void CNWTile__SetSourceLightColor(CNWTile* thisPtr, unsigned char, unsigned char);

}

}
