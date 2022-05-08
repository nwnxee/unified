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

/// @brief A tile info struct
struct NWNX_Area_TileInfo
{
    int nID; ///< The tile's ID
    int nHeight; ///< The tile's height
    int nOrientation; ///< The tile's orientation
    int nGridX; ///< The tile's grid x position
    int nGridY; ///< The tile's grid y position
};

/// @brief Area wind info struct
struct NWNX_Area_AreaWind
{
    vector vDirection; ///< Wind's direction
    float fMagnitude; ///< Wind's magnitude
    float fYaw; ///< Wind's yaw
    float fPitch; ///< Wind's pitch
};

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

/// @brief Export the .git file of oArea to the UserDirectory/nwnx folder, or to the location of sAlias.
/// @note Take care with local objects set on objects, they will likely not reference the same object after a server restart.
/// @param oArea The area to export the .git file of.
/// @param sFileName The filename, 16 characters or less and should be lowercase. If left blank the resref of oArea will be used.
/// @param bExportVarTable If TRUE, local variables set on oArea will be exported too.
/// @param bExportUUID If TRUE, the UUID of oArea will be exported, if it has one.
/// @param nObjectFilter One or more OBJECT_TYPE_* constants. These object will not be exported. For example OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
/// will not export creatures and doors. Use OBJECT_TYPE_ALL to filter all objects or 0 to export all objects.
/// @param sAlias The alias of the resource directory to add the .git file to. Default: UserDirectory/nwnx
/// @return TRUE if exported successfully, FALSE if not.
int NWNX_Area_ExportGIT(object oArea, string sFileName = "", int bExportVarTable = TRUE, int bExportUUID = TRUE, int nObjectFilter = 0, string sAlias = "NWNX");

/// @brief Get the tile info of the tile at [fTileX, fTileY] in oArea.
/// @param oArea The area name.
/// @param fTileX, fTileY The coordinates of the tile.
/// @return A NWNX_Area_TileInfo struct with tile info.
struct NWNX_Area_TileInfo NWNX_Area_GetTileInfo(object oArea, float fTileX, float fTileY);

/// @brief Export the .are file of oArea to the UserDirectory/nwnx folder, or to the location of sAlias.
/// @param oArea The area to export the .are file of.
/// @param sFileName The filename, 16 characters or less and should be lowercase. This will also be the resref of the area.
/// @param sNewName Optional new name of the area. Leave blank to use the current name.
/// @param sNewTag Optional new tag of the area. Leave blank to use the current tag.
/// @param sAlias The alias of the resource directory to add the .are file to. Default: UserDirectory/nwnx
/// @return TRUE if exported successfully, FALSE if not.
int NWNX_Area_ExportARE(object oArea, string sFileName, string sNewName = "", string sNewTag = "", string sAlias = "NWNX");

/// @brief Get the ambient sound playing in an area during the day.
/// @param oArea The area to get the sound of.
/// @return The ambient soundtrack. See ambientsound.2da.
int NWNX_Area_GetAmbientSoundDay(object oArea);

/// @brief Get the ambient sound playing in an area during the night.
/// @param oArea The area to get the sound of.
/// @return The ambient soundtrack. See ambientsound.2da.
int NWNX_Area_GetAmbientSoundNight(object oArea);

/// @brief Get the volume of the ambient sound playing in an area during the day.
/// @param oArea The area to get the sound volume of.
/// @return The volume.
int NWNX_Area_GetAmbientSoundDayVolume(object oArea);

/// @brief Get the volume of the ambient sound playing in an area during the night.
/// @param oArea The area to get the sound volume of.
/// @return The volume.
int NWNX_Area_GetAmbientSoundNightVolume(object oArea);

/// @brief Create a sound object.
/// @param oArea The area where to create the sound object.
/// @param vPosition The area position where to create the sound object.
/// @param sResRef The ResRef of the sound object.
/// @return The sound object.
object NWNX_Area_CreateSoundObject(object oArea, vector vPosition, string sResRef);

/// @brief Rotates an existing area, including all objects within (excluding PCs).
/// @note Functions while clients are in the area, but not recommended as tiles/walkmesh only updates on area load, and this may result in unexpected clientside results.
/// @param oArea The area to be rotated
/// @param nRotation How many 90 degrees clockwise to rotate (1-3).
void NWNX_Area_RotateArea(object oArea, int nRotation);

