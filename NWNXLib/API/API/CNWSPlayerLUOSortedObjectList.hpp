#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerLUOSortedObjectList)
#endif



typedef uint32_t OBJECT_ID;


class CNWSPlayerLUOSortedObjectList
{
    OBJECT_ID oidObject;
    float fDistanceToPlayer;
    uint32_t nCategory;



#ifdef NWN_CLASS_EXTENSION_CNWSPlayerLUOSortedObjectList
    NWN_CLASS_EXTENSION_CNWSPlayerLUOSortedObjectList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerLUOSortedObjectList)
#endif

