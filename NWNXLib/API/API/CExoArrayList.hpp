#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoArrayList)
#endif



typedef int BOOL;


template <class T> struct CExoArrayList
{
    T * element;
    int32_t num;
    int32_t array_size;

    CExoArrayList(int32_t s = 0);
    CExoArrayList(const CExoArrayList<T> & list);
    ~CExoArrayList();
    CExoArrayList<T> & operator=(const CExoArrayList<T> & list);
    T & operator[](int32_t i);
    void Allocate(int32_t s);
    void SetSize(int32_t s);
    void Pack();
    void Add(T t);
    BOOL AddUnique(T t);
    int32_t Contains(T t);
    BOOL DerefContains(T t);
    void Insert(T t, int32_t k);
    int32_t IndexOf(T t);
    void Remove(T t);
    void DelIndex(int32_t i);


#ifdef NWN_CLASS_EXTENSION_CExoArrayList
    NWN_CLASS_EXTENSION_CExoArrayList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoArrayList)
#endif

