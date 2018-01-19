#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCNWSStats_SpellPtr.hpp"
#include "CExoArrayListTemplatedlongunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSStats_Spell;

struct CNWSCreatureStats_ClassInfo
{
    CExoArrayListTemplatedlongunsignedint m_pKnownSpellList[10];
    CExoArrayListTemplatedCNWSStats_SpellPtr m_pMemorizedSpellList[10];
    uint32_t m_nBonusSpellsList[10];
    uint8_t m_nSpellsPerDayLeft[10];
    uint8_t m_nMaxSpellsPerDayLeft[10];
    uint8_t m_nClass;
    uint8_t m_nLevel;
    uint8_t m_nNegativeLevels;
    uint8_t m_nSchool;
    uint8_t m_nDomain[2];
    int32_t m_bHasLostClassAbilities;

    // The below are auto generated stubs.
    CNWSCreatureStats_ClassInfo(const CNWSCreatureStats_ClassInfo&) = default;
    CNWSCreatureStats_ClassInfo& operator=(const CNWSCreatureStats_ClassInfo&) = default;

    CNWSCreatureStats_ClassInfo();
    ~CNWSCreatureStats_ClassInfo();
    void AddKnownSpell(unsigned char, uint32_t);
    void ClearMemorizedKnownSpells(uint32_t);
    void ClearMemorizedSpellSlot(unsigned char, unsigned char);
    int32_t ConfirmDomainSpell(unsigned char, uint32_t);
    void DecrementSpellsPerDayLeft(unsigned char);
    int32_t GetIsDomainSpell(unsigned char, unsigned char);
    uint32_t GetKnownSpell(unsigned char, unsigned char);
    unsigned char GetMaxSpellsPerDayLeft(unsigned char);
    uint32_t GetMemorizedSpellInSlot(unsigned char, unsigned char);
    CNWSStats_Spell* GetMemorizedSpellInSlotDetails(unsigned char, unsigned char);
    unsigned char GetMemorizedSpellInSlotMetaType(unsigned char, unsigned char);
    int32_t GetMemorizedSpellInSlotReady(unsigned char, unsigned char);
    unsigned char GetMemorizedSpellReadyCount(uint32_t, unsigned char);
    unsigned char GetMemorizedSpellReadyCount(uint32_t, unsigned char*, unsigned char*, unsigned char);
    unsigned char GetNumberBonusSpells(unsigned char);
    uint16_t GetNumberKnownSpells(unsigned char);
    unsigned char GetNumberMemorizedSpellSlots(unsigned char);
    unsigned char GetSpellsPerDayLeft(unsigned char);
    void IncrementSpellsPerDayLeft(unsigned char);
    void ModifyNumberBonusSpells(unsigned char, int32_t);
    void RemoveKnownSpell(unsigned char, uint32_t);
    void ResetSpellsPerDayLeft(unsigned char, unsigned char);
    void SetMaxSpellsPerDayLeft(unsigned char, unsigned char);
    void SetMemorizedSpellInSlotReady(unsigned char, unsigned char, int32_t);
    void SetMemorizedSpellSlot(unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
    void SetNumberMemorizedSpellSlots(unsigned char, unsigned char, int32_t);
    void SetSpellsPerDayLeft(unsigned char, unsigned char);
};

void CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoCtor(CNWSCreatureStats_ClassInfo* thisPtr);
void CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoDtor(CNWSCreatureStats_ClassInfo* thisPtr);
void CNWSCreatureStats_ClassInfo__AddKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, uint32_t);
void CNWSCreatureStats_ClassInfo__ClearMemorizedKnownSpells(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t);
void CNWSCreatureStats_ClassInfo__ClearMemorizedSpellSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
int32_t CNWSCreatureStats_ClassInfo__ConfirmDomainSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, uint32_t);
void CNWSCreatureStats_ClassInfo__DecrementSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
int32_t CNWSCreatureStats_ClassInfo__GetIsDomainSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
uint32_t CNWSCreatureStats_ClassInfo__GetKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetMaxSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
uint32_t CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
CNWSStats_Spell* CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotDetails(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotMetaType(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
int32_t CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotReady(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__0(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__1(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t, unsigned char*, unsigned char*, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetNumberBonusSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
uint16_t CNWSCreatureStats_ClassInfo__GetNumberKnownSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetNumberMemorizedSpellSlots(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
unsigned char CNWSCreatureStats_ClassInfo__GetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
void CNWSCreatureStats_ClassInfo__IncrementSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char);
void CNWSCreatureStats_ClassInfo__ModifyNumberBonusSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, int32_t);
void CNWSCreatureStats_ClassInfo__RemoveKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, uint32_t);
void CNWSCreatureStats_ClassInfo__ResetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
void CNWSCreatureStats_ClassInfo__SetMaxSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);
void CNWSCreatureStats_ClassInfo__SetMemorizedSpellInSlotReady(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char, int32_t);
void CNWSCreatureStats_ClassInfo__SetMemorizedSpellSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
void CNWSCreatureStats_ClassInfo__SetNumberMemorizedSpellSlots(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char, int32_t);
void CNWSCreatureStats_ClassInfo__SetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char, unsigned char);

}

}
