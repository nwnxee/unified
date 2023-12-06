#include "nwnx.hpp"
#include "Lua_Functions.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/Constants.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/Globals.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Vector.hpp"
#include "API/CExoString.hpp"
#include "API/CScriptLocation.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CWorldTimer.hpp"
#include "API/CNWSObject.hpp"
#include <sys/time.h>
#include <cmath>


// metatables
#define LUA_NWN_VECTOR "nwn_vector"
#define LUA_NWN_EFFECT "nwn_effect"
#define LUA_NWN_EVENT "nwn_event"
#define LUA_NWN_LOCATION "nwn_location"
#define LUA_NWN_TALENT "nwn_talent"
#define LUA_NWN_ITEMPROPERTY "nwn_itemproperty"


using namespace NWNXLib;
using namespace NWNXLib::API;


CVirtualMachine* GetVm()
{
    return Globals::VirtualMachine();
}


CNWSVirtualMachineCommands* GetVmCommands()
{
    return static_cast<CNWSVirtualMachineCommands*>(GetVm()->m_pCmdImplementer);
}

CVirtualMachineScript* CreateScriptForClosure(const char* token)
{
    CVirtualMachineScript* script = new CVirtualMachineScript();
    script->m_pCode = NULL;
    script->m_nSecondaryInstructPtr = 0;
    script->m_nInstructPtr = 0;
    script->m_nStackSize = 0;
    script->m_pStack = new CVirtualMachineStack();

    char buff[128];
    sprintf(buff, "%s %s", "NWNX_LUA_INTERNAL", token);
    script->m_sScriptName = CExoString(buff);

    return script;
}

