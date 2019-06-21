#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown_CURLcode.hpp"
#include "unknown_std__shared_ptrTemplatedDataBlock.hpp"
#include "unknown_std__vectorTemplatedHttpConnection__HeaderTuplestd__allocatorTemplatedHttpConnection__HeaderTuple.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct HttpBufferReceiver;

struct HttpBuffer
{
    std__shared_ptrTemplatedDataBlock m_buffer;
    uint32_t m_totalDownloadBytes;
    uint32_t m_receivedDownloadBytes;
    uint32_t m_averageDownloadSpeed;
    CExoString m_url;
    void* m_userData;
    int32_t m_finished;
    CURLcode m_result;
    char m_errbuf[256];
    HttpBufferReceiver* m_callback;
    std__vectorTemplatedHttpConnection__HeaderTuplestd__allocatorTemplatedHttpConnection__HeaderTuple m_responseHeaders;

    // The below are auto generated stubs.
    HttpBuffer() = default;
    HttpBuffer(const HttpBuffer&) = default;
    HttpBuffer& operator=(const HttpBuffer&) = default;

    HttpBuffer(const CExoString&, void*, HttpBufferReceiver*, uint32_t);
    ~HttpBuffer();
    void Complete(CURLcode);
    CExoString GetErrorMessage();
    int32_t GetIsFinished();
    int32_t GetIsSuccessful();
    void Progress(int32_t, int32_t, int32_t);
};

void HttpBuffer__HttpBufferCtor(HttpBuffer* thisPtr, const CExoString&, void*, HttpBufferReceiver*, uint32_t);
void HttpBuffer__HttpBufferDtor(HttpBuffer* thisPtr);
void HttpBuffer__Complete(HttpBuffer* thisPtr, CURLcode);
CExoString HttpBuffer__GetErrorMessage(HttpBuffer* thisPtr);
int32_t HttpBuffer__GetIsFinished(HttpBuffer* thisPtr);
int32_t HttpBuffer__GetIsSuccessful(HttpBuffer* thisPtr);
void HttpBuffer__Progress(HttpBuffer* thisPtr, int32_t, int32_t, int32_t);

}

}
