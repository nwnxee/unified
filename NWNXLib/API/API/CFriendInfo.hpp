#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CFriendInfo)
#endif





struct CFriendInfo
{
    CExoString name;
    unsigned int address;
    unsigned short port;
    uint64_t lobby;

    void Sanitize();


#ifdef NWN_CLASS_EXTENSION_CFriendInfo
    NWN_CLASS_EXTENSION_CFriendInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CFriendInfo)
#endif

