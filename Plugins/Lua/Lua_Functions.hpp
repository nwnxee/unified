#pragma once

#include "API/ALL_CLASSES.hpp"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#ifdef NWNX_LUA_LUAJIT
#include "luajit.h"
#endif
}

CVirtualMachine* GetVm();
CNWSVirtualMachineCommands* GetVmCommands();

void LUA_InitNWScript(lua_State *L);

