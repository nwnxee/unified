#pragma once

namespace NWNXLib
{
namespace Services
{
class HooksProxy;
}
}

class CServerExoApp;

namespace Bridge
{
class Bridge;

class Hooks
{
public:
    static void InitHooks(Bridge* bridge, NWNXLib::Services::HooksProxy* hooker);
private:
    static Bridge* s_bridge;
    static void CServerExoApp__MainLoop(bool before, CServerExoApp*);
};
}