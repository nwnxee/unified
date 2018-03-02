#pragma once

#include <cstdint>

#include "timespec.hpp"
#include "unknown___quad_t.hpp"
#include "unknown___u_quad_t.hpp"

namespace NWNXLib {

namespace API {

struct stat
{
    __u_quad_t st_dev;
    uint16_t __pad1;
    uint32_t __st_ino;
    uint32_t st_mode;
    uint32_t st_nlink;
    uint32_t st_uid;
    uint32_t st_gid;
    __u_quad_t st_rdev;
    uint16_t __pad2;
    __quad_t st_size;
    int32_t st_blksize;
    __quad_t st_blocks;
    timespec st_atim;
    timespec st_mtim;
    timespec st_ctim;
    __u_quad_t st_ino;
};

}

}
