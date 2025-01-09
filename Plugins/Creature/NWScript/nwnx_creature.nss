/// @addtogroup creature Creature
/// @brief Functions exposing additional creature properties.
/// @{
/// @file nwnx_creature.nss

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

/// @name Ranged Projectile VFX
/// @anchor ranged_projectile_vfx
///
/// Used with NWNX_Creature_OverrideRangedProjectileVFX() these are the projectile vfx types.
/// @{
const int NWNX_CREATURE_PROJECTILE_VFX_NONE         = 0; ///< No VFX
const int NWNX_CREATURE_PROJECTILE_VFX_ACID         = 1;
const int NWNX_CREATURE_PROJECTILE_VFX_COLD         = 2;
const int NWNX_CREATURE_PROJECTILE_VFX_ELECTRICAL   = 3;
const int NWNX_CREATURE_PROJECTILE_VFX_FIRE         = 4;
const int NWNX_CREATURE_PROJECTILE_VFX_SONIC        = 5;
const int NWNX_CREATURE_PROJECTILE_VFX_RANDOM       = 6; ///< Random Elemental VFX
/// @}

const int NWNX_CREATURE_ABILITY_NONE = 6;

/// @struct NWNX_Creature_SpecialAbility
/// @brief A creature special ability.
struct NWNX_Creature_SpecialAbility
{
    int id; ///< The spell id
    int ready; ///< Whether it can be used
    int level; ///< The level of the ability
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

/// @brief Removes the creature a feat assigned at a level
/// @param creature The creature object.
/// @param feat The feat id.
/// @param level The level they gained the feat.
/// @remark Removes the feat from the stat list at the provided level. Does not remove the feat from the creature, use
/// NWNX_Creature_RemoveFeat for this.
void NWNX_Creature_RemoveFeatByLevel(object creature, int feat, int level);

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

/// @brief Returns the creature's maximum movement rate cap.
/// @remark Default movement rate cap is 1.5.
/// @param creature The creature object.
/// @return The maximum movement rate cap.
float NWNX_Creature_GetMovementRateFactorCap(object creature);

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

/// @brief Set the base ranks in a skill for creature
/// @param creature The creature object.
/// @param skill The skill id.
/// @param rank The value to set as the skill rank.
void NWNX_Creature_SetSkillRank(object creature, int skill, int rank);

/// @brief Get the ranks in a skill for creature assigned at a level.
/// @param creature The creature object.
/// @param skill The skill id.
/// @param level The level they gained skill ranks.
/// @return The rank in a skill assigned at a level (-1 on error).
int NWNX_Creature_GetSkillRankByLevel(object creature, int skill, int level);

/// @brief Set the ranks in a skill for creature assigned at a level.
/// @note It only affect the leveling array, to know what to do on level-down. To effectivly change the skill rank on the current level, NWNX_Creature_SetSkillRank is also needed.
/// @param creature The creature object.
/// @param skill The skill id.
/// @param level The level they gained skill ranks.
/// @param rank The value to set as the skill rank.
void NWNX_Creature_SetSkillRankByLevel(object creature, int skill, int rank, int level);

/// @brief Set the class ID in a particular position for a creature.
/// @param creature The creature object.
/// @param position Should be 0, 1, or 2 depending on how many classes the creature
/// has and which is to be modified.
/// @param classID A valid ID number in classes.2da and between 0 and 255.
/// @param bUpdateLevels determines whether the method will replace all occurrences
/// of the old class in CNWLevelStats with the new classID.
void NWNX_Creature_SetClassByPosition(object creature, int position, int classID, int bUpdateLevels = TRUE);

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

/// @brief Restore all creature feat uses.
/// @param creature The creature object.
void NWNX_Creature_RestoreFeats(object creature);

/// @brief Restore all creature special ability uses.
/// @param creature The creature object.
void NWNX_Creature_RestoreSpecialAbilities(object creature);

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

/// @brief Gets the creature's remaining unspent skill points for level.
/// @param creature The creature object.
/// @param level The level.
/// @return The remaining unspent skill points for level.
int NWNX_Creature_GetSkillPointsRemainingByLevel(object creature, int level);

/// @brief Sets the creature's remaining unspent skill points for level.
/// @param creature The creature object.
/// @param level The level.
/// @param value The value to set for level.
void NWNX_Creature_SetSkillPointsRemainingByLevel(object creature, int level, int value);

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
/// @param package The class package to use for leveling up (PACKAGE_INVALID = starting package)
/// @note This will not work on player characters.
void NWNX_Creature_LevelUp(object creature, int class, int count = 1, int package = PACKAGE_INVALID);

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

/// @brief Sets one of creature's domains.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param index The first or second domain.
/// @param domain The domain constant to set.
void NWNX_Creature_SetDomain(object creature, int class, int index, int domain);

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
/// @param oItem The spell cast item retrieved by GetSpellCastItem().
/// @param sImpactScript The spell impact script. Set to "****"" to not run any impact script. If left blank, will execute nSpellID's impact script.
void NWNX_Creature_DoItemCastSpell(object oCreature, object oTarget, location locTarget, int nSpellID, int nCasterLevel, float fProjectileTime, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int nProjectileSpellID = -1, object oItem = OBJECT_INVALID, string sImpactScript = "");

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

/// @brief Override the elemental projectile visual effect of ranged/throwing weapons.
/// @param oCreature The creature.
/// @param nProjectileVFX A @ref ranged_projectile_vfx "NWNX_CREATURE_PROJECTILE_VFX_*" constant or -1 to remove the override.
/// @param bPersist Whether the vfx should persist to the .bic file (for PCs).
/// @note Persistence is enabled after a server reset by the first use of this function. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_OverrideRangedProjectileVFX(object oCreature, int nProjectileVFX, int bPersist = FALSE);

/// @brief Sets a custom Initiative modifier
/// @param oCreature The affected creature
/// @param nMod The amount to adjust their initiative (+/-).
/// @param bPersist Whether the modifier should persist to .bic file (for PCs)
/// @note Persistence is enabled after a server reset by the first use of this function. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
/// @warning This modifier takes precedence over an NWNX_Race Initiative modifier; they're not additive
void NWNX_Creature_SetInitiativeModifier(object oCreature, int nMod, int bPersist = FALSE);

/// @brief Gets the custom Initiative modifier.
/// @param oCreature The target creature
/// @return the current custom initiative modifier for the creature
int NWNX_Creature_GetInitiativeModifier(object oCreature);

/// @brief Gets the Body Bag of a creature
/// @param oCreature The target creature
/// @return The creatures assigned Body Bag
object NWNX_Creature_GetBodyBag(object oCreature);

/// @brief Add a cast spell action to oCreature's action queue.
/// @param oCreature The creature casting the spell.
/// @param oTarget The target, to cast at a location use the area as target.
/// @param vTargetLocation The target location.
/// @param nSpellID The spell ID.
/// @param nMultiClass The character class position to cast the spell as. 0 = First Class, 1 = Second Class, 3 = Third Class. To cast a cheat spell use 255 and to cast a special ability use 254.
/// @param nMetaMagic A METAMAGIC_* constant, except METAMAGIC_ANY.
/// @param nDomainLevel The domain level if casting a domain spell.
/// @param nProjectilePathType A PROJECTILE_PATH_TYPE_* constant.
/// @param bInstant TRUE to instantly cast the spell.
/// @param bClearActions TRUE to clear all actions.
/// @param bAddToFront TRUE to add the cast spell action to the front of the action queue.
/// @return TRUE if the action was successfully added to oCreature's action queue.
int NWNX_Creature_AddCastSpellActions(object oCreature, object oTarget, vector vTargetLocation, int nSpellID, int nMultiClass, int nMetaMagic = METAMAGIC_NONE, int nDomainLevel = 0, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstant = FALSE, int bClearActions = FALSE, int bAddToFront = FALSE);

/// @brief Get whether oCreature is flanking oTargetCreature.
/// @param oCreature The creature object.
/// @param oTargetCreature The target creature object.
/// @return TRUE if oCreature is flanking oTargetCreature.
int NWNX_Creature_GetIsFlanking(object oCreature, object oTargetCreature);

/// @brief Decrements the remaining spell slots (innate casting) at a class level.
/// @param oCreature The creature object.
/// @param nClass The class id from classes.2da. (Not class index 0-2)
/// @param nSpellLevel The spell level.
void NWNX_Creature_DecrementRemainingSpellSlots(object oCreature, int nClass, int nSpellLevel);

/// @brief Increments the remaining spell slots (innate casting) at a class level.
/// @param oCreature The creature object.
/// @param nClass The class id from classes.2da. (Not class index 0-2)
/// @param nSpellLevel The spell level.
void NWNX_Creature_IncrementRemainingSpellSlots(object oCreature, int nClass, int nSpellLevel);

/// @brief Gets the maximum number of bonus attacks a creature can have from EffectModifyAttacks().
/// @param oCreature The creature.
/// @return The maximum number of bonus attacks or 0 on error.
int NWNX_Creature_GetMaximumBonusAttacks(object oCreature);

/// @brief Sets the maximum number of bonus attacks a creature can have from EffectModifyAttacks().
/// @note This function also removes the limit of 5 bonus attacks from EffectModifyAttacks().
/// @param oCreature The creature.
/// @param nMaxBonusAttacks The maximum number of bonus attacks. Values < 0 will set the limit back to the default of 5.
/// @param bPersist Whether the modifier should persist to .bic file (for PCs).
/// @note Persistence is enabled after a server reset by the first use of this function. Recommended to trigger on a dummy target OnModuleLoad to enable persistence.
void NWNX_Creature_SetMaximumBonusAttacks(object oCreature, int nMaxBonusAttacks, int bPersist = FALSE);

/// @brief Inserts a cleave or great cleave attack into oCreature's current attack round against the nearest enemy within melee reach.
/// @param oCreature The creature object.
/// @note oCreature must have the cleave or great cleave feats, must be in combat, and must have available attacks remaining in their combat round to use for cleave attack.
void NWNX_Creature_DoCleaveAttack(object oCreature);

/// @brief Gets the current object oCreature's orientation is locked to.
/// @param oCreature The creature object.
/// @return The object oCreature's orientation is locked to, or OBJECT_INVALID if oCreature's orientation is not locked.
object NWNX_Creature_GetLockOrientationToObject(object oCreature);

/// @brief Locks oCreature's orientation to always face oTarget.
/// @param oCreature The creature object.
/// @param oTarget The target to lock oCreature's orientation to. Use OBJECT_INVALID to remove the orientation lock.
void NWNX_Creature_SetLockOrientationToObject(object oCreature, object oTarget);

/// @brief Causes oCreature to broadcast an Attack of Opportunity against themself.
/// @param oCreature The creature object.
/// @param oSingleCreature A single creature to broadcast the Attack of Opporunity to. Use OBJECT_INVALID to broadcast to all nearby enemies.
/// @param bMovement Whether the Attack of Opportunity was caused by movement.
void NWNX_Creature_BroadcastAttackOfOpportunity(object oCreature, object oSingleCreature = OBJECT_INVALID, int bMovement = FALSE);

/// @brief Returns the maximum price oStore will buy items from oCreature for.
/// @param oCreature The creature object.
/// @param oStore The store object.
/// @return The max buy price override. -1 = No maximum buy price, -2 = No override set.
int NWNX_Creature_GetMaxSellToStorePriceOverride(object oCreature, object oStore);

/// @brief Overrides the maximum price oStore will buy items from oCreature for.
/// @param oCreature The creature object.
/// @param oStore The store object.
/// @param nMaxSellToPrice The maximum buy price override. -1 = No maximum buy price, -2 = Remove the override.
void NWNX_Creature_SetMaxSellToStorePriceOverride(object oCreature, object oStore, int nMaxSellToPrice);

/// @brief Returns the creature's ability increase for nLevel.
/// @param oCreature The creature object.
/// @param nLevel The level.
/// @return An ABILITY_* constant, NWNX_CREATURE_ABILITY_NONE or -1 on error
int NWNX_Creature_GetAbilityIncreaseByLevel(object oCreature, int nLevel);

/// @brief Sets the creature's ability increase for nLevel.
/// @param oCreature The creature object.
/// @param nLevel The level.
/// @param nAbility ABILITY_* constant or NWNX_CREATURE_ABILITY_NONE
void NWNX_Creature_SetAbilityIncreaseByLevel(object oCreature, int nLevel, int nAbility);

/// @brief Returns the creature's maximum attack range to a target
/// @param oCreature The creature object.
/// @param oTarget The target to get the maximum attack range to
/// @return The maximum attack range for oCreature to oTarget
float NWNX_Creature_GetMaxAttackRange(object oCreature, object oTarget);

/// @brief Returns the creature's multiclass limit.
/// @note Only works on player characters.
/// @param oCreature The creature object. Has to be a player character.
/// @return The PCs multiclass limit. Returns 0 if no limit is set.
int NWNX_Creature_GetMulticlassLimit(object oCreature);

/// @brief Sets the creature's multiclass limit.
/// @note Only works on player characters and only for future level ups.
/// Classes already taken will continue to be available on level up.
/// The limit must be lower than the server limit set in ruleset.2da MULTICLASS_LIMIT.
/// Setting a value of 0 will remove the limit.
/// @param oCreature The creature object. Has to be a player character.
/// @param nLimit The multiclass limit.
/// @param bPersist Whether the limit should persist to the .bic file.
/// @note Persistence is enabled after a server reset by the first use of this function.
void NWNX_Creature_SetMulticlassLimit(object oCreature, int nLimit, int bPersist = FALSE);

/// @}

void NWNX_Creature_AddFeat(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "AddFeat");
}

