#include "Events.hpp"
#include "../../../Core/NWNXCore.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoResMan.hpp"

#include <sys/inotify.h>
#include <unistd.h>
#include <poll.h>
#include <climits>
#include <fcntl.h>
#include <thread>

namespace Core {
    extern NWNXCore* g_core;
    extern bool g_CoreShuttingDown;
}

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

constexpr int EVENT_SIZE    = sizeof(struct inotify_event);
constexpr int EVENT_BUF_LEN = (128 * (EVENT_SIZE + NAME_MAX + 1));

static volatile bool s_processEvents;
static int s_selfPipeFds[2];
static std::unique_ptr<std::thread> s_pollThread;

void ResourceEvents() __attribute__((constructor));
void ResourceEvents()
{
    InitOnFirstSubscribe("NWNX_ON_RESOURCE_.*", []()
    {
        int ret = pipe2(s_selfPipeFds, O_NONBLOCK);
        int pipeReadFd = s_selfPipeFds[0];

        if (ret == -1)
        {
            LOG_ERROR("Failed to initialize self-pipe with error: %s", std::strerror(errno));
            return;
        }

        std::unordered_map<std::string, std::string> paths;

        auto AddAlias = [&](const std::string& alias)
        {
            CExoString path = Globals::ExoBase()->m_pcExoAliasList->GetAliasPath(alias);

            if (!path.IsEmpty())
            {
                LOG_DEBUG("Adding path '%s' for alias '%s'", path, alias);
                paths.emplace(alias, path.CStr());
            }
        };

        // Add all the custom resource directories
        for (auto &alias : Core::g_core->GetCustomResourceDirectoryAliases())
        {
            AddAlias(alias);
        }

        // Manually add DEVELOPMENT
        AddAlias("DEVELOPMENT");

        s_pollThread = std::make_unique<std::thread>([pipeReadFd, paths]()
        {
            auto QueueLogMessage = [](const std::string &message, bool warn = true)
            {
                Tasks::QueueOnMainThread([message, warn]()
                {
                    if (warn)
                        LOG_WARNING("%s", message);
                    else
                        LOG_ERROR("%s", message);
                });
            };

            struct pollfd fds[2];
            char buffer[EVENT_BUF_LEN];
            std::unordered_map<int, std::string> aliases;
            int inotifyFd = inotify_init1(IN_NONBLOCK);

            if (inotifyFd != -1)
            {
                fds[0].fd = pipeReadFd;
                fds[0].events = POLLIN;

                fds[1].fd = inotifyFd;
                fds[1].events = POLLIN;

                for (const auto& path : paths)
                {
                    int wd = inotify_add_watch(inotifyFd, path.second.c_str(), IN_CREATE | IN_DELETE | IN_CLOSE_WRITE);

                    if (wd != -1)
                        aliases[wd] = path.first;
                    else
                        QueueLogMessage("Failed to add inotify watch for alias '" + path.first + ":" + path.second + "' with error: " + std::string(std::strerror(errno)));
                }

                if (!aliases.empty())
                {
                    s_processEvents = true;
                }
            }
            else
                QueueLogMessage("Failed to intialize inotify with error: " + std::string(std::strerror(errno)), false);

            while (s_processEvents)
            {
                int pollNum = poll(fds, 2, -1);

                if (pollNum > 0)
                {
                    if (fds[1].revents & POLLIN)
                    {
                        std::vector<std::tuple<std::string, std::string, std::string>> events;
                        size_t length = read(inotifyFd, buffer, EVENT_BUF_LEN);

                        size_t i = 0;
                        while (i < length)
                        {
                            auto *event = reinterpret_cast<inotify_event *>(&buffer[i]);

                            if (event->len)
                            {
                                if (event->mask & IN_CLOSE_WRITE)
                                {
                                    events.emplace_back(event->name, aliases[event->wd], "MODIFIED");
                                }
                                else if (event->mask & IN_CREATE)
                                {
                                    events.emplace_back(event->name, aliases[event->wd], "ADDED");
                                }
                                else if (event->mask & IN_DELETE)
                                {
                                    events.emplace_back(event->name, aliases[event->wd], "REMOVED");
                                }
                            }

                            i += (EVENT_SIZE + event->len);
                        }

                        std::this_thread::sleep_for(std::chrono::seconds(1));

                        Tasks::QueueOnMainThread([events]()
                        {
                            if (Core::g_CoreShuttingDown)
                                return;

                            for (const auto&[file, alias, event] : events)
                            {
                                LOG_DEBUG("File '%s' was '%s' in alias '%s'", file, event, alias);

                                uint16_t resType = Globals::ExoResMan()->GetResTypeFromFile(file);

                                if (resType != 65535)
                                {
                                    CResRef resRef;
                                    Globals::ExoResMan()->GetResRefFromFile(resRef, file);

                                    PushEventData("ALIAS", alias);
                                    PushEventData("RESREF", resRef.GetResRefStr());
                                    PushEventData("TYPE", std::to_string(resType));

                                    SignalEvent("NWNX_ON_RESOURCE_" + event, Utils::GetModule()->m_idSelf);
                                }
                            }
                        });
                    }
                }
            }

            if (inotifyFd != -1)
            {
                for (const auto& alias : aliases)
                {
                    inotify_rm_watch(inotifyFd, alias.first);
                }

                close(inotifyFd);
            }
        });
    });

    MessageBus::Subscribe("NWNX_CORE_SIGNAL",
        [](const std::vector<std::string>& message)
        {
            if (message[0] == "ON_DESTROY_SERVER")
            {
                s_processEvents = false;

                if (s_pollThread)
                {
                    (void)!write(s_selfPipeFds[1], "a", 1);

                    s_pollThread->join();

                    close(s_selfPipeFds[0]);
                    close(s_selfPipeFds[1]);
                }
            }
        });
}

}
