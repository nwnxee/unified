#include "nwnx.hpp"

#include "API/CExoBase.hpp"
#include "API/C2DA.hpp"
#include "API/CNWRules.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoStringList.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CTlkTable.hpp"
#include "API/CTlkTableTokenCustom.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CWorldTimer.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CScriptCompiler.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CExoFile.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWDoorSurfaceMesh.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"

#include <string>
#include <cstdio>
#include <regex>
#include <cmath>
#include <chrono>
#include <unistd.h>
#include <sys/stat.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

static size_t s_resRefIndex;
static std::vector<std::string> s_listResRefs;
static std::unique_ptr<CScriptCompiler> s_scriptCompiler;
static std::unordered_map<std::string, std::string> s_serverConsoleCommandMap;

static auto s_id = MessageBus::Subscribe("NWNX_CORE_SIGNAL",
    [](const std::vector<std::string>& message)
    {
        if (message[0] == "ON_MODULE_LOAD_FINISH")
        {
            if (auto startScript = Config::Get<std::string>("PRE_MODULE_START_SCRIPT"))
            {
                LOG_NOTICE("Running module start script: %s", *startScript);
                Utils::ExecuteScript(*startScript, 0);
            }

            if (auto startChunk = Config::Get<std::string>("PRE_MODULE_START_SCRIPT_CHUNK"))
            {
                LOG_NOTICE("Running module start script chunk: %s", *startChunk);

                bool bWrapIntoMain = startChunk->find("void main()") == std::string::npos;
                if (Globals::VirtualMachine()->RunScriptChunk(*startChunk, 0, true, bWrapIntoMain))
                {
                    LOG_ERROR("Failed to run module start script chunk with error: %s",
                    Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
                }
            }
        }
    });

NWNX_EXPORT ArgumentStack GetCurrentScriptName(ArgumentStack&& args)
{
    std::string retVal;

    const auto depth = args.extract<int32_t>();

    auto *pVM = API::Globals::VirtualMachine();
    if (pVM && pVM->m_nRecursionLevel >= 0 && pVM->m_nRecursionLevel >= depth)
    {
        auto& script = pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel - depth];
        if (!script.m_sScriptName.IsEmpty())
            retVal = script.m_sScriptName.CStr();
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack GetAsciiTableString(ArgumentStack&&)
{
    static char table[257];

    if (table[0] == 0)
    {
        table[0] = 1; // Can't pass NULL or it will terminate the string
        for (size_t i = 1; i <= 0xFF; i++)
            table[i] = i;
    }

    return std::string(table);
}

namespace { // temporary fix for conflict with CExoResMan::Hash::SHA1
NWNX_EXPORT ArgumentStack Hash(ArgumentStack&& args)
{
    const auto str = args.extract<std::string>();
    return (int32_t)std::hash<std::string>{}(str);
}
}

NWNX_EXPORT ArgumentStack GetModuleMtime(ArgumentStack&&)
{
    CNWSModule *pMod = Utils::GetModule();
    if (pMod->m_bIsSaveGame)
    {
        LOG_DEBUG("NWNX_GetModuleMtime() module is a save game, returning 0");
        return 0;
    }
    std::string modName = pMod->m_sModuleResourceName.SubString(12); // discard "CURRENTGAME:"
    std::string modPath = Globals::ExoBase()->m_pcExoAliasList->ResolveFileName("MODULES:" + modName, Constants::ResRefType::MOD);
    struct stat s;
    if (stat(modPath.c_str(), &s) == 0)
    {
        LOG_DEBUG("NWNX_GetModuleMtime() mtime for: %s", modPath);
        return (int32_t)s.st_mtim.tv_sec;
    }
    LOG_ERROR("NWNX_GetModuleMtime() could not get file stats for: %s", modPath);
    return 0;
}

NWNX_EXPORT ArgumentStack GetModuleFile(ArgumentStack&&)
{
    CNWSModule *pMod = Utils::GetModule();
    return pMod->m_sModuleResourceName.SubString(12); // discard "CURRENTGAME:"
}

NWNX_EXPORT ArgumentStack GetCustomToken(ArgumentStack&& args)
{
    std::string retVal;

    const auto tokenNumber = args.extract<int32_t>();
      ASSERT_OR_THROW(tokenNumber >= 0);

    auto *pTlk = API::Globals::TlkTable();
    auto *pTokens = pTlk->m_pTokensCustom;
    uint32_t numTokens = pTlk->m_nTokensCustom;

    CTlkTableTokenCustom token;
    token.m_nNumber = tokenNumber;

    auto *foundToken = (CTlkTableTokenCustom*)std::bsearch(&token, pTokens, numTokens, sizeof(token),
        +[](const void *a, const void *b){ return (int32_t)((CTlkTableTokenCustom*)a)->m_nNumber - (int32_t)((CTlkTableTokenCustom*)b)->m_nNumber; });

    if(foundToken)
    {
        retVal = foundToken->m_sValue.CStr();
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack EffectTypeCast(ArgumentStack&& args)
{
    return args.extract<CGameEffect*>();
}

NWNX_EXPORT ArgumentStack StripColors(ArgumentStack&& args)
{
    const auto s = args.extract<std::string>();

    std::regex color_codes("<c.+?(?=>)>|<\\/c>");
    std::string retVal = std::regex_replace(s, color_codes, "");

    return retVal;
}

NWNX_EXPORT ArgumentStack GetEnvironmentVariable(ArgumentStack&& args)
{
    std::string retVal;
    const auto envVar = args.extract<std::string>();

    if (const char* value = std::getenv(envVar.c_str()))
        retVal = std::string(value);

    return retVal;
}

NWNX_EXPORT ArgumentStack GetMinutesPerHour(ArgumentStack&&)
{
    return Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->m_nMinutesPerHour;
}

NWNX_EXPORT ArgumentStack SetMinutesPerHour(ArgumentStack&& args)
{
    const auto minPerHour = args.extract<int32_t>();
      ASSERT_OR_THROW(minPerHour > 0);
      ASSERT_OR_THROW(minPerHour <= 255);

    Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->SetMinutesPerHour(minPerHour);

    return {};
}

NWNX_EXPORT ArgumentStack EncodeStringForURL(ArgumentStack&& args)
{
    const auto s = args.extract<std::string>();
    std::string result;

    // ** Copied from ../Webhook/External/httplib.h
    for (auto i = 0; s[i]; i++)
    {
        switch (s[i])
        {
            case ' ':  result += "+"; break;
            case '\'': result += "%27"; break;
            case ',':  result += "%2C"; break;
            case ':':  result += "%3A"; break;
            case ';':  result += "%3B"; break;
            default:
                if (s[i] < 0)
                {
                    result += '%';
                    char hex[4];
                    size_t len = snprintf(hex, sizeof(hex) - 1, "%02X", (unsigned char)s[i]);
                      ASSERT_OR_THROW(len == 2);
                    result.append(hex, len);
                }
                else
                {
                    result += s[i];
                }
                break;
        }
    }
    // **
    return result;
}

NWNX_EXPORT ArgumentStack GetFirstResRef(ArgumentStack&& args)
{
    std::string retVal;

    const auto resRefType = args.extract<int32_t>();
    const auto regexFilter = args.extract<std::string>();
    const auto bModuleOnly = args.extract<int32_t>();

    s_resRefIndex = 0;
    s_listResRefs.clear();
    s_listResRefs.reserve(25);

    CExoStringList *pList = Globals::ExoResMan()->GetResOfType(resRefType, !!bModuleOnly);

    if (pList)
    {
        std::regex rgx(regexFilter);

        for (int i = 0; i < pList->m_nCount; i++)
        {
            if (regexFilter.empty() || std::regex_match(pList->m_pStrings[i]->CStr(), rgx))
            {
                s_listResRefs.emplace_back(pList->m_pStrings[i]->CStr());
            }
        }

        delete pList;
    }

    if (s_resRefIndex < s_listResRefs.size())
    {
        retVal = s_listResRefs[s_resRefIndex];
        s_resRefIndex++;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack GetNextResRef(ArgumentStack&&)
{
    std::string retVal;

    if (s_resRefIndex < s_listResRefs.size())
    {
        retVal = s_listResRefs[s_resRefIndex];
        s_resRefIndex++;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack GetLastCreatedObject(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    const auto objectType = args.extract<int32_t>();
      ASSERT_OR_THROW(objectType >= 0);
    const auto nthLast = args.extract<int32_t>();
      ASSERT_OR_THROW(nthLast > 0);

    auto* pGameObjectArray = Globals::AppManager()->m_pServerExoApp->GetObjectArray();
    int count = 1;
    CGameObject *pObject;

    for(int nObjectID = pGameObjectArray->m_nNextObjectArrayID[0] - 1; nObjectID >= 0; nObjectID--)
    {
        if(!pGameObjectArray->GetGameObject(nObjectID, &pObject))
        {
            if (pObject && (pObject->m_nObjectType == objectType || objectType == 0))
            {
                if (count == nthLast)
                {
                    retVal = pObject->m_idSelf;
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack AddScript(ArgumentStack&& args)
{
    const auto scriptName = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptName.empty());
      ASSERT_OR_THROW(scriptName.size() <= 16);
    const auto scriptData = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptData.empty());
    const auto wrapIntoMain = args.extract<int32_t>();

    auto alias = args.extract<std::string>();

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_AddScript() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    if (!s_scriptCompiler)
    {
        s_scriptCompiler = std::make_unique<CScriptCompiler>(Constants::ResRefType::NSS, Constants::ResRefType::NCS, Constants::ResRefType::NDB);
        s_scriptCompiler->SetGenerateDebuggerOutput(0);
        s_scriptCompiler->SetOptimizationFlags(CSCRIPTCOMPILER_OPTIMIZE_EVERYTHING);
        s_scriptCompiler->SetCompileConditionalOrMain(true);
        s_scriptCompiler->SetIdentifierSpecification("nwscript");
    }

    s_scriptCompiler->SetOutputAlias(alias);

    if (s_scriptCompiler->CompileScriptChunk(scriptData, wrapIntoMain != 0) == 0)
    {
        auto writeFileResult = s_scriptCompiler->WriteFinalCodeToFile(scriptName);
        if (writeFileResult != 0)
            return Globals::TlkTable()->GetSimpleString(abs(writeFileResult)).CStr();
    }
    else
        return s_scriptCompiler->m_sCapturedError.CStr();

    return "";
}

NWNX_EXPORT ArgumentStack AddNSSFile(ArgumentStack&& args)
{
    const auto fileName = args.extract<std::string>();
      ASSERT_OR_THROW(!fileName.empty());
      ASSERT_OR_THROW(fileName.size() <= 16);
    const auto contents = args.extract<std::string>();

    auto alias = args.extract<std::string>();

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_AddNSSFile() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    auto file = CExoFile((alias + ":" + fileName).c_str(), Constants::ResRefType::NSS, "w");
    bool bOk = file.FileOpened() && file.Write(contents) && file.Flush();
    if (bOk)
        Globals::ExoResMan()->UpdateResourceDirectory(alias + ":");
    return bOk;
}

NWNX_EXPORT ArgumentStack RemoveNWNXResourceFile(ArgumentStack&& args)
{
    const auto fileName = args.extract<std::string>();
      ASSERT_OR_THROW(!fileName.empty());
      ASSERT_OR_THROW(fileName.size() <= 16);
    const auto type = args.extract<int32_t>();

    auto alias = args.extract<std::string>();

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_RemoveNWNXResourceFile() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    bool bOk = Globals::ExoResMan()->RemoveFile(alias + ":" + fileName, type);
    if (bOk)
        Globals::ExoResMan()->UpdateResourceDirectory(alias + ":");
    return bOk;
}

NWNX_EXPORT ArgumentStack SetInstructionLimit(ArgumentStack&& args)
{
    const static uint32_t defaultInstructionLimit = Globals::VirtualMachine()->m_nInstructionLimit;
    const auto limit = args.extract<int32_t>();

    if (limit < 0)
    {
        // We queue it on the main thread so it'll reset after the current script is done executing
        Tasks::QueueOnMainThread(
            [](){ Globals::VirtualMachine()->m_nInstructionLimit = defaultInstructionLimit; });
    }
    else
        Globals::VirtualMachine()->m_nInstructionLimit = limit;

    return {};
}

NWNX_EXPORT ArgumentStack GetInstructionLimit(ArgumentStack&&)
{
    int32_t retVal = Globals::VirtualMachine()->m_nInstructionLimit;
    return retVal;
}

NWNX_EXPORT ArgumentStack SetInstructionsExecuted(ArgumentStack&& args)
{
    const auto instructions = args.extract<int32_t>();

    Globals::VirtualMachine()->m_nInstructionsExecuted = instructions >= 0 ? instructions : 0;

    return {};
}

NWNX_EXPORT ArgumentStack GetInstructionsExecuted(ArgumentStack&&)
{
    int32_t retVal = Globals::VirtualMachine()->m_nInstructionsExecuted;
    return retVal;
}

NWNX_EXPORT ArgumentStack GetScriptReturnValue(ArgumentStack&&)
{
    int32_t retVal = 0;

    int32_t nParameterType;
    void* pParameter;
    if (Globals::VirtualMachine()->GetRunScriptReturnValue(&nParameterType, &pParameter) && nParameterType == 3) {
        retVal = (intptr_t)pParameter;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack RegisterServerConsoleCommand(ArgumentStack&& args)
{
    const auto command = args.extract<std::string>();
      ASSERT_OR_THROW(!command.empty());
    const auto scriptChunk = args.extract<std::string>();
      ASSERT_OR_THROW(!scriptChunk.empty());

    bool registered = Commands::Register(command, [](std::string &command, std::string &args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        LOG_INFO("Executing NWScript Server Console Command: '%s' with args: %s", command, args);

        std::string scriptChunk = s_serverConsoleCommandMap[command];
        bool wrapIntoMain = scriptChunk.find("void main()") == std::string::npos;
        std::string search = "$args";

        auto searchPos = scriptChunk.find(search);
        while (searchPos != std::string::npos)
        {
            scriptChunk.replace(searchPos, search.size(), args);
            searchPos = scriptChunk.find(search, searchPos + args.size());
        }

        if (Globals::VirtualMachine()->RunScriptChunk(scriptChunk, 0, true, wrapIntoMain))
        {
            LOG_ERROR("Failed to run NWScript Server Console Command '%s' with error: %s", command,
                      Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
        }
    });

    if (registered)
        s_serverConsoleCommandMap[command] = scriptChunk;

    return registered;
}

NWNX_EXPORT ArgumentStack UnregisterServerConsoleCommand(ArgumentStack&& args)
{
    const auto command = args.extract<std::string>();
      ASSERT_OR_THROW(!command.empty());

    if (s_serverConsoleCommandMap.find(command) != s_serverConsoleCommandMap.end())
    {
        Commands::Unregister(command);
        s_serverConsoleCommandMap.erase(command);
    }

    return {};
}

NWNX_EXPORT ArgumentStack PluginExists(ArgumentStack&& args)
{
    return Plugin::Find(args.extract<std::string>()) ? 1 : 0;
}

NWNX_EXPORT ArgumentStack GetUserDirectory(ArgumentStack&&)
{
    return Globals::ExoBase()->m_sUserDirectory.CStr();
}

NWNX_EXPORT ArgumentStack CreateDoor(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    const auto strResRef = args.extract<std::string>();
      ASSERT_OR_THROW(!strResRef.empty());
    const auto locSpawn = args.extract<CScriptLocation>();
    const auto tag = args.extract<std::string>();
    const auto appearance = args.extract<int32_t>();

    auto resRef = CResRef(strResRef);

    if (!Globals::ExoResMan()->Exists(resRef, Constants::ResRefType::UTD, nullptr))
    {
        LOG_WARNING("CreateDoor: ResRef '%s' does not exist", resRef.GetResRefStr());
        return Constants::OBJECT_INVALID;
    }

    if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(locSpawn.m_oArea)))
    {
        CResStruct resStruct{};
        CResGFF gff(Constants::ResRefType::UTD, (char*)"UTD ", resRef);

        if (gff.m_bLoaded)
        {
            auto *pDoor = new CNWSDoor();
            gff.GetTopLevelStruct(&resStruct);

            pDoor->m_sTemplate = resRef.GetResRefStr();
            pDoor->LoadDoor(&gff, &resStruct);
            pDoor->LoadVarTable(&gff, &resStruct);
            pDoor->SetPosition(locSpawn.m_vPosition);
            if (appearance > 0)
            {
                pDoor->m_nAppearanceType = appearance;
                int32_t bVisibleModel = true;
                Globals::Rules()->m_p2DArrays->GetDoorTypesTable()->GetINTEntry(appearance, "VisibleModel", &bVisibleModel);
                pDoor->m_bVisibleModel = bVisibleModel;
                CExoString sWalkMeshTemplate;
                Globals::Rules()->m_p2DArrays->GetDoorTypesTable()->GetCExoStringEntry(appearance, "Model", &sWalkMeshTemplate);
                delete pDoor->m_pWalkMesh;
                pDoor->m_pWalkMesh = new CNWDoorSurfaceMesh;
                pDoor->m_pWalkMesh->LoadWalkMesh(sWalkMeshTemplate);
                pDoor->PostProcess();
            }
            pDoor->SetOrientation(locSpawn.m_vOrientation);

            if (!tag.empty())
            {
                pDoor->m_sTag = CExoString(tag.c_str());
                Utils::GetModule()->AddObjectToLookupTable(pDoor->m_sTag, pDoor->m_idSelf);
            }

            pDoor->AddToArea(pArea, locSpawn.m_vPosition.x, locSpawn.m_vPosition.y, pArea->ComputeHeight(locSpawn.m_vPosition));

            retVal = pDoor->m_idSelf;
        }
        else
            LOG_WARNING("CreateDoor: Unable to load ResRef: %s", resRef.GetResRefStr());
    }
    else
        LOG_WARNING("CreateDoor: Invalid Area");

    return retVal;
}

NWNX_EXPORT ArgumentStack SetItemActivator(ArgumentStack&& args)
{
    const auto objectId = args.extract<ObjectID>();

    if (auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId))
        Utils::GetModule()->m_oidLastItemActivator = pGameObject->m_idSelf;
    else
        Utils::GetModule()->m_oidLastItemActivator = Constants::OBJECT_INVALID;

    return {};
}

NWNX_EXPORT ArgumentStack GetWorldTime(ArgumentStack&& args)
{
    const auto adjustment = args.extract<float>();

    auto *pWorldTimer = Globals::AppManager()->m_pServerExoApp->GetWorldTimer();
    uint32_t adjustmentCalendarDay = pWorldTimer->GetCalendarDayFromSeconds(std::fabs(adjustment));
    uint32_t adjustmentTimeOfDay = pWorldTimer->GetTimeOfDayFromSeconds(std::fabs(adjustment));
    uint32_t currentCalendarDay, currentTimeOfDay, retvalCalendarDay, retvalTimeOfDay;
    pWorldTimer->GetWorldTime(&currentCalendarDay, &currentTimeOfDay);

    if (adjustment > 0.0f)
        pWorldTimer->AddWorldTimes(currentCalendarDay, currentTimeOfDay, adjustmentCalendarDay, adjustmentTimeOfDay, &retvalCalendarDay, &retvalTimeOfDay);
    else if (adjustment < 0.0f)
        pWorldTimer->SubtractWorldTimes(currentCalendarDay, currentTimeOfDay, adjustmentCalendarDay, adjustmentTimeOfDay, &retvalCalendarDay, &retvalTimeOfDay);
    else
    {
        retvalCalendarDay = currentCalendarDay;
        retvalTimeOfDay = currentTimeOfDay;
    }

    return {(int32_t)retvalCalendarDay, (int32_t)retvalTimeOfDay};
}

NWNX_EXPORT ArgumentStack SetResourceOverride(ArgumentStack&& args)
{
    auto resType = args.extract<int32_t>();
      ASSERT_OR_THROW(resType >= Constants::ResRefType::MIN);
      ASSERT_OR_THROW(resType <= Constants::ResRefType::MAX);
    auto oldName = args.extract<std::string>();
      ASSERT_OR_THROW(!oldName.empty());
      ASSERT_OR_THROW(oldName.size() <= 16);
    auto newName = args.extract<std::string>();
      ASSERT_OR_THROW(newName.size() <= 16);

    if (newName.empty())
        Globals::ExoResMan()->RemoveOverride(oldName.c_str(), resType);
    else
        Globals::ExoResMan()->AddOverride(oldName.c_str(), newName.c_str(), resType);

    return {};
}

NWNX_EXPORT ArgumentStack GetResourceOverride(ArgumentStack&& args)
{
    auto resType = args.extract<int32_t>();
      ASSERT_OR_THROW(resType >= Constants::ResRefType::MIN);
      ASSERT_OR_THROW(resType <= Constants::ResRefType::MAX);
    auto resName = args.extract<std::string>();
      ASSERT_OR_THROW(!resName.empty());
      ASSERT_OR_THROW(resName.size() <= 16);

    std::string overrideResName = Globals::ExoResMan()->GetOverride(resName.c_str(), resType).GetResRefStr();

    return overrideResName == resName ? "" : overrideResName;
}

NWNX_EXPORT ArgumentStack GetScriptParamIsSet(ArgumentStack&& args)
{
    int32_t retVal = false;

    const auto paramName = args.extract<std::string>();
      ASSERT_OR_THROW(!paramName.empty());

    auto *pVirtualMachine = API::Globals::VirtualMachine();
    if (pVirtualMachine && pVirtualMachine->m_nRecursionLevel >= 0)
    {
        auto &scriptParams = pVirtualMachine->m_lScriptParams[pVirtualMachine->m_nRecursionLevel];

        for (const auto& scriptParam : scriptParams)
        {
            if (scriptParam.key.CStr() == paramName)
            {
                retVal = true;
                break;
            }
        }
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack SetDawnHour(ArgumentStack &&args)
{
    const auto dawnHour = args.extract<int32_t>();
      ASSERT_OR_THROW(dawnHour >= 0);
      ASSERT_OR_THROW(dawnHour <= 23);

    Utils::GetModule()->m_nDawnHour = dawnHour;

    return {};
}

NWNX_EXPORT ArgumentStack GetDawnHour(ArgumentStack &&args)
{
    return Utils::GetModule()->m_nDawnHour;
}

NWNX_EXPORT ArgumentStack SetDuskHour(ArgumentStack &&args)
{
    const auto duskHour = args.extract<int32_t>();
      ASSERT_OR_THROW(duskHour >= 0);
      ASSERT_OR_THROW(duskHour <= 23);

    Utils::GetModule()->m_nDuskHour = duskHour;

    return {};
}

NWNX_EXPORT ArgumentStack GetDuskHour(ArgumentStack &&args)
{
    return Utils::GetModule()->m_nDuskHour;
}

NWNX_EXPORT ArgumentStack GetHighResTimeStamp(ArgumentStack&&)
{
    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();

    auto count = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    return {(int32_t)(count / 1000000), (int32_t)(count % 1000000)};
}

NWNX_EXPORT ArgumentStack GetTTY(ArgumentStack&&)
{
    std::string retval;
    auto tty = ttyname(STDIN_FILENO);
    if (tty)
       retval = tty;
    return retval;
}

NWNX_EXPORT ArgumentStack SetCurrentlyRunningEvent(ArgumentStack&& args)
{
    const auto eventId = args.extract<int32_t>();

    Globals::VirtualMachine()->m_pVirtualMachineScript[0].m_nScriptEventID = eventId;

    return {};
}

NWNX_EXPORT ArgumentStack GetStringLevenshteinDistance(ArgumentStack&& args)
{
    // C++ Levenshtein Distance by Martin Ettl, 2012-10-05
    // https://rosettacode.org/wiki/Levenshtein_distance#C++
    auto s1 = args.extract<std::string>();
    auto s2 = args.extract<std::string>();

	const size_t m = s1.size();
    const size_t n = s2.size();

    if (m == 0)
        return (int32_t)n;

    if (n == 0)
        return (int32_t)m;

    std::vector<size_t> costs(n + 1);
    std::iota(costs.begin(), costs.end(), 0);
    size_t i = 0;
    for (auto c1 : s1)
	{
        costs[0] = i + 1;
        size_t corner = i;
        size_t j = 0;
        for (auto c2 : s2)
		{
            size_t upper = costs[j + 1];
            costs[j + 1] = (c1 == c2) ? corner : 1 + std::min(std::min(upper, corner), costs[j]);
            corner = upper;
            ++j;
        }
        ++i;
    }

    return (int32_t)costs[n];
}

NWNX_EXPORT ArgumentStack UpdateClientObject(ArgumentStack&& args)
{
    auto oidObject = args.extract<OBJECT_ID>();
        ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    if (auto* pPlayer = Utils::PopPlayer(args))
        Utils::UpdateClientObjectForPlayer(oidObject, pPlayer);
    else
        Utils::UpdateClientObject(oidObject);

    return {};
}

NWNX_EXPORT ArgumentStack CleanResourceDirectory(ArgumentStack&& args)
{
    const auto alias = args.extract<std::string>();
    const auto type = args.extract<int32_t>();
    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_CleanResourceDirectory() called with an invalid alias: %s", alias);
        return false;
    }
    bool bOk = Globals::ExoResMan()->CleanDirectory(alias + ":", false, false, type);
    Globals::ExoResMan()->UpdateResourceDirectory(alias + ":");
    return bOk;
}

NWNX_EXPORT ArgumentStack GetModuleTlkFile(ArgumentStack&&)
{
    return Utils::GetModule()->m_sModuleAltTLKFile;
}

NWNX_EXPORT ArgumentStack UpdateResourceDirectory(ArgumentStack&& args)
{
    const auto alias = args.extract<std::string>();
      ASSERT_OR_THROW(!alias.empty());
    return Globals::ExoResMan()->UpdateResourceDirectory(alias + ":");
}
