#pragma once

#include <windows.h>
#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace Loader
{

struct StartupArgs
{
    std::string loaderPath;
    std::string fileName;
    std::string fileArgs;
    std::string dllName;
};

class Loader
{
public:
    Loader(const StartupArgs& args);
    ~Loader();

    bool processRunning() const;

private:
    void startRemoteProcess();
    void injectDllIntoRemoteProcess();
    std::string getWindowsPath(const std::string& path, const size_t bufferSize);

    std::unique_ptr<PROCESS_INFORMATION, std::function<void(PROCESS_INFORMATION*)>> m_processInfo;
    const StartupArgs m_startupArgs;
};

}
