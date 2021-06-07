/// @addtogroup creature Creature
/// @brief Functions exposing additional creature properties.
/// @{
/// @file nwnx_creature.nss
#include "nwnx"

const string NWNX_Creature = "NWNX_Creature"; ///< @private

/// @name Creature Movement Rates
/// @anchor creature_movement_rates
///
/// The various types of movement rates.
/// @{
const int NWNX_CREATURE_MOVEMENT_RATE_PC        = 0;
const int NWNX_CREATURE_MOVEMENT_RATE_IMMOBILE  = 1;
const int NWNX_CREATURE_MOVEMENT_RATE_VERY_SLOW = 2;
const int NWNX_CREATURE_MOVEMENT_RATE_SLOW      = 3;
const int NWNX_CREATURE_MOVEMENT_RATE_NORMAL    = 4;
const int NWNX_CREATURE_MOVEMENT_RATE_FAST      = 5;
const int NWNX_CREATURE_MOVEMENT_RATE_VERY_FAST = 6;
const int NWNX_CREATURE_MOVEMENT_RATE_DEFAULT   = 7;
const int NWNX_CREATURE_MOVEMENT_RATE_DM_FAST   = 8;
/// @}

/// @name Creature Movement Types
/// @anchor creature_movement_types
///
/// The various types of movement types.
/// @{
const int NWNX_CREATURE_MOVEMENT_TYPE_STATIONARY      = 0;
const int NWNX_CREATURE_MOVEMENT_TYPE_WALK            = 1;
const int NWNX_CREATURE_MOVEMENT_TYPE_RUN             = 2;
const int NWNX_CREATURE_MOVEMENT_TYPE_SIDESTEP        = 3;
const int NWNX_CREATURE_MOVEMENT_TYPE_WALK_BACKWARDS  = 4;
/// @}

/// @name Cleric Domains
/// @anchor cleric_domains
///
/// The clerical domains.
/// @{
const int NWNX_CREATURE_CLERIC_DOMAIN_AIR         = 0;
const int NWNX_CREATURE_CLERIC_DOMAIN_ANIMAL      = 1;
const int NWNX_CREATURE_CLERIC_DOMAIN_DEATH       = 3;
const int NWNX_CREATURE_CLERIC_DOMAIN_DESTRUCTION = 4;
const int NWNX_CREATURE_CLERIC_DOMAIN_EARTH       = 5;
const int NWNX_CREATURE_CLERIC_DOMAIN_EVIL        = 6;
const int NWNX_CREATURE_CLERIC_DOMAIN_FIRE        = 7;
const int NWNX_CREATURE_CLERIC_DOMAIN_GOOD        = 8;
const int NWNX_CREATURE_CLERIC_DOMAIN_HEALING     = 9;
const int NWNX_CREATURE_CLERIC_DOMAIN_KNOWLEDGE   = 10;
const int NWNX_CREATURE_CLERIC_DOMAIN_MAGIC       = 13;
const int NWNX_CREATURE_CLERIC_DOMAIN_PLANT       = 14;
const int NWNX_CREATURE_CLERIC_DOMAIN_PROTECTION  = 15;
const int NWNX_CREATURE_CLERIC_DOMAIN_STRENGTH    = 16;
const int NWNX_CREATURE_CLERIC_DOMAIN_SUN         = 17;
const int NWNX_CREATURE_CLERIC_DOMAIN_TRAVEL      = 18;
const int NWNX_CREATURE_CLERIC_DOMAIN_TRICKERY    = 19;
const int NWNX_CREATURE_CLERIC_DOMAIN_WAR         = 20;
const int NWNX_CREATURE_CLERIC_DOMAIN_WATER       = 21;
/// @}

/// @name Bonus Types
/// @anchor bonus_types
///
/// Used with NWNX_Creature_GetTotalEffectBonus() these are the types of temporary bonuses from effects.
/// @{
const int NWNX_CREATURE_BONUS_TYPE_ATTACK        = 1;
const int NWNX_CREATURE_BONUS_TYPE_DAMAGE        = 2;
const int NWNX_CREATURE_BONUS_TYPE_SAVING_THROW  = 3;
const int NWNX_CREATURE_BONUS_TYPE_ABILITY       = 4;
const int NWNX_CREATURE_BONUS_TYPE_SKILL         = 5;
const int NWNX_CREATURE_BONUS_TYPE_TOUCH_ATTACK  = 6;
/// @}

/// @struct NWNX_Creature_SpecialAbility
/// @brief A creature special ability.
struct NWNX_Creature_SpecialAbility
{
    int id; ///< The spell id
    int ready; ///< Whether it can be used
    int level; ///< The level of the ability
};

/// @struct NWNX_Creature_MemorisedSpell
/// @brief A memorised spell structure.
struct NWNX_Creature_MemorisedSpell
{
    int id; ///< Spell ID
    int ready; ///< Whether the spell can be cast
    int meta; ///< Metamagic type, if any
    int domain; ///< Clerical domain, if any
};

/// @brief Gives the creature a feat.
/// @param creature The creature object.
/// @param feat The feat id.
/// @remark Consider also using NWNX_Creature_AddFeatByLevel() to properly allocate the feat to a level
void NWNX_Creature_AddFeat(object creature, int feat);

/// @brief Gives the creature a feat assigned at a level
/// @param creature The creature object.
/// @param feat The feat id.
/// @param level The level they gained the feat.
/// @remark Adds the feat to the stat list at the provided level.
void NWNX_Creature_AddFeatByLevel(object creature, int feat, int level);

/// @brief Removes a feat from a creature.
/// @param creature The creature object.
/// @param feat The feat id.
void NWNX_Creature_RemoveFeat(object creature, int feat);

/// @brief Determines if the creature knows a feat.
/// @note This differs from native @nwn{GetHasFeat} which returns FALSE if the feat has no more uses per day.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return TRUE if the creature has the feat, regardless if they have any usages left or not.
int NWNX_Creature_GetKnowsFeat(object creature, int feat);

/// @brief Returns the count of feats learned at the provided level.
/// @param creature The creature object.
/// @param level The level.
/// @return The count of feats.
int NWNX_Creature_GetFeatCountByLevel(object creature, int level);

/// @brief Returns the feat learned at the level and index.
/// @param creature The creature object.
/// @param level The level.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetFeatCountByLevel().
/// @return The feat id at the index.
int NWNX_Creature_GetFeatByLevel(object creature, int level, int index);

/// @brief Returns the creature level where the specified feat was learned.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return The character level that the specified feat was granted, otherwise 0 if the creature does not have this feat.
int NWNX_Creature_GetFeatGrantLevel(object creature, int feat);

/// @brief Get the total number of feats known by creature.
/// @param creature The creature object.
/// @return The total feat count for the creature.
int NWNX_Creature_GetFeatCount(object creature);

/// @brief Returns the creature's feat at a given index
/// @param creature The creature object.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetFeatCount();
/// @return The feat id at the index.
int NWNX_Creature_GetFeatByIndex(object creature, int index);

/// @brief Gets if creature meets feat requirements.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return TRUE if creature meets all requirements to take given feat
int NWNX_Creature_GetMeetsFeatRequirements(object creature, int feat);

/// @brief Gets the count of special abilities of the creature.
/// @param creature The creature object.
/// @return The total special ability count.
int NWNX_Creature_GetSpecialAbilityCount(object creature);

/// @brief Returns the creature's special ability at a given index.
/// @param creature The creature object.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount().
/// @return An NWNX_Creature_SpecialAbility struct.
struct NWNX_Creature_SpecialAbility NWNX_Creature_GetSpecialAbility(object creature, int index);

/// @brief Adds a special ability to a creature.
/// @param creature The creature object.
/// @param ability An NWNX_Creature_SpecialAbility struct.
void NWNX_Creature_AddSpecialAbility(object creature, struct NWNX_Creature_SpecialAbility ability);

/// @brief Removes a special ability from a creature.
/// @param creature The creature object.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount().
void NWNX_Creature_RemoveSpecialAbility(object creature, int index);

/// @brief Sets a special ability at the index for the creature.
/// @param creature The creature object.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetSpecialAbilityCount().
/// @param ability An NWNX_Creature_SpecialAbility struct.
void NWNX_Creature_SetSpecialAbility(object creature, int index, struct NWNX_Creature_SpecialAbility ability);

