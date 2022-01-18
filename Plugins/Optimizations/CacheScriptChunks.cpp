#include "nwnx.hpp"

#include "API/CVirtualMachine.hpp"
#include "API/CScriptCompiler.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unordered_map<std::string, DataBlockRef> s_CachedScriptChunks;

void CacheScriptChunks() __attribute__((constructor));
void CacheScriptChunks()
{
    if (Config::Get<bool>("CACHE_SCRIPT_CHUNKS", false))
    {
        LOG_INFO("Caching script chunks");

        static Hooks::Hook s_SetUpJITCompiledScript = Hooks::HookFunction(API::Functions::_ZN15CVirtualMachine22SetUpJITCompiledScriptERK10CExoStringi,
        (void*)+[](CVirtualMachine *pVirtualMachine, const CExoString& sScriptChunk, BOOL bWrapIntoMain) -> int32_t
        {
            pVirtualMachine->m_nRecursionLevel += 1;
            if (pVirtualMachine->m_nRecursionLevel >= 8)
            {
                --pVirtualMachine->m_nRecursionLevel;
                return -633;
            }

            auto cachedScript = s_CachedScriptChunks.find(sScriptChunk.CStr());
            if (cachedScript != s_CachedScriptChunks.end())
            {
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = "Chunk";
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = 0;
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], cachedScript->second);
                return 0;
            }

            int32_t nReturnValue = pVirtualMachine->m_pJitCompiler->CompileScriptChunk(sScriptChunk, bWrapIntoMain);
            if (nReturnValue < 0)
            {
                --pVirtualMachine->m_nRecursionLevel;
                return nReturnValue;
            }

            char *pScriptData;
            int32_t nScriptDataSize;
            pVirtualMachine->m_pJitCompiler->GetCompiledScriptCode(&pScriptData, &nScriptDataSize);

            if (pScriptData[0] == 'N' && pScriptData[1] == 'C' && pScriptData[2] == 'S' && pScriptData[3] == ' ' &&
                pScriptData[4] == 'V' && pScriptData[6] == '.' && pScriptData[8] == 'B')
            {
                int32_t nVersion = 0;
                if (pScriptData[5] >= '1' && pScriptData[5] <= '9')
                    nVersion += (pScriptData[5] - '0') * 10;
                if (pScriptData[7] >= '1' && pScriptData[7] <= '9')
                    nVersion += pScriptData[7] - '0';
                if (nVersion != 10)
                {
                    --pVirtualMachine->m_nRecursionLevel;
                    return -635;
                }

                pScriptData += 13;
                nScriptDataSize -= 13;

                DataBlockRef pScriptDataBlock = std::make_shared<DataBlock>();
                pScriptDataBlock->Append(pScriptData, nScriptDataSize);

                s_CachedScriptChunks[sScriptChunk.CStr()] = pScriptDataBlock;

                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = "Chunk";
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = 0;
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], pScriptDataBlock);
                return 0;
            }

            --pVirtualMachine->m_nRecursionLevel;
            return -635;
        }, Hooks::Order::Final);

        Tasks::QueueOnMainThread([](){ Globals::VirtualMachine()->m_pJitCompiler->SetOptimizeBinaryCodeLength(true); });
    }
}

// No nwscript export, call it manually.
extern "C" Events::ArgumentStack FlushCachedChunks(Events::ArgumentStack&& args)
{
    const auto scriptChunk = args.extract<std::string>();

    if (scriptChunk.empty())
        s_CachedScriptChunks.clear();
    else
        s_CachedScriptChunks.erase(scriptChunk);

    return {};
}

}
