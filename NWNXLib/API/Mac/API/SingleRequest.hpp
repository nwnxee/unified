#pragma once

#include <cstdint>

#include "curltime.hpp"
#include "unknown_TLS_E4C28B22DC4D5CEAE742B86B03E3B761.hpp"
#include "unknown___ssize_t.hpp"
#include "unknown___time_t.hpp"
#include "unknown_expect100.hpp"
#include "unknown_upgrade101.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct contenc_writer_s;

struct SingleRequest
{
    int64_t size;
    int64_t* bytecountp;
    int64_t maxdownload;
    int64_t* writebytecountp;
    int64_t bytecount;
    int64_t writebytecount;
    int32_t headerbytecount;
    int32_t deductheadercount;
    curltime start;
    curltime now;
    bool header;
    TLS_E4C28B22DC4D5CEAE742B86B03E3B761 badheader;
    int32_t headerline;
    char* hbufp;
    uint32_t hbuflen;
    char* str;
    char* str_start;
    char* end_ptr;
    char* p;
    bool content_range;
    int64_t offset;
    int32_t httpcode;
    curltime start100;
    expect100 exp100;
    upgrade101 upgr101;
    contenc_writer_s* writer_stack;
    __time_t timeofdoc;
    int32_t bodywrites;
    char* buf;
    int32_t maxfd;
    int32_t keepon;
    bool upload_done;
    bool ignorebody;
    bool ignorecl;
    char* location;
    char* newurl;
    __ssize_t upload_present;
    char* upload_fromhere;
    bool chunk;
    bool upload_chunky;
    bool getheader;
    bool forbidchunk;
    void* protop;
};

}

}
