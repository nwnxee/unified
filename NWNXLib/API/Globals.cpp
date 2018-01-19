#include "Globals.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

namespace Globals {

CExoBase* ExoBase()
{
    CExoBase** ptr = reinterpret_cast<CExoBase**>(Platform::ASLR::GetRelocatedGlobalAddress(g_exoBaseAddr));
    return *ptr;
}

CExoResMan* ExoResMan()
{
    CExoResMan** ptr = reinterpret_cast<CExoResMan**>(Platform::ASLR::GetRelocatedGlobalAddress(g_exoResManAddr));
    return *ptr;
}

CVirtualMachine* VirtualMachine()
{
    CVirtualMachine** ptr = reinterpret_cast<CVirtualMachine**>(Platform::ASLR::GetRelocatedGlobalAddress(g_virtualMachineAddr));
    return *ptr;
}

CScriptCompiler* ScriptCompiler()
{
    CScriptCompiler** ptr = reinterpret_cast<CScriptCompiler**>(Platform::ASLR::GetRelocatedGlobalAddress(g_scriptCompilerAddr));
    return *ptr;
}

CAppManager* AppManager()
{
    CAppManager** ptr = reinterpret_cast<CAppManager**>(Platform::ASLR::GetRelocatedGlobalAddress(g_appManagerAddr));
    return *ptr;
}

CTlkTable* TlkTable()
{
    CTlkTable** ptr = reinterpret_cast<CTlkTable**>(Platform::ASLR::GetRelocatedGlobalAddress(g_tlkTableAddr));
    return *ptr;
}

CNWRules* Rules()
{
    CNWRules** ptr = reinterpret_cast<CNWRules**>(Platform::ASLR::GetRelocatedGlobalAddress(g_nwRulesAddr));
    return *ptr;
}

}

}

}
