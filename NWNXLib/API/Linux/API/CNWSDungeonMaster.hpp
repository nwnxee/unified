#pragma once

#include <cstdint>

#include "CNWSPlayer.hpp"

namespace NWNXLib {

namespace API {

struct CNWSDungeonMaster
    : CNWSPlayer
{
    uint32_t m_oidDungeonMasterAvatar;
    uint8_t m_nPossessState;

    // The below are auto generated stubs.
    CNWSDungeonMaster() = default;
    CNWSDungeonMaster(const CNWSDungeonMaster&) = default;
    CNWSDungeonMaster& operator=(const CNWSDungeonMaster&) = default;

    CNWSDungeonMaster(uint32_t);
    ~CNWSDungeonMaster();
    CNWSDungeonMaster* AsNWSDungeonMaster();
    void PossessCreature(uint32_t, unsigned char);
};

void CNWSDungeonMaster__CNWSDungeonMasterCtor(CNWSDungeonMaster* thisPtr, uint32_t);
void CNWSDungeonMaster__CNWSDungeonMasterDtor__0(CNWSDungeonMaster* thisPtr);
CNWSDungeonMaster* CNWSDungeonMaster__AsNWSDungeonMaster(CNWSDungeonMaster* thisPtr);
void CNWSDungeonMaster__PossessCreature(CNWSDungeonMaster* thisPtr, uint32_t, unsigned char);

}

}