/// @brief Get the class taken by the creature at the provided level.
/// @param creature The creature object.
/// @param level The level.
/// @return The class id.
int NWNX_Creature_GetClassByLevel(object creature, int level);

/// @brief Sets the base AC for the creature.
/// @param creature The creature object.
/// @param ac The base AC to set for the creature.
void NWNX_Creature_SetBaseAC(object creature, int ac);

/// @brief Get the base AC for the creature.
/// @param creature The creature object.
/// @return The base AC.
int NWNX_Creature_GetBaseAC(object creature);

/// @brief Sets the ability score of the creature to the provided value.
/// @note Does not apply racial bonuses/penalties.
/// @param creature The creature object.
/// @param ability The ability constant.
/// @param value The value to set.
void NWNX_Creature_SetRawAbilityScore(object creature, int ability, int value);

/// @brief Gets the ability score of the creature.
/// @note Does not apply racial bonuses/penalties.
/// @param creature The creature object.
/// @param ability The ability constant.
/// @return The ability score.
int NWNX_Creature_GetRawAbilityScore(object creature, int ability);

/// @brief Adjusts the ability score of a creature.
/// @note Does not apply racial bonuses/penalties.
/// @param creature The creature object.
/// @param ability The ability constant.
/// @param modifier The modifier value.
void NWNX_Creature_ModifyRawAbilityScore(object creature, int ability, int modifier);

/// @brief Gets the raw ability score a polymorphed creature had prior to polymorphing.
/// @note For Strength, Dexterity and Constitution only.
/// @param creature The creature object.
/// @param ability The ability constant.
/// @return The raw ability score.
int NWNX_Creature_GetPrePolymorphAbilityScore(object creature, int ability);

/// @brief Gets the count of memorised spells for a creature's class at a level.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @return The memorised spell count.
int NWNX_Creature_GetMemorisedSpellCountByLevel(object creature, int class, int level);

/// @brief Gets the memorised spell at a class level's index.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel().
/// @return An NWNX_Creature_MemorisedSpell() struct.
struct NWNX_Creature_MemorisedSpell NWNX_Creature_GetMemorisedSpell(object creature, int class, int level, int index);

/// @brief Sets the memorised spell at a class level's index.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel().
/// @param spell An NWNX_Creature_MemorisedSpell() struct.
void NWNX_Creature_SetMemorisedSpell(object creature, int class, int level, int index, struct NWNX_Creature_MemorisedSpell spell);

/// @brief Gets the remaining spell slots (innate casting) at a class level's index.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @return The remaining spell slot count.
int NWNX_Creature_GetRemainingSpellSlots(object creature, int class, int level);

/// @brief Sets the remaining spell slots (innate casting) at a class level.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param slots The remaining spell slots to set.
void NWNX_Creature_SetRemainingSpellSlots(object creature, int class, int level, int slots);

/// @brief Gets the maximum spell slots (innate casting) at a class level.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @return The maximum spell slot count.
int NWNX_Creature_GetMaxSpellSlots(object creature, int class, int level);

/// @brief Gets the known spell count (innate casting) at a class level.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @return The known spell count.
int NWNX_Creature_GetKnownSpellCount(object creature, int class, int level);

/// @brief Gets the known spell at a class level's index.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetKnownSpellCount().
/// @return The spell id.
int NWNX_Creature_GetKnownSpell(object creature, int class, int level, int index);

/// @brief Add a spell to a creature's spellbook for class.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param spellId The spell to remove.
void NWNX_Creature_AddKnownSpell(object creature, int class, int level, int spellId);

/// @brief Remove a spell from creature's spellbook for class.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param spellId The spell to remove.
void NWNX_Creature_RemoveKnownSpell(object creature, int class, int level, int spellId);

/// @brief Clear a specific spell from the creature's spellbook for class
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param spellId The spell to clear.
void NWNX_Creature_ClearMemorisedKnownSpells(object creature, int class, int spellId);

/// @brief Clear the memorised spell of the creature for the class, level and index.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param level The spell level.
/// @param index The index. Index bounds: 0 <= index < NWNX_Creature_GetMemorisedSpellCountByLevel().
void NWNX_Creature_ClearMemorisedSpell(object creature, int class, int level, int index);

/// @brief Gets the maximum hit points for creature for level.
/// @param creature The creature object.
/// @param level The level.
/// @return The maximum hit points a creature can have for the class at the provided level.
int NWNX_Creature_GetMaxHitPointsByLevel(object creature, int level);

/// @brief Sets the maximum hit points for creature.
/// @param creature The creature object.
/// @param level The level.
/// @param value The amount to set the max hit points.
void NWNX_Creature_SetMaxHitPointsByLevel(object creature, int level, int value);

/// @brief Set creature's movement rate.
/// @param creature The creature object.
/// @param rate The movement rate.
void NWNX_Creature_SetMovementRate(object creature, int rate);

/// @brief Returns the creature's current movement rate factor.
/// @remark Base movement rate factor is 1.0.
/// @param creature The creature object.
/// @return The current movement rate factor.
float NWNX_Creature_GetMovementRateFactor(object creature);

/// @brief Sets the creature's current movement rate factor.
/// @note Base movement rate factor is 1.0.
/// @param creature The creature object.
/// @param rate The rate to set.
void NWNX_Creature_SetMovementRateFactor(object creature, float rate);

/// @brief Sets the creature's maximum movement rate cap.
/// @note Default movement rate cap is 1.5.
/// @param creature The creature object.
/// @param cap The cap to set.
void NWNX_Creature_SetMovementRateFactorCap(object creature, float cap);

/// @brief Returns the creature's current movement type
/// @param creature The creature object.
/// @return An NWNX_CREATURE_MOVEMENT_TYPE_* constant.
int NWNX_Creature_GetMovementType(object creature);

/// @brief Sets the maximum movement rate a creature can have while walking (not running)
/// @remark This allows a creature with movement speed enhancements to walk at a normal rate.
/// @param creature The creature object.
/// @param fWalkRate The walk rate to apply. Setting the value to -1.0 will remove the cap.
/// Default value is 2000.0, which is the base human walk speed.
void NWNX_Creature_SetWalkRateCap(object creature, float fWalkRate = 2000.0f);

/// @brief Set creature's raw good/evil alignment value.
/// @param creature The creature object.
/// @param value The value to set.
void NWNX_Creature_SetAlignmentGoodEvil(object creature, int value);

/// @brief Set creature's raw law/chaos alignment value.
/// @param creature The creature object.
/// @param value The value to set.
void NWNX_Creature_SetAlignmentLawChaos(object creature, int value);

/// @brief Get the soundset index for creature.
/// @param creature The creature object.
/// @return The soundset used by the creature.
int NWNX_Creature_GetSoundset(object creature);

/// @brief Set the soundset index for creature.
/// @param creature The creature object.
/// @param soundset The soundset index.
void NWNX_Creature_SetSoundset(object creature, int soundset);

/// @brief Set the base ranks in a skill for creature
/// @param creature The creature object.
/// @param skill The skill id.
/// @param rank The value to set as the skill rank.
void NWNX_Creature_SetSkillRank(object creature, int skill, int rank);

/// @brief Set the class ID in a particular position for a creature.
/// @param creature The creature object.
/// @param position Should be 0, 1, or 2 depending on how many classes the creature
/// has and which is to be modified.
/// @param classID A valid ID number in classes.2da and between 0 and 255.
void NWNX_Creature_SetClassByPosition(object creature, int position, int classID);

/// @brief Set the level at the given position for a creature.
/// @note A creature should already have a class in that position.
/// @param creature The creature object.
/// @param position Should be 0, 1, or 2 depending on how many classes the creature
/// has and which is to be modified.
/// @param level The level to set.
void NWNX_Creature_SetLevelByPosition(object creature, int position, int level);

/// @brief Set creature's base attack bonus (BAB).
/// @note Modifying the BAB will also affect the creature's attacks per round and its
/// eligibility for feats, prestige classes, etc.
/// @param creature The creature object.
/// @param bab The BAB value. Should be between 0 and 254. Setting BAB to 0 will cause the
/// creature to revert to its original BAB based on its classes and levels. A creature can
/// never have an actual BAB of zero.
/// @remark The base game has a function @nwn{SetBaseAttackBonus}, which actually sets
/// the bonus attacks per round for a creature, not the BAB.
void NWNX_Creature_SetBaseAttackBonus(object creature, int bab);

