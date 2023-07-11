#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogSpeaker)
#endif



typedef uint32_t OBJECT_ID;


class CNWSDialogSpeaker
{
    CExoString m_sSpeaker;
    OBJECT_ID m_id;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogSpeaker
    NWN_CLASS_EXTENSION_CNWSDialogSpeaker
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogSpeaker)
#endif

