#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerLUOInventoryItem)
#endif



typedef uint32_t OBJECT_ID;


class CNWSPlayerLUOInventoryItem
{
public:
    OBJECT_ID oidObject;
    uint8_t xPos;
    uint8_t yPos;
    uint32_t nStackSize;
    uint32_t nCost;



#ifdef NWN_CLASS_EXTENSION_CNWSPlayerLUOInventoryItem
    NWN_CLASS_EXTENSION_CNWSPlayerLUOInventoryItem
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerLUOInventoryItem)
#endif

