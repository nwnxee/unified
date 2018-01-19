#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ct_data_s;

struct static_tree_desc_s
{
    const ct_data_s* static_tree;
    const int32_t* extra_bits;
    int32_t extra_base;
    int32_t elems;
    int32_t max_length;
};

}

}
