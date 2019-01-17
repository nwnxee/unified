#pragma once

#include <cstdint>

#include "curl_fileinfo.hpp"
#include "curl_llist_element.hpp"

namespace NWNXLib {

namespace API {

struct fileinfo
{
    curl_fileinfo info;
    curl_llist_element list;
};

}

}
