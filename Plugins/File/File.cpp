#include "nwnx.hpp"

#include <filesystem>
#include <fstream>


using namespace NWNXLib;
using namespace NWNXLib::API;

namespace fs = std::filesystem;


std::string ValidateFilePath(const std::string& filename)
{
    if (filename.length() >= 255)
    {
      LOG_ERROR("Passed filename is too long.");
      return "";
    }

    std::string filepath = fs::current_path();

    while (true)
    {
        if (fs::is_directory(filepath + "/logs.0"))
            return filepath + "/logs.0/" + filename;

        std::size_t nloc = filepath.rfind("/");
        if (nloc == std::string::npos)
            return "";

        filepath = filepath.substr(0, nloc);
        if (filepath.length() <= 1)
            return "";
    }
}

NWNX_EXPORT ArgumentStack FileTruncate(ArgumentStack&& args)
{
    const auto filename = args.extract<std::string>();

    std::string filepath = ValidateFilePath(filename);
    if (!filepath.length())
      return {};

    std::ofstream outfile(filepath, std::ios_base::out);

    return {};
}

NWNX_EXPORT ArgumentStack FileAppend(ArgumentStack&& args)
{
    const auto filename = args.extract<std::string>();
    const auto line = args.extract<std::string>();

    if (line.length() >= 4096)
    {
      LOG_ERROR("Passed line is too long.");
      return "";
    }

    std::string filepath = ValidateFilePath(filename);
    if (!filepath.length())
      return {};

    std::ofstream outfile(filepath, std::ios_base::app);
    outfile << line << "\n";

    return {};
}
