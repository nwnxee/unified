#pragma once

#include <cstdint>

#include "unknown_peerCrossPingCallback.hpp"
#include "unknown_peerDisconnectedCallback.hpp"
#include "unknown_peerGameStartedCallback.hpp"
#include "unknown_peerGlobalKeyChangedCallback.hpp"
#include "unknown_peerKickedCallback.hpp"
#include "unknown_peerNewPlayerListCallback.hpp"
#include "unknown_peerPingCallback.hpp"
#include "unknown_peerPlayerChangedNickCallback.hpp"
#include "unknown_peerPlayerFlagsChangedCallback.hpp"
#include "unknown_peerPlayerInfoCallback.hpp"
#include "unknown_peerPlayerJoinedCallback.hpp"
#include "unknown_peerPlayerLeftCallback.hpp"
#include "unknown_peerPlayerMessageCallback.hpp"
#include "unknown_peerPlayerUTMCallback.hpp"
#include "unknown_peerQRAddErrorCallback.hpp"
#include "unknown_peerQRCountCallback.hpp"
#include "unknown_peerQRKeyListCallback.hpp"
#include "unknown_peerQRNatNegotiateCallback.hpp"
#include "unknown_peerQRPlayerKeyCallback.hpp"
#include "unknown_peerQRServerKeyCallback.hpp"
#include "unknown_peerQRTeamKeyCallback.hpp"
#include "unknown_peerReadyChangedCallback.hpp"
#include "unknown_peerRoomKeyChangedCallback.hpp"
#include "unknown_peerRoomMessageCallback.hpp"
#include "unknown_peerRoomModeChangedCallback.hpp"
#include "unknown_peerRoomNameChangedCallback.hpp"
#include "unknown_peerRoomUTMCallback.hpp"

namespace NWNXLib {

namespace API {

struct PEERCallbacks
{
    peerDisconnectedCallback disconnected;
    peerRoomMessageCallback roomMessage;
    peerRoomUTMCallback roomUTM;
    peerRoomNameChangedCallback roomNameChanged;
    peerRoomModeChangedCallback roomModeChanged;
    peerPlayerMessageCallback playerMessage;
    peerPlayerUTMCallback playerUTM;
    peerReadyChangedCallback readyChanged;
    peerGameStartedCallback gameStarted;
    peerPlayerJoinedCallback playerJoined;
    peerPlayerLeftCallback playerLeft;
    peerKickedCallback kicked;
    peerNewPlayerListCallback newPlayerList;
    peerPlayerChangedNickCallback playerChangedNick;
    peerPlayerInfoCallback playerInfo;
    peerPlayerFlagsChangedCallback playerFlagsChanged;
    peerPingCallback ping;
    peerCrossPingCallback crossPing;
    peerGlobalKeyChangedCallback globalKeyChanged;
    peerRoomKeyChangedCallback roomKeyChanged;
    peerQRServerKeyCallback qrServerKey;
    peerQRPlayerKeyCallback qrPlayerKey;
    peerQRTeamKeyCallback qrTeamKey;
    peerQRKeyListCallback qrKeyList;
    peerQRCountCallback qrCount;
    peerQRAddErrorCallback qrAddError;
    peerQRNatNegotiateCallback qrNatNegotiateCallback;
    void* param;
};

}

}
