#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ssl_primary_config
{
    int32_t version;
    int32_t version_max;
    bool verifypeer;
    bool verifyhost;
    bool verifystatus;
    bool sessionid;
    char* CApath;
    char* CAfile;
    char* clientcert;
    char* random_file;
    char* egdsocket;
    char* cipher_list;
};

}

}
