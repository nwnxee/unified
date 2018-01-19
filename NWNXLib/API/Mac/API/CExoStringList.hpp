#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CExoStringList
{
    CExoString** m_pStrings;
    int32_t m_nCount;
    int32_t m_nDuplicates;
    int32_t m_nSorted;
    int32_t m_nSize;

    CExoStringList();
    CExoStringList(CExoStringList*);
    CExoStringList(int32_t, int32_t, int32_t);
    ~CExoStringList();
    void Add(CExoString*);
    void AddSorted(CExoString*);
    void Clear();
    void Delete(CExoString*);
    int32_t GetCount();
    int32_t GetDuplicate();
    int32_t GetSize();
    int32_t GetSorted();
    CExoString* GetString(int32_t);
    void Insert(CExoString*, int32_t);
    void Introduce(CExoString*, int32_t);
    CExoStringList* Merge(CExoStringList*, int32_t, int32_t);
    CExoString* operator*(int32_t);
    CExoStringList& operator=(CExoStringList&);
    void Remove(int32_t);
};

void CExoStringList__CExoStringListCtor__0(CExoStringList* thisPtr);
void CExoStringList__CExoStringListCtor__2(CExoStringList* thisPtr, CExoStringList*);
void CExoStringList__CExoStringListCtor__4(CExoStringList* thisPtr, int32_t, int32_t, int32_t);
void CExoStringList__CExoStringListDtor__0(CExoStringList* thisPtr);
void CExoStringList__Add(CExoStringList* thisPtr, CExoString*);
void CExoStringList__AddSorted(CExoStringList* thisPtr, CExoString*);
void CExoStringList__Clear(CExoStringList* thisPtr);
void CExoStringList__Delete(CExoStringList* thisPtr, CExoString*);
int32_t CExoStringList__GetCount(CExoStringList* thisPtr);
int32_t CExoStringList__GetDuplicate(CExoStringList* thisPtr);
int32_t CExoStringList__GetSize(CExoStringList* thisPtr);
int32_t CExoStringList__GetSorted(CExoStringList* thisPtr);
CExoString* CExoStringList__GetString(CExoStringList* thisPtr, int32_t);
void CExoStringList__Insert(CExoStringList* thisPtr, CExoString*, int32_t);
void CExoStringList__Introduce(CExoStringList* thisPtr, CExoString*, int32_t);
CExoStringList* CExoStringList__Merge(CExoStringList* thisPtr, CExoStringList*, int32_t, int32_t);
CExoString* CExoStringList__OperatorMultiplication(CExoStringList* thisPtr, int32_t);
CExoStringList& CExoStringList__OperatorAssignment(CExoStringList* thisPtr, CExoStringList&);
void CExoStringList__Remove(CExoStringList* thisPtr, int32_t);

}

}
