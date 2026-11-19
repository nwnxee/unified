#include "nwnx.hpp"

#include "API/CNWRules.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoString.hpp"
#include "API/CExoStringList.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <climits>
#include <cstdint>
#include <iterator>
#include <optional>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace {

// baseitems.2da ModelType
enum ModelType : uint8_t
{
    Simple    = 0,
    Layered   = 1,
    Composite = 2,
    Armor     = 3,
};

constexpr int32_t NUM_PARTS = 3;
constexpr int32_t RANDOM_WEAPON_TRIES = 1000;
constexpr int64_t MAX_WEAPON_SEARCH = 5000000; // appearances tried when the random tries fail

// Inclusive value ranges. Empty means any value.
using Ranges = std::vector<std::pair<int32_t, int32_t>>;

struct Rule
{
    std::array<Ranges, NUM_PARTS> models; // simple and layered items use models[0] only
    std::array<Ranges, NUM_PARTS> colors;
};

struct Rules
{
    std::vector<Rule> blacklist;
    std::vector<Ranges> sync;
};

struct Appearances
{
    // Sorted, unique. Simple and layered items: model numbers; composite: model * 10 + color per part.
    std::vector<int32_t> simple;
    std::array<std::vector<int32_t>, NUM_PARTS> parts;
};

// Both keyed by the lowercase baseitems.2da ItemClass, like the icon and model names.
std::unordered_map<std::string, Appearances> s_appearances;
std::unordered_map<std::string, Rules> s_rules;
std::mt19937 s_rng{std::random_device{}()};

std::string ToLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

// A non-negative number of up to six digits.
std::optional<int32_t> ParseNumber(const std::string& s)
{
    if (s.empty() || s.size() > 6 || !std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isdigit(c); }))
        return std::nullopt;
    return std::stoi(s);
}

CNWBaseItem* GetBaseItem(int32_t baseItem)
{
    auto *pBaseItemArray = Globals::Rules()->m_pBaseItemArray;
    if (baseItem < 0 || baseItem >= pBaseItemArray->m_nNumBaseItems)
        return nullptr;
    return pBaseItemArray->GetBaseItem(baseItem);
}

std::string GetItemClass(const CNWBaseItem *pBaseItem)
{
    return ToLower(pBaseItem->m_ItemClassResRefChunk);
}

template <typename F>
void ForEachResOfType(uint16_t type, F&& fn)
{
    if (auto *pList = Globals::ExoResMan()->GetResOfType(type, false))
    {
        for (int32_t i = 0; i < pList->m_nCount; i++)
            fn(ToLower(pList->m_pStrings[i]->CStr()));
        delete pList;
    }
}

// "*" is any value. Otherwise a comma separated list of "n", "n-m", "-m" (up to m) and "n-" (n and up).
std::optional<Ranges> ParseRanges(const std::string& str)
{
    Ranges ranges;
    if (str == "*")
        return ranges;

    size_t start = 0;
    while (start <= str.size())
    {
        auto end = str.find(',', start);
        if (end == std::string::npos)
            end = str.size();

        std::string token;
        for (auto c : str.substr(start, end - start))
        {
            if (!std::isspace(static_cast<unsigned char>(c)))
                token += c;
        }

        const auto dash = token.find('-');
        const auto lower = token.substr(0, dash);
        const auto upper = dash == std::string::npos ? lower : token.substr(dash + 1);
        if (lower.empty() && upper.empty())
            return std::nullopt;

        const auto low = lower.empty() ? std::optional<int32_t>(0) : ParseNumber(lower);
        const auto high = upper.empty() ? std::optional<int32_t>(INT_MAX) : ParseNumber(upper);
        if (!low || !high || *low > *high)
            return std::nullopt;
        ranges.emplace_back(*low, *high);

        start = end + 1;
    }
    return ranges;
}

bool InRanges(const Ranges& ranges, int32_t value)
{
    if (ranges.empty())
        return true;
    return std::any_of(ranges.begin(), ranges.end(), [value](const auto& r) { return value >= r.first && value <= r.second; });
}

const Rules* GetRules(const std::string& itemClass)
{
    auto it = s_rules.find(itemClass);
    return it == s_rules.end() ? nullptr : &it->second;
}

