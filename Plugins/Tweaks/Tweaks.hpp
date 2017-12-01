#pragma once

#include "Plugin.hpp"

namespace Tweaks {

class Tweaks : public NWNXLib::Plugin
{
public:
    Tweaks(const Plugin::CreateParams& params);
    virtual ~Tweaks();
};

}
