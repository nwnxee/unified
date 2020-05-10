#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Test
{
class Test : public NWNXLib::Plugin
{
public:
    Test(const Plugin::CreateParams& params);
    virtual ~Test();
    
};

} // namespace Test
