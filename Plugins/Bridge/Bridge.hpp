#pragma once

#include "Common.hpp"
#include "Plugin.hpp"
#include "BridgeClient.hpp"

namespace NWNXLib::Hooking { class FunctionHook; }

namespace Bridge
{

    class Bridge : public NWNXLib::Plugin
    {
    public:
        Bridge(const Plugin::CreateParams& params);
        BridgeClient* GetInstance() { return instance.get(); }
        bool IsConnected();
        virtual ~Bridge();

    private:
        bool m_isClient = true;
        std::unique_ptr<BridgeClient> instance = nullptr;
    };

}
