// We need this because MSVC bitches about std::string::copy.
#ifndef _SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define __INTERNAL__UNDO_AFTER_FILE
#endif

#include "Loader.hpp"
#include <iostream>
#include <shlwapi.h>

namespace Loader
{

Loader::Loader(const StartupArgs& args)
    : m_startupArgs(args)
{
    m_processInfo = { new PROCESS_INFORMATION{},
        [](PROCESS_INFORMATION* procInfo)
        {
            if (procInfo->hProcess != nullptr)
            {
                CloseHandle(procInfo->hProcess);
            }

            if (procInfo->hThread != nullptr)
            {
                CloseHandle(procInfo->hThread);
            }
        } };

    startRemoteProcess();
    injectDllIntoRemoteProcess();
}

Loader::~Loader()
{
}

bool Loader::processRunning() const
{
    DWORD exitCode{};
    GetExitCodeProcess(m_processInfo->hProcess, &exitCode);
    return exitCode == STILL_ACTIVE;
}

void Loader::startRemoteProcess()
{
    const std::string path = getWindowsPath(m_startupArgs.fileName, MAX_PATH);

    if (path.empty())
    {
        throw std::logic_error{"Could not locate the path to the executable."};
    }

    const std::string& argsString = m_startupArgs.fileArgs;
    char* args = new char[MAX_PATH];
    argsString.copy(args, argsString.length(), 0);
    args[argsString.length()] = '\0';

    std::cout << "Full path to the executable is '" << path << "' with args '" << args << "'." << std::endl;

    STARTUPINFO startupInfo;
    GetStartupInfo(&startupInfo);

    if(FAILED(CreateProcess(path.c_str(),
                            args,
                            nullptr,
                            nullptr,
                            false,
                            NORMAL_PRIORITY_CLASS,
                            nullptr,
                            nullptr,
                            &startupInfo,
                            m_processInfo.get())))
    {
        throw std::logic_error{"Failed to open the remote process."};
    }

    delete[] args;
}

void Loader::injectDllIntoRemoteProcess()
{
    const std::string path = getWindowsPath(m_startupArgs.dllName, MAX_PATH);
    const auto pathLen = path.length() + 1;

    if (path.empty())
    {
        throw std::logic_error{"Could not locate the path to the library."};
    }

    std::cout << "Full path to the core library is '" << path << "'." << std::endl;

    void* remoteDllPath = VirtualAllocEx(m_processInfo->hProcess,
                                         nullptr,
                                         pathLen,
                                         MEM_COMMIT | MEM_RESERVE,
                                         PAGE_READWRITE);

    if (remoteDllPath == nullptr)
    {
        throw std::logic_error{"Failed to allocate memory for the DLL path in the remote process."};
    }

    if (FAILED(WriteProcessMemory(m_processInfo->hProcess,
                                  remoteDllPath,
                                  path.c_str(),
                                  pathLen,
                                  nullptr)))
    {
        throw std::logic_error{"Failed to write the DLL path to the remote process."};
    }

    HANDLE remoteThreadHandle = CreateRemoteThread(m_processInfo->hProcess,
                                                   nullptr,
                                                   0,
                                                   reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA")), 
                                                   remoteDllPath,
                                                   0,
                                                   nullptr);

    if (remoteThreadHandle == nullptr)
    {
        throw std::logic_error{"Failed to create a thread in the remote process."};
    }

    WaitForSingleObject(remoteThreadHandle, INFINITE);
    VirtualFreeEx(m_processInfo->hProcess, remoteDllPath, MAX_PATH, MEM_RELEASE);
    DWORD exitCode{};
    GetExitCodeThread(remoteThreadHandle, &exitCode);
    CloseHandle(remoteThreadHandle);

    std::cout << "Injected DLL into the remote process. Thread exited with code '" << exitCode << "'." << std::endl;
}

std::string Loader::getWindowsPath(const std::string& path, const size_t bufferSize)
{
    char* buffer = new char[bufferSize];
    // First assume the path is a path relative to the working directory.
    GetFullPathName(path.c_str(), bufferSize, buffer, nullptr);

    if (!PathFileExists(buffer))
    {
        // If this isn't a case, assume it's a path relative to the current executable location.
        const std::string& loaderPath = m_startupArgs.loaderPath;
        memset(buffer, 0, sizeof(char) * bufferSize);
        loaderPath.copy(buffer, loaderPath.length(), 0);
        buffer[loaderPath.length()] = '\0';
        PathRemoveFileSpec(buffer);
        PathCombine(buffer, buffer, path.c_str());

        if (!PathFileExists(buffer))
        {
            // Now we assume that it's an absolute path.
            memset(buffer, 0, sizeof(char) * bufferSize);
            path.copy(buffer, path.length(), 0);
            buffer[path.length()] = '\0';

            if (!PathFileExists(buffer))
            {
                // No hits -- so this path is definitely invalid.
                delete[] buffer;
                return {};
            }
        }
    }

    std::string absPath{buffer};
    delete[] buffer;
    return std::move(absPath);
}

}

#ifdef __INTERNAL__UNDO_AFTER_FILE
#undef _SCL_SECURE_NO_WARNINGS
#undef __INTERNAL__UNDO_AFTER_FILE
#endif
