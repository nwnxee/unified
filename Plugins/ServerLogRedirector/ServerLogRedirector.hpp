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
    static void WriteToLogFileHook(bool, CExoDebugInternal*, CExoString*);
    static void WriteToErrorFileHook(bool, CExoDebugInternal*, CExoString*);
};

}
