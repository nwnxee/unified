#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Extra2DA {

// str ... cha
struct StatBonus : public std::array<int32_t,6>
{
    void operator+=(const StatBonus &other);
    void operator-=(const StatBonus &other);
};

struct StatBonuses : public std::vector<StatBonus>
{
    std::string encode() const;
    static StatBonuses decode(const std::string &s);
};

class Extra2DA : public NWNXLib::Plugin
{
public:
    Extra2DA(const Plugin::CreateParams& params);
    virtual ~Extra2DA();

private:
    ArgumentStack GetDragonAbilityDivergence(ArgumentStack&& args);

    NWNXLib::Hooking::FunctionHook* m_ComputeFeatBonusesHook;
    StatBonuses m_DragonAbilityBonuses;

    static void LoadDragonAbilityBonuses();
    static StatBonuses GetDragonAbilityHistory(NWNXLib::API::CNWSCreature *pCreature);
    static void SetDragonAbilityHistory(NWNXLib::API::CNWSCreature *pCreature, const StatBonuses& sb);

    static void OnComputeFeatBonuses(NWNXLib::API::CNWSCreatureStats *pThis,
                                     NWNXLib::API::CExoArrayListTemplatedunsignedshort *pFeats,
                                     int32_t bSubtractBonuses, int32_t bLevelingDown);
};

}
