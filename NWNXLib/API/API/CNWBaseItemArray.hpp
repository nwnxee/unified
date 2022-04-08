#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWBaseItemArray)
#endif

struct CNWBaseItem;


typedef int BOOL;


struct CNWBaseItemArray
{
    int32_t m_nNumBaseItems;
    CNWBaseItem * m_pBaseItems;

    CNWBaseItemArray();
    ~CNWBaseItemArray();
    CNWBaseItem * GetBaseItem(int32_t nBaseItemID) const;
    void Load();
    uint16_t GetDefaultWeaponFocusFeat(uint32_t baseItemId);
    uint16_t GetDefaultEpicWeaponFocusFeat(uint32_t baseItemId);
    uint16_t GetDefaultWeaponSpecializationFeat(uint32_t baseItemId);
    uint16_t GetDefaultEpicWeaponSpecializationFeat(uint32_t baseItemId);
    uint16_t GetDefaultWeaponImprovedCriticalFeat(uint32_t baseItemId);
    uint16_t GetDefaultEpicWeaponOverwhelmingCriticalFeat(uint32_t baseItemId);
    uint16_t GetDefaultEpicWeaponDevastatingCriticalFeat(uint32_t baseItemId);
    uint16_t GetDefaultWeaponOfChoiceFeat(uint32_t baseItemId);
    BOOL GetIsDefaultMonkWeapon(uint32_t baseItemId);
    uint8_t GetDefaultWeaponFinesseMinimumCreatureSize(uint32_t baseItemId);


#ifdef NWN_CLASS_EXTENSION_CNWBaseItemArray
    NWN_CLASS_EXTENSION_CNWBaseItemArray
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWBaseItemArray)
#endif

