#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSClient)
#endif

struct CNWSPlayer;




struct CNWSClient
{
    uint32_t m_nPlayerID;
    int32_t m_nLanguage;

    CNWSClient(uint32_t nPlayerID);
    virtual ~CNWSClient();
    virtual CNWSPlayer * AsNWSDungeonMaster();
    virtual CNWSPlayer * AsNWSPlayer();


#ifdef NWN_CLASS_EXTENSION_CNWSClient
    NWN_CLASS_EXTENSION_CNWSClient
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSClient)
#endif

