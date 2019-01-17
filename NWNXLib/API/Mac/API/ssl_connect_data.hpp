#pragma once

#include <cstdint>

#include "unknown_ssl_connect_state.hpp"
#include "unknown_ssl_connection_state.hpp"

namespace NWNXLib {

namespace API {

struct ssl_connect_data
{
    bool use;
    ssl_connection_state state;
    ssl_connect_state connecting_state;
};

}

}
