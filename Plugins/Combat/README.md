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
- 