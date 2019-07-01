#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSItem.hpp"
#include <list>
#include <map>

using namespace std;
using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Item {

class Item : public NWNXLib::Plugin
{
public:
    Item(const Plugin::CreateParams& params);
    virtual ~Item();

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
    ArgumentStack SetWeight                 (ArgumentStack&& args);
    ArgumentStack SetBaseGoldPieceValue     (ArgumentStack&& args);
    ArgumentStack GetBaseGoldPieceValue     (ArgumentStack&& args);
    ArgumentStack SetAddGoldPieceValue      (ArgumentStack&& args);
    ArgumentStack GetAddGoldPieceValue      (ArgumentStack&& args);
    ArgumentStack SetBaseItemType           (ArgumentStack&& args);
    ArgumentStack SetItemAppearance         (ArgumentStack&& args);
    ArgumentStack GetEntireItemAppearance   (ArgumentStack&& args);
    ArgumentStack RestoreItemAppearance     (ArgumentStack&& args);
    ArgumentStack GetBaseArmorClass         (ArgumentStack&& args);
    ArgumentStack GetMinEquipLevel          (ArgumentStack&& args);
    ArgumentStack CacheAppearances          (ArgumentStack&& args);
    ArgumentStack BlacklistAppearance       (ArgumentStack&& args);
    ArgumentStack SyncAppearance            (ArgumentStack&& args);
    ArgumentStack GetRandomAppearance       (ArgumentStack&& args);
    ArgumentStack GetNextAppearance         (ArgumentStack&& args);
    ArgumentStack GetPreviousAppearance     (ArgumentStack&& args);
    ArgumentStack GetNextColor              (ArgumentStack&& args);
    ArgumentStack GetPreviousColor          (ArgumentStack&& args);

    NWNXLib::API::CNWSItem *item(ArgumentStack& args);
    static int IsBlacklisted(NWNXLib::API::CNWSItem *oItem, int32_t nPart, int32_t newApp);
    ArgumentStack GetNextPreviousAppearanceColor(ArgumentStack& args, uint8_t appType);
};

}
