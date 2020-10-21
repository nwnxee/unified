#include "Util.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"
#include "API/C2DA.hpp"
#include "API/CNWRules.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CResRef.hpp"
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
#include "API/CExoFile.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/Functions.hpp"
#include "Utils.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Plugins/Plugins.hpp"
#include "Services/Commands/Commands.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Messaging/Messaging.hpp"

#include <string>
#include <cstdio>
#include <regex>
#include <cmath>


using namespace NWNXLib;
using namespace NWNXLib::API;

static Util::Util* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Util::Util(services);
    return g_plugin;
}


namespace Util {

Util::Util(Services::ProxyServiceList* services)
    : Plugin(services),
      m_scriptCompiler(nullptr)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetCurrentScriptName);
    REGISTER(GetAsciiTableString);
    REGISTER(Hash);
    REGISTER(GetCustomToken);
    REGISTER(EffectTypeCast);
    REGISTER(StripColors);
    REGISTER(IsValidResRef);
    REGISTER(GetEnvironmentVariable);
    REGISTER(GetMinutesPerHour);
    REGISTER(SetMinutesPerHour);
    REGISTER(EncodeStringForURL);
    REGISTER(Get2DARowCount);
    REGISTER(GetFirstResRef);
    REGISTER(GetNextResRef);
    REGISTER(GetServerTicksPerSecond);
    REGISTER(GetLastCreatedObject);
    REGISTER(AddScript);
    REGISTER(GetNSSContents);
    REGISTER(AddNSSFile);
    REGISTER(RemoveNWNXResourceFile);
    REGISTER(SetInstructionLimit);
    REGISTER(RegisterServerConsoleCommand);
    REGISTER(UnregisterServerConsoleCommand);
    REGISTER(PluginExists);
    REGISTER(GetUserDirectory);
    REGISTER(GetScriptReturnValue);
    REGISTER(CreateDoor);
    REGISTER(SetItemActivator);
    REGISTER(GetWorldTime);
    REGISTER(SetResourceOverride);
    REGISTER(GetResourceOverride);
    REGISTER(GetScriptParamIsSet);

