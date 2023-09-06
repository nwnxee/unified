#include "Lua.hpp"

#include "API/Globals.hpp"
#include "API/CExoBase.hpp"
#include "API/Functions.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
//for objectself
#include "API/CVirtualMachine.hpp"
// for dlopen
#ifdef NWNX_LUA_LIBRARY
#include <dlfcn.h>
#endif


using namespace NWNXLib;
static Lua::Lua* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Lua::Lua(services);
    return g_plugin;
}

namespace Lua {

    using namespace NWNXLib::Services;
    using namespace NWNXLib::API;
    using namespace NWNXLib;

    static Hooks::Hook s_RunScriptHook;
    static Hooks::Hook s_RunScriptSituationHook;

    Lua::Lua(Services::ProxyServiceList* services) : Plugin(services)
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
        std::string preloadScript = Config::Get<std::string>("PRELOAD_SCRIPT", userDir+"/lua/preload.lua");
        std::string tokenFunction = Config::Get<std::string>("TOKEN_FUNCTION", "CallToken");

        // if you want to use an event framework instead of use only Eval and EvalVoid, less intensive
        std::string eventFunction = Config::Get<std::string>("EVENT_FUNCTION", "RunEvent");

        // custom Set OBJECT_SELF function accepting an integer as argument (the current value of OBJECT_SELF)
        // if this configuration is not defined a global OBJECT_SELF integer wil be keeped aligned to the current value
        // This is useful if you want to write OOP code and treat nwn objects as lua classes and not as numbers
        // The other function in wich you recive a numeric object is the RunEvent Function,
        // but RunEvent is in lua code so you can modifiy as you want
        std::string setObjSelfFunction = Config::Get<std::string>("OBJSELF_FUNCTION", "");

        // Name of the table containg the functions called in the run script hook
        // Optional; a function with the same name of the script executed will be run before
        // the script, if returning something diffferent from nil the script execution will be skipped,
        // if returns a Lua boolean is treated like a return value from a StartingConditional() in NWScript
        std::string runScriptTable = Config::Get<std::string>("RUNSCRIPT_TABLE", "");

        // loading preload code
        // Dont call any NWN function in this script like SetLocalString(), GetModule() etc
        // the module is not loaded and you can have strange errors with premature crash
        // the trick is to load/require the remainig scripts on the module_load event
        LOG_DEBUG("Loding preload script: %s", preloadScript);
        if(luaL_dofile(m_luaInstance, preloadScript.c_str()))
        {
            LOG_ERROR("Error loading preload script: %s", lua_tostring(m_luaInstance, -1));
        }
        lua_settop(m_luaInstance, 0);

        // save the Token function in the lua registry for fast access
        lua_getglobal(m_luaInstance, tokenFunction.c_str());
        m_tokenFunction = luaL_ref(m_luaInstance, LUA_REGISTRYINDEX);

        // save the Event function in the lua registry for fast access
        lua_getglobal(m_luaInstance, eventFunction.c_str());
        m_eventFunction = luaL_ref(m_luaInstance, LUA_REGISTRYINDEX);

        // default assignement
        m_object_self = Constants::OBJECT_INVALID;

        if(setObjSelfFunction.empty())
        {
            m_setObjSelfFunction = [&](ObjectID objSelf)
            {
                lua_pushinteger(m_luaInstance, objSelf);
                lua_setglobal(m_luaInstance, "OBJECT_SELF");
            };
        }
        else
        {
            // Save the SetObjectSelf function in the lua registry
            lua_getglobal(m_luaInstance, setObjSelfFunction.c_str());
            int iRef = luaL_ref(m_luaInstance, LUA_REGISTRYINDEX);

            m_setObjSelfFunction = [&, iRef](ObjectID objSelf)
            {
                lua_rawgeti(m_luaInstance, LUA_REGISTRYINDEX, iRef);
                lua_pushinteger(m_luaInstance, objSelf);
                if (lua_pcall(m_luaInstance, 1, 0, 0) != 0)
                {
                    LOG_ERROR("Error on OBJSELF_FUNCTION function, object 0x%x: %s", objSelf, lua_tostring(m_luaInstance, -1));
                    lua_remove(m_luaInstance, -1);
                }
            };
        }

        // bind events
        ScriptAPI::RegisterEvent(PLUGIN_NAME, "Eval", std::bind(&Lua::Eval, this, std::placeholders::_1));
        ScriptAPI::RegisterEvent(PLUGIN_NAME, "EvalVoid", std::bind(&Lua::EvalVoid, this, std::placeholders::_1));
        ScriptAPI::RegisterEvent(PLUGIN_NAME, "RunEvent", std::bind(&Lua::RunEvent, this, std::placeholders::_1));

