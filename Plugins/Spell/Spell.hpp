#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include <iostream>



using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;


namespace Spell {

class Spell : public NWNXLib::Plugin
{
    typedef struct SplHandle SplHandle;
    typedef SplHandle* (*Create_Exp)(const char*, const char*);
    typedef int (*Spell_Exp)(SplHandle* e, const char*);
    typedef int (*Suggest_Exp)(SplHandle* e, char***, const char*);
    typedef void (*Des_Exp)(SplHandle* e);
    typedef void (*Free_Exp)(SplHandle* e, char***, int);
    
public:
    Spell(const Plugin::CreateParams& params);
    virtual ~Spell();
    
    
private:
    ArgumentStack GetSpell                          (ArgumentStack&& args);
    ArgumentStack GetSuggest                        (ArgumentStack&& args);
    std::string dic;
    std::string aff;
    void Init(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config);
    Create_Exp setcreate;
    SplHandle* created;
    Spell_Exp spell_e;
    Suggest_Exp suggest_e;
    Des_Exp dest_e;
    Free_Exp free_e;
    void* handle;
};

}
