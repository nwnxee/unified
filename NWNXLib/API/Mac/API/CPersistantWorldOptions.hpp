#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CPersistantWorldOptions
{
    int32_t bVaultCharsOnly;
    int32_t bSaveCharsInSaveGame;
    int32_t bSuppressBaseServerVault;
    int32_t bStickyPlayerNames;
    int32_t bServerVaultByPlayerName;
};

}

}