bool IsSimpleAllowed(const Rules *pRules, int32_t value)
{
    if (!pRules)
        return true;
    return std::none_of(pRules->blacklist.begin(), pRules->blacklist.end(),
                        [value](const Rule& rule) { return InRanges(rule.models[0], value); });
}

bool IsSynced(const Rules *pRules, int32_t model)
{
    return pRules && std::any_of(pRules->sync.begin(), pRules->sync.end(),
                                 [model](const Ranges& sync) { return InRanges(sync, model); });
}

// values: model * 10 + color for bottom, middle and top.
bool IsWeaponAllowed(const Rules *pRules, const std::array<int32_t, NUM_PARTS>& values)
{
    if (!pRules)
        return true;

    for (const auto& rule : pRules->blacklist)
    {
        bool match = true;
        for (int32_t k = 0; k < NUM_PARTS && match; k++)
            match = InRanges(rule.models[k], values[k] / 10) && InRanges(rule.colors[k], values[k] % 10);
        if (match)
            return false;
    }

    // A synced model must be used by all three parts.
    const bool allSame = values[0] / 10 == values[1] / 10 && values[1] / 10 == values[2] / 10;
    for (int32_t k = 0; k < NUM_PARTS; k++)
    {
        if (!allSame && IsSynced(pRules, values[k] / 10))
            return false;
    }
    return true;
}

struct ItemInfo
{
    CNWSItem *pItem;
    uint8_t modelType;
    const Appearances *pAppearances;
    const Rules *pRules;
};

// part is only used by composite items.
std::optional<ItemInfo> GetItemInfo(CNWSItem *pItem, int32_t part)
{
    if (!pItem)
        return std::nullopt;
    auto *pBaseItem = GetBaseItem(pItem->m_nBaseItem);
    if (!pBaseItem)
        return std::nullopt;

    const auto itemClass = GetItemClass(pBaseItem);
    auto it = s_appearances.find(itemClass);
    if (it == s_appearances.end())
        return std::nullopt;
    if (pBaseItem->m_nModelType == ModelType::Composite && (part < 0 || part >= NUM_PARTS))
    {
        LOG_WARNING("Invalid weapon part %d", part);
        return std::nullopt;
    }
    return ItemInfo{pItem, pBaseItem->m_nModelType, &it->second, GetRules(itemClass)};
}

// The values the item's part can take without breaking a rule, keeping its other parts. Sorted.
std::vector<int32_t> GetAllowed(const ItemInfo& info, int32_t part)
{
    std::vector<int32_t> allowed;
    switch (info.modelType)
    {
        case ModelType::Simple:
        case ModelType::Layered:
            for (auto value : info.pAppearances->simple)
            {
                if (IsSimpleAllowed(info.pRules, value))
                    allowed.push_back(value);
            }
            break;

        case ModelType::Composite:
            for (auto value : info.pAppearances->parts[part])
            {
                std::array<int32_t, NUM_PARTS> values = {info.pItem->m_nModelPart[0], info.pItem->m_nModelPart[1], info.pItem->m_nModelPart[2]};
                values[part] = value;
                if (IsWeaponAllowed(info.pRules, values))
                    allowed.push_back(value);
            }
            break;

        default:
            break;
    }
    return allowed;
}

int32_t GetCurrentValue(const ItemInfo& info, int32_t part)
{
    return info.modelType == ModelType::Composite ? info.pItem->m_nModelPart[part] : info.pItem->m_nModelPart[0];
}

// The next (or previous) value after current in sorted values, wrapping around. -1 if values is empty.
int32_t Step(const std::vector<int32_t>& values, int32_t current, bool next)
{
    if (values.empty())
        return -1;
    if (next)
    {
        auto it = std::upper_bound(values.begin(), values.end(), current);
        return it == values.end() ? values.front() : *it;
    }
    auto it = std::lower_bound(values.begin(), values.end(), current);
    return it == values.begin() ? values.back() : *std::prev(it);
}

int32_t Pick(const std::vector<int32_t>& values)
{
    if (values.empty())
        return -1;
    std::uniform_int_distribution<size_t> dist(0, values.size() - 1);
    return values[dist(s_rng)];
}

