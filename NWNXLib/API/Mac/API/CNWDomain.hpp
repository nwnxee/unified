#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWDomain
{
    int32_t m_nNameStrref;
    int32_t m_nDescriptionStrref;
    CResRef m_cIcon;
    uint32_t m_lstSpells[10];
    uint16_t m_nGrantedFeat;
    int32_t m_bValidDomain;
    int32_t m_bCastableFeat;

    // The below are auto generated stubs.
    CNWDomain(const CNWDomain&) = default;
    CNWDomain& operator=(const CNWDomain&) = default;

    CNWDomain();
    ~CNWDomain();
    CExoString GetDescriptionText();
    CExoString GetNameText();
};

void CNWDomain__CNWDomainCtor__0(CNWDomain* thisPtr);
void CNWDomain__CNWDomainDtor__0(CNWDomain* thisPtr);
CExoString CNWDomain__GetDescriptionText(CNWDomain* thisPtr);
CExoString CNWDomain__GetNameText(CNWDomain* thisPtr);

}

}
