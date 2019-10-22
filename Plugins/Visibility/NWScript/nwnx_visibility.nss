/// @addtogroup visibility Visibility
/// @brief Functions to manipulate visibility of objects both globally or per observer
/// @{
/// @file nwnx_visibility.nss
#include "nwnx"

const string NWNX_Visibility = "NWNX_Visibility"; ///< @private

/// @name Visibility Types
/// @anchor vis_types
/// @{
const int NWNX_VISIBILITY_DEFAULT   = -1;
const int NWNX_VISIBILITY_VISIBLE   = 0;
const int NWNX_VISIBILITY_HIDDEN    = 1;
const int NWNX_VISIBILITY_DM_ONLY   = 2;
///@}

/// @brief Queries the existing visibility override for given (player, target) pair.
///
/// If player is OBJECT_INVALID, the global visibility override will be returned
/// * Player == VALID -> returns:
///  * NWNX_VISIBILITY_DEFAULT = Player override not set
///  * NWNX_VISIBILITY_VISIBLE = Target is always visible for player
///  * NWNX_VISIBILITY_HIDDEN  = Target is always hidden for player
/// * Player == OBJECT_INVALID -> returns:
///  * NWNX_VISIBILITY_DEFAULT = Global override not set
///  * NWNX_VISIBILITY_VISIBLE = Target is globally visible
///  * NWNX_VISIBILITY_HIDDEN  = Target is globally hidden
///  * NWNX_VISIBILITY_DM_ONLY = Target is only visible to DMs
/// @param player The PC Object or OBJECT_INVALID.
/// @param target The object for which we're querying the visibility.
/// @return The @ref vis_types "Visibility Type".
int NWNX_Visibility_GetVisibilityOverride(object player, object target);

/// @brief Overrides the default visibility rules about how player perceives the target object.
///
/// If player is OBJECT_INVALID, the global visibility override will be set
/// * Player == VALID -> override:
///  * NWNX_VISIBILITY_DEFAULT = Remove the player override
///  * NWNX_VISIBILITY_VISIBLE = Target is always visible for player
///  * NWNX_VISIBILITY_HIDDEN  = Target is always hidden for player
/// * Player == OBJECT_INVALID -> override:
///  * NWNX_VISIBILITY_DEFAULT = Remove the global override
///  * NWNX_VISIBILITY_VISIBLE = Target is globally visible
///  * NWNX_VISIBILITY_HIDDEN  = Target is globally hidden
///  * NWNX_VISIBILITY_DM_ONLY = Target is only visible to DMs
///
/// @note Player state overrides the global state which means if a global state is set
/// to NWNX_VISIBILITY_HIDDEN or NWNX_VISIBILITY_DM_ONLY but the player's state is
/// set to NWNX_VISIBILITY_VISIBLE for the target, the object will be visible to the player.
/// @param player The PC Object or OBJECT_INVALID.
/// @param target The object for which we're altering the visibility.
/// @param override The visibility type from @ref vis_types "Visibility Types".
void NWNX_Visibility_SetVisibilityOverride(object player, object target, int override);

/// @}

int NWNX_Visibility_GetVisibilityOverride(object player, object target)
{
    string sFunc = "GetVisibilityOverride";

    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, player);
    NWNX_CallFunction(NWNX_Visibility, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Visibility, sFunc);
}

void NWNX_Visibility_SetVisibilityOverride(object player, object target, int override)
{
    string sFunc = "SetVisibilityOverride";

    NWNX_PushArgumentInt(NWNX_Visibility, sFunc, override);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, player);
    NWNX_CallFunction(NWNX_Visibility, sFunc);
}
