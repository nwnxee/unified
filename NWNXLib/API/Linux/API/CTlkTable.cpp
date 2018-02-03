#include "CTlkTable.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CTlkFile.hpp"
#include "CTlkTableToken.hpp"
#include "CTlkTableTokenCustom.hpp"
#include "STR_RES.hpp"

namespace NWNXLib {

namespace API {

CTlkTable::CTlkTable()
{
    CTlkTable__CTlkTableCtor(this);
}

CTlkTable::~CTlkTable()
{
    CTlkTable__CTlkTableDtor__0(this);
}

void CTlkTable::ClearCustomTokens()
{
    return CTlkTable__ClearCustomTokens(this);
}

void CTlkTable::CloseFile(CTlkFile** a0)
{
    return CTlkTable__CloseFile(this, a0);
}

void CTlkTable::CloseFileAlternate()
{
    return CTlkTable__CloseFileAlternate(this);
}

int32_t CTlkTable::ExoIsDBCSLeadByte(unsigned char a0)
{
    return CTlkTable__ExoIsDBCSLeadByte(a0);
}

int32_t CTlkTable::FetchInternal(uint32_t a0, STR_RES& a1, int32_t a2)
{
    return CTlkTable__FetchInternal(this, a0, a1, a2);
}

uint32_t CTlkTable::GetLanguageVersion()
{
    return CTlkTable__GetLanguageVersion(this);
}

CExoString CTlkTable::GetSimpleString(uint32_t a0)
{
    return CTlkTable__GetSimpleString(this, a0);
}

void CTlkTable::GetTokenValue(const CTlkTableToken& a0, CExoString& a1)
{
    return CTlkTable__GetTokenValue(this, a0, a1);
}

int32_t CTlkTable::OpenFile(CExoString a0)
{
    return CTlkTable__OpenFile__0(this, a0);
}

int32_t CTlkTable::OpenFile(const CExoString& a0, CTlkFile** a1)
{
    return CTlkTable__OpenFile__1(this, a0, a1);
}

int32_t CTlkTable::OpenFileAlternate(const CExoString& a0)
{
    return CTlkTable__OpenFileAlternate(this, a0);
}

void CTlkTable::ParseStr(CExoString& a0)
{
    return CTlkTable__ParseStr(this, a0);
}

char* CTlkTable::RemapFontName(char* a0)
{
    return CTlkTable__RemapFontName(this, a0);
}

void CTlkTable::SetCustomToken(int32_t a0, const CExoString& a1)
{
    return CTlkTable__SetCustomToken(this, a0, a1);
}

int32_t CTlkTable::SetUseLargeDialogFont(int32_t a0)
{
    return CTlkTable__SetUseLargeDialogFont(this, a0);
}

void CTlkTable__CTlkTableCtor(CTlkTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__CTlkTableCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CTlkTable__CTlkTableDtor__0(CTlkTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__CTlkTableDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CTlkTable__ClearCustomTokens(CTlkTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__ClearCustomTokens);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CTlkTable__CloseFile(CTlkTable* thisPtr, CTlkFile** a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*, CTlkFile**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__CloseFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CTlkTable__CloseFileAlternate(CTlkTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__CloseFileAlternate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CTlkTable__ExoIsDBCSLeadByte(unsigned char a0)
{
    using FuncPtrType = int32_t(*)(unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__ExoIsDBCSLeadByte);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0);
}

int32_t CTlkTable__FetchInternal(CTlkTable* thisPtr, uint32_t a0, STR_RES& a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkTable*, uint32_t, STR_RES&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__FetchInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CTlkTable__GetLanguageVersion(CTlkTable* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CTlkTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__GetLanguageVersion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CTlkTable__GetSimpleString(CTlkTable* thisPtr, uint32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CTlkTable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__GetSimpleString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CTlkTable__GetTokenValue(CTlkTable* thisPtr, const CTlkTableToken& a0, CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*, const CTlkTableToken&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__GetTokenValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CTlkTable__OpenFile__0(CTlkTable* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkTable*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__OpenFile__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CTlkTable__OpenFile__1(CTlkTable* thisPtr, const CExoString& a0, CTlkFile** a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkTable*, const CExoString&, CTlkFile**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__OpenFile__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CTlkTable__OpenFileAlternate(CTlkTable* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkTable*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__OpenFileAlternate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CTlkTable__ParseStr(CTlkTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__ParseStr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char* CTlkTable__RemapFontName(CTlkTable* thisPtr, char* a0)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CTlkTable*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__RemapFontName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CTlkTable__SetCustomToken(CTlkTable* thisPtr, int32_t a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CTlkTable*, int32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__SetCustomToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CTlkTable__SetUseLargeDialogFont(CTlkTable* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CTlkTable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CTlkTable__SetUseLargeDialogFont);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
