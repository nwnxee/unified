#include "Resources.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Resources::Resources* g_plugin;

const int RESMAN_PRIORITY_USER_HAK = 31000000;
const int RESMAN_PRIORITY_NWSYNC = 40000000;

const uint32_t LOADMODULE_ERROR_COULDNOTLOADHAK = 2;

const int NWSYNC_STATE_DISCOVERY = 0;   // Currently trying to figure out if we need to do something.

const int NWSYNC_STATE_DOWNLOAD_MANIFEST_META_REQUEST = 5;   // We sent the manifest meta request.
const int NWSYNC_STATE_DOWNLOAD_MANIFEST_META_PROGRESS = 6;   // Waiting for response/downloading.
const int NWSYNC_STATE_DOWNLOAD_MANIFEST_META_PARSE = 7;   // Parsing and configuring metadata.

const int NWSYNC_STATE_DOWNLOAD_MANIFEST_REQUEST = 10;  // We sent the manifest request.
const int NWSYNC_STATE_DOWNLOAD_MANIFEST_PROGRESS = 11;  // Downloading the manifest.
const int NWSYNC_STATE_DOWNLOAD_MANIFEST_PARSE = 12;  // Parsing the manifest in-memory.

const int NWSYNC_STATE_WAIT_PERMISSION_TO_SYNC = 20;  // We're waiting for you/the user to give the go-ahead. Call SetSyncPermission(true) to advance.

const int NWSYNC_STATE_GOT_PERMISSION_TO_SYNC = 21;  // Internal state.

const int NWSYNC_STATE_SYNC_IN_PROGRESS = 100; // We're currently syncing.
const int NWSYNC_STATE_SYNC_IN_PROGRESS_FLUSH = 101; // We're currently flushing to disk.

const int NWSYNC_STATE_HOUSEKEEPING_IN_PROGRESS = 200; // Do some post-transfer cleanup.

const int NWSYNC_STATE_DONE = 800; // Done! Go ahead.
const int NWSYNC_STATE_FAILED = 801; // We aborted. Error will be in currentStateMessage.

static Hooks::Hook s_loadModuleStartHook;
static Hooks::Hook s_readFieldCExoStringHook;
static Hooks::Hook s_GetListHook;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Resources::Resources(services);
    return g_plugin;
}

