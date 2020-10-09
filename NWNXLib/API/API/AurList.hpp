#pragma once
#include "nwn_api.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(AurList)
#endif





template <class Type> struct AurList
{
    Type * element;
    int32_t num;
    int32_t array_size;

    AurList(int s = 0);
    AurList(AurList<Type> & list);
    ~AurList();
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
    AurList<Type> & operator=(AurList<Type> & list);


#ifdef NWN_CLASS_EXTENSION_AurList
    NWN_CLASS_EXTENSION_AurList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(AurList)
#endif

