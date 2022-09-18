#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CNWActionNode.hpp"
#include "CNWSStats_SpellLikeAbility.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerLastUpdateObject)
#endif

struct CEffectIconObject;
struct CFeatUseListEntry;
struct CNWSStats_Spell;
struct CNWVisibilityNode;
struct CSpell_Add;
struct CSpell_Delete;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSPlayerLastUpdateObject
{
    uint32_t m_nGold;
    int16_t m_nArmorClass;
    int16_t m_nHenchmanArmorClass;
    int16_t m_nTotalWeightCarried;
    int16_t m_nHenchmanTotalWeightCarried;
    BOOL m_bCanLevelUp;
    int32_t m_nLevel;
    uint32_t m_nGuiSkills;
    CExoArrayList<uint16_t> m_lstFeats;
    CExoArrayList<uint16_t> m_lstBonusFeats;
    CExoArrayList<CFeatUseListEntry *> m_lstFeatUses;
    uint32_t m_nPlayerState;
    int32_t m_nPolymorphSpellId1;
    int32_t m_nPolymorphSpellId2;
    int32_t m_nPolymorphSpellId3;
    CNWActionNode m_pActionQueueList[10];
    uint8_t * m_pAutoMapTileData;
    OBJECT_ID m_oidAutoMapArea;
    CExoArrayList<CNWVisibilityNode *> m_lstVisibilityList;
    CExoArrayList<uint32_t> m_pKnownSpellList[8][10];
    CExoArrayList<CNWSStats_Spell *> m_pMemorizedSpellList[8][10];
    CExoArrayList<uint32_t> m_lstKnownSpellsToDelete[8];
    CExoArrayList<uint32_t> m_lstKnownSpellsToAdd[8];
    CExoArrayList<CSpell_Delete *> m_lstMemorizedSpellsToDelete[8];
    CExoArrayList<CSpell_Add *> m_lstMemorizedSpellsToAdd[8];
    uint8_t m_pKnownSpellUsesLeft[8][10];
    CExoArrayList<CEffectIconObject *> m_aEffectIcons;
    CExoArrayList<CNWSStats_SpellLikeAbility> * m_pSpellLikeAbilityList;

    CNWSPlayerLastUpdateObject();
    ~CNWSPlayerLastUpdateObject();
    void SetMemorizedSpellSlot(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot, uint32_t nSpellId, BOOL bDomainSpell, uint8_t nMetaType);
    void AddKnownSpell(uint8_t nMultiClass, uint8_t nSpellLevel, uint32_t nSpellId);
    void ClearKnownSpells();
    void ClearMemorizedSpells();
    uint32_t GetKnownSpell(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot);
    uint32_t GetMemorizedSpell(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot);
    BOOL GetMemorizedSpellReadied(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot);
    void SetMemorizedSpellReadied(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot, BOOL bReadied);
    uint8_t GetMemorizedSpellMetaType(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot);
    BOOL GetIsDomainSpell(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nSpellSlot);
    void SetNumberMemorizedSpellSlots(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nNumSlots);
    void ClearSpellAddDeleteLists();
    void ClearKnownSpellUsesLeft();
    uint8_t GetKnownSpellUsesLeft(uint8_t nMultiClass, uint8_t nSpellLevel);
    void SetKnownSpellUsesLeft(uint8_t nMultiClass, uint8_t nSpellLevel, uint8_t nUses);
    void ClearVisibilityList();
    void ClearActionQueue();
    void ClearAutoMapData();
    void ResetAutoMapData(OBJECT_ID oidArea);
    BOOL InitializeAutoMapData();
    void ClearEffectIcons();


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerLastUpdateObject
    NWN_CLASS_EXTENSION_CNWSPlayerLastUpdateObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerLastUpdateObject)
#endif

