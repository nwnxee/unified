#include "ItemAppearance.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoString.hpp"
#include "API/CExoStringList.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include <list>
#include <random>
#include <algorithm>
#include <iostream>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ItemAppearance::ItemAppearance* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new ItemAppearance::ItemAppearance(services);
    return g_plugin;
}


namespace ItemAppearance {

ItemAppearance::ItemAppearance(Services::ProxyServiceList* services)
        : Plugin(services)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&ItemAppearance::func, this, std::placeholders::_1))

    REGISTER(CacheAppearances);
    REGISTER(BlacklistAppearance);
    REGISTER(SyncAppearance);
    REGISTER(GetRandomAppearance);
    REGISTER(GetNextAppearance);
    REGISTER(GetPreviousAppearance);
    REGISTER(GetNextColor);
    REGISTER(GetPreviousColor);

#undef REGISTER
}

ItemAppearance::~ItemAppearance()
{
}

CNWSItem *ItemAppearance::item(ArgumentStack& args)
{
    const auto objectId = Services::Events::ExtractArgument<ObjectID>(args);

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Item function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    auto *pItem = pGameObject->AsNWSItem();
    if (!pItem)
        LOG_NOTICE("NWNX_Item function called on non item object");

    return pItem;
}

static bool startsWithCaseInsensitive(const char *a, const char *b)
{
    for (size_t i = 0; b[i]; i++)
    {
        if (a[i] != b[i] && abs(a[i] - b[i]) != 32)
        {
            return false;
        }
    }
    return true;
}

static int32_t check_range(const char* app_ranges, int32_t app)
{
    const char *range;
    int32_t lower, upper;

    if (!app_ranges)
    {
        return 1;
    }

    for (range = app_ranges; *range != '\0';)
    {
        if (*range == '-')
        {
            lower = 1;
            range++;
            upper = (int32_t) strtol(range, (char **) &range, 10);
        }
        else
        {
            lower = (int32_t) strtol(range, (char **) &range, 10);

            if (*range == '-')
            {
                range++;
                if (!isdigit(*range & 255))
                {
                    upper = 25;
                }
                else
                {
                    upper = (int32_t) strtol(range, (char **) &range, 10);
                }
            }
            else
            {
                upper = lower;
            }
        }

        if (app >= lower && app <= upper)
        {
            return 1;
        }

        if (*range == ',')
        {
            range++;
        }
        else
        {
            break;
        }
    }
    return 0;
}