/// @brief Gets the creatures current attacks per round (using equipped weapon).
/// @param creature The creature object.
/// @param bBaseAPR If TRUE, will return the base attacks per round, based on BAB and
/// equipped weapons, regardless of overrides set by calls to @nwn{SetBaseAttackBonus} builtin function.
/// @return The attacks per round.
int NWNX_Creature_GetAttacksPerRound(object creature, int bBaseAPR = FALSE);

/// @brief Sets the creature gender.
/// @param creature The creature object.
/// @param gender The GENDER_ constant.
void NWNX_Creature_SetGender(object creature, int gender);

/// @brief Restore all creature feat uses.
/// @param creature The creature object.
void NWNX_Creature_RestoreFeats(object creature);

/// @brief Restore all creature special ability uses.
/// @param creature The creature object.
void NWNX_Creature_RestoreSpecialAbilities(object creature);

/// @brief Restore all creature spells per day for given level.
/// @param creature The creature object.
/// @param level The level to restore. If -1, all spells are restored.
void NWNX_Creature_RestoreSpells(object creature, int level = -1);

/// @brief Restore uses for all items carried by the creature.
/// @param creature The creature object.
void NWNX_Creature_RestoreItems(object creature);

/// @brief Sets the creature size.
/// @param creature The creature object.
/// @param size Use CREATURE_SIZE_* constants.
void NWNX_Creature_SetSize(object creature, int size);

/// @brief Gets the creature's remaining unspent skill points.
/// @param creature The creature object.
/// @return The remaining unspent skill points.
int NWNX_Creature_GetSkillPointsRemaining(object creature);

/// @brief Sets the creature's remaining unspent skill points.
/// @param creature The creature object.
/// @param skillpoints The value to set.
void NWNX_Creature_SetSkillPointsRemaining(object creature, int skillpoints);

/// @brief Sets the creature's racial type
/// @param creature The creature object.
/// @param racialtype The racial type to set.
void NWNX_Creature_SetRacialType(object creature, int racialtype);

/// @brief Sets the creature's gold without sending a feedback message
/// @param creature The creature object.
/// @param gold The amount of gold to set for their creature.
void NWNX_Creature_SetGold(object creature, int gold);

/// @brief Sets corpse decay time in milliseconds
/// @param creature The creature object.
/// @param nDecayTime The corpse decay time.
void NWNX_Creature_SetCorpseDecayTime(object creature, int nDecayTime);

/// @brief Gets the creature's base save.
/// @param creature The creature object.
/// @param which One of SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
/// @return The base save value.
/// @note This will include any modifiers set in the toolset.
int NWNX_Creature_GetBaseSavingThrow(object creature, int which);

/// @brief Sets the creature's base save.
/// @param creature The creature object.
/// @param which One of SAVING_THROW_FORT, SAVING_THROW_REFLEX or SAVING_THROW_WILL
/// @param value The base save value.
void NWNX_Creature_SetBaseSavingThrow(object creature, int which, int value);

/// @brief Add levels of class to the creature, bypassing all validation
/// @param creature The creature object.
/// @param class The class id.
/// @param count The amount of levels of class to add.
/// @note This will not work on player characters.
void NWNX_Creature_LevelUp(object creature, int class, int count=1);

/// @brief Remove last levels from a creature.
/// @param creature The creature object.
/// @param count The amount of levels to decrement.
/// @note This will not work on player characters.
void NWNX_Creature_LevelDown(object creature, int count=1);

/// @brief Sets the creature's challenge rating
/// @param creature The creature object.
/// @param fCR The challenge rating.
void NWNX_Creature_SetChallengeRating(object creature, float fCR);

/// @brief Returns the creature's highest attack bonus based on its own stats.
/// @note AB vs. Type and +AB on Gauntlets are excluded
/// @param creature The creature object.
/// @param isMelee
///   * TRUE: Get Melee/Unarmed Attack Bonus
///   * FALSE: Get Ranged Attack Bonus
///   * -1: Get Attack Bonus depending on the weapon creature has equipped in its right hand
///       Defaults to Melee Attack Bonus if weapon is invalid or no weapon
/// @param isTouchAttack If the attack was a touch attack.
/// @param isOffhand If the attack was with the offhand.
/// @param includeBaseAttackBonus Should the result include the base attack bonus.
/// @return The highest attack bonus.
int NWNX_Creature_GetAttackBonus(object creature, int isMelee = -1, int isTouchAttack = FALSE, int isOffhand = FALSE, int includeBaseAttackBonus = TRUE);

/// @brief Get highest level version of feat possessed by creature.
/// @remark For feats that increment in power, for example, barbarian rage.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return The highest level version of the feat.
int NWNX_Creature_GetHighestLevelOfFeat(object creature, int feat);

/// @brief Get feat remaining uses.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return The amount of remaining uses.
int NWNX_Creature_GetFeatRemainingUses(object creature, int feat);

/// @brief Get feat total uses.
/// @param creature The creature object.
/// @param feat The feat id.
/// @return The total uses.
int NWNX_Creature_GetFeatTotalUses(object creature, int feat);

/// @brief Set feat remaining uses.
/// @param creature The creature object.
/// @param feat The feat id.
/// @param uses The amount of remaining uses.
void NWNX_Creature_SetFeatRemainingUses(object creature, int feat, int uses);

/// @brief Get total effect bonus
/// @remark This exposes the actual bonus value beyond a player's base scores to attack, damage bonus, saves,
/// skills, ability scores, and touch attack provided by spells, equipment, potions etc.
/// @param creature The creature object.
/// @param bonusType A @ref bonus_types "Bonus Type"
/// @param target A target object. Used to calculate bonuses versus specific races, alignments, etc.
/// @param isElemental If a damage bonus includes elemental damage.
/// @param isForceMax If the bonus should return the maximum possible.
/// @param savetype A SAVING_THROW_* constant.
/// @param saveSpecificType A SAVING_THROW_TYPE_* constant.
/// @param skill A skill id.
/// @param abilityScore An ABILITY_* constant.
/// @param isOffhand Whether the attack is an offhand attack.
/// @return The bonus value.
int NWNX_Creature_GetTotalEffectBonus(object creature, int bonusType=NWNX_CREATURE_BONUS_TYPE_ATTACK, object target=OBJECT_INVALID, int isElemental=0, int isForceMax=0, int savetype=-1, int saveSpecificType=-1, int skill=-1, int abilityScore=-1, int isOffhand=FALSE);

/// @brief Set the original first or last name of creature
/// @param creature The creature object.
/// @param name The name to give the creature.
/// @param isLastName TRUE to change their last name, FALSE for first.
/// @note For PCs this will persist to the .bic file if saved. Requires a relog to update.
void NWNX_Creature_SetOriginalName(object creature, string name, int isLastName);

/// @brief Get the original first or last name of creature
/// @param creature The creature object.
/// @param isLastName TRUE to get last name, FALSE for first name.
/// @return The original first or last name of the creature.
string NWNX_Creature_GetOriginalName(object creature, int isLastName);

/// @brief Set creature's spell resistance
/// @param creature The creature object.
/// @param sr The spell resistance.
/// @warning This setting will be overwritten by effects and once those effects fade the old setting (typically 0) will be set.
void NWNX_Creature_SetSpellResistance(object creature, int sr);

/// @brief Set creature's animal companion creature type
/// @param creature The master creature object.
/// @param type The type from ANIMAL_COMPANION_CREATURE_TYPE_*.
void NWNX_Creature_SetAnimalCompanionCreatureType(object creature, int type);

/// @brief Set creature's familiar creature type
/// @param creature The master creature object.
/// @param type The type from FAMILIAR_CREATURE_TYPE_*.
void NWNX_Creature_SetFamiliarCreatureType(object creature, int type);

/// @brief Set creature's animal companion's name
/// @param creature The master creature object.
/// @param name The name to give their animal companion.
void NWNX_Creature_SetAnimalCompanionName(object creature, string name);

/// @brief Set creature's familiar's name
/// @param creature The master creature object.
/// @param name The name to give their familiar.
void NWNX_Creature_SetFamiliarName(object creature, string name);

/// @brief Get whether the creature can be disarmed.
/// @param creature The creature object.
/// @return TRUE if the creature can be disarmed.
int NWNX_Creature_GetDisarmable(object creature);

/// @brief Set whether a creature can be disarmed.
/// @param creature The creature object.
/// @param disarmable Set to TRUE if the creature can be disarmed.
void NWNX_Creature_SetDisarmable(object creature, int disarmable);

