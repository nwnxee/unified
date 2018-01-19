#pragma once

#include <cstdint>

#include "CNWSpell.hpp"

namespace NWNXLib {

namespace API {

struct CNWSpellArray
{
    int32_t m_nNumSpells;
    CNWSpell* m_pSpells;

    // The below are auto generated stubs.
    CNWSpellArray(const CNWSpellArray&) = default;
    CNWSpellArray& operator=(const CNWSpellArray&) = default;

    CNWSpellArray();
    ~CNWSpellArray();
    CNWSpell* GetSpell(int32_t);
    void Load();
    CNWSpell operator*(int32_t);
};

void CNWSpellArray__CNWSpellArrayCtor__0(CNWSpellArray* thisPtr);
void CNWSpellArray__CNWSpellArrayDtor__0(CNWSpellArray* thisPtr);
CNWSpell* CNWSpellArray__GetSpell(CNWSpellArray* thisPtr, int32_t);
void CNWSpellArray__Load(CNWSpellArray* thisPtr);
CNWSpell CNWSpellArray__OperatorMultiplication(CNWSpellArray* thisPtr, int32_t);

}

}
