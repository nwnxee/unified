// The following functions have been removed from NWNX, please replace them with their basegame implementation!
// To use this file, include it to nwnx.nss and recompile all your scripts.

// *** NWNX_Creature

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

/// @struct NWNX_Creature_MemorisedSpell
/// @brief A memorised spell structure.
struct NWNX_Creature_MemorisedSpell
{
    int id; ///< Spell ID
    int ready; ///< Whether the spell can be cast
    int meta; ///< Metamagic type, if any
    int domain; ///< Clerical domain, if any
};

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

/// @brief Get the soundset index for creature.
/// @param creature The creature object.
/// @return The soundset used by the creature.
int NWNX_Creature_GetSoundset(object creature);

/// @brief Set the soundset index for creature.
/// @param creature The creature object.
/// @param soundset The soundset index.
void NWNX_Creature_SetSoundset(object creature, int soundset);

/// @brief Sets the creature gender.
/// @param creature The creature object.
/// @param gender The GENDER_ constant.
void NWNX_Creature_SetGender(object creature, int gender);

/// @brief Restore all creature spells per day for given level.
/// @param creature The creature object.
/// @param level The level to restore. If -1, all spells are restored.
void NWNX_Creature_RestoreSpells(object creature, int level = -1);

/// @brief Gets one of creature's domains.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @param index The first or second domain.
/// @deprecated Use GetDomain(). This will be removed in future NWNX releases.
int NWNX_Creature_GetDomain(object creature, int class, int index);

/// @brief Gets the creature's specialist school.
/// @param creature The creature object.
/// @param class The class id from classes.2da. (Not class index 0-2)
/// @deprecated Use GetSpecialization(). This will be removed in future NWNX releases.
int NWNX_Creature_GetSpecialization(object creature, int class);

/// @brief Get the number of uses left of a spell.
/// @note This function is for caster classes that don't need to memorize spells.
/// @param oCreature The creature.
/// @param nSpellID The spell ID.
/// @param nMultiClass The position of the class to check, 0-2
/// @param nDomainLevel The domain level if checking a domain spell.
/// @param nMetaMagic A METAMAGIC_* constant.
/// @return The number of spell uses left or 0 on error.
int NWNX_Creature_GetSpellUsesLeft(object oCreature, int nSpellID, int nMultiClass, int nDomainLevel = 0, int nMetaMagic = METAMAGIC_NONE);

/// @brief Get the number of memorized ready spells by spellid.
/// @note This function is for caster classes that need to memorize spells.
/// @param oCreature The creature.
/// @param nSpellID The spell ID.
/// @param nMultiClass The position of the class to check, 0-2
/// @param nMetaMagic A METAMAGIC_* constant.
/// @return The number of spell uses left or 0 on error.
int NWNX_Creature_GetMemorizedSpellReadyCount(object oCreature, int nSpellID, int nMultiClass, int nMetaMagic = METAMAGIC_NONE);

/// @brief Set whether an effect icon is flashing or not.
/// @param oCreature The target creature.
/// @param nIconId The icon id, see effecticons.2da.
/// @param bFlashing TRUE for flashing, FALSE for not flashing.
void NWNX_Creature_SetEffectIconFlashing(object oCreature, int nIconId, int bFlashing);

int NWNX_Creature_GetMemorisedSpellCountByLevel(object creature, int class, int level)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetMemorisedSpellCountByLevel");
    return GetMemorizedSpellCountByLevel(creature, class, level);
}

struct NWNX_Creature_MemorisedSpell NWNX_Creature_GetMemorisedSpell(object creature, int class, int level, int index)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetMemorisedSpell");
    struct NWNX_Creature_MemorisedSpell spell;
    spell.domain = GetMemorizedSpellIsDomainSpell(creature, class, level, index);
    spell.meta   = GetMemorizedSpellMetaMagic(creature, class, level, index);
    spell.ready  = GetMemorizedSpellReady(creature, class, level, index);
    spell.id     = GetMemorizedSpellId(creature, class, level, index);
    return spell;
}

