#include "Services/Events/Events.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "Utils.hpp"
#include "../../../Core/NWNXCore.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <sstream>

namespace Core {
extern NWNXCore* g_core;
}

namespace NWNXLib::Services {

std::optional<Events::FunctionCallback> Events::GetEventCallback(const std::string& pluginName, const std::string& eventName)
{
    auto& events = m_eventMap[pluginName];
    auto it = events.find(eventName);
    if (it != events.end())
        return std::make_optional<FunctionCallback>(it->second);

    LOG_DEBUG("Plugin '%s', event '%s' not found, trying dlsym()", pluginName, eventName);

    auto *plugin = NWNXLib::Plugin::Find(pluginName);
    if (!plugin)
        return std::optional<FunctionCallback>();

    void* handle = plugin->GetExportedSymbol(eventName);
    if (!handle)
    {
        LOG_ERROR("Plugin %s does not expose a function named '%s'", pluginName, eventName);
        return std::optional<FunctionCallback>();
    }

    auto cb = FunctionCallback{reinterpret_cast<FunctionCallbackPtr>(handle)};
    RegisterEvent(pluginName, eventName, std::move(cb));
    return std::make_optional<FunctionCallback>(cb);
}

void Events::Call(const std::string& pluginName, const std::string& eventName)
{
    if (auto callback = GetEventCallback(pluginName, eventName))
    {
        LOG_DEBUG("Calling event handler. Event '%s', Plugin: '%s'.", eventName, pluginName);
        try
        {
            m_returns = (*callback)(std::move(m_arguments));
        }
        catch (const std::exception& err)
        {
            LOG_ERROR("Plugin '%s' failed event '%s'. Error: %s", pluginName, eventName, err.what());
        }
    }
    else
    {
        if (!NWNXLib::Plugin::Find(pluginName))
        {
            LOG_ERROR("Plugin '%s' is not loaded but NWScript '%s' tried to call function '%s'.",
                    pluginName, Utils::GetCurrentScript(), eventName);
        }
        else
        {
            LOG_ERROR("Plugin '%s' does not have an event '%s' registered. (NWScript: '%s', are your nwnx_*.nss files up to date?)",
                    pluginName, eventName, Utils::GetCurrentScript());
        }
    }
}


void Events::RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb)
{
    auto& events = m_eventMap[pluginName];

    if (events.count(eventName) == 1)
        throw std::runtime_error("Tried to register an event twice with the same name.");

    events[eventName] = cb;
}

}
