#pragma once

#include <cstdint>

#include "sockaddr_in.hpp"
#include "unknown_cdkey_process_t.hpp"
#include "unknown_qr2_adderrorcallback_t.hpp"
#include "unknown_qr2_clientmessagecallback_t.hpp"
#include "unknown_qr2_countcallback_t.hpp"
#include "unknown_qr2_keylistcallback_t.hpp"
#include "unknown_qr2_natnegcallback_t.hpp"
#include "unknown_qr2_playerteamkeycallback_t.hpp"
#include "unknown_qr2_serverkeycallback_t.hpp"

namespace NWNXLib {

namespace API {

struct qr2_implementation_s
{
    int32_t hbsock;
    char gamename[64];
    char secret_key[64];
    char instance_key[4];
    qr2_serverkeycallback_t server_key_callback;
    qr2_playerteamkeycallback_t player_key_callback;
    qr2_playerteamkeycallback_t team_key_callback;
    qr2_keylistcallback_t key_list_callback;
    qr2_countcallback_t playerteam_count_callback;
    qr2_adderrorcallback_t adderror_callback;
    qr2_natnegcallback_t nn_callback;
    qr2_clientmessagecallback_t cm_callback;
    uint32_t lastheartbeat;
    uint32_t lastka;
    int32_t listed_state;
    int32_t ispublic;
    int32_t qport;
    int32_t read_socket;
    int32_t nat_negotiate;
    sockaddr_in hbaddr;
    cdkey_process_t cdkeyprocess;
    int32_t client_message_keys[10];
    int32_t cur_message_key;
    void* udata;
};

}

}
