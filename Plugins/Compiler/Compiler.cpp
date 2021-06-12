#include "nwnx.hpp"

#include "API/CScriptCompiler.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoResMan.hpp"

#include <dirent.h>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

namespace Compiler
{
using namespace NWNXLib;
using namespace API;

static bool DirectoryExists(const std::string& path);
static bool CompiledOutputIsNewer(const std::string& sourceFile, const std::string& outputFile);
static std::vector<std::string> GetFiles(const std::string& path, const std::string& extension);
static void CleanOutput(const std::string& outputPath);
static void CreateResourceDirectory(const CExoString& alias, const std::string& path, uint32_t priority);
static std::unique_ptr<CScriptCompiler> CreateAndConfigureCompiler(const CExoString&);
static int Compile(const std::string& sourcePath, const std::string& outputPath, std::unique_ptr<CScriptCompiler> scriptCompiler);

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

    const auto& sourcePath = source.value();
    const auto& outputPath = output.value();

    if (sourcePath == outputPath)
    {
        LOG_INFO("Skipping compilation. NWNX_COMPILER_SRC_DIR must not be the same path as NWNX_COMPILER_OUT_DIR.");
        return;
    }

    if (!DirectoryExists(sourcePath))
    {
        LOG_INFO("Skipping compilation. Cannot find or access source directory %s.", source.value());
        return;
    }

    if (!DirectoryExists(outputPath))
    {
        mkdir(outputPath.c_str(), 0);
        if (!DirectoryExists(outputPath))
        {
            LOG_INFO("Skipping compilation. Cannot write to output directory %s.", source.value());
            return;
        }
    }
    else if (Config::Get<bool>("CLEAN_COMPILE", false))
    {
        CleanOutput(outputPath);
    }

    const auto sourceAlias = CExoString("NWNXCOMPILE_SRC");
    const auto outputAlias = CExoString("NWNXCOMPILE_OUT");

    if (!Globals::ExoBase()->m_pcExoAliasList->GetAliasPath(outputAlias).IsEmpty())
    {
        LOG_WARNING("Skipping compilation. A Resource Directory with %s already exists. Please remove this entry from nwn.ini.", outputAlias.CStr());
        return;
    }

    Tasks::QueueOnMainThread([sourceAlias, sourcePath, outputAlias, outputPath]
    {
        CreateResourceDirectory(sourceAlias, sourcePath, 90000001);
        CreateResourceDirectory(outputAlias, outputPath, 90000000);

        const auto result = Compile(sourcePath, outputPath, CreateAndConfigureCompiler(outputAlias));

        if (Config::Get<bool>("EXIT_ON_COMPLETE", true))
        {
            exit(result);
        }
    });
}

static bool DirectoryExists(const std::string& path)
{
    return access(path.c_str(), F_OK) == 0;
}

static bool CompiledOutputIsNewer(const std::string& sourceFile, const std::string& outputFile)
{
    struct stat sourceInfo{};
    struct stat outputInfo{};

    stat(sourceFile.c_str(), &sourceInfo);

    return stat(outputFile.c_str(), &outputInfo) == 0 && outputInfo.st_mtim.tv_sec > sourceInfo.st_mtim.tv_sec;
}

static std::vector<std::string> GetFiles(const std::string& path, const std::string& extension)
{
    std::vector<std::string> files;
    if (auto* dir = opendir(path.c_str()))
    {
        while (auto* entry = readdir(dir))
        {
            if ((entry->d_type == DT_UNKNOWN || entry->d_type == DT_REG || entry->d_type == DT_LNK) && String::EndsWith(entry->d_name, extension))
            {
                files.emplace_back(entry->d_name);
            }
        }
        closedir(dir);
    }

    std::sort(std::begin(files), std::end(files));

    return files;
}

static void CleanOutput(const std::string& outputPath)
{
    const auto files = GetFiles(outputPath, ".ncs");
    for (const auto& file : files)
    {
        remove(file.c_str());
    }
}

static void CreateResourceDirectory(const CExoString& alias, const std::string& path, uint32_t priority)
{
    const auto qualifiedAlias = alias + ":";

    Globals::ExoBase()->m_pcExoAliasList->Add(qualifiedAlias, path.c_str());
    Globals::ExoResMan()->CreateDirectory(qualifiedAlias);
    Globals::ExoResMan()->AddResourceDirectory(qualifiedAlias, priority, false);
}

static std::unique_ptr<CScriptCompiler> CreateAndConfigureCompiler(const CExoString& outputAlias)
{
    auto scriptCompiler = std::make_unique<CScriptCompiler>();

    scriptCompiler->SetCompileDebugLevel(Config::Get<int>("DEBUG_LEVEL", 0));
    scriptCompiler->SetCompileSymbolicOutput(Config::Get<int>("SYMBOLIC_OUTPUT", 0));
    scriptCompiler->SetGenerateDebuggerOutput(Config::Get<int>("GENERATE_DEBUGGER_OUTPUT", 0));
    scriptCompiler->SetOptimizeBinaryCodeLength(Config::Get<bool>("OPTIMIZE_BINARY_CODE_LENGTH", true));
    scriptCompiler->SetIdentifierSpecification("nwscript");
    scriptCompiler->SetCompileConditionalOrMain(true);
    scriptCompiler->SetCompileConditionalFile(true);
    scriptCompiler->SetAutomaticCleanUpAfterCompiles(false);

    scriptCompiler->SetOutputAlias(outputAlias);

    return scriptCompiler;
}

static int Compile(const std::string& sourcePath, const std::string& outputPath, std::unique_ptr<CScriptCompiler> scriptCompiler)
{
    const auto continueOnError = Config::Get<bool>("CONTINUE_ON_ERROR", false);
    auto exitCode = 0;

    const auto sourceFiles = GetFiles(sourcePath, ".nss");

    const auto fileCount = sourceFiles.size();
    auto progress = 0;

    for (const auto& sourceFile : sourceFiles)
    {
        ++progress;
        auto scriptName = String::Basename(sourceFile);

        auto sourceFilePath = sourcePath;
        sourceFilePath.append("/").append(sourceFile);

        auto outFilePath = outputPath;
        outFilePath.append("/").append(scriptName).append(".ncs");

        if (CompiledOutputIsNewer(sourceFilePath, outFilePath))
        {
            continue;
        }

        LOG_INFO("[%i/%i] Compiling: %s", progress, fileCount, sourceFilePath.c_str());

        std::ifstream sourceStream(sourceFilePath);
        std::string sourceContent((std::istreambuf_iterator<char>(sourceStream)), std::istreambuf_iterator<char>());

        const auto compileResult = scriptCompiler->CompileFile(scriptName);
        if (compileResult == 0)
        {
            LOG_INFO("[%i/%i] Succeeded: %s", progress, fileCount, outFilePath);
        }
        else
        {
            const auto* error = scriptCompiler->m_sCapturedError.CStr();

            if (String::EndsWith(error, "NO FUNCTION MAIN() IN SCRIPT\n"))
            {
                LOG_INFO("Skipping include file %s: The file does not define a main() or StartingConditional() function.", sourceFilePath);
                continue;
            }

            exitCode = compileResult;
            LOG_ERROR("Failed: %s", error);
            if (!continueOnError)
            {
                break;
            }
        }
    }

    return exitCode;
}
}
