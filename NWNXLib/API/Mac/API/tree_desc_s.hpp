#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ct_data_s;
struct static_tree_desc_s;

struct tree_desc_s
{
    ct_data_s* dyn_tree;
    int32_t max_code;
    const static_tree_desc_s* stat_desc;
};

}

}
