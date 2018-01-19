#pragma once

#include <cstdint>

#include "ct_data_s.hpp"
#include "tree_desc_s.hpp"
#include "unknown_Pos.hpp"
#include "unknown_uch.hpp"
#include "unknown_ush.hpp"
#include "unknown_z_Byte.hpp"
#include "unknown_z_gz_header.hpp"
#include "unknown_z_stream_0.hpp"

namespace NWNXLib {

namespace API {

struct z_internal_state
{
    z_stream_0* strm;
    int32_t status;
    z_Byte* pending_buf;
    uint32_t pending_buf_size;
    z_Byte* pending_out;
    uint32_t pending;
    int32_t wrap;
    z_gz_header* gzhead;
    uint32_t gzindex;
    uint8_t method;
    int32_t last_flush;
    uint32_t w_size;
    uint32_t w_bits;
    uint32_t w_mask;
    z_Byte* window;
    uint32_t window_size;
    Pos* prev;
    Pos* head;
    uint32_t ins_h;
    uint32_t hash_size;
    uint32_t hash_bits;
    uint32_t hash_mask;
    uint32_t hash_shift;
    int32_t block_start;
    uint32_t match_length;
    uint32_t prev_match;
    int32_t match_available;
    uint32_t strstart;
    uint32_t match_start;
    uint32_t lookahead;
    uint32_t prev_length;
    uint32_t max_chain_length;
    uint32_t max_lazy_match;
    int32_t level;
    int32_t strategy;
    uint32_t good_match;
    int32_t nice_match;
    ct_data_s dyn_ltree[573];
    ct_data_s dyn_dtree[61];
    ct_data_s bl_tree[39];
    tree_desc_s l_desc;
    tree_desc_s d_desc;
    tree_desc_s bl_desc;
    uint16_t bl_count[16];
    int32_t heap[573];
    int32_t heap_len;
    int32_t heap_max;
    uint8_t depth[573];
    uch* l_buf;
    uint32_t lit_bufsize;
    uint32_t last_lit;
    ush* d_buf;
    uint32_t opt_len;
    uint32_t static_len;
    uint32_t matches;
    uint32_t insert;
    uint16_t bi_buf;
    int32_t bi_valid;
    uint32_t high_water;
};

}

}
