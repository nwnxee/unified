#include "MessageBus.hpp"

#include <algorithm>

namespace NWNXLib {

MessageBus::HandlerId MessageBus::Subscribe(const MessageBus::Tag& tag, const MessageBus::Handler& handler)
{
    static HandlerId s_nextHandlerId = 0;
    HandlerId nextId = s_nextHandlerId++;
    s_messageMap[tag].push_back(std::make_pair(nextId, handler));
    return nextId;
}

void MessageBus::Unsubscribe(const MessageBus::HandlerId id)
{
    for (auto& bucket : s_messageMap)
    {
        HandlerList& handlers = bucket.second;
        auto entry = std::find_if(std::begin(handlers), std::end(handlers), [id](const auto& elem)
        {
            return elem.first == id;
        });

        if (entry != std::end(handlers))
        {
            handlers.erase(entry);
            return;
        }
    }

    throw std::runtime_error("Tried to unsubscribe with an ID that wasn't present.");
}

void MessageBus::Broadcast(const MessageBus::Tag& tag, const MessageBus::Message& message)
{
    auto bucket = s_messageMap.find(tag);

    if (bucket == std::end(s_messageMap))
    {
        return;
    }

    for (std::pair<HandlerId, Handler>& entry : bucket->second)
    {
        entry.second(message);
    }
}

}
