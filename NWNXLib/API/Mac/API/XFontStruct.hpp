#pragma once

#include <cstdint>

#include "XCharStruct.hpp"
#include "unknown_XID.hpp"
#include "unknown__XExtData.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct XFontProp;

struct XFontStruct
{
    _XExtData* ext_data;
    XID fid;
    uint32_t direction;
    uint32_t min_char_or_byte2;
    uint32_t max_char_or_byte2;
    uint32_t min_byte1;
    uint32_t max_byte1;
    int32_t all_chars_exist;
    uint32_t default_char;
    int32_t n_properties;
    XFontProp* properties;
    XCharStruct min_bounds;
    XCharStruct max_bounds;
    XCharStruct* per_char;
    int32_t ascent;
    int32_t descent;
};

}

}
