#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
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

    NWNXLib::API::CNWSArea *area(ArgumentStack& args);

};

}
