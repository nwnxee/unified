#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResHelperTemplatedCResLTR2036u.hpp"

namespace NWNXLib {

namespace API {

struct CNWNameGen
    : CResHelperTemplatedCResLTR2036u
{
    int32_t m_bLoaded;
    uint16_t m_nTableRace;
    uint8_t m_nTableNameType;

    // The below are auto generated stubs.
    CNWNameGen(const CNWNameGen&) = default;
    CNWNameGen& operator=(const CNWNameGen&) = default;

    CNWNameGen();
    ~CNWNameGen();
    CExoString GetRandomName();
    CExoString GetRandomName(uint16_t, unsigned char);
    int32_t LoadNameTable(CExoString);
    void UnloadNameTable();
};

void CNWNameGen__CNWNameGenCtor__0(CNWNameGen* thisPtr);
void CNWNameGen__CNWNameGenDtor__0(CNWNameGen* thisPtr);
CExoString CNWNameGen__GetRandomName__0(CNWNameGen* thisPtr);
CExoString CNWNameGen__GetRandomName__1(CNWNameGen* thisPtr, uint16_t, unsigned char);
int32_t CNWNameGen__LoadNameTable(CNWNameGen* thisPtr, CExoString);
void CNWNameGen__UnloadNameTable(CNWNameGen* thisPtr);

}

}
