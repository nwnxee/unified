#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResHelperTemplatedCRes2DA2017u.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct C2DA
    : CResHelperTemplatedCRes2DA2017u
{
    CExoString m_sDefaultValue;
    CExoString* m_pRowLabel;
    CExoString* m_pColumnLabel;
    CExoString** m_pArrayData;
    int32_t m_nNumRows;
    int32_t m_nNumColumns;
    int32_t m_bLoaded;

    // The below are auto generated stubs.
    C2DA(const C2DA&) = default;
    C2DA& operator=(const C2DA&) = default;

    C2DA();
    C2DA(CResRef, int32_t);
    ~C2DA();
    int32_t GetCExoStringEntry(const CExoString&, const CExoString&, CExoString*);
    int32_t GetCExoStringEntry(int32_t, const CExoString&, CExoString*);
    int32_t GetCExoStringEntry(int32_t, int32_t, CExoString*);
    int32_t GetCExoStringEntry(const CExoString&, int32_t, CExoString*);
    int32_t GetColumnIndex(const CExoString&);
    int32_t GetFLOATEntry(const CExoString&, int32_t, float*);
    int32_t GetFLOATEntry(int32_t, const CExoString&, float*);
    int32_t GetFLOATEntry(int32_t, int32_t, float*);
    int32_t GetFLOATEntry(const CExoString&, const CExoString&, float*);
    int32_t GetINTEntry(const CExoString&, const CExoString&, int32_t*);
    int32_t GetINTEntry(int32_t, int32_t, int32_t*);
    int32_t GetINTEntry(int32_t, const CExoString&, int32_t*);
    int32_t GetINTEntry(const CExoString&, int32_t, int32_t*);
    uint32_t GetNextLineLength(char*, uint32_t);
    int32_t GetNextToken(char**, uint32_t*, char*, uint32_t, uint32_t*);
    int32_t GetRowIndex(const CExoString&);
    int32_t Load2DArray();
    int32_t SetBlankEntry(int32_t, int32_t);
    int32_t SetBlankEntry(CExoString, CExoString);
    int32_t SetBlankEntry(CExoString, int32_t);
    int32_t SetBlankEntry(int32_t, CExoString);
    int32_t SetCExoStringEntry(CExoString, CExoString, CExoString);
    int32_t SetCExoStringEntry(int32_t, CExoString, CExoString);
    int32_t SetCExoStringEntry(int32_t, int32_t, CExoString);
    int32_t SetCExoStringEntry(CExoString, int32_t, CExoString);
    int32_t SetFLOATEntry(CExoString, int32_t, float);
    int32_t SetFLOATEntry(int32_t, CExoString, float);
    int32_t SetFLOATEntry(int32_t, int32_t, float);
    int32_t SetFLOATEntry(CExoString, CExoString, float);
    int32_t SetINTEntry(CExoString, CExoString, int32_t);
    int32_t SetINTEntry(int32_t, int32_t, int32_t);
    int32_t SetINTEntry(int32_t, CExoString, int32_t);
    int32_t SetINTEntry(CExoString, int32_t, int32_t);
    int32_t SkipNewLines(char**, uint32_t*);
    void Unload2DArray();
};

void C2DA__C2DACtor__0(C2DA* thisPtr);
void C2DA__C2DACtor__1(C2DA* thisPtr, CResRef, int32_t);
void C2DA__C2DADtor__0(C2DA* thisPtr);
int32_t C2DA__GetCExoStringEntry__0(C2DA* thisPtr, const CExoString&, const CExoString&, CExoString*);
int32_t C2DA__GetCExoStringEntry__1(C2DA* thisPtr, int32_t, const CExoString&, CExoString*);
int32_t C2DA__GetCExoStringEntry__2(C2DA* thisPtr, int32_t, int32_t, CExoString*);
int32_t C2DA__GetCExoStringEntry__3(C2DA* thisPtr, const CExoString&, int32_t, CExoString*);
int32_t C2DA__GetColumnIndex(C2DA* thisPtr, const CExoString&);
int32_t C2DA__GetFLOATEntry__0(C2DA* thisPtr, const CExoString&, int32_t, float*);
int32_t C2DA__GetFLOATEntry__1(C2DA* thisPtr, int32_t, const CExoString&, float*);
int32_t C2DA__GetFLOATEntry__2(C2DA* thisPtr, int32_t, int32_t, float*);
int32_t C2DA__GetFLOATEntry__3(C2DA* thisPtr, const CExoString&, const CExoString&, float*);
int32_t C2DA__GetINTEntry__0(C2DA* thisPtr, const CExoString&, const CExoString&, int32_t*);
int32_t C2DA__GetINTEntry__1(C2DA* thisPtr, int32_t, int32_t, int32_t*);
int32_t C2DA__GetINTEntry__2(C2DA* thisPtr, int32_t, const CExoString&, int32_t*);
int32_t C2DA__GetINTEntry__3(C2DA* thisPtr, const CExoString&, int32_t, int32_t*);
uint32_t C2DA__GetNextLineLength(C2DA* thisPtr, char*, uint32_t);
int32_t C2DA__GetNextToken(C2DA* thisPtr, char**, uint32_t*, char*, uint32_t, uint32_t*);
int32_t C2DA__GetRowIndex(C2DA* thisPtr, const CExoString&);
int32_t C2DA__Load2DArray(C2DA* thisPtr);
int32_t C2DA__SetBlankEntry__0(C2DA* thisPtr, int32_t, int32_t);
int32_t C2DA__SetBlankEntry__1(C2DA* thisPtr, CExoString, CExoString);
int32_t C2DA__SetBlankEntry__2(C2DA* thisPtr, CExoString, int32_t);
int32_t C2DA__SetBlankEntry__3(C2DA* thisPtr, int32_t, CExoString);
int32_t C2DA__SetCExoStringEntry__0(C2DA* thisPtr, CExoString, CExoString, CExoString);
int32_t C2DA__SetCExoStringEntry__1(C2DA* thisPtr, int32_t, CExoString, CExoString);
int32_t C2DA__SetCExoStringEntry__2(C2DA* thisPtr, int32_t, int32_t, CExoString);
int32_t C2DA__SetCExoStringEntry__3(C2DA* thisPtr, CExoString, int32_t, CExoString);
int32_t C2DA__SetFLOATEntry__0(C2DA* thisPtr, CExoString, int32_t, float);
int32_t C2DA__SetFLOATEntry__1(C2DA* thisPtr, int32_t, CExoString, float);
int32_t C2DA__SetFLOATEntry__2(C2DA* thisPtr, int32_t, int32_t, float);
int32_t C2DA__SetFLOATEntry__3(C2DA* thisPtr, CExoString, CExoString, float);
int32_t C2DA__SetINTEntry__0(C2DA* thisPtr, CExoString, CExoString, int32_t);
int32_t C2DA__SetINTEntry__1(C2DA* thisPtr, int32_t, int32_t, int32_t);
int32_t C2DA__SetINTEntry__2(C2DA* thisPtr, int32_t, CExoString, int32_t);
int32_t C2DA__SetINTEntry__3(C2DA* thisPtr, CExoString, int32_t, int32_t);
int32_t C2DA__SkipNewLines(C2DA* thisPtr, char**, uint32_t*);
void C2DA__Unload2DArray(C2DA* thisPtr);

}

}
