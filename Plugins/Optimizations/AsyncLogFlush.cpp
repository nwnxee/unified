#include "nwnx.hpp"

#include "API/CExoDebugInternal.hpp"
#include "API/CExoFile.hpp"

namespace Optimizations {

using namespace NWNXLib;

void AsyncLogFlush() __attribute__((constructor));
void AsyncLogFlush()
{
    if (Config::Get<bool>("ASYNC_LOG_FLUSH", false))
    {
        LOG_INFO("Game logs will be flushed asynchronously");
        static auto s_FlushLogFile = Hooks::HookFunction(&CExoDebugInternal::FlushLogFile,
            +[](CExoDebugInternal* pThis)
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
            }, Hooks::Order::Final);
    }
}

}