// A value from sorted values with the model picked first, so a model with many colors isn't favored.
int32_t PickByModel(const std::vector<int32_t>& values)
{
    if (values.empty())
        return -1;

    std::vector<int32_t> models;
    for (auto value : values)
    {
        if (models.empty() || models.back() != value / 10)
            models.push_back(value / 10);
    }
    const auto model = Pick(models);
    const auto first = std::lower_bound(values.begin(), values.end(), model * 10);
    const auto last = std::lower_bound(first, values.end(), model * 10 + 10);
    return Pick(std::vector<int32_t>(first, last));
}

// Middle or top values for a bottom model: only that model if synced, otherwise any unsynced one.
std::vector<int32_t> GetWeaponChoices(const Rules *pRules, const std::vector<int32_t>& values, int32_t bottomModel)
{
    const bool synced = IsSynced(pRules, bottomModel);
    std::vector<int32_t> choices;
    for (auto value : values)
    {
        if (synced ? value / 10 == bottomModel : !IsSynced(pRules, value / 10))
            choices.push_back(value);
    }
    return choices;
}

// The value of sorted values with the model, keeping the color if the model has it. -1 if there is none.
int32_t GetValueForModel(const std::vector<int32_t>& values, int32_t model, int32_t color)
{
    auto it = std::lower_bound(values.begin(), values.end(), model * 10 + color);
    if (it != values.end() && *it == model * 10 + color)
        return *it;
    it = std::lower_bound(values.begin(), values.end(), model * 10);
    return it != values.end() && *it / 10 == model ? *it : -1;
}

using Weapon = std::array<int32_t, NUM_PARTS>;

// Closest weapon with this bottom: keep other parts if allowed, else the bottom model, else the first unsynced.
std::optional<Weapon> BuildWeapon(const ItemInfo& info, int32_t bottomModel)
{
    const auto& parts = info.pAppearances->parts;
    std::array<std::vector<int32_t>, NUM_PARTS> options;
    for (int32_t k = 0; k < NUM_PARTS; k++)
    {
        const int32_t current = info.pItem->m_nModelPart[k];
        std::vector<int32_t> candidates;
        if (k == 0 || IsSynced(info.pRules, bottomModel))
            candidates = {GetValueForModel(parts[k], bottomModel, current % 10)};
        else
        {
            const auto unsynced = GetWeaponChoices(info.pRules, parts[k], bottomModel);
            candidates = {current, GetValueForModel(parts[k], bottomModel, current % 10),
                          unsynced.empty() ? -1 : unsynced.front()};
        }
        for (auto value : candidates)
        {
            if (value != -1 && std::find(options[k].begin(), options[k].end(), value) == options[k].end())
                options[k].push_back(value);
        }
    }

    for (auto bottom : options[0])
    {
        for (auto middle : options[1])
        {
            for (auto top : options[2])
            {
                const Weapon weapon = {bottom, middle, top};
                if (IsWeaponAllowed(info.pRules, weapon))
                    return weapon;
            }
        }
    }
    return std::nullopt;
}

// The next (or previous) bottom model, wrapping around, that has an allowed weapon. -1 for every part if none.
Weapon StepWeapon(const ItemInfo& info, bool next)
{
    std::vector<int32_t> models;
    for (auto value : info.pAppearances->parts[0])
    {
        if (models.empty() || models.back() != value / 10)
            models.push_back(value / 10);
    }
    if (models.empty())
        return {-1, -1, -1};

    // Every model gets a turn, the item's own last.
    const int64_t count = models.size();
    const int32_t current = info.pItem->m_nModelPart[0] / 10;
    const int64_t start = next ? std::upper_bound(models.begin(), models.end(), current) - models.begin()
                               : std::lower_bound(models.begin(), models.end(), current) - models.begin() - 1;
    for (int64_t i = 0; i < count; i++)
    {
        const int64_t pos = ((next ? start + i : start - i) % count + count) % count;
        if (auto weapon = BuildWeapon(info, models[pos]))
            return *weapon;
    }
    return {-1, -1, -1};
}

