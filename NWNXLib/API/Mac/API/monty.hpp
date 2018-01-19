#pragma once

#include <cstdint>

#include "MS_RSAVLong.hpp"

namespace NWNXLib {

namespace API {

struct monty
{
    MS_RSAVLong R;
    MS_RSAVLong R1;
    MS_RSAVLong m;
    MS_RSAVLong n1;
    MS_RSAVLong T;
    MS_RSAVLong k;
    uint32_t N;

    // The below are auto generated stubs.
    monty() = default;
    monty(const monty&) = default;
    monty& operator=(const monty&) = default;

    ~monty();
};

void monty__montyDtor(monty* thisPtr);

}

}
