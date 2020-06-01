#include "Test.hpp"

#include "Utils/String.hpp"
#include "External/rang/rang.hpp"
#include "Services/Plugins/Plugins.hpp"
#include "Services/Config/Config.hpp"

#include "API/API/CExoFile.hpp"
#include "API/API/CExoStringList.hpp"
#include "API/API/CKeyTableEntry.hpp"
#include "API/API/CScriptCompiler.hpp"
#include "API/API/CExoResMan.hpp"
#include "API/API/CRes.hpp"

#include <dirent.h>
#include <fstream>
#include <ftw.h>
#include <fnmatch.h>
#include <linux/limits.h>
#include <regex>

Test::Test* g_plugin;

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
        {
            "Test",
            "Test some stuff",
            "jmd",
            "jmd2028@gmail.com",
            1,
            true,
            0
        };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Test::Test(params);
    return g_plugin;
}

namespace Test
{

Test::Test(const Plugin::CreateParams& params)
        : Plugin(params),
            m_compiler{std::make_unique<CScriptCompiler>()}
{
    m_sourceDir = GetServices()->m_config->Get<std::string>("SOURCE_DIR", "");
    m_waitForPC = GetServices()->m_config->Get<bool>("WAIT_FOR_PC", false);

    if (m_sourceDir.empty())
    {
        // Check if the source path used to build exists, if so that's the source dir.
        if (DIR* d = opendir(NWNX_TEST_SOURCE_PATH))
        {
            closedir(d);
            m_sourceDir = NWNX_TEST_SOURCE_PATH;
        }
    }

    if (!m_sourceDir.empty())
        LOG_NOTICE("NWNX:EE Source Directory: %s", m_sourceDir);

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(AddTestScript);
    REGISTER(Context);
    REGISTER(Flush);
    REGISTER(ReportFailure);

#undef REGISTER

    if(!m_waitForPC)
    {
        GetServices()->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSModule16LoadModuleFinishEv, uint32_t>
            (LoadModuleEndHook);
    }
    else
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN21CServerExoAppInternal19LoadCharacterFinishEP10CNWSPlayerii, void, CServerExoAppInternal*, CNWSPlayer*, int32_t, int32_t>
            (LoadCharacterFinishHook);
    }
}

Test::~Test()
{
}

ArgumentStack Test::AddTestScript(ArgumentStack&& args)
{
    auto script = args.extract<std::string>();
        ASSERT_OR_THROW(!script.empty());
    m_extraScripts.insert(std::move(script));
    return {};
}

ArgumentStack Test::Context(ArgumentStack&& args)
{
    auto [message, depth] = args.extract_n<std::string, int32_t>();

    // Align new lines to depth
    std::regex newline("\n");
    message = std::regex_replace(message, newline, "\n" + std::string(2*(depth-1), ' '));

    m_output.emplace_back(std::string(2*(depth-1), ' ') + message, false);
    return {};
}

ArgumentStack Test::Flush(ArgumentStack&& args)
{
    auto [passed, failed, skipped, depth] = args.extract_n<int32_t, int32_t, int32_t, int32_t>();
    bool finished = !!args.extract<int32_t>();

    m_output.emplace_back(tfm::format("%s%d passed, %d failed, %d skipped.", std::string(2*depth, ' '), passed, failed, skipped), false);

    if (finished)
    {
        m_output.emplace_back(std::string(80, '='), false);
    }

    return {};
}

ArgumentStack Test::ReportFailure(ArgumentStack&& args)
{
    auto [failure, message, depth] = args.extract_n<std::string, std::string, int32_t>();

    auto temp = tfm::format("%sFAIL: %s%s",
                            std::string(2*depth, ' '),
                            !message.empty() ? message + " - " : "",
                            failure);
    m_output.emplace_back(std::move(temp), true);
    return {};
}

bool Test::CompileTestScript(const char* name, const char* script)
{
    m_compiler->SetCompileDebugLevel(2);
    m_compiler->SetCompileSymbolicOutput(0);
    m_compiler->SetGenerateDebuggerOutput(0);
    m_compiler->SetOptimizeBinaryCodeLength(true);
    m_compiler->SetCompileConditionalOrMain(true);
    m_compiler->SetIdentifierSpecification("nwscript");
    m_compiler->SetOutputAlias("NWNX");

    if (m_compiler->CompileScriptChunk(script, false) == 0)
    {
        m_compiler->WriteFinalCodeToFile(name);
        return true;
    }
    else
    {
        LOG_ERROR("Script: %s, Error: %s", name, m_compiler->m_sCapturedError.CStr());
        return false;
    }
}

