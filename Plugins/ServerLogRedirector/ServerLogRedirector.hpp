#pragma once

#include "Plugin.hpp"
#include "API/CExoDebugInternal.hpp"
#include "API/CExoString.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <memory>

namespace ServerLogRedirector {

class ServerLogRedirector : public NWNXLib::Plugin
{
public:
    ServerLogRedirector(const Plugin::CreateParams& params);
    virtual ~ServerLogRedirector();

private:
    static void WriteToLogFileHook(NWNXLib::Services::Hooks::CallType,
        CExoDebugInternal*, CExoString*);
    static void WriteToErrorFileHook(NWNXLib::Services::Hooks::CallType,
        CExoDebugInternal*, CExoString*);
};

}
