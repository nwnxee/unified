#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoDebugInternal)
#endif

struct CExoFile;


typedef int BOOL;


struct CExoDebugInternal
{
    BOOL m_bFilesOpen;
    CExoFile * m_pLogFile;
    CExoString m_sExecutableName;
    int32_t m_nMaxLogSize;
    int32_t m_nCurrentLogSize;
    int32_t m_nCurrentLogFileNumber;
    BOOL m_bRotateLogFile;

    CExoDebugInternal();
    ~CExoDebugInternal();
    void Assert(int32_t nLineNumber, const char * sFileName, const char * sComment = nullptr);
    void CloseLogFiles();
    void FlushLogFile();
    void OpenLogFiles(const CExoString sExecutableName, int32_t nMaxLogSize);
    void Warning(int32_t nLineNumber, const char * sFileName, const char *sComment, const char * sCond, const char * sAction);
    void WriteToLogFile(const CExoString & sLogString);
    void GetCurrentTimestamp(CExoString & sTimestamp);
    BOOL CreateDirectory(const CExoString sDirectory);


#ifdef NWN_CLASS_EXTENSION_CExoDebugInternal
    NWN_CLASS_EXTENSION_CExoDebugInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoDebugInternal)
#endif

