#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedExoLocString_st.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoLocStringInternal
{
    CExoLinkedListTemplatedExoLocString_st m_lstString;
    uint32_t m_nStringCount;

    // The below are auto generated stubs.
    CExoLocStringInternal(const CExoLocStringInternal&) = default;
    CExoLocStringInternal& operator=(const CExoLocStringInternal&) = default;

    CExoLocStringInternal();
    ~CExoLocStringInternal();
    int32_t AddString(int32_t, CExoString);
    int32_t Assign(CExoLocStringInternal*);
    void ClearLocString();
    int32_t Compare(CExoLocString&);
    int32_t GetString(int32_t, CExoString*);
    int32_t GetString(uint32_t, int32_t*, CExoString*);
    uint32_t GetStringCount();
    int32_t GetStringLength(uint32_t);
    void RemoveString(int32_t);
};

void CExoLocStringInternal__CExoLocStringInternalCtor(CExoLocStringInternal* thisPtr);
void CExoLocStringInternal__CExoLocStringInternalDtor(CExoLocStringInternal* thisPtr);
int32_t CExoLocStringInternal__AddString(CExoLocStringInternal* thisPtr, int32_t, CExoString);
int32_t CExoLocStringInternal__Assign(CExoLocStringInternal* thisPtr, CExoLocStringInternal*);
void CExoLocStringInternal__ClearLocString(CExoLocStringInternal* thisPtr);
int32_t CExoLocStringInternal__Compare(CExoLocStringInternal* thisPtr, CExoLocString&);
int32_t CExoLocStringInternal__GetString__0(CExoLocStringInternal* thisPtr, int32_t, CExoString*);
int32_t CExoLocStringInternal__GetString__1(CExoLocStringInternal* thisPtr, uint32_t, int32_t*, CExoString*);
uint32_t CExoLocStringInternal__GetStringCount(CExoLocStringInternal* thisPtr);
int32_t CExoLocStringInternal__GetStringLength(CExoLocStringInternal* thisPtr, uint32_t);
void CExoLocStringInternal__RemoveString(CExoLocStringInternal* thisPtr, int32_t);

}

}