void NWNX_Creature_SetMemorisedSpell(object creature, int class, int level, int index, struct NWNX_Creature_MemorisedSpell spell)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_SetMemorisedSpell");
    SetMemorizedSpell(creature, class, level, index, spell.id, spell.ready, spell.meta, spell.domain);
}

int NWNX_Creature_GetKnownSpellCount(object creature, int class, int level)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetKnownSpellCount");
    return GetKnownSpellCount(creature, class, level);
}

int NWNX_Creature_GetKnownSpell(object creature, int class, int level, int index)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetKnownSpell");
    return GetKnownSpellId(creature, class, level, index);
}

void NWNX_Creature_ClearMemorisedKnownSpells(object creature, int class, int spellId)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_ClearMemorisedKnownSpells");
    ClearMemorizedSpellBySpellId(creature, class, spellId);
}

void NWNX_Creature_ClearMemorisedSpell(object creature, int class, int level, int index)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_ClearMemorisedSpell");
    ClearMemorizedSpell(creature, class, level, index);
}

int NWNX_Creature_GetSoundset(object creature)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetSoundset");
    return GetSoundset(creature);
}

void NWNX_Creature_SetSoundset(object creature, int soundset)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_SetSoundset");
    SetSoundset(creature, soundset);
}

void NWNX_Creature_SetGender(object creature, int gender)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_SetGender");
    SetGender(creature, gender);
}

void NWNX_Creature_RestoreSpells(object creature, int level = -1)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_RestoreSpells");
    if (level == -1)
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            ReadySpellLevel(creature, i);
        }
    }
    else
        ReadySpellLevel(creature, level);

}

int NWNX_Creature_GetDomain(object creature, int class, int index)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetDomain");
    return GetDomain(creature, index, class);
}

int NWNX_Creature_GetSpecialization(object creature, int class)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetSpecialization");
    return GetSpecialization(creature, class);
}

int NWNX_Creature_GetSpellUsesLeft(object oCreature, int nSpellID, int nMultiClass, int nDomainLevel = 0, int nMetaMagic = METAMAGIC_NONE)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetSpellUsesLeft");
    return GetSpellUsesLeft(oCreature, GetClassByPosition(nMultiClass + 1), nSpellID, nMetaMagic, nDomainLevel);
}

int NWNX_Creature_GetMemorizedSpellReadyCount(object oCreature, int nSpellID, int nMultiClass, int nMetaMagic = METAMAGIC_NONE)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_GetMemorizedSpellReadyCount");
    return GetSpellUsesLeft(oCreature, GetClassByPosition(nMultiClass + 1), nSpellID, nMetaMagic);
}

void NWNX_Creature_SetEffectIconFlashing(object oCreature, int nIconId, int bFlashing)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Creature_SetEffectIconFlashing");
    SetEffectIconFlashing(oCreature, nIconId, bFlashing);
}

// *** NWNX_Effect

/// @brief Set a script with optional data that runs when an effect expires
/// @param e The effect.
/// @param script The script to run when the effect expires.
/// @param data Any other data you wish to send back to the script.
/// @remark OBJECT_SELF in the script is the object the effect is applied to.
/// @note Only works for TEMPORARY and PERMANENT effects applied to an object.
effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "");

/// @brief Get the data set with NWNX_Effect_SetEffectExpiredScript()
/// @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
/// @return The data attached to the effect.
string NWNX_Effect_GetEffectExpiredData();

/// @brief Get the effect creator.
/// @note Should only be called from a script set with NWNX_Effect_SetEffectExpiredScript().
/// @return The object from which the effect originated.
object NWNX_Effect_GetEffectExpiredCreator();

