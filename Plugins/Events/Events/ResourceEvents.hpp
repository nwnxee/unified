#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"

#include <thread>

namespace Events {

class ResourceEvents
{
public:
    ResourceEvents(NWNXLib::Services::TasksProxy* tasks);
    virtual ~ResourceEvents();

private:
    static std::unique_ptr<std::thread> m_pollThread;
};

}
