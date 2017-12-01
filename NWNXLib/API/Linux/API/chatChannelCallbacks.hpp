#pragma once

#include <cstdint>

#include "unknown_chatBroadcastKeyChanged.hpp"
#include "unknown_chatChannelMessage.hpp"
#include "unknown_chatChannelModeChanged.hpp"
#include "unknown_chatKicked.hpp"
#include "unknown_chatNewUserList.hpp"
#include "unknown_chatTopicChanged.hpp"
#include "unknown_chatUserChangedNick.hpp"
#include "unknown_chatUserJoined.hpp"
#include "unknown_chatUserListUpdated.hpp"
#include "unknown_chatUserModeChanged.hpp"
#include "unknown_chatUserParted.hpp"

namespace NWNXLib {

namespace API {

struct chatChannelCallbacks
{
    chatChannelMessage channelMessage;
    chatKicked kicked;
    chatUserJoined userJoined;
    chatUserParted userParted;
    chatUserChangedNick userChangedNick;
    chatTopicChanged topicChanged;
    chatChannelModeChanged channelModeChanged;
    chatUserModeChanged userModeChanged;
    chatUserListUpdated userListUpdated;
    chatNewUserList newUserList;
    chatBroadcastKeyChanged broadcastKeyChanged;
    void* param;
};

}

}
