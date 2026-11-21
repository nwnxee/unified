/// @addtogroup itemappearance ItemAppearance
/// @brief Lists the appearances an item can take, with rules to leave some out.
/// @{
/// @file nwnx_itemapp.nss

const string NWNX_ItemAppearance = "NWNX_ItemAppearance"; ///< @private

/// @brief A random weapon appearance: model * 10 + color for each part, -1 if none was found.
struct NWNX_ItemAppearance_Weapon
{
    int nBottom;
    int nMiddle;
    int nTop;
};

/// @brief Build the appearance lists from the icons in the module and haks, and clear all rules.
/// @remark Call once on module load, before adding rules.
void NWNX_ItemAppearance_CacheAppearances();

/// @brief Leave out the appearances matching every given range.
/// @remark A range is "*" (any), or a comma separated list of "n", "n-m", "-m" (up to m) and "n-" (n and up).
/// @remark Simple items (rings, shields, cloaks, helmets) only use sBot, matched against the model number. A rule
/// for one of them with any other range is ignored, with a warning in the log.
/// Weapons match sBot, sMid and sTop against the model and sBotC, sMidC and sTopC against the color.
/// @param nBaseItem The BASE_ITEM_* the rule is for (it applies to every base item of the same item class).
/// @param sBot Bottom model range (the model number for simple items).
/// @param sMid Middle model range.
/// @param sTop Top model range.
/// @param sBotC Bottom color range.
/// @param sMidC Middle color range.
/// @param sTopC Top color range.
void NWNX_ItemAppearance_BlacklistAppearance(int nBaseItem, string sBot = "*", string sMid = "*", string sTop = "*", string sBotC = "*", string sMidC = "*", string sTopC = "*");

/// @brief The weapon models in sModels may only be used on all three parts together.
/// @param nBaseItem The BASE_ITEM_* the rule is for.
/// @param sModels A range, as in NWNX_ItemAppearance_BlacklistAppearance().
void NWNX_ItemAppearance_SyncAppearance(int nBaseItem, string sModels);

/// @brief A random appearance for one part of an item, allowed with its other parts as they are.
/// @remark A single part never lands on a synced model, since the other parts would no longer match. Use
/// NWNX_ItemAppearance_GetRandomWeaponAppearance() or NWNX_ItemAppearance_GetNextWeaponAppearance() for those.
/// @param oItem The item.
/// @param nPart For weapons, ITEM_APPR_WEAPON_MODEL_*. Ignored for simple items.
/// @return The model number for simple items, model * 10 + color for weapons, -1 if there is none.
int NWNX_ItemAppearance_GetRandomAppearance(object oItem, int nPart = 0);

/// @brief A random appearance for all three parts of a weapon.
/// @remark A synced model picked for the bottom is used for all three parts. The models are picked evenly, not
/// the model and color together, so a model with many colors isn't favored. Only returns -1 if no weapon is allowed.
/// @param oItem The weapon.
/// @return The appearance; all parts are -1 if none was found.
struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetRandomWeaponAppearance(object oItem);

/// @brief The next allowed appearance for all three parts of a weapon, by bottom model, wrapping around.
/// @remark The middle and top parts stay as they are if the rules allow it. Otherwise they take the new bottom model
/// (all three parts do for a synced model), or failing that the first model that isn't synced. The current color
/// is kept where the new model has it.
/// @param oItem The weapon.
/// @return The appearance, the current one if it is the only one allowed; all parts are -1 if none is.
struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetNextWeaponAppearance(object oItem);

/// @brief The previous allowed appearance for all three parts of a weapon, by bottom model, wrapping around.
/// @param oItem The weapon.
/// @return As NWNX_ItemAppearance_GetNextWeaponAppearance(), for the previous model.
struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetPreviousWeaponAppearance(object oItem);

/// @brief The next allowed appearance for one part of an item, wrapping around.
/// @param oItem The item.
/// @param nPart For weapons, ITEM_APPR_WEAPON_MODEL_*. Ignored for simple items.
/// @return The model number for simple items. For weapons, model * 10 + color of the next model, keeping the
/// current color if the model has it. The current appearance if it is the only one allowed, -1 if none is.
int NWNX_ItemAppearance_GetNextAppearance(object oItem, int nPart = 0);

