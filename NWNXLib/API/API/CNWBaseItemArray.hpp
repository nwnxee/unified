#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWBaseItemArray)
#endif

struct CNWBaseItem;




struct CNWBaseItemArray
{
    int32_t m_nNumBaseItems;
    CNWBaseItem * m_pBaseItems;

    CNWBaseItemArray();
    ~CNWBaseItemArray();
    CNWBaseItem * GetBaseItem(int32_t nBaseItemID);
    void Load();


#ifdef NWN_CLASS_EXTENSION_CNWBaseItemArray
    NWN_CLASS_EXTENSION_CNWBaseItemArray
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWBaseItemArray)
#endif

