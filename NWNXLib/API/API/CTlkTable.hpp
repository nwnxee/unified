#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkTable)
#endif

struct CTlkFile;
struct CTlkTableTokenCustom;
struct STR_RES;
struct CTlkTableToken;


typedef uint32_t STRREF;
typedef int BOOL;


struct CTlkTable
{
    CTlkFile * m_pTlkFile[2];
    CTlkFile * m_pTlkFileAlternate[2];
    uint8_t m_currentGender;
    CTlkTableToken * m_pTokens;
    uint32_t m_nTokens;
    CTlkTableTokenCustom * m_pTokensCustom;
    uint32_t m_nTokensCustom;
    BOOL m_bRemove;

    CTlkTable();
    virtual ~CTlkTable();
    BOOL OpenFile(CExoString sFilename);
    BOOL OpenFileAlternate(const CExoString & sFileName);
    void CloseFileAlternate();
    void SetCustomToken(int32_t nCustomTokenNumber, const CExoString & sValue);
    void ClearCustomTokens();
    char * RemapFontName(char * pFontName);
    void ParseStr(CExoString & sText);
    CExoString GetSimpleString(STRREF strId);
    uint32_t GetLanguageVersion();
    BOOL SetUseLargeDialogFont(BOOL bUseIt);
    virtual void GetTokenValue(const CTlkTableToken & cTlkTableToken, CExoString & sToken);
    BOOL FetchInternal(uint32_t strId, STR_RES & strRes, BOOL bParse);
    void CloseFile(CTlkFile * pTlkFile);
    BOOL OpenFile(const CExoString & sFileName, CTlkFile * pTlkFile);


#ifdef NWN_CLASS_EXTENSION_CTlkTable
    NWN_CLASS_EXTENSION_CTlkTable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTlkTable)
#endif

