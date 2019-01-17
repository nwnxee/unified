#pragma once

#include <cstdint>

#include "ConnectBits.hpp"
#include "Curl_async.hpp"
#include "Curl_chunker.hpp"
#include "curl_llist.hpp"
#include "curl_llist_element.hpp"
#include "curltime.hpp"
#include "dynamically_allocated_data.hpp"
#include "hostname.hpp"
#include "proxy_info.hpp"
#include "ssl_connect_data.hpp"
#include "ssl_primary_config.hpp"
#include "unknown_Curl_recv.hpp"
#include "unknown_Curl_send.hpp"
#include "unknown_TLS_E7F09F5CFAA32A5CE7DEF399A1D12299.hpp"
#include "unknown___time_t.hpp"
#include "unknown_curl_closesocket_callback.hpp"
#include "unknown_curl_seek_callback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_addrinfo;
struct Curl_dns_entry;
struct Curl_easy;
struct Curl_handler;
struct connectbundle;
struct http_connect_state;

struct connectdata
{
    Curl_easy* data;
    curl_llist_element bundle_node;
    Curl_chunker chunk;
    curl_closesocket_callback fclosesocket;
    void* closesocket_client;
    bool inuse;
    int32_t connection_id;
    Curl_dns_entry* dns_entry;
    Curl_addrinfo* ip_addr;
    Curl_addrinfo* tempaddr[2];
    char ip_addr_str[46];
    uint32_t scope_id;
    int32_t socktype;
    hostname host;
    char* secondaryhostname;
    hostname conn_to_host;
    proxy_info socks_proxy;
    proxy_info http_proxy;
    int32_t port;
    int32_t remote_port;
    int32_t conn_to_port;
    uint16_t secondary_port;
    char primary_ip[46];
    int32_t primary_port;
    char local_ip[46];
    int32_t local_port;
    char* user;
    char* passwd;
    char* options;
    char* oauth_bearer;
    int32_t httpversion;
    int32_t rtspversion;
    curltime now;
    curltime created;
    int32_t sock[2];
    int32_t tempsock[2];
    bool sock_accepted[2];
    Curl_recv* recv[2];
    Curl_send* send[2];
    ssl_connect_data ssl[2];
    ssl_connect_data proxy_ssl[2];
    ssl_primary_config ssl_config;
    ssl_primary_config proxy_ssl_config;
    bool tls_upgraded;
    ConnectBits bits;
    curltime connecttime;
    int32_t num_addr;
    __time_t timeoutms_per_addr;
    const Curl_handler* handler;
    const Curl_handler* given;
    int32_t ip_version;
    int32_t sockfd;
    int32_t writesockfd;
    dynamically_allocated_data allocptr;
    bool readchannel_inuse;
    bool writechannel_inuse;
    curl_llist send_pipe;
    curl_llist recv_pipe;
    char* master_buffer;
    uint32_t read_pos;
    uint32_t buf_len;
    curl_seek_callback seek_func;
    void* seek_client;
    char syserr_buf[256];
    Curl_async async;
    char* trailer;
    int32_t trlMax;
    int32_t trlPos;
    TLS_E7F09F5CFAA32A5CE7DEF399A1D12299 proto;
    int32_t cselect_bits;
    int32_t waitfor;
    char* localdev;
    uint16_t localport;
    int32_t localportrange;
    http_connect_state* connect_state;
    connectbundle* bundle;
    int32_t negnpn;
    char* unix_domain_socket;
    bool abstract_unix_socket;
};

}

}
