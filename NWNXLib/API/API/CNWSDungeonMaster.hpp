#pragma once
#include "nwn_api.hpp"

#include "CNWSPlayer.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDungeonMaster)
#endif



typedef uint32_t OBJECT_ID;


struct CNWSDungeonMaster : CNWSPlayer
{
    OBJECT_ID m_oidDungeonMasterAvatar;
    uint8_t m_nPossessState;

    CNWSDungeonMaster(uint32_t nPlayerID);
    virtual CNWSDungeonMaster * AsNWSDungeonMaster();
    void PossessCreature(OBJECT_ID oidTarget, uint8_t possessType);


#ifdef NWN_CLASS_EXTENSION_CNWSDungeonMaster
    NWN_CLASS_EXTENSION_CNWSDungeonMaster
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDungeonMaster)
#endif

