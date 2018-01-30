#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace NWNXLib {

namespace Platform {

namespace FileSystem {

struct FileData
{
    uint32_t m_modified;
    uint32_t m_size;
};

using FileName = std::string;
using FileMap = std::unordered_map<FileName, FileData>;

struct File
{
    FileName m_name;
    FileData m_data;
};

// Freestanding functions
FileMap GetAllFilesInDirectory(std::string directory);
FileMap GetAllDynamicLibrariesInDirectory(std::string directory);
std::string GetCurDirectory();
std::string GetCurExecutablePath();
std::string StripExtensionFromFileName(const std::string& fileName);
std::string RemoveFileNameFromPath(const std::string& path);
std::string CombinePaths(const std::string& pathOne, const std::string& pathTwo);
bool FileExists(const std::string& fileName);
void RemoveFile(const std::string& fileName);
void RenameFile(const std::string& oldName, const std::string& newName);
}

}

}
