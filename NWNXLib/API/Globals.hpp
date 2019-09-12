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

constexpr uintptr_t g_exoBaseAddr        = 0x00BA7420; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_exoResManAddr      = 0x00BA7418; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_virtualMachineAddr = 0x00BA7410; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_scriptCompilerAddr = 0x00BA7408; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_appManagerAddr     = 0x00BA7400; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_tlkTableAddr       = 0x00BA73F8; NWNX_EXPECT_VERSION(8190);
constexpr uintptr_t g_nwRulesAddr        = 0x00BA73F0; NWNX_EXPECT_VERSION(8190);

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
