#include "nwnx.hpp"

#include "API/CScriptCompiler.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoResMan.hpp"

#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

#include "API/CTlkTable.hpp"

namespace Compiler
{
using namespace NWNXLib;
using namespace API;

static bool DirectoryExists(const std::string& path);
static std::vector<std::string> GetFiles(const std::string& path, const std::string& extension);
static void CleanOutput(const std::string& outputPath);
static void CreateResourceDirectory(const CExoString& alias, const std::string& path, uint32_t priority);
static std::unique_ptr<CScriptCompiler> CreateAndConfigureCompiler(const CExoString&);
static int Compile(const std::string& sourcePath, const std::string& outputPath,
                   std::unique_ptr<CScriptCompiler> scriptCompiler);
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

        RemoveResourceDirectory(sourceAlias);
        RemoveResourceDirectory(outputAlias);

        if (Config::Get<bool>("EXIT_ON_COMPLETE", true))
        {
            exit(result);
        }
    });
}

static bool DirectoryExists(const std::string& path)
{
    struct stat info;
    return stat(path.c_str(), &info) == 0 && info.st_mode & S_IFDIR;
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
    Globals::ExoBase()->m_pcExoAliasList->Add(alias, path.c_str());
    Globals::ExoResMan()->CreateDirectory(alias);
    Globals::ExoResMan()->AddResourceDirectory(alias, priority, true);
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
    scriptCompiler->SetIdentifierSpecification("nwscript");
    scriptCompiler->SetCompileConditionalOrMain(true);
    scriptCompiler->SetCompileConditionalFile(true);
    scriptCompiler->SetAutomaticCleanUpAfterCompiles(true);

    scriptCompiler->SetOutputAlias(outputAlias);

    return scriptCompiler;
}

static int Compile(const std::string& sourcePath, const std::string& outputPath, std::unique_ptr<CScriptCompiler> scriptCompiler)
{
    const auto continueOnError = Config::Get<bool>("CONTINUE_ON_ERROR", false);
    auto exitCode = 0;

    const auto sourceFiles = GetFiles(sourcePath, ".nss");
    for (const auto& sourceFile : sourceFiles)
    {
        auto scriptName = String::Basename(sourceFile);

        auto sourceFilePath = sourcePath;
        sourceFilePath.append("/").append(sourceFile);

        auto outFilePath = outputPath;
        outFilePath.append("/").append(scriptName).append(".ncs");

        LOG_INFO("Compiling: %s", sourceFilePath.c_str());

        std::ifstream sourceStream(sourceFilePath);
        std::string sourceContent((std::istreambuf_iterator<char>(sourceStream)), std::istreambuf_iterator<char>());

        const auto compileResult = scriptCompiler->CompileScriptChunk(sourceContent.c_str(), false);
        if (compileResult == 0)
        {
            auto writeFileResult = scriptCompiler->WriteFinalCodeToFile(scriptName);
            LOG_INFO("Succeeded: %s", outFilePath);

            if (writeFileResult != 0)
            {
                exitCode = writeFileResult;
                LOG_ERROR("Write failed: %s", Globals::TlkTable()->GetSimpleString(abs(writeFileResult)).CStr());
                if (!continueOnError)
                {
                    break;
                }
            }
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