// Every allowed weapon in random order until one is found; for when the random tries come up empty.
std::optional<Weapon> SearchWeapon(const ItemInfo& info)
{
    const auto& parts = info.pAppearances->parts;
    auto bottoms = parts[0];
    std::shuffle(bottoms.begin(), bottoms.end(), s_rng);

    int64_t checked = 0;
    for (auto bottom : bottoms)
    {
        auto middles = GetWeaponChoices(info.pRules, parts[1], bottom / 10);
        auto tops = GetWeaponChoices(info.pRules, parts[2], bottom / 10);
        std::shuffle(middles.begin(), middles.end(), s_rng);
        std::shuffle(tops.begin(), tops.end(), s_rng);
        for (auto middle : middles)
        {
            for (auto top : tops)
            {
                if (++checked > MAX_WEAPON_SEARCH)
                    return std::nullopt;
                const Weapon weapon = {bottom, middle, top};
                if (IsWeaponAllowed(info.pRules, weapon))
                    return weapon;
            }
        }
    }
    return std::nullopt;
}

ArgumentStack StepWeaponAppearance(ArgumentStack& args, bool next)
{
    Weapon weapon = {-1, -1, -1};
    auto info = GetItemInfo(Utils::PopItem(args), 0);
    if (info && info->modelType == ModelType::Composite)
        weapon = StepWeapon(*info, next);
    return {weapon[0], weapon[1], weapon[2]};
}

int32_t NextPreviousAppearance(ArgumentStack& args, bool next)
{
    auto *pItem = Utils::PopItem(args);
    const auto part = args.extract<int32_t>();

    auto info = GetItemInfo(pItem, part);
    if (!info)
        return -1;

    const auto allowed = GetAllowed(*info, part);
    if (allowed.empty())
        return -1;

    const auto current = GetCurrentValue(*info, part);
    if (info->modelType != ModelType::Composite)
        return Step(allowed, current, next);

    std::vector<int32_t> models;
    for (auto value : allowed)
    {
        if (models.empty() || models.back() != value / 10)
            models.push_back(value / 10);
    }
    const auto model = Step(models, current / 10, next);

    // Keep the current color if the new model has it, otherwise its first allowed color.
    if (std::binary_search(allowed.begin(), allowed.end(), model * 10 + current % 10))
        return model * 10 + current % 10;
    return *std::lower_bound(allowed.begin(), allowed.end(), model * 10);
}

int32_t NextPreviousColor(ArgumentStack& args, bool next)
{
    auto *pItem = Utils::PopItem(args);
    const auto part = args.extract<int32_t>();

    auto info = GetItemInfo(pItem, part);
    if (!info)
        return -1;

    const auto allowed = GetAllowed(*info, part);
    const auto current = GetCurrentValue(*info, part);
    if (info->modelType != ModelType::Composite)
        return Step(allowed, current, next);

    std::vector<int32_t> colors;
    for (auto value : allowed)
    {
        if (value / 10 == current / 10)
            colors.push_back(value % 10);
    }
    return Step(colors, current % 10, next);
}

}

