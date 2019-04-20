#include "nwnx"

const int NWNX_AREA_PVP_SETTING_NO_PVP              = 0;
const int NWNX_AREA_PVP_SETTING_PARTY_PVP           = 1;
const int NWNX_AREA_PVP_SETTING_FULL_PVP            = 2;
const int NWNX_AREA_PVP_SETTING_SERVER_DEFAULT      = 3;

const int NWNX_AREA_WEATHER_CHANCE_RAIN             = 0;
const int NWNX_AREA_WEATHER_CHANCE_SNOW             = 1;
const int NWNX_AREA_WEATHER_CHANCE_LIGHTNING        = 2;

const int NWNX_AREA_DAYNIGHTCYCLE_CYCLE_DAY_NIGHT   = 0;
const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_BRIGHT     = 1;
const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK       = 2;

const int NWNX_AREA_COLOR_TYPE_MOON_AMBIENT         = 0;
const int NWNX_AREA_COLOR_TYPE_MOON_DIFFUSE         = 1;
const int NWNX_AREA_COLOR_TYPE_SUN_AMBIENT          = 2;
const int NWNX_AREA_COLOR_TYPE_SUN_DIFFUSE          = 3;

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
void NWNX_Area_SetPVPSetting(object area, int pvpSetting);

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

// Get the fog clip distance in area
float NWNX_Area_GetFogClipDistance(object area);

// Set the fog clip distance in area
void NWNX_Area_SetFogClipDistance(object area, float distance);

// Get the shadow opacity of area
int NWNX_Area_GetShadowOpacity(object area);

// Set the shadow opacity of area
// shadowOpacity = 0-100
void NWNX_Area_SetShadowOpacity(object area, int shadowOpacity);

// Get the day/night cycle of area
// Returns NWNX_AREA_DAYNIGHTCYCLE_*
int NWNX_Area_GetDayNightCycle(object area);

// Set the day/night cycle of area
// type = NWNX_AREA_DAYNIGHTCYCLE_*
void NWNX_Area_SetDayNightCycle(object area, int type);

// Get the Sun/Moon Ambient/Diffuse colors of area
// type = NWNX_AREA_COLOR_TYPE_*
//
// Returns FOG_COLOR_* or a custom value, -1 on error
int NWNX_Area_GetSunMoonColors(object area, int type);

// Set the Sun/Moon Ambient/Diffuse colors of area
// type = NWNX_AREA_COLOR_TYPE_*
// color = FOG_COLOR_*
//
// The color can also be represented as a hex RGB number if specific color shades are desired.
// The format of a hex specified color would be 0xFFEEDD where
// FF would represent the amount of red in the color
// EE would represent the amount of green in the color
// DD would represent the amount of blue in the color.
void NWNX_Area_SetSunMoonColors(object area, int type, int color);

// Create and returns a transition (square shaped of specified size) at a location
// Valid object types for the target are DOOR or WAYPOINT.
// If a tag is specified the returning object will have that tag
object NWNX_Area_CreateTransition(object area, object target, float x, float y, float z, float size = 2.0f, string tag="");

// Get the state of a tile animation loop
// nAnimLoop = 1-3
int NWNX_Area_GetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop);

// Set the state of a tile animation loop
// nAnimLoop = 1-3
//
// NOTE: Requires clients to re-enter the area for it to take effect
void NWNX_Area_SetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop, int bEnabled);


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

float NWNX_Area_GetFogClipDistance(object area)
{
    string sFunc = "GetFogClipDistance";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueFloat(NWNX_Area, sFunc);
}

void NWNX_Area_SetFogClipDistance(object area, float distance)
{
    string sFunc = "SetFogClipDistance";

    NWNX_PushArgumentFloat(NWNX_Area, sFunc, distance);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetShadowOpacity(object area)
{
    string sFunc = "GetShadowOpacity";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetShadowOpacity(object area, int shadowOpacity)
{
    string sFunc = "SetShadowOpacity";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, shadowOpacity);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}


int NWNX_Area_GetDayNightCycle(object area)
{
    string sFunc = "GetDayNightCycle";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetDayNightCycle(object area, int type)
{
    string sFunc = "SetDayNightCycle";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, type);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetSunMoonColors(object area, int type)
{
    string sFunc = "GetSunMoonColors";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, type);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetSunMoonColors(object area, int type, int color)
{
    string sFunc = "SetSunMoonColors";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, color);
    NWNX_PushArgumentInt(NWNX_Area, sFunc, type);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

object NWNX_Area_CreateTransition(object area, object target, float x, float y, float z, float size = 2.0f, string tag="")
{
    string sFunc = "CreateTransition";

    NWNX_PushArgumentString(NWNX_Area, sFunc, tag);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, size);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, z);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, y);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, x);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, target);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Area, sFunc);
}

int NWNX_Area_GetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop)
{
    string sFunc = "GetTileAnimationLoop";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, nAnimLoop);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileX);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

void NWNX_Area_SetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop, int bEnabled)
{
    string sFunc = "SetTileAnimationLoop";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, bEnabled);
    NWNX_PushArgumentInt(NWNX_Area, sFunc, nAnimLoop);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileX);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);
}