void NWNX_Creature_AddFeatByLevel(object creature, int feat, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "AddFeatByLevel");
}

void NWNX_Creature_RemoveFeat(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RemoveFeat");
}

void NWNX_Creature_RemoveFeatByLevel(object creature, int feat, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RemoveFeatByLevel");
}

int NWNX_Creature_GetKnowsFeat(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetKnowsFeat");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatCountByLevel(object creature, int level)
{
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatCountByLevel");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatByLevel(object creature, int level, int index)
{
    NWNXPushInt(index);
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatByLevel");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatCount(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatCount");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatGrantLevel(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatGrantLevel");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatByIndex(object creature, int index)
{
    NWNXPushInt(index);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatByIndex");
    return NWNXPopInt();
}

int NWNX_Creature_GetMeetsFeatRequirements(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMeetsFeatRequirements");
    return NWNXPopInt();
}

struct NWNX_Creature_SpecialAbility NWNX_Creature_GetSpecialAbility(object creature, int index)
{
    struct NWNX_Creature_SpecialAbility ability;
    NWNXPushInt(index);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetSpecialAbility");
    ability.level  = NWNXPopInt();
    ability.ready  = NWNXPopInt();
    ability.id     = NWNXPopInt();
    return ability;
}

int NWNX_Creature_GetSpecialAbilityCount(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetSpecialAbilityCount");
    return NWNXPopInt();
}

void NWNX_Creature_AddSpecialAbility(object creature, struct NWNX_Creature_SpecialAbility ability)
{
    NWNXPushInt(ability.id);
    NWNXPushInt(ability.ready);
    NWNXPushInt(ability.level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "AddSpecialAbility");
}

void NWNX_Creature_RemoveSpecialAbility(object creature, int index)
{
    NWNXPushInt(index);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RemoveSpecialAbility");
}

void NWNX_Creature_SetSpecialAbility(object creature, int index, struct NWNX_Creature_SpecialAbility ability)
{
    NWNXPushInt(ability.id);
    NWNXPushInt(ability.ready);
    NWNXPushInt(ability.level);
    NWNXPushInt(index);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSpecialAbility");
}

int NWNX_Creature_GetClassByLevel(object creature, int level)
{
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetClassByLevel");
    return NWNXPopInt();
}

void NWNX_Creature_SetBaseAC(object creature, int ac)
{
    NWNXPushInt(ac);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetBaseAC");
}

int NWNX_Creature_GetBaseAC(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetBaseAC");
    return NWNXPopInt();
}

void NWNX_Creature_SetRawAbilityScore(object creature, int ability, int value)
{
    NWNXPushInt(value);
    NWNXPushInt(ability);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetRawAbilityScore");
}

int NWNX_Creature_GetRawAbilityScore(object creature, int ability)
{
    NWNXPushInt(ability);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetRawAbilityScore");
    return NWNXPopInt();
}

void NWNX_Creature_ModifyRawAbilityScore(object creature, int ability, int modifier)
{
    NWNXPushInt(modifier);
    NWNXPushInt(ability);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "ModifyRawAbilityScore");
}

int NWNX_Creature_GetPrePolymorphAbilityScore(object creature, int ability)
{
    NWNXPushInt(ability);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetPrePolymorphAbilityScore");
    return NWNXPopInt();
}

int NWNX_Creature_GetRemainingSpellSlots(object creature, int class, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetRemainingSpellSlots");
    return NWNXPopInt();
}

void NWNX_Creature_SetRemainingSpellSlots(object creature, int class, int level, int slots)
{
    NWNXPushInt(slots);
    NWNXPushInt(level);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetRemainingSpellSlots");
}

void NWNX_Creature_RemoveKnownSpell(object creature, int class, int level, int spellId)
{
    NWNXPushInt(spellId);
    NWNXPushInt(level);
    NWNXPushInt(class);
    NWNXPushObject(creature);

    NWNXCall(NWNX_Creature, "RemoveKnownSpell");
}

void NWNX_Creature_AddKnownSpell(object creature, int class, int level, int spellId)
{
    NWNXPushInt(spellId);
    NWNXPushInt(level);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "AddKnownSpell");
}

int NWNX_Creature_GetMaxSpellSlots(object creature, int class, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMaxSpellSlots");
    return NWNXPopInt();
}


int NWNX_Creature_GetMaxHitPointsByLevel(object creature, int level)
{
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMaxHitPointsByLevel");
    return NWNXPopInt();
}

void NWNX_Creature_SetMaxHitPointsByLevel(object creature, int level, int value)
{
    NWNXPushInt(value);
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetMaxHitPointsByLevel");
}

void NWNX_Creature_SetMovementRate(object creature, int rate)
{
    NWNXPushInt(rate);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetMovementRate");
}

float NWNX_Creature_GetMovementRateFactor(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMovementRateFactor");
    return NWNXPopFloat();
}

void NWNX_Creature_SetMovementRateFactor(object creature, float factor)
{
    NWNXPushFloat(factor);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetMovementRateFactor");
}

float NWNX_Creature_GetMovementRateFactorCap(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMovementRateFactorCap");
    return NWNXPopFloat();
}

void NWNX_Creature_SetMovementRateFactorCap(object creature, float cap)
{
    NWNXPushFloat(cap);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetMovementRateFactorCap");
}

void NWNX_Creature_SetAlignmentGoodEvil(object creature, int value)
{
    NWNXPushInt(value);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetAlignmentGoodEvil");
}

void NWNX_Creature_SetAlignmentLawChaos(object creature, int value)
{
    NWNXPushInt(value);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetAlignmentLawChaos");
}

void NWNX_Creature_SetSkillRank(object creature, int skill, int rank)
{
    NWNXPushInt(rank);
    NWNXPushInt(skill);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSkillRank");
}

int NWNX_Creature_GetSkillRankByLevel(object creature, int skill, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(skill);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetSkillRankByLevel");
    return NWNXPopInt();
}

void NWNX_Creature_SetSkillRankByLevel(object creature, int skill, int rank, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(rank);
    NWNXPushInt(skill);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSkillRankByLevel");
}

void NWNX_Creature_SetClassByPosition(object creature, int position, int classID, int bUpdateLevels = TRUE)
{
    NWNXPushInt(bUpdateLevels);
    NWNXPushInt(classID);
    NWNXPushInt(position);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetClassByPosition");
}

void NWNX_Creature_SetLevelByPosition(object creature, int position, int level)
{
    NWNXPushInt(level);
    NWNXPushInt(position);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetLevelByPosition");
}

void NWNX_Creature_SetBaseAttackBonus(object creature, int bab)
{
    NWNXPushInt(bab);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetBaseAttackBonus");
}

int NWNX_Creature_GetAttacksPerRound(object creature, int bBaseAPR = FALSE)
{
    NWNXPushInt(bBaseAPR);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetAttacksPerRound");
    return NWNXPopInt();
}

void NWNX_Creature_RestoreFeats(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RestoreFeats");
}

void NWNX_Creature_RestoreSpecialAbilities(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RestoreSpecialAbilities");
}

void NWNX_Creature_RestoreItems(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "RestoreItems");
}

