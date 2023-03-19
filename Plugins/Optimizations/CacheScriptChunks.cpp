#include "nwnx.hpp"

#include "API/CVirtualMachine.hpp"
#include "API/CScriptCompiler.hpp"
#include "API/CExoResMan.hpp"
#include "API/CTlkTable.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unordered_map<std::string, std::pair<DataBlockRef, DataBlockRef>> s_CachedScriptChunks;

void CacheScriptChunks() __attribute__((constructor));
void CacheScriptChunks()
{
    if (Config::Get<bool>("CACHE_SCRIPT_CHUNKS", false))
    {
        LOG_INFO("Caching script chunks");

        static Hooks::Hook s_SetUpJITCompiledScript = Hooks::HookFunction(&CVirtualMachine::SetUpJITCompiledScript,
        +[](CVirtualMachine *pVirtualMachine, const CExoString& sScriptChunk, BOOL bWrapIntoMain) -> int32_t
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
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = "!Chunk";
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = 0;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptChunk = sScriptChunk;
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], cachedScript->second.first, cachedScript->second.second);
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

                auto pNDB = Globals::ExoResMan()->Get("!Chunk", Constants::ResRefType::NDB);

                s_CachedScriptChunks[sScriptChunk.CStr()] = std::make_pair(pScriptDataBlock, pNDB);

                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = "!Chunk";
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = 0;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptChunk = sScriptChunk;
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], pScriptDataBlock, pNDB);
                return 0;
            }

            --pVirtualMachine->m_nRecursionLevel;
            return -635;
        }, Hooks::Order::Final);

        Tasks::QueueOnMainThread([](){ Globals::VirtualMachine()->m_pJitCompiler->SetOptimizeBinaryCodeLength(true); });
    }
}

// No nwscript export, call it manually.
extern "C" ArgumentStack FlushCachedChunks(ArgumentStack&& args)
{
    const auto scriptChunk = args.extract<std::string>();

    if (scriptChunk.empty())
        s_CachedScriptChunks.clear();
    else
        s_CachedScriptChunks.erase(scriptChunk);

    return {};
}

extern "C" ArgumentStack CacheScriptChunk(ArgumentStack&& args)
{
    const auto scriptChunk = args.extract<std::string>();
    const auto wrapIntoMain = args.extract<int32_t>();

    if (scriptChunk.empty())
        return "";

    if (s_CachedScriptChunks.find(scriptChunk) != s_CachedScriptChunks.end())
        return "";

    int32_t nReturnValue = Globals::VirtualMachine()->m_pJitCompiler->CompileScriptChunk(scriptChunk, wrapIntoMain);
    if (nReturnValue < 0)
    {
        CExoString retVal;
        retVal.Format("%s: %s", Globals::TlkTable()->GetSimpleString(-nReturnValue).CStr(), Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
        return retVal.CStr();
    }

    char *pScriptData;
    int32_t nScriptDataSize;
    Globals::VirtualMachine()->m_pJitCompiler->GetCompiledScriptCode(&pScriptData, &nScriptDataSize);

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
            CExoString retVal;
            retVal.Format("%s: %s", Globals::TlkTable()->GetSimpleString(635).CStr(), Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
            return retVal.CStr();
        }

        pScriptData += 13;
        nScriptDataSize -= 13;

        DataBlockRef pScriptDataBlock = std::make_shared<DataBlock>();
        pScriptDataBlock->Append(pScriptData, nScriptDataSize);

        auto pNDB = Globals::ExoResMan()->Get("!Chunk", Constants::ResRefType::NDB);

        s_CachedScriptChunks[scriptChunk] = std::make_pair(pScriptDataBlock, pNDB);
    }

    return "";
}

}
