#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCombatRoundAction)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSCombatRoundAction
{
public:
    int32_t m_nActionTimer;
    uint16_t m_nAnimation;
    int32_t m_nAnimationTime;
    int32_t m_nNumAttacks;
    uint8_t m_nActionType;
    OBJECT_ID m_oidTarget;
    BOOL m_bActionRetargettable;
    uint32_t m_nInventorySlot;
    OBJECT_ID m_oidTargetRepository;
    uint8_t m_nRepositoryX;
    uint8_t m_nRepositoryY;

    CNWSCombatRoundAction();
    ~CNWSCombatRoundAction();
    BOOL SaveData(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadData(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSCombatRoundAction
    NWN_CLASS_EXTENSION_CNWSCombatRoundAction
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCombatRoundAction)
#endif

