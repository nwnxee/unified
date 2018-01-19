#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoFile;

struct CExoPackedFile
{
    void** m_vtable;
    CExoString m_sFileName;
    uint16_t m_wDrives;
    uint32_t m_nFileSize;
    CExoFile* m_pExoFile;
    CExoFile* m_pAsyncExoFile;
    int32_t m_nRefCount;
    int32_t m_nAsyncRefCount;
    int32_t m_bLoaded;
    int32_t m_bAsyncLoaded;
    int32_t m_bHeaderLoaded;

    // The below are auto generated stubs.
    CExoPackedFile(const CExoPackedFile&) = default;
    CExoPackedFile& operator=(const CExoPackedFile&) = default;

    CExoPackedFile();
    ~CExoPackedFile();
    CExoFile* GetAsyncFile();
    CExoFile* GetFile();
};

void CExoPackedFile__CExoPackedFileCtor(CExoPackedFile* thisPtr);
void CExoPackedFile__CExoPackedFileDtor__0(CExoPackedFile* thisPtr);
CExoFile* CExoPackedFile__GetAsyncFile(CExoPackedFile* thisPtr);
CExoFile* CExoPackedFile__GetFile(CExoPackedFile* thisPtr);

}

}
