#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCEffectIconObjectPtr.hpp"
#include "CExoArrayListTemplatedCFeatUseListEntryPtr.hpp"
#include "CExoArrayListTemplatedCNWSStats_SpellPtr.hpp"
#include "CExoArrayListTemplatedCNWVisibilityNodePtr.hpp"
#include "CExoArrayListTemplatedCSpell_AddPtr.hpp"
#include "CExoArrayListTemplatedCSpell_DeletePtr.hpp"
#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoArrayListTemplatedshortunsignedint.hpp"
#include "CNWActionNode.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCNWSStats_SpellLikeAbility;

struct CNWSPlayerLastUpdateObject
{
    uint32_t m_nGold;
    int16_t m_nArmorClass;
    int16_t m_nHenchmanArmorClass;
    int16_t m_nTotalWeightCarried;
    int16_t m_nHenchmanTotalWeightCarried;
    int32_t m_bCanLevelUp;
    int32_t m_nLevel;
    uint32_t m_nGuiSkills;
    CExoArrayListTemplatedshortunsignedint m_lstFeats;
    CExoArrayListTemplatedshortunsignedint m_lstBonusFeats;
    CExoArrayListTemplatedCFeatUseListEntryPtr m_lstFeatUses;
    uint32_t m_nPlayerState;
    int32_t m_nPolymorphSpellId1;
    int32_t m_nPolymorphSpellId2;
    int32_t m_nPolymorphSpellId3;
    CNWActionNode m_pActionQueueList[10];
    uint8_t* m_pAutoMapTileData;
    uint32_t m_oidAutoMapArea;
    CExoArrayListTemplatedCNWVisibilityNodePtr m_lstVisibilityList;
    CExoArrayListTemplatedlongunsignedint m_pKnownSpellList[3][10];
    CExoArrayListTemplatedCNWSStats_SpellPtr m_pMemorizedSpellList[3][10];
    CExoArrayListTemplatedlongunsignedint m_lstKnownSpellsToDelete[3];
    CExoArrayListTemplatedlongunsignedint m_lstKnownSpellsToAdd[3];
    CExoArrayListTemplatedCSpell_DeletePtr m_lstMemorizedSpellsToDelete[3];
    CExoArrayListTemplatedCSpell_AddPtr m_lstMemorizedSpellsToAdd[3];
    uint8_t m_pKnownSpellUsesLeft[3][10];
    CExoArrayListTemplatedCEffectIconObjectPtr m_aEffectIcons;
    CExoArrayListTemplatedCNWSStats_SpellLikeAbility* m_pSpellLikeAbilityList;

    // The below are auto generated stubs.
    CNWSPlayerLastUpdateObject(const CNWSPlayerLastUpdateObject&) = default;
    CNWSPlayerLastUpdateObject& operator=(const CNWSPlayerLastUpdateObject&) = default;

    CNWSPlayerLastUpdateObject();
    ~CNWSPlayerLastUpdateObject();
    void AddKnownSpell(unsigned char, unsigned char, uint32_t);
    void ClearActionQueue();
    void ClearAutoMapData();
    void ClearEffectIcons();
    void ClearKnownSpells();
    void ClearKnownSpellUsesLeft();
    void ClearMemorizedSpells();
    void ClearSpellAddDeleteLists();
    void ClearVisibilityList();
    int32_t GetIsDomainSpell(unsigned char, unsigned char, unsigned char);
    uint32_t GetKnownSpell(unsigned char, unsigned char, unsigned char);
    unsigned char GetKnownSpellUsesLeft(unsigned char, unsigned char);
    uint32_t GetMemorizedSpell(unsigned char, unsigned char, unsigned char);
    unsigned char GetMemorizedSpellMetaType(unsigned char, unsigned char, unsigned char);
    int32_t GetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char);
    int32_t InitializeAutoMapData();
    void ResetAutoMapData(uint32_t);
    void SetKnownSpellUsesLeft(unsigned char, unsigned char, unsigned char);
    void SetMemorizedSpellReadied(unsigned char, unsigned char, unsigned char, int32_t);
    void SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
    void SetNumberMemorizedSpellSlots(unsigned char, unsigned char, unsigned char);
};

void CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectCtor__0(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectDtor__0(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__AddKnownSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, uint32_t);
void CNWSPlayerLastUpdateObject__ClearActionQueue(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearAutoMapData(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearEffectIcons(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearKnownSpells(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearMemorizedSpells(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearSpellAddDeleteLists(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ClearVisibilityList(CNWSPlayerLastUpdateObject* thisPtr);
int32_t CNWSPlayerLastUpdateObject__GetIsDomainSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
uint32_t CNWSPlayerLastUpdateObject__GetKnownSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
unsigned char CNWSPlayerLastUpdateObject__GetKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char);
uint32_t CNWSPlayerLastUpdateObject__GetMemorizedSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
unsigned char CNWSPlayerLastUpdateObject__GetMemorizedSpellMetaType(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
int32_t CNWSPlayerLastUpdateObject__GetMemorizedSpellReadied(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
int32_t CNWSPlayerLastUpdateObject__InitializeAutoMapData(CNWSPlayerLastUpdateObject* thisPtr);
void CNWSPlayerLastUpdateObject__ResetAutoMapData(CNWSPlayerLastUpdateObject* thisPtr, uint32_t);
void CNWSPlayerLastUpdateObject__SetKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);
void CNWSPlayerLastUpdateObject__SetMemorizedSpellReadied(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char, int32_t);
void CNWSPlayerLastUpdateObject__SetMemorizedSpellSlot(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
void CNWSPlayerLastUpdateObject__SetNumberMemorizedSpellSlots(CNWSPlayerLastUpdateObject* thisPtr, unsigned char, unsigned char, unsigned char);

}

}
