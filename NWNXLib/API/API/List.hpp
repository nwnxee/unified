#pragma once
#include "nwn_api.hpp"

#include "List.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(List)
#endif





template <class Type> struct List
{
    Type * element;
    int32_t num;
    int32_t array_size;

    List(int s = 0);
    List(List<Type> & list);
    ~List();
    void allocate(int32_t s);
    void SetSize(int32_t s);
    void Pack();
    void Add(Type );
    void AddUnique(Type );
    bool Contains(Type );
    void Insert(Type , int32_t );
    int32_t IndexOf(Type );
    void Remove(Type );
    void DelIndex(int32_t i);
    List<Type> & operator=(List<Type> & list);


#ifdef NWN_CLASS_EXTENSION_List
    NWN_CLASS_EXTENSION_List
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(List)
#endif

