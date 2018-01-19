#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CNWSCombatRoundAction
{
    int32_t m_nActionTimer;
    uint16_t m_nAnimation;
    int32_t m_nAnimationTime;
    int32_t m_nNumAttacks;
    uint8_t m_nActionType;
    uint32_t m_oidTarget;
    int32_t m_bActionRetargettable;
    uint32_t m_nInventorySlot;
    uint32_t m_oidTargetRepository;
    uint8_t m_nRepositoryX;
    uint8_t m_nRepositoryY;

    // The below are auto generated stubs.
    CNWSCombatRoundAction(const CNWSCombatRoundAction&) = default;
    CNWSCombatRoundAction& operator=(const CNWSCombatRoundAction&) = default;

    CNWSCombatRoundAction();
    ~CNWSCombatRoundAction();
    int32_t LoadData(CResGFF*, CResStruct*);
    int32_t SaveData(CResGFF*, CResStruct*);
};

void CNWSCombatRoundAction__CNWSCombatRoundActionCtor__0(CNWSCombatRoundAction* thisPtr);
void CNWSCombatRoundAction__CNWSCombatRoundActionDtor__0(CNWSCombatRoundAction* thisPtr);
int32_t CNWSCombatRoundAction__LoadData(CNWSCombatRoundAction* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSCombatRoundAction__SaveData(CNWSCombatRoundAction* thisPtr, CResGFF*, CResStruct*);

}

}
