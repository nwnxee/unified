#pragma once

#include "Plugin.hpp"

namespace SWIG_DotNET
{

class SWIG_DotNET : public NWNXLib::Plugin
{
public:
    SWIG_DotNET(NWNXLib::Services::ProxyServiceList* services);
    virtual ~SWIG_DotNET() {}
};

} // namespace SWIG_DotNET