void NWNX_Creature_SetSize(object creature, int size)
{
    NWNXPushInt(size);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSize");
}

int NWNX_Creature_GetSkillPointsRemaining(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetSkillPointsRemaining");
    return NWNXPopInt();
}

void NWNX_Creature_SetSkillPointsRemaining(object creature, int skillpoints)
{
    NWNXPushInt(skillpoints);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSkillPointsRemaining");
}

int NWNX_Creature_GetSkillPointsRemainingByLevel(object creature, int level)
{
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetSkillPointsRemainingByLevel");
    return NWNXPopInt();
}

void NWNX_Creature_SetSkillPointsRemainingByLevel(object creature, int level, int value)
{
    NWNXPushInt(value);
    NWNXPushInt(level);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSkillPointsRemainingByLevel");
}

void NWNX_Creature_SetRacialType(object creature, int racialtype)
{
    NWNXPushInt(racialtype);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetRacialType");
}

int NWNX_Creature_GetMovementType(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetMovementType");
    return NWNXPopInt();
}

void NWNX_Creature_SetWalkRateCap(object creature, float fWalkRate = 2000.0f)
{
    NWNXPushFloat(fWalkRate);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetWalkRateCap");
}

void NWNX_Creature_SetGold(object creature, int gold)
{
    NWNXPushInt(gold);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetGold");
}

