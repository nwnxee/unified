#include "nwnx"

const int NWNX_AREA_PVP_SETTING_NO_PVP          = 0;
const int NWNX_AREA_PVP_SETTING_PARTY_PVP       = 1;
const int NWNX_AREA_PVP_SETTING_FULL_PVP        = 2;
const int NWNX_AREA_PVP_SETTING_SERVER_DEFAULT  = 3;

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
