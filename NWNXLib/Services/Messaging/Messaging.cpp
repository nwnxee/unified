#include "Services/Messaging/Messaging.hpp"

#include <algorithm>

namespace NWNXLib {

namespace Services {

Messaging::Messaging()
{
}

Messaging::~Messaging()
{
}

Messaging::HandlerId Messaging::SubscribeMessage(const Messaging::Tag& tag, const Messaging::Handler& handler)
{
    static HandlerId s_nextHandlerId = 0;
    HandlerId nextId = s_nextHandlerId++;
    m_messageMap[tag].push_back(std::make_pair(nextId, handler));
    return nextId;
}

void Messaging::UnsubscribeMessage(const Messaging::HandlerId id)
{
    for (auto& bucket : m_messageMap)
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

void Messaging::BroadcastMessage(const Messaging::Tag& tag, const Messaging::Message& message)
{
    auto bucket = m_messageMap.find(tag);

    if (bucket == std::end(m_messageMap))
    {
        return;
    }

    for (std::pair<HandlerId, Handler>& entry : bucket->second)
    {
        entry.second(message);
    }
}

MessagingProxy::MessagingProxy(Messaging& messaging)
    : ServiceProxy<Messaging>(messaging)
{
}

MessagingProxy::~MessagingProxy()
{
    for (auto& id : m_subscribed)
    {
        m_proxyBase.UnsubscribeMessage(id);
    }
}

Messaging::HandlerId MessagingProxy::SubscribeMessage(const Messaging::Tag& tag, const Messaging::Handler& handler)
{
    Messaging::HandlerId id = m_proxyBase.SubscribeMessage(tag, handler);
    m_subscribed.push_back(id);
    return id;
}

void MessagingProxy::UnsubscribeMessage(const Messaging::HandlerId id)
{
    auto subscribed = std::find(std::begin(m_subscribed), std::end(m_subscribed), id);

    if (subscribed == std::end(m_subscribed))
    {
        throw std::runtime_error("Tried to unsubscribe with an ID that wasn't present.");
    }

    m_proxyBase.UnsubscribeMessage(*subscribed);
    m_subscribed.erase(subscribed);
}

void MessagingProxy::BroadcastMessage(const Messaging::Tag& tag, const Messaging::Message& message)
{
    m_proxyBase.BroadcastMessage(tag, message);
}

}

}
