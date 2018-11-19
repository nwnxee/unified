#pragma once

#include <cstdint>

#include "conncache.hpp"
#include "curl_hash.hpp"
#include "curl_llist.hpp"
#include "curltime.hpp"
#include "unknown_curl_multi_timer_callback.hpp"
#include "unknown_curl_push_callback.hpp"
#include "unknown_curl_socket_callback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;
struct Curl_tree;

struct Curl_multi
{
    int32_t type;
    Curl_easy* easyp;
    Curl_easy* easylp;
    int32_t num_easy;
    int32_t num_alive;
    curl_llist msglist;
    curl_llist pending;
    curl_socket_callback socket_cb;
    void* socket_userp;
    curl_push_callback push_cb;
    void* push_userp;
    curl_hash hostcache;
    Curl_tree* timetree;
    curl_hash sockhash;
    int32_t pipelining;
    bool recheckstate;
    conncache conn_cache;
    int32_t maxconnects;
    int32_t max_host_connections;
    int32_t max_total_connections;
    int32_t max_pipeline_length;
    int32_t content_length_penalty_size;
    int32_t chunk_length_penalty_size;
    curl_llist pipelining_site_bl;
    curl_llist pipelining_server_bl;
    curl_multi_timer_callback timer_cb;
    void* timer_userp;
    curltime timer_lastcall;
    bool in_callback;
};

}

}
