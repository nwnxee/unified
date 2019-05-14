#include "nwnx"

const int NWNX_APPEARANCE_TYPE_APPEARANCE       = 0;
const int NWNX_APPEARANCE_TYPE_GENDER           = 1;
const int NWNX_APPEARANCE_TYPE_HITPOINTS        = 2;
const int NWNX_APPEARANCE_TYPE_HAIR_COLOR       = 3;
const int NWNX_APPEARANCE_TYPE_SKIN_COLOR       = 4;
const int NWNX_APPEARANCE_TYPE_PHENOTYPE        = 5;
const int NWNX_APPEARANCE_TYPE_HEAD_TYPE        = 6;
const int NWNX_APPEARANCE_TYPE_SOUNDSET         = 7;
const int NWNX_APPEARANCE_TYPE_TAIL_TYPE        = 8;
const int NWNX_APPEARANCE_TYPE_WING_TYPE        = 9;
const int NWNX_APPEARANCE_TYPE_FOOTSTEP_SOUND   = 10;
const int NWNX_APPEARANCE_TYPE_PORTRAIT         = 11;

// Override oCreature's nType to nValue for oPlayer
// - oCreature can be a PC
//
// nType = NWNX_APPEARANCE_TYPE_APPEARANCE
// nValue = APPEARANCE_TYPE_* or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_GENDER
// nValue = GENDER_* or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_HITPOINTS
// nValue = 0-GetMaxHitPoints(oCreature) or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_HAIR_COLOR
// nType = NWNX_APPEARANCE_TYPE_SKIN_COLOR
// nValue = 0-175 or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_PHENOTYPE
// nValue = PHENOTYPE_* or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_HEAD_TYPE
// nValue = 0-? or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_SOUNDSET
// nValue = See soundset.2da or -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_TAIL_TYPE
// nValue = CREATURE_WING_TYPE_* or see wingmodel.2da, -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_WING_TYPE
// nValue = CREATURE_TAIL_TYPE_* or see tailmodel.2da, -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_FOOTSTEP_SOUND
// nValue = 0-17 or see footstepsounds.2da, -1 to remove
//
// nType = NWNX_APPEARANCE_TYPE_PORTRAIT
// nValue = See portraits.2da, -1 to remove
// NOTE: Does not change the Examine Window portrait
void NWNX_Appearance_SetOverride(object oPlayer, object oCreature, int nType, int nValue);

// Get oCreature's nValue of nType for oPlayer
// - oCreature can be a PC
// Returns -1 when not set
int NWNX_Appearance_GetOverride(object oPlayer, object oCreature, int nType);

const string NWNX_Appearance = "NWNX_Appearance";


void NWNX_Appearance_SetOverride(object oPlayer, object oCreature, int nType, int nValue)
{
    string sFunc = "SetOverride";

    NWNX_PushArgumentInt(NWNX_Appearance, sFunc, nValue);
    NWNX_PushArgumentInt(NWNX_Appearance, sFunc, nType);
    NWNX_PushArgumentObject(NWNX_Appearance, sFunc, oCreature);
    NWNX_PushArgumentObject(NWNX_Appearance, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Appearance, sFunc);
}

int NWNX_Appearance_GetOverride(object oPlayer, object oCreature, int nType)
{
    string sFunc = "GetOverride";

    NWNX_PushArgumentInt(NWNX_Appearance, sFunc, nType);
    NWNX_PushArgumentObject(NWNX_Appearance, sFunc, oCreature);
    NWNX_PushArgumentObject(NWNX_Appearance, sFunc, oPlayer);

    NWNX_CallFunction(NWNX_Appearance, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Appearance, sFunc);
}
