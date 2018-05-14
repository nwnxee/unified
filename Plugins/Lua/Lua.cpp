#include "Lua.hpp"

#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"
#include <cstring>
//for objectself
#include "API/CVirtualMachine.hpp"
// for dlopen
#ifdef NWNX_LUA_LIBRARY
#include <dlfcn.h>
#endif


using namespace NWNXLib;
static ViewPtr<Lua::Lua> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Lua",
        "Allows users to call lua code with NWScript binding.",
        "dparoli",
        "d.paroli@tiscali.it",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Lua::Lua(params);
    return g_plugin;
}

namespace Lua {

    using namespace NWNXLib::Services;
    using namespace NWNXLib::API;

    Lua::Lua(const Plugin::CreateParams& params) : Plugin(params)
    {
        std::string userDir = std::string(Globals::ExoBase()->m_sUserDirectory.CStr());
        
        // This dcall assure that external object libraries required by lua can have the lualib loaded and exported,
        // It seems that by default cmake link library with RTLD_LOCAL so the symbols in the lualib are not visible by 
        // external object required/loaded in lua code.
        // With this trick the library visibility will become global without load it a second time (RTLD_NOLOAD)
        // Without this trick if you load/require an object extension you will have the error: *undefined symbol* 
        // on some lua_api functions.
        // Dont know if that is necessary for Mac
        #ifdef NWNX_LUA_LIBRARY
        dlopen(NWNX_LUA_LIBRARY, RTLD_NOW | RTLD_NOLOAD | RTLD_GLOBAL);
        #endif

        // create new Lua instance and open libs
        m_luaInstance = luaL_newstate();
        luaL_openlibs(m_luaInstance);

        // open nwnx specific functions
        LUA_InitNWScript(m_luaInstance);

        //set global USER_DIR in Lua
        lua_pushstring(m_luaInstance, userDir.c_str()); 
        lua_setglobal(m_luaInstance, "USER_DIR");

        // get configuration
        // mandatory preload script and Token Function
        std::string preloadScript = GetServices()->m_config->Get<std::string>("PRELOAD_SCRIPT", userDir+"/lua/preload.lua");
        m_tokenFunction = GetServices()->m_config->Get<std::string>("TOKEN_FUNCTION", "CallToken");
        
        // if you want to use an event framework instead of use only Eval and EvalVoid, less intensive
        m_eventFunction = GetServices()->m_config->Get<std::string>("EVENT_FUNCTION", "RunEvent");
        
        // custom Set OBJECT_SELF function accepting an integer as argument (the current value of OBJECT_SELF)
        // if this configuration is not defined a global OBJECT_SELF integer wil be keeped aligned to the current value
        // This is useful if you want to write OOP code and treat nwn objects as lua classes and not as numbers
        // The other function in wich you recive a numeric object is the RunEvent Function,
        // but RunEvent is in lua code so you can modifiy as you want
        m_setObjSelfFunction = GetServices()->m_config->Get<std::string>("OBJSELF_FUNCTION", "");
        
        // loading preload code
        // Dont call any NWN function in this script like SetLocalString(), GetModule() etc
        // the module is not loaded and you can have strange errors with premature crash
        // the trick is to load/require the remainig scripts on the module_load event     
        LOG_DEBUG("Loding preload script: %s", preloadScript.c_str()); 
        if(luaL_dofile(m_luaInstance, preloadScript.c_str()))
        {
            LOG_ERROR("Error loading preload script: %s", lua_tostring(m_luaInstance, -1)); 
        }
        lua_settop(m_luaInstance, 0);

        m_object_self = Constants::OBJECT_INVALID;
        // bind events
        GetServices()->m_events->RegisterEvent("EVAL", std::bind(&Lua::OnEval, this, std::placeholders::_1));
        GetServices()->m_events->RegisterEvent("EVALVOID", std::bind(&Lua::OnEvalVoid, this, std::placeholders::_1));
        GetServices()->m_events->RegisterEvent("TOKEN", std::bind(&Lua::OnToken, this, std::placeholders::_1));    
        GetServices()->m_events->RegisterEvent("EVENT", std::bind(&Lua::OnEvent, this, std::placeholders::_1));
    }

    Lua::~Lua()
    {        
        // run last event so resources on Lua side could be released, i.e: closing DB connections
        LOG_DEBUG("Running server_shutdown event");
        lua_getglobal(m_luaInstance, m_eventFunction.c_str());  /* function to be called */
        lua_pushstring(m_luaInstance, "server_shutdown");   /* push 1st argument */
        lua_pushinteger(m_luaInstance, 0);   /* push 2nd argument */
        //lua_pushstring(m_luaInstance, "");   /* push 3st argument, OPTIONAL */
        lua_pcall(m_luaInstance, 2, 0, 0);
        lua_settop (m_luaInstance, 0);

        LOG_DEBUG("Lua Shutdown, Memory: %d Kb", lua_gc(m_luaInstance, LUA_GCCOUNT, 0));
    }

