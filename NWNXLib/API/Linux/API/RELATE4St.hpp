#pragma once

#include <cstdint>

#include "F4FLAG.hpp"
#include "LIST4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct DATA4St;
struct RELATION4St;
struct TAG4St;
struct e4exprSt;

struct RELATE4St
{
    l4linkSt link;
    int16_t relationType;
    int32_t sortType;
    int16_t errorAction;
    int16_t matchLen;
    uint16_t id;
    char* scanValue;
    RELATE4St* master;
    RELATION4St* relation;
    CODE4St* codeBase;
    e4exprSt* masterExpr;
    TAG4St* dataTag;
    DATA4St* data;
    LIST4 slaves;
    LIST4 relateList;
    int32_t scanValueLen;
    int32_t scanValueAllocLen;
    int32_t isRead;
    F4FLAG set;
    char* oldRecord;
};

}

}
