#pragma once

#include "Plugin.hpp"

namespace Tweaks {

class HideClassesOnCharList;

class Tweaks : public NWNXLib::Plugin
{
public:
    Tweaks(const Plugin::CreateParams& params);
    virtual ~Tweaks();

private:
    std::unique_ptr<HideClassesOnCharList> m_HideClassesOnCharlist;
};

}
