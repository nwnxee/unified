#include "Loader.hpp"
#include <string>
#include <iostream>
#include <algorithm>

static const std::string DEFAULT_FILE_NAME = R"(nwserver.exe)";
static const std::string DEFAULT_DLL_NAME = R"(NWNX_Core.dll)";

int main(int argc, char* argv[])
{
    Loader::StartupArgs args;

    // The first param is always the file name.
    args.loaderPath = std::string{argv[0]};

    for (int i = 1; i < argc; ++i)
    {
        std::string currentArg{argv[i]};
        std::transform(currentArg.begin(), currentArg.end(), currentArg.begin(), tolower);

        if (argc > i + 1)
        {
            std::string argumentParam{argv[i]};

            if (currentArg == "-dllname")
            {
                ++i;
                args.dllName = std::move(argumentParam);
            }
            else if (currentArg == "-filename")
            {
                ++i;
                args.fileName = std::move(argumentParam);
            }
            else if (currentArg == "-fileargs")
            {
                ++i;
                args.fileArgs = std::move(argumentParam);
            }
            else
            {
                std::cout << "Invalid argument:" << currentArg << std::endl;
                std::cout << R"(Valid arguments: -dllname "[name]" -filename "[name]" -fileargs "[args]")";
            }
        }
    }

    if (args.dllName.empty())
    {
        args.dllName = DEFAULT_DLL_NAME;
    }

    if (args.fileName.empty())
    {
        args.fileName = DEFAULT_FILE_NAME;
    }

    try
    {
        Loader::Loader loader{args};
    }
    catch (std::exception& ex)
    {
        std::cout << "Caught exception '" << ex.what() << "' while injecting." << std::endl;
        std::cout << "Press any key to exit." << std::endl;
        std::cin.get();
    }
}