/// @brief Gets one of creature's domains.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param index The first or second domain.
/// @deprecated Use GetDomain(). This will be removed in future NWNX releases.
int NWNX_Creature_GetDomain(object creature, int class, int index);

/// @brief Sets one of creature's domains.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param index The first or second domain.
/// @param domain The domain constant to set.
void NWNX_Creature_SetDomain(object creature, int class, int index, int domain);

/// @brief Gets the creature's specialist school.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @deprecated Use GetSpecialization(). This will be removed in future NWNX releases.
int NWNX_Creature_GetSpecialization(object creature, int class);

/// @brief Sets creature's specialist school.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param school The school constant.
void NWNX_Creature_SetSpecialization(object creature, int class, int school);

/// @brief Sets oCreatures faction to be the faction with id nFactionId.
/// @param oCreature The creature.
/// @param nFactionId The faction id we want the creature to join.
void NWNX_Creature_SetFaction(object oCreature, int nFactionId);

/// @brief Gets the faction id from oCreature
/// @param oCreature the creature we wish to query against
/// @return faction id as an integer, -1 when used against invalid creature or invalid object.
int NWNX_Creature_GetFaction(object oCreature);

/// @brief Get whether a creature is flat-footed.
/// @param oCreature The creature object.
/// @return TRUE if the creature is flat-footed.
int NWNX_Creature_GetFlatFooted(object oCreature);

/// @brief Serialize oCreature's quickbar to a base64 string
/// @param oCreature The creature.
/// @return A base64 string representation of oCreature's quickbar.
string NWNX_Creature_SerializeQuickbar(object oCreature);

/// @brief Deserialize sSerializedQuickbar for oCreature
/// @param oCreature The creature.
/// @param sSerializedQuickbar A base64 string of a quickbar
/// @return TRUE on success
int NWNX_Creature_DeserializeQuickbar(object oCreature, string sSerializedQuickbar);

/// @brief Sets a caster level modifier for oCreature
/// @param oCreature the target creature
/// @param nClass the class that this modifier will apply to
/// @param nModifier the modifier to apply
/// @param bPersist whether the modifier should be persisted to the .bic file if applicable
void NWNX_Creature_SetCasterLevelModifier(object oCreature, int nClass, int nModifier, int bPersist = FALSE);

/// @brief Gets the current caster level modifier for oCreature
/// @param oCreature the target creature
/// @param nClass the creature caster class
/// @return the current caster level modifier for the creature
int NWNX_Creature_GetCasterLevelModifier(object oCreature, int nClass);

/// @brief Sets a caster level override for oCreature
/// @param oCreature the target creature
/// @param nClass the class that this modifier will apply to
/// @param nCasterLevel the caster level override to apply
/// @param bPersist whether the override should be persisted to the .bic file if applicable
void NWNX_Creature_SetCasterLevelOverride(object oCreature, int nClass, int nCasterLevel, int bPersist = FALSE);

/// @brief Gets the current caster level override for oCreature
/// @param oCreature the target creature
/// @param nClass the creature caster class
/// @return the current caster level override for the creature or -1 if not set
int NWNX_Creature_GetCasterLevelOverride(object oCreature, int nClass);

/// @brief Move a creature to limbo.
/// @param oCreature The creature object.
void NWNX_Creature_JumpToLimbo(object oCreature);

/// @brief Sets the critical hit multiplier modifier for the Creature
/// @param oCreature The target creature
/// @param nModifier The modifier to apply
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param bPersist Whether the modifier should persist to .bic file if applicable
/// @param nBaseItem Applies the.modifier only when the attack used this baseitem. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @note Persistence is activated each server reset by the first use of either 'SetCriticalMultiplier*' functions. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_SetCriticalMultiplierModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1);

/// @brief Gets the critical hit multiplier modifier for the Creature
/// @param oCreature The target creature
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param nBaseItem The baseitem modifer to retrieve. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @return the current critical hit multiplier modifier for the creature
int NWNX_Creature_GetCriticalMultiplierModifier(object oCreature, int nHand = 0, int nBaseItem = -1);

/// @brief Sets the critical hit multiplier override for the Creature.
/// @param oCreature The target creature
/// @param nOverride The override value to apply. -1 to clear override.
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param bPersist Whether the modifier should persist to .bic file if applicable
/// @param nBaseItem Applies the.Override only when the attack used this baseitem. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @note Persistence is activated each server reset by the first use of either 'SetCriticalMultiplier*' functions. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_SetCriticalMultiplierOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1);

/// @brief Gets the critical hit multiplier override for the Creature
/// @param oCreature The target creature
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param nBaseItem The baseitem Override to retrieve. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @return the current critical hit multiplier override for the creature. No override == -1
int NWNX_Creature_GetCriticalMultiplierOverride(object oCreature, int nHand = 0, int nBaseItem = -1);

/// @brief Sets the critical hit range modifier for the creature.
/// @param oCreature The target creature
/// @param nModifier The modifier to apply. Positive modifiers reduce critical chance. (I.e. From 18-20, a +1 results in crit range of 19-20)
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param bPersist Whether the modifier should persist to .bic file if applicable
/// @param nBaseItem Applies the.modifier only when the attack used this baseitem. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @note Persistence is activated each server reset by the first use of either 'SetCriticalRange*' functions. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_SetCriticalRangeModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1);

/// @brief Gets the critical hit range modifier for the creature.
/// @param oCreature The target creature
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param nBaseItem The baseitem modifer to retrieve. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @return the current critical hit range modifier for the creature
int NWNX_Creature_GetCriticalRangeModifier(object oCreature, int nHand = 0, int nBaseItem = -1);

/// @brief Sets the critical hit range Override for the creature.
/// @param oCreature The target creature
/// @param nOverride The new minimum roll to crit. i.e nOverride of 15 results in crit range of 15-20. -1 to clear override.
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param bPersist Whether the modifier should persist to .bic file if applicable
/// @param nBaseItem Applies the.Override only when the attack used this baseitem. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @note Persistence is activated each server reset by the first use of either 'SetCriticalRange*' functions. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_SetCriticalRangeOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1);

/// @brief Sets the critical hit range Override for the creature.
/// @param oCreature The target creature
/// @param nHand 0 for all attacks, 1 for Mainhand, 2 for Offhand
/// @param nBaseItem The baseitem Override to retrieve. BASE_ITEM_GLOVES for Unarmed, '-1' for all
/// @return the current critical hit range override for the creature. No override == -1
int NWNX_Creature_GetCriticalRangeOverride(object oCreature, int nHand = 0, int nBaseItem = -1);

/// @brief Add oAssociate as nAssociateType to oCreature
/// @warning Only basic checks are done so care must be taken when using this function
/// @param oCreature The creature to add oAssociate to
/// @param oAssociate The associate, must be a NPC
/// @param nAssociateType The associate type, one of ASSOCIATE_TYPE_*, except _NONE
void NWNX_Creature_AddAssociate(object oCreature, object oAssociate, int nAssociateType);

/// @brief Set whether an effect icon is flashing or not.
/// @param oCreature The target creature.
/// @param nIconId The icon id, see effecticons.2da.
/// @param bFlashing TRUE for flashing, FALSE for not flashing.
void NWNX_Creature_SetEffectIconFlashing(object oCreature, int nIconId, int bFlashing);

/// @brief Override the damage level of oCreature.
/// @note Damage levels are the damage state under a creature's name, for example: 'Near Death'
/// @param oCreature The target creature.
/// @param nDamageLevel A damage level, see damagelevels.2da. Allowed values: 0-255 or -1 to remove the override.
void NWNX_Creature_OverrideDamageLevel(object oCreature, int nDamageLevel);

/// @brief Set the encounter source of oCreature.
/// @param oCreature The target creature.
/// @param oEncounter The source encounter
void NWNX_Creature_SetEncounter(object oCreature, object oEncounter);

/// @brief Get the encounter source of oCreature.
/// @param oCreature The target creature.
/// @return The encounter, OBJECT_INVALID if not part of an encounter or on error
object NWNX_Creature_GetEncounter(object oCreature);

/// @brief Get if oCreature is currently bartering.
/// @param oCreature The target creature.
/// @return TRUE if oCreature is bartering, FALSE if not or on error.
int NWNX_Creature_GetIsBartering(object oCreature);

