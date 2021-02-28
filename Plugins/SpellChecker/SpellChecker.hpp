#pragma once

#include "nwnx.hpp"
#include <iostream>


using ArgumentStack = NWNXLib::Events::ArgumentStack;
using HandleType = void*;

namespace SpellChecker {

class SpellChecker : public NWNXLib::Plugin
{
    typedef struct SplHandle SplHandle;
    typedef SplHandle* (*Create_Exp)(const char*, const char*);
    typedef int (*Spell_Exp)(SplHandle* e, const char*);
    typedef int (*Suggest_Exp)(SplHandle* e, char***, const char*);
    typedef void (*Des_Exp)(SplHandle* e);
    typedef void (*Free_Exp)(SplHandle* e, char***, int);

public:
    SpellChecker(NWNXLib::Services::ProxyServiceList* services);
    virtual ~SpellChecker();


private:
    ArgumentStack FindMisspell                      (ArgumentStack&& args);
    ArgumentStack GetSuggestSpell                   (ArgumentStack&& args);
    std::string dic;
    std::string aff;
    void Init();
    uintptr_t EstbSymFunction(const std::string& symbol);
    Create_Exp setcreate;
    SplHandle* created;
    Spell_Exp spell_e;
    Suggest_Exp suggest_e;
    Des_Exp dest_e;
    Free_Exp free_e;
    HandleType handle;
};

}
