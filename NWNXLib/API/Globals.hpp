#pragma once

#include <cstdint>
#include "API/Version.hpp"

namespace NWNXLib {

namespace API {

#ifdef _WIN32
    static_assert(false, "Windows is not suported.");
#endif

struct CExoBase;
struct CExoResMan;
struct CVirtualMachine;
struct CScriptCompiler;
struct CAppManager;
struct CTlkTable;
struct CNWRules;
struct CExoString;

namespace Globals {

constexpr uintptr_t g_exoBaseAddr        = 0x005F2CEC; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_exoResManAddr      = 0x005F2CE8; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_virtualMachineAddr = 0x005F2CE4; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_scriptCompilerAddr = 0x005F2CE0; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_appManagerAddr     = 0x005F2CDC; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_tlkTableAddr       = 0x005F2CD8; NWNX_EXPECT_VERSION(8186);
constexpr uintptr_t g_nwRulesAddr        = 0x005F2CD4; NWNX_EXPECT_VERSION(8186);

extern CExoBase*        ExoBase();
extern CExoResMan*      ExoResMan();
extern CVirtualMachine* VirtualMachine();
extern CScriptCompiler* ScriptCompiler();
extern CAppManager*     AppManager();
extern CTlkTable*       TlkTable();
extern CNWRules*        Rules();

}

}

}
