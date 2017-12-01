#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"

namespace NWNXLib {

namespace API {

struct piPlayer
{
    char nick[64];
    PEERBool inRoom[3];
    PEERBool local;
    uint32_t IP;
    int32_t profileID;
    PEERBool gotIPAndProfileID;
    int32_t flags[3];
    uint32_t lastPingSend;
    uint32_t lastPingRecv;
    uint32_t lastXping;
    PEERBool waitingForPing;
    int32_t pingsReturned;
    int32_t pingsLostConsecutive;
    int32_t pingAverage;
    int32_t pingHistory[4];
    int32_t pingHistoryNum;
    int32_t numPings;
    PEERBool xpingSent;
    PEERBool inPingRoom;
    PEERBool inXpingRoom;
    PEERBool mustPing;
};

}

}
