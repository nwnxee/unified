#include "nwnx"

const int NWNX_VISIBILITY_DEFAULT   = -1;
const int NWNX_VISIBILITY_VISIBLE   = 0;
const int NWNX_VISIBILITY_HIDDEN    = 1;

// Queries the existing visibility override for given (player, target) pair
// If player is OBJECT_INVALID, the global visibility override will be returned
//
// Returns:
//   NWNX_VISIBILITY_DEFAULT = Player override not set
//   NWNX_VISIBILITY_VISIBLE = Target is visible
//   NWNX_VISIBILITY_HIDDEN  = Target is hidden
int NWNX_Visibility_GetVisibilityOverride(object player, object target);

// Overrides the default visibility rules about how player perceives the target object
// If player is OBJECT_INVALID, the global visibility override will be set
//
// override:
//   NWNX_VISIBILITY_DEFAULT = Remove the player override
//   NWNX_VISIBILITY_VISIBLE = Target is visible
//   NWNX_VISIBILITY_HIDDEN  = Target is hidden
//
// Note:
// Player state overrides the global state which means if a global state is set
// to NWNX_VISIBILITY_HIDDEN but the player's state is set to NWNX_VISIBILITY_VISIBLE
// for the target, the object will be visible to the player
void NWNX_Visibility_SetVisibilityOverride(object player, object target, int override);


const string NWNX_Visibility = "NWNX_Visibility";


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
