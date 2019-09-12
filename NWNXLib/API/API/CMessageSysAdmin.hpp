#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CMessageSysAdmin)
#endif

struct CMessageSysAdminInternal;


typedef class CExoString CExoStringS;
typedef int BOOL;


struct CMessageSysAdmin
{
    CMessageSysAdminInternal * m_pcMessageSysAdminInternal;

    CMessageSysAdmin();
    ~CMessageSysAdmin();
    BOOL HandleServerToClientMessage(uint8_t * pMessage, uint32_t nSize);
    BOOL SendClientToServerMessage(CExoString sCommand);
    BOOL SendServerToClientMessage(uint32_t nPlayerId, CExoStringS sCommand);
    BOOL HandleClientToServerMessage(uint32_t nPlayerId, uint8_t * pMessage, uint32_t nSize);


#ifdef NWN_CLASS_EXTENSION_CMessageSysAdmin
    NWN_CLASS_EXTENSION_CMessageSysAdmin
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CMessageSysAdmin)
#endif

