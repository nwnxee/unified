#pragma once

#include <cstdint>

#include "Curl_message.hpp"
#include "DynamicStatic.hpp"
#include "Names.hpp"
#include "Progress.hpp"
#include "PureInfo.hpp"
#include "SingleRequest.hpp"
#include "UrlState.hpp"
#include "UserDefined.hpp"
#include "WildcardData.hpp"
#include "curl_llist_element.hpp"
#include "curl_tlssessioninfo.hpp"
#include "unknown_CURLMstate.hpp"
#include "unknown_CURLcode.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CookieInfo;
struct Curl_multi;
struct Curl_share;
struct connectdata;

struct Curl_easy
{
    Curl_easy* next;
    Curl_easy* prev;
    connectdata* easy_conn;
    curl_llist_element connect_queue;
    curl_llist_element pipeline_queue;
    CURLMstate mstate;
    CURLcode result;
    Curl_message msg;
    int32_t sockets[5];
    int32_t numsocks;
    Names dns;
    Curl_multi* multi;
    Curl_multi* multi_easy;
    Curl_share* share;
    SingleRequest req;
    UserDefined set;
    DynamicStatic change;
    CookieInfo* cookies;
    Progress progress;
    UrlState state;
    WildcardData wildcard;
    PureInfo info;
    curl_tlssessioninfo tsi;
    uint32_t magic;
};

}

}
