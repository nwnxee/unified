#pragma once

#include "nwnx.hpp"
#include <list>
#include <map>

using namespace std;

using ArgumentStack = NWNXLib::ArgumentStack;

namespace Layonara {

class Layonara : public NWNXLib::Plugin
{
public:
    Layonara(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Layonara();

private:
    static void RemoveEffectByTag(CNWSCreature *pCreature, std::string sCustomTag);
    static void SetArrowsEffect(CNWSCreature *pCreature, bool bOff=false);
    static CNWSItem *GetItemInSlotHook(CNWSInventory*, uint32_t);
    static void SetPositionHook(CNWSObject*, Vector, int32_t);
    static void SendMessageToCombatLog(CNWSCreature* target, const std::string& msg);
    NWNXLib::Hooks::FunctionHook* m_GetItemInSlotHook;

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

    enum SurfaceMaterials
    {
        UNDEFINED = 0,
        DIRT = 1,
        OBSCURING = 2,
        GRASS = 3,
        STONE = 4,
        WOOD = 5,
        WATER = 6,
        NONWALK = 7,
        TRANSPARENT = 8,
        CARPET = 9,
        METAL = 10,
        PUDDLES = 11,
        SWAMP = 12,
        MUD = 13,
        LEAVES = 14,
        LAVA = 15,
        BOTTOMLESSPIT = 16,
        DEEPWATER = 17,
        DOOR = 18,
        SNOW = 19,
        SAND = 20,
        BAREBONES = 21,
        STONEBRIDGE = 22,
        TEMP23 = 23,
        TEMP24 = 24,
        TEMP25 = 25,
        TEMP26 = 26,
        TEMP27 = 27,
        DIRTPATH = 28,
        STONEPATH = 29,
        TRIGGER = 30
    };

    unordered_map<uint8_t, std::array<int32_t, 10>> m_GemBonuses;
    unordered_map<uint8_t, int8_t> m_SurfaceMaterialSpeeds;
    unordered_map<ObjectID, int32_t> m_objectCurrentMaterial;

    std::list<int32_t> m_ElementalDamageTypes;
    std::list<int32_t> m_PhysicalDamageTypes;

    ArgumentStack SetEquippableSlots              (ArgumentStack&& args);
    ArgumentStack SetHostileFeat                  (ArgumentStack&& args);
    ArgumentStack SetDuelistCannyDefense          (ArgumentStack&& args);
    ArgumentStack SetDuelistGrace                 (ArgumentStack&& args);
    ArgumentStack SetDuelistElaborateParry        (ArgumentStack&& args);
    ArgumentStack SetSubraceDayEffects            (ArgumentStack&& args);
    ArgumentStack ApplyRune                       (ArgumentStack&& args);
    ArgumentStack CombineRunes                    (ArgumentStack&& args);
    ArgumentStack GetRuneDescription              (ArgumentStack&& args);
    ArgumentStack SetQuiver                       (ArgumentStack&& args);
    ArgumentStack SetQuiverArrows                 (ArgumentStack&& args);
    ArgumentStack CreateVFXAtTransitionCentroid   (ArgumentStack&& args);
    ArgumentStack ClearSurfaceMaterial            (ArgumentStack&& args);
};

}
