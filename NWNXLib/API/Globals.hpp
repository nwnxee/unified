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

constexpr uintptr_t g_exoBaseAddr        = 0x00480800; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_exoResManAddr      = 0x004807FC; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_virtualMachineAddr = 0x004807F8; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_scriptCompilerAddr = 0x004807F4; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_appManagerAddr     = 0x004807F0; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_tlkTableAddr       = 0x004807EC; NWNX_EXPECT_VERSION(8159);
constexpr uintptr_t g_nwRulesAddr        = 0x004807E8; NWNX_EXPECT_VERSION(8159);

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
