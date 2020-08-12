#!/bin/bash

# Usage: bootstrap_plugin.sh PluginName
#
# A simple script to bootstrap new plugins.  Where ever the script
# is run their must be a Plugins subdirectory.  For example in the
# main directory of the NWNX repository.

if [ $# -ne 1 ]; then
    echo $0: usage: bootstrap_plugin.sh PluginName
    exit 1
fi

pname="$1"
lower_case=`echo $1 | tr '[:upper:]' '[:lower:]'`

if [ -d "Plugins/$1" ]; then
    echo Directory "Plugins/$1" already exists!
    exit 1
fi

if mkdir "Plugins/$1"; then
    echo Generating plugin $1...
else
    echo Unbale to create directory "Plugins/$1"!
    exit 1
fi

cat > "Plugins/$1/CMakeLists.txt" <<-EOT
add_plugin($1 $1.cpp)
EOT

cat > "Plugins/$1/README.md" <<-EOT
@page $lower_case Readme
@ingroup $lower_case

## Environment Variables

| Variable Name            |  Type  | Default Value |
| -------------------------| :----: | ------------- |
| none                     |        |               |
EOT

cat > "Plugins/$1/$1.hpp" <<-EOT
#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace $1
{

class $1 : public NWNXLib::Plugin
{
public:
    $1(NWNXLib::Services::ProxyServiceList* services);
    virtual ~$1() {}
};

} // namespace $1
EOT

cat > "Plugins/$1/$1.cpp" <<-EOT
#include "$1.hpp"

#include "Services/Hooks/Hooks.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static $1::$1* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new $1::$1(services);
    return g_plugin;
}


namespace $1
{

$1::$1(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func)              \\
    GetServices()->m_events->RegisterEvent(#func, \\
        [this](ArgumentStack&& args){ return func(std::move(args)); })
    // No blades, no bows: Put your NWScript Events here.
#undef REGISTER
}

}
EOT
