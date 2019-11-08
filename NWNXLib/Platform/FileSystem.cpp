#include "Platform/FileSystem.hpp"
#include "Assert.hpp"


#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>


namespace NWNXLib::Platform::FileSystem {

FileMap GetAllFilesInDirectory(std::string directory)
{
    FileMap files;
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

        if (extension == "so")
            dynamicLibraries.insert(std::move(file));
    }

    return dynamicLibraries;
}


std::string GetCurDirectory()
{
    return std::string{"."};
}

std::string GetCurExecutablePath()
{
    std::array<char, 256> buffer;
    readlink("/proc/self/exe", buffer.data(), buffer.size() - 1);

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
    const std::string separator = "/";

    const bool hasSeparator = std::equal(separator.begin(), separator.end(), pathOne.rbegin());
    return hasSeparator ? pathOne + pathTwo : pathOne + separator + pathTwo;
}


bool FileExists(const std::string& fileName)
{
    return access(fileName.c_str(), F_OK) == 0;
}

void RemoveFile(const std::string& fileName)
{
    unlink(fileName.c_str());
}
void RenameFile(const std::string& oldName, const std::string& newName)
{
    if (FileExists(newName))
        RemoveFile(newName);
    rename(oldName.c_str(), newName.c_str());
}

}