void NWNX_Creature_SetCorpseDecayTime(object creature, int nDecayTime)
{
    NWNXPushInt(nDecayTime);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetCorpseDecayTime");
}

int NWNX_Creature_GetBaseSavingThrow(object creature, int which)
{
    NWNXPushInt(which);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetBaseSavingThrow");
    return NWNXPopInt();
}

void NWNX_Creature_SetBaseSavingThrow(object creature, int which, int value)
{
    NWNXPushInt(value);
    NWNXPushInt(which);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetBaseSavingThrow");
}

void NWNX_Creature_LevelUp(object creature, int class, int count = 1, int package = PACKAGE_INVALID)
{
    NWNXPushInt(package);
    NWNXPushInt(count);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "LevelUp");
}

void NWNX_Creature_LevelDown(object creature, int count=1)
{
    NWNXPushInt(count);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "LevelDown");
}

void NWNX_Creature_SetChallengeRating(object creature, float fCR)
{
    NWNXPushFloat(fCR);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetChallengeRating");
}

int NWNX_Creature_GetAttackBonus(object creature, int isMelee = -1, int isTouchAttack = FALSE, int isOffhand = FALSE, int includeBaseAttackBonus = TRUE)
{
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
    NWNXPushInt(includeBaseAttackBonus);
    NWNXPushInt(isOffhand);
    NWNXPushInt(isTouchAttack);
    NWNXPushInt(isMelee);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetAttackBonus");
    return NWNXPopInt();
}

