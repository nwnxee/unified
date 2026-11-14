@page combat Readme
@ingroup combat

Functions that expose extra functionality related to the combat engine.

Note: This plugin is not compatible with `NWNX_ON_USE_FEAT_.*` events.

### Overview

- The attack can be set as Ranged/Melee only. A script (TestRequirementsScript) can be used to further customize the feat requirements, allowing the script to block/skip the feat use.
- Static attack and damage modifiers can be set and will be applied automatically. Custom scripts will be called (if set), allowing dynamic modifiers to be applied.
- If the attack did damage, the PostDamage script will be called.

#### Flow
- UseFeat -> Skippable through TestRequirementsScript
- ResolveSpecialAttackAttackBonus -> nAttackModifier + result set in AttackModScript
- ResolveSpecialAttackDamageBonus -> nDamageModifier + result set in DamageModScript
- Resolve{Melee|Ranged}SpecialAttack -> Calls PostDamageScript if damage > 0

#### Examples
##### on_load script
```
    NWNX_Combat_SetSpecialAttackInfo(FEAT_KNOCKDOWN, 0, 0, 0, "test_kd", "test_kd", "test_kd", "test_kd");
    NWNX_Combat_SetSpecialAttackInfo(FEAT_IMPROVED_KNOCKDOWN, 0, 0, 0, "test_kd", "test_kd", "test_kd", "test_kd");
```

##### test_kd
```
#include "nwnx_combat"

void main()
{
    int nScriptType = NWNX_Combat_GetScriptType();
    int nFeat = NWNX_Combat_GetCurrentFeat();
    object oTarget = NWNX_Combat_GetFeatTarget();
    switch(nScriptType) {
    case NWNX_COMBAT_SCRIPT_TYPE_REQUIREMENTS:
        SendMessageToPC(OBJECT_SELF, "Requirements script. Feat: " + IntToString(nFeat) + ". Target: " + GetName(oTarget));
        return;
    case NWNX_COMBAT_SCRIPT_TYPE_ATTACK_MODIFIER:
        SendMessageToPC(OBJECT_SELF, "Attack modifier script. Adding 15 AB");
        NWNX_Combat_SetReturnValue(15);
        return;
    case NWNX_COMBAT_SCRIPT_TYPE_DAMAGE_MODIFIER:
        SendMessageToPC(OBJECT_SELF, "Damage modifier script. Adding 50 damage");
        NWNX_Combat_SetReturnValue(50);
        return;
    case NWNX_COMBAT_SCRIPT_TYPE_POST_DAMAGE:
        SendMessageToPC(OBJECT_SELF, "PostDamage script");
        return;
    }
}
```
