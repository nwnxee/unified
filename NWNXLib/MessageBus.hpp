#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace NWNXLib {

class MessageBus
{
public: // Structures
    using Tag = std::string;
    using Message = std::vector<std::string>;
    using Handler = std::function<void(const Message&)>;
    using HandlerId = uint32_t;

    static HandlerId Subscribe(const Tag& tag, const Handler& handler);
    static void Unsubscribe(const HandlerId id);
    static void Broadcast(const Tag& tag, const Message& message);

private: // Structures
    using HandlerList = std::vector<std::pair<HandlerId, Handler>>;
    using MessageMap = std::unordered_map<Tag, HandlerList>;

    static inline MessageMap s_messageMap;
};

}
