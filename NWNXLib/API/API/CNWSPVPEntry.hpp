#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPVPEntry)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSPVPEntry
{
    OBJECT_ID m_oidPC;
    BOOL m_bILikePlayer;
    BOOL m_bPlayerLikesMe;



#ifdef NWN_CLASS_EXTENSION_CNWSPVPEntry
    NWN_CLASS_EXTENSION_CNWSPVPEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPVPEntry)
#endif

