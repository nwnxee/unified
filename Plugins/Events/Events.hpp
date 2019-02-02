#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace Events {

class AssociateEvents;
class ClientEvents;
class CombatEvents;
class DMActionEvents;
class ExamineEvents;
class FeatEvents;
class ItemEvents;
class MapEvents;
class StealthEvents;
class SpellEvents;
class PartyEvents;
class HealerKitEvents;
class SkillEvents;
class PolymorphEvents;

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
    Events(const Plugin::CreateParams& params);
    virtual ~Events();

    // Pushes event data to the stack - won't do anything until SignalEvent is called.
    static void PushEventData(const std::string tag, const std::string data);

    // Get event data
    static std::string GetEventData(const std::string tag);

    // Returns true if the event can proceed, or false if the event has been skipped.
    static bool SignalEvent(const std::string& eventName, const NWNXLib::API::Types::ObjectID target, std::string *result=nullptr);

private: // Structures
    using EventMapType = std::unordered_map<std::string, std::vector<std::string>>;

private:
    NWNXLib::Services::Events::ArgumentStack OnSubscribeEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnPushEventData(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSignalEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetEventData(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSkipEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnEventResult(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetCurrentEvent(NWNXLib::Services::Events::ArgumentStack&& args);

    // Pushes a brand new event data onto the event data stack, set up with the correct defaults.
    // Only does it if needed though, based on the current event depth!
    void CreateNewEventDataIfNeeded();

    EventMapType m_eventMap; // Event name -> subscribers.
    std::stack<EventParams> m_eventData; // Data tag -> data for currently executing event.
    uint8_t m_eventDepth;

    std::unique_ptr<AssociateEvents> m_associateEvents;
    std::unique_ptr<ClientEvents> m_clientEvents;
    std::unique_ptr<CombatEvents> m_combatEvents;
    std::unique_ptr<DMActionEvents> m_dmActionEvents;
    std::unique_ptr<ExamineEvents> m_examineEvents;
    std::unique_ptr<FeatEvents> m_featEvents;
    std::unique_ptr<ItemEvents> m_itemEvents;
    std::unique_ptr<MapEvents> m_mapEvents;
    std::unique_ptr<StealthEvents> m_stealthEvents;
    std::unique_ptr<SpellEvents> m_spellEvents;
    std::unique_ptr<PartyEvents> m_partyEvents;
    std::unique_ptr<HealerKitEvents> m_healerKitEvents;
    std::unique_ptr<SkillEvents> m_skillEvents;
    std::unique_ptr<PolymorphEvents> m_polymorphEvents;
};

}