extern "C" {

    static int NWScript_DelayCommand(lua_State *L)
    {
        uint32_t oid = (uint32_t)luaL_checkinteger(L, 1);
        const char* token = luaL_checkstring(L, 2);
        float duration = lua_tonumber(L, 3);

        CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
        if (obj)
        {
            int32_t days = 0;
            int32_t time = 0;
            if(duration > 0.0f)
            {
                days = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetCalendarDayFromSeconds(duration);
                time = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetTimeOfDayFromSeconds(duration);
            }

            CServerAIMaster* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
            ai->AddEventDeltaTime(days, time, oid, oid, 1, CreateScriptForClosure(token));
        }
        return 0;
    }

    static int NWScript_ActionDoCommand(lua_State *L)
    {
        uint32_t oid = (uint32_t)luaL_checkinteger(L, 1);
        const char* token = luaL_checkstring(L, 2);

        CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
        if (obj && obj->m_nObjectType > Constants::ObjectType::Area)
        {
            ((CNWSObject*)obj)->AddDoCommandAction(CreateScriptForClosure(token));
            return 0;
        }

        return 0;
    }

    static int NWScript_VM_ExecuteCommand(lua_State *L)
    {
        int32_t nCommand = (int32_t)luaL_checkinteger(L, 1);
        int32_t nArgs = (int32_t)luaL_checkinteger(L, 2);
        if(GetVmCommands()->ExecuteCommand(nCommand, nArgs))
        {
            LOG_WARNING("VM command %d failure called with %d args.", nCommand, nArgs);
        }
        return 0;
    }

    static int NWScript_StackPushInteger(lua_State *L)
    {
        int32_t nArg = (int32_t)luaL_checkinteger(L, 1);
        if(!GetVm()->StackPushInteger(nArg))
        {
            LOG_DEBUG("VM failed to push Integer");
        }
        return 0;
    }

    static int NWScript_StackPopInteger(lua_State *L)
    {
        int32_t nRetVal;
        if (!GetVm()->StackPopInteger(&nRetVal))
        {
            LOG_DEBUG("VM failed to pop Integer");
            nRetVal = 0;
        }
        lua_pushinteger(L, nRetVal);
        return 1;
    }

    static int NWScript_StackPushFloat(lua_State *L)
    {
        float fFloat = luaL_checknumber(L, 1);
        if(!GetVm()->StackPushFloat(fFloat))
        {
            LOG_DEBUG("VM failed to push Float");
        }
        return 0;
    }

    static int NWScript_StackPopFloat(lua_State *L)
    {
        float fRetVal;
        if (!GetVm()->StackPopFloat(&fRetVal))
        {
            LOG_DEBUG("VM failed to pop Float");
            fRetVal = 0.0f;
        }
        lua_pushnumber(L, fRetVal);
        return 1;
    }

    static int NWScript_StackPushString(lua_State *L)
    {
        const char *sString = luaL_checkstring(L, 1);
        CExoString str(sString);
        if(!GetVm()->StackPushString(str))
        {
            LOG_DEBUG("VM failed to push String");
        }
        return 0;
    }

    static int NWScript_StackPopString(lua_State *L)
    {
        CExoString value;
        if(!GetVm()->StackPopString(&value))
        {
            LOG_DEBUG("VM failed to pop String");
        }
        lua_pushstring(L, value.CStr());
        return 1;
    }

    static int NWScript_StackPushObject(lua_State *L)
    {
        uint32_t oObject = (uint32_t)luaL_checkinteger(L, 1);
        if(!GetVm()->StackPushObject(oObject))
        {
            LOG_DEBUG("VM failed to push Object");
        }
        return 0;
    }

    static int NWScript_StackPopObject(lua_State *L)
    {
        uint32_t nRetVal;
        if (!GetVm()->StackPopObject(&nRetVal))
        {
            LOG_DEBUG("VM failed to pop Object");
            nRetVal = Constants::OBJECT_INVALID;
        }
        lua_pushinteger(L, nRetVal);
        return 1;
    }

    static int NWScript_StackPushVector(lua_State *L)
    {
        Vector *vVector = (Vector *)luaL_checkudata(L, 1, LUA_NWN_VECTOR);
        if(!GetVm()->StackPushVector(*vVector))
        {
            LOG_DEBUG("VM failed to push Vector");
        }
        return 0;
    }

    static int NWScript_StackPopVector(lua_State *L)
    {
       Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
       if(!GetVm()->StackPopVector(vRetVal))
       {
            LOG_DEBUG("VM failed to pop Vector");
       }
       luaL_getmetatable(L, LUA_NWN_VECTOR);
       lua_setmetatable(L, -2);
       return 1;
    }

    static int NWScript_StackPushEffect(lua_State *L)
    {
        void *pEffect = *(void **)luaL_checkudata(L, 1, LUA_NWN_EFFECT);
        if(!GetVm()->StackPushEngineStructure(0, pEffect))
        {
            LOG_DEBUG("VM failed to push Effect");
        }
        return 0;
    }

    static int NWScript_StackPopEffect(lua_State *L)
    {
        void **pEffect = (void **)lua_newuserdata(L, sizeof(void*)); //CGameEffect
        if(!GetVm()->StackPopEngineStructure(0, pEffect))
        {
            LOG_DEBUG("VM failed to pop Effect");
        }
        luaL_getmetatable(L, LUA_NWN_EFFECT);
        lua_setmetatable(L, -2);
        return 1;
    }

    static int NWScript_StackPushEvent(lua_State *L)
    {
        void *pEvent = *(void **)luaL_checkudata(L, 1, LUA_NWN_EVENT);
        if(!GetVm()->StackPushEngineStructure(1, pEvent))
        {
            LOG_DEBUG("VM failed to push Event");
        }
        return 0;
    }

    static int NWScript_StackPopEvent(lua_State *L)
    {
        void **pEvent = (void **)lua_newuserdata(L, sizeof(void*));//CScriptEvent
        if(!GetVm()->StackPopEngineStructure(1, pEvent))
        {
            LOG_DEBUG("VM failed to pop Event");
        }
        luaL_getmetatable(L, LUA_NWN_EVENT);
        lua_setmetatable(L, -2);
        return 1;
    }

    static int NWScript_StackPushLocation(lua_State *L)
    {
        void *pLocation = *(void **)luaL_checkudata(L, 1, LUA_NWN_LOCATION);
        if(!GetVm()->StackPushEngineStructure(2, pLocation))
        {
            LOG_DEBUG("VM failed to push Location");
        }
        return 0;
    }

    static int NWScript_StackPopLocation(lua_State *L)
    {
        void **pLocation = (void **)lua_newuserdata(L, sizeof(void*));//CScriptLocation
        if(!GetVm()->StackPopEngineStructure(2, pLocation))
        {
            LOG_DEBUG("VM failed to pop Location");
        }
        luaL_getmetatable(L, LUA_NWN_LOCATION);
        lua_setmetatable(L, -2);
        return 1;
    }

    static int NWScript_StackPushTalent(lua_State *L)
    {
        void *pTalent = *(void **)luaL_checkudata(L, 1, LUA_NWN_TALENT);
        if(!GetVm()->StackPushEngineStructure(3, pTalent))
        {
            LOG_DEBUG("VM failed to push Talent");
        }
        return 0;
    }

    static int NWScript_StackPopTalent(lua_State *L)
    {
        void **pTalent = (void **)lua_newuserdata(L, sizeof(void*));//CScriptTalent
        if(!GetVm()->StackPopEngineStructure(3, pTalent))
        {
            LOG_DEBUG("VM failed to pop Talent");
        }
        luaL_getmetatable(L, LUA_NWN_TALENT);
        lua_setmetatable(L, -2);
        return 1;
    }

    static int NWScript_StackPushItemProperty(lua_State *L)
    {
        void *pProperty = *(void **)luaL_checkudata(L, 1, LUA_NWN_ITEMPROPERTY);
        if(!GetVm()->StackPushEngineStructure(4, pProperty))
        {
            LOG_DEBUG("VM failed to push ItemProperty");
        }
        return 0;
    }

    static int NWScript_StackPopItemProperty(lua_State *L)
    {
        void **pProperty = (void **)lua_newuserdata(L, sizeof(void*));//CGameEffect
        if(!GetVm()->StackPopEngineStructure(4, pProperty))
        {
            LOG_DEBUG("VM failed to pop ItemProperty");
        }
        luaL_getmetatable(L, LUA_NWN_ITEMPROPERTY);
        lua_setmetatable(L, -2);
        return 1;
    }
    // metatables functions
    // __gc
    static int NWScript_FreeEffect(lua_State *L)
    {
        void *pEffect = *(void **)lua_touserdata(L, 1);
        if (pEffect)
        {
            GetVmCommands()->DestroyGameDefinedStructure(0, pEffect);
        }
        return 0;
    }

    static int NWScript_FreeEvent(lua_State *L)
    {
        void *pEvent = *(void **)lua_touserdata(L, 1);
        if (pEvent)
        {
            GetVmCommands()->DestroyGameDefinedStructure(1, pEvent);
        }
        return 0;
    }

    static int NWScript_FreeLocation(lua_State *L)
    {
        void *pLocation = *(void **)lua_touserdata(L, 1);
        if (pLocation)
        {
            GetVmCommands()->DestroyGameDefinedStructure(2, pLocation);
        }
        return 0;
    }

    static int NWScript_FreeTalent(lua_State *L)
    {
        void *pTalent = *(void **)lua_touserdata(L, 1);
        if (pTalent)
        {
            GetVmCommands()->DestroyGameDefinedStructure(3, pTalent);
        }
        return 0;
    }

    static int NWScript_FreeItemProperty(lua_State *L)
    {
        void *pProperty = *(void **)lua_touserdata(L, 1);
        if (pProperty)
        {
            GetVmCommands()->DestroyGameDefinedStructure(4, pProperty);
        }
        return 0;
    }

    // nwn_vector.components()
    static int NWScript_VectorGetComponents(lua_State *L)
    {
        Vector *ptr = (Vector *)luaL_checkudata(L, 1, LUA_NWN_VECTOR);
        lua_pushnumber(L, ptr->x);
        lua_pushnumber(L, ptr->y);
        lua_pushnumber(L, ptr->z);
        return 3;
    }

    // nwn_location.components()
    static int NWScript_LocationGetComponents(lua_State *L)
    {
        CScriptLocation *ptr = *(CScriptLocation **)luaL_checkudata(L, 1, LUA_NWN_LOCATION);

        float facing = (float)(std::atan2(ptr->m_vOrientation.y, ptr->m_vOrientation.x) * (180 / 3.1415927));
        while (facing > 360.0)
        {
            facing -= 360.0;
        }
        while (facing < 0.0)
        {
            facing += 360.0;
        }
        lua_pushinteger(L, ptr->m_oArea);
        lua_pushnumber(L, ptr->m_vPosition.x);
        lua_pushnumber(L, ptr->m_vPosition.y);
        lua_pushnumber(L, ptr->m_vPosition.z);
        lua_pushnumber(L, facing);
        return 5;
    }

    // Additional functions
    static int NWScript_gettimeofday(lua_State *L)
    {
        struct timeval t;
        gettimeofday(&t, NULL);
        lua_pushnumber(L, t.tv_sec);
        lua_pushnumber(L, t.tv_usec);
        return 2;
    }

    static int NWScript_SerializeObject(lua_State *L)
    {
        uint32_t value = (uint32_t)luaL_checkinteger(L, 1);
        CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(value);
        std::string serialized = Utils::SerializeGameObjectB64(pObject);
        lua_pushstring(L, serialized.c_str());
        return 1;
    }

    static int NWScript_DeserializeObject(lua_State *L)
    {
        const char *s = luaL_checkstring(L, 1);
        uint32_t owner = (uint32_t)luaL_checkinteger(L, 2);
        Vector *v = (Vector *)luaL_checkudata(L, 3, LUA_NWN_VECTOR);

        std::string serialized(s);
        uint32_t retval = API::Constants::OBJECT_INVALID;
        if (CGameObject *pObject = Utils::DeserializeGameObjectB64(serialized))
        {
            retval = static_cast<uint32_t>(pObject->m_idSelf);
            ASSERT(API::Globals::AppManager()->m_pServerExoApp->GetGameObject(retval));

            CGameObject *pOwner = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(owner);
            if (auto *pArea = Utils::AsNWSArea(pOwner))
            {
                if (!Utils::AddToArea(pObject, pArea, v->x, v->y, v->z))
                    LOG_WARNING("Failed to add object %x to area %x (%f,%f,%f)", retval, owner, v->x, v->y, v->z);
            }
            else if (auto *pItem = Utils::AsNWSItem(pObject))
            {
                if (!Utils::AcquireItem(pItem, pOwner))
                    LOG_WARNING("Failed to 'acquire' deserialized item %x by owner %x", retval, owner);
            }
            else
            {
                LOG_INFO("No valid owner given, object %x deserialized outside world bounds", retval);
            }
        }

        lua_pushinteger(L, retval);
        return 1;
    }

}

