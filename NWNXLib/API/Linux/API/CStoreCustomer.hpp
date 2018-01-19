#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CStoreCustomer
{
    uint32_t m_oidObject;
    uint8_t m_nPage;
    uint8_t m_nPanel;
    Vector m_vOpenPosition;
    char m_nBonusMarkUp;
    char m_nBonusMarkDown;

    // The below are auto generated stubs.
    CStoreCustomer(const CStoreCustomer&) = default;
    CStoreCustomer& operator=(const CStoreCustomer&) = default;

    CStoreCustomer();
};

void CStoreCustomer__CStoreCustomerCtor(CStoreCustomer* thisPtr);

}

}
