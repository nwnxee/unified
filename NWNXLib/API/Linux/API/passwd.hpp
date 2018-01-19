#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct passwd
{
    char* pw_name;
    char* pw_passwd;
    uint32_t pw_uid;
    uint32_t pw_gid;
    char* pw_gecos;
    char* pw_dir;
    char* pw_shell;
};

}

}
