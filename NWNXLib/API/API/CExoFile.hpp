#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoFile)
#endif

struct CExoFileInternal;
struct CExoString;


typedef int BOOL;
typedef uint16_t RESTYPE;


struct CExoFile
{
    CExoFileInternal * m_pcExoFileInternal;

    CExoFile(const CExoString & fileName, const CExoString & mode);
    CExoFile(const CExoString & fileName, RESTYPE fileType, const CExoString & mode);
    CExoFile(const void * pBuffer, int32_t nSize);
    void SetMemoryBuffer(const void * pMemoryBuffer, int32_t nSize);
    BOOL IsMemoryBacked() const;
    virtual ~CExoFile();
    BOOL Eof();
    BOOL FileOpened();
    BOOL Flush();
    uint32_t GetOffset();
    int32_t GetSize();
    uint32_t Read(void * ptr, uint32_t size, uint32_t number);
    uint32_t Read(CExoString & string, uint32_t length);
    uint32_t Write(const void * ptr, uint32_t size, uint32_t number);
    uint32_t Write(const char * string);
    uint32_t Write(const CExoString & string);
    BOOL Seek(int32_t offset, int32_t whence);
    BOOL SeekBeginning();
    BOOL SeekEnd();
    BOOL IsMMapped() const;
    BOOL GetIsEOS();
    void * GetFileHandle();


#ifdef NWN_CLASS_EXTENSION_CExoFile
    NWN_CLASS_EXTENSION_CExoFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoFile)
#endif

