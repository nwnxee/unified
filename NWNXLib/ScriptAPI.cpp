#include "nwnx.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"

#include <algorithm>
#include <array>
#include <cstring>
#include <sstream>


namespace NWNXLib::ScriptAPI
{
ArgumentStack s_arguments;
ArgumentStack s_returns;

using PluginEventMap = std::unordered_map<std::string, ScriptAPI::FunctionCallback>;
static std::unordered_map<std::string, PluginEventMap> s_eventMap;

std::optional<ScriptAPI::FunctionCallback> GetEventCallback(const std::string& pluginName, const std::string& eventName)
{
    auto& events = s_eventMap[pluginName];
    auto it = events.find(eventName);
    if (it != events.end())
        return std::make_optional<FunctionCallback>(it->second);

    LOG_DEBUG("Plugin '%s', event '%s' not found, trying dlsym()", pluginName, eventName);

    auto *plugin = Plugin::Find(pluginName);
    if (!plugin)
        return std::optional<FunctionCallback>();

    void* handle = plugin->GetExportedSymbol(eventName);
    if (!handle)
    {
        LOG_ERROR("Plugin %s does not expose a function named '%s'", pluginName, eventName);
        return std::optional<FunctionCallback>();
    }

    using FunctionCallbackPtr = ArgumentStack(*)(ArgumentStack&&);
    auto cb = FunctionCallback{reinterpret_cast<FunctionCallbackPtr>(handle)};
    RegisterEvent(pluginName, eventName, std::move(cb));
    return std::make_optional<FunctionCallback>(cb);
}

void Call(const std::string& pluginName, const std::string& eventName)
{
    INSTR_SCOPE();
    INSTR_SCOPE_PROP_STR("Plugin", pluginName.c_str());
    INSTR_SCOPE_PROP_STR("Function", eventName.c_str());

    if (auto callback = GetEventCallback(pluginName, eventName))
    {
        LOG_DEBUG("Calling event handler. Event '%s', Plugin: '%s'.", eventName, pluginName);
        try
        {
            s_returns = (*callback)(std::move(s_arguments));
        }
        catch (const std::exception& err)
        {
            LOG_ERROR("Plugin '%s' failed event '%s'. Error: %s", pluginName, eventName, err.what());
        }

        if (!s_arguments.empty())
        {
            LOG_WARNING("Argument stack not empty after running %s::%s from %s.ncs. Discarding unused arguments",
                pluginName, eventName, Utils::GetCurrentScript());
            while (!s_arguments.empty())
            {
                LOG_DEBUG("Discarding argument '%s'", s_arguments.top().toString());
                s_arguments.pop();
            }
        }
    }
    else
    {
        if (!Plugin::Find(pluginName))
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


void RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb)
{
    auto& events = s_eventMap[pluginName];

    if (events.count(eventName) == 1)
    {
        std::string str = pluginName + "::" + eventName;
        str += " - Tried to register an event twice with the same name.";
        throw std::runtime_error(str.c_str());
    }

    events[eventName] = cb;
}

}
