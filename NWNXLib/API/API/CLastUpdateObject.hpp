#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSPlayerLUOAppearanceInfo.hpp"
#include "CResRef.hpp"
#include "MaterialShaderParam.hpp"
#include "ObjectVisualTransformData.hpp"
#include "TextureReplaceInfo.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CLastUpdateObject)
#endif

struct CLoopingVisualEffect;
struct CNWSPlayerLUOQuickbarItemButton;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CLastUpdateObject
{
    CNWSPlayerLUOAppearanceInfo m_cAppearance;
    BOOL m_bActive;
    uint8_t m_nObjectType;
    uint16_t m_nSoundSet;
    int32_t m_nFootstepType;
    uint32_t m_nId;
    Vector m_vPosition;
    OBJECT_ID m_oidArea;
    Vector m_vOrientation;
    int32_t m_nAnimation;
    float m_fAnimSpeed;
    uint8_t m_nWalkAnimation;
    Vector m_vWalkTo;
    uint8_t m_nPlayerPathNumber;
    uint8_t m_nWalkedPathCutVerify;
    uint16_t m_nAIState;
    uint8_t m_nAIStateAction;
    uint16_t m_nAIStateActivities;
    BOOL m_bCombatState;
    uint32_t m_oidAIStateActee;
    OBJECT_ID m_oidLockOnTarget;
    OBJECT_ID m_oidAttackTarget;
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    CExoLocString m_sLocFirstName;
    CExoLocString m_sLocLastName;
    float m_fWalkRate;
    float m_fRunRate;
    CExoArrayList<CLoopingVisualEffect *> m_lstLoopingVisualEffects;
    uint16_t m_nAssociateState;
    uint8_t m_nDamageLevel;
    uint8_t m_nDomain1;
    uint8_t m_nDomain2;
    uint8_t m_nSchool;
    int16_t m_nCurrentHitPoints;
    int16_t m_nBaseHitPoints;
    int16_t m_nTemporaryHitPoints;
    int16_t m_nMaxHitPoints;
    BOOL m_bFreeWill;
    BOOL m_bPartyLeader;
    BOOL m_bSingletonParty;
    BOOL m_bInvitedToParty;
    CExoArrayList<OBJECT_ID> m_poidCreatureList;
    BOOL m_bTrapped;
    BOOL m_bFlagged;
    int32_t m_nTrapFaction;
    BOOL m_bLocked;
    BOOL m_bLockable;
    BOOL m_bRecoverable;
    BOOL m_bClickable;
    uint8_t m_nAIStateReaction;
    OBJECT_ID m_oidMaster;
    uint16_t m_nAssociateType;
    BOOL m_bSummonedAnimalCompanion;
    BOOL m_bSummonedFamiliar;
    BOOL m_bTakesCommands;
    BOOL m_bObjectSeen;
    BOOL m_bObjectHeard;
    BOOL m_bObjectInvisible;
    uint16_t m_nRace;
    CExoString m_sSubRace;
    CExoString m_sDeity;
    uint8_t m_nGender;
    uint8_t m_nClass[3];
    uint8_t m_nLevel[3];
    int16_t m_nAlignmentLawChaos;
    int16_t m_nAlignmentGoodEvil;
    BOOL m_bSelectableWhenDead;
    BOOL m_bLootable;
    BOOL m_bPC;
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
    ObjectVisualTransformData m_pObjectVisualTransformData;
    CExoArrayList<MaterialShaderParam> m_lMaterialShaderParameters;
    CExoArrayList<TextureReplaceInfo> m_lTextureReplaceInfo;
    Vector m_vHiliteColor;
    int32_t m_nMouseCursor;
    int32_t m_nUpdateDisplayNameSeq;
    int32_t m_nUpdateHiddenSeq;
    CNWSPlayerLUOQuickbarItemButton * m_pQuickbarButton;

    CLastUpdateObject();
    ~CLastUpdateObject();
    void InitializeQuickbar();


#ifdef NWN_CLASS_EXTENSION_CLastUpdateObject
    NWN_CLASS_EXTENSION_CLastUpdateObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CLastUpdateObject)
#endif