/// @brief Get the tile info of the tile at nIndex in the tile array.
/// @param oArea The area.
/// @param nIndex The index of the tile.
/// @return A NWNX_Area_TileInfo struct with tile info.
struct NWNX_Area_TileInfo NWNX_Area_GetTileInfoByTileIndex(object oArea, int nIndex);

/// @brief Check if there is a path between two positions in an area.
/// @note Does not care about doors or placeables, only checks tile path nodes.
/// @param oArea The area.
/// @param vStartPosition The start position.
/// @param vEndPosition The end position.
/// @param nMaxDepth The max depth of the DFS tree. A good value is AreaWidth * AreaHeight.
/// @return TRUE if there is a path between vStartPosition and vEndPosition, FALSE if not or on error.
int NWNX_Area_GetPathExists(object oArea, vector vStartPosition, vector vEndPosition, int nMaxDepth);

/// @brief Get oArea's flags, interior/underground etc.
/// @param oArea The area.
/// @return The raw flags bitmask or -1 on error.
int NWNX_Area_GetAreaFlags(object oArea);

/// @brief Set oArea's raw flags bitmask.
/// @note You'll have to do any bitwise operations yourself.
/// @note Requires clients to reload the area to get any updated flags.
/// @param oArea The area.
/// @param nFlags The flags.
void NWNX_Area_SetAreaFlags(object oArea, int nFlags);

/// @brief Get oArea's detailed win data.
/// @note vDirection returns [0.0, 0.0, 0.0] if not set previously with SetAreaWind nwscript function.
/// @param oArea The area.
struct NWNX_Area_AreaWind NWNX_Area_GetAreaWind(object oArea);

/// @}