/// @brief Accessorize an EffectVisualEffect(), making it undispellable and unable to be removed by resting or death.
/// @note If linked with a non-visualeffect or a non-accessorized visualeffect it *will* get removed.
/// @param eEffect An EffectVisualEffect(), does not work for other effect types.
/// @return The accessorized effect or an unchanged effect if not an EffectVisualEffect().
effect NWNX_Effect_AccessorizeVisualEffect(effect eEffect);

effect NWNX_Effect_SetEffectExpiredScript(effect e, string script, string data = "")
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Effect_SetEffectExpiredScript");
    return EffectLinkEffects(EffectRunScript("", script, "", 0.0f, data), e);
}

string NWNX_Effect_GetEffectExpiredData()
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Effect_GetEffectExpiredData");
    return GetEffectString(GetLastRunScriptEffect(), 0);
}

object NWNX_Effect_GetEffectExpiredCreator()
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Effect_GetEffectExpiredCreator");
    return GetEffectCreator(GetLastRunScriptEffect());
}

effect NWNX_Effect_AccessorizeVisualEffect(effect eEffect)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Effect_AccessorizeVisualEffect");
    if (GetEffectType(eEffect) == EFFECT_TYPE_VISUALEFFECT)
        return UnyieldingEffect(eEffect);
    else
        return eEffect;
}

// *** NWNX_Object

/// @brief Convert an object id to the actual object.
/// @param id The object id.
/// @return An object from the provided object ID.
/// @remark This is the counterpart to ObjectToString.
/// @deprecated Use the basegame StringToObject() function. This will be removed in a future NWNX release.
object NWNX_Object_StringToObject(string id);

/// @brief Check if an item can fit in an object's inventory.
/// @param obj The object with an inventory.
/// @param baseitem The base item id to check for a fit.
/// @return TRUE if an item of base item type can fit in object's inventory
int NWNX_Object_CheckFit(object obj, int baseitem);

/// @brief Add an effect to an object that displays an icon and has no other effect.
/// @remark See effecticons.2da for a list of possible effect icons.
/// @param obj The object to apply the effect.
/// @param nIcon The icon id.
/// @param fDuration If specified the effect will be temporary and last this length in seconds, otherwise the effect
/// will be permanent.
void NWNX_Object_AddIconEffect(object obj, int nIcon, float fDuration=0.0);

/// @brief Remove an icon effect from an object that was added by the NWNX_Object_AddIconEffect() function.
/// @param obj The object.
/// @param nIcon The icon id.
void NWNX_Object_RemoveIconEffect(object obj, int nIcon);

/// @brief Cause oObject to face fDirection.
/// @note This function is almost identical to SetFacing(), the only difference being that it allows you to specify
/// the target object without the use of AssignCommand(). This is useful when you want to change the facing of an object
/// in an ExecuteScriptChunk() call where AssignCommand() does not work.
/// @param oObject The object to change its facing of
/// @param fDirection The direction the object should face
void NWNX_Object_SetFacing(object oObject, float fDirection);

object NWNX_Object_StringToObject(string id)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Object_StringToObject");
    return StringToObject(id);
}

int NWNX_Object_CheckFit(object obj, int baseitem)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Object_CheckFit");
    return GetBaseItemFitsInInventory(baseitem, obj);
}

void NWNX_Object_AddIconEffect(object obj, int nIcon, float fDuration=0.0)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Object_AddIconEffect");
    effect eEffect = GetFirstEffect(obj);
    while (GetIsEffectValid(eEffect))
    {
        if (GetEffectTag(eEffect) == "NWNX_Object_IconEffect" && GetEffectInteger(eEffect, 0) == nIcon)
            RemoveEffect(obj, eEffect);
        eEffect = GetNextEffect(obj);
    }

    effect eIcon = TagEffect(SupernaturalEffect(EffectIcon(nIcon)), "NWNX_Object_IconEffect");
    ApplyEffectToObject(fDuration == 0.0 ? DURATION_TYPE_PERMANENT : DURATION_TYPE_TEMPORARY, eIcon, obj, fDuration);
}

