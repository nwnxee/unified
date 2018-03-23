#include "Utils.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include <sstream>

namespace NWNXLib {
namespace Utils {


std::string ObjectIDToString(const API::Types::ObjectID id)
{
    std::stringstream ss;
    ss << std::hex << id;
    return ss.str();
}

std::string GetCurrentScript()
{
    auto *pVM = API::Globals::VirtualMachine();
    return std::string(pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel].m_sScriptName.CStr());
}
void ExecuteScript(const std::string& script, API::Types::ObjectID oidOwner)
{
    API::CExoString exoStr = script.c_str();
    API::Globals::VirtualMachine()->RunScript(&exoStr, oidOwner, 1);
}

}
}
