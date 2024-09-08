#pragma once

#include "nwnx.hpp"
#include "API/CNWSItem.hpp"
#include <list>
#include <map>

using namespace std;
using ArgumentStack = NWNXLib::ArgumentStack;

namespace ItemAppearance {

class ItemAppearance : public NWNXLib::Plugin
{
public:
    ItemAppearance(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ItemAppearance();

private:
    enum ModelChange
    {
        NextAppearance     = 0,
        PreviousAppearance = 1,
        NextColor          = 2,
        PreviousColor      = 3,
    };

    unordered_map<std::string, vector<uint16_t>>                             m_BaseItemSimpleAppearances;
    unordered_map<std::string, unordered_map<uint8_t, vector<uint16_t>>>     m_BaseItemConfigurableAppearances;
    unordered_map<std::string, std::list<std::pair<std::tuple<int8_t, int8_t, int8_t>,
                               std::tuple<int8_t, int8_t, int8_t>>>> m_BaseItemBlackListAppearances;
    ArgumentStack CacheAppearances          (ArgumentStack&& args);
    ArgumentStack BlacklistAppearance       (ArgumentStack&& args);
    ArgumentStack SyncAppearance            (ArgumentStack&& args);
    ArgumentStack GetRandomAppearance       (ArgumentStack&& args);
    ArgumentStack GetNextAppearance         (ArgumentStack&& args);
    ArgumentStack GetPreviousAppearance     (ArgumentStack&& args);
    ArgumentStack GetNextColor              (ArgumentStack&& args);
    ArgumentStack GetPreviousColor          (ArgumentStack&& args);

    CNWSItem *item(ArgumentStack& args);
    static int IsBlacklisted(CNWSItem *oItem, int32_t nPart, int32_t newApp);
    ArgumentStack GetNextPreviousAppearanceColor(ArgumentStack& args, uint8_t appType);
};

}
