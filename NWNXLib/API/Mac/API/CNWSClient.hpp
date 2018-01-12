#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSDungeonMaster;
struct CNWSPlayer;

struct CNWSClient
{
    void** m_vtable;
    uint32_t m_nPlayerID;
    int32_t m_nLanguage;

    // The below are auto generated stubs.
    CNWSClient() = default;
    CNWSClient(const CNWSClient&) = default;
    CNWSClient& operator=(const CNWSClient&) = default;

    CNWSClient(uint32_t);
    ~CNWSClient();
    CNWSDungeonMaster* AsNWSDungeonMaster();
    CNWSPlayer* AsNWSPlayer();
};

void CNWSClient__CNWSClientCtor__0(CNWSClient* thisPtr, uint32_t);
void CNWSClient__CNWSClientDtor__0(CNWSClient* thisPtr);
CNWSDungeonMaster* CNWSClient__AsNWSDungeonMaster(CNWSClient* thisPtr);
CNWSPlayer* CNWSClient__AsNWSPlayer(CNWSClient* thisPtr);

}

}
