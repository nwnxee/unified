#pragma once

#include <cstdint>

#include "Curl_tree.hpp"
#include "auth.hpp"
#include "curl_llist.hpp"
#include "curltime.hpp"
#include "digestdata.hpp"
#include "tempbuf.hpp"
#include "time_node.hpp"
#include "unknown_curl_read_callback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;
struct conncache;
struct connectdata;
struct curl_ssl_session;

struct UrlState
{
    conncache* conn_cache;
    bool multi_owned_by_easy;
    curltime keeps_speed;
    connectdata* lastconnect;
    char* headerbuff;
    uint32_t headersize;
    char* buffer;
    char uploadbuffer[16385];
    int64_t current_speed;
    bool this_is_a_follow;
    bool refused_stream;
    char* first_host;
    int32_t first_remote_port;
    curl_ssl_session* session;
    int32_t sessionage;
    uint32_t tempcount;
    tempbuf tempwrite[3];
    char* scratch;
    bool errorbuf;
    int32_t os_errno;
    void** m_funcPtrPlaceholder__0;
    bool allow_port;
    digestdata digest;
    digestdata proxydigest;
    auth authhost;
    auth authproxy;
    bool authproblem;
    void* resolver;
    curltime expiretime;
    Curl_tree timenode;
    curl_llist timeoutlist;
    time_node expires[10];
    char* most_recent_ftp_entrypath;
    bool ftp_trying_alternative;
    bool wildcardmatch;
    int32_t httpversion;
    bool expect100header;
    bool pipe_broke;
    bool prev_block_had_trailing_cr;
    int64_t crlf_conversions;
    char* pathbuffer;
    char* path;
    bool slash_removed;
    bool use_range;
    bool rangestringalloc;
    char* range;
    int64_t resume_from;
    int32_t rtsp_next_client_CSeq;
    int32_t rtsp_next_server_CSeq;
    int32_t rtsp_CSeq_recv;
    int64_t infilesize;
    uint32_t drain;
    bool done;
    curl_read_callback fread_func;
    void* in;
    Curl_easy* stream_depends_on;
    bool stream_depends_e;
    int32_t stream_weight;
};

}

}
