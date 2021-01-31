#include "Optimizations/AsyncLogFlush.hpp"

#include "API/Functions.hpp"
#include "API/CExoDebugInternal.hpp"
#include "API/CExoFile.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

AsyncLogFlush::AsyncLogFlush()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(API::Functions::_ZN17CExoDebugInternal12FlushLogFileEv, (void*)&FlushLogFile_Hook, Hooks::Order::Final);
}

void AsyncLogFlush::FlushLogFile_Hook(CExoDebugInternal* pThis)
{
    // Rotating log file, do synchronously
    if (pThis->m_bRotateLogFile && ((pThis->m_nCurrentLogSize << 2) > pThis->m_nMaxLogSize))
    {
        pThis->m_pLogFile->Flush();
        return;
    }

    if (pThis->m_bFilesOpen)
    {
        Tasks::QueueOnAsyncThread([pThis](){ pThis->m_pLogFile->Flush(); });
    }
}

}