/// @brief Sets caster level for the last item used. Use in a spellhook or spell event before to set caster level for any spells cast from the item.
/// @param oCreature the creature who used the item.
/// @param nCasterLvl the desired caster level.
void NWNX_Creature_SetLastItemCasterLevel(object oCreature, int nCasterLvl);

/// @brief Gets the caster level of the last item used.
/// @param oCreature the creature who used the item.
/// @return returns the creatures last used item's level.
int NWNX_Creature_GetLastItemCasterLevel(object oCreature);

/// @brief Gets the Armor classed of attacked against versus
/// @param oAttacked The one being attacked
/// @param oVersus The one doing the attacking
/// @param nTouch TRUE for touch attacks
/// @return -255 on Error, Flat footed AC if oVersus is invalid or the Attacked AC versus oVersus.
int NWNX_Creature_GetArmorClassVersus(object oAttacked, object oVersus, int nTouch=FALSE);

/// @brief Gets the current walk animation of oCreature.
/// @param oCreature The target creature.
/// @return -1 on Error, otherwise the walk animation number
int NWNX_Creature_GetWalkAnimation(object oCreature);

/// @brief Sets the current walk animation of oCreature.
/// @param oCreature The target creature.
/// @param nAnimation The walk animation number.
void NWNX_Creature_SetWalkAnimation(object oCreature, int nAnimation);

/// @brief Changes the attack modifier depending on the dice roll. Used to skip autofail on 1 and autosucceed on 20 as well.
/// @param oCreature The attacking creature, use OBJECT_INVALID for all.
/// @param nRoll The dice roll to modify.
/// @param nModifier The modifier to the attack, use 0 to turn off autofail for 1/autosucceed for 20 with no attack modifier value.
void NWNX_Creature_SetAttackRollOverride(object oCreature, int nRoll, int nModifier);

/// @brief Works like the tweak but can be turned on and off for all creatures or single ones.
/// @param oCreature The parrying creature, use OBJECT_INVALID for all.
/// @param bParry TRUE to parry all attacks.
/// @note Use this command on_module_load instead of the NWNX_TWEAKS_PARRY_ALL_ATTACKS tweak if using NWNX_Creature_SetAttackRollOverride()
void NWNX_Creature_SetParryAllAttacks(object oCreature, int bParry);

/// @brief Gets the NoPermanentDeath flag of oCreature.
/// @param oCreature The target creature.
/// @return TRUE/FALSE or -1 on error.
int NWNX_Creature_GetNoPermanentDeath(object oCreature);

/// @brief Sets the NoPermanentDeath flag of oCreature.
/// @param oCreature The target creature.
/// @param bNoPermanentDeath TRUE/FALSE.
void NWNX_Creature_SetNoPermanentDeath(object oCreature, int bNoPermanentDeath);

/// @brief Compute a safe location for oCreature.
/// @param oCreature The target creature.
/// @param vPosition The starting position.
/// @param fRadius The search radius around vPosition.
/// @param bWalkStraightLineRequired Whether the creature must be able to walk in a straight line to the position.
/// @return A safe location as vector, will return vPosition if one wasn't found. Returns {0.0, 0.0, 0.0} on error.
vector NWNX_Creature_ComputeSafeLocation(object oCreature, vector vPosition, float fRadius = 20.0f, int bWalkStraightLineRequired = TRUE);

/// @brief Update oCreature's perception of oTargetCreature.
/// @param oCreature The creature.
/// @param oTargetCreature The target creature.
void NWNX_Creature_DoPerceptionUpdateOnCreature(object oCreature, object oTargetCreature);

/// @brief Get a creatures personal space (meters from center to non-creature objects).
/// @param oCreature The creature.
/// @return The creatures personal space.
float NWNX_Creature_GetPersonalSpace(object oCreature);

/// @brief Set a creatures personal space (meters from center to non-creature objects).
/// @param oCreature The creature.
/// @param fPerspace The creatures personal space.
void NWNX_Creature_SetPersonalSpace(object oCreature, float fPerspace);

/// @brief Get a creatures creature personal space (meters from center to other creatures).
/// @param oCreature The creature.
/// @return The creatures creature personal space.
float NWNX_Creature_GetCreaturePersonalSpace(object oCreature);

/// @brief Set a creatures creature personal space (meters from center to other creatures).
/// @param oCreature The creature.
/// @param fCrePerspace The creatures creature personal space.
void NWNX_Creature_SetCreaturePersonalSpace(object oCreature, float fCrePerspace);

/// @brief Get a creatures height.
/// @param oCreature The creature.
/// @return The creatures height.
float NWNX_Creature_GetHeight(object oCreature);

/// @brief Set a creatures height.
/// @param oCreature The creature.
/// @param fHeight The creatures height.
void NWNX_Creature_SetHeight(object oCreature, float fHeight);

/// @brief Get a creatures hit distance.
/// @param oCreature The creature.
/// @return The creatures hit distance.
float NWNX_Creature_GetHitDistance(object oCreature);

/// @brief Set a creatures hit distance.
/// @param oCreature The creature.
/// @param fHitDist The creatures hit distance.
void NWNX_Creature_SetHitDistance(object oCreature, float fHitDist);

/// @brief Get a creatures preferred attack distance.
/// @param oCreature The creature.
/// @return The creatures preferred attack distance.
float NWNX_Creature_GetPreferredAttackDistance(object oCreature);

/// @brief Set a creatures preferred attack distance.
/// @param oCreature The creature.
/// @param fPrefAtckDist The creatures preferred attack distance.
void NWNX_Creature_SetPreferredAttackDistance(object oCreature, float fPrefAtckDist);

/// @brief Get the skill penalty from wearing armor.
/// @param oCreature The creature.
int NWNX_Creature_GetArmorCheckPenalty(object oCreature);

/// @brief Get the skill penalty from wearing a shield.
/// @param oCreature The creature.
int NWNX_Creature_GetShieldCheckPenalty(object oCreature);

/// @brief Sets a chance for normal Effect Immunities to be bypassed
/// @param oCreature The affected creature
/// @param nImmunityType 'IMMUNITY_TYPE_*' to bypass. By default affects outgoing effects (oCreature -> another creature). Use a negative (-IMMUNITY_TYPE_*) to affect incoming effects instead (another creature -> oCreature) use 255/-255 to bypass ALL Immunities.
/// @param nChance The chance (of 100%) to bypass the immunity check. A Positive chance results in NOT IMMUNE. A Negative chance results in IMMUNE.
/// @param bPersist Whether the modifier should persist to .bic file (for PCs)
/// @note Persistence is enabled after a server reset by the first use of this function. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
/// @note Where an Outgoing and Incoming bypass both attempt opposing outcomes, both are ignored and the immunity status without bypass will apply.
void NWNX_Creature_SetBypassEffectImmunity(object oCreature, int nImmunityType, int nChance = 100, int bPersist = FALSE);

/// @brief Gets a chance for normal Effect Immunities to be bypassed
/// @param oCreature The target creature
/// @param nImmunityType 'IMMUNITY_TYPE_*' to retrieve the current chance for bypass: Positive gets outgoing effects (oCreature -> another creature). Negative (-IMMUNITY_TYPE_*) gets incoming effects (another creature -> oCreature).
/// @return the current critical hit multiplier modifier for the creature
int NWNX_Creature_GetBypassEffectImmunity(object oCreature, int nImmunityType);

/// @brief Sets the killer of oCreature to oKiller.
/// @param oCreature The target creature.
/// @param oKiller The killer.
void NWNX_Creature_SetLastKiller(object oCreature, object oKiller);

/// @brief Instantly cast a spell at a target or location.
/// @note oCreature must be in the same area as oTarget or locTarget.
/// @note Does not care if oCreature can't cast spells or doesn't know the spell. Does not consume spell slots.
/// @param oCreature The caster.
/// @param oTarget The target, use OBJECT_INVALID to cast at a location.
/// @param locTarget The location, only used when oTarget is OBJECT_INVALID.
/// @param nSpellID The spell ID.
/// @param nCasterLevel The caster level of the spell.
/// @param fProjectileTime The time in seconds for the projectile to reach the target. 0.0f for no projectile.
/// @param nProjectilePathType A PROJECTILE_PATH_TYPE_* constant.
/// @param nProjectileSpellID An optional spell ID which to use the projectile vfx of. -1 to use nSpellID's projectile vfx.
void NWNX_Creature_DoItemCastSpell(object oCreature, object oTarget, location locTarget, int nSpellID, int nCasterLevel, float fProjectileTime, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int nProjectileSpellID = -1);

