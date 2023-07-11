#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPersonalReputation)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSPersonalReputation
{
    uint32_t m_nDay;
    uint32_t m_nTime;
    BOOL m_bValueDecays;
    int32_t m_nDurationInSeconds;
    OBJECT_ID m_oidCreature;
    int32_t m_nAmount;



#ifdef NWN_CLASS_EXTENSION_CNWSPersonalReputation
    NWN_CLASS_EXTENSION_CNWSPersonalReputation
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPersonalReputation)
#endif

