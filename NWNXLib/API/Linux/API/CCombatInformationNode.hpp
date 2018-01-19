#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CCombatInformationNode
{
    char m_nModifier;
    uint8_t m_nModifierType;
    uint8_t m_nWeaponWield;
    uint8_t m_nVersusAlignLawChaos;
    uint8_t m_nVersusAlignGoodEvil;
    uint8_t m_nVersusRace;

    // The below are auto generated stubs.
    CCombatInformationNode(const CCombatInformationNode&) = default;

    CCombatInformationNode();
    int32_t operator!=(CCombatInformationNode&);
    CCombatInformationNode& operator=(const CCombatInformationNode&);
    int32_t operator==(CCombatInformationNode&);
};

void CCombatInformationNode__CCombatInformationNodeCtor(CCombatInformationNode* thisPtr);
int32_t CCombatInformationNode__OperatorNotEqualTo(CCombatInformationNode* thisPtr, CCombatInformationNode&);
CCombatInformationNode& CCombatInformationNode__OperatorAssignment(CCombatInformationNode* thisPtr, const CCombatInformationNode&);
int32_t CCombatInformationNode__OperatorEqualTo(CCombatInformationNode* thisPtr, CCombatInformationNode&);

}

}
