#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSQuickbarButton)
#endif



typedef uint32_t OBJECT_ID;


class CNWSQuickbarButton
{
    OBJECT_ID m_oidItem;
    OBJECT_ID m_oidSecondaryItem;
    uint8_t m_nObjectType;
    uint8_t m_nMultiClass;
    CResRef m_cResRef;
    CExoString m_sCommandLabel;
    CExoString m_sCommandLine;
    CExoString m_sToolTip;
    int32_t m_nINTParam1;
    uint8_t m_nMetaType;
    uint8_t m_nDomainLevel;
    uint16_t m_nAssociateType;
    OBJECT_ID m_oidAssociate;



#ifdef NWN_CLASS_EXTENSION_CNWSQuickbarButton
    NWN_CLASS_EXTENSION_CNWSQuickbarButton
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSQuickbarButton)
#endif

