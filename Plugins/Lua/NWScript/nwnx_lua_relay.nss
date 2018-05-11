// this script is used internally by the Lua plugin to emulate 
// DelayCommand, AssignCommand and ActionDoCommand functions
#include "nwnx"

void NWNX_Lua_CallToken(string sToken)
{
    NWNX_PushArgumentString("NWNX_Lua", "TOKEN", sToken);
    NWNX_CallFunction("NWNX_Lua", "TOKEN");
}

void main() {
    string sCmd = GetLocalString(OBJECT_SELF, "lua_relay_cmd");
    int iType = GetLocalInt(OBJECT_SELF, "lua_relay_type");
    switch (iType) 
    {
    case 0:
         // DelayCommand
         DelayCommand(GetLocalFloat(OBJECT_SELF, "lua_relay_delay"), NWNX_Lua_CallToken(sCmd));
         break;  
    case 1:
         // AssignCommand ...
         AssignCommand(OBJECT_SELF, NWNX_Lua_CallToken(sCmd));
         break;
    case 2:
         // ActionDoCommand ...
         ActionDoCommand(NWNX_Lua_CallToken(sCmd));
         break;
    }
}