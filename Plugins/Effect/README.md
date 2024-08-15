@page effect Readme
@ingroup effect 

Provide various utility functions to manipulate builtin effect type

## Environment Variables

### NWNX_EFFECT_EXTEND_DURATION_TYPE = true/false

Allow ApplyEffectToObject to apply internal duration types; simply give the new constants as described
below to the function.

To correctly read and iterate these functions, you need to use:

* NWNX_Effect_GetIsEffectValid()
* NWNX_Effect_GetAppliedEffectCount()
* NWNX_Effect_GetAppliedEffect()

The builtin functions (GetFirstEffect, GetNextEffect, GetIsEffectValid) do not expose internal effect types.

#### const int DURATION_TYPE_EQUIPPED = 3;

This effect gets automatically removed when the item that created it gets unequipped.

For this to work, the effect creator needs to be a valid equipped item; you can set this either by
spawning the effect from the item handler, or by using SetEffectCreator().

Behaviour without a equipped item in the effect creator slot is undefined.

#### const int DURATION_TYPE_INNATE = 4;

This is used by the game to represent things like racial and feat effects, as well as movement speed
adjustments.
