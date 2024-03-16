/// @addtogroup vault Vault
/// @brief Provides various character/servervault related functions.
/// @{
/// @file nwnx_vault.nss
#include "nwnx"

const string NWNX_Vault = "NWNX_Vault"; ///< @private

/// @name Vault Event Types
/// @anchor vault_event_types
/// @{
const int NWNX_VAULT_EVENT_TYPE_CREATED = 1;
const int NWNX_VAULT_EVENT_TYPE_LOGIN = 2;
const int NWNX_VAULT_EVENT_TYPE_LOGOUT = 3;
const int NWNX_VAULT_EVENT_TYPE_MIGRATED = 4;
/// @}

/// @brief Switch oPlayer's character to another one.
/// @warning THIS FUNCTION IS EXPERIMENTAL, BACKUP YOUR SERVERVAULT BEFORE EVEN ATTEMPTING TO USE THIS.
/// @note If something goes catastrophically wrong the player will be disconnected.
/// @param oPlayer The player.
/// @param nCharacterId The Id of the character in the server vault database.
/// @param bSaveCurrentCharacter TRUE to save the current character.
void NWNX_Vault_SwitchCharacter(object oPlayer, int nCharacterId, int bSaveCurrentCharacter = TRUE);

// @brief Get oPlayer's character as json.
// @param oPlayer A player character.
// @return The player character as json or JsonNull().
json NWNX_Vault_GetCharacterJson(object oPlayer);

/// @}

void NWNX_Vault_SwitchCharacter(object oPlayer, int nCharacterId, int bSaveCurrentCharacter = TRUE)
{
    NWNX_PushArgumentInt(bSaveCurrentCharacter);
    NWNX_PushArgumentInt(nCharacterId);
    NWNX_PushArgumentObject(oPlayer);
    NWNX_CallFunction(NWNX_Vault, "SwitchCharacter");
}

json NWNX_Vault_GetCharacterJson(object oPlayer)
{
    NWNX_PushArgumentObject(oPlayer);
    NWNX_CallFunction(NWNX_Vault, "GetCharacterJson");
    return NWNX_GetReturnValueJson();
}