int NWNX_Creature_GetHighestLevelOfFeat(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetHighestLevelOfFeat");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatRemainingUses(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatRemainingUses");
    return NWNXPopInt();
}

int NWNX_Creature_GetFeatTotalUses(object creature, int feat)
{
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetFeatTotalUses");
    return NWNXPopInt();
}

void NWNX_Creature_SetFeatRemainingUses(object creature, int feat, int uses)
{
    NWNXPushInt(uses);
    NWNXPushInt(feat);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetFeatRemainingUses");
}

int NWNX_Creature_GetTotalEffectBonus(object creature, int bonusType=NWNX_CREATURE_BONUS_TYPE_ATTACK, object target=OBJECT_INVALID, int isElemental=0, int isForceMax=0, int savetype=-1, int saveSpecificType=-1, int skill=-1, int abilityScore=-1, int isOffhand=FALSE)
{
    NWNXPushInt(isOffhand);
    NWNXPushInt(abilityScore);
    NWNXPushInt(skill);
    NWNXPushInt(saveSpecificType);
    NWNXPushInt(savetype);
    NWNXPushInt(isForceMax);
    NWNXPushInt(isElemental);
    NWNXPushObject(target);
    NWNXPushInt(bonusType);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetTotalEffectBonus");
    return NWNXPopInt();
}

void NWNX_Creature_SetOriginalName(object creature, string name, int isLastName)
{
    NWNXPushInt(isLastName);
    NWNXPushString(name);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetOriginalName");
}

string NWNX_Creature_GetOriginalName(object creature, int isLastName)
{
    NWNXPushInt(isLastName);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetOriginalName");
    return NWNXPopString();
}

void NWNX_Creature_SetSpellResistance(object creature, int sr)
{
    NWNXPushInt(sr);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSpellResistance");
}

void NWNX_Creature_SetAnimalCompanionCreatureType(object creature, int type)
{
    NWNXPushInt(type);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetAnimalCompanionCreatureType");
}

