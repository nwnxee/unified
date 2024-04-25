#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include <unordered_map>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkTable)
#endif

struct CTlkFile;
struct CTlkTableToken;
struct CTlkTableTokenCustom;
struct STR_RES;


typedef int BOOL;
typedef uint32_t STRREF;


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
    CExoString m_sTlkFilePath;
    CExoString m_sTlkFileAlternatePath;
    std::unordered_map<STRREF, CExoString> m_overrides;

    CTlkTable();
    virtual ~CTlkTable();
    BOOL OpenFile(CExoString sFilename);
    BOOL OpenFileAlternate(const CExoString & sFileName);
    void CloseFileAlternate();
    void SetCustomToken(int32_t nCustomTokenNumber, const CExoString & sValue);
    void ClearCustomTokens();
    void ClearOverrides();
    void SetOverride(STRREF strId, const CExoString & ovr);
    char * RemapFontName(const char * pFontName);
    void ParseStr(CExoString & sText);
    CExoString GetSimpleString(STRREF strId);
    uint32_t GetLanguageVersion();
    BOOL SetUseLargeDialogFont(BOOL bUseIt);
    BOOL Reload();
    virtual void GetTokenValue(const CTlkTableToken & cTlkTableToken, CExoString & sToken);
    BOOL FetchInternal(uint32_t strId, STR_RES & strRes, BOOL bParse);
    void CloseFile(CTlkFile * pTlkFile[2]);
    BOOL OpenFile(const CExoString & sFileName, CTlkFile * pTlkFile[2]);


#ifdef NWN_CLASS_EXTENSION_CTlkTable
    NWN_CLASS_EXTENSION_CTlkTable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTlkTable)
#endif

