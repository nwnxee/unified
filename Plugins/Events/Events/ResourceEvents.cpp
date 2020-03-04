#include "Events/ResourceEvents.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoResMan.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"

#include <sys/inotify.h>
#include <unistd.h>
#include <poll.h>
#include <climits>
#include <fcntl.h>

namespace Core {
    extern bool g_CoreShuttingDown;
}

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

#define EVENT_SIZE          ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN       ( 128 * ( EVENT_SIZE + NAME_MAX + 1) )

static bool processEvents;
static int selfPipeFds[2];
std::unique_ptr<std::thread> ResourceEvents::m_pollThread;

ResourceEvents::ResourceEvents(Services::TasksProxy* tasks)
{
    Events::InitOnFirstSubscribe("NWNX_ON_RESOURCE_.*", [tasks]()
    {
        int ret = pipe2(selfPipeFds, O_NONBLOCK);

        if (ret == -1)
        {
            LOG_ERROR("Failed to initialize self-pipe with error: %s", std::strerror(errno));
            return;
        }

        int pipeReadFd = selfPipeFds[0];
        CExoString exoPath = Globals::ExoBase()->m_pcExoAliasList->GetAliasPath("NWNX");
        std::string path = exoPath.CStr();

        m_pollThread = std::make_unique<std::thread>([tasks, path, pipeReadFd]()
        {
            struct pollfd fds[2];
            char buffer[EVENT_BUF_LEN];

            fds[0].fd = pipeReadFd;
            fds[0].events = POLLIN;

            int fd = inotify_init1(IN_NONBLOCK), wd = 0;

            if (fd != -1)
            {
                fds[1].fd = fd;
                fds[1].events = POLLIN;

                wd = inotify_add_watch(fd, path.c_str(), IN_CREATE | IN_DELETE | IN_MODIFY);

                if (wd != -1)
                {
                    processEvents = true;
                }
            }

            auto ProcessEvent = [tasks](const std::string &eventType, const std::string &file) -> void
            {
                tasks->QueueOnMainThread([eventType, file]()
                {
                    if (Core::g_CoreShuttingDown)
                        return;

                    LOG_DEBUG("EventType: %s, File: %s", eventType, file);

                    uint16_t resType = Globals::ExoResMan()->GetResTypeFromFile(file);

                    if (resType != 65535)
                    {
                        CResRef resRef;
                        Globals::ExoResMan()->GetResRefFromFile(resRef, file);

                        Events::PushEventData("RESREF", resRef.GetResRefStr());
                        Events::PushEventData("TYPE", std::to_string(resType));
                        Events::SignalEvent("NWNX_ON_RESOURCE_" + eventType, Utils::GetModule()->m_idSelf);
                    }
                });
            };

            while (processEvents)
            {
                int pollNum = poll(fds, 2, -1);

                if (pollNum > 0)
                {
                    if (fds[1].revents & POLLIN)
                    {
                        size_t length = read(fd, buffer, EVENT_BUF_LEN);

                        if (length > 0)
                        {
                            for (size_t i = 0; i < length;)
                            {
                                auto *event = reinterpret_cast<inotify_event *>(&buffer[i]);

                                if (event->len)
                                {
                                    if (event->mask & IN_MODIFY)
                                    {
                                        ProcessEvent("MODIFIED", event->name);
                                    }
                                    else
                                    if (event->mask & IN_CREATE)
                                    {
                                        ProcessEvent("ADDED", event->name);
                                    }
                                    else
                                    if (event->mask & IN_DELETE)
                                    {
                                        ProcessEvent("REMOVED", event->name);
                                    }
                                }

                                i += (EVENT_SIZE + event->len);
                            }
                        }
                    }
                }
            }

            if (wd != -1)
                inotify_rm_watch(fd, wd);
            if (fd != -1)
                close(fd);
        });
    });
}

ResourceEvents::~ResourceEvents()
{
    processEvents = false;

    if (m_pollThread)
    {
        int ret = write(selfPipeFds[1], "a", 1);
        (void)ret;

        m_pollThread->join();

        close(selfPipeFds[0]);
        close(selfPipeFds[1]);
    }
}

}
