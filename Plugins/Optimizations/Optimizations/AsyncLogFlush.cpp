#include "Optimizations/AsyncLogFlush.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "API/Functions.hpp"
#include "API/CExoDebugInternal.hpp"
#include "API/CExoFile.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Services::TasksProxy* AsyncLogFlush::s_tasker;
AsyncLogFlush::AsyncLogFlush(Services::HooksProxy* hooker, Services::TasksProxy* tasker)
{
    s_tasker = tasker;
    hooker->RequestExclusiveHook<API::Functions::_ZN17CExoDebugInternal12FlushLogFileEv>
        (&FlushLogFile_Hook);
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
        s_tasker->QueueOnAsyncThread([pThis](){ pThis->m_pLogFile->Flush(); });
    }
}

}