/// @brief Have oCreature instantly equip oItem to nInventorySlot.
/// @param oCreature The creature.
/// @param oItem The item, must be possessed by oCreature.
/// @param nInventorySlot An INVENTORY_SLOT_* constant.
/// @return TRUE on success, FALSE on failure.
int NWNX_Creature_RunEquip(object oCreature, object oItem, int nInventorySlot);

/// @brief Have oCreature instantly unequip oItem.
/// @param oCreature The creature.
/// @param oItem The item, must be possessed by oCreature.
/// @return TRUE on success, FALSE on failure.
int NWNX_Creature_RunUnequip(object oCreature, object oItem);

/// @}

void NWNX_Creature_AddFeat(object creature, int feat)
{
    string sFunc = "AddFeat";
    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_AddFeatByLevel(object creature, int feat, int level)
{
    string sFunc = "AddFeatByLevel";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RemoveFeat(object creature, int feat)
{
    string sFunc = "RemoveFeat";
    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetKnowsFeat(object creature, int feat)
{
    string sFunc = "GetKnowsFeat";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatCountByLevel(object creature, int level)
{
    string sFunc = "GetFeatCountByLevel";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatByLevel(object creature, int level, int index)
{
    string sFunc = "GetFeatByLevel";

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatCount(object creature)
{
    string sFunc = "GetFeatCount";

    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatGrantLevel(object creature, int feat)
{
    string sFunc = "GetFeatGrantLevel";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatByIndex(object creature, int index)
{
    string sFunc = "GetFeatByIndex";

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetMeetsFeatRequirements(object creature, int feat)
{
    string sFunc = "GetMeetsFeatRequirements";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

struct NWNX_Creature_SpecialAbility NWNX_Creature_GetSpecialAbility(object creature, int index)
{
    string sFunc = "GetSpecialAbility";

    struct NWNX_Creature_SpecialAbility ability;

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);

    ability.level  = NWNX_GetReturnValueInt();
    ability.ready  = NWNX_GetReturnValueInt();
    ability.id     = NWNX_GetReturnValueInt();

    return ability;
}

int NWNX_Creature_GetSpecialAbilityCount(object creature)
{
    string sFunc = "GetSpecialAbilityCount";

    NWNX_PushArgumentObject(creature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_AddSpecialAbility(object creature, struct NWNX_Creature_SpecialAbility ability)
{
    string sFunc = "AddSpecialAbility";

    NWNX_PushArgumentInt(ability.id);
    NWNX_PushArgumentInt(ability.ready);
    NWNX_PushArgumentInt(ability.level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RemoveSpecialAbility(object creature, int index)
{
    string sFunc = "RemoveSpecialAbility";

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSpecialAbility(object creature, int index, struct NWNX_Creature_SpecialAbility ability)
{
    string sFunc = "SetSpecialAbility";

    NWNX_PushArgumentInt(ability.id);
    NWNX_PushArgumentInt(ability.ready);
    NWNX_PushArgumentInt(ability.level);
    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetClassByLevel(object creature, int level)
{
    string sFunc = "GetClassByLevel";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetBaseAC(object creature, int ac)
{
    string sFunc = "SetBaseAC";

    NWNX_PushArgumentInt(ac);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetBaseAC(object creature)
{
    string sFunc = "GetBaseAC";

    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetRawAbilityScore(object creature, int ability, int value)
{
    string sFunc = "SetRawAbilityScore";

    NWNX_PushArgumentInt(value);
    NWNX_PushArgumentInt(ability);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetRawAbilityScore(object creature, int ability)
{
    string sFunc = "GetRawAbilityScore";

    NWNX_PushArgumentInt(ability);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_ModifyRawAbilityScore(object creature, int ability, int modifier)
{
    string sFunc = "ModifyRawAbilityScore";

    NWNX_PushArgumentInt(modifier);
    NWNX_PushArgumentInt(ability);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetPrePolymorphAbilityScore(object creature, int ability)
{
    string sFunc = "GetPrePolymorphAbilityScore";

    NWNX_PushArgumentInt(ability);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

struct NWNX_Creature_MemorisedSpell NWNX_Creature_GetMemorisedSpell(object creature, int class, int level, int index)
{
    string sFunc = "GetMemorisedSpell";
    struct NWNX_Creature_MemorisedSpell spell;

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);

    spell.domain = NWNX_GetReturnValueInt();
    spell.meta   = NWNX_GetReturnValueInt();
    spell.ready  = NWNX_GetReturnValueInt();
    spell.id     = NWNX_GetReturnValueInt();
    return spell;
}

int NWNX_Creature_GetMemorisedSpellCountByLevel(object creature, int class, int level)
{
    string sFunc = "GetMemorisedSpellCountByLevel";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetMemorisedSpell(object creature, int class, int level, int index, struct NWNX_Creature_MemorisedSpell spell)
{
    string sFunc = "SetMemorisedSpell";

    NWNX_PushArgumentInt(spell.id);
    NWNX_PushArgumentInt(spell.ready);
    NWNX_PushArgumentInt(spell.meta);
    NWNX_PushArgumentInt(spell.domain);

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetRemainingSpellSlots(object creature, int class, int level)
{
    string sFunc = "GetRemainingSpellSlots";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetRemainingSpellSlots(object creature, int class, int level, int slots)
{
    string sFunc = "SetRemainingSpellSlots";

    NWNX_PushArgumentInt(slots);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetKnownSpell(object creature, int class, int level, int index)
{
    string sFunc = "GetKnownSpell";

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetKnownSpellCount(object creature, int class, int level)
{
    string sFunc = "GetKnownSpellCount";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_RemoveKnownSpell(object creature, int class, int level, int spellId)
{
    string sFunc = "RemoveKnownSpell";

    NWNX_PushArgumentInt(spellId);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_AddKnownSpell(object creature, int class, int level, int spellId)
{
    string sFunc = "AddKnownSpell";

    NWNX_PushArgumentInt(spellId);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_ClearMemorisedKnownSpells(object creature, int class, int spellId)
{
    string sFunc = "ClearMemorisedKnownSpells";

    NWNX_PushArgumentInt(spellId);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_ClearMemorisedSpell(object creature, int class, int level, int index)
{
    string sFunc = "ClearMemorisedSpell";

    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetMaxSpellSlots(object creature, int class, int level)
{
    string sFunc = "GetMaxSpellSlots";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}


int NWNX_Creature_GetMaxHitPointsByLevel(object creature, int level)
{
    string sFunc = "GetMaxHitPointsByLevel";

    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetMaxHitPointsByLevel(object creature, int level, int value)
{
    string sFunc = "SetMaxHitPointsByLevel";

    NWNX_PushArgumentInt(value);
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetMovementRate(object creature, int rate)
{
    string sFunc = "SetMovementRate";

    NWNX_PushArgumentInt(rate);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetMovementRateFactor(object creature)
{
    string sFunc = "GetMovementRateFactor";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetMovementRateFactor(object creature, float factor)
{
    string sFunc = "SetMovementRateFactor";

    NWNX_PushArgumentFloat(factor);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetMovementRateFactorCap(object creature, float cap)
{
    string sFunc = "SetMovementRateFactorCap";

    NWNX_PushArgumentFloat(cap);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAlignmentGoodEvil(object creature, int value)
{
    string sFunc = "SetAlignmentGoodEvil";

    NWNX_PushArgumentInt(value);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAlignmentLawChaos(object creature, int value)
{
    string sFunc = "SetAlignmentLawChaos";

    NWNX_PushArgumentInt(value);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetSoundset(object creature)
{
    string sFunc = "GetSoundset";

    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetSoundset(object creature, int soundset)
{
    string sFunc = "SetSoundset";

    NWNX_PushArgumentInt(soundset);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSkillRank(object creature, int skill, int rank)
{
    string sFunc = "SetSkillRank";
    NWNX_PushArgumentInt(rank);
    NWNX_PushArgumentInt(skill);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetClassByPosition(object creature, int position, int classID)
{
    string sFunc = "SetClassByPosition";
    NWNX_PushArgumentInt(classID);
    NWNX_PushArgumentInt(position);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetLevelByPosition(object creature, int position, int level)
{
    string sFunc = "SetLevelByPosition";
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentInt(position);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetBaseAttackBonus(object creature, int bab)
{
    string sFunc = "SetBaseAttackBonus";
    NWNX_PushArgumentInt(bab);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetAttacksPerRound(object creature, int bBaseAPR = FALSE)
{
    string sFunc = "GetAttacksPerRound";
    NWNX_PushArgumentInt(bBaseAPR);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetGender(object creature, int gender)
{
    string sFunc = "SetGender";
    NWNX_PushArgumentInt(gender);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreFeats(object creature)
{
    string sFunc = "RestoreFeats";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreSpecialAbilities(object creature)
{
    string sFunc = "RestoreSpecialAbilities";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreSpells(object creature, int level = -1)
{
    string sFunc = "RestoreSpells";
    NWNX_PushArgumentInt(level);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_RestoreItems(object creature)
{
    string sFunc = "RestoreItems";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetSize(object creature, int size)
{
    string sFunc = "SetSize";
    NWNX_PushArgumentInt(size);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetSkillPointsRemaining(object creature)
{
    string sFunc = "GetSkillPointsRemaining";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}


void NWNX_Creature_SetSkillPointsRemaining(object creature, int skillpoints)
{
    string sFunc = "SetSkillPointsRemaining";
    NWNX_PushArgumentInt(skillpoints);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetRacialType(object creature, int racialtype)
{
    string sFunc = "SetRacialType";
    NWNX_PushArgumentInt(racialtype);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetMovementType(object creature)
{
    string sFunc = "GetMovementType";
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetWalkRateCap(object creature, float fWalkRate = 2000.0f)
{
    string sFunc = "SetWalkRateCap";
    NWNX_PushArgumentFloat(fWalkRate);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetGold(object creature, int gold)
{
    string sFunc = "SetGold";
    NWNX_PushArgumentInt(gold);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetCorpseDecayTime(object creature, int nDecayTime)
{
    string sFunc = "SetCorpseDecayTime";
    NWNX_PushArgumentInt(nDecayTime);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}


int NWNX_Creature_GetBaseSavingThrow(object creature, int which)
{
    string sFunc = "GetBaseSavingThrow";
    NWNX_PushArgumentInt(which);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetBaseSavingThrow(object creature, int which, int value)
{
    string sFunc = "SetBaseSavingThrow";
    NWNX_PushArgumentInt(value);
    NWNX_PushArgumentInt(which);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_LevelUp(object creature, int class, int count=1)
{
    string sFunc = "LevelUp";
    NWNX_PushArgumentInt(count);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_LevelDown(object creature, int count=1)
{
    string sFunc = "LevelDown";
    NWNX_PushArgumentInt(count);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetChallengeRating(object creature, float fCR)
{
    string sFunc = "SetChallengeRating";
    NWNX_PushArgumentFloat(fCR);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetAttackBonus(object creature, int isMelee = -1, int isTouchAttack = FALSE, int isOffhand = FALSE, int includeBaseAttackBonus = TRUE)
{
    string sFunc = "GetAttackBonus";

    if (isMelee == -1)
    {
        object oWeapon = GetItemInSlot(INVENTORY_SLOT_RIGHTHAND, creature);

        if (GetIsObjectValid(oWeapon))
        {
            isMelee = !GetWeaponRanged(oWeapon);
        }
        else
        {// Default to melee for unarmed
            isMelee = TRUE;
        }
    }

    NWNX_PushArgumentInt(includeBaseAttackBonus);
    NWNX_PushArgumentInt(isOffhand);
    NWNX_PushArgumentInt(isTouchAttack);
    NWNX_PushArgumentInt(isMelee);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetHighestLevelOfFeat(object creature, int feat)
{
    string sFunc = "GetHighestLevelOfFeat";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatRemainingUses(object creature, int feat)
{
    string sFunc = "GetFeatRemainingUses";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFeatTotalUses(object creature, int feat)
{
    string sFunc = "GetFeatTotalUses";

    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetFeatRemainingUses(object creature, int feat, int uses)
{
    string sFunc = "SetFeatRemainingUses";

    NWNX_PushArgumentInt(uses);
    NWNX_PushArgumentInt(feat);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetTotalEffectBonus(object creature, int bonusType=NWNX_CREATURE_BONUS_TYPE_ATTACK, object target=OBJECT_INVALID, int isElemental=0, int isForceMax=0, int savetype=-1, int saveSpecificType=-1, int skill=-1, int abilityScore=-1, int isOffhand=FALSE)
{
    string sFunc = "GetTotalEffectBonus";

    NWNX_PushArgumentInt(isOffhand);
    NWNX_PushArgumentInt(abilityScore);
    NWNX_PushArgumentInt(skill);
    NWNX_PushArgumentInt(saveSpecificType);
    NWNX_PushArgumentInt(savetype);
    NWNX_PushArgumentInt(isForceMax);
    NWNX_PushArgumentInt(isElemental);
    NWNX_PushArgumentObject(target);
    NWNX_PushArgumentInt(bonusType);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetOriginalName(object creature, string name, int isLastName)
{
    string sFunc = "SetOriginalName";

    NWNX_PushArgumentInt(isLastName);
    NWNX_PushArgumentString(name);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

string NWNX_Creature_GetOriginalName(object creature, int isLastName)
{
    string sFunc = "GetOriginalName";

    NWNX_PushArgumentInt(isLastName);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueString();
}

void NWNX_Creature_SetSpellResistance(object creature, int sr)
{
    string sFunc = "SetSpellResistance";

    NWNX_PushArgumentInt(sr);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAnimalCompanionCreatureType(object creature, int type)
{
    string sFunc = "SetAnimalCompanionCreatureType";

    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetFamiliarCreatureType(object creature, int type)
{
    string sFunc = "SetFamiliarCreatureType";

    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAnimalCompanionName(object creature, string name)
{
    string sFunc = "SetAnimalCompanionName";

    NWNX_PushArgumentString(name);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetFamiliarName(object creature, string name)
{
    string sFunc = "SetFamiliarName";

    NWNX_PushArgumentString(name);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetDisarmable(object creature)
{
    string sFunc = "GetDisarmable";

    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetDisarmable(object creature, int disarmable)
{
    string sFunc = "SetDisarmable";

    NWNX_PushArgumentInt(disarmable);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetDomain(object creature, int class, int index)
{
    WriteTimestampedLogEntry("NWNX_Creature: GetDomain() is deprecated. Please use the basegame's GetDomain() instead");

    return GetDomain(creature, index, class);
}

void NWNX_Creature_SetDomain(object creature, int class, int index, int domain)
{
    string sFunc = "SetDomain";

    NWNX_PushArgumentInt(domain);
    NWNX_PushArgumentInt(index);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetSpecialization(object creature, int class)
{
    WriteTimestampedLogEntry("NWNX_Creature: GetSpecialization() is deprecated. Please use the basegame's GetSpecialization() instead");

    return GetSpecialization(creature, class);
}

void NWNX_Creature_SetSpecialization(object creature, int class, int school)
{
    string sFunc = "SetSpecialization";

    NWNX_PushArgumentInt(school);
    NWNX_PushArgumentInt(class);
    NWNX_PushArgumentObject(creature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetFaction(object oCreature, int nFactionId)
{
    string sFunc = "SetFaction";
    NWNX_PushArgumentInt(nFactionId);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetFaction(object oCreature)
{
    string sFunc = "GetFaction";
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetFlatFooted(object oCreature)
{
    string sFunc = "GetFlatFooted";
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

string NWNX_Creature_SerializeQuickbar(object oCreature)
{
    string sFunc = "SerializeQuickbar";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueString();
}

int NWNX_Creature_DeserializeQuickbar(object oCreature, string sSerializedQuickbar)
{
    string sFunc = "DeserializeQuickbar";

    NWNX_PushArgumentString(sSerializedQuickbar);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetCasterLevelModifier(object oCreature, int nClass, int nModifier, int bPersist = FALSE)
{
    string sFunc = "SetCasterLevelModifier";

    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nModifier);
    NWNX_PushArgumentInt(nClass);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCasterLevelModifier(object oCreature, int nClass)
{
    string sFunc = "GetCasterLevelModifier";

    NWNX_PushArgumentInt(nClass);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetCasterLevelOverride(object oCreature, int nClass, int nCasterLevel, int bPersist = FALSE)
{
    string sFunc = "SetCasterLevelOverride";

    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nCasterLevel);
    NWNX_PushArgumentInt(nClass);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCasterLevelOverride(object oCreature, int nClass)
{
    string sFunc = "GetCasterLevelOverride";

    NWNX_PushArgumentInt(nClass);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_JumpToLimbo(object oCreature)
{
    string sFunc = "JumpToLimbo";
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetCriticalMultiplierModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    string sFunc = "SetCriticalMultiplierModifier";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentInt(nModifier);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCriticalMultiplierModifier(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    string sFunc = "GetCriticalMultiplierModifier";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetCriticalMultiplierOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    string sFunc = "SetCriticalMultiplierOverride";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentInt(nOverride);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCriticalMultiplierOverride(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    string sFunc = "GetCriticalMultiplierOverride";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetCriticalRangeModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    string sFunc = "SetCriticalRangeModifier";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentInt(nModifier);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCriticalRangeModifier(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    string sFunc = "GetCriticalRangeModifier";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetCriticalRangeOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    string sFunc = "SetCriticalRangeOverride";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentInt(nOverride);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetCriticalRangeOverride(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    string sFunc = "GetCriticalRangeOverride";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentInt(nHand);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_AddAssociate(object oCreature, object oAssociate, int nAssociateType)
{
    string sFunc = "AddAssociate";

    NWNX_PushArgumentInt(nAssociateType);
    NWNX_PushArgumentObject(oAssociate);
    NWNX_PushArgumentObject(oCreature);

    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetEffectIconFlashing(object oCreature, int nIconId, int bFlashing)
{
    string sFunc = "SetEffectIconFlashing";

    NWNX_PushArgumentInt(bFlashing);
    NWNX_PushArgumentInt(nIconId);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_OverrideDamageLevel(object oCreature, int nDamageLevel)
{
    string sFunc = "OverrideDamageLevel";

    NWNX_PushArgumentInt(nDamageLevel);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetEncounter(object oCreature, object oEncounter)
{
    string sFunc = "SetEncounter";

    NWNX_PushArgumentObject(oEncounter);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

object NWNX_Creature_GetEncounter(object oCreature)
{
    string sFunc = "GetEncounter";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueObject();
}

int NWNX_Creature_GetIsBartering(object oCreature)
{
    string sFunc = "GetIsBartering";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetLastItemCasterLevel(object oCreature, int nCasterLvl)
{
    string sFunc = "SetLastItemCasterLevel";
    NWNX_PushArgumentInt(nCasterLvl);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}


int NWNX_Creature_GetLastItemCasterLevel(object oCreature)
{
    string sFunc = "GetLastItemCasterLevel";
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetArmorClassVersus(object oAttacked, object oVersus, int nTouch=FALSE)
{
    string sFunc = "GetArmorClassVersus";
    NWNX_PushArgumentInt(nTouch);
    NWNX_PushArgumentObject(oVersus);
    NWNX_PushArgumentObject(oAttacked);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetWalkAnimation(object oCreature)
{
    string sFunc = "GetWalkAnimation";
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetWalkAnimation(object oCreature, int nAnimation)
{
    string sFunc = "SetWalkAnimation";
    NWNX_PushArgumentInt(nAnimation);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetAttackRollOverride(object oCreature, int nRoll, int nModifier)
{
    string sFunc = "SetAttackRollOverride";
    NWNX_PushArgumentInt(nModifier);
    NWNX_PushArgumentInt(nRoll);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_SetParryAllAttacks(object oCreature, int bParry)
{
    string sFunc = "SetParryAllAttacks";
    NWNX_PushArgumentInt(bParry);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetNoPermanentDeath(object oCreature)
{
    string sFunc = "GetNoPermanentDeath";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetNoPermanentDeath(object oCreature, int bNoPermanentDeath)
{
    string sFunc = "SetNoPermanentDeath";

    NWNX_PushArgumentInt(bNoPermanentDeath);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

vector NWNX_Creature_ComputeSafeLocation(object oCreature, vector vPosition, float fRadius = 20.0f, int bWalkStraightLineRequired = TRUE)
{
    string sFunc = "ComputeSafeLocation";

    NWNX_PushArgumentInt(bWalkStraightLineRequired);
    NWNX_PushArgumentFloat(fRadius);
    NWNX_PushArgumentFloat(vPosition.x);
    NWNX_PushArgumentFloat(vPosition.y);
    NWNX_PushArgumentFloat(vPosition.z);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    vector v;
    v.z = NWNX_GetReturnValueFloat();
    v.y = NWNX_GetReturnValueFloat();
    v.x = NWNX_GetReturnValueFloat();

    return v;
}

void NWNX_Creature_DoPerceptionUpdateOnCreature(object oCreature, object oTargetCreature)
{
    string sFunc = "DoPerceptionUpdateOnCreature";

    NWNX_PushArgumentObject(oTargetCreature);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetPersonalSpace(object oCreature)
{
    string sFunc = "GetPersonalSpace";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetPersonalSpace(object oCreature, float fPerspace)
{
    string sFunc = "SetPersonalSpace";

    NWNX_PushArgumentFloat(fPerspace);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetCreaturePersonalSpace(object oCreature)
{
    string sFunc = "GetCreaturePersonalSpace";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetCreaturePersonalSpace(object oCreature, float fCrePerspace)
{
    string sFunc = "SetCreaturePersonalSpace";

    NWNX_PushArgumentFloat(fCrePerspace);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetHeight(object oCreature)
{
    string sFunc = "GetHeight";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetHeight(object oCreature, float fHeight)
{
    string sFunc = "SetHeight";

    NWNX_PushArgumentFloat(fHeight);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetHitDistance(object oCreature)
{
    string sFunc = "GetHitDistance";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetHitDistance(object oCreature, float fHitDist)
{
    string sFunc = "SetHitDistance";

    NWNX_PushArgumentFloat(fHitDist);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

float NWNX_Creature_GetPreferredAttackDistance(object oCreature)
{
    string sFunc = "GetPreferredAttackDistance";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Creature_SetPreferredAttackDistance(object oCreature, float fPrefAtckDist)
{
    string sFunc = "SetPreferredAttackDistance";

    NWNX_PushArgumentFloat(fPrefAtckDist);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetArmorCheckPenalty(object oCreature)
{
    string sFunc = "GetArmorCheckPenalty";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_GetShieldCheckPenalty(object oCreature)
{
    string sFunc = "GetShieldCheckPenalty";

    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetBypassEffectImmunity(object oCreature, int nImmunityType, int nChance = 100, int bPersist = FALSE)
{
    string sFunc = "SetBypassEffectImmunity";

    NWNX_PushArgumentInt(bPersist);
    NWNX_PushArgumentInt(nChance);
    NWNX_PushArgumentInt(nImmunityType);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_GetBypassEffectImmunity(object oCreature, int nImmunityType)
{
    string sFunc = "GetBypassEffectImmunity";

    NWNX_PushArgumentInt(nImmunityType);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Creature_SetLastKiller(object oCreature, object oKiller)
{
    string sFunc = "SetLastKiller";

    NWNX_PushArgumentObject(oKiller);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

void NWNX_Creature_DoItemCastSpell(object oCreature, object oTarget, location locTarget, int nSpellID, int nCasterLevel, float fProjectileTime, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int nProjectileSpellID = -1)
{
    string sFunc = "DoItemCastSpell";

    object oArea = GetAreaFromLocation(locTarget);
    vector vPosition = GetPositionFromLocation(locTarget);

    NWNX_PushArgumentInt(nProjectileSpellID);
    NWNX_PushArgumentInt(nProjectilePathType);
    NWNX_PushArgumentFloat(fProjectileTime);
    NWNX_PushArgumentInt(nCasterLevel);
    NWNX_PushArgumentInt(nSpellID);
    NWNX_PushArgumentFloat(vPosition.z);
    NWNX_PushArgumentFloat(vPosition.y);
    NWNX_PushArgumentFloat(vPosition.x);
    NWNX_PushArgumentObject(oArea);
    NWNX_PushArgumentObject(oTarget);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);
}

int NWNX_Creature_RunEquip(object oCreature, object oItem, int nInventorySlot)
{
    string sFunc = "RunEquip";

    NWNX_PushArgumentInt(nInventorySlot);
    NWNX_PushArgumentObject(oItem);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Creature_RunUnequip(object oCreature, object oItem)
{
    string sFunc = "RunUnequip";

    NWNX_PushArgumentObject(oItem);
    NWNX_PushArgumentObject(oCreature);
    NWNX_CallFunction(NWNX_Creature, sFunc);

    return NWNX_GetReturnValueInt();
}