ArgumentStack ItemAppearance::CacheAppearances(ArgumentStack&&)
{
    ArgumentStack stack;
    auto numBaseItems = Globals::Rules()->m_pBaseItemArray->m_nNumBaseItems;
    std::vector<std::string> processedItemClass;

    // Build our lists of resources we're interested in
    CExoStringList *pltList = Globals::ExoResMan()->GetResOfType(6, 0);
    CExoStringList *tgaList = Globals::ExoResMan()->GetResOfType(3, 0);
    std::vector<std::string> pltStrings;
    std::vector<std::string> tgaStrings;
    for (int i = 0; i < pltList->m_nCount; i++)
    {
        if (pltList->m_pStrings[i]->CStr()[0] == 'i')
        {
            pltStrings.emplace_back(pltList->m_pStrings[i]->CStr());
        }
    }
    std::sort(pltStrings.begin(), pltStrings.end());
    for (int i = 0; i < tgaList->m_nCount; i++)
    {
        if (tgaList->m_pStrings[i]->CStr()[0] == 'i')
        {
            tgaStrings.emplace_back(tgaList->m_pStrings[i]->CStr());
        }
    }
    std::sort(tgaStrings.begin(), tgaStrings.end());
    std::vector<std::string> resList;

    for (int baseItem = 0; baseItem < numBaseItems; baseItem++)
    {
        // Baseitem is null
        if (!Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_nName)
        {
            continue;
        }
        auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_ItemClassResRefChunk;

        // We've already processed this item class
        if (std::count(processedItemClass.begin(), processedItemClass.end(), resRef))
        {
            continue;
        }
        processedItemClass.emplace_back(resRef);

        switch (Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_nModelType)
        {
            case Constants::ItemAppearanceType::SimpleModel:
            case Constants::ItemAppearanceType::WeaponColor:
            {
                if (baseItem == Constants::BaseItem::Cloak || baseItem == Constants::BaseItem::CEP_Cloak)
                {
                    resList = pltStrings;
                }
                else
                {
                    resList = tgaStrings;
                }

                std::string simpleModel = resRef;
                simpleModel.insert(0, 1, 'i');
                bool iFoundOne = false;
                bool iFoundLast = false;
                for (auto const &name : resList)
                {
                    if (iFoundLast)
                    {
                        break;
                    }
                    if (startsWithCaseInsensitive(name.c_str(), simpleModel.c_str()))
                    {
                        iFoundOne = true;
                        auto appNumber = std::strtol(name.substr(name.find_last_of('_') + 1).c_str(), nullptr, 10);
                        g_plugin->m_BaseItemSimpleAppearances[resRef].push_back(appNumber);
                    }
                    else if (iFoundOne)
                    {
                        iFoundLast = true;
                    }
                }
                break;
            }
            case Constants::ItemAppearanceType::WeaponModel:
            {
                resList = tgaStrings;
                auto isWpn = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_bPartEnvMap[1];
                for (int k = 0; k < 3; k++)
                {
                    std::string complexModel = resRef;
                    complexModel.insert(0, 1, 'i');
                    if (k == 0)
                    {
                        complexModel.append("_b_");
                    }
                    else if (k == 1)
                    {
                        complexModel.append("_m_");
                    }
                    else if (k == 2)
                    {
                        complexModel.append("_t_");
                    }

                    bool iFoundOne = false;
                    bool iFoundLast = false;
                    for (auto const &name : resList)
                    {
                        if (iFoundLast)
                        {
                            break;
                        }
                        if (startsWithCaseInsensitive(name.c_str(), complexModel.c_str()))
                        {
                            iFoundOne = true;
                            if (isWpn && !Globals::ExoResMan()->Exists(CResRef(name.substr(1).c_str()), 2002, nullptr))
                            {
                                LOG_WARNING("You have an icon for %s but no model.", name.c_str());
                            }
                            else
                            {
                                auto appNum = std::strtol(name.substr(name.find_last_of('_') + 1).c_str(), nullptr, 10);
                                g_plugin->m_BaseItemConfigurableAppearances[resRef][k].push_back(appNum);
                            }
                        }
                        else if (iFoundOne)
                        {
                            iFoundLast = true;
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    return stack;
}

ArgumentStack ItemAppearance::SyncAppearance(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto baseItem = Services::Events::ExtractArgument<int32_t>(args);
    auto models = Services::Events::ExtractArgument<std::string>(args);
    auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_ItemClassResRefChunk;

    std::vector<int8_t> range;
    if (models == "*")
    {
        range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 25; i++)
        {
            if (check_range(models.c_str(), i))
            {
                range.emplace_back(i);
            }
        }
    }

    std::tuple<int8_t, int8_t, int8_t> colors = {-1, -1, -1};
    for (int i = 1; i <= 25; i++)
    {
        for (int j = 1; j <= 25; j++)
        {
            for (int k = 1; k <= 25; k++)
            {
                for (auto sync : range)
                {
                    if (((i != sync || j != sync) && k == sync) ||
                        ((i != sync || k != sync) && j == sync) ||
                        ((j != sync || k != sync) && i == sync))
                    {
                        std::tuple<int8_t, int8_t, int8_t> parts = {i, j, k};
                        m_BaseItemBlackListAppearances[resRef].push_back(std::make_pair(parts, colors));
                    }
                }
            }
        }
    }
    return stack;
}

ArgumentStack ItemAppearance::BlacklistAppearance(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto baseItem = Services::Events::ExtractArgument<int32_t>(args);
    auto bot = Services::Events::ExtractArgument<std::string>(args);
    auto mid = Services::Events::ExtractArgument<std::string>(args);
    auto top = Services::Events::ExtractArgument<std::string>(args);
    auto botc = Services::Events::ExtractArgument<std::string>(args);
    auto midc = Services::Events::ExtractArgument<std::string>(args);
    auto topc = Services::Events::ExtractArgument<std::string>(args);

    uint16_t modelType = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_nModelType;
    uint8_t rangeCheck = 25;
    if (modelType == Constants::ItemAppearanceType::SimpleModel || modelType == Constants::ItemAppearanceType::WeaponColor)
        rangeCheck = 255;

    std::vector<int8_t> bot_range;
    if (bot == "*")
    {
        bot_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= rangeCheck; i++)
        {
            if (check_range(bot.c_str(), i))
            {
                bot_range.emplace_back(i);
            }
        }
    }

    std::vector<int8_t> botc_range;
    if (botc == "*")
    {
        botc_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check_range(botc.c_str(), i))
            {
                botc_range.emplace_back(i);
            }
        }
    }

    std::vector<int8_t> mid_range;
    if (mid == "*")
    {
        mid_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 25; i++)
        {
            if (check_range(mid.c_str(), i))
            {
                mid_range.emplace_back(i);
            }
        }
    }

    std::vector<int8_t> midc_range;
    if (midc == "*")
    {
        midc_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check_range(midc.c_str(), i))
            {
                midc_range.emplace_back(i);
            }
        }
    }

    std::vector<int8_t> top_range;
    if (top == "*")
    {
        top_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 25; i++)
        {
            if (check_range(top.c_str(), i))
            {
                top_range.emplace_back(i);
            }
        }
    }

    std::vector<int8_t> topc_range;
    if (topc == "*")
    {
        topc_range.emplace_back(-1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check_range(topc.c_str(), i))
            {
                topc_range.emplace_back(i);
            }
        }
    }

    auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_ItemClassResRefChunk;

    for (auto bot_bl : bot_range)
    {
        for (auto mid_bl : mid_range)
        {
            for (auto top_bl : top_range)
            {
                for (auto botc_bl : botc_range)
                {
                    for (auto midc_bl : midc_range)
                    {
                        for (auto topc_bl : topc_range)
                        {
                            std::tuple<int8_t, int8_t, int8_t> parts = {bot_bl, mid_bl, top_bl};
                            std::tuple<int8_t, int8_t, int8_t> colors = {botc_bl, midc_bl, topc_bl};
                            m_BaseItemBlackListAppearances[resRef].push_back(std::make_pair(parts, colors));
                        }
                    }
                }
            }
        }
    }
    return stack;
}