void NWNX_Object_RemoveIconEffect(object obj, int nIcon)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Object_RemoveIconEffect");
    effect eEffect = GetFirstEffect(obj);
    while (GetIsEffectValid(eEffect))
    {
        if (GetEffectTag(eEffect) == "NWNX_Object_IconEffect" && GetEffectInteger(eEffect, 0) == nIcon)
            RemoveEffect(obj, eEffect);
        eEffect = GetNextEffect(obj);
    }
}

void NWNX_Object_SetFacing(object oObject, float fDirection)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Object_SetFacing");
    AssignCommand(oObject, SetFacing(fDirection));
}

// *** NWNX_Regex

/// @param str The string to search.
/// @param regex The regular expression to use when searching.
/// @return TRUE if string matches the regular expression.
int NWNX_Regex_Search(string str, string regex);

/// @brief Replaces any matches of the regular expression with a string.
/// @param str The string to search.
/// @param regex The regular expression to use when searching.
/// @param replace The string to replace the matches with.
/// @param firstOnly Set to TRUE to only replace the first match.
/// @return A new string with any replacements made.
string NWNX_Regex_Replace(string str, string regex, string replace = "", int firstOnly = FALSE);

/// @brief Returns all matches in a string that match the regular expression.
/// @param str The string to search.
/// @param regex The regular expression to use.
/// @return A json array with json arrays of all (sub)matches. Returns JsonNull() on error.
json NWNX_Regex_Match(string str, string regex);

int NWNX_Regex_Search(string str, string regex)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Regex_Search");
    return JsonGetLength(RegExpMatch(regex, str));
}

string NWNX_Regex_Replace(string str, string regex, string replace="", int firstOnly=0)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Regex_Replace");
    return RegExpReplace(regex, str, replace, firstOnly ? REGEXP_FORMAT_FIRST_ONLY : REGEXP_FORMAT_DEFAULT);
}

json NWNX_Regex_Match(string str, string regex)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Regex_Match");
    return RegExpIterate(regex, str);
}

// *** NWNX_Util

/// @brief Determines if the supplied resref exists.
/// @param resref The resref to check.
/// @param type The @ref resref_types "Resref Type".
/// @return TRUE/FALSE
int NWNX_Util_IsValidResRef(string resref, int type = RESTYPE_UTC);

/// @anchor twoda_row_count
/// @brief Gets the row count for a 2da.
/// @param str The 2da to check (do not include the .2da).
/// @return The amount of rows in the 2da.
int NWNX_Util_Get2DARowCount(string str);

/// @brief Gets the contents of a .nss script file as a string.
/// @param sScriptName The name of the script to get the contents of.
/// @param nMaxLength The max length of the return string, -1 to get everything
/// @return The script file contents or "" on error.
string NWNX_Util_GetNSSContents(string sScriptName, int nMaxLength = -1);

/// @brief Get the ticks per second of the server.
/// @remark Useful to dynamically detect lag and adjust behavior accordingly.
/// @return The ticks per second.
int NWNX_Util_GetServerTicksPerSecond();

int NWNX_Util_IsValidResRef(string resref, int type = RESTYPE_UTC)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Util_IsValidResRef");
    return ResManGetAliasFor(resref, type) != "";
}

int NWNX_Util_Get2DARowCount(string str)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Util_Get2DARowCount");
    return Get2DARowCount(str);
}

string NWNX_Util_GetNSSContents(string sScriptName, int nMaxLength = -1)
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Util_GetNSSContents");
    string s = ResManGetFileContents(sScriptName, RESTYPE_NSS);
    return nMaxLength == -1 ? s : GetStringLeft(s, nMaxLength);
}

int NWNX_Util_GetServerTicksPerSecond()
{
    WriteTimestampedLogEntry("WARNING: Calling deprecated NWNX Function: NWNX_Util_GetServerTicksPerSecond");
    return GetTickRate();
}
