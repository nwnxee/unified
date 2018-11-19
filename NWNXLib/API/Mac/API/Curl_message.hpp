#pragma once

#include <cstdint>

#include "CURLMsg.hpp"
#include "curl_llist_element.hpp"

namespace NWNXLib {

namespace API {

struct Curl_message
{
    curl_llist_element list;
    CURLMsg extmsg;
};

}

}
