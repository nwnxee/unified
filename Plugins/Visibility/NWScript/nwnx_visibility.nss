/// @addtogroup visibility Visibility
/// @brief Functions to manipulate visibility of objects both globally or per observer
/// @{
/// @file nwnx_visibility.nss
#include "nwnx"

const string NWNX_Visibility = "NWNX_Visibility"; ///< @private

/// @name Visibility Types
/// @anchor vis_types
/// @{
const int NWNX_VISIBILITY_DEFAULT                 = -1;
const int NWNX_VISIBILITY_VISIBLE                 = 0;
const int NWNX_VISIBILITY_HIDDEN                  = 1;
const int NWNX_VISIBILITY_DM_ONLY                 = 2;
const int NWNX_VISIBILITY_ALWAYS_VISIBLE          = 3;
const int NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY  = 4;
///@}

/// @brief Queries the existing visibility override for given (oPlayer, oTarget) pair.
///        If oPlayer is OBJECT_INVALID, the global visibility override will be returned.
///
///  * NWNX_VISIBILITY_DEFAULT = Override not set.
///  * NWNX_VISIBILITY_VISIBLE = Target is visible but still adheres to default visibility rules.
///  * NWNX_VISIBILITY_HIDDEN  = Target is always hidden.
///  * NWNX_VISIBILITY_DM_ONLY = Target is only visible to DMs but still adheres to default visibility rules.
///  * NWNX_VISIBILITY_ALWAYS_VISIBLE = Target is always visible in all circumstances.
///  * NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY = Target is always visible only to DMs in all circumstances.
///
/// @param oPlayer The PC Object or OBJECT_INVALID.
/// @param oTarget The object for which we're querying the visibility override.
/// @return The @ref vis_types "Visibility Type".
int NWNX_Visibility_GetVisibilityOverride(object oPlayer, object oTarget);

/// @brief Overrides the default visibility rules about how oPlayer perceives oTarget.
///        If oPlayer is OBJECT_INVALID, the global visibility override will be set.
///
///  * NWNX_VISIBILITY_DEFAULT = Remove a set override.
///  * NWNX_VISIBILITY_VISIBLE = Target is visible but still adheres to default visibility rules.
///  * NWNX_VISIBILITY_HIDDEN  = Target is always hidden.
///  * NWNX_VISIBILITY_DM_ONLY = Target is only visible to DMs but still adheres to default visibility rules.
///  * NWNX_VISIBILITY_ALWAYS_VISIBLE = Target is always visible in all circumstances.
///  * NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY = Target is always visible to DMs in all circumstances.
///
/// @warning Setting too many objects to ALWAYS_VISIBLE in an area will impact the performance of your players. Use sparingly.
///
/// @note Player state overrides the global state which means if a global state is set
/// to NWNX_VISIBILITY_HIDDEN or NWNX_VISIBILITY_DM_ONLY but the player's state is
/// set to NWNX_VISIBILITY_VISIBLE for the target, the object will be visible to the player.
///
/// @param oPlayer The PC Object or OBJECT_INVALID.
/// @param oTarget The object for which we're altering the visibility.
/// @param nOverride The visibility type from @ref vis_types "Visibility Types".
void NWNX_Visibility_SetVisibilityOverride(object oPlayer, object oTarget, int nOverride);

/// @}

int NWNX_Visibility_GetVisibilityOverride(object oPlayer, object oTarget)
{
    string sFunc = "GetVisibilityOverride";

    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, oTarget);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, oPlayer);
    NWNX_CallFunction(NWNX_Visibility, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Visibility, sFunc);
}

void NWNX_Visibility_SetVisibilityOverride(object oPlayer, object oTarget, int nOverride)
{
    string sFunc = "SetVisibilityOverride";

    NWNX_PushArgumentInt(NWNX_Visibility, sFunc, nOverride);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, oTarget);
    NWNX_PushArgumentObject(NWNX_Visibility, sFunc, oPlayer);
    NWNX_CallFunction(NWNX_Visibility, sFunc);
}
