#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDialogLinkEntry)
#endif





struct CNWSDialogLinkEntry
{
    CResRef m_sActive;
    uint32_t m_nIndex;



#ifdef NWN_CLASS_EXTENSION_CNWSDialogLinkEntry
    NWN_CLASS_EXTENSION_CNWSDialogLinkEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDialogLinkEntry)
#endif

