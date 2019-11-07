#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CMessagePlayer)
#endif

struct CMessagePlayerInternal;


typedef int BOOL;


struct CMessagePlayer
{
    CMessagePlayerInternal * m_pcMessagePlayerInternal;

    CMessagePlayer();
    ~CMessagePlayer();
    BOOL HandleServerToClientMessage(uint8_t * pBuffer, uint32_t nBufferSize);
    BOOL SendClientToServerMessage(uint8_t nMajor, uint8_t nMinor, uint8_t * pBuffer, uint32_t nBufferSize);
    BOOL SendServerToClientMessage(uint32_t nPlayerId, uint8_t nMajor, uint8_t nMinor, uint8_t * pBuffer, uint32_t nBufferSize);
    BOOL HandleClientToServerMessage(uint32_t nPlayerId, uint8_t * pBuffer, uint32_t nBufferSize);


#ifdef NWN_CLASS_EXTENSION_CMessagePlayer
    NWN_CLASS_EXTENSION_CMessagePlayer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CMessagePlayer)
#endif

