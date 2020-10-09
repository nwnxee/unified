#pragma once

#include "Plugin.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo;

class Experimental : public NWNXLib::Plugin
{
public:
    Experimental(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Experimental();

private:
    std::unique_ptr<SuppressPlayerLoginInfo> m_SuppressPlayerLoginInfo;
};

}
