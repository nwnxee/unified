#pragma once

#include <cstdint>

#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CLastUpdatePartyObject
{
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    int32_t m_bActive;
    uint32_t m_nPlayerId;
    uint16_t m_nAIState;
    uint8_t m_nAIStateAction;
    uint16_t m_nAIStateActivities;
    uint32_t m_oidAIStateActee;
    uint16_t m_nCurrentHitPoints;
    uint16_t m_nBaseHitPoints;
    uint16_t m_nTemporaryHitPoints;
    uint16_t m_nMaxHitPoints;
    uint8_t m_nAIStateReaction;
    int32_t m_bCombatState;
    uint32_t m_oidArea;
    Vector m_vPosition;
    int32_t m_bPC;
    int32_t m_bFreeWill;
    int32_t m_bPartyLeader;
    int32_t m_bSingletonParty;
    int32_t m_bInvitedToParty;
    int32_t m_bSummonedFamiliar;
    uint16_t m_nAssociateType;
    uint32_t m_oidMaster;
    int32_t m_bSummonedAnimalCompanion;
    int32_t m_bPoisoned;
    int32_t m_bDiseased;
};

}

}
