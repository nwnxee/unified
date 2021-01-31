#pragma once

#include "nwnx.hpp"
#include "API/CNWSArea.hpp"

#include <set>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Area {

class Area : public NWNXLib::Plugin
{
public:
    Area(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Area();

private:
    ArgumentStack GetNumberOfPlayersInArea      (ArgumentStack&& args);
    ArgumentStack GetLastEntered                (ArgumentStack&& args);
    ArgumentStack GetLastLeft                   (ArgumentStack&& args);
    ArgumentStack GetPVPSetting                 (ArgumentStack&& args);
    ArgumentStack SetPVPSetting                 (ArgumentStack&& args);
    ArgumentStack GetAreaSpotModifier           (ArgumentStack&& args);
    ArgumentStack SetAreaSpotModifier           (ArgumentStack&& args);
    ArgumentStack GetAreaListenModifier         (ArgumentStack&& args);
    ArgumentStack SetAreaListenModifier         (ArgumentStack&& args);
    ArgumentStack GetNoRestingAllowed           (ArgumentStack&& args);
    ArgumentStack SetNoRestingAllowed           (ArgumentStack&& args);
    ArgumentStack GetWindPower                  (ArgumentStack&& args);
    ArgumentStack SetWindPower                  (ArgumentStack&& args);
    ArgumentStack GetWeatherChance              (ArgumentStack&& args);
    ArgumentStack SetWeatherChance              (ArgumentStack&& args);
    ArgumentStack GetFogClipDistance            (ArgumentStack&& args);
    ArgumentStack SetFogClipDistance            (ArgumentStack&& args);
    ArgumentStack GetShadowOpacity              (ArgumentStack&& args);
    ArgumentStack SetShadowOpacity              (ArgumentStack&& args);
    ArgumentStack GetDayNightCycle              (ArgumentStack&& args);
    ArgumentStack SetDayNightCycle              (ArgumentStack&& args);
    ArgumentStack GetSunMoonColors              (ArgumentStack&& args);
    ArgumentStack SetSunMoonColors              (ArgumentStack&& args);
    ArgumentStack CreateTransition              (ArgumentStack&& args);
    ArgumentStack GetTileAnimationLoop          (ArgumentStack&& args);
    ArgumentStack SetTileAnimationLoop          (ArgumentStack&& args);
    ArgumentStack GetTileModelResRef            (ArgumentStack&& args);
    ArgumentStack TestDirectLine                (ArgumentStack&& args);
    ArgumentStack GetMusicIsPlaying             (ArgumentStack&& args);
    ArgumentStack CreateGenericTrigger          (ArgumentStack&& args);
    ArgumentStack AddObjectToExclusionList      (ArgumentStack&& args);
    ArgumentStack RemoveObjectFromExclusionList (ArgumentStack&& args);
    ArgumentStack ExportGIT                     (ArgumentStack&& args);
    ArgumentStack GetTileInfo                   (ArgumentStack&& args);
    ArgumentStack ExportARE                     (ArgumentStack&& args);
    ArgumentStack GetAmbientSoundDay            (ArgumentStack&& args);
    ArgumentStack GetAmbientSoundNight          (ArgumentStack&& args);
    ArgumentStack GetAmbientSoundDayVolume      (ArgumentStack&& args);
    ArgumentStack GetAmbientSoundNightVolume    (ArgumentStack&& args);

    CNWSArea *area(ArgumentStack& args);

    std::set<ObjectID> m_ExportExclusionList;
};

}
