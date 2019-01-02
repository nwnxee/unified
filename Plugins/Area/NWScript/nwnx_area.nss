#include "nwnx"

const int NWNX_AREA_PVP_SETTING_NO_PVP          = 0;
const int NWNX_AREA_PVP_SETTING_PARTY_PVP       = 1;
const int NWNX_AREA_PVP_SETTING_FULL_PVP        = 2;
const int NWNX_AREA_PVP_SETTING_SERVER_DEFAULT  = 3;

const int NWNX_AREA_WEATHER_CHANCE_RAIN         = 0;
const int NWNX_AREA_WEATHER_CHANCE_SNOW         = 1;
const int NWNX_AREA_WEATHER_CHANCE_LIGHTNING    = 2;

// Gets the number of players in area
int NWNX_Area_GetNumberOfPlayersInArea(object area);

// Gets the creature that last entered area
object NWNX_Area_GetLastEntered(object area);

// Gets the creature that last left area
object NWNX_Area_GetLastLeft(object area);

// Get the PVP setting of area
// Returns NWNX_AREA_PVP_SETTING_*
int NWNX_Area_GetPVPSetting(object area);

// Set the PVP setting of area
// pvpSetting = NWNX_AREA_PVP_SETTING_*
int NWNX_Area_SetPVPSetting(object area, int pvpSetting);

// Get the spot modifier of area
int NWNX_Area_GetAreaSpotModifier(object area);

// Set the spot modifier of area
void NWNX_Area_SetAreaSpotModifier(object area, int spotModifier);

// Get the listen modifer of area
int NWNX_Area_GetAreaListenModifier(object area);

// Set the listen modifier of area
void NWNX_Area_SetAreaListenModifier(object area, int listenModifier);

// Returns TRUE if resting is not allowed in area
int NWNX_Area_GetNoRestingAllowed(object area);

// Set whether resting is allowed in area
// TRUE: Resting not allowed
// FALSE: Resting allowed
void NWNX_Area_SetNoRestingAllowed(object area, int bNoRestingAllowed);

// Get the wind power in area
int NWNX_Area_GetWindPower(object area);

// Set the wind power in area
// windPower = 0-2
void NWNX_Area_SetWindPower(object area, int windPower);

// Get the weather chance of type in area
// type = NWNX_AREA_WEATHER_CHANCE_*
int NWNX_Area_GetWeatherChance(object area, int type);

// Set the weather chance of type in area
// type = NWNX_AREA_WEATHER_CHANCE_*
// chance = 0-100
void NWNX_Area_SetWeatherChance(object area, int type, int chance);

const string NWNX_Area = "NWNX_Area";


int NWNX_Area_GetNumberOfPlayersInArea(object area)
{
    string sFunc = "GetNumberOfPlayersInArea";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

object NWNX_Area_GetLastEntered(object area)
{
    string sFunc = "GetLastEntered";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Area, sFunc);
}

object NWNX_Area_GetLastLeft(object area)
{
    string sFunc = "GetLastLeft";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Area, sFunc);
}

int NWNX_Area_GetPVPSetting(object area)
{
    string sFunc = "GetPVPSetting";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetPVPSetting(object area, int pvpSetting)
{
    string sFunc = "SetPVPSetting";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, pvpSetting);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetAreaSpotModifier(object area)
{
    string sFunc = "GetAreaSpotModifier";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetAreaSpotModifier(object area, int spotModifier)
{
    string sFunc = "SetAreaSpotModifier";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, spotModifier);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetAreaListenModifier(object area)
{
    string sFunc = "GetAreaListenModifier";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetAreaListenModifier(object area, int listenModifier)
{
    string sFunc = "SetAreaListenModifier";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, listenModifier);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetNoRestingAllowed(object area)
{
    string sFunc = "GetNoRestingAllowed";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetNoRestingAllowed(object area, int bNoRestingAllowed)
{
    string sFunc = "SetNoRestingAllowed";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, bNoRestingAllowed);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetWindPower(object area)
{
    string sFunc = "GetWindPower";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetWindPower(object area, int windPower)
{
    string sFunc = "SetWindPower";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, windPower);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetWeatherChance(object area, int type)
{
    string sFunc = "GetWeatherChance";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, type);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetWeatherChance(object area, int type, int chance)
{
    string sFunc = "SetWeatherChance";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, chance);
    NWNX_PushArgumentInt(NWNX_Area, sFunc, type);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}
