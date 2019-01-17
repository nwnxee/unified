#pragma once

#include <cstdint>

#include "pingpong.hpp"
#include "unknown_curl_ftpfile.hpp"
#include "unknown_ftpstate.hpp"

namespace NWNXLib {

namespace API {

struct ftp_conn
{
    pingpong pp;
    char* entrypath;
    char** dirs;
    int32_t dirdepth;
    int32_t diralloc;
    char* file;
    bool dont_check;
    bool ctl_valid;
    bool cwddone;
    int32_t cwdcount;
    bool cwdfail;
    bool wait_data_conn;
    char* prevpath;
    curl_ftpfile prevmethod;
    char transfertype;
    int32_t count1;
    int32_t count2;
    int32_t count3;
    ftpstate state;
    ftpstate state_saved;
    int64_t retr_size_saved;
    char* server_os;
    int64_t known_filesize;
    char* newhost;
    uint16_t newport;
};

}

}
