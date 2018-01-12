#include "CExoPackedFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoFile.hpp"

namespace NWNXLib {

namespace API {

CExoPackedFile::CExoPackedFile()
{
    CExoPackedFile__CExoPackedFileCtor(this);
}

CExoPackedFile::~CExoPackedFile()
{
    CExoPackedFile__CExoPackedFileDtor__0(this);
}

CExoFile* CExoPackedFile::GetAsyncFile()
{
    return CExoPackedFile__GetAsyncFile(this);
}

CExoFile* CExoPackedFile::GetFile()
{
    return CExoPackedFile__GetFile(this);
}

void CExoPackedFile__CExoPackedFileCtor(CExoPackedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoPackedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoPackedFile__CExoPackedFileCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoPackedFile__CExoPackedFileDtor__0(CExoPackedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoPackedFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoPackedFile__CExoPackedFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoFile* CExoPackedFile__GetAsyncFile(CExoPackedFile* thisPtr)
{
    using FuncPtrType = CExoFile*(__attribute__((cdecl)) *)(CExoPackedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoPackedFile__GetAsyncFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoFile* CExoPackedFile__GetFile(CExoPackedFile* thisPtr)
{
    using FuncPtrType = CExoFile*(__attribute__((cdecl)) *)(CExoPackedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoPackedFile__GetFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