int NWNX_Area_GetNumberOfPlayersInArea(object area)
{
    string sFunc = "GetNumberOfPlayersInArea";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

object NWNX_Area_GetLastEntered(object area)
{
    string sFunc = "GetLastEntered";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject();
}

object NWNX_Area_GetLastLeft(object area)
{
    string sFunc = "GetLastLeft";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject();
}

int NWNX_Area_GetPVPSetting(object area)
{
    string sFunc = "GetPVPSetting";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetPVPSetting(object area, int pvpSetting)
{
    string sFunc = "SetPVPSetting";

    NWNX_PushArgumentInt(pvpSetting);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetAreaSpotModifier(object area)
{
    string sFunc = "GetAreaSpotModifier";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetAreaSpotModifier(object area, int spotModifier)
{
    string sFunc = "SetAreaSpotModifier";

    NWNX_PushArgumentInt(spotModifier);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetAreaListenModifier(object area)
{
    string sFunc = "GetAreaListenModifier";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetAreaListenModifier(object area, int listenModifier)
{
    string sFunc = "SetAreaListenModifier";

    NWNX_PushArgumentInt(listenModifier);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetNoRestingAllowed(object area)
{
    string sFunc = "GetNoRestingAllowed";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetNoRestingAllowed(object area, int bNoRestingAllowed)
{
    string sFunc = "SetNoRestingAllowed";

    NWNX_PushArgumentInt(bNoRestingAllowed);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetWindPower(object area)
{
    string sFunc = "GetWindPower";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetWindPower(object area, int windPower)
{
    string sFunc = "SetWindPower";

    NWNX_PushArgumentInt(windPower);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetWeatherChance(object area, int type)
{
    string sFunc = "GetWeatherChance";

    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetWeatherChance(object area, int type, int chance)
{
    string sFunc = "SetWeatherChance";

    NWNX_PushArgumentInt(chance);
    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

float NWNX_Area_GetFogClipDistance(object area)
{
    string sFunc = "GetFogClipDistance";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueFloat();
}

void NWNX_Area_SetFogClipDistance(object area, float distance)
{
    string sFunc = "SetFogClipDistance";

    NWNX_PushArgumentFloat(distance);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetShadowOpacity(object area)
{
    string sFunc = "GetShadowOpacity";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetShadowOpacity(object area, int shadowOpacity)
{
    string sFunc = "SetShadowOpacity";

    NWNX_PushArgumentInt(shadowOpacity);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}


int NWNX_Area_GetDayNightCycle(object area)
{
    string sFunc = "GetDayNightCycle";

    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetDayNightCycle(object area, int type)
{
    string sFunc = "SetDayNightCycle";

    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_GetSunMoonColors(object area, int type)
{
    string sFunc = "GetSunMoonColors";

    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetSunMoonColors(object area, int type, int color)
{
    string sFunc = "SetSunMoonColors";

    NWNX_PushArgumentInt(color);
    NWNX_PushArgumentInt(type);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

object NWNX_Area_CreateTransition(object area, object target, float x, float y, float z, float size = 2.0f, string tag="")
{
    string sFunc = "CreateTransition";

    NWNX_PushArgumentString(tag);
    NWNX_PushArgumentFloat(size);
    NWNX_PushArgumentFloat(z);
    NWNX_PushArgumentFloat(y);
    NWNX_PushArgumentFloat(x);
    NWNX_PushArgumentObject(target);
    NWNX_PushArgumentObject(area);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject();
}

int NWNX_Area_GetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop)
{
    string sFunc = "GetTileAnimationLoop";

    NWNX_PushArgumentInt(nAnimLoop);
    NWNX_PushArgumentFloat(fTileY);
    NWNX_PushArgumentFloat(fTileX);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetTileAnimationLoop(object oArea, float fTileX, float fTileY, int nAnimLoop, int bEnabled)
{
    string sFunc = "SetTileAnimationLoop";

    NWNX_PushArgumentInt(bEnabled);
    NWNX_PushArgumentInt(nAnimLoop);
    NWNX_PushArgumentFloat(fTileY);
    NWNX_PushArgumentFloat(fTileX);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);
}

string NWNX_Area_GetTileModelResRef(object oArea, float fTileX, float fTileY)
{
    string sFunc = "GetTileModelResRef";
    NWNX_PushArgumentFloat(fTileY);
    NWNX_PushArgumentFloat(fTileX);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueString();
}

int NWNX_Area_TestDirectLine(object oArea, float fStartX, float fStartY, float fEndX, float fEndY, float fPerSpace, float fHeight, int bIgnoreDoors=FALSE)
{
    string sFunc = "TestDirectLine";

    NWNX_PushArgumentInt(bIgnoreDoors);
    NWNX_PushArgumentFloat(fHeight);
    NWNX_PushArgumentFloat(fPerSpace);
    NWNX_PushArgumentFloat(fEndY);
    NWNX_PushArgumentFloat(fEndX);
    NWNX_PushArgumentFloat(fStartY);
    NWNX_PushArgumentFloat(fStartX);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetMusicIsPlaying(object oArea, int bBattleMusic = FALSE)
{
    string sFunc = "GetMusicIsPlaying";

    NWNX_PushArgumentInt(bBattleMusic);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

object NWNX_Area_CreateGenericTrigger(object oArea, float fX, float fY, float fZ, string sTag = "", float fSize = 1.0f)
{
    string sFunc = "CreateGenericTrigger";

    NWNX_PushArgumentFloat(fSize);
    NWNX_PushArgumentString(sTag);
    NWNX_PushArgumentFloat(fZ);
    NWNX_PushArgumentFloat(fY);
    NWNX_PushArgumentFloat(fX);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject();
}

void NWNX_Area_AddObjectToExclusionList(object oObject)
{
    string sFunc = "AddObjectToExclusionList";

    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

void NWNX_Area_RemoveObjectFromExclusionList(object oObject)
{
    string sFunc = "RemoveObjectFromExclusionList";

    NWNX_PushArgumentObject(oObject);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

int NWNX_Area_ExportGIT(object oArea, string sFileName = "", int bExportVarTable = TRUE, int bExportUUID = TRUE, int nObjectFilter = 0, string sAlias = "NWNX")
{
    string sFunc = "ExportGIT";

    NWNX_PushArgumentString(sAlias);
    NWNX_PushArgumentInt(nObjectFilter);
    NWNX_PushArgumentInt(bExportUUID);
    NWNX_PushArgumentInt(bExportVarTable);
    NWNX_PushArgumentString(sFileName);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

struct NWNX_Area_TileInfo NWNX_Area_GetTileInfo(object oArea, float fTileX, float fTileY)
{
    string sFunc = "GetTileInfo";

    NWNX_PushArgumentFloat(fTileY);
    NWNX_PushArgumentFloat(fTileX);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    struct NWNX_Area_TileInfo str;

    str.nGridY = NWNX_GetReturnValueInt();
    str.nGridX = NWNX_GetReturnValueInt();
    str.nOrientation = NWNX_GetReturnValueInt();
    str.nHeight = NWNX_GetReturnValueInt();
    str.nID = NWNX_GetReturnValueInt();

    return str;
}

int NWNX_Area_ExportARE(object oArea, string sFileName, string sNewName = "", string sNewTag = "", string sAlias = "NWNX")
{
    string sFunc = "ExportARE";

    NWNX_PushArgumentString(sAlias);
    NWNX_PushArgumentString(sNewTag);
    NWNX_PushArgumentString(sNewName);
    NWNX_PushArgumentString(sFileName);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetAmbientSoundDay(object oArea)
{
    string sFunc = "GetAmbientSoundDay";

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetAmbientSoundNight(object oArea)
{
    string sFunc = "GetAmbientSoundNight";

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetAmbientSoundDayVolume(object oArea)
{
    string sFunc = "GetAmbientSoundDayVolume";

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetAmbientSoundNightVolume(object oArea)
{
    string sFunc = "GetAmbientSoundNightVolume";

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

object NWNX_Area_CreateSoundObject(object oArea, vector vPosition, string sResRef)
{
    string sFunc = "CreateSoundObject";

    NWNX_PushArgumentString(sResRef);
    NWNX_PushArgumentFloat(vPosition.z);
    NWNX_PushArgumentFloat(vPosition.y);
    NWNX_PushArgumentFloat(vPosition.x);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueObject();
}

void NWNX_Area_RotateArea(object oArea, int nRotation)
{
    string sFunc = "RotateArea";

    NWNX_PushArgumentInt(nRotation);
    NWNX_PushArgumentObject(oArea);

    NWNX_CallFunction(NWNX_Area, sFunc);
}

struct NWNX_Area_TileInfo NWNX_Area_GetTileInfoByTileIndex(object oArea, int nIndex)
{
    string sFunc = "GetTileInfoByTileIndex";

    NWNX_PushArgumentInt(nIndex);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    struct NWNX_Area_TileInfo str;

    str.nGridY = NWNX_GetReturnValueInt();
    str.nGridX = NWNX_GetReturnValueInt();
    str.nOrientation = NWNX_GetReturnValueInt();
    str.nHeight = NWNX_GetReturnValueInt();
    str.nID = NWNX_GetReturnValueInt();

    return str;
}

int NWNX_Area_GetPathExists(object oArea, vector vStartPosition, vector vEndPosition, int nMaxDepth)
{
    string sFunc = "GetPathExists";

    NWNX_PushArgumentInt(nMaxDepth);
    NWNX_PushArgumentFloat(vEndPosition.y);
    NWNX_PushArgumentFloat(vEndPosition.x);
    NWNX_PushArgumentFloat(vStartPosition.y);
    NWNX_PushArgumentFloat(vStartPosition.x);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

int NWNX_Area_GetAreaFlags(object oArea)
{
    string sFunc = "GetAreaFlags";

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    return NWNX_GetReturnValueInt();
}

void NWNX_Area_SetAreaFlags(object oArea, int nFlags)
{
    string sFunc = "SetAreaFlags";

    NWNX_PushArgumentInt(nFlags);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);
}

struct NWNX_Area_AreaWind NWNX_Area_GetAreaWind(object oArea)
{
    string sFunc = "GetAreaWind";
    struct NWNX_Area_AreaWind data;

    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Area, sFunc);

    data.fPitch = NWNX_GetReturnValueFloat();
    data.fYaw = NWNX_GetReturnValueFloat();
    data.fMagnitude = NWNX_GetReturnValueFloat();
    data.vDirection.x = NWNX_GetReturnValueFloat();
    data.vDirection.y = NWNX_GetReturnValueFloat();
    data.vDirection.z = NWNX_GetReturnValueFloat();

    return data;
}
