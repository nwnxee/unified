#include "nwnx_area"
#include "nwnx_tests"

void main()
{
    WriteTimestampedLogEntry("NWNX_Area unit test begin..");

    object oArea = GetAreaFromLocation(GetStartingLocation());

    if (GetIsObjectValid(oArea))
    {
        WriteTimestampedLogEntry("Using starting area: " + GetName(oArea));

        object oPC = GetFirstPC();

        if (GetIsObjectValid(oPC) && GetArea(oPC) == oArea)
        {
            NWNX_Tests_Report("NWNX_Area", "GetNumberOfPlayersInArea", NWNX_Area_GetNumberOfPlayersInArea(oArea) == 1);
        }
        else
        {
            WriteTimestampedLogEntry("No player in area, skipping 'GetNumberOfPlayersInArea' test");
        }

        NWNX_Area_SetPVPSetting(oArea, NWNX_AREA_PVP_SETTING_PARTY_PVP);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}PVPSetting", NWNX_Area_GetPVPSetting(oArea) == NWNX_AREA_PVP_SETTING_PARTY_PVP);

        NWNX_Area_SetAreaSpotModifier(oArea, 25);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}AreaSpotModifier", NWNX_Area_GetAreaSpotModifier(oArea) == 25);

        NWNX_Area_SetAreaListenModifier(oArea, 25);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}AreaListenModifier", NWNX_Area_GetAreaListenModifier(oArea) == 25);

        NWNX_Area_SetNoRestingAllowed(oArea, TRUE);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}NoRestingAllowed", NWNX_Area_GetNoRestingAllowed(oArea));

        NWNX_Area_SetWindPower(oArea, 2);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}WindPower", NWNX_Area_GetWindPower(oArea) == 2);

        NWNX_Area_SetWeatherChance(oArea, NWNX_AREA_WEATHER_CHANCE_LIGHTNING, 50);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}WeatherChance", NWNX_Area_GetWeatherChance(oArea, NWNX_AREA_WEATHER_CHANCE_LIGHTNING) == 50);

        NWNX_Area_SetFogClipDistance(oArea, 12.5f);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}FogClipDistance", NWNX_Area_GetFogClipDistance(oArea) == 12.5f);

        NWNX_Area_SetShadowOpacity(oArea, 75);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}ShadowOpacity", NWNX_Area_GetShadowOpacity(oArea) == 75);

        NWNX_Area_SetDayNightCycle(oArea, NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}DayNightCycle", NWNX_Area_GetDayNightCycle(oArea) == NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK);

        NWNX_Area_SetSunMoonColors(oArea, NWNX_AREA_COLOR_TYPE_MOON_DIFFUSE, FOG_COLOR_GREEN);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}SunMoonColors", NWNX_Area_GetSunMoonColors(oArea, NWNX_AREA_COLOR_TYPE_MOON_DIFFUSE) == FOG_COLOR_GREEN);

        vector vLoc = GetPositionFromLocation(GetStartingLocation());
        object oWP = CreateObject(OBJECT_TYPE_WAYPOINT, "nw_waypoint001", GetStartingLocation());
        object oAT = NWNX_Area_CreateTransition(oArea, oWP, vLoc.x, vLoc.y, vLoc.z);
        NWNX_Tests_Report("NWNX_Area", "CreateTransition", oAT != OBJECT_INVALID);

        string sResult = NWNX_Area_GetTileModelResRef(oArea, vLoc.x, vLoc.y);
        NWNX_Tests_Report("NWNX_Area", "GetTileModelResRef", sResult != "");

        NWNX_Area_SetTileAnimationLoop(oArea, vLoc.x, vLoc.y, 1, FALSE);
        NWNX_Tests_Report("NWNX_Area", "{Set/Get}TileAnimationLoop", NWNX_Area_GetTileAnimationLoop(oArea, vLoc.x, vLoc.y, 1) == FALSE);

        AmbientSoundChangeDay(oArea, 42);
        NWNX_Tests_Report("NWNX_Area", "GetAmbientSoundDay", NWNX_Area_GetAmbientSoundDay(oArea) == 42);

        AmbientSoundChangeNight(oArea, 43);
        NWNX_Tests_Report("NWNX_Area", "GetAmbientSoundNight", NWNX_Area_GetAmbientSoundNight(oArea) == 43);

        AmbientSoundSetDayVolume(oArea, 88);
        NWNX_Tests_Report("NWNX_Area", "GetAmbientSoundDayVolume", NWNX_Area_GetAmbientSoundDayVolume(oArea) == 88);

        AmbientSoundSetNightVolume(oArea, 77);
        NWNX_Tests_Report("NWNX_Area", "GetAmbientSoundNightVolume", NWNX_Area_GetAmbientSoundNightVolume(oArea) == 77);
    }
    else
    {
        WriteTimestampedLogEntry("No valid area found, aborting.");
    }


    WriteTimestampedLogEntry("NWNX_Area unit test end.");
}
