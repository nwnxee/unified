/// @addtogroup area Area
/// @brief Functions exposing additional area properties as well as creating transitions.
/// @{
/// @file nwnx_area.nss
#include "nwnx"

const string NWNX_Area = "NWNX_Area"; ///< @private

/// @name Area PVP Settings
/// @anchor area_pvp
/// @{
const int NWNX_AREA_PVP_SETTING_NO_PVP              = 0;
const int NWNX_AREA_PVP_SETTING_PARTY_PVP           = 1;
const int NWNX_AREA_PVP_SETTING_FULL_PVP            = 2;
const int NWNX_AREA_PVP_SETTING_SERVER_DEFAULT      = 3;
/// @}

/// @name Area Weather Settings
/// @anchor area_weather
/// @{
const int NWNX_AREA_WEATHER_CHANCE_RAIN             = 0;
const int NWNX_AREA_WEATHER_CHANCE_SNOW             = 1;
const int NWNX_AREA_WEATHER_CHANCE_LIGHTNING        = 2;
/// @}

/// @name Area Day Night Cycle Settings
/// @anchor area_daynight
/// @{
const int NWNX_AREA_DAYNIGHTCYCLE_CYCLE_DAY_NIGHT   = 0;
const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_BRIGHT     = 1;
const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK       = 2;
/// @}

/// @name Area Sun/Moon Color Settings
/// @anchor area_color
/// @{
const int NWNX_AREA_COLOR_TYPE_MOON_AMBIENT         = 0;
const int NWNX_AREA_COLOR_TYPE_MOON_DIFFUSE         = 1;
const int NWNX_AREA_COLOR_TYPE_SUN_AMBIENT          = 2;
const int NWNX_AREA_COLOR_TYPE_SUN_DIFFUSE          = 3;
/// @}

/// @brief Gets the number of players in area.
/// @param area The area object.
/// @return The player count for the area.
int NWNX_Area_GetNumberOfPlayersInArea(object area);

/// @brief Gets the creature that last entered area.
/// @param area The area object.
/// @return The most recent creature to enter the area.
object NWNX_Area_GetLastEntered(object area);

/// @brief Gets the creature that last left area
/// @param area The area object.
object NWNX_Area_GetLastLeft(object area);

/// @brief Get the PVP setting of area
/// @param area The area object.
/// @return Returns the @ref area_pvp "PVP Setting" for the area.
int NWNX_Area_GetPVPSetting(object area);

/// @brief Set the PVP setting of area
/// @param area The area object.
/// @param pvpSetting One of @ref area_pvp the "PVP Settings".
void NWNX_Area_SetPVPSetting(object area, int pvpSetting);

/// @brief Get the spot modifier of area
/// @param area The area object.
/// @return The value of the Spot skill modifier for this area.
int NWNX_Area_GetAreaSpotModifier(object area);

/// @brief Set the spot modifier of area
/// @param area The area object.
/// @param spotModifier The modifier to the Spot skill for this area.
/// @sa NWNX_SkillRanks_SetAreaModifier() to change any skill modifier.
void NWNX_Area_SetAreaSpotModifier(object area, int spotModifier);

/// @brief Get the listen modifer of area
/// @param area The area object.
/// @return The value of the Listen skill modifier for this area.
int NWNX_Area_GetAreaListenModifier(object area);

/// @brief Set the listen modifier of area
/// @param area The area object.
/// @param listenModifier The modifier to the Listen skill for this area.
/// @sa NWNX_SkillRanks_SetAreaModifier() to change any skill modifier.
void NWNX_Area_SetAreaListenModifier(object area, int listenModifier);

/// @brief Checks the No Resting area flag
/// @param area The area object.
/// @return TRUE if resting is not allowed in area.
int NWNX_Area_GetNoRestingAllowed(object area);

/// @brief Set whether to disable resting in the area.
/// @param area The area object.
/// @param bNoRestingAllowed TRUE to disable resting in the area.
void NWNX_Area_SetNoRestingAllowed(object area, int bNoRestingAllowed);

/// @brief Get the wind power in area
/// @param area The area object.
/// @return The wind power for the area. (0-2)
int NWNX_Area_GetWindPower(object area);

/// @brief Set the wind power in area
/// @param area The area object.
/// @param windPower Set to 0, 1 or 2.
void NWNX_Area_SetWindPower(object area, int windPower);

/// @brief Get the weather chance of type in area
/// @param type A @ref area_weather "Weather Setting".
/// @param area The area object.
/// @return The percentage chance for the weather type. (0-100)
int NWNX_Area_GetWeatherChance(object area, int type);

