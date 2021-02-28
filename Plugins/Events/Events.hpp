#pragma once

#include "nwnx.hpp"
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Events {

class AssociateEvents;
class BarterEvents;
class CalendarEvents;
class ClientEvents;
class CombatEvents;
class DMActionEvents;
class ExamineEvents;
class FactionEvents;
class FeatEvents;
class ItemEvents;
class MapEvents;
class StealthEvents;
class SpellEvents;
class PartyEvents;
class HealingEvents;
class SkillEvents;
class PolymorphEvents;
class EffectEvents;
class QuickChatEvents;
class InventoryEvents;
class TrapEvents;
class TimingBarEvents;
class LevelEvents;
class PVPEvents;
class InputEvents;
class MaterialChangeEvents;
class ObjectEvents;
class UUIDEvents;
class ResourceEvents;
class QuickbarEvents;
class DebugEvents;
class StoreEvents;
class JournalEvents;

class Events : public NWNXLib::Plugin
{
public: // Structures
    struct EventParams
    {
        // This maps between event data key -> event data value.
        std::unordered_map<std::string, std::string> m_EventDataMap;

        // This is true if SkipEvent() has been called on this event during its execution.
        bool m_Skipped;

        // The result of the event, if any, is stored here
        std::string m_Result;

        // The current event name
        std::string m_EventName;
    };

public:
    Events(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Events();

    // Pushes event data to the stack - won't do anything until SignalEvent is called.
    static void PushEventData(const std::string& tag, const std::string& data);

    // Get event data
    static std::string GetEventData(const std::string& tag);

    // Returns true if the event can proceed, or false if the event has been skipped.
    static bool SignalEvent(const std::string& eventName, const ObjectID target, std::string *result=nullptr);

    static void InitOnFirstSubscribe(const std::string& eventName, std::function<void(void)> init);

    static bool IsIDInWhitelist(const std::string& eventName, int32_t id);
    static void ForceEnableWhitelist(const std::string& eventName);

private: // Structures
    using EventMapType = std::unordered_map<std::string, std::vector<std::string>>;

private:
    ArgumentStack SubscribeEvent(ArgumentStack&& args);
    ArgumentStack UnsubscribeEvent(ArgumentStack&& args);
    ArgumentStack PushEventData(ArgumentStack&& args);
    ArgumentStack SignalEvent(ArgumentStack&& args);
    ArgumentStack GetEventData(ArgumentStack&& args);
    ArgumentStack SkipEvent(ArgumentStack&& args);
    ArgumentStack SetEventResult(ArgumentStack&& args);
    ArgumentStack GetCurrentEvent(ArgumentStack&& args);
    ArgumentStack ToggleDispatchListMode(ArgumentStack&& args);
    ArgumentStack AddObjectToDispatchList(ArgumentStack&& args);
    ArgumentStack RemoveObjectFromDispatchList(ArgumentStack&& args);
    ArgumentStack ToggleIDWhitelist(ArgumentStack&& args);
    ArgumentStack AddIDToWhitelist(ArgumentStack&& args);
    ArgumentStack RemoveIDFromWhitelist(ArgumentStack&& args);

    // Pushes a brand new event data onto the event data stack, set up with the correct defaults.
    // Only does it if needed though, based on the current event depth!
    void CreateNewEventDataIfNeeded();

    void RunEventInit(const std::string& eventName);

    EventMapType m_eventMap; // Event name -> subscribers.
    std::stack<EventParams> m_eventData; // Data tag -> data for currently executing event.
    uint8_t m_eventDepth;

    std::unordered_map<std::string, std::function<void(void)>> m_initList;
    std::unordered_map<std::string, std::set<ObjectID>> m_dispatchList;
    std::unordered_map<std::string, std::set<int32_t>> m_idWhitelist;

    std::unique_ptr<AssociateEvents> m_associateEvents;
    std::unique_ptr<BarterEvents> m_barterEvents;
    std::unique_ptr<CalendarEvents> m_calendarEvents;
    std::unique_ptr<ClientEvents> m_clientEvents;
    std::unique_ptr<CombatEvents> m_combatEvents;
    std::unique_ptr<DMActionEvents> m_dmActionEvents;
    std::unique_ptr<ExamineEvents> m_examineEvents;
    std::unique_ptr<FactionEvents> m_factionEvents;
    std::unique_ptr<FeatEvents> m_featEvents;
    std::unique_ptr<ItemEvents> m_itemEvents;
    std::unique_ptr<MapEvents> m_mapEvents;
    std::unique_ptr<StealthEvents> m_stealthEvents;
    std::unique_ptr<SpellEvents> m_spellEvents;
    std::unique_ptr<PartyEvents> m_partyEvents;
    std::unique_ptr<HealingEvents> m_healingEvents;
    std::unique_ptr<SkillEvents> m_skillEvents;
    std::unique_ptr<PolymorphEvents> m_polymorphEvents;
    std::unique_ptr<EffectEvents> m_effectEvents;
    std::unique_ptr<QuickChatEvents> m_quickChatEvents;
    std::unique_ptr<InventoryEvents> m_inventoryEvents;
    std::unique_ptr<TrapEvents> m_trapEvents;
    std::unique_ptr<TimingBarEvents> m_timingBarEvents;
    std::unique_ptr<LevelEvents> m_levelEvents;
    std::unique_ptr<PVPEvents> m_PVPEvents;
    std::unique_ptr<InputEvents> m_inputEvents;
    std::unique_ptr<MaterialChangeEvents> m_matChangeEvents;
    std::unique_ptr<ObjectEvents> m_objectEvents;
    std::unique_ptr<UUIDEvents> m_uuidEvents;
    std::unique_ptr<ResourceEvents> m_resourceEvents;
    std::unique_ptr<QuickbarEvents> m_quickbarEvents;
    std::unique_ptr<DebugEvents> m_debugEvents;
    std::unique_ptr<StoreEvents> m_storeEvents;
    std::unique_ptr<JournalEvents> m_journalEvents;
};

}
