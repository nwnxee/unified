#include "nwnx.hpp"

#include "API/CExoResMan.hpp"
#include "API/CExoString.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWCSync.hpp"
#include "API/CNWRules.hpp"
#include "API/SHA1.hpp"
#include "API/HttpConnection.hpp"
#include "API/NWSyncAdvertisement.hpp"

#include <unistd.h>

namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

const int RESMAN_PRIORITY_NWSYNC = 40000000;

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

void ShowScreenUpdate(const NWSync::CNWCSync::Progress &progress, bool force);

const char *NWSyncStateToStr(const int state);

void LoadNwSyncManifest() __attribute__((constructor));

void LoadNwSyncManifest()
{
    if (!Config::Get<bool>("LOAD_NWSYNC_MANIFEST", false))
        return;

    static Hooks::Hook loadModuleStartHook = Hooks::HookFunction(&CNWSModule::LoadModuleStart,
    +[](CNWSModule *pModule, CExoString param_1, int param_2, int param_3, const NWSync::Advertisement &param_4) -> uint32_t
    {
        auto host = Config::Get<std::string>("NWSYNC_HOST");
        auto manifest = Config::Get<std::string>("NWSYNC_MANIFEST");

        if (!host || !manifest)
        {
            LOG_WARNING("Missing host/manifest variables. Skipping sync.");
            return loadModuleStartHook->CallOriginal<uint32_t>(pModule, param_1, param_2, param_3, param_4);
        }

        LOG_INFO("Loading nwsync manifest %s/%s", host.value(), manifest.value());

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

            ShowScreenUpdate(status, false);

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

        ASSERT_OR_THROW(status.m_currentState == NWSYNC_STATE_DONE);
        Globals::ExoResMan()->AddManifest(hash, RESMAN_PRIORITY_NWSYNC);
        Globals::Rules()->ReloadAll();

        return loadModuleStartHook->CallOriginal<uint32_t>(pModule, param_1, param_2, param_3, param_4);
    }, Hooks::Order::Early);
}

void ShowScreenUpdate(const NWSync::CNWCSync::Progress &progress, bool force)
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

const char *NWSyncStateToStr(const int state)
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
