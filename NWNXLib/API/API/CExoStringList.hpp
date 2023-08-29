#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoStringList)
#endif

class CExoString;




class CExoStringList
{
public:
    CExoString * * m_pStrings;
    int32_t m_nCount;
    int32_t m_nDuplicates;
    int32_t m_nSorted;
    int32_t m_nSize;

    CExoStringList();
    CExoStringList(int32_t a_nSorted, int32_t a_nDuplicates, int32_t a_nSize);
    CExoStringList(CExoStringList * a_nList);
    ~CExoStringList();
    void Add(CExoString * a_nString);
    void Clear();
    void Delete(CExoString * a_nString);
    int32_t GetCount();
    int32_t GetDuplicate();
    int32_t GetSize();
    int32_t GetSorted();
    CExoString * GetString(int32_t a_nPosition);
    void Insert(CExoString * a_nString, int32_t a_nPosition);
    CExoStringList * Merge(CExoStringList * a_nSecond, int32_t a_nSorted, int32_t a_nDuplicates);
    void Remove(int32_t a_nPosition);
    CExoString * operator[](int32_t a_nPosition);
    CExoStringList & operator=(CExoStringList & a_slList);
    void AddSorted(CExoString * a_nString);
    void Introduce(CExoString * a_nString, int32_t a_nPosition);


#ifdef NWN_CLASS_EXTENSION_CExoStringList
    NWN_CLASS_EXTENSION_CExoStringList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoStringList)
#endif

