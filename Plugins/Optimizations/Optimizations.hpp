#pragma once

#include "Plugin.hpp"

namespace Optimizations {

class AsyncLogFlush;
class GameObjectLookup;
class ObjectTagLookup;

class Optimizations : public NWNXLib::Plugin
{
public:
    Optimizations(const Plugin::CreateParams& params);
    virtual ~Optimizations();

private:
    std::unique_ptr<AsyncLogFlush> m_AsyncLogFlush;
    std::unique_ptr<GameObjectLookup> m_GameObjectLookup;
    std::unique_ptr<ObjectTagLookup> m_ObjectTagLookup;
};

}