    // Eval Lua code and returns the result
    Events::ArgumentStack Lua::OnEval(Events::ArgumentStack&& args)
    {
        const auto code = Events::ExtractArgument<std::string>(args);       
        Events::ArgumentStack stack;

        SetObjectSelf();  
        
        if(luaL_dostring(m_luaInstance, code.c_str()))
        {
            LOG_ERROR("Error on Eval: %s", lua_tostring(m_luaInstance, -1));
            Events::InsertArgument(stack, std::string(""));               
        }
        else if(lua_gettop(m_luaInstance))
        {   
            size_t iLength = 0;
            const char *returnStr = lua_tolstring(m_luaInstance, -1, &iLength);
            Events::InsertArgument(stack, std::string(returnStr, iLength));
        }
        else
        {
            Events::InsertArgument(stack, std::string(""));
        }        
        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Eval Lua code without result
    Events::ArgumentStack Lua::OnEvalVoid(Events::ArgumentStack&& args)
    {
        const auto code = Events::ExtractArgument<std::string>(args);        
        Events::ArgumentStack stack;

        SetObjectSelf();  

        if(luaL_dostring(m_luaInstance, code.c_str()))
        {
            LOG_ERROR("Error on EvalVoid: %s", lua_tostring(m_luaInstance, -1));               
        }
     
        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Used to emulate DelayCommand, AssignCommand and ActioDoCommand
    Events::ArgumentStack Lua::OnToken(Events::ArgumentStack&& args)
    {
        const auto token = Events::ExtractArgument<std::string>(args);        
        Events::ArgumentStack stack;
        
        SetObjectSelf();         
        
        lua_getglobal(m_luaInstance, m_tokenFunction.c_str());  /* function to be called */
        lua_pushstring(m_luaInstance, token.c_str());   /* push 1st argument */

        if (lua_pcall(m_luaInstance, 1, 0, 0) != 0)
        {
            LOG_ERROR("Error on Token %s: %s", token.c_str(), lua_tostring(m_luaInstance, -1));
        }
        
        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Call the event function
    Events::ArgumentStack Lua::OnEvent(Events::ArgumentStack&& args)
    {
        const auto eventStr = Events::ExtractArgument<std::string>(args);
        const auto objectId = Events::ExtractArgument<Types::ObjectID>(args);
        const auto extraStr = Events::ExtractArgument<std::string>(args);
        Events::ArgumentStack stack;
        
        SetObjectSelf();  

        lua_getglobal(m_luaInstance, m_eventFunction.c_str());  /* function to be called */
        lua_pushstring(m_luaInstance, eventStr.c_str());   /* push 1st argument */
        lua_pushinteger(m_luaInstance, objectId);   /* push 2nd argument */
        lua_pushstring(m_luaInstance, extraStr.c_str());   /* push 3st argument */
        
        if (lua_pcall(m_luaInstance, 3, 0, 0) != 0)
        {
            LOG_ERROR("Error on Event %s, object 0x%x: %s", eventStr.c_str(), objectId, lua_tostring(m_luaInstance, -1));
        }
        
        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Set a global number OBJECT_SELF at each request of running Lua code,
    // if a function is present in the configuration
    // call that function instead
    void Lua::SetObjectSelf()
    {              
        Types::ObjectID objSelf = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];

        if(m_object_self == objSelf)
        {
            return;
        }
        
        // a function is defined, call it 
        if(!m_setObjSelfFunction.empty())
        {
            lua_getglobal(m_luaInstance, m_setObjSelfFunction.c_str());  /* function to be called */
            lua_pushinteger(m_luaInstance, objSelf);   /* push 1st argument */
            if (lua_pcall(m_luaInstance, 1, 0, 0) != 0)
            {
                LOG_ERROR("Error on SetObjSelf function %s, object 0x%x: %s", m_setObjSelfFunction.c_str(), objSelf, lua_tostring(m_luaInstance, -1));
            }

        }
        else // no function: give the value to a Global integer 
        {
            lua_pushinteger(m_luaInstance, objSelf); 
            lua_setglobal(m_luaInstance, "OBJECT_SELF");
        }
        m_object_self = objSelf;
        lua_settop(m_luaInstance, 0);
    }

}