NWNX_EXPORT ArgumentStack CacheAppearances(ArgumentStack&&)
{
    s_appearances.clear();
    s_rules.clear();

    // Icons: i<class>_<number>, or i<class>_<b|m|t>_<number> for composite items (models <class>_<b|m|t>_<number>).
    std::unordered_map<std::string, std::set<int32_t>> simpleIcons;
    std::unordered_map<std::string, std::array<std::set<std::string>, NUM_PARTS>> partIcons;
    auto addIcon = [&](const std::string& name)
    {
        if (name.size() < 3 || name[0] != 'i')
            return;
        const auto underscore = name.find_last_of('_');
        const auto number = underscore == std::string::npos ? std::nullopt : ParseNumber(name.substr(underscore + 1));
        if (!number)
            return;

        // Values are stored in a uint16; simple model 0 can't be set.
        if (*number > UINT16_MAX)
            return;
        const auto prefix = name.substr(1, underscore - 1);
        if (*number > 0)
            simpleIcons[prefix].insert(*number);

        static const std::string partLetters = "bmt";
        if (prefix.size() > 2 && prefix[prefix.size() - 2] == '_')
        {
            const auto part = partLetters.find(prefix.back());
            if (part != std::string::npos)
                partIcons[prefix.substr(0, prefix.size() - 2)][part].insert(name.substr(1));
        }
    };
    // The client only loads item icons as TGA or PLT; a DDS-only icon fails item creation on the client.
    ForEachResOfType(Constants::ResRefType::TGA, addIcon);
    ForEachResOfType(Constants::ResRefType::PLT, addIcon);

    std::unordered_set<std::string> models;
    ForEachResOfType(Constants::ResRefType::MDL, [&](const std::string& name) { models.insert(name); });

    auto *pBaseItemArray = Globals::Rules()->m_pBaseItemArray;
    for (int32_t baseItem = 0; baseItem < pBaseItemArray->m_nNumBaseItems; baseItem++)
    {
        auto *pBaseItem = pBaseItemArray->GetBaseItem(baseItem);
        if (!pBaseItem || !pBaseItem->m_nName)
            continue;

        const auto itemClass = GetItemClass(pBaseItem);
        if (itemClass.empty() || s_appearances.count(itemClass))
            continue;

        auto& appearances = s_appearances[itemClass];
        switch (pBaseItem->m_nModelType)
        {
            case ModelType::Simple:
            case ModelType::Layered:
            {
                std::set<int32_t> numbers;
                auto it = simpleIcons.find(itemClass);
                if (it != simpleIcons.end())
                    numbers = it->second;
                // Cloak icons are icloak_m_<number>.
                it = simpleIcons.find(itemClass + "_m");
                if (pBaseItem->m_nModelType == ModelType::Layered && it != simpleIcons.end())
                    numbers.insert(it->second.begin(), it->second.end());
                appearances.simple.assign(numbers.begin(), numbers.end());
                break;
            }
            case ModelType::Composite:
            {
                auto it = partIcons.find(itemClass);
                if (it == partIcons.end())
                    break;

                // Drawn items (weapons) need a model for each icon; never-drawn items (boots) have none.
                bool hasModels = false;
                for (const auto& part : it->second)
                {
                    for (const auto& name : part)
                        hasModels = hasModels || models.count(name);
                }

                for (int32_t k = 0; k < NUM_PARTS; k++)
                {
                    for (const auto& name : it->second[k])
                    {
                        if (hasModels && !models.count(name))
                        {
                            LOG_WARNING("You have an icon for i%s but no model.", name.c_str());
                            continue;
                        }
                        appearances.parts[k].push_back(*ParseNumber(name.substr(name.find_last_of('_') + 1)));
                    }
                    std::sort(appearances.parts[k].begin(), appearances.parts[k].end());
                    appearances.parts[k].erase(std::unique(appearances.parts[k].begin(), appearances.parts[k].end()), appearances.parts[k].end());
                }
                break;
            }
            default:
                break;
        }
    }

    LOG_INFO("Cached appearances for %zu item classes.", s_appearances.size());
    return {};
}

NWNX_EXPORT ArgumentStack BlacklistAppearance(ArgumentStack&& args)
{
    const auto baseItem = args.extract<int32_t>();
    std::array<std::string, NUM_PARTS * 2> ranges;
    for (auto& range : ranges)
        range = args.extract<std::string>();

    auto *pBaseItem = GetBaseItem(baseItem);
    if (!pBaseItem)
    {
        LOG_WARNING("BlacklistAppearance: invalid base item %d", baseItem);
        return {};
    }

    // Simple and layered items have one model and no colors; a rule for more would block too much.
    if (pBaseItem->m_nModelType != ModelType::Composite &&
        std::any_of(ranges.begin() + 1, ranges.end(), [](const std::string& range) { return range != "*"; }))
    {
        LOG_WARNING("BlacklistAppearance: base item %d has a single model, only sBot can be used, rule ignored", baseItem);
        return {};
    }

    Rule rule;
    for (int32_t k = 0; k < NUM_PARTS * 2; k++)
    {
        auto parsed = ParseRanges(ranges[k]);
        if (!parsed)
        {
            LOG_WARNING("BlacklistAppearance: base item %d: invalid range '%s', rule ignored", baseItem, ranges[k].c_str());
            return {};
        }
        (k < NUM_PARTS ? rule.models[k] : rule.colors[k - NUM_PARTS]) = *parsed;
    }
    s_rules[GetItemClass(pBaseItem)].blacklist.push_back(std::move(rule));
    return {};
}

