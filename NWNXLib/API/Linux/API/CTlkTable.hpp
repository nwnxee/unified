#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CTlkTableToken.hpp"
#include "STR_RES.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CTlkFile;
struct CTlkTableTokenCustom;

struct CTlkTable
{
    void** m_vtable;
    CTlkFile* m_pTlkFile[2];
    CTlkFile* m_pTlkFileAlternate[2];
    uint8_t m_currentGender;
    CTlkTableToken* m_pTokens;
    uint32_t m_nTokens;
    CTlkTableTokenCustom* m_pTokensCustom;
    uint32_t m_nTokensCustom;
    int32_t m_bRemove;

    // The below are auto generated stubs.
    CTlkTable(const CTlkTable&) = default;
    CTlkTable& operator=(const CTlkTable&) = default;

    CTlkTable();
    ~CTlkTable();
    void ClearCustomTokens();
    void CloseFile(CTlkFile**);
    void CloseFileAlternate();
    static int32_t ExoIsDBCSLeadByte(unsigned char);
    int32_t FetchInternal(uint32_t, STR_RES&, int32_t);
    uint32_t GetLanguageVersion();
    CExoString GetSimpleString(uint32_t);
    void GetTokenValue(const CTlkTableToken&, CExoString&);
    int32_t OpenFile(CExoString);
    int32_t OpenFile(const CExoString&, CTlkFile**);
    int32_t OpenFileAlternate(const CExoString&);
    void ParseStr(CExoString&);
    char* RemapFontName(char*);
    void SetCustomToken(int32_t, const CExoString&);
    int32_t SetUseLargeDialogFont(int32_t);
};

void CTlkTable__CTlkTableCtor(CTlkTable* thisPtr);
void CTlkTable__CTlkTableDtor__0(CTlkTable* thisPtr);
void CTlkTable__ClearCustomTokens(CTlkTable* thisPtr);
void CTlkTable__CloseFile(CTlkTable* thisPtr, CTlkFile**);
void CTlkTable__CloseFileAlternate(CTlkTable* thisPtr);
int32_t CTlkTable__ExoIsDBCSLeadByte(unsigned char);
int32_t CTlkTable__FetchInternal(CTlkTable* thisPtr, uint32_t, STR_RES&, int32_t);
uint32_t CTlkTable__GetLanguageVersion(CTlkTable* thisPtr);
CExoString CTlkTable__GetSimpleString(CTlkTable* thisPtr, uint32_t);
void CTlkTable__GetTokenValue(CTlkTable* thisPtr, const CTlkTableToken&, CExoString&);
int32_t CTlkTable__OpenFile__0(CTlkTable* thisPtr, CExoString);
int32_t CTlkTable__OpenFile__1(CTlkTable* thisPtr, const CExoString&, CTlkFile**);
int32_t CTlkTable__OpenFileAlternate(CTlkTable* thisPtr, const CExoString&);
void CTlkTable__ParseStr(CTlkTable* thisPtr, CExoString&);
char* CTlkTable__RemapFontName(CTlkTable* thisPtr, char*);
void CTlkTable__SetCustomToken(CTlkTable* thisPtr, int32_t, const CExoString&);
int32_t CTlkTable__SetUseLargeDialogFont(CTlkTable* thisPtr, int32_t);

}

}
