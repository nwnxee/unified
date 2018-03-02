#pragma once

#include <cstdint>

#include "unknown___fsid_t.hpp"
#include "unknown___u_quad_t.hpp"

namespace NWNXLib {

namespace API {

struct statfs
{
    int32_t f_type;
    int32_t f_bsize;
    __u_quad_t f_blocks;
    __u_quad_t f_bfree;
    __u_quad_t f_bavail;
    __u_quad_t f_files;
    __u_quad_t f_ffree;
    __fsid_t f_fsid;
    int32_t f_namelen;
    int32_t f_frsize;
    int32_t f_flags;
    int32_t f_spare[4];
};

}

}
