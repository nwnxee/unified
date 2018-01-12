#include "CScriptSourceFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CScriptSourceFile::CScriptSourceFile()
{
    CScriptSourceFile__CScriptSourceFileCtor__0(this);
}

CScriptSourceFile::~CScriptSourceFile()
{
    CScriptSourceFile__CScriptSourceFileDtor__0(this);
}

int32_t CScriptSourceFile::LoadScript(const CExoString& a0, char** a1, uint32_t* a2)
{
    return CScriptSourceFile__LoadScript(this, a0, a1, a2);
}

void CScriptSourceFile::UnloadScript()
{
    return CScriptSourceFile__UnloadScript(this);
}

void CScriptSourceFile__CScriptSourceFileCtor__0(CScriptSourceFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptSourceFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptSourceFile__CScriptSourceFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptSourceFile__CScriptSourceFileDtor__0(CScriptSourceFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptSourceFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptSourceFile__CScriptSourceFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CScriptSourceFile__LoadScript(CScriptSourceFile* thisPtr, const CExoString& a0, char** a1, uint32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptSourceFile*, const CExoString&, char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptSourceFile__LoadScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CScriptSourceFile__UnloadScript(CScriptSourceFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptSourceFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptSourceFile__UnloadScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
