#pragma once

#include "nwn_api.hpp"
#include <cstdint>

NWNX_IMPORT extern CExoString                g_sBuildNumber;
NWNX_IMPORT extern CExoString                g_sBuildRevision;
NWNX_IMPORT extern CExoString                g_sBuildPostfix;
NWNX_IMPORT extern class CExoBase           *g_pExoBase;
NWNX_IMPORT extern class CExoResMan         *g_pExoResMan;
NWNX_IMPORT extern class CVirtualMachine    *g_pVirtualMachine;
NWNX_IMPORT extern class CScriptCompiler    *g_pScriptCompiler;
NWNX_IMPORT extern class CAppManager        *g_pAppManager;
NWNX_IMPORT extern class CTlkTable          *g_pTlkTable;
NWNX_IMPORT extern class CNWRules           *g_pRules;
namespace Task {
NWNX_IMPORT extern class CExoTaskManager    *g_pExoTaskManager;
}
NWNX_IMPORT extern int32_t                   g_bEnableCombatDebugging;
NWNX_IMPORT extern int32_t                   g_bEnableSavingThrowDebugging;
NWNX_IMPORT extern int32_t                   g_bEnableMovementSpeedDebugging;
NWNX_IMPORT extern int32_t                   g_bEnableHitDieDebugging;
NWNX_IMPORT extern int32_t                   g_bExitProgram;

namespace NWNXLib::API::Globals {

inline CExoString*            BuildNumber()     { return &g_sBuildNumber; }
inline CExoString*            BuildRevision()   { return &g_sBuildRevision; }
inline CExoString*            BuildPostfix()    { return &g_sBuildPostfix; }
inline CExoBase*              ExoBase()         { return g_pExoBase; }
inline CExoResMan*            ExoResMan()       { return g_pExoResMan; }
inline CVirtualMachine*       VirtualMachine()  { return g_pVirtualMachine; }
inline CScriptCompiler*       ScriptCompiler()  { return g_pScriptCompiler; }
inline CAppManager*           AppManager()      { return g_pAppManager; }
inline CTlkTable*             TlkTable()        { return g_pTlkTable; }
inline CNWRules*              Rules()           { return g_pRules; }
inline Task::CExoTaskManager* TaskManager()     { return Task::g_pExoTaskManager; }

inline int32_t* EnableCombatDebugging()         { return &g_bEnableCombatDebugging; }
inline int32_t* EnableSavingThrowDebugging()    { return &g_bEnableSavingThrowDebugging; }
inline int32_t* EnableMovementSpeedDebugging()  { return &g_bEnableMovementSpeedDebugging; }
inline int32_t* EnableHitDieDebugging()         { return &g_bEnableHitDieDebugging; }
#ifdef WIN32
inline int32_t* ExitProgram()                   { return NULL; }
#else
inline int32_t* ExitProgram()                   { return &g_bExitProgram; }
#endif

}
