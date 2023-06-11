#pragma once

#include "nwnx.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoString.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWCSync.hpp"
#include "API/CNWRules.hpp"
#include "API/SHA1.hpp"
#include "API/HttpConnection.hpp"
#include "API/NWSyncAdvertisement.hpp"
#include "API/CExoStringList.hpp"

#include <unistd.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Resources {

class Resources : public NWNXLib::Plugin
{
public:
    Resources(NWNXLib::Services::ProxyServiceList* services);

private:
    uint32_t LoadNwSyncResources();
    uint32_t LoadCustomHakResources();

    void ShowNWSyncProgressUpdate(const NWSync::CNWCSync::Progress &progress, bool force);
    CExoString* FindNwSyncTlk();
    const char *NWSyncStateToStr(int state);

    static uint32_t OnLoadModuleStart(CNWSModule *pModule, CExoString param_1, int param_2, int param_3, const NWSync::Advertisement &param_4);
    static CExoString OnReadFieldCExoString(CResGFF *pGff, CResStruct *pStructure, char *szFieldID, BOOL &bSuccess, const CExoString &sDefault = "");
    static int32_t OnGetList(CResGFF *pGff, CResList *pList, CResStruct *pStructure, char *szFieldID);
};

}
