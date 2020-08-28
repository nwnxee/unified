#pragma once

#include "Plugin.hpp"

namespace ServerLogRedirector {

class ServerLogRedirector : public NWNXLib::Plugin
{
public:
    ServerLogRedirector(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ServerLogRedirector();

private:
    static void WriteToLogFileHook(bool, CExoDebugInternal*, CExoString*);
    static void WriteToErrorFileHook(bool, CExoDebugInternal*, CExoString*);
};

}
