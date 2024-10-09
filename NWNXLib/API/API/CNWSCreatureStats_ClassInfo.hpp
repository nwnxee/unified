#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCreatureStats_ClassInfo)
#endif

struct CNWSStats_Spell;


typedef int BOOL;


struct CNWSCreatureStats_ClassInfo
{
    CExoArrayList<uint32_t> m_pKnownSpellList[10];
    CExoArrayList<CNWSStats_Spell *> m_pMemorizedSpellList[10];
    uint32_t m_nBonusSpellsList[10];
    uint8_t m_nSpellsPerDayLeft[10];
    uint8_t m_nMaxSpellsPerDayLeft[10];
    uint8_t m_nClass;
    uint8_t m_nLevel;
    uint8_t m_nNegativeLevels;
    uint8_t m_nSchool;
    uint8_t m_nDomain[2];
    BOOL m_bHasLostClassAbilities;

    CNWSCreatureStats_ClassInfo();
    ~CNWSCreatureStats_ClassInfo();
    void SetMemorizedSpellSlot(uint8_t nSpellLevel, uint8_t nSpellSlot, uint32_t nSpellId, BOOL bDomainSpell, uint8_t nMetaType);
    void ClearMemorizedSpellSlot(uint8_t nSpellLevel, uint8_t nSpellSlot);
    void ClearMemorizedKnownSpells(uint32_t nSpellId);
    void AddKnownSpell(uint8_t nSpellLevel, uint32_t nSpellId);
    void RemoveKnownSpell(uint8_t nSpellLevel, uint32_t nSpellId);
    uint32_t GetKnownSpell(uint8_t nSpellLevel, uint8_t nSpellListIndex);
    uint32_t GetMemorizedSpellInSlot(uint8_t nSpellLevel, uint8_t nSpellSlot);
    BOOL GetIsDomainSpell(uint8_t nSpellLevel, uint8_t nSpellSlot);
    BOOL ConfirmDomainSpell(uint8_t nSpellLevel, uint32_t nSpellID);
    CNWSStats_Spell * GetMemorizedSpellInSlotDetails(uint8_t nSpellLevel, uint8_t nSpellSlot);
    uint16_t GetNumberKnownSpells(uint8_t nSpellLevel);
    uint8_t GetNumberMemorizedSpellSlots(uint8_t nSpellLevel);
    void SetNumberMemorizedSpellSlots(uint8_t nSpellLevel, uint8_t nNumSlots, BOOL bClear = true);
    uint8_t GetNumberBonusSpells(uint8_t nSpellLevel);
    void ModifyNumberBonusSpells(uint8_t nSpellLevel, int32_t nDelta);
    BOOL GetMemorizedSpellInSlotReady(uint8_t nSpellLevel, uint8_t nSpellSlot);
    void SetMemorizedSpellInSlotReady(uint8_t nSpellLevel, uint8_t nSpellSlot, BOOL bReady);
    uint8_t GetMemorizedSpellReadyCount(uint32_t nSpellID, uint8_t * nMinSpellLevel, uint8_t * nMinSpellSlot, uint8_t nRequestedMetaType = 0xFF);
    uint8_t GetMemorizedSpellReadyCount(uint32_t nSpellID, uint8_t nSpellLevel);
    uint8_t GetMemorizedSpellInSlotMetaType(uint8_t nSpellLevel, uint8_t nSpellSlot);
    uint8_t GetSpellsPerDayLeft(uint8_t nSpellLevel);
    void SetSpellsPerDayLeft(uint8_t nSpellLevel, uint8_t nNumSpells);
    uint8_t GetMaxSpellsPerDayLeft(uint8_t nSpellLevel);
    void SetMaxSpellsPerDayLeft(uint8_t nSpellLevel, uint8_t nNumSpells);
    void DecrementSpellsPerDayLeft(uint8_t nSpellLevel);
    void IncrementSpellsPerDayLeft(uint8_t nSpellLevel);
    void ResetSpellsPerDayLeft(uint8_t nSpellLevel, uint8_t nSpellGain);


#ifdef NWN_CLASS_EXTENSION_CNWSCreatureStats_ClassInfo
    NWN_CLASS_EXTENSION_CNWSCreatureStats_ClassInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCreatureStats_ClassInfo)
#endif
