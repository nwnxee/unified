#pragma once
#include "nwn_api.hpp"

#include "CNWSClient.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSSysAdmin)
#endif





class CNWSSysAdmin : CNWSClient
{

    CNWSSysAdmin(uint32_t nPlayerID);
    ~CNWSSysAdmin();
    virtual CNWSSysAdmin * AsNWSSysAdmin();


#ifdef NWN_CLASS_EXTENSION_CNWSSysAdmin
    NWN_CLASS_EXTENSION_CNWSSysAdmin
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSSysAdmin)
#endif

