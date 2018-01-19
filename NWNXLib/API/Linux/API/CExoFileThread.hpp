#pragma once

#include <cstdint>

#include "CExoCriticalSection.hpp"
#include "pthread_cond_t.hpp"
#include "pthread_mutex_t.hpp"
#include "unknown__IO_FILE.hpp"

namespace NWNXLib {

namespace API {

struct CExoFileThread
{
    uint32_t m_nThreadID;
    uint32_t m_pthThread;
    pthread_cond_t m_pthcCondition;
    pthread_mutex_t m_mxMutex;
    CExoCriticalSection m_csFileHandle;
    int32_t m_bReadComplete;
    int32_t m_bShutdownThread;
    _IO_FILE* m_pFile_Handle;
    int32_t m_nFile_Size;
    int32_t m_nFile_Number;
    int32_t m_nBytesRead;
    void* m_pFile_Buffer;

    // The below are auto generated stubs.
    CExoFileThread(const CExoFileThread&) = default;
    CExoFileThread& operator=(const CExoFileThread&) = default;

    CExoFileThread();
    ~CExoFileThread();
    void AsyncRead();
    void Read(void*, uint32_t, uint32_t, _IO_FILE*);
};

void CExoFileThread__CExoFileThreadCtor(CExoFileThread* thisPtr);
void CExoFileThread__CExoFileThreadDtor(CExoFileThread* thisPtr);
void CExoFileThread__AsyncRead(CExoFileThread* thisPtr);
void CExoFileThread__Read(CExoFileThread* thisPtr, void*, uint32_t, uint32_t, _IO_FILE*);

}

}
