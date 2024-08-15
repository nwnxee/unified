#include "nwnx.hpp"

#include "API/CVirtualMachine.hpp"
#include "API/CScriptCompiler.hpp"
#include "API/CExoResMan.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unordered_map<int32_t, DataBlockRef> s_CachedScripts;

void CacheScripts() __attribute__((constructor));
void CacheScripts()
{
    if (Config::Get<bool>("CACHE_SCRIPTS", false))
    {
        LOG_INFO("Caching scripts");

        static Hooks::Hook s_ReadScriptFile = Hooks::HookFunction(&CVirtualMachine::ReadScriptFile,
        +[](CVirtualMachine *pVirtualMachine, CExoString *psFileName, int32_t nScriptEventID) -> int32_t
        {
            pVirtualMachine->m_nRecursionLevel += 1;
            if (pVirtualMachine->m_nRecursionLevel >= 8)
            {
                --pVirtualMachine->m_nRecursionLevel;
                return -633;
            }

            CExoString sScript;
            if (psFileName)
                sScript = *psFileName;

            int32_t nHash = sScript.GetHash();

            auto cachedScript = s_CachedScripts.find(nHash);
            if (cachedScript != s_CachedScripts.end())
            {
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = sScript;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = nScriptEventID;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptChunk = "";
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], cachedScript->second);
                return 0;
            }

            auto pVMFile = Globals::ExoResMan()->Get(sScript, pVirtualMachine->m_nResTypeCompiled);
            if (!pVMFile)
            {
                --pVirtualMachine->m_nRecursionLevel;
                return -634;
            }

            char *pScriptData = (char*)pVMFile->Data();
            uint32_t nScriptDataSize = pVMFile->Used();

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
                s_CachedScripts[nHash] = pScriptDataBlock;

                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptName = sScript;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_nScriptEventID = nScriptEventID;
                pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel].m_sScriptChunk = "";
                pVirtualMachine->InitializeScript(&pVirtualMachine->m_pVirtualMachineScript[pVirtualMachine->m_nRecursionLevel], pScriptDataBlock);
                return 0;
            }

            --pVirtualMachine->m_nRecursionLevel;
            return -635;
        }, Hooks::Order::Final);
    }
}

// No nwscript export, call it manually.
extern "C" ArgumentStack FlushCachedScripts(ArgumentStack&& args)
{
    const auto script = args.extract<std::string>();

    if (script.empty())
        s_CachedScripts.clear();
    else
        s_CachedScripts.erase(CExoString(script).GetHash());

    return {};
}

}
