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
