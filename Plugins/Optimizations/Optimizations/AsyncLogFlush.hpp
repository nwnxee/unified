#pragma once

#include "nwnx.hpp"

namespace Optimizations {

class AsyncLogFlush
{
public:
    AsyncLogFlush();

private:
    static void FlushLogFile_Hook(CExoDebugInternal*);
};

}
