/// @addtogroup feat Feat
/// @brief Define feat bonuses/penalties
/// @{
/// @file nwnx_feat.nss
#include "nwnx"

const string NWNX_Feat = "NWNX_Feat"; ///< @private

/// @name Feat Modifiers
/// @anchor feat_modifiers
///
/// @{
const int NWNX_FEAT_MODIFIER_INVALID            = 0;
const int NWNX_FEAT_MODIFIER_AB                 = 1;
const int NWNX_FEAT_MODIFIER_ABILITY            = 2;
const int NWNX_FEAT_MODIFIER_ABVSRACE           = 3;
const int NWNX_FEAT_MODIFIER_AC                 = 4;
const int NWNX_FEAT_MODIFIER_ACVSRACE           = 5;
const int NWNX_FEAT_MODIFIER_ARCANESPELLFAILURE = 6;
const int NWNX_FEAT_MODIFIER_CONCEALMENT        = 7;
const int NWNX_FEAT_MODIFIER_DMGIMMUNITY        = 8;
const int NWNX_FEAT_MODIFIER_DMGREDUCTION       = 9;
const int NWNX_FEAT_MODIFIER_DMGRESIST          = 10;
const int NWNX_FEAT_MODIFIER_IMMUNITY           = 11;
const int NWNX_FEAT_MODIFIER_MOVEMENTSPEED      = 12;
const int NWNX_FEAT_MODIFIER_REGENERATION       = 13;
const int NWNX_FEAT_MODIFIER_SAVE               = 14;
const int NWNX_FEAT_MODIFIER_SAVEVSRACE         = 15;
const int NWNX_FEAT_MODIFIER_SAVEVSTYPE         = 16;
const int NWNX_FEAT_MODIFIER_SAVEVSTYPERACE     = 17;
const int NWNX_FEAT_MODIFIER_SPELLIMMUNITY      = 18;
const int NWNX_FEAT_MODIFIER_SRCHARGEN          = 19;
const int NWNX_FEAT_MODIFIER_SRINCLEVEL         = 20;
///@}

/// @brief Sets a feat modifier.
/// @param iFeat The Feat constant or value in feat.2da.
/// @param iMod The @ref feat_modifiers "feat modifier" to set.
/// @param iParam1, iParam2, iParam3, iParam4 The parameters for this feat modifier.
void NWNX_Feat_SetFeatModifier(int iFeat, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF, int iParam4 = 0xDEADBEEF);

/// @}

void NWNX_Feat_SetFeatModifier(int iFeat, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF, int iParam4 = 0xDEADBEEF)
{
    string sFunc = "SetFeatModifier";

    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iParam4);
    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iParam3);
    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iParam2);
    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iParam1);
    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iMod);
    NWNX_PushArgumentInt(NWNX_Feat, sFunc, iFeat);

    NWNX_CallFunction(NWNX_Feat, sFunc);
}
