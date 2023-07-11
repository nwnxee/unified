#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogPlayer)
#endif



typedef uint32_t OBJECT_ID;


class CNWSDialogPlayer
{
    uint32_t m_playerId;
    OBJECT_ID m_oidObject;
    uint8_t m_gender;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogPlayer
    NWN_CLASS_EXTENSION_CNWSDialogPlayer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogPlayer)
#endif

