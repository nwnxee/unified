#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown_std__vectorTemplatedHttpConnection__QueuedURLstd__allocatorTemplatedHttpConnection__QueuedURL.hpp"
#include "unknown_std__vectorTemplatedvoidPtrstd__allocatorTemplatedvoidPtr.hpp"

namespace NWNXLib {

namespace API {

struct HttpConnection
{
    int32_t m_handleCount;
    void* m_multiHandle;
    std__vectorTemplatedvoidPtrstd__allocatorTemplatedvoidPtr m_easyHandles;
    std__vectorTemplatedHttpConnection__QueuedURLstd__allocatorTemplatedHttpConnection__QueuedURL m_urls;
    int32_t m_writeBufferSize;

    // The below are auto generated stubs.
    HttpConnection(const HttpConnection&) = default;
    HttpConnection& operator=(const HttpConnection&) = default;

    HttpConnection();
    ~HttpConnection();
    void Cancel();
    static CExoString Escape(const CExoString&);
    int32_t GetIsFinished();
    int32_t GetIsRunning();
    int32_t RecycleHandle(void*);
    void SetBufferSize(int32_t);
    int32_t StartDownloadsAsNeeded();
    static CExoString Unescape(const CExoString&);
    int32_t Update();
    static uint32_t WriteCallback(char*, uint32_t, uint32_t, void*);
    static uint32_t WriteHeaderCallback(char*, uint32_t, uint32_t, void*);
};

void HttpConnection__HttpConnectionCtor(HttpConnection* thisPtr);
void HttpConnection__HttpConnectionDtor(HttpConnection* thisPtr);
void HttpConnection__Cancel(HttpConnection* thisPtr);
CExoString HttpConnection__Escape(const CExoString&);
int32_t HttpConnection__GetIsFinished(HttpConnection* thisPtr);
int32_t HttpConnection__GetIsRunning(HttpConnection* thisPtr);
int32_t HttpConnection__RecycleHandle(HttpConnection* thisPtr, void*);
void HttpConnection__SetBufferSize(HttpConnection* thisPtr, int32_t);
int32_t HttpConnection__StartDownloadsAsNeeded(HttpConnection* thisPtr);
CExoString HttpConnection__Unescape(const CExoString&);
int32_t HttpConnection__Update(HttpConnection* thisPtr);
uint32_t HttpConnection__WriteCallback(char*, uint32_t, uint32_t, void*);
uint32_t HttpConnection__WriteHeaderCallback(char*, uint32_t, uint32_t, void*);

}

}
