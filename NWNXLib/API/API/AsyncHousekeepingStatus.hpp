#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "Status.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(AsyncHousekeepingStatus)
#endif





struct AsyncHousekeepingStatus
{
    Status m_status;
    CExoString m_humanReadable;



#ifdef NWN_CLASS_EXTENSION_AsyncHousekeepingStatus
    NWN_CLASS_EXTENSION_AsyncHousekeepingStatus
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(AsyncHousekeepingStatus)
#endif

