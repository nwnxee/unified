#include "nwnx.hpp"

#include "API/CResGFF.hpp"
#include "API/CNWSModule.hpp"
#include "API/NWSyncAdvertisement.hpp"
#include "API/CExoResMan.hpp"
#include "API/CNWSRules.hpp"


namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

const int RESMAN_PRIORITY_USER_HAK = 31000000;
const int LOADMODULE_ERROR_COULDNOTLOADHAK = 2;

void CustomHakList() __attribute__((constructor));
void CustomHakList()
{
    if (!Config::Get<bool>("USE_CUSTOM_HAK_LIST", false))
        return;

    LOG_INFO("Using custom list of hak files to load.");

    static Hooks::Hook s_GetListHook =
    Hooks::HookFunction(&CResGFF::GetList,
    +[](CResGFF *pGff, CResList *pList, CResStruct *pStructure, char *szFieldID) -> int32_t
    {
        if (strncmp(pGff->m_pFileType, "IFO", 3) == 0 && strcmp(szFieldID, "Mod_HakList") == 0)
        {
            return false;
        }

        return s_GetListHook->CallOriginal<int32_t>(pGff, pList, pStructure, szFieldID);
    }, Hooks::Order::Late);

    static Hooks::Hook loadModuleStartHook = Hooks::HookFunction(&CNWSModule::LoadModuleStart,
    +[](CNWSModule *pModule, CExoString param_1, int param_2, int param_3, const NWSync::Advertisement &param_4) -> uint32_t
    {
        std::vector<std::string> hakList = String::Split(Config::Get<std::string>("CUSTOM_HAK_LIST", ""), ',');

        if (hakList.empty())
        {
            LOG_INFO("Skipping load of hak files.");
        }

        for (const std::string &hakName: hakList)
        {
            if (Globals::ExoResMan()->AddEncapsulatedResourceFile(CExoString("HAK:") + hakName, RESMAN_PRIORITY_USER_HAK))
            {
                LOG_INFO("Loaded hak %s", hakName);
            }
            else
            {
                LOG_ERROR("Failed to load hak %s", hakName);
                return LOADMODULE_ERROR_COULDNOTLOADHAK;
            }
        }

        Globals::Rules()->ReloadAll();

        return loadModuleStartHook->CallOriginal<uint32_t>(pModule, param_1, param_2, param_3, param_4);
    }, Hooks::Order::Early);
}

}
