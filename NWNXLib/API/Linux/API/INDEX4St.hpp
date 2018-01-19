#pragma once

#include <cstdint>

#include "FILE4St.hpp"
#include "LIST4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4St;
struct INDEX4FILESt;

struct INDEX4St
{
    l4linkSt link;
    LIST4 tags;
    DATA4St* data;
    CODE4St* codeBase;
    int32_t isValid;
    INDEX4FILESt* indexFile;
    char accessName[251];
    FILE4St space1;
    char* space2;
    int32_t space3;
};

}

}
