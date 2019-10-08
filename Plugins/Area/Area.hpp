#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/CNWSArea.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Area {

class Area : public NWNXLib::Plugin
{
public:
    Area(const Plugin::CreateParams& params);
    virtual ~Area();

private:
    ArgumentStack GetNumberOfPlayersInArea  (ArgumentStack&& args);
    ArgumentStack GetLastEntered            (ArgumentStack&& args);
    ArgumentStack GetLastLeft               (ArgumentStack&& args);
    ArgumentStack GetPVPSetting             (ArgumentStack&& args);
    ArgumentStack SetPVPSetting             (ArgumentStack&& args);
    ArgumentStack GetAreaSpotModifier       (ArgumentStack&& args);
    ArgumentStack SetAreaSpotModifier       (ArgumentStack&& args);
    ArgumentStack GetAreaListenModifier     (ArgumentStack&& args);
    ArgumentStack SetAreaListenModifier     (ArgumentStack&& args);
    ArgumentStack GetNoRestingAllowed       (ArgumentStack&& args);
    ArgumentStack SetNoRestingAllowed       (ArgumentStack&& args);
    ArgumentStack GetWindPower              (ArgumentStack&& args);
    ArgumentStack SetWindPower              (ArgumentStack&& args);
    ArgumentStack GetWeatherChance          (ArgumentStack&& args);
    ArgumentStack SetWeatherChance          (ArgumentStack&& args);
    ArgumentStack GetFogClipDistance        (ArgumentStack&& args);
    ArgumentStack SetFogClipDistance        (ArgumentStack&& args);
    ArgumentStack GetShadowOpacity          (ArgumentStack&& args);
    ArgumentStack SetShadowOpacity          (ArgumentStack&& args);
    ArgumentStack GetDayNightCycle          (ArgumentStack&& args);
    ArgumentStack SetDayNightCycle          (ArgumentStack&& args);
    ArgumentStack GetSunMoonColors          (ArgumentStack&& args);
    ArgumentStack SetSunMoonColors          (ArgumentStack&& args);
    ArgumentStack CreateTransition          (ArgumentStack&& args);
    ArgumentStack GetTileAnimationLoop      (ArgumentStack&& args);
    ArgumentStack SetTileAnimationLoop      (ArgumentStack&& args);
    ArgumentStack TestDirectLine            (ArgumentStack&& args);

    NWNXLib::API::CNWSArea *area(ArgumentStack& args);
    static NWNXLib::API::CNWSTile *GetTile(NWNXLib::API::CNWSArea *pArea, float x, float y);
};

}
