#include "Events/ResourceEvents.hpp"
#include "../../../Core/NWNXCore.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoResMan.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"

#include <sys/inotify.h>
#include <unistd.h>
#include <poll.h>
#include <climits>
#include <fcntl.h>

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

static volatile bool processEvents;
static int selfPipeFds[2];

std::unique_ptr<std::thread> ResourceEvents::m_pollThread;

ResourceEvents::ResourceEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_RESOURCE_.*", []()
    {
        int ret = pipe2(selfPipeFds, O_NONBLOCK);
        int pipeReadFd = selfPipeFds[0];

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

        m_pollThread = std::make_unique<std::thread>([pipeReadFd, paths]()
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
                    processEvents = true;
                }
            }
            else
                QueueLogMessage("Failed to intialize inotify with error: " + std::string(std::strerror(errno)), false);

            while (processEvents)
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

                                    Events::PushEventData("ALIAS", alias);
                                    Events::PushEventData("RESREF", resRef.GetResRefStr());
                                    Events::PushEventData("TYPE", std::to_string(resType));

                                    Events::SignalEvent("NWNX_ON_RESOURCE_" + event, Utils::GetModule()->m_idSelf);
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
}

ResourceEvents::~ResourceEvents()
{
    processEvents = false;

    if (m_pollThread)
    {
        (void)write(selfPipeFds[1], "a", 1);

        m_pollThread->join();

        close(selfPipeFds[0]);
        close(selfPipeFds[1]);
    }
}

}
