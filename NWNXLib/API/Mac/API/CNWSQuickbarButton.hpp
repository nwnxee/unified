#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWSQuickbarButton
{
    uint32_t m_oidItem;
    uint32_t m_oidSecondaryItem;
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
    uint32_t m_oidAssociate;
};

}

}
