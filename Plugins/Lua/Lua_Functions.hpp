#pragma once

#include "API/NWNXLibApi.hpp"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#ifdef NWNX_LUA_LUAJIT
#include "luajit.h"
#endif
}

NWNXLib::API::CVirtualMachine* GetVm();
NWNXLib::API::CNWVirtualMachineCommands* GetVmCommands();

void LUA_InitNWScript(lua_State *L);

