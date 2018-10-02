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

constexpr uintptr_t g_exoBaseAddr        = 0x0048EAAC; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_exoResManAddr      = 0x0048EAA8; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_virtualMachineAddr = 0x0048EAA4; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_scriptCompilerAddr = 0x0048EAA0; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_appManagerAddr     = 0x0048EA9C; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_tlkTableAddr       = 0x0048EA98; NWNX_EXPECT_VERSION(8181);
constexpr uintptr_t g_nwRulesAddr        = 0x0048EA94; NWNX_EXPECT_VERSION(8181);

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