#undef REGISTER

    GetServices()->m_hooks->RequestSharedHook<API::Functions::_ZN21CServerExoAppInternal8MainLoopEv, int32_t>(
            +[](bool before, CServerExoAppInternal*)
            {
                static int ticks;
                static time_t previous;

                if (!before)
                {
                    time_t current = time(nullptr);

                    if (current == previous)
                    {
                        ticks++;
                    }
                    else
                    {
                        g_plugin->m_tickCount = ticks;
                        previous = current;
                        ticks = 1;
                    }
                }
            });

    GetServices()->m_messaging->SubscribeMessage("NWNX_CORE_SIGNAL",
        [](const std::vector<std::string>& message)
        {
            if (message[0] == "ON_MODULE_LOAD_FINISH")
            {
                if (auto startScript = g_plugin->GetServices()->m_config->Get<std::string>("PRE_MODULE_START_SCRIPT"))
                {
                    LOG_NOTICE("Running module start script: %s", *startScript);
                    Utils::ExecuteScript(*startScript, 0);
                }

                if (auto startChunk = g_plugin->GetServices()->m_config->Get<std::string>("PRE_MODULE_START_SCRIPT_CHUNK"))
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
}

Util::~Util()
{

}

ArgumentStack Util::GetCurrentScriptName(ArgumentStack&& args)
{
    std::string retval = "";

    const auto depth = Services::Events::ExtractArgument<int32_t>(args);

    auto *pVM = API::Globals::VirtualMachine();
    if (pVM && pVM->m_nRecursionLevel >= 0 && pVM->m_nRecursionLevel >= depth)
    {
        auto& script = pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel - depth];
        if (!script.m_sScriptName.IsEmpty())
            retval = script.m_sScriptName.CStr();
    }

    return Services::Events::Arguments(retval);
}

ArgumentStack Util::GetAsciiTableString(ArgumentStack&&)
{
    static char table[256];

    if (table[0] == 0)
    {
        table[0] = 1; // Can't pass NULL or it will terminate the string
        for (size_t i = 1; i < sizeof(table); i++)
            table[i] = i;
    }

    return Services::Events::Arguments(std::string(table));
}

ArgumentStack Util::Hash(ArgumentStack&& args)
{
    const auto str = Services::Events::ExtractArgument<std::string>(args);
    return Services::Events::Arguments((int32_t)std::hash<std::string>{}(str));
}

ArgumentStack Util::GetCustomToken(ArgumentStack&& args)
{
    std::string retVal;

    const auto tokenNumber = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(tokenNumber >= 0);

    auto *pTlk = API::Globals::TlkTable();
    auto *pTokens = pTlk->m_pTokensCustom;
    int numTokens = pTlk->m_nTokensCustom;

    CTlkTableTokenCustom token;
    token.m_nNumber = tokenNumber;

    auto *foundToken = (CTlkTableTokenCustom*)std::bsearch(&token, pTokens, numTokens, sizeof(token),
        +[](const void *a, const void *b){ return (int32_t)((CTlkTableTokenCustom*)a)->m_nNumber - (int32_t)((CTlkTableTokenCustom*)b)->m_nNumber; });

    if(foundToken)
    {
        retVal = foundToken->m_sValue.CStr();
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::EffectTypeCast(ArgumentStack&& args)
{
    return Services::Events::Arguments(Services::Events::ExtractArgument<CGameEffect*>(args));
}

ArgumentStack Util::StripColors(ArgumentStack&& args)
{
    const auto s = Services::Events::ExtractArgument<std::string>(args);

    std::regex color_codes("<c.+?(?=>)>|<\\/c>");
    std::string retVal = std::regex_replace(s, color_codes, "");
    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::IsValidResRef(ArgumentStack&& args)
{
    int32_t retVal = 0;
    const auto resRef = Services::Events::ExtractArgument<std::string>(args);
    const auto resType = Services::Events::ExtractArgument<int32_t>(args);

    retVal = Globals::ExoResMan()->Exists(CResRef(resRef.c_str()), resType, nullptr);
    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::GetEnvironmentVariable(ArgumentStack&& args)
{
    std::string retVal;
    const auto envVar = Services::Events::ExtractArgument<std::string>(args);

    if (const char* value = std::getenv(envVar.c_str()))
        retVal = std::string(value);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::GetMinutesPerHour(ArgumentStack&&)
{
    return Services::Events::Arguments(Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->m_nMinutesPerHour);
}

ArgumentStack Util::SetMinutesPerHour(ArgumentStack&& args)
{
    const auto minPerHour = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(minPerHour > 0);
      ASSERT_OR_THROW(minPerHour <= 255);

    Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->SetMinutesPerHour(minPerHour);
    return Services::Events::Arguments();
}

ArgumentStack Util::EncodeStringForURL(ArgumentStack&& args)
{
    const auto s = Services::Events::ExtractArgument<std::string>(args);
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
    return Services::Events::Arguments(result);
}

ArgumentStack Util::Get2DARowCount(ArgumentStack&& args)
{
    const auto twodaRef = Services::Events::ExtractArgument<std::string>(args);
    auto twoda = Globals::Rules()->m_p2DArrays->GetCached2DA(twodaRef.c_str(), true);
    return Services::Events::Arguments(twoda ? twoda->m_nNumRows : 0);
}

ArgumentStack Util::GetFirstResRef(ArgumentStack&& args)
{
    std::string retVal;

    const auto resRefType = Services::Events::ExtractArgument<int32_t>(args);
    const auto regexFilter = Services::Events::ExtractArgument<std::string>(args);
    const auto bModuleOnly = Services::Events::ExtractArgument<int32_t>(args);

    m_resRefIndex = 0;
    m_listResRefs.clear();
    m_listResRefs.reserve(10);

    CExoStringList *pList = Globals::ExoResMan()->GetResOfType(resRefType, !!bModuleOnly);

    if (pList)
    {
        std::regex rgx(regexFilter);

        for (int i = 0; i < pList->m_nCount; i++)
        {
            if (regexFilter.empty() || std::regex_match(pList->m_pStrings[i]->CStr(), rgx))
            {
                m_listResRefs.emplace_back(pList->m_pStrings[i]->CStr());
            }
        }
    }

    if (m_resRefIndex < m_listResRefs.size())
    {
        retVal = m_listResRefs[m_resRefIndex];
        m_resRefIndex++;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::GetNextResRef(ArgumentStack&&)
{
    std::string retVal;

    if (m_resRefIndex < m_listResRefs.size())
    {
        retVal = m_listResRefs[m_resRefIndex];
        m_resRefIndex++;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::GetServerTicksPerSecond(ArgumentStack&&)
{
    return Services::Events::Arguments(m_tickCount);
}

ArgumentStack Util::GetLastCreatedObject(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    const auto objectType = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(objectType >= 0);
    const auto nthLast = Services::Events::ExtractArgument<int32_t>(args);
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

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::AddScript(ArgumentStack&& args)
{
    std::string retVal;

    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
      ASSERT_OR_THROW(scriptName.size() <= 16);
    const auto scriptData = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptData.empty());
    const auto wrapIntoMain = Services::Events::ExtractArgument<int32_t>(args);

    std::string alias;
    try
    {
        alias = Services::Events::ExtractArgument<std::string>(args);
    }
    catch (const std::runtime_error& e)
    {
        LOG_WARNING("NWNX_Util_AddScript() called without alias parameter, please update nwnx_util.nss");
        alias = "NWNX";
    }

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_AddScript() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    if (!m_scriptCompiler)
    {
        m_scriptCompiler = std::make_unique<CScriptCompiler>();
        m_scriptCompiler->SetCompileDebugLevel(0);
        m_scriptCompiler->SetCompileSymbolicOutput(0);
        m_scriptCompiler->SetGenerateDebuggerOutput(0);
        m_scriptCompiler->SetOptimizeBinaryCodeLength(true);
        m_scriptCompiler->SetCompileConditionalOrMain(true);
        m_scriptCompiler->SetIdentifierSpecification("nwscript");
    }

    m_scriptCompiler->SetOutputAlias(alias);

    if (m_scriptCompiler->CompileScriptChunk(scriptData.c_str(), wrapIntoMain != 0) == 0)
    {
        auto writeFileResult = m_scriptCompiler->WriteFinalCodeToFile(scriptName.c_str());
        if (writeFileResult != 0)
            retVal = Globals::TlkTable()->GetSimpleString(abs(writeFileResult)).CStr();
    }
    else
        retVal = m_scriptCompiler->m_sCapturedError.CStr();

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::GetNSSContents(ArgumentStack&& args)
{
    std::string retVal;

    const auto scriptName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptName.empty());
      ASSERT_OR_THROW(scriptName.size() <= 16);
    const auto maxLength = Services::Events::ExtractArgument<int32_t>(args);

    if (Globals::ExoResMan()->Exists(scriptName.c_str(), Constants::ResRefType::NSS, nullptr))
    {
        CScriptSourceFile scriptSourceFile;
        char *data;
        uint32_t size = 0;

        if (scriptSourceFile.LoadScript(scriptName, &data, &size) == 0)
        {
            retVal.assign(data, maxLength < 0 ? size : (uint32_t)maxLength > size ? size : maxLength);
            scriptSourceFile.UnloadScript();
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::AddNSSFile(ArgumentStack&& args)
{
    int32_t retVal = false;

    const auto fileName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!fileName.empty());
      ASSERT_OR_THROW(fileName.size() <= 16);
    const auto contents = Services::Events::ExtractArgument<std::string>(args);

    std::string alias;
    try
    {
        alias = Services::Events::ExtractArgument<std::string>(args);
    }
    catch (const std::runtime_error& e)
    {
        LOG_WARNING("NWNX_Util_AddNSSFile() called without alias parameter, please update nwnx_util.nss");
        alias = "NWNX";
    }

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_AddNSSFile() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    auto file = CExoFile((alias + ":" + fileName).c_str(), Constants::ResRefType::NSS, "w");

    if (file.FileOpened())
    {
        if (file.Write(contents))
        {
            retVal = file.Flush();
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::RemoveNWNXResourceFile(ArgumentStack&& args)
{
    int32_t retVal;

    const auto fileName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!fileName.empty());
      ASSERT_OR_THROW(fileName.size() <= 16);
    const auto type = Services::Events::ExtractArgument<int32_t>(args);

    std::string alias;
    try
    {
        alias = Services::Events::ExtractArgument<std::string>(args);
    }
    catch (const std::runtime_error& e)
    {
        LOG_WARNING("NWNX_Util_RemoveNWNXResourceFile() called without alias parameter, please update nwnx_util.nss");
        alias = "NWNX";
    }

    if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
    {
        LOG_WARNING("NWNX_Util_RemoveNWNXResourceFile() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
        alias = "NWNX";
    }

    CExoString exoFileName = (alias + ":" + fileName).c_str();

    retVal = Globals::ExoResMan()->RemoveFile(exoFileName, type);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::SetInstructionLimit(ArgumentStack&& args)
{
    const static uint32_t defaultInstructionLimit = Globals::VirtualMachine()->m_nInstructionLimit;
    const auto limit = Services::Events::ExtractArgument<int32_t>(args);

    if (limit < 0)
    {
        // We queue it on the main thread so it'll reset after the current script is done executing
        g_plugin->GetServices()->m_tasks->QueueOnMainThread(
            [](){ Globals::VirtualMachine()->m_nInstructionLimit = defaultInstructionLimit; });
    }
    else
        Globals::VirtualMachine()->m_nInstructionLimit = limit;

    return Services::Events::Arguments();
}

ArgumentStack Util::GetScriptReturnValue(ArgumentStack&&)
{
    int32_t retVal = 0;

    int32_t nParameterType;
    void* pParameter;
    if (Globals::VirtualMachine()->GetRunScriptReturnValue(&nParameterType, &pParameter) && nParameterType == 3) {
        retVal = (intptr_t)pParameter;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::RegisterServerConsoleCommand(ArgumentStack&& args)
{
    const auto command = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!command.empty());
    const auto scriptChunk = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!scriptChunk.empty());

    bool registered = g_plugin->GetServices()->m_commands->RegisterCommand(command, [](std::string &command, std::string &args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        LOG_INFO("Executing NWScript Server Console Command: '%s' with args: %s", command, args);

        std::string scriptChunk = g_plugin->m_serverConsoleCommandMap[command];
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
        g_plugin->m_serverConsoleCommandMap[command] = scriptChunk;

    return Services::Events::Arguments(registered);
}

ArgumentStack Util::UnregisterServerConsoleCommand(ArgumentStack&& args)
{
    const auto command = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!command.empty());

    if (g_plugin->m_serverConsoleCommandMap.find(command) != g_plugin->m_serverConsoleCommandMap.end())
    {
        g_plugin->GetServices()->m_commands->UnregisterCommand(command);
        g_plugin->m_serverConsoleCommandMap.erase(command);
    }

    return Services::Events::Arguments();
}

ArgumentStack Util::PluginExists(ArgumentStack&& args)
{
    auto pluginName = Services::Events::ExtractArgument<std::string>(args);

    return GetServices()->m_plugins->FindPluginByName(pluginName) ? Services::Events::Arguments(1) : Services::Events::Arguments(0);
}

ArgumentStack Util::GetUserDirectory(ArgumentStack&&)
{
    return Services::Events::Arguments(Globals::ExoBase()->m_sUserDirectory.CStr());
}

ArgumentStack Util::CreateDoor(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    const auto strResRef = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!strResRef.empty());
    const auto oidArea = Services::Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(oidArea != Constants::OBJECT_INVALID);
    const auto posX = Services::Events::ExtractArgument<float>(args);
    const auto posY = Services::Events::ExtractArgument<float>(args);
    const auto posZ = Services::Events::ExtractArgument<float>(args);
    const auto facing = Services::Events::ExtractArgument<float>(args);
    const auto tag = Services::Events::ExtractArgument<std::string>(args);

    int32_t appearance = -1;
    try
    {
        appearance = Services::Events::ExtractArgument<int32_t>(args);
    }
    catch (const std::runtime_error& e)
    {
        LOG_WARNING("NWNX_Util_CreateDoor() called without appearance parameter, please update nwnx_util.nss");
    }

    auto resRef = CResRef(strResRef);
    Vector position = {posX, posY, posZ};

    if (!Globals::ExoResMan()->Exists(resRef, Constants::ResRefType::UTD, nullptr))
    {
        LOG_WARNING("CreateDoor: ResRef '%s' does not exist", resRef.GetResRefStr());
        return Services::Events::Arguments(Constants::OBJECT_INVALID);
    }

    if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(oidArea)))
    {
        CResStruct resStruct{};
        CResGFF gff(Constants::ResRefType::UTD, "UTD ", resRef);

        if (gff.m_bLoaded)
        {
            auto *pDoor = new CNWSDoor();
            gff.GetTopLevelStruct(&resStruct);

            pDoor->m_sTemplate = resRef.GetResRefStr();
            pDoor->LoadDoor(&gff, &resStruct);
            pDoor->LoadVarTable(&gff, &resStruct);
            pDoor->SetPosition(position);
            if (appearance >= 0)
                pDoor->m_nAppearanceType = appearance;
            Utils::SetOrientation(pDoor, facing);

            if (!tag.empty())
            {
                pDoor->m_sTag = CExoString(tag.c_str());
                Utils::GetModule()->AddObjectToLookupTable(pDoor->m_sTag, pDoor->m_idSelf);
            }

            pDoor->AddToArea(pArea, posX, posY, pArea->ComputeHeight(position));

            retVal = pDoor->m_idSelf;
        }
        else
            LOG_WARNING("CreateDoor: Unable to load ResRef: %s", resRef.GetResRefStr());
    }
    else
        LOG_WARNING("CreateDoor: Invalid Area");

    return Services::Events::Arguments(retVal);
}

ArgumentStack Util::SetItemActivator(ArgumentStack&& args)
{
    const auto objectId = Services::Events::ExtractArgument<ObjectID>(args);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    if (pGameObject)
      Utils::GetModule()->m_oidLastItemActivator = pGameObject->m_idSelf;
    else
      Utils::GetModule()->m_oidLastItemActivator = Constants::OBJECT_INVALID;

    return Services::Events::Arguments();
}

ArgumentStack Util::GetWorldTime(ArgumentStack&& args)
{
    const auto adjustment = Services::Events::ExtractArgument<float>(args);

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

    return Services::Events::Arguments((int32_t)retvalCalendarDay, (int32_t)retvalTimeOfDay);
}

ArgumentStack Util::SetResourceOverride(ArgumentStack&& args)
{
    auto resType = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(resType >= Constants::ResRefType::MIN);
      ASSERT_OR_THROW(resType <= Constants::ResRefType::MAX);
    auto oldName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!oldName.empty());
      ASSERT_OR_THROW(oldName.size() <= 16);
    auto newName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(newName.size() <= 16);

    if (newName.empty())
        Globals::ExoResMan()->RemoveOverride(oldName.c_str(), resType);
    else
        Globals::ExoResMan()->AddOverride(oldName.c_str(), newName.c_str(), resType);

    return Services::Events::Arguments();
}

ArgumentStack Util::GetResourceOverride(ArgumentStack&& args)
{
    auto resType = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(resType >= Constants::ResRefType::MIN);
      ASSERT_OR_THROW(resType <= Constants::ResRefType::MAX);
    auto resName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!resName.empty());
      ASSERT_OR_THROW(resName.size() <= 16);

    std::string overrideResName = Globals::ExoResMan()->GetOverride(resName.c_str(), resType).GetResRefStr();

    return overrideResName == resName ? "" : overrideResName;
}

ArgumentStack Util::GetScriptParamIsSet(ArgumentStack&& args)
{
    int32_t retVal = false;

    const auto paramName = Services::Events::ExtractArgument<std::string>(args);
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

    return Services::Events::Arguments(retVal);
}

}
