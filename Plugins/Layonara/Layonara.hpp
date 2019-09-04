#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <list>
#include <map>

using namespace std;

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Layonara {

class Layonara : public NWNXLib::Plugin
{
public:
    Layonara(const Plugin::CreateParams& params);
    virtual ~Layonara();

private:
    static void SetArrowsEffect(NWNXLib::API::CNWSCreature *pCreature, bool bOff=false);
    static NWNXLib::API::CNWSItem *GetItemInSlotHook(NWNXLib::API::CNWSInventory*, uint32_t);
    NWNXLib::Hooking::FunctionHook* m_GetItemInSlotHook;

    enum Gems
    {
        GRE = 1,
        MAL = 2,
        FIA = 3,
        AVE = 4,
        PHE = 5,
        AME = 6,
        FEL = 7,
        GAR = 8,
        ALE = 9,
        TOP = 10,
        SAP = 11,
        FIO = 12,
        DIA = 13,
        RUB = 14,
        EME = 15
    };

    enum Runes
    {
        SHADOW = 0x0001,
        TIDAL = 0x0002,
        FORESTAL = 0x0004,
        ALNOTH = 0x0008
    };

    unordered_map<uint8_t, std::array<int32_t, 10>> m_GemBonuses;

    std::list<int32_t> m_ElementalDamageTypes;
    std::list<int32_t> m_PhysicalDamageTypes;

    ArgumentStack SetEquippableSlots              (ArgumentStack&& args);
    ArgumentStack SetHostileFeat                  (ArgumentStack&& args);
    ArgumentStack SetDuelistCannyDefense          (ArgumentStack&& args);
    ArgumentStack SetDuelistGrace                 (ArgumentStack&& args);
    ArgumentStack SetDuelistElaborateParry        (ArgumentStack&& args);
    ArgumentStack SetSpellswordIgnoreSpellFailure (ArgumentStack&& args);
    ArgumentStack SetUndeadSlayerImmunity         (ArgumentStack&& args);
    ArgumentStack SetSubraceDayEffects            (ArgumentStack&& args);
    ArgumentStack ApplyRune                       (ArgumentStack&& args);
    ArgumentStack CombineRunes                    (ArgumentStack&& args);
    ArgumentStack GetRuneDescription              (ArgumentStack&& args);
    ArgumentStack SetQuiver                       (ArgumentStack&& args);
    ArgumentStack SetQuiverArrows                 (ArgumentStack&& args);
    ArgumentStack CreateVFXAtTransitionCentroid   (ArgumentStack&& args);
};

}
