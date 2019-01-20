#include "nwnx_area"

void report(string func, int bSuccess)
{
    if (bSuccess)
        WriteTimestampedLogEntry("NWNX_Area: " + func + "() success");
    else
        WriteTimestampedLogEntry("NWNX_Area: " + func + "() failed");
}

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
            report("GetNumberOfPlayersInArea", NWNX_Area_GetNumberOfPlayersInArea(oArea) == 1);
        }
        else
        {
            WriteTimestampedLogEntry("No player in area, skipping 'GetNumberOfPlayersInArea' test");
        }

        NWNX_Area_SetPVPSetting(oArea, NWNX_AREA_PVP_SETTING_PARTY_PVP);
        report("{Set/Get}PVPSetting", NWNX_Area_GetPVPSetting(oArea) == NWNX_AREA_PVP_SETTING_PARTY_PVP);

        NWNX_Area_SetAreaSpotModifier(oArea, 25);
        report("{Set/Get}AreaSpotModifier", NWNX_Area_GetAreaSpotModifier(oArea) == 25);

        NWNX_Area_SetAreaListenModifier(oArea, 25);
        report("{Set/Get}AreaListenModifier", NWNX_Area_GetAreaListenModifier(oArea) == 25);

        NWNX_Area_SetNoRestingAllowed(oArea, TRUE);
        report("{Set/Get}NoRestingAllowed", NWNX_Area_GetNoRestingAllowed(oArea));

        NWNX_Area_SetWindPower(oArea, 2);
        report("{Set/Get}WindPower", NWNX_Area_GetWindPower(oArea) == 2);

        NWNX_Area_SetWeatherChance(oArea, NWNX_AREA_WEATHER_CHANCE_LIGHTNING, 50);
        report("{Set/Get}WeatherChance", NWNX_Area_GetWeatherChance(oArea, NWNX_AREA_WEATHER_CHANCE_LIGHTNING) == 50);

        NWNX_Area_SetFogClipDistance(oArea, 12.5f);
        report("{Set/Get}FogClipDistance", NWNX_Area_GetFogClipDistance(oArea) == 12.5f);

        NWNX_Area_SetShadowOpacity(oArea, 75);
        report("{Set/Get}ShadowOpacity", NWNX_Area_GetShadowOpacity(oArea) == 75);

        NWNX_Area_SetDayNightCycle(oArea, NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK);
        report("{Set/Get}DayNightCycle", NWNX_Area_GetDayNightCycle(oArea) == NWNX_AREA_DAYNIGHTCYCLE_ALWAYS_DARK);
    }
    else
    {
        WriteTimestampedLogEntry("No valid area found, aborting.");
    }


    WriteTimestampedLogEntry("NWNX_Area unit test end.");
}
