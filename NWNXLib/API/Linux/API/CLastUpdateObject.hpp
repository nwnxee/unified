#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCLoopingVisualEffectPtr.hpp"
#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSPlayerLUOAppearanceInfo.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPlayerLUOQuickbarItemButton;

struct CLastUpdateObject
{
    CNWSPlayerLUOAppearanceInfo m_cAppearance;
    int32_t m_bActive;
    uint8_t m_nObjectType;
    uint16_t m_nSoundSet;
    int32_t m_nFootstepType;
    uint32_t m_nId;
    Vector m_vPosition;
    uint32_t m_oidArea;
    Vector m_vOrientation;
    int32_t m_nAnimation;
    float m_fAnimSpeed;
    Vector m_vWalkTo;
    uint8_t m_nPlayerPathNumber;
    uint8_t m_nWalkedPathCutVerify;
    uint16_t m_nAIState;
    uint8_t m_nAIStateAction;
    uint16_t m_nAIStateActivities;
    int32_t m_bCombatState;
    uint32_t m_oidAIStateActee;
    uint32_t m_oidLockOnTarget;
    uint32_t m_oidAttackTarget;
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    CExoLocString m_sLocFirstName;
    CExoLocString m_sLocLastName;
    float m_fWalkRate;
    float m_fRunRate;
    CExoArrayListTemplatedCLoopingVisualEffectPtr m_lstLoopingVisualEffects;
    uint16_t m_nAssociateState;
    uint8_t m_nDamageLevel;
    uint8_t m_nDomain1;
    uint8_t m_nDomain2;
    uint8_t m_nSchool;
    int16_t m_nCurrentHitPoints;
    int16_t m_nBaseHitPoints;
    int16_t m_nTemporaryHitPoints;
    int16_t m_nMaxHitPoints;
    int32_t m_bFreeWill;
    int32_t m_bPartyLeader;
    int32_t m_bSingletonParty;
    int32_t m_bInvitedToParty;
    CExoArrayListTemplatedlongunsignedint m_poidCreatureList;
    int32_t m_bTrapped;
    int32_t m_bFlagged;
    int32_t m_nTrapFaction;
    int32_t m_bLocked;
    int32_t m_bLockable;
    int32_t m_bRecoverable;
    uint8_t m_nAIStateReaction;
    uint32_t m_oidMaster;
    uint16_t m_nAssociateType;
    int32_t m_bSummonedAnimalCompanion;
    int32_t m_bSummonedFamiliar;
    int32_t m_bObjectSeen;
    int32_t m_bObjectHeard;
    int32_t m_bObjectInvisible;
    uint16_t m_nRace;
    CExoString m_sSubRace;
    CExoString m_sDeity;
    uint8_t m_nGender;
    uint8_t m_nClass[3];
    uint8_t m_nLevel[3];
    int16_t m_nAlignmentLawChaos;
    int16_t m_nAlignmentGoodEvil;
    int32_t m_bSelectableWhenDead;
    int32_t m_bLootable;
    int32_t m_bPC;
    uint8_t m_nAbilityBaseSTR;
    uint8_t m_nAbilityBaseDEX;
    uint8_t m_nAbilityBaseCON;
    uint8_t m_nAbilityBaseINT;
    uint8_t m_nAbilityBaseWIS;
    uint8_t m_nAbilityBaseCHA;
    uint8_t m_nAbilityFinalSTR;
    uint8_t m_nAbilityFinalDEX;
    uint8_t m_nAbilityFinalCON;
    uint8_t m_nAbilityFinalINT;
    uint8_t m_nAbilityFinalWIS;
    uint8_t m_nAbilityFinalCHA;
    CNWSPlayerLUOQuickbarItemButton* m_pQuickbarButton;

    // The below are auto generated stubs.
    CLastUpdateObject(const CLastUpdateObject&) = default;
    CLastUpdateObject& operator=(const CLastUpdateObject&) = default;

    CLastUpdateObject();
    ~CLastUpdateObject();
    void InitializeQuickbar();
};

void CLastUpdateObject__CLastUpdateObjectCtor(CLastUpdateObject* thisPtr);
void CLastUpdateObject__CLastUpdateObjectDtor(CLastUpdateObject* thisPtr);
void CLastUpdateObject__InitializeQuickbar(CLastUpdateObject* thisPtr);

}

}
