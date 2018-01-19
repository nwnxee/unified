#pragma once

#include <cstdint>

#include "unknown___fsid_t.hpp"

namespace NWNXLib {

namespace API {

struct statfs
{
    int32_t f_type;
    int32_t f_bsize;
    uint32_t f_blocks;
    uint32_t f_bfree;
    uint32_t f_bavail;
    uint32_t f_files;
    uint32_t f_ffree;
    __fsid_t f_fsid;
    int32_t f_namelen;
    int32_t f_frsize;
    int32_t f_flags;
    int32_t f_spare[4];
};

}

}
