
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

#include "Spell.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include <sstream>
#include <dlfcn.h>
#include <hunspell/hunspell.hxx>
#include <iostream>
#include "Services/Config/Config.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Spell::Spell> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Spell",
        "Function to check spelling",
        "Morderon (With use of Hunspell)",
        "will386@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Spell::Spell(params);
    return g_plugin;
}

using namespace NWNXLib::Services;
namespace Spell {

Spell::Spell(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Spell::func, this, std::placeholders::_1))

    REGISTER(GetSpell);
    REGISTER(GetSuggest);

#undef REGISTER
}

Spell::~Spell()
{
}
void Spell::Init(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config)
{
    Spell::handle = dlopen("libhunspell.so", RTLD_LAZY);
    
    if(!handle)
    {
        throw std::runtime_error("Dynamic link handler error");
    }
    
    Spell::setcreate = reinterpret_cast<Spell::Create_Exp>(dlsym(handle, "Hunspell_create"));
    
    if (!setcreate) 
    { 
        throw std::runtime_error("Dynamic link symbol error");
    }
    
    Spell::spell_e = reinterpret_cast<Spell::Spell_Exp>(dlsym(handle, "Hunspell_spell"));
    if (!spell_e) 
    { 
        throw std::runtime_error("Dynamic link symbol error");
    }

    Spell::suggest_e = reinterpret_cast<Spell::Suggest_Exp>(dlsym(handle, "Hunspell_suggest"));
    if (!suggest_e) 
    { 
        throw std::runtime_error("Dynamic link symbol error");
    }
    Spell::dest_e = reinterpret_cast<Spell::Des_Exp>(dlsym(handle, "Hunspell_destroy"));
    if (!dest_e) 
    { 
        throw std::runtime_error("Dynamic link symbol error");
    }
    
    Spell::free_e = reinterpret_cast<Spell::Free_Exp>(dlsym(handle, "Hunspell_free_list"));
    if (!free_e) 
    { 
        throw std::runtime_error("Dynamic link symbol error");
    }
    Spell::dic = config->Get<std::string>("PATH_DIC", "/usr/share/hunspell/en_US.dic");
    Spell::aff = config->Get<std::string>("PATH_AFF", "/usr/share/hunspell/en_US.aff");
    
    Spell::created = setcreate(Spell::aff.c_str(), Spell::dic.c_str());
}
ArgumentStack Spell::GetSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    Spell::Init(GetServices()->m_config);


    std::string sentence = Services::Events::ExtractArgument<std::string>(args);
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ','), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ':'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ';'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '"'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '('), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ')'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ')'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '*'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '['), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), ']'), sentence.end());
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());
    std::istringstream iss(sentence);
    std::string  word;
    std::string output = "";
    int sc;
    while (getline( iss, word, ' ' ))
    {
        if(!word.empty())
        {
            sc = Spell::spell_e(Spell::created, word.c_str());
            if(sc == 0)
              output += word + ",";         
        }

        
    }
  
    Spell::dest_e(Spell::created);
    dlclose(Spell::handle);
    Services::Events::InsertArgument(stack, output);    
    return stack;
}

ArgumentStack Spell::GetSuggest(ArgumentStack&& args)
{
    ArgumentStack stack;
    
   
  
    Spell::Init(GetServices()->m_config);
 
    std::string word = Services::Events::ExtractArgument<std::string>(args);

    const char* cword;
    int sc;
    std::string output = "";
    if(!word.empty())
    {
        cword = word.c_str();
        sc = Spell::spell_e(Spell::created, cword);
        if(sc == 0)
        {
            char** wlst;
           int ns = Spell::suggest_e(Spell::created, &wlst, cword);
            for (int i = 0; i < ns; i++) {
                output += (std::string)wlst[i]  + ",";
            }
            
            output += "\n";
            Spell::free_e(Spell::created, &wlst, ns);
        }
    
    }
  
    Spell::dest_e(Spell::created);
    dlclose(Spell::handle);
    Services::Events::InsertArgument(stack, output);    
    return stack;
}


}