static const struct luaL_Reg vector_m [] = {
  {"components", NWScript_VectorGetComponents},
  {NULL, NULL}
};

static const struct luaL_Reg effect_m [] = {
  {"__gc", NWScript_FreeEffect},
  {NULL, NULL}
};

static const struct luaL_Reg event_m [] = {
  {"__gc", NWScript_FreeEvent},
  {NULL, NULL}
};

static const struct luaL_Reg location_m [] = {
  {"components", NWScript_LocationGetComponents},
  {"__gc", NWScript_FreeLocation},
  {NULL, NULL}
};

static const struct luaL_Reg talent_m [] = {
  {"__gc", NWScript_FreeTalent},
  {NULL, NULL}
};

static const struct luaL_Reg property_m [] = {
  {"__gc", NWScript_FreeItemProperty},
  {NULL, NULL}
};

void luaopen_structure(lua_State *L, const char *tname, const luaL_Reg *lreg, bool global) {
    luaL_newmetatable(L, tname);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
#if LUA_VERSION_NUM > 501
    luaL_setfuncs(L, lreg, 0);
#else
    luaL_register(L, NULL, lreg);
#endif
    if (global)
    {
        lua_setglobal(L, tname);
    }
}

void LUA_InitNWScript(lua_State *L)
{
    luaopen_structure(L, LUA_NWN_VECTOR, vector_m, true);
    luaopen_structure(L, LUA_NWN_LOCATION, location_m, true);
    luaopen_structure(L, LUA_NWN_EFFECT, effect_m, false);
    luaopen_structure(L, LUA_NWN_EVENT, event_m, false);
    luaopen_structure(L, LUA_NWN_TALENT, talent_m, false);
    luaopen_structure(L, LUA_NWN_ITEMPROPERTY, property_m, false);
    lua_register(L, "actiondocommand", NWScript_ActionDoCommand);
    lua_register(L, "delaycommand", NWScript_DelayCommand);
    lua_register(L, "serializeobject", NWScript_SerializeObject);
    lua_register(L, "deserializeobject", NWScript_DeserializeObject);
    lua_register(L, "gettimeofday", NWScript_gettimeofday);
    lua_register(L, "VM_ExecuteCommand", NWScript_VM_ExecuteCommand);
    lua_register(L, "StackPushObject", NWScript_StackPushObject);
    lua_register(L, "StackPopObject", NWScript_StackPopObject);
    lua_register(L, "StackPushVector", NWScript_StackPushVector);
    lua_register(L, "StackPopVector", NWScript_StackPopVector);
    lua_register(L, "StackPushString", NWScript_StackPushString);
    lua_register(L, "StackPopString", NWScript_StackPopString);
    lua_register(L, "StackPushFloat", NWScript_StackPushFloat);
    lua_register(L, "StackPopFloat", NWScript_StackPopFloat);
    lua_register(L, "StackPushInteger", NWScript_StackPushInteger);
    lua_register(L, "StackPopInteger", NWScript_StackPopInteger);
    lua_register(L, "StackPushEffect", NWScript_StackPushEffect);
    lua_register(L, "StackPopEffect", NWScript_StackPopEffect);
    lua_register(L, "StackPushEvent", NWScript_StackPushEvent);
    lua_register(L, "StackPopEvent", NWScript_StackPopEvent);
    lua_register(L, "StackPushLocation", NWScript_StackPushLocation);
    lua_register(L, "StackPopLocation", NWScript_StackPopLocation);
    lua_register(L, "StackPushTalent", NWScript_StackPushTalent);
    lua_register(L, "StackPopTalent", NWScript_StackPopTalent);
    lua_register(L, "StackPushItemProperty", NWScript_StackPushItemProperty);
    lua_register(L, "StackPopItemProperty", NWScript_StackPopItemProperty);
}