/// @brief The previous allowed appearance for one part of an item, wrapping around.
/// @param oItem The item.
/// @param nPart For weapons, ITEM_APPR_WEAPON_MODEL_*. Ignored for simple items.
/// @return As NWNX_ItemAppearance_GetNextAppearance(), for the previous model.
int NWNX_ItemAppearance_GetPreviousAppearance(object oItem, int nPart = 0);

/// @brief The next allowed color of one weapon part's current model, wrapping around.
/// @param oItem The item.
/// @param nPart ITEM_APPR_WEAPON_COLOR_*.
/// @return The color (0-9), -1 if none is allowed. Simple items return the next appearance.
int NWNX_ItemAppearance_GetNextColor(object oItem, int nPart = 0);

/// @brief The previous allowed color of one weapon part's current model, wrapping around.
/// @param oItem The item.
/// @param nPart ITEM_APPR_WEAPON_COLOR_*.
/// @return The color (0-9), -1 if none is allowed. Simple items return the previous appearance.
int NWNX_ItemAppearance_GetPreviousColor(object oItem, int nPart = 0);

/// @}

void NWNX_ItemAppearance_CacheAppearances()
{
    NWNXCall(NWNX_ItemAppearance, "CacheAppearances");
}

void NWNX_ItemAppearance_BlacklistAppearance(int nBaseItem, string sBot = "*", string sMid = "*", string sTop = "*", string sBotC = "*", string sMidC = "*", string sTopC = "*")
{
    NWNXPushString(sTopC);
    NWNXPushString(sMidC);
    NWNXPushString(sBotC);
    NWNXPushString(sTop);
    NWNXPushString(sMid);
    NWNXPushString(sBot);
    NWNXPushInt(nBaseItem);
    NWNXCall(NWNX_ItemAppearance, "BlacklistAppearance");
}

void NWNX_ItemAppearance_SyncAppearance(int nBaseItem, string sModels)
{
    NWNXPushString(sModels);
    NWNXPushInt(nBaseItem);
    NWNXCall(NWNX_ItemAppearance, "SyncAppearance");
}

int NWNX_ItemAppearance_GetRandomAppearance(object oItem, int nPart = 0)
{
    NWNXPushInt(nPart);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetRandomAppearance");
    return NWNXPopInt();
}

struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetRandomWeaponAppearance(object oItem)
{
    struct NWNX_ItemAppearance_Weapon weapon;
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetRandomWeaponAppearance");
    weapon.nTop = NWNXPopInt();
    weapon.nMiddle = NWNXPopInt();
    weapon.nBottom = NWNXPopInt();
    return weapon;
}

struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetNextWeaponAppearance(object oItem)
{
    struct NWNX_ItemAppearance_Weapon weapon;
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetNextWeaponAppearance");
    weapon.nTop = NWNXPopInt();
    weapon.nMiddle = NWNXPopInt();
    weapon.nBottom = NWNXPopInt();
    return weapon;
}

struct NWNX_ItemAppearance_Weapon NWNX_ItemAppearance_GetPreviousWeaponAppearance(object oItem)
{
    struct NWNX_ItemAppearance_Weapon weapon;
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetPreviousWeaponAppearance");
    weapon.nTop = NWNXPopInt();
    weapon.nMiddle = NWNXPopInt();
    weapon.nBottom = NWNXPopInt();
    return weapon;
}

int NWNX_ItemAppearance_GetNextAppearance(object oItem, int nPart = 0)
{
    NWNXPushInt(nPart);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetNextAppearance");
    return NWNXPopInt();
}

int NWNX_ItemAppearance_GetPreviousAppearance(object oItem, int nPart = 0)
{
    NWNXPushInt(nPart);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetPreviousAppearance");
    return NWNXPopInt();
}

int NWNX_ItemAppearance_GetNextColor(object oItem, int nPart = 0)
{
    NWNXPushInt(nPart);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetNextColor");
    return NWNXPopInt();
}

int NWNX_ItemAppearance_GetPreviousColor(object oItem, int nPart = 0)
{
    NWNXPushInt(nPart);
    NWNXPushObject(oItem);
    NWNXCall(NWNX_ItemAppearance, "GetPreviousColor");
    return NWNXPopInt();
}