        // RunScript hook
        if(!runScriptTable.empty())
        {
            // save the Scripts table in the registry
            lua_getglobal(m_luaInstance, runScriptTable.c_str());
            m_runScriptTable = luaL_ref(m_luaInstance, LUA_REGISTRYINDEX);

            s_RunScriptHook = Hooks::HookFunction(&CVirtualMachine::RunScript,
                +[](CVirtualMachine* thisPtr, CExoString* script, ObjectID objId, int32_t valid, int32_t eventId)
                {
                    bool skip = script->m_sString && g_plugin->OnScript(script->m_sString, objId, !!valid);
                    return skip ? 1 : s_RunScriptHook->CallOriginal<int32_t>(thisPtr, script, objId, valid, eventId);
                },
                Hooks::Order::Latest);
        }

        // RunScriptSituation hook
        s_RunScriptSituationHook = Hooks::HookFunction(&CVirtualMachine::RunScriptSituation,
            +[](CVirtualMachine* thisPtr, CVirtualMachineScript* script, ObjectID oid, int32_t oidValid)
            {
                if (strstr(script->m_sScriptName.m_sString, "NWNX_LUA_INTERNAL"))
                {
                    char* token = strstr(script->m_sScriptName.m_sString, " ");
                    if (token)
                    {
                        g_plugin->OnToken(oid, token + 1);
                        delete script;
                    }
                    return 1;
                }

                return s_RunScriptSituationHook->CallOriginal<int32_t>(thisPtr, script, oid, oidValid);
            },
            Hooks::Order::Latest);
    }

    Lua::~Lua()
    {
        // run last event so resources on Lua side could be released, i.e: closing DB connections
        LOG_INFO("Running server_shutdown event");
        lua_rawgeti(m_luaInstance, LUA_REGISTRYINDEX, m_eventFunction);  /* function to be called */
        lua_pushstring(m_luaInstance, "server_shutdown");   /* push 1st argument */
        lua_pushinteger(m_luaInstance, 0);   /* push 2nd argument */

        if (lua_pcall(m_luaInstance, 2, 0, 0) != 0)
        {
            LOG_ERROR("Error on Event server_shutdown, object 0x0: %s", lua_tostring(m_luaInstance, -1));
        }

        lua_settop (m_luaInstance, 0);
        LOG_INFO("Lua Shutdown, Memory: %d Kb", lua_gc(m_luaInstance, LUA_GCCOUNT, 0));
    }

    // Eval Lua code and returns the result
    ArgumentStack Lua::Eval(ArgumentStack&& args)
    {
        const auto code = ScriptAPI::ExtractArgument<std::string>(args);
        ArgumentStack stack;

        SetObjectSelf();

        LOG_DEBUG("Eval request code: %s", code);

        if(luaL_dostring(m_luaInstance, code.c_str()))
        {
            LOG_ERROR("Error on Eval: %s", lua_tostring(m_luaInstance, -1));
            ScriptAPI::InsertArgument(stack, std::string(""));
        }
        else if(lua_gettop(m_luaInstance))
        {
            size_t iLength = 0;
            const char *returnStr = lua_tolstring(m_luaInstance, -1, &iLength);
            ScriptAPI::InsertArgument(stack, std::string(returnStr, iLength));
        }
        else
        {
            ScriptAPI::InsertArgument(stack, std::string(""));
        }
        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Eval Lua code without result
    ArgumentStack Lua::EvalVoid(ArgumentStack&& args)
    {
        const auto code = ScriptAPI::ExtractArgument<std::string>(args);
        ArgumentStack stack;

        SetObjectSelf();

        LOG_DEBUG("Evalvoid request code: %s", code);

        if(luaL_dostring(m_luaInstance, code.c_str()))
        {
            LOG_ERROR("Error on EvalVoid: %s", lua_tostring(m_luaInstance, -1));
        }

        lua_settop(m_luaInstance, 0);
        return stack;
    }

    // Used to emulate DelayCommand, AssignCommand and ActioDoCommand
    void Lua::OnToken(ObjectID oid, char* token)
    {
        GetVm()->m_nRecursionLevel += 1;

        GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = oid;
        GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = 1;
        GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];

        SetObjectSelf(oid);

        LOG_DEBUG("Token %s on OBJECT: 0x%x", token, oid);

        lua_rawgeti(m_luaInstance, LUA_REGISTRYINDEX, m_tokenFunction);
        lua_pushstring(m_luaInstance, token);   /* push 1st argument */
        if (lua_pcall(m_luaInstance, 1, 0, 0) != 0)
        {
            LOG_ERROR("Error on Token %s: %s", token, lua_tostring(m_luaInstance, -1));
        }

        lua_settop(m_luaInstance, 0);

        GetVm()->m_nRecursionLevel -= 1;
    }

    // Call the event function
    ArgumentStack Lua::RunEvent(ArgumentStack&& args)
    {
        const auto eventStr = ScriptAPI::ExtractArgument<std::string>(args);
        const auto objectId = ScriptAPI::ExtractArgument<ObjectID>(args);
        const auto extraStr = ScriptAPI::ExtractArgument<std::string>(args);
        ArgumentStack stack;

        SetObjectSelf();

        LOG_DEBUG("Event %s on OBJECT: 0x%x", eventStr, objectId);

        lua_rawgeti(m_luaInstance, LUA_REGISTRYINDEX, m_eventFunction);  /* function to be called */
        lua_pushstring(m_luaInstance, eventStr.c_str());   /* push 1st argument */
        lua_pushinteger(m_luaInstance, objectId);   /* push 2nd argument */
        lua_pushstring(m_luaInstance, extraStr.c_str());   /* push 3st argument */

        if (lua_pcall(m_luaInstance, 3, 0, 0) != 0)
        {
            LOG_ERROR("Error on Event %s, object 0x%x: %s", eventStr, objectId, lua_tostring(m_luaInstance, -1));
        }

        lua_settop(m_luaInstance, 0);
        return stack;
    }

    bool Lua::OnScript(const char* scriptName, ObjectID objId, bool valid)
    {
        bool bSkip = false;

        //LOG_DEBUG("Called Script %s, OBJECT: 0x%x", scriptName, objId);
        lua_rawgeti(m_luaInstance, LUA_REGISTRYINDEX, m_runScriptTable);
        lua_getfield(m_luaInstance, -1, scriptName);

        // check if the functions exists in the m_runScriptTable Table
        if(lua_isfunction(m_luaInstance, -1))
        {
            LOG_DEBUG("RunScript Hook: %s function found, object 0x%x", scriptName, objId);

            // PREPARE VM
            if (GetVm()->m_nRecursionLevel == -1)
            {
                GetVm()->m_cRunTimeStack.InitializeStack();
                GetVm()->m_cRunTimeStack.m_pVMachine = GetVm();
            }
            GetVm()->m_nReturnValueParameterType = 0;
            GetVm()->m_pReturnValue = nullptr;
            GetVm()->m_nRecursionLevel += 1;
            GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = objId;
            GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = valid;
            GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
            GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];

            int spBefore = GetVm()->m_cRunTimeStack.GetStackPointer();

            SetObjectSelf(objId);

            if (lua_pcall(m_luaInstance, 0, 1, 0) != 0) // call with 0 args and a return value
            {
                LOG_ERROR("Error on function %s: %s", scriptName, lua_tostring(m_luaInstance, -1));
            }
            else
            {
                if(!lua_isnil(m_luaInstance, -1))
                {
                    // we got something so skip the original script call
                    bSkip = true;
                    LOG_DEBUG("Skipping %s execution", scriptName);


                    if(lua_isboolean(m_luaInstance, -1))
                    {
                        // we got a boolean: it's a result from a starting conditional!!
                        int retval = lua_toboolean(m_luaInstance, -1);
                        LOG_DEBUG("Got a returning boolean from function %s, value: %d", scriptName, retval);
                        GetVm()->m_nReturnValueParameterType = 0x03;
                        GetVm()->m_pReturnValue = reinterpret_cast<void*>(retval);
                    }
                }
            }

            // check the VM stack
            int spAfter = GetVm()->m_cRunTimeStack.GetStackPointer();
            if (spBefore != spAfter)
            {
                LOG_WARNING("The stack pointer before (%d) and after (%d) were different - stack over/underflow in script %s?", spBefore, spAfter, scriptName);
            }

            // CLEANUP VM
            GetVm()->m_nRecursionLevel -= 1;
            if (GetVm()->m_nRecursionLevel != -1)
            {
                GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
                GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
            }

        }
        // clean the stack
        lua_settop(m_luaInstance, 0);
        return bSkip;
    }

    // Set a global number OBJECT_SELF at each request of running Lua code,
    // if a function is present in the configuration
    // call that function instead, leave the stack clean even on error
    void Lua::SetObjectSelf(ObjectID objSelf)
    {
        if(objSelf == Constants::OBJECT_INVALID)
        {
            objSelf = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        }
        // change only if there is a change of context
        if(m_object_self == objSelf)
        {
            return;
        }
        LOG_DEBUG("Setting OBJECT_SELF to 0x%x", objSelf);
        m_setObjSelfFunction(objSelf);
        m_object_self = objSelf;
    }

}
