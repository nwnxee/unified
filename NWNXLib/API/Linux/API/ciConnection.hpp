#pragma once

#include <cstdint>

#include "chatGlobalCallbacks.hpp"
#include "ciSocket.hpp"
#include "unknown_CHATBool.hpp"
#include "unknown_chatConnectCallback.hpp"
#include "unknown_chatFillInUserCallback.hpp"
#include "unknown_chatNickErrorCallback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DArrayImplementation;
struct HashImplementation;
struct ciServerMessageFilter;

struct ciConnection
{
    CHATBool connected;
    CHATBool connecting;
    CHATBool disconnected;
    chatNickErrorCallback nickErrorCallback;
    chatFillInUserCallback fillInUserCallback;
    chatConnectCallback connectCallback;
    void* connectParam;
    ciSocket chatSocket;
    char nick[64];
    char name[128];
    char user[128];
    uint32_t IP;
    char server[128];
    int32_t port;
    chatGlobalCallbacks globalCallbacks;
    HashImplementation* channelTable;
    DArrayImplementation* enteringChannelList;
    ciServerMessageFilter* filterList;
    ciServerMessageFilter* lastFilter;
    int32_t nextID;
    DArrayImplementation* callbackList;
    CHATBool quiet;
    char secretKey[128];
};

}

}
