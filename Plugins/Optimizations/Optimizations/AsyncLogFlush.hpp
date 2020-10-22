#pragma once

#include "Common.hpp"

namespace Optimizations {

class AsyncLogFlush
{
public:
    AsyncLogFlush(NWNXLib::Services::HooksProxy* hooker, NWNXLib::Services::TasksProxy* tasker);

private:
    static void FlushLogFile_Hook(CExoDebugInternal*);
    static NWNXLib::Services::TasksProxy* s_tasker;
};

}
