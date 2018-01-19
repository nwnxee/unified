#pragma once

#include <cstdint>

#include "CNWSClient.hpp"

namespace NWNXLib {

namespace API {

struct CNWSSysAdmin
    : CNWSClient
{

    // The below are auto generated stubs.
    CNWSSysAdmin() = default;
    CNWSSysAdmin(const CNWSSysAdmin&) = default;
    CNWSSysAdmin& operator=(const CNWSSysAdmin&) = default;

    CNWSSysAdmin(uint32_t);
    ~CNWSSysAdmin();
    CNWSSysAdmin* AsNWSSysAdmin();
};

void CNWSSysAdmin__CNWSSysAdminCtor__0(CNWSSysAdmin* thisPtr, uint32_t);
void CNWSSysAdmin__CNWSSysAdminDtor__0(CNWSSysAdmin* thisPtr);
CNWSSysAdmin* CNWSSysAdmin__AsNWSSysAdmin(CNWSSysAdmin* thisPtr);

}

}