static int get_source_tree_scripts(const char *fpath, const struct stat *, int tflag, struct FTW *)
{
    // We're getting all nss, but we will only run the tests.
    if (tflag == FTW_F && !fnmatch("*.nss", fpath, 0))
    {
        std::string nss = std::string(basename(fpath));
        nss = nss.substr(0, nss.size() - 4);
        LOG_DEBUG("Path: %s %s", nss, fpath);
        g_plugin->m_sourceFiles[nss] = fpath;
    }
    return 0;
}

void Test::HooverTestScripts()
{
    if (!m_sourceDir.empty())
    {
        // TODO: Ultimately it would be best to replace this with std::filesystem, some day?
        if(nftw(m_sourceDir.c_str(), get_source_tree_scripts, 20, FTW_PHYS))
            perror("nftw");
    }

    auto copy = [this](const std::string& fileName, const std::string& contents) {
        auto file = CExoFile(("NWNX:" + fileName).c_str(), Constants::ResRefType::NSS, "w");

        if (file.FileOpened() && file.Write(contents))
        {
            file.Flush();
        }
    };

    for (const auto&[script, path] : m_sourceFiles)
    {
        std::ifstream ifs(path.c_str());
        auto nss = std::string((std::istreambuf_iterator<char>(ifs)),
                               (std::istreambuf_iterator<char>()));
        copy(script, nss);

        std::regex rgx("nwnx_.*_t$");

        if (std::regex_match(script, rgx))
        {
            // TODO: Preprocessing/Parsing?
            CompileTestScript(script.c_str(), nss.c_str());
        }
    }

    auto collectResMan = [this](Constants::ResRefType::TYPE type) {
        CExoStringList *pList = Globals::ExoResMan()->GetResOfType(type);

        if (pList)
        {
            std::regex rgx("nwnx_.*_t");

            for (int i = 0; i < pList->m_nCount; i++)
            {
                if (std::regex_match(pList->m_pStrings[i]->CStr(), rgx))
                {
                    // Using emplace to prioritize first found
                    m_resManFiles.emplace(pList->m_pStrings[i]->CStr(), type);
                    LOG_DEBUG("ResMan file: %s", pList->m_pStrings[i]->CStr());
                }
            }
        }
    };

    collectResMan(Constants::ResRefType::NCS);
    collectResMan(Constants::ResRefType::NSS);
}

void Test::ExecuteTestScript(const std::string& script)
{
    if (script.size() > 16)
    {
       LOG_ERROR("Invalid script name: %s", script);
       return;
    }

    if(!Globals::ExoResMan()->Exists(CResRef(script.c_str()), API::Constants::ResRefType::NCS))
    {
        LOG_ERROR("Script does not exist in the ResMan: %s", script);
        return;
    }

    Utils::ExecuteScript(script, API::Constants::OBJECT_INVALID);
}

void Test::RunTests()
{
    HooverTestScripts();

    m_output.emplace_back("\n" + std::string(80, '=') + "\nRunning Tests...\n" + std::string(80, '='), false);

    for (const auto& [script, type] : m_resManFiles)
    {
        if (type == Constants::ResRefType::NSS)
        {
            // TODO: Compile Scripts test scripts that are in ResMan?
            continue;
        }
        ExecuteTestScript(script);
    }

    for(const auto& script : m_extraScripts)
    {
        ExecuteTestScript(script);
    }

    for(const auto& [line, failure] : m_output)
    {
        if (failure) std::cout << rang::fg::red << rang::style::bold;

        std::cout << line << std::endl;

        if (failure) std::cout << rang::fg::reset << rang::style::reset;
    }

    std::cout << std::string(80, '=') << std::endl;
    m_testsComplete = true;
}

void Test::LoadCharacterFinishHook(bool before, CServerExoAppInternal*, CNWSPlayer*, int32_t, int32_t)
{
    if(before || g_plugin->m_testsComplete) return;
    g_plugin->RunTests();
}

void Test::LoadModuleEndHook(bool before, CNWSModule*)
{
    if (before || g_plugin->m_testsComplete) return;
    g_plugin->RunTests();
}

} // namespace Test