void NWNX_Creature_SetFamiliarCreatureType(object creature, int type)
{
    NWNXPushInt(type);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetFamiliarCreatureType");
}

void NWNX_Creature_SetAnimalCompanionName(object creature, string name)
{
    NWNXPushString(name);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetAnimalCompanionName");
}

void NWNX_Creature_SetFamiliarName(object creature, string name)
{
    NWNXPushString(name);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetFamiliarName");
}

int NWNX_Creature_GetDisarmable(object creature)
{
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "GetDisarmable");
    return NWNXPopInt();
}

void NWNX_Creature_SetDisarmable(object creature, int disarmable)
{
    NWNXPushInt(disarmable);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetDisarmable");
}

void NWNX_Creature_SetDomain(object creature, int class, int index, int domain)
{
    NWNXPushInt(domain);
    NWNXPushInt(index);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetDomain");
}

void NWNX_Creature_SetSpecialization(object creature, int class, int school)
{
    NWNXPushInt(school);
    NWNXPushInt(class);
    NWNXPushObject(creature);
    NWNXCall(NWNX_Creature, "SetSpecialization");
}

void NWNX_Creature_SetFaction(object oCreature, int nFactionId)
{
    NWNXPushInt(nFactionId);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetFaction");
}

int NWNX_Creature_GetFaction(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetFaction");
    return NWNXPopInt();
}

int NWNX_Creature_GetFlatFooted(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetFlatFooted");
    return NWNXPopInt();
}

string NWNX_Creature_SerializeQuickbar(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SerializeQuickbar");
    return NWNXPopString();
}

int NWNX_Creature_DeserializeQuickbar(object oCreature, string sSerializedQuickbar)
{
    NWNXPushString(sSerializedQuickbar);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "DeserializeQuickbar");
    return NWNXPopInt();
}

void NWNX_Creature_SetCasterLevelModifier(object oCreature, int nClass, int nModifier, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nModifier);
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCasterLevelModifier");
}

int NWNX_Creature_GetCasterLevelModifier(object oCreature, int nClass)
{
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetCasterLevelModifier");
    return NWNXPopInt();
}

void NWNX_Creature_SetCasterLevelOverride(object oCreature, int nClass, int nCasterLevel, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nCasterLevel);
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCasterLevelOverride");
}

int NWNX_Creature_GetCasterLevelOverride(object oCreature, int nClass)
{
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetCasterLevelOverride");
    return NWNXPopInt();
}

void NWNX_Creature_JumpToLimbo(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "JumpToLimbo");
}

void NWNX_Creature_SetCriticalMultiplierModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(bPersist);
    NWNXPushInt(nHand);
    NWNXPushInt(nModifier);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCriticalMultiplierModifier");
}

int NWNX_Creature_GetCriticalMultiplierModifier(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(nHand);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetCriticalMultiplierModifier");
    return NWNXPopInt();
}

void NWNX_Creature_SetCriticalMultiplierOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(bPersist);
    NWNXPushInt(nHand);
    NWNXPushInt(nOverride);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCriticalMultiplierOverride");
}

int NWNX_Creature_GetCriticalMultiplierOverride(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(nHand);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetCriticalMultiplierOverride");
    return NWNXPopInt();
}

void NWNX_Creature_SetCriticalRangeModifier(object oCreature, int nModifier, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(bPersist);
    NWNXPushInt(nHand);
    NWNXPushInt(nModifier);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCriticalRangeModifier");
}

int NWNX_Creature_GetCriticalRangeModifier(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(nHand);
    NWNXPushObject(oCreature);

    NWNXCall(NWNX_Creature, "GetCriticalRangeModifier");
    return NWNXPopInt();
}

void NWNX_Creature_SetCriticalRangeOverride(object oCreature, int nOverride, int nHand = 0, int bPersist = FALSE, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(bPersist);
    NWNXPushInt(nHand);
    NWNXPushInt(nOverride);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCriticalRangeOverride");
}

int NWNX_Creature_GetCriticalRangeOverride(object oCreature, int nHand = 0, int nBaseItem = -1)
{
    NWNXPushInt(nBaseItem);
    NWNXPushInt(nHand);
    NWNXPushObject(oCreature);

    NWNXCall(NWNX_Creature, "GetCriticalRangeOverride");
    return NWNXPopInt();
}

void NWNX_Creature_AddAssociate(object oCreature, object oAssociate, int nAssociateType)
{
    NWNXPushInt(nAssociateType);
    NWNXPushObject(oAssociate);
    NWNXPushObject(oCreature);

    NWNXCall(NWNX_Creature, "AddAssociate");
}

void NWNX_Creature_OverrideDamageLevel(object oCreature, int nDamageLevel)
{
    NWNXPushInt(nDamageLevel);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "OverrideDamageLevel");
}

void NWNX_Creature_SetEncounter(object oCreature, object oEncounter)
{
    NWNXPushObject(oEncounter);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetEncounter");
}

object NWNX_Creature_GetEncounter(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetEncounter");
    return NWNXPopObject();
}

int NWNX_Creature_GetIsBartering(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetIsBartering");
    return NWNXPopInt();
}

