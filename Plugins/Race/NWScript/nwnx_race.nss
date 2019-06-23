#include "nwnx"

const int NWNX_RACE_MODIFIER_INVALID       = 0;
const int NWNX_RACE_MODIFIER_AB            = 1;
const int NWNX_RACE_MODIFIER_ABVSRACE      = 2;
const int NWNX_RACE_MODIFIER_AC            = 3;
const int NWNX_RACE_MODIFIER_ACVSRACE      = 4;
const int NWNX_RACE_MODIFIER_CONCEALMENT   = 5;
const int NWNX_RACE_MODIFIER_DMGIMMUNITY   = 6;
const int NWNX_RACE_MODIFIER_DMGREDUCTION  = 7;
const int NWNX_RACE_MODIFIER_DMGRESIST     = 8;
const int NWNX_RACE_MODIFIER_FEAT          = 9;
const int NWNX_RACE_MODIFIER_FEATUSAGE     = 10;
const int NWNX_RACE_MODIFIER_IMMUNITY      = 11;
const int NWNX_RACE_MODIFIER_INITIATIVE    = 12;
const int NWNX_RACE_MODIFIER_MOVEMENTSPEED = 13;
const int NWNX_RACE_MODIFIER_RACE          = 14;
const int NWNX_RACE_MODIFIER_REGENERATION  = 15;
const int NWNX_RACE_MODIFIER_SAVE          = 16;
const int NWNX_RACE_MODIFIER_SAVEVSRACE    = 17;
const int NWNX_RACE_MODIFIER_SAVEVSTYPE    = 18;
const int NWNX_RACE_MODIFIER_SKILL         = 19;
const int NWNX_RACE_MODIFIER_SPELLIMMUNITY = 20;
const int NWNX_RACE_MODIFIER_SRCHARGEN     = 21;
const int NWNX_RACE_MODIFIER_SRINCLEVEL    = 22;

// Set a racial modifier
void NWNX_Race_SetRacialModifier(int iRace, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF);

const string NWNX_Race = "NWNX_Race";


void NWNX_Race_SetRacialModifier(int iRace, int iMod, int iParam1, int iParam2 = 0xDEADBEEF, int iParam3 = 0xDEADBEEF)
{
    string sFunc = "SetRacialModifier";

    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam3);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam2);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iParam1);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iMod);
    NWNX_PushArgumentInt(NWNX_Race, sFunc, iRace);

    NWNX_CallFunction(NWNX_Race, sFunc);
}
