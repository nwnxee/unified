#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoDebug)
#endif

struct CExoDebugInternal;


typedef int BOOL;


struct CExoDebug
{
    CExoString m_sLogString;
    CExoDebugInternal * m_pcExoDebugInternal;

    CExoDebug();
    ~CExoDebug();
    void Assert(int32_t nLineNumber, const char * sFileName, const char * sComment = nullptr);
    void CloseLogFiles();
    void FlushLogFile();
    void OpenLogFiles(CExoString sExecutableName, int32_t nMaxLogSize = 10000000);
    void Warning(int32_t nLineNumber, const char * sFileName, const char * sComment= nullptr, const char * sCond = nullptr, const char * sAction = nullptr);
    void WriteToLogFile(const CExoString & sLogString);
    void GetCurrentTimestamp(CExoString & sTimestamp);
    void SetRotateLogFile(BOOL bEnable);


#ifdef NWN_CLASS_EXTENSION_CExoDebug
    NWN_CLASS_EXTENSION_CExoDebug
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoDebug)
#endif