void NWNX_Creature_SetLastItemCasterLevel(object oCreature, int nCasterLvl)
{
    NWNXPushInt(nCasterLvl);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetLastItemCasterLevel");
}


int NWNX_Creature_GetLastItemCasterLevel(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetLastItemCasterLevel");
    return NWNXPopInt();
}

int NWNX_Creature_GetArmorClassVersus(object oAttacked, object oVersus, int nTouch=FALSE)
{
    NWNXPushInt(nTouch);
    NWNXPushObject(oVersus);
    NWNXPushObject(oAttacked);
    NWNXCall(NWNX_Creature, "GetArmorClassVersus");
    return NWNXPopInt();
}

int NWNX_Creature_GetWalkAnimation(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetWalkAnimation");
    return NWNXPopInt();
}

void NWNX_Creature_SetWalkAnimation(object oCreature, int nAnimation)
{
    NWNXPushInt(nAnimation);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetWalkAnimation");
}

void NWNX_Creature_SetAttackRollOverride(object oCreature, int nRoll, int nModifier)
{
    NWNXPushInt(nModifier);
    NWNXPushInt(nRoll);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetAttackRollOverride");
}

void NWNX_Creature_SetParryAllAttacks(object oCreature, int bParry)
{
    NWNXPushInt(bParry);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetParryAllAttacks");
}

int NWNX_Creature_GetNoPermanentDeath(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetNoPermanentDeath");
    return NWNXPopInt();
}

void NWNX_Creature_SetNoPermanentDeath(object oCreature, int bNoPermanentDeath)
{
    NWNXPushInt(bNoPermanentDeath);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetNoPermanentDeath");
}

vector NWNX_Creature_ComputeSafeLocation(object oCreature, vector vPosition, float fRadius = 20.0f, int bWalkStraightLineRequired = TRUE)
{
    NWNXPushInt(bWalkStraightLineRequired);
    NWNXPushFloat(fRadius);
    NWNXPushVector(vPosition);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "ComputeSafeLocation");
    return NWNXPopVector();
}

void NWNX_Creature_DoPerceptionUpdateOnCreature(object oCreature, object oTargetCreature)
{
    NWNXPushObject(oTargetCreature);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "DoPerceptionUpdateOnCreature");
}

float NWNX_Creature_GetPersonalSpace(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetPersonalSpace");
    return NWNXPopFloat();
}

void NWNX_Creature_SetPersonalSpace(object oCreature, float fPerspace)
{
    NWNXPushFloat(fPerspace);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetPersonalSpace");
}

float NWNX_Creature_GetCreaturePersonalSpace(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetCreaturePersonalSpace");
    return NWNXPopFloat();
}

void NWNX_Creature_SetCreaturePersonalSpace(object oCreature, float fCrePerspace)
{
    NWNXPushFloat(fCrePerspace);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetCreaturePersonalSpace");
}

float NWNX_Creature_GetHeight(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetHeight");
    return NWNXPopFloat();
}

void NWNX_Creature_SetHeight(object oCreature, float fHeight)
{
    NWNXPushFloat(fHeight);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetHeight");
}

float NWNX_Creature_GetHitDistance(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetHitDistance");
    return NWNXPopFloat();
}

void NWNX_Creature_SetHitDistance(object oCreature, float fHitDist)
{
    NWNXPushFloat(fHitDist);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetHitDistance");
}

float NWNX_Creature_GetPreferredAttackDistance(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetPreferredAttackDistance");
    return NWNXPopFloat();
}

void NWNX_Creature_SetPreferredAttackDistance(object oCreature, float fPrefAtckDist)
{
    NWNXPushFloat(fPrefAtckDist);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetPreferredAttackDistance");
}

int NWNX_Creature_GetArmorCheckPenalty(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetArmorCheckPenalty");
    return NWNXPopInt();
}

int NWNX_Creature_GetShieldCheckPenalty(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetShieldCheckPenalty");
    return NWNXPopInt();
}

void NWNX_Creature_SetBypassEffectImmunity(object oCreature, int nImmunityType, int nChance = 100, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nChance);
    NWNXPushInt(nImmunityType);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetBypassEffectImmunity");
}

int NWNX_Creature_GetBypassEffectImmunity(object oCreature, int nImmunityType)
{
    NWNXPushInt(nImmunityType);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetBypassEffectImmunity");
    return NWNXPopInt();
}

void NWNX_Creature_SetLastKiller(object oCreature, object oKiller)
{
    NWNXPushObject(oKiller);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetLastKiller");
}

void NWNX_Creature_DoItemCastSpell(object oCreature, object oTarget, location locTarget, int nSpellID, int nCasterLevel, float fProjectileTime, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int nProjectileSpellID = -1, object oItem = OBJECT_INVALID, string sImpactScript = "")
{
    NWNXPushString(sImpactScript);
    NWNXPushObject(oItem);
    NWNXPushInt(nProjectileSpellID);
    NWNXPushInt(nProjectilePathType);
    NWNXPushFloat(fProjectileTime);
    NWNXPushInt(nCasterLevel);
    NWNXPushInt(nSpellID);
    NWNXPushLocation(locTarget);
    NWNXPushObject(oTarget);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "DoItemCastSpell");
}

