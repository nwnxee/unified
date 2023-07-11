#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CCombatInformationNode)
#endif



typedef int BOOL;


class CCombatInformationNode
{
    char m_nModifier;
    uint8_t m_nModifierType;
    uint8_t m_nWeaponWield;
    uint8_t m_nVersusAlignLawChaos;
    uint8_t m_nVersusAlignGoodEvil;
    uint8_t m_nVersusRace;

    CCombatInformationNode();
    BOOL operator==(CCombatInformationNode & pNode);
    BOOL operator!=(CCombatInformationNode & pNode);
    CCombatInformationNode & operator=(const CCombatInformationNode & pNode);


#ifdef NWN_CLASS_EXTENSION_CCombatInformationNode
    NWN_CLASS_EXTENSION_CCombatInformationNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CCombatInformationNode)
#endif

