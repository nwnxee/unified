#include "SpellChecker.hpp"

#include "API/CAppManager.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include <hunspell/hunspell.hxx>
#include <iostream>

#include <dlfcn.h>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static SpellChecker::SpellChecker* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new SpellChecker::SpellChecker(services);
    return g_plugin;
}


namespace SpellChecker {

SpellChecker::SpellChecker(Services::ProxyServiceList* services)
    : Plugin(services)
{

#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(FindMisspell);
    REGISTER(GetSuggestSpell);
    SpellChecker::Init();
#undef REGISTER

}

SpellChecker::~SpellChecker()
{
    SpellChecker::dest_e(SpellChecker::created);
    dlclose(SpellChecker::handle);
}

uintptr_t SpellChecker::EstbSymFunction(const std::string& symbol)
{
    uintptr_t var = reinterpret_cast<uintptr_t>(dlsym(SpellChecker::handle, symbol.c_str()));

    if (!var)
    {
        throw std::runtime_error("Dynamic link symbol error");
    }
    return var;
}
void SpellChecker::Init()
{
    SpellChecker::handle = dlopen("libhunspell.so", RTLD_NOW | RTLD_NODELETE);

    if(!SpellChecker::handle)
    {
        throw std::runtime_error("Dynamic link handler error");
    }

    SpellChecker::setcreate = reinterpret_cast<SpellChecker::Create_Exp>(EstbSymFunction("Hunspell_create"));
    SpellChecker::spell_e = reinterpret_cast<SpellChecker::Spell_Exp>(EstbSymFunction("Hunspell_spell"));

    SpellChecker::suggest_e = reinterpret_cast<SpellChecker::Suggest_Exp>(EstbSymFunction("Hunspell_suggest"));

    SpellChecker::dest_e = reinterpret_cast<SpellChecker::Des_Exp>(EstbSymFunction("Hunspell_destroy"));


    SpellChecker::free_e = reinterpret_cast<SpellChecker::Free_Exp>(EstbSymFunction( "Hunspell_free_list"));

    SpellChecker::dic = Config::Get<std::string>("PATH_DIC", "/usr/share/hunspell/en_US.dic");
    SpellChecker::aff = Config::Get<std::string>("PATH_AFF", "/usr/share/hunspell/en_US.aff");

    SpellChecker::created = setcreate(SpellChecker::aff.c_str(), SpellChecker::dic.c_str());

}
ArgumentStack SpellChecker::FindMisspell(ArgumentStack&& args)
{
    std::string sentence = Events::ExtractArgument<std::string>(args);

    std::string  word;
    std::vector <std::string> list;
    for(char& c : sentence) {
        if(isalpha(c) ||  c == '.' || c == '-' || c == '\'')
            word += c;
        else if(c == ' ' && !word.empty()) {
            list.push_back(word);
            word = "";
        }
    }
    if(!word.empty())
        list.push_back(word);
    std::string output = "";
    int sc;

    for(uint i=0; i<list.size(); i++)
    {
        sc = SpellChecker::spell_e(SpellChecker::created, list[i].c_str());
        if(sc == 0)
            output += list[i] + ",";
    }

    return Events::Arguments(output);
}

ArgumentStack SpellChecker::GetSuggestSpell(ArgumentStack&& args)
{
    std::string word = Events::ExtractArgument<std::string>(args);

    const char* cword;
    int sc;
    std::string output = "";
    if(!word.empty())
    {
        cword = word.c_str();
        sc = SpellChecker::spell_e(SpellChecker::created, cword);
        if(sc == 0)
        {
            char** wlst;
            int ns = SpellChecker::suggest_e(SpellChecker::created, &wlst, cword);
            for (int i = 0; i < ns; i++) {
                output += (std::string)wlst[i]  + ",";
            }

            SpellChecker::free_e(SpellChecker::created, &wlst, ns);
        }
    }
    return Events::Arguments(output);
}


}
