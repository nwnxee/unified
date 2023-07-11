#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSCreRestorePolymorphData)
#endif

class CGameEffect;
class CNWSItem;


typedef int BOOL;


class CNWSCreRestorePolymorphData
{
    int32_t nCurrentHitPoints;
    int32_t nTemporaryHitPoints;
    CGameEffect * effect;
    CNWSItem * pItemCreatureHide;
    CNWSItem * pItemCreatureWeapon;
    BOOL bTemporaryEffect;
    uint32_t nExpiryDate;
    uint32_t nExpiryTime;



#ifdef NWN_CLASS_EXTENSION_CNWSCreRestorePolymorphData
    NWN_CLASS_EXTENSION_CNWSCreRestorePolymorphData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSCreRestorePolymorphData)
#endif