int NWNX_Creature_RunEquip(object oCreature, object oItem, int nInventorySlot)
{
    NWNXPushInt(nInventorySlot);
    NWNXPushObject(oItem);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "RunEquip");
    return NWNXPopInt();
}

int NWNX_Creature_RunUnequip(object oCreature, object oItem)
{
    NWNXPushObject(oItem);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "RunUnequip");
    return NWNXPopInt();
}

void NWNX_Creature_OverrideRangedProjectileVFX(object oCreature, int nProjectileVFX, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nProjectileVFX);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "OverrideRangedProjectileVFX");
}

void NWNX_Creature_SetInitiativeModifier(object oCreature, int nMod, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nMod);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetInitiativeModifier");
}

int NWNX_Creature_GetInitiativeModifier(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetInitiativeModifier");
    return NWNXPopInt();
}

object NWNX_Creature_GetBodyBag(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetBodyBag");
    return NWNXPopObject();
}

int NWNX_Creature_AddCastSpellActions(object oCreature, object oTarget, vector vTargetLocation, int nSpellID, int nMultiClass, int nMetaMagic = METAMAGIC_NONE, int nDomainLevel = 0, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstant = FALSE, int bClearActions = FALSE, int bAddToFront = FALSE)
{
    NWNXPushInt(bAddToFront);
    NWNXPushInt(bClearActions);
    NWNXPushInt(bInstant);
    NWNXPushInt(nProjectilePathType);
    NWNXPushInt(nDomainLevel);
    NWNXPushInt(nMetaMagic);
    NWNXPushInt(nMultiClass);
    NWNXPushInt(nSpellID);
    NWNXPushVector(vTargetLocation);
    NWNXPushObject(oTarget);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "AddCastSpellActions");
    return NWNXPopInt();
}

int NWNX_Creature_GetIsFlanking(object oCreature, object oTargetCreature)
{
    NWNXPushObject(oTargetCreature);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetIsFlanking");
    return NWNXPopInt();
}

void NWNX_Creature_DecrementRemainingSpellSlots(object oCreature, int nClass, int nSpellLevel)
{
    NWNXPushInt(nSpellLevel);
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "DecrementRemainingSpellSlots");
}

void NWNX_Creature_IncrementRemainingSpellSlots(object oCreature, int nClass, int nSpellLevel)
{
    NWNXPushInt(nSpellLevel);
    NWNXPushInt(nClass);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "IncrementRemainingSpellSlots");
}

int NWNX_Creature_GetMaximumBonusAttacks(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetMaximumBonusAttacks");
    return NWNXPopInt();
}

void NWNX_Creature_SetMaximumBonusAttacks(object oCreature, int nMaxBonusAttacks, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nMaxBonusAttacks);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetMaximumBonusAttacks");
}

void NWNX_Creature_DoCleaveAttack(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "DoCleaveAttack");
}

object NWNX_Creature_GetLockOrientationToObject(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetLockOrientationToObject");
    return NWNXPopObject();
}

void NWNX_Creature_SetLockOrientationToObject(object oCreature, object oTarget)
{
    NWNXPushObject(oTarget);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetLockOrientationToObject");
}

void NWNX_Creature_BroadcastAttackOfOpportunity(object oCreature, object oSingleCreature = OBJECT_INVALID, int bMovement = FALSE)
{
    NWNXPushInt(bMovement);
    NWNXPushObject(oSingleCreature);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "BroadcastAttackOfOpportunity");
}

int NWNX_Creature_GetMaxSellToStorePriceOverride(object oCreature, object oStore)
{
    NWNXPushObject(oStore);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetMaxSellToStorePriceOverride");

    return NWNXPopInt();
}

void NWNX_Creature_SetMaxSellToStorePriceOverride(object oCreature, object oStore, int nMaxSellToPrice)
{
    NWNXPushInt(nMaxSellToPrice);
    NWNXPushObject(oStore);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetMaxSellToStorePriceOverride");
}

int NWNX_Creature_GetAbilityIncreaseByLevel(object oCreature, int nLevel)
{
    NWNXPushInt(nLevel);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetAbilityIncreaseByLevel");
    return NWNXPopInt();
}

void NWNX_Creature_SetAbilityIncreaseByLevel(object oCreature, int nLevel, int nAbility)
{
    NWNXPushInt(nAbility);
    NWNXPushInt(nLevel);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetAbilityIncreaseByLevel");
}

float NWNX_Creature_GetMaxAttackRange(object oCreature, object oTarget)
{
    NWNXPushObject(oTarget);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetMaxAttackRange");
    return NWNXPopFloat();
}

int NWNX_Creature_GetMulticlassLimit(object oCreature)
{
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "GetMulticlassLimit");
    return NWNXPopInt();
}


void NWNX_Creature_SetMulticlassLimit(object oCreature, int nLimit, int bPersist = FALSE)
{
    NWNXPushInt(bPersist);
    NWNXPushInt(nLimit);
    NWNXPushObject(oCreature);
    NWNXCall(NWNX_Creature, "SetMulticlassLimit");
}
