#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWItem
{
    void** m_vtable;
    uint8_t m_nLayeredTextureColors[6];
    uint8_t* m_pLayeredTextureColorsPerPart[6];
    uint32_t m_nBaseItem;

    // The below are auto generated stubs.
    CNWItem(const CNWItem&) = default;
    CNWItem& operator=(const CNWItem&) = default;

    CNWItem();
    ~CNWItem();
    unsigned char GetLayeredTextureColorPerPart(unsigned char, unsigned char);
    void SetLayeredTextureColorPerPart(unsigned char, unsigned char, unsigned char);
};

void CNWItem__CNWItemCtor(CNWItem* thisPtr);
void CNWItem__CNWItemDtor__0(CNWItem* thisPtr);
unsigned char CNWItem__GetLayeredTextureColorPerPart(CNWItem* thisPtr, unsigned char, unsigned char);
void CNWItem__SetLayeredTextureColorPerPart(CNWItem* thisPtr, unsigned char, unsigned char, unsigned char);

}

}
