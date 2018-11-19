#pragma once

#include <cstdint>

#include "addrinfo.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_addrinfo;
struct thread_data;

struct thread_sync_data
{
    pthread_mutex_t_0* mtx;
    int32_t done;
    char* hostname;
    int32_t port;
    int32_t sock_error;
    Curl_addrinfo* res;
    addrinfo hints;
    thread_data* td;
};

}

}
