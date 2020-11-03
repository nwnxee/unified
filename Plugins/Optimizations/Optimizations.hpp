#pragma once

#include "Plugin.hpp"

namespace Optimizations {

class AsyncLogFlush;
class GameObjectLookup;

class Optimizations : public NWNXLib::Plugin
{
public:
    Optimizations(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Optimizations();

private:
    std::unique_ptr<AsyncLogFlush> m_AsyncLogFlush;
    std::unique_ptr<GameObjectLookup> m_GameObjectLookup;
};

}
