#pragma once

#include "nwnx.hpp"

namespace Diagnostics {

class MemorySanitizer;

class Diagnostics : public NWNXLib::Plugin
{
public:
    Diagnostics(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Diagnostics();

private:
    std::unique_ptr<MemorySanitizer> m_MemorySanitizer;
};

}
