#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWItem)
#endif





class CNWItem
{
    uint8_t m_nLayeredTextureColors[6];
    uint8_t * m_pLayeredTextureColorsPerPart[6];
    uint32_t m_nBaseItem;

    CNWItem();
    virtual ~CNWItem();
    uint8_t GetLayeredTextureColorPerPart(uint8_t nTexture, uint8_t nPart);
    void SetLayeredTextureColorPerPart(uint8_t nTexture, uint8_t nPart, uint8_t nColor);


#ifdef NWN_CLASS_EXTENSION_CNWItem
    NWN_CLASS_EXTENSION_CNWItem
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWItem)
#endif