/// @brief Set the weather chance of type in area
/// @param area The area object.
/// @param type A @ref area_weather "Weather Setting".
/// @param chance The chance this weather event occurs.
void NWNX_Area_SetWeatherChance(object area, int type, int chance);

/// @brief Get the fog clip distance in area
/// @param area The area object.
/// @return The fog clip distance.
float NWNX_Area_GetFogClipDistance(object area);

/// @brief Set the fog clip distance in area
/// @param area The area object.
/// @param distance The new fog clip distance.
void NWNX_Area_SetFogClipDistance(object area, float distance);

/// @brief Get the shadow opacity of area
/// @param area The area object.
/// @return The shadow opacity for the area. (0-100)
int NWNX_Area_GetShadowOpacity(object area);

/// @brief Set the shadow opacity of area
/// @param area The area object.
/// @param shadowOpacity The shadow opacity to set for the area (0-100).
void NWNX_Area_SetShadowOpacity(object area, int shadowOpacity);

/// @brief Get the day/night cycle of area
/// @param area The area object.
/// @return The @ref area_daynight "Day Night Cycle Setting".
int NWNX_Area_GetDayNightCycle(object area);

/// @brief Set the day/night cycle of area
/// @param area The area object.
/// @param type = A @ref area_daynight "Day Night Cycle Setting".
void NWNX_Area_SetDayNightCycle(object area, int type);

/// @brief Get the Sun/Moon Ambient/Diffuse colors of area
/// @param area The area object.
/// @param type = A @ref area_color "Sun/Moon Color Setting".
/// @return A FOG_COLOR_* or a custom value, -1 on error.
int NWNX_Area_GetSunMoonColors(object area, int type);

/// @brief Set the Sun/Moon Ambient/Diffuse colors of area
// type = NWNX_AREA_COLOR_TYPE_*
/// @param area The area object.
/// @param type = A @ref area_color "Sun/Moon Color Setting".
/// @param color = A FOG_COLOR_*.
/// @note The color can also be represented as a hex RGB number if specific color shades are desired.
/// The format of a hex specified color would be 0xFFEEDD where
///  * FF would represent the amount of red in the color
///  * EE would represent the amount of green in the color
///  * DD would represent the amount of blue in the color.
void NWNX_Area_SetSunMoonColors(object area, int type, int color);

/// @brief Create and returns a transition (square shaped of specified size) at a location.
/// @param area The area object.
/// @param target A door or waypoint object.
/// @param x,y,z The position to create the transition.
/// @param size The size of the square.
/// @param tag If specified, the returning object will have this tag.
/// @sa NWNX_Object_SetTriggerGeometry() if you wish to draw the transition as something other than a square.
object NWNX_Area_CreateTransition(object area, object target, float x, float y, float z, float size = 2.0f, string tag="");

/// @brief Get the state of a tile animation loop.
/// @param oArea The area object.
/// @param fTileX, fTileY The coordinates of the tile.
/// @param nAnimLoop The loop to check. (1-3)
/// @return TRUE if the loop is enabled.
int NWNX_Area_GetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop);

/// @brief Set the state of a tile animation loop.
/// @param oArea The area object.
/// @param fTileX, fTileY The coordinates of the tile.
/// @param nAnimLoop The loop to set (1-3).
/// @param bEnabled TRUE or FALSE.
/// @note Requires clients to re-enter the area for it to take effect
void NWNX_Area_SetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop, int bEnabled);

/// @brief Get the name of the tile model from any location.
/// @param oArea The area name.
/// @param fTileX, fTileY The coordinates of the tile.
string NWNX_Area_GetTileModelResRef(object oArea, float fTileX, float fTileY);

/// @brief Test to see if there's a direct, walkable line between two points in the area.
/// @param oArea The area object.
/// @param fStartX, fStartY The starting points.
/// @param fEndX, fEndY The ending points.
/// @param fPerSpace The personal space of a creature. Found in appearance.2da.
/// @param fHeight The height of a creature. Found in appearance.2da.
/// @param bIgnoreDoors Whether to ignore doors in the check.
/// @return
///  * 1 if there is a direct walkable line.
///  * -1 if the line is blocked by terrain.
///  * -2 if the line is blocked by a placeable.
///  * -3 if the line is blocked by a creature.
int NWNX_Area_TestDirectLine(object oArea, float fStartX, float fStartY, float fEndX, float fEndY, float fPerSpace, float fHeight, int bIgnoreDoors=FALSE);

