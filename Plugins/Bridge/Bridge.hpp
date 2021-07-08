#pragma once

#include "Common.hpp"
#include "Plugin.hpp"
#include "BridgeClient.hpp"
#include "BridgeWebserver.hpp"

namespace NWNXLib::Hooking { class FunctionHook; }

namespace Bridge
{

    class Bridge : public NWNXLib::Plugin
    {
    public:
        Bridge(const Plugin::CreateParams& params);
        BridgeClient* GetBridgeInstance() { return m_bridgeInstance.get(); }
        Webserver* GetWebserverInstance() { return m_webserverInstance.get(); }
        bool IsConnected();
        virtual ~Bridge();

    private:
        bool m_isClient = true;
        std::unique_ptr<BridgeClient> m_bridgeInstance = nullptr;
        std::unique_ptr<Webserver> m_webserverInstance = nullptr;
    };

}
