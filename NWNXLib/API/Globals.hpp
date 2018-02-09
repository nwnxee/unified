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

constexpr uintptr_t g_exoBaseAddr        = 0x004777E0; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_exoResManAddr      = 0x004777DC; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_virtualMachineAddr = 0x004777D8; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_scriptCompilerAddr = 0x004777D4; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_appManagerAddr     = 0x004777D0; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_tlkTableAddr       = 0x004777CC; NWNX_EXPECT_VERSION(8158);
constexpr uintptr_t g_nwRulesAddr        = 0x004777C8; NWNX_EXPECT_VERSION(8158);

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
