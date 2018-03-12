#include "Platform/FileSystem.hpp"
#include "Assert.hpp"

#ifdef _WIN32
    #include "Windows.h"
    #include <thread>
#else
    #include <dirent.h>
    #include <unistd.h>
    #include <sys/stat.h>
#endif

namespace NWNXLib {

namespace Platform {

namespace FileSystem {

FileMap GetAllFilesInDirectory(std::string directory)
{
    FileMap files;

#ifdef _WIN32
    // Windows needs \* appended to the search.
    directory.append("\\*");

    HANDLE findHandle;
    WIN32_FIND_DATA findData;

    findHandle = FindFirstFileA(directory.c_str(), &findData);

    if (findHandle != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                FileName name = findData.cFileName;
                assert(files.find(name) == files.end());

                FileData data
                {
                    findData.ftLastWriteTime.dwLowDateTime, findData.nFileSizeLow
                };

                files.insert(std::make_pair(std::move(name), std::move(data)));
            }
        } while (FindNextFileA(findHandle, &findData));
    }

    FindClose(findHandle);
#else
    DIR* dir = opendir(directory.c_str());

    if (dir != nullptr)
    {
        dirent* directoryEntry = readdir(dir);

        while (directoryEntry != nullptr)
        {
            if (directoryEntry->d_type == DT_UNKNOWN || directoryEntry->d_type == DT_REG)
            {
                FileName name = directoryEntry->d_name;
                ASSERT(files.find(name) == files.end());

                const std::string fullFilePath = CombinePaths(directory, name);
                struct stat fileStatistics;
                stat(fullFilePath.c_str(), &fileStatistics);

                FileData data
                {
                    static_cast<uint32_t>(fileStatistics.st_mtime),
                    static_cast<uint32_t>(fileStatistics.st_size)
                };

                files.insert(std::make_pair(std::move(name), std::move(data)));
            }

            directoryEntry = readdir(dir);
        }

        closedir(dir);
    }
#endif

    return files;
}

FileMap GetAllDynamicLibrariesInDirectory(std::string directory)
{
    FileMap allFiles = GetAllFilesInDirectory(std::move(directory));
    FileMap dynamicLibraries;

    for (auto& file : allFiles)
    {
        const std::string& name = file.first;
        const std::string extension = name.substr(name.find_last_of(".") + 1);

#ifdef _WIN32
        if (extension == "dll")
#else
        if (extension == "so")
#endif

        dynamicLibraries.insert(std::move(file));
    }

    return dynamicLibraries;
}


std::string GetCurDirectory()
{
#ifdef _WIN32
    std::array<char, MAX_PATH> buffer;
    GetCurrentDirectory(buffer.size(), buffer.data());
#else
    std::array<char, 2> buffer = { '.', '\0' };
#endif

    return std::string(buffer.data());
}

std::string GetCurExecutablePath()
{
#ifdef _WIN32
    std::array<char, MAX_PATH> buffer;
    GetModuleFileNameA(nullptr, buffer.data(), buffer.size());
#else
    std::array<char, 256> buffer;
    readlink("/proc/self/exe", buffer.data(), buffer.size() - 1);
#endif

    return RemoveFileNameFromPath(buffer.data());
}

std::string StripExtensionFromFileName(const std::string& fileName)
{
    return fileName.substr(0, fileName.find_last_of('.'));
}

std::string RemoveFileNameFromPath(const std::string& path)
{
    return path.substr(0, path.find_last_of("/\\"));
}

std::string CombinePaths(const std::string& pathOne, const std::string& pathTwo)
{
#ifdef _WIN32
    const std::string separator = "\\";
#else
    const std::string separator = "/";
#endif

    const bool hasSeparator = std::equal(separator.begin(), separator.end(), pathOne.rbegin());
    return hasSeparator ? pathOne + pathTwo : pathOne + separator + pathTwo;
}


bool FileExists(const std::string& fileName)
{
#ifdef _WIN32
    DWORD dwAttrib = GetFileAttributes(szPath);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
#else
    return access(fileName.c_str(), F_OK) == 0;
#endif
}

void RemoveFile(const std::string& fileName)
{
#ifdef _WIN32
    DeleteFile(fileName.c_str());
#else
    unlink(fileName.c_str());
#endif
}
void RenameFile(const std::string& oldName, const std::string& newName)
{
    if (FileExists(newName))
        RemoveFile(newName);
    rename(oldName.c_str(), newName.c_str());
}

}

}

}
