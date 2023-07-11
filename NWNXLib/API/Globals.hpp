#pragma once

#include <cstdint>

__declspec(dllimport) extern CExoString                g_sBuildNumber;
__declspec(dllimport) extern CExoString                g_sBuildRevision;
__declspec(dllimport) extern CExoString                g_sBuildPostfix;
__declspec(dllimport) extern class CExoBase           *g_pExoBase;
__declspec(dllimport) extern class CExoResMan         *g_pExoResMan;
__declspec(dllimport) extern class CVirtualMachine    *g_pVirtualMachine;
__declspec(dllimport) extern class CScriptCompiler    *g_pScriptCompiler;
__declspec(dllimport) extern class CAppManager        *g_pAppManager;
__declspec(dllimport) extern class CTlkTable          *g_pTlkTable;
__declspec(dllimport) extern class CNWRules           *g_pRules;
namespace Task {
__declspec(dllimport) extern class CExoTaskManager    *g_pExoTaskManager;
}
__declspec(dllimport) extern int32_t                   g_bEnableCombatDebugging;
__declspec(dllimport) extern int32_t                   g_bEnableSavingThrowDebugging;
__declspec(dllimport) extern int32_t                   g_bEnableMovementSpeedDebugging;
__declspec(dllimport) extern int32_t                   g_bEnableHitDieDebugging;
__declspec(dllimport) extern int32_t                   g_bExitProgram;

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
inline int32_t* ExitProgram()                   { return &g_bExitProgram; }

}
