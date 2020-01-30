#pragma once

#include "Plugin.hpp"

namespace Experimental {

class SuppressPlayerLoginInfo;
class AsyncLogFlush;
class OptimizeGOA;

class Experimental : public NWNXLib::Plugin
{
public:
    Experimental(const Plugin::CreateParams& params);
    virtual ~Experimental();

private:
    std::unique_ptr<SuppressPlayerLoginInfo> m_SuppressPlayerLoginInfo;
    std::unique_ptr<AsyncLogFlush> m_AsyncLogFlush;
    std::unique_ptr<OptimizeGOA> m_OptimizeGOA;
};

}
