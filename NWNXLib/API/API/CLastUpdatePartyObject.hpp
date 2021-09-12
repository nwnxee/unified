#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CLastUpdatePartyObject)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CLastUpdatePartyObject
{
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    BOOL m_bActive;
    OBJECT_ID m_nPlayerId;
    uint16_t m_nAIState;
    uint8_t m_nAIStateAction;
    uint16_t m_nAIStateActivities;
    uint32_t m_oidAIStateActee;
    uint16_t m_nCurrentHitPoints;
    uint16_t m_nBaseHitPoints;
    uint16_t m_nTemporaryHitPoints;
    uint16_t m_nMaxHitPoints;
    uint8_t m_nAIStateReaction;
    BOOL m_bCombatState;
    OBJECT_ID m_oidArea;
    Vector m_vPosition;
    BOOL m_bPC;
    BOOL m_bFreeWill;
    BOOL m_bPartyLeader;
    BOOL m_bSingletonParty;
    BOOL m_bInvitedToParty;
    BOOL m_bSummonedFamiliar;
    uint16_t m_nAssociateType;
    OBJECT_ID m_oidMaster;
    BOOL m_bSummonedAnimalCompanion;
    BOOL m_bTakesCommands;
    BOOL m_bPoisoned;
    BOOL m_bDiseased;



#ifdef NWN_CLASS_EXTENSION_CLastUpdatePartyObject
    NWN_CLASS_EXTENSION_CLastUpdatePartyObject
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CLastUpdatePartyObject)
#endif

