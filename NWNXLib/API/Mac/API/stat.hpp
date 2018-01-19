#pragma once

#include <cstdint>

#include "timespec.hpp"
#include "unknown___u_quad_t.hpp"

namespace NWNXLib {

namespace API {

struct stat
{
    __u_quad_t st_dev;
    uint16_t __pad1;
    uint32_t st_ino;
    uint32_t st_mode;
    uint32_t st_nlink;
    uint32_t st_uid;
    uint32_t st_gid;
    __u_quad_t st_rdev;
    uint16_t __pad2;
    int32_t st_size;
    int32_t st_blksize;
    int32_t st_blocks;
    timespec st_atim;
    timespec st_mtim;
    timespec st_ctim;
    uint32_t __glibc_reserved4;
    uint32_t __glibc_reserved5;
};

}

}
