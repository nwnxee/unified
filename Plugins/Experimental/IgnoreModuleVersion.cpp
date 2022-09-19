#include "nwnx.hpp"
#include "API/CExoString.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"


namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_ReadFieldCExoStringHook = nullptr;

void IgnoreModuleVersion() __attribute__((constructor));
void IgnoreModuleVersion()
{
    if (!Config::Get<bool>("IGNORE_MODULE_VERSION", false))
        return;

    LOG_INFO("EXPERIMENTAL: Ignoring Module Version check");

    s_ReadFieldCExoStringHook = Hooks::HookFunction(&CResGFF::ReadFieldCExoString,
        +[](CResGFF *pThis, CResStruct* pStructure, char* szFieldID, BOOL &bSuccess, const CExoString &sDefault) -> CExoString
        {
            if (strcmp(szFieldID, "Mod_MinGameVer") == 0)
            {
                bSuccess = true;
                return {"1.00"};
            }
            else
                return s_ReadFieldCExoStringHook->CallOriginal<CExoString>(pThis, pStructure, szFieldID, &bSuccess, &sDefault);
        }, Hooks::Order::Late);
}

}
