#pragma once

#include <cstdint>

#include "mime_encoder_state.hpp"
#include "mime_state.hpp"
#include "unknown__IO_FILE.hpp"
#include "unknown_curl_free_callback.hpp"
#include "unknown_curl_read_callback.hpp"
#include "unknown_curl_seek_callback.hpp"
#include "unknown_mimekind.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Curl_easy;
struct curl_mime_s;
struct curl_slist;
struct mime_encoder;

struct curl_mimepart_s
{
    Curl_easy* easy;
    curl_mime_s* parent;
    curl_mimepart_s* nextpart;
    mimekind kind;
    char* data;
    curl_read_callback readfunc;
    curl_seek_callback seekfunc;
    curl_free_callback freefunc;
    void* arg;
    _IO_FILE* fp;
    curl_slist* curlheaders;
    curl_slist* userheaders;
    char* mimetype;
    char* filename;
    char* name;
    int64_t datasize;
    uint32_t flags;
    mime_state state;
    const mime_encoder* encoder;
    mime_encoder_state encstate;
};

}

}
