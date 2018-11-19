#pragma once

#include <cstdint>

#include "unknown_CURLcode.hpp"
#include "unknown_sshstate.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct curl_slist;

struct ssh_conn
{
    const char* authlist;
    const char* passphrase;
    char* rsa_pub;
    char* rsa;
    bool authed;
    sshstate state;
    sshstate nextstate;
    CURLcode actualcode;
    curl_slist* quote_item;
    char* quote_path1;
    char* quote_path2;
    bool acceptfail;
    char* homedir;
    int32_t readdir_len;
    int32_t readdir_totalLen;
    int32_t readdir_currLen;
    char* readdir_line;
    char* readdir_linkPath;
    int32_t secondCreateDirs;
    char* slash_pos;
    int32_t orig_waitfor;
};

}

}
