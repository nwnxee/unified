#pragma once

#include <cstdint>

#include "unknown_Curl_do_more_func.hpp"
#include "unknown_Curl_done_func.hpp"

namespace NWNXLib {

namespace API {

struct Curl_handler
{
    const char* scheme;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    Curl_done_func done;
    Curl_do_more_func do_more;
    void** m_funcPtrPlaceholder__2;
    void** m_funcPtrPlaceholder__3;
    void** m_funcPtrPlaceholder__4;
    void** m_funcPtrPlaceholder__5;
    void** m_funcPtrPlaceholder__6;
    void** m_funcPtrPlaceholder__7;
    void** m_funcPtrPlaceholder__8;
    void** m_funcPtrPlaceholder__9;
    void** m_funcPtrPlaceholder__10;
    void** m_funcPtrPlaceholder__11;
    int32_t defport;
    uint32_t protocol;
    uint32_t flags;
};

}

}
