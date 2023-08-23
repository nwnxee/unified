@page events Readme
@ingroup events 

Provides an interface for plugins to create event-based systems, and exposes some events through that interface.

## Custom Item Property Example Script
```c
#include "nwnx_events"
#include "nwnx_effect"
void main()
{
    string sEvent = NWNX_Events_GetCurrentEvent();
    object oCreature = StringToObject(NWNX_Events_GetEventData("CREATURE"));
    int nProperty = StringToInt(NWNX_Events_GetEventData("PROPERTY"));
    int bLoading = StringToInt(NWNX_Events_GetEventData("LOADING_GAME"));

    if (sEvent == "NWNX_ON_ITEMPROPERTY_EFFECT_APPLIED_BEFORE")
    {
        if (nProperty == ITEM_PROPERTY_ENLARGE)// An example property
        {
            // Since the VT gets saved to the .bic, we only apply it when the item gets equipped by the player,
            // not when it gets re-applied due to loading into the game with the item already equipped.
            if (!bLoading)
            {
                SetObjectVisualTransform(oCreature, OBJECT_VISUAL_TRANSFORM_SCALE, 2.0f,
                    OBJECT_VISUAL_TRANSFORM_LERP_EASE_IN, 1.0f);
            }

            // We do need to reapply this glow every time since DURATION_TYPE_EQUIPPED effects are not stored in the TURD.
            ApplyEffectToObject(DURATION_TYPE_EQUIPPED, EffectVisualEffect(VFX_DUR_GLOW_GREEN), oCreature);
        }
        else if (nProperty == ITEM_PROPERTY_ABILITY_BONUS)
        {
            int nSubType = StringToInt(NWNX_Events_GetEventData("SUBTYPE"));
            int nCostTableValue = StringToInt(NWNX_Events_GetEventData("COST_TABLE_VALUE"));

            // We'll turn any ability bonuses into ability decreases!
            // When examining the item it'll still display a bonus but the actual effect will be a decrease.
            ApplyEffectToObject(DURATION_TYPE_EQUIPPED, EffectAbilityDecrease(nSubType, nCostTableValue), oCreature);
            // Skip the application of the basegame effect.
            NWNX_Events_SkipEvent();
        }
    }
    else if(sEvent == "NWNX_ON_ITEMPROPERTY_EFFECT_REMOVED_BEFORE")
    {
        if (nProperty == ITEM_PROPERTY_ENLARGE)// An example property.
        {
            // The player unequipped the item with this property so we reset the VT.
            SetObjectVisualTransform(oCreature, OBJECT_VISUAL_TRANSFORM_SCALE, 1.0f,
                OBJECT_VISUAL_TRANSFORM_LERP_EASE_OUT, 1.0f);

            // No need to remove the glow, unequipping the item will automatically remove it, magic!
        }
        else if (nProperty == ITEM_PROPERTY_ABILITY_BONUS)
        {
            // No need to do anything here.
        }
    }
}
```
