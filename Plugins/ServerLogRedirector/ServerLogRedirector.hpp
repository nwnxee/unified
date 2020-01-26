#pragma once

#include "Plugin.hpp"

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
