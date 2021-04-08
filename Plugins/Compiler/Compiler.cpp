#include "nwnx.hpp"

#include "API/CScriptCompiler.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoResMan.hpp"

#include <filesystem>

namespace Compiler
{

using namespace NWNXLib;
using namespace API;

static void CleanOutput(const std::filesystem::path&);
static void CreateResourceDirectory(const CExoString&, const std::filesystem::path&);
static std::unique_ptr<CScriptCompiler> CreateAndConfigureCompiler(const CExoString&);
static int Compile(const std::filesystem::path&, const std::filesystem::path&, std::unique_ptr<CScriptCompiler>);
static void RemoveResourceDirectory(const CExoString&);

void Compiler() __attribute__((constructor));

void Compiler()
{
    const auto source = Config::Get<std::string>("SRC_DIR");
    const auto output = Config::Get<std::string>("OUT_DIR");

    if (!source.has_value() || !output.has_value())
    {
        LOG_INFO("Skipping compilation. NWNX_COMPILER_SRC_DIR or NWNX_COMPILER_OUT_DIR was not specified.");
        return;
    }

    const std::filesystem::path sourcePath(source.value());
    const std::filesystem::path outputPath(output.value());

    if (sourcePath == outputPath)
    {
        LOG_INFO("Skipping compilation. NWNX_COMPILER_SRC_DIR must not be the same path as NWNX_COMPILER_OUT_DIR.");
        return;
    }

    if (!exists(sourcePath))
    {
        LOG_INFO("Skipping compilation. Source directory %s does not exist.", source.value());
        return;
    }

    if (Config::Get<bool>("CLEAN_COMPILE", false) && exists(outputPath))
    {
        CleanOutput(output.value());
    }

    const auto sourceAlias = CExoString("NWNXCOMPILE_SRC");
    const auto outputAlias = CExoString("NWNXCOMPILE_OUT");

    if (!Globals::ExoBase()->m_pcExoAliasList->GetAliasPath(sourceAlias).IsEmpty() || !Globals::ExoBase()->m_pcExoAliasList->GetAliasPath(outputAlias).IsEmpty())
    {
        LOG_WARNING("Skipping compilation. A Resource Directory with %s, or %s already exists. Please remove these entries from nwn.ini.", sourceAlias.CStr(), outputAlias.CStr());
        return;
    }

    CreateResourceDirectory(sourceAlias, sourcePath);
    CreateResourceDirectory(outputAlias, outputPath);

    const auto result = Compile(sourcePath, outputPath, CreateAndConfigureCompiler(outputAlias));

    RemoveResourceDirectory(sourceAlias);
    RemoveResourceDirectory(outputAlias);

    if (Config::Get<bool>("EXIT_ON_COMPLETE", true))
    {
        exit(result);
    }
}

static void CleanOutput(const std::filesystem::path& outputPath)
{
    for (const auto& entry : std::filesystem::directory_iterator(outputPath))
    {
        if (entry.path().extension() == ".ncs")
        {
            std::filesystem::remove(entry.path());
        }
    }
}

static void CreateResourceDirectory(const CExoString& alias, const std::filesystem::path& path)
{
    Globals::ExoBase()->m_pcExoAliasList->Add(alias, path.c_str());
    Globals::ExoResMan()->CreateDirectory(alias);
    Globals::ExoResMan()->AddResourceDirectory(alias, UINT32_MAX, true);
}

static void RemoveResourceDirectory(const CExoString& alias)
{
    Globals::ExoResMan()->RemoveResourceDirectory(alias);
    Globals::ExoBase()->m_pcExoAliasList->Delete(alias);
}

static std::unique_ptr<CScriptCompiler> CreateAndConfigureCompiler(const CExoString& outputAlias)
{
    auto scriptCompiler = std::make_unique<CScriptCompiler>();

    scriptCompiler->SetCompileDebugLevel(Config::Get<int>("DEBUG_LEVEL", 0));
    scriptCompiler->SetCompileSymbolicOutput(Config::Get<int>("SYMBOLIC_OUTPUT", 0));
    scriptCompiler->SetGenerateDebuggerOutput(Config::Get<int>("GENERATE_DEBUGGER_OUTPUT", 0));
    scriptCompiler->SetOptimizeBinaryCodeLength(Config::Get<bool>("OPTIMIZE_BINARY_CODE_LENGTH", true));
    scriptCompiler->SetCompileConditionalOrMain(true);
    scriptCompiler->SetIdentifierSpecification("nwscript");

    scriptCompiler->SetOutputAlias(outputAlias);

    return scriptCompiler;
}

static int Compile(const std::filesystem::path& sourcePath, const std::filesystem::path& outputPath, std::unique_ptr<CScriptCompiler> scriptCompiler)
{
    const auto continueOnError = Config::Get<bool>("CONTINUE_ON_ERROR", false);
    auto exitCode = 0;

    for (const auto& sourceFile : std::filesystem::directory_iterator(sourcePath))
    {
        auto outputFile = outputPath / sourceFile.path().stem() / ".ncs";
        if (exists(outputFile) && last_write_time(outputFile) > sourceFile.last_write_time())
        {
            LOG_INFO("%s - Compilation skipped as the output file is newer.", sourceFile.path().c_str());
            continue;
        }

        LOG_INFO("Compiling: %s", sourceFile.path().c_str());
        const auto result = scriptCompiler->CompileFile(sourceFile.path().filename().c_str());

        if (result == 0)
        {
            LOG_INFO("Succeeded: %s", outputFile.c_str());
        }
        else
        {
            exitCode = result;

            LOG_ERROR("Failed: %s", scriptCompiler->m_sCapturedError.CStr());

            if (!continueOnError)
            {
                break;
            }
        }
    }

    return exitCode;
}

}
