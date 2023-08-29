
#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoArrayList)
#endif



typedef int BOOL;

// NOTE: Manually implemented for now..
template <class T> class CExoArrayList
{
public:
    T * element;
    int32_t num;
    int32_t array_size;


    CExoArrayList(int32_t s = 0)
    {
        num = array_size = 0;
        element = nullptr;
        if (s) Allocate(s);
    }
    CExoArrayList(const CExoArrayList<T> &list)
    {
        num = array_size = 0;
        element = nullptr;
        for (int32_t i = 0; i < list.num; i++)
            Add(list[i]);
    }
    ~CExoArrayList()
    {
        delete[] element;
    }
    CExoArrayList<T>& operator=(const CExoArrayList<T>& list)
    {
        num = 0;
        for (int32_t i = 0; i < list.num; i++)
            Add(list[i]);
        return *this;
    }
    T& operator[](int32_t i) const
    {
        return element[i];
    }
    void Allocate(int32_t s)
    {
        T *tmp = element;
        element = new T[array_size = s];
        for (int32_t i = 0; i < num; i++)
            element[i] = tmp[i];
        delete[] tmp;
    }
    void SetSize(int32_t s)
    {
        if (s == 0)
        {
            delete[] element;
            element = nullptr;
            array_size = 0;
        }
        else { Allocate(s); }
        num = s;
    }
    void Pack()
    {
        Allocate(num);
    }
    void Add(T t)
    {
        if (num == array_size)
            Allocate(array_size ? array_size * 2 : 16);
        element[num++] = t;
    }
    BOOL AddUnique(T t)
    {
        if (!Contains(t))
        {
            Add(t);
            return true;
        }
        return false;
    }
    int32_t Contains(T t)
    {
        int32_t count = 0;
        for (int32_t i=0; i < num; i++)
            count += element[i] == t;
        return count;
    }
    BOOL DerefContains(T t)
    {
        for (int32_t i=0; i < num; i++)
            if (*(element[i]) == *t)
                return true;
        return false;
    }
    void Insert(T t, int32_t k)
    {
        Add(t);
        for (int32_t i = num; i > k; i--)
            element[i]=element[i-1];

        element[k] = t;
    }
    int32_t IndexOf(T t)
    {
        for (int32_t i = 0; i < num; i++)
            if(element[i] == t)
                return i;

        return -1;
    }
    void Remove(T t)
    {
        for (int32_t i = 0; i < num; i++)
        {
            if (element[i] == t)
            {
                DelIndex(i);
                return;
            }
        }
    }
    void DelIndex(int32_t i)
    {
        for (num--; i < num; i++)
            element[i] = element[i+1];
    }

    T* begin()        { return &element[0];   }
    const T* begin() const  { return &element[0];   }
    T* end()          { return &element[num]; }
    const T* end() const    { return &element[num]; }
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoArrayList)
#endif
