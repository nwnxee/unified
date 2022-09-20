// The following functions have been removed from NWNX, please replace them with their basegame implementation!

// *** NWNX_Creature

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
    return EffectLinkEffects(EffectRunScript("", script, "", 0.0f, data), e);
}

string NWNX_Effect_GetEffectExpiredData()
{
    return GetEffectString(GetLastRunScriptEffect(), 0);
}

object NWNX_Effect_GetEffectExpiredCreator()
{
    return GetEffectCreator(GetLastRunScriptEffect());
}

effect NWNX_Effect_AccessorizeVisualEffect(effect eEffect)
{
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

/// @brief Set an object's hit points.
/// @param obj The object.
/// @param hp The hit points.
void NWNX_Object_SetCurrentHitPoints(object obj, int hp);

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
    return StringToObject(id);
}

void NWNX_Object_SetCurrentHitPoints(object creature, int hp)
{
    SetCurrentHitPoints(creature, hp);
}

int NWNX_Object_CheckFit(object obj, int baseitem)
{
    return GetBaseItemFitsInInventory(baseitem, obj);
}

void NWNX_Object_AddIconEffect(object obj, int nIcon, float fDuration=0.0)
{
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
    return JsonGetLength(RegExpMatch(regex, str));
}

string NWNX_Regex_Replace(string str, string regex, string replace="", int firstOnly=0)
{
    return RegExpReplace(regex, str, replace, firstOnly ? REGEXP_FORMAT_FIRST_ONLY : REGEXP_FORMAT_DEFAULT);
}

json NWNX_Regex_Match(string str, string regex)
{
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

int NWNX_Util_IsValidResRef(string resref, int type = RESTYPE_UTC)
{
    return ResManGetAliasFor(resref, type) != "";
}

int NWNX_Util_Get2DARowCount(string str)
{
    return Get2DARowCount(str);
}

string NWNX_Util_GetNSSContents(string sScriptName, int nMaxLength = -1)
{
    string s = ResManGetFileContents(sScriptName, RESTYPE_NSS;
    return nMaxLength == -1 ? s : GetStringLeft(s, nMaxLength);
}
