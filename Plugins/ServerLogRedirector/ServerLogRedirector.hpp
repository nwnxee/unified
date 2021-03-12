#pragma once

#include "nwnx.hpp"

namespace ServerLogRedirector {

class ServerLogRedirector : public NWNXLib::Plugin
{
public:
    ServerLogRedirector(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ServerLogRedirector();

private:
    static void WriteToLogFileHook(CExoDebugInternal*, CExoString*);
    static void WriteToErrorFileHook(CExoDebugInternal*, CExoString*);
};

}
