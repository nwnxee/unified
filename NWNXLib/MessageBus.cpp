#include "nwnx.hpp"
#include <algorithm>

namespace NWNXLib::MessageBus
{

using HandlerList = std::vector<std::pair<uint32_t, Handler>>;
using MessageMap = std::unordered_map<std::string, HandlerList>;
static MessageMap s_messageMap;

uint32_t Subscribe(const std::string& tag, const Handler& handler)
{
    static uint32_t s_nextHandlerId = 0;
    uint32_t nextId = s_nextHandlerId++;
    s_messageMap[tag].push_back(std::make_pair(nextId, handler));
    return nextId;
}

void Unsubscribe(const uint32_t id)
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

void Broadcast(const std::string& tag, const Message& message)
{
    auto bucket = s_messageMap.find(tag);

    if (bucket == std::end(s_messageMap))
    {
        return;
    }

    for (std::pair<uint32_t, Handler>& entry : bucket->second)
    {
        entry.second(message);
    }
}

}