NWNX_EXPORT ArgumentStack SyncAppearance(ArgumentStack&& args)
{
    const auto baseItem = args.extract<int32_t>();
    const auto models = args.extract<std::string>();

    auto *pBaseItem = GetBaseItem(baseItem);
    if (!pBaseItem)
    {
        LOG_WARNING("SyncAppearance: invalid base item %d", baseItem);
        return {};
    }

    auto parsed = ParseRanges(models);
    if (!parsed)
    {
        LOG_WARNING("SyncAppearance: base item %d: invalid range '%s', ignored", baseItem, models.c_str());
        return {};
    }
    s_rules[GetItemClass(pBaseItem)].sync.push_back(std::move(*parsed));
    return {};
}

NWNX_EXPORT ArgumentStack GetRandomAppearance(ArgumentStack&& args)
{
    auto *pItem = Utils::PopItem(args);
    const auto part = args.extract<int32_t>();

    auto info = GetItemInfo(pItem, part);
    if (!info)
        return -1;
    return Pick(GetAllowed(*info, part));
}

NWNX_EXPORT ArgumentStack GetRandomWeaponAppearance(ArgumentStack&& args)
{
    Weapon weapon = {-1, -1, -1};

    auto info = GetItemInfo(Utils::PopItem(args), 0);
    if (!info || info->modelType != ModelType::Composite)
        return {weapon[0], weapon[1], weapon[2]};

    const auto& parts = info->pAppearances->parts;
    if (parts[0].empty() || parts[1].empty() || parts[2].empty())
        return {weapon[0], weapon[1], weapon[2]};

    // Bottom first: a synced bottom is used for all parts, otherwise synced models are left out of middle and top.
    std::array<std::vector<int32_t>, NUM_PARTS> unsynced;
    for (int32_t k = 1; k < NUM_PARTS; k++)
    {
        std::copy_if(parts[k].begin(), parts[k].end(), std::back_inserter(unsynced[k]),
                     [&](int32_t value) { return !IsSynced(info->pRules, value / 10); });
    }

    bool found = false;
    for (int32_t i = 0; i < RANDOM_WEAPON_TRIES && !found; i++)
    {
        Weapon candidate;
        candidate[0] = PickByModel(parts[0]);
        const bool synced = IsSynced(info->pRules, candidate[0] / 10);
        found = true;
        for (int32_t k = 1; k < NUM_PARTS && found; k++)
        {
            candidate[k] = PickByModel(synced ? GetWeaponChoices(info->pRules, parts[k], candidate[0] / 10) : unsynced[k]);
            found = candidate[k] != -1;
        }

        if (found && IsWeaponAllowed(info->pRules, candidate))
            weapon = candidate;
        else
            found = false;
    }

    // Blacklists can leave so few weapons that picking at random rarely finds one.
    if (!found)
    {
        if (auto searched = SearchWeapon(*info))
            weapon = *searched;
        else
            LOG_WARNING("GetRandomWeaponAppearance: no allowed appearance found for base item %d", info->pItem->m_nBaseItem);
    }
    return {weapon[0], weapon[1], weapon[2]};
}

NWNX_EXPORT ArgumentStack GetNextAppearance(ArgumentStack&& args)
{
    return NextPreviousAppearance(args, true);
}

NWNX_EXPORT ArgumentStack GetPreviousAppearance(ArgumentStack&& args)
{
    return NextPreviousAppearance(args, false);
}

NWNX_EXPORT ArgumentStack GetNextColor(ArgumentStack&& args)
{
    return NextPreviousColor(args, true);
}

NWNX_EXPORT ArgumentStack GetPreviousColor(ArgumentStack&& args)
{
    return NextPreviousColor(args, false);
}

NWNX_EXPORT ArgumentStack GetNextWeaponAppearance(ArgumentStack&& args)
{
    return StepWeaponAppearance(args, true);
}

NWNX_EXPORT ArgumentStack GetPreviousWeaponAppearance(ArgumentStack&& args)
{
    return StepWeaponAppearance(args, false);
}