int32_t ItemAppearance::IsBlacklisted(CNWSItem *pItem, int32_t nPart, int32_t newApp)
{
    auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem)->m_ItemClassResRefChunk;
    switch (Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem)->m_nModelType)
    {
        case Constants::ItemAppearanceType::SimpleModel:
        case Constants::ItemAppearanceType::WeaponColor:
        {
            for (auto &i : g_plugin->m_BaseItemBlackListAppearances[resRef])
            {
                auto parts = i.first;
                auto part = std::get<0>(parts);
                if (part == nPart)
                {
                    return true;
                }
            }
            break;
        }
        case Constants::ItemAppearanceType::WeaponModel:
        {
            auto currentBotApp = nPart == 0 ? newApp / 10 : pItem->m_nModelPart[0] / 10;
            auto currentMidApp = nPart == 1 ? newApp / 10 : pItem->m_nModelPart[1] / 10;
            auto currentTopApp = nPart == 2 ? newApp / 10 : pItem->m_nModelPart[2] / 10;
            auto currentBotColor = nPart == 0 ? newApp % 10 : pItem->m_nModelPart[0] % 10;
            auto currentMidColor = nPart == 1 ? newApp % 10 : pItem->m_nModelPart[1] % 10;
            auto currentTopColor = nPart == 2 ? newApp % 10 : pItem->m_nModelPart[2] % 10;

            for (auto &i : g_plugin->m_BaseItemBlackListAppearances[resRef])
            {
                auto parts = i.first;
                auto color = i.second;
                auto botPart = std::get<0>(parts);
                auto midPart = std::get<1>(parts);
                auto topPart = std::get<2>(parts);
                auto botColor = std::get<0>(color);
                auto midColor = std::get<1>(color);
                auto topColor = std::get<2>(color);
                if ((botPart == currentBotApp || botPart == -1) &&
                    (midPart == currentMidApp || midPart == -1) &&
                    (topPart == currentTopApp || topPart == -1) &&
                    (botColor == currentBotColor || botColor == -1) &&
                    (midColor == currentMidColor || midColor == -1) &&
                    (topColor == currentTopColor || topColor == -1))
                {
                    return true;
                }
            }
            break;
        }
        default:
            break;

    }
    return false;
}

