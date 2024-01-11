/// @addtogroup file File
/// @brief Various file writing functions
/// @{
/// @file nwnx_file.nss
#include "nwnx"

const string NWNX_File = "NWNX_File"; ///< @private

/// @brief Truncate the file
void NWNX_File_Truncate(string filename);

/// @brief Append line to file
void NWNX_File_Append(string filename, string line);

void NWNX_File_Truncate(string filename)
{
    string sFunc = "FileTruncate";

    NWNX_PushArgumentString(filename);
    NWNX_CallFunction(NWNX_File, sFunc);
}

void NWNX_File_Append(string filename, string line)
{
    string sFunc = "FileAppend";

    NWNX_PushArgumentString(line);
    NWNX_PushArgumentString(filename);
    NWNX_CallFunction(NWNX_File, sFunc);
}