namespace Resources {

Resources::Resources(Services::ProxyServiceList* services)
: Plugin(services)
{
    s_loadModuleStartHook = Hooks::HookFunction(&CNWSModule::LoadModuleStart, &OnLoadModuleStart, Hooks::Order::Late);
}

uint32_t Resources::OnLoadModuleStart(CNWSModule *pModule, CExoString param_1, int param_2, int param_3, const NWSync::Advertisement &param_4)
{
    bool reloadRequired = false;
    uint32_t retVal = 0;

    if (Config::Get<bool>("USE_CUSTOM_HAK_LIST", false))
    {
        retVal = LoadCustomHakResources();
        if (retVal != 0)
        {
            return retVal;
        }

        s_GetListHook = Hooks::HookFunction(&CResGFF::GetList, &OnGetList, Hooks::Order::Late);
        reloadRequired = true;
    }

    if (Config::Get<bool>("USE_NWSYNC", false))
    {
        retVal = LoadNwSyncResources();
        if (retVal != 0)
        {
            return retVal;
        }

        s_readFieldCExoStringHook = Hooks::HookFunction(&CResGFF::ReadFieldCExoString, &OnReadFieldCExoString, Hooks::Order::Late);
        reloadRequired = true;
    }

    if (reloadRequired)
    {
        Globals::Rules()->ReloadAll();
    }

    return s_loadModuleStartHook->CallOriginal<uint32_t>(pModule, param_1, param_2, param_3, param_4);
}

CExoString Resources::OnReadFieldCExoString(CResGFF *pGff, CResStruct *pStructure, char *szFieldID, BOOL &bSuccess, const CExoString &sDefault)
{
    if (strncmp(pGff->m_pFileType, "IFO", 3) == 0 && strcmp(szFieldID, "Mod_CustomTlk") == 0)
    {
        if (auto tlk = g_plugin->FindNwSyncTlk())
        {
            LOG_INFO("Using TLK file '%s' from NWSync", tlk->CStr());
            bSuccess = true;
            return {*tlk};
        }
    }

    return s_readFieldCExoStringHook->CallOriginal<CExoString>(pGff, pStructure, szFieldID, &bSuccess, &sDefault);
}

int32_t Resources::OnGetList(CResGFF *pGff, CResList *pList, CResStruct *pStructure, char *szFieldID)
{
    if (strncmp(pGff->m_pFileType, "IFO", 3) == 0 && strcmp(szFieldID, "Mod_HakList") == 0)
    {
        return false;
    }

    return s_GetListHook->CallOriginal<int32_t>(pGff, pList, pStructure, szFieldID);
}

uint32_t Resources::LoadNwSyncResources()
{
    auto host = Config::Get<std::string>("NWSYNC_HOST");
    auto manifest = Config::Get<std::string>("NWSYNC_MANIFEST");

    if (!host || !manifest)
    {
        LOG_WARNING("Missing NWSync host/manifest variables. Skipping sync.");
        return 0;
    }

    LOG_INFO("Loading NWSync manifest '%s/%s'", host.value(), manifest.value());

    const auto &hashString = CExoString(manifest.value());
    const auto &hash = Hash::SHA1{hashString};

    NWSync::CNWCSync cli(host->c_str(), hash, "", "");
    auto &status = cli.GetStatus();

    while (true)
    {
        HttpConnection::UpdateAll();
        cli.Update();

        if (status.m_currentState == NWSYNC_STATE_WAIT_PERMISSION_TO_SYNC)
        {
            cli.SetSyncPermission(true);
            continue;
        }

        ShowNWSyncProgressUpdate(status, false);

        if (status.m_currentState >= NWSYNC_STATE_DONE)
        {
            break;
        }

        if (status.m_currentState == NWSYNC_STATE_SYNC_IN_PROGRESS)
        {
            // libcurl is happy to do the heavy lifting async
            usleep(250);
        }
    }

    if (status.m_currentState != NWSYNC_STATE_DONE)
    {
        LOG_ERROR("Failed to load NWSync manifest '%s/%s'", host.value(), manifest.value());
        return LOADMODULE_ERROR_COULDNOTLOADHAK;
    }

    Globals::ExoResMan()->AddManifest(hash, RESMAN_PRIORITY_NWSYNC);
    Globals::Rules()->ReloadAll();

    return 0;
}

uint32_t Resources::LoadCustomHakResources()
{
    auto hakListStr = Config::Get<std::string>("CUSTOM_HAK_LIST", "");
    std::vector<std::string> hakList = String::Split(hakListStr, ',');

    if (!hakList.empty())
    {
        LOG_INFO("Using custom hak list: %s", hakListStr);
    }
    else
    {
        LOG_INFO("Skipping load of all hak files");
    }

    for (const std::string &hakName: hakList)
    {
        if (Globals::ExoResMan()->AddEncapsulatedResourceFile(CExoString("HAK:") + hakName, RESMAN_PRIORITY_USER_HAK))
        {
            LOG_INFO("Loaded hak '%s'", hakName);
        }
        else
        {
            LOG_ERROR("Failed to load hak '%s'", hakName);
            return LOADMODULE_ERROR_COULDNOTLOADHAK;
        }
    }

    return 0;
}

CExoString* Resources::FindNwSyncTlk()
{
    if (auto *pList = Globals::ExoResMan()->GetResOfType(Constants::ResRefType::TLK, false))
    {
        if (pList->m_nCount > 0)
        {
            // We can only load 1 custom tlk, so just use the first one we find.
            return pList->m_pStrings[0];
        }
    }

    return nullptr;
}

void Resources::ShowNWSyncProgressUpdate(const NWSync::CNWCSync::Progress &progress, bool force)
{
    if (progress.m_currentState == NWSYNC_STATE_SYNC_IN_PROGRESS_FLUSH)
        return;

    static int lastState = -1;
    static CExoString lastMsg;

    static int last = 0;
    const int now = time(0);

    CExoString bytesRemainingStr;
    CExoString rateStr;
    CExoString etaStr;

    const uint64_t bytesRemaining = progress.m_allFilesBytesTotal ? progress.m_allFilesBytesTotal - progress.m_allFilesBytesTransferred : 0;

    if (progress.m_allFilesBytesTotal > 0)
        bytesRemainingStr.Format("%s", CExoString::FormatBytes(bytesRemaining).CStr());

    if (progress.m_allFilesBytesTransferred > 0 && progress.m_averageNetworkBps)
        rateStr.Format(" @ %s/s", CExoString::FormatBytes(progress.m_averageNetworkBps).CStr());

    const uint64_t secondsRemaining = bytesRemaining > 0 && progress.m_averageNetworkBps > 0 ? bytesRemaining / progress.m_averageNetworkBps : 0;

    if (secondsRemaining > 0)
        etaStr.Format("%s", CExoString::FormatDuration(secondsRemaining).CStr());

    CExoString thisMsg;
    thisMsg.Format("%-25s %-5s %10s%-15s %-8s   %s",
    NWSyncStateToStr(progress.m_currentState),
    progress.m_currentStateMessage.CStr(),
    bytesRemainingStr.CStr(),
    rateStr.CStr(),
    etaStr.CStr(),
    progress.m_currentTransferMessage.CStr());

    if (force || lastState != progress.m_currentState || now - last > 1)
    {
        if (lastMsg != thisMsg)
        {
            LOG_INFO("nwsync: %s", thisMsg.CStr());
            lastMsg = thisMsg;
        }

        last = now;
    }

    lastState = progress.m_currentState;
}

const char* Resources::NWSyncStateToStr(const int state)
{
    if (state == NWSYNC_STATE_DISCOVERY) return "Discovery";
    else if (state == NWSYNC_STATE_DOWNLOAD_MANIFEST_REQUEST) return "Requesting Manifest";
    else if (state == NWSYNC_STATE_DOWNLOAD_MANIFEST_PROGRESS) return "Downloading Manifest";
    else if (state == NWSYNC_STATE_DOWNLOAD_MANIFEST_PARSE) return "Verifying Existing Data";
    else if (state == NWSYNC_STATE_WAIT_PERMISSION_TO_SYNC) return "Waiting for Permission";
    else if (state == NWSYNC_STATE_GOT_PERMISSION_TO_SYNC) return "Got Permission Response";
    else if (state == NWSYNC_STATE_SYNC_IN_PROGRESS) return "Sync In Progress";
    else if (state == NWSYNC_STATE_SYNC_IN_PROGRESS_FLUSH) return "Sync In Progress (Waiting On Storage)";
    else if (state == NWSYNC_STATE_HOUSEKEEPING_IN_PROGRESS) return "Housekeeping";
    else if (state == NWSYNC_STATE_DONE) return "Done";
    else if (state == NWSYNC_STATE_FAILED) return "FAILED";
    else return "?";
}

}
