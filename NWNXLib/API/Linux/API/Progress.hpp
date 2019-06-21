#pragma once

#include <cstdint>

#include "curltime.hpp"
#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct Progress
{
    __time_t lastshow;
    int64_t size_dl;
    int64_t size_ul;
    int64_t downloaded;
    int64_t uploaded;
    int64_t current_speed;
    bool callback;
    int32_t width;
    int32_t flags;
    __time_t timespent;
    int64_t dlspeed;
    int64_t ulspeed;
    __time_t t_nslookup;
    __time_t t_connect;
    __time_t t_appconnect;
    __time_t t_pretransfer;
    __time_t t_starttransfer;
    __time_t t_redirect;
    curltime start;
    curltime t_startsingle;
    curltime t_startop;
    curltime t_acceptdata;
    bool is_t_startransfer_set;
    curltime ul_limit_start;
    int64_t ul_limit_size;
    curltime dl_limit_start;
    int64_t dl_limit_size;
    int64_t speeder[6];
    curltime speeder_time[6];
    int32_t speeder_c;
};

}

}