/// @brief Get if the area music is playing.
/// @param oArea The area object.
/// @param bBattleMusic Set to TRUE to get if the battle music is playing.
/// @return TRUE if music is playing
int NWNX_Area_GetMusicIsPlaying(object oArea, int bBattleMusic = FALSE);

/// @brief Create and return a generic trigger (square shaped of specified size) at a location.
/// @param oArea The area object.
/// @param fX, fY, fZ The position to create the trigger.
/// @param sTag If specified, the returned trigger will have this tag.
/// @param fSize The size of the square.
/// @sa NWNX_Object_SetTriggerGeometry() if you wish to draw the trigger as something other than a square.
object NWNX_Area_CreateGenericTrigger(object oArea, float fX, float fY, float fZ, string sTag = "", float fSize = 1.0f);

/// @brief Add oObject to the ExportGIT exclusion list, objects on this list won't be exported when NWNX_Area_ExportGIT() is called.
/// @param oObject The object to add
void NWNX_Area_AddObjectToExclusionList(object oObject);

/// @brief Remove oObject from the ExportGIT exclusion list.
/// @param oObject The object to add
void NWNX_Area_RemoveObjectFromExclusionList(object oObject);

/// @brief Export the GIT of oArea to the UserDirectory/nwnx folder.
/// @note Take care with local objects set on objects, they will likely not reference the same object after a server restart.
/// @param oArea The area to export the GIT of.
/// @param sFileName The filename, 16 characters or less. If left blank the resref of oArea will be used.
/// @param bExportVarTable If TRUE, local variables set on oArea will be exported too.
/// @param bExportUUID If TRUE, the UUID of oArea will be exported, if it has one.
/// @param nObjectFilter One or more OBJECT_TYPE_* constants. These object will not be exported. For example OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
/// will not export creatures and doors. Use OBJECT_TYPE_ALL to filter all objects or 0 to export all objects.
/// @return TRUE if exported successfully, FALSE if not.
int NWNX_Area_ExportGIT(object oArea, string sFileName = "", int bExportVarTable = TRUE, int bExportUUID = TRUE, int nObjectFilter = 0);

/// @}

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

string NWNX_Area_GetTileModelResRef(object oArea, float fTileX, float fTileY)
{
    string sFunc = "GetTileModelResRef";
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fTileX);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueString(NWNX_Area, sFunc);
}

int NWNX_Area_TestDirectLine(object oArea, float fStartX, float fStartY, float fEndX, float fEndY, float fPerSpace, float fHeight, int bIgnoreDoors=FALSE)
{
    string sFunc = "TestDirectLine";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, bIgnoreDoors);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fHeight);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fPerSpace);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fEndY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fEndX);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fStartY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fStartX);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

int NWNX_Area_GetMusicIsPlaying(object oArea, int bBattleMusic = FALSE)
{
    string sFunc = "GetMusicIsPlaying";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, bBattleMusic);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}

object NWNX_Area_CreateGenericTrigger(object oArea, float fX, float fY, float fZ, string sTag = "", float fSize = 1.0f)
{
    string sFunc = "CreateGenericTrigger";

    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fSize);
    NWNX_PushArgumentString(NWNX_Area, sFunc, sTag);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fZ);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fY);
    NWNX_PushArgumentFloat(NWNX_Area, sFunc, fX);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject(NWNX_Area, sFunc);
}

void NWNX_Area_AddObjectToExclusionList(object oObject)
{
    string sFunc = "AddObjectToExclusionList";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, oObject);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

void NWNX_Area_RemoveObjectFromExclusionList(object oObject)
{
    string sFunc = "RemoveObjectFromExclusionList";

    NWNX_PushArgumentObject(NWNX_Area, sFunc, oObject);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_ExportGIT(object oArea, string sFileName = "", int bExportVarTable = TRUE, int bExportUUID = TRUE, int nObjectFilter = 0)
{
    string sFunc = "ExportGIT";

    NWNX_PushArgumentInt(NWNX_Area, sFunc, nObjectFilter);
    NWNX_PushArgumentInt(NWNX_Area, sFunc, bExportUUID);
    NWNX_PushArgumentInt(NWNX_Area, sFunc, bExportVarTable);
    NWNX_PushArgumentString(NWNX_Area, sFunc, sFileName);
    NWNX_PushArgumentObject(NWNX_Area, sFunc, oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Area, sFunc);
}
