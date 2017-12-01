#pragma once

#include <cstdint>

#include "PEERCallbacks.hpp"
#include "unknown_PEERAutoMatchStatus.hpp"
#include "unknown_PEERBool.hpp"
#include "unknown__SBQueryEngine.hpp"
#include "unknown__SBServer.hpp"
#include "unknown__SBServerList.hpp"
#include "unknown_peerListingGamesCallback.hpp"
#include "unknown_peerNickErrorCallback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DArrayImplementation;
struct HashImplementation;
struct piOperation;
struct qr2_implementation_s;

struct piConnection
{
    void* chat;
    char nick[64];
    PEERBool connecting;
    PEERBool connected;
    peerNickErrorCallback nickErrorCallback;
    uint32_t lastChatPing;
    uint32_t publicIP;
    uint32_t privateIP;
    int32_t profileID;
    char title[32];
    char rooms[3][257];
    PEERBool enteringRoom[3];
    PEERBool inRoom[3];
    char names[3][512];
    int32_t oldFlags[3];
    int32_t groupID;
    char titleRoomChannel[257];
    PEERBool stayInTitleRoom;
    HashImplementation* players;
    int32_t numPlayers[3];
    PEERBool alwaysRequestPlayerInfo;
    PEERBool doPings;
    int32_t lastPingTimeMod;
    PEERBool pingRoom[3];
    PEERBool xpingRoom[3];
    HashImplementation* xpings;
    uint32_t lastXpingSend;
    qr2_implementation_s* queryReporting;
    char qrSecretKey[64];
    PEERBool natNegotiate;
    int32_t reportingOptions;
    int32_t reportingGroupID;
    PEERBool hosting;
    PEERBool playing;
    int32_t maxPlayers;
    PEERBool passwordedRoom;
    _SBServer* hostServer;
    PEERBool ready;
    char sbName[32];
    char sbSecretKey[32];
    int32_t sbGameVersion;
    int32_t sbMaxUpdates;
    PEERBool sbInitialized;
    _SBServerList gameList;
    _SBServerList groupList;
    _SBQueryEngine gameEngine;
    peerListingGamesCallback gameListCallback;
    void* gameListParam;
    PEERBool initialGameList;
    piOperation* listingGroupsOperation;
    int32_t nextID;
    DArrayImplementation* operationList;
    int32_t operationsStarted;
    int32_t operationsFinished;
    PEERCallbacks callbacks;
    DArrayImplementation* callbackList;
    int32_t callbacksQueued;
    int32_t callbacksCalled;
    int32_t callbackDepth;
    PEERBool away;
    char awayReason[128];
    HashImplementation* globalWatchKeys[3];
    HashImplementation* roomWatchKeys[3];
    HashImplementation* globalWatchCache;
    HashImplementation* roomWatchCache[3];
    PEERAutoMatchStatus autoMatchStatus;
    _SBServerList autoMatchList;
    _SBQueryEngine autoMatchEngine;
    PEERBool autoMatchBrowsing;
    piOperation* autoMatchOperation;
    qr2_implementation_s* autoMatchReporting;
    char* autoMatchFilter;
    PEERBool autoMatchSBFailed;
    PEERBool autoMatchQRFailed;
    PEERBool disconnect;
    PEERBool shutdown;
};

}

}