ArgumentStack ItemAppearance::GetRandomAppearance(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pItem = item(args))
    {
        auto baseItem = pItem->m_nBaseItem;
        auto index = Services::Events::ExtractArgument<int32_t>(args);
        auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_ItemClassResRefChunk;
        std::random_device random_device;
        std::mt19937 engine{random_device()};
        int32_t appsSize;
        int32_t randomElement = -1;

        switch (Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItem)->m_nModelType)
        {
            case Constants::ItemAppearanceType::SimpleModel:
            case Constants::ItemAppearanceType::WeaponColor:
            {
                appsSize = g_plugin->m_BaseItemSimpleAppearances[resRef].size();
                if (appsSize > 0)
                {
                    std::uniform_int_distribution<int32_t> dist(0, appsSize - 1);
                    bool first = true;
                    while (first || IsBlacklisted(pItem, index, randomElement))
                    {
                        randomElement = g_plugin->m_BaseItemSimpleAppearances[resRef][dist(engine)];
                        first = false;
                    }
                }
                break;
            }
            case Constants::ItemAppearanceType::WeaponModel:
            {
                appsSize = g_plugin->m_BaseItemConfigurableAppearances[resRef][index].size();
                if (appsSize > 0)
                {
                    std::uniform_int_distribution<int32_t> dist(0, appsSize - 1);
                    bool first = true;
                    while (first || IsBlacklisted(pItem, index, randomElement))
                    {
                        randomElement = g_plugin->m_BaseItemConfigurableAppearances[resRef][index][dist(engine)];
                        first = false;
                    }
                }
                break;
            }
            default:
                break;
        }
        Services::Events::InsertArgument(stack, randomElement);
    }

    return stack;
}

