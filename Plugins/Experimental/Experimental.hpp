#pragma once

#include "Plugin.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo;

class Experimental : public NWNXLib::Plugin
{
public:
    Experimental(const Plugin::CreateParams& params);
    virtual ~Experimental();

private:
    std::unique_ptr<SuppressPlayerLoginInfo> m_SuppressPlayerLoginInfo;
};

}
