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
class DMActionEvents;
class ExamineEvents;
class FeatEvents;
class ItemEvents;
class StealthEvents;

class Events : public NWNXLib::Plugin
{
public: // Structures
    using DataMapType = std::unordered_map<std::string, std::string>;

public:
    Events(const Plugin::CreateParams& params);
    virtual ~Events();

    static void PushEventData(const std::string tag, const std::string data);

    // Returns true if one or more events were dispatched. False otherwise (e.g. no subscribers).
    static bool SignalEvent(const std::string& eventName, const NWNXLib::API::Types::ObjectID target);

private: // Structures
    using EventMapType = std::unordered_map<std::string, std::vector<std::string>>;

private:
    NWNXLib::Services::Events::ArgumentStack OnSubscribeEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnPushEventData(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSignalEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetEventData(NWNXLib::Services::Events::ArgumentStack&& args);

    EventMapType m_eventMap; // Event name -> subscribers.
    std::stack<DataMapType> m_eventData; // Data tag -> data for currently executing event.
    uint8_t m_eventDepth;

    std::unique_ptr<AssociateEvents> m_associateEvents;
    std::unique_ptr<ClientEvents> m_clientEvents;
    std::unique_ptr<DMActionEvents> m_dmActionEvents;
    std::unique_ptr<ExamineEvents> m_examineEvents;
    std::unique_ptr<FeatEvents> m_featEvents;
    std::unique_ptr<ItemEvents> m_itemEvents;
    std::unique_ptr<StealthEvents> m_stealthEvents;
};

}
