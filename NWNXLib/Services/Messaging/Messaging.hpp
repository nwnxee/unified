#pragma once

#include "Services/Services.hpp"

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace NWNXLib::Services {

class Messaging
{
public: // Structures
    using Tag = std::string;
    using Message = std::vector<std::string>;
    using Handler = std::function<void(const Message&)>;
    using HandlerId = uint32_t;

public:
    Messaging();
    ~Messaging();

    HandlerId SubscribeMessage(const Tag& tag, const Handler& handler);
    void UnsubscribeMessage(const HandlerId id);
    void BroadcastMessage(const Tag& tag, const Message& message);

private: // Structures
    using HandlerList = std::vector<std::pair<HandlerId, Handler>>;
    using MessageMap = std::unordered_map<Tag, HandlerList>;

private:
    MessageMap m_messageMap;
};

class MessagingProxy : public ServiceProxy<Messaging>
{
public:
    MessagingProxy(Messaging& metrics);
    ~MessagingProxy();

    Messaging::HandlerId SubscribeMessage(const Messaging::Tag& tag, const Messaging::Handler& handler);
    void UnsubscribeMessage(const Messaging::HandlerId id);
    void BroadcastMessage(const Messaging::Tag& tag, const Messaging::Message& message);

private:
    std::vector<Messaging::HandlerId> m_subscribed;
};

}