ArgumentStack ItemAppearance::GetNextPreviousAppearanceColor(ArgumentStack& args, uint8_t appType)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pItem = item(args))
    {
        auto part = Services::Events::ExtractArgument<int32_t>(args);
        auto resRef = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem)->m_ItemClassResRefChunk;

        switch (Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItem->m_nBaseItem)->m_nModelType)
        {
            case Constants::ItemAppearanceType::SimpleModel:
            case Constants::ItemAppearanceType::WeaponColor:
            {
                auto v = g_plugin->m_BaseItemSimpleAppearances[resRef];
                switch (appType)
                {
                    case ModelChange::NextAppearance:
                    case ModelChange::NextColor:
                    {
                        auto currentKey = pItem->m_nModelPart[0];
                        auto itr = std::find(v.begin(), v.end(), currentKey);
                        uint32_t index;
                        if (itr != v.cend())
                        {
                            index = std::distance(v.begin(), itr) + 1;
                            while (IsBlacklisted(pItem, part, v[index]) && v[index] != v.back())
                                index++;
                            if (v[index] == v.back() && IsBlacklisted(pItem, part, v[index]))
                            {
                                index = 0;
                                while (IsBlacklisted(pItem, part, v[index]) && v[index] != v.back())
                                    index++;
                                if (index == v.size() - 1)
                                {
                                    retVal = -1;
                                }
                                else
                                {
                                    retVal = index;
                                }
                            }
                            else
                            {
                                retVal = v[index];
                            }
                        }
                        break;
                    }
                    case ModelChange::PreviousAppearance:
                    case ModelChange::PreviousColor:
                    {
                        auto currentKey = pItem->m_nModelPart[0];
                        auto itr = std::find(v.begin(), v.end(), currentKey);
                        uint32_t index;
                        if (itr != v.cend())
                        {
                            index = std::distance(v.begin(), itr) - 1;
                            if (index > 255)
                                index = v.size() - 1;
                            while (IsBlacklisted(pItem, part, v[index]) && v[index] != v.front())
                                index--;
                            if (v[index] == v.front() && IsBlacklisted(pItem, part, v[index]))
                            {
                                index = v.size() - 1;
                                while (IsBlacklisted(pItem, part, v[index]) && v[index] != v.front())
                                    index--;
                                if (index == 0)
                                {
                                    retVal = -1;
                                }
                                else
                                {
                                    retVal = index;
                                }
                            }
                            else
                            {
                                retVal = v[index];
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Constants::ItemAppearanceType::WeaponModel:
            {
                auto v = g_plugin->m_BaseItemConfigurableAppearances[resRef][part];
                auto currentKey = pItem->m_nModelPart[part];
                uint32_t index;
                auto itr = std::find(v.begin(), v.end(), currentKey);
                if (itr != v.cend())
                {
                    index = std::distance(v.begin(), itr);
                    switch (appType)
                    {
                        case ModelChange::NextAppearance:
                        {
                            while ((v[index] / 10 == currentKey / 10 || IsBlacklisted(pItem, part, v[index])) &&
                                   v[index] != v.back())
                                index++;
                            if (v[index] == v.back())
                            {
                                index = 0;
                                while ((v[index] / 10 == currentKey / 10 || IsBlacklisted(pItem, part, v[index])) &&
                                       v[index] != v.back())
                                    index++;
                                if (v[index] == v.back() && IsBlacklisted(pItem, part, v[index]))
                                {
                                    retVal = -1;
                                }
                                else
                                {
                                    retVal = v[index] / 10;
                                }
                            }
                            else
                            {
                                retVal = v[index] / 10;
                            }
                            break;
                        }
                        case ModelChange::PreviousAppearance:
                        {
                            while ((v[index] / 10 == currentKey / 10 || IsBlacklisted(pItem, part, v[index])) &&
                                   v[index] != v.front())
                                index--;
                            if (v[index] == v.front())
                            {
                                index = v.size() - 1;
                                while ((v[index] / 10 == currentKey / 10 || IsBlacklisted(pItem, part, v[index])) &&
                                       v[index] != v.front())
                                    index--;
                                if (v[index] == v.front() && IsBlacklisted(pItem, part, v[index]))
                                {
                                    retVal = -1;
                                }
                                else
                                {
                                    retVal = v[index] / 10;
                                }
                            }
                            else
                            {
                                retVal = v[index] / 10;
                            }
                            break;
                        }
                        case ModelChange::NextColor:
                        {
                            index++;
                            if (v[index] / 10 == currentKey / 10)
                            {
                                retVal = v[index] % 10;
                            }
                            else
                            {
                                retVal = 1;
                            }
                            break;
                        }
                        case ModelChange::PreviousColor:
                        {
                            index--;
                            if (v[index] / 10 == currentKey / 10)
                            {
                                retVal = v[index] % 10;
                            }
                            else
                            {
                                for (int i = 9; i >= 0; i--)
                                {
                                    if (std::find(v.begin(), v.end(), currentKey - (currentKey % 10) + i) != v.cend())
                                    {
                                        retVal = i;
                                        break;
                                    }

                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
                break;
            }
            default:
                break;
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack ItemAppearance::GetNextAppearance(ArgumentStack&& args)
{
    return GetNextPreviousAppearanceColor(args, ModelChange::NextAppearance);
}

ArgumentStack ItemAppearance::GetPreviousAppearance(ArgumentStack&& args)
{
    return GetNextPreviousAppearanceColor(args, ModelChange::PreviousAppearance);
}

ArgumentStack ItemAppearance::GetNextColor(ArgumentStack&& args)
{
    return GetNextPreviousAppearanceColor(args, ModelChange::NextColor);
}

ArgumentStack ItemAppearance::GetPreviousColor(ArgumentStack&& args)
{
    return GetNextPreviousAppearanceColor(args, ModelChange::PreviousColor);
}

}
