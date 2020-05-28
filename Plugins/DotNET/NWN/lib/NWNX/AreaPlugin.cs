namespace NWNX
{
    [NWNXPlugin(NWNX_Area)]
    public class AreaPlugin
    {
        public const string NWNX_Area = "NWNX_Area";

        // /< @private
        // / @name Area PVP Settings
        // / @anchor area_pvp
        // / @{
        public const int NWNX_AREA_PVP_SETTING_NO_PVP = 0;
        public const int NWNX_AREA_PVP_SETTING_PARTY_PVP = 1;
        public const int NWNX_AREA_PVP_SETTING_FULL_PVP = 2;
        public const int NWNX_AREA_PVP_SETTING_SERVER_DEFAULT = 3;

        // / @}
        // / @name Area Weather Settings
        // / @anchor area_weather
        // / @{
        public const int NWNX_AREA_WEATHER_CHANCE_RAIN = 0;
        public const int NWNX_AREA_WEATHER_CHANCE_SNOW = 1;
        public const int NWNX_AREA_WEATHER_CHANCE_LIGHTNING = 2;

        // / @}
        // / @name Area Day Night Cycle Settings
        // / @anchor area_daynight
        // / @{
        public const int NWNX_AREA_DAYNIGHTCYCLE_CYCLE_DAY_NIGHT = 0;
        public const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_BRIGHT = 1;
        public const int NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK = 2;

        // / @}
        // / @name Area Sun/Moon Color Settings
        // / @anchor area_color
        // / @{
        public const int NWNX_AREA_COLOR_TYPE_MOON_AMBIENT = 0;
        public const int NWNX_AREA_COLOR_TYPE_MOON_DIFFUSE = 1;
        public const int NWNX_AREA_COLOR_TYPE_SUN_AMBIENT = 2;
        public const int NWNX_AREA_COLOR_TYPE_SUN_DIFFUSE = 3;

        // / @}
        // / @brief Gets the number of players in area.
        // / @param area The area object.
        // / @return The player count for the area.
        public static int GetNumberOfPlayersInArea(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetNumberOfPlayersInArea");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Gets the creature that last entered area.
        // / @param area The area object.
        // / @return The most recent creature to enter the area.
        public static uint GetLastEntered(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetLastEntered");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Gets the creature that last left area
        // / @param area The area object.
        public static uint GetLastLeft(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetLastLeft");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Get the PVP setting of area
        // / @param area The area object.
        // / @return Returns the @ref area_pvp "PVP Setting" for the area.
        public static int GetPVPSetting(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetPVPSetting");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the PVP setting of area
        // / @param area The area object.
        // / @param pvpSetting One of @ref area_pvp the "PVP Settings".
        public static void SetPVPSetting(uint area, int pvpSetting)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetPVPSetting");
            NWN.Internal.NativeFunctions.nwnxPushInt(pvpSetting);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the spot modifier of area
        // / @param area The area object.
        // / @return The value of the Spot skill modifier for this area.
        public static int GetAreaSpotModifier(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetAreaSpotModifier");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the spot modifier of area
        // / @param area The area object.
        // / @param spotModifier The modifier to the Spot skill for this area.
        // / @sa NWNX_SkillRanks_SetAreaModifier() to change any skill modifier.
        public static void SetAreaSpotModifier(uint area, int spotModifier)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetAreaSpotModifier");
            NWN.Internal.NativeFunctions.nwnxPushInt(spotModifier);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the listen modifer of area
        // / @param area The area object.
        // / @return The value of the Listen skill modifier for this area.
        public static int GetAreaListenModifier(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetAreaListenModifier");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the listen modifier of area
        // / @param area The area object.
        // / @param listenModifier The modifier to the Listen skill for this area.
        // / @sa NWNX_SkillRanks_SetAreaModifier() to change any skill modifier.
        public static void SetAreaListenModifier(uint area, int listenModifier)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetAreaListenModifier");
            NWN.Internal.NativeFunctions.nwnxPushInt(listenModifier);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Checks the No Resting area flag
        // / @param area The area object.
        // / @return TRUE if resting is not allowed in area.
        public static int GetNoRestingAllowed(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetNoRestingAllowed");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set whether to disable resting in the area.
        // / @param area The area object.
        // / @param bNoRestingAllowed TRUE to disable resting in the area.
        public static void SetNoRestingAllowed(uint area, int bNoRestingAllowed)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetNoRestingAllowed");
            NWN.Internal.NativeFunctions.nwnxPushInt(bNoRestingAllowed);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the wind power in area
        // / @param area The area object.
        // / @return The wind power for the area. (0-2)
        public static int GetWindPower(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetWindPower");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the wind power in area
        // / @param area The area object.
        // / @param windPower Set to 0, 1 or 2.
        public static void SetWindPower(uint area, int windPower)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetWindPower");
            NWN.Internal.NativeFunctions.nwnxPushInt(windPower);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the weather chance of type in area
        // / @param type A @ref area_weather "Weather Setting".
        // / @param area The area object.
        // / @return The percentage chance for the weather type. (0-100)
        public static int GetWeatherChance(uint area, int type)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetWeatherChance");
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the weather chance of type in area
        // / @param area The area object.
        // / @param type A @ref area_weather "Weather Setting".
        // / @param chance The chance this weather event occurs.
        public static void SetWeatherChance(uint area, int type, int chance)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetWeatherChance");
            NWN.Internal.NativeFunctions.nwnxPushInt(chance);
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the fog clip distance in area
        // / @param area The area object.
        // / @return The fog clip distance.
        public static float GetFogClipDistance(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetFogClipDistance");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopFloat();
        }

        // / @brief Set the fog clip distance in area
        // / @param area The area object.
        // / @param distance The new fog clip distance.
        public static void SetFogClipDistance(uint area, float distance)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetFogClipDistance");
            NWN.Internal.NativeFunctions.nwnxPushFloat(distance);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the shadow opacity of area
        // / @param area The area object.
        // / @return The shadow opacity for the area. (0-100)
        public static int GetShadowOpacity(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetShadowOpacity");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the shadow opacity of area
        // / @param area The area object.
        // / @param shadowOpacity The shadow opacity to set for the area (0-100).
        public static void SetShadowOpacity(uint area, int shadowOpacity)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetShadowOpacity");
            NWN.Internal.NativeFunctions.nwnxPushInt(shadowOpacity);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the day/night cycle of area
        // / @param area The area object.
        // / @return The @ref area_daynight "Day Night Cycle Setting".
        public static int GetDayNightCycle(uint area)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetDayNightCycle");
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the day/night cycle of area
        // / @param area The area object.
        // / @param type = A @ref area_daynight "Day Night Cycle Setting".
        public static void SetDayNightCycle(uint area, int type)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetDayNightCycle");
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the Sun/Moon Ambient/Diffuse colors of area
        // / @param area The area object.
        // / @param type = A @ref area_color "Sun/Moon Color Setting".
        // / @return A FOG_COLOR_* or a custom value, -1 on error.
        public static int GetSunMoonColors(uint area, int type)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetSunMoonColors");
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the Sun/Moon Ambient/Diffuse colors of area
        //  type = NWNX_AREA_COLOR_TYPE_*
        // / @param area The area object.
        // / @param type = A @ref area_color "Sun/Moon Color Setting".
        // / @param color = A FOG_COLOR_*.
        // / @note The color can also be represented as a hex RGB number if specific color shades are desired.
        // / The format of a hex specified color would be 0xFFEEDD where
        // /  * FF would represent the amount of red in the color
        // /  * EE would represent the amount of green in the color
        // /  * DD would represent the amount of blue in the color.
        public static void SetSunMoonColors(uint area, int type, int color)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetSunMoonColors");
            NWN.Internal.NativeFunctions.nwnxPushInt(color);
            NWN.Internal.NativeFunctions.nwnxPushInt(type);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Create and returns a transition (square shaped of specified size) at a location.
        // / @param area The area object.
        // / @param target A door or waypoint object.
        // / @param x,y,z The position to create the transition.
        // / @param size The size of the square.
        // / @param tag If specified, the returning object will have this tag.
        // / @sa NWNX_Object_SetTriggerGeometry() if you wish to draw the transition as something other than a square.
        public static uint CreateTransition(uint area, uint target, float x, float y, float z, float size = 2.0f, string tag = "")
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "CreateTransition");
            NWN.Internal.NativeFunctions.nwnxPushString(tag);
            NWN.Internal.NativeFunctions.nwnxPushFloat(size);
            NWN.Internal.NativeFunctions.nwnxPushFloat(z);
            NWN.Internal.NativeFunctions.nwnxPushFloat(y);
            NWN.Internal.NativeFunctions.nwnxPushFloat(x);
            NWN.Internal.NativeFunctions.nwnxPushObject(target);
            NWN.Internal.NativeFunctions.nwnxPushObject(area);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @brief Get the state of a tile animation loop.
        // / @param oArea The area object.
        // / @param fTileX, fTileY The coordinates of the tile.
        // / @param nAnimLoop The loop to check. (1-3)
        // / @return TRUE if the loop is enabled.
        public static int GetTileAnimationLoop(uint oArea, float fTileX, float fTileY, int nAnimLoop)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetTileAnimationLoop");
            NWN.Internal.NativeFunctions.nwnxPushInt(nAnimLoop);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileX);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the state of a tile animation loop.
        // / @param oArea The area object.
        // / @param fTileX, fTileY The coordinates of the tile.
        // / @param nAnimLoop The loop to set (1-3).
        // / @param bEnabled TRUE or FALSE.
        // / @note Requires clients to re-enter the area for it to take effect
        public static void SetTileAnimationLoop(uint oArea, float fTileX, float fTileY, int nAnimLoop, int bEnabled)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "SetTileAnimationLoop");
            NWN.Internal.NativeFunctions.nwnxPushInt(bEnabled);
            NWN.Internal.NativeFunctions.nwnxPushInt(nAnimLoop);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileX);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the name of the tile model from any location.
        // / @param oArea The area name.
        // / @param fTileX, fTileY The coordinates of the tile.
        public static string GetTileModelResRef(uint oArea, float fTileX, float fTileY)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetTileModelResRef");
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fTileX);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopString();
        }

        // / @brief Test to see if there's a direct, walkable line between two points in the area.
        // / @param oArea The area object.
        // / @param fStartX, fStartY The starting points.
        // / @param fEndX, fEndY The ending points.
        // / @param fPerSpace The personal space of a creature. Found in appearance.2da.
        // / @param fHeight The height of a creature. Found in appearance.2da.
        // / @param bIgnoreDoors Whether to ignore doors in the check.
        // / @return
        // /  * 1 if there is a direct walkable line.
        // /  * -1 if the line is blocked by terrain.
        // /  * -2 if the line is blocked by a placeable.
        // /  * -3 if the line is blocked by a creature.
        public static int TestDirectLine(uint oArea, float fStartX, float fStartY, float fEndX, float fEndY, float fPerSpace, float fHeight, int bIgnoreDoors = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "TestDirectLine");
            NWN.Internal.NativeFunctions.nwnxPushInt(bIgnoreDoors);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fHeight);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fPerSpace);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fEndY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fEndX);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fStartY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fStartX);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Get if the area music is playing.
        // / @param oArea The area object.
        // / @param bBattleMusic Set to TRUE to get if the battle music is playing.
        // / @return TRUE if music is playing
        public static int GetMusicIsPlaying(uint oArea, int bBattleMusic = NWN.NWScript.FALSE)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "GetMusicIsPlaying");
            NWN.Internal.NativeFunctions.nwnxPushInt(bBattleMusic);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Create and return a generic trigger (square shaped of specified size) at a location.
        // / @param oArea The area object.
        // / @param fX, fY, fZ The position to create the trigger.
        // / @param sTag If specified, the returned trigger will have this tag.
        // / @param fSize The size of the square.
        // / @sa NWNX_Object_SetTriggerGeometry() if you wish to draw the trigger as something other than a square.
        public static uint CreateGenericTrigger(uint oArea, float fX, float fY, float fZ, string sTag = "", float fSize = 1.0f)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Area, "CreateGenericTrigger");
            NWN.Internal.NativeFunctions.nwnxPushFloat(fSize);
            NWN.Internal.NativeFunctions.nwnxPushString(sTag);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fZ);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fY);
            NWN.Internal.NativeFunctions.nwnxPushFloat(fX);
            NWN.Internal.NativeFunctions.nwnxPushObject(oArea);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopObject();
        }

        // / @}
    }
}
