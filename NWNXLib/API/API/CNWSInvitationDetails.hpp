#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSInvitationDetails)
#endif



typedef uint32_t OBJECT_ID;


class CNWSInvitationDetails
{
public:
    OBJECT_ID m_oidCreature;
    uint32_t m_nCalenderDay;
    uint32_t m_nTimeOfDay;



#ifdef NWN_CLASS_EXTENSION_CNWSInvitationDetails
    NWN_CLASS_EXTENSION_CNWSInvitationDetails
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSInvitationDetails)
#endif

