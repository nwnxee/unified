#include "C2DA.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

C2DA::C2DA()
{
    C2DA__C2DACtor__0(this);
}

C2DA::C2DA(CResRef a0, int32_t a1)
{
    C2DA__C2DACtor__1(this, a0, a1);
}

C2DA::~C2DA()
{
    C2DA__C2DADtor__0(this);
}

int32_t C2DA::GetCExoStringEntry(const CExoString& a0, const CExoString& a1, CExoString* a2)
{
    return C2DA__GetCExoStringEntry__0(this, a0, a1, a2);
}

int32_t C2DA::GetCExoStringEntry(int32_t a0, const CExoString& a1, CExoString* a2)
{
    return C2DA__GetCExoStringEntry__1(this, a0, a1, a2);
}

int32_t C2DA::GetCExoStringEntry(int32_t a0, int32_t a1, CExoString* a2)
{
    return C2DA__GetCExoStringEntry__2(this, a0, a1, a2);
}

int32_t C2DA::GetCExoStringEntry(const CExoString& a0, int32_t a1, CExoString* a2)
{
    return C2DA__GetCExoStringEntry__3(this, a0, a1, a2);
}

int32_t C2DA::GetColumnIndex(const CExoString& a0)
{
    return C2DA__GetColumnIndex(this, a0);
}

int32_t C2DA::GetFLOATEntry(const CExoString& a0, int32_t a1, float* a2)
{
    return C2DA__GetFLOATEntry__0(this, a0, a1, a2);
}

int32_t C2DA::GetFLOATEntry(int32_t a0, const CExoString& a1, float* a2)
{
    return C2DA__GetFLOATEntry__1(this, a0, a1, a2);
}

int32_t C2DA::GetFLOATEntry(int32_t a0, int32_t a1, float* a2)
{
    return C2DA__GetFLOATEntry__2(this, a0, a1, a2);
}

int32_t C2DA::GetFLOATEntry(const CExoString& a0, const CExoString& a1, float* a2)
{
    return C2DA__GetFLOATEntry__3(this, a0, a1, a2);
}

int32_t C2DA::GetINTEntry(const CExoString& a0, const CExoString& a1, int32_t* a2)
{
    return C2DA__GetINTEntry__0(this, a0, a1, a2);
}

int32_t C2DA::GetINTEntry(int32_t a0, int32_t a1, int32_t* a2)
{
    return C2DA__GetINTEntry__1(this, a0, a1, a2);
}

int32_t C2DA::GetINTEntry(int32_t a0, const CExoString& a1, int32_t* a2)
{
    return C2DA__GetINTEntry__2(this, a0, a1, a2);
}

int32_t C2DA::GetINTEntry(const CExoString& a0, int32_t a1, int32_t* a2)
{
    return C2DA__GetINTEntry__3(this, a0, a1, a2);
}

uint32_t C2DA::GetNextLineLength(char* a0, uint32_t a1)
{
    return C2DA__GetNextLineLength(this, a0, a1);
}

int32_t C2DA::GetNextToken(char** a0, uint32_t* a1, char* a2, uint32_t a3, uint32_t* a4)
{
    return C2DA__GetNextToken(this, a0, a1, a2, a3, a4);
}

int32_t C2DA::GetRowIndex(const CExoString& a0)
{
    return C2DA__GetRowIndex(this, a0);
}

int32_t C2DA::Load2DArray()
{
    return C2DA__Load2DArray(this);
}

int32_t C2DA::SetBlankEntry(int32_t a0, int32_t a1)
{
    return C2DA__SetBlankEntry__0(this, a0, a1);
}

int32_t C2DA::SetBlankEntry(CExoString a0, CExoString a1)
{
    return C2DA__SetBlankEntry__1(this, a0, a1);
}

int32_t C2DA::SetBlankEntry(CExoString a0, int32_t a1)
{
    return C2DA__SetBlankEntry__2(this, a0, a1);
}

int32_t C2DA::SetBlankEntry(int32_t a0, CExoString a1)
{
    return C2DA__SetBlankEntry__3(this, a0, a1);
}

int32_t C2DA::SetCExoStringEntry(CExoString a0, CExoString a1, CExoString a2)
{
    return C2DA__SetCExoStringEntry__0(this, a0, a1, a2);
}

int32_t C2DA::SetCExoStringEntry(int32_t a0, CExoString a1, CExoString a2)
{
    return C2DA__SetCExoStringEntry__1(this, a0, a1, a2);
}

int32_t C2DA::SetCExoStringEntry(int32_t a0, int32_t a1, CExoString a2)
{
    return C2DA__SetCExoStringEntry__2(this, a0, a1, a2);
}

int32_t C2DA::SetCExoStringEntry(CExoString a0, int32_t a1, CExoString a2)
{
    return C2DA__SetCExoStringEntry__3(this, a0, a1, a2);
}

int32_t C2DA::SetFLOATEntry(CExoString a0, int32_t a1, float a2)
{
    return C2DA__SetFLOATEntry__0(this, a0, a1, a2);
}

int32_t C2DA::SetFLOATEntry(int32_t a0, CExoString a1, float a2)
{
    return C2DA__SetFLOATEntry__1(this, a0, a1, a2);
}

int32_t C2DA::SetFLOATEntry(int32_t a0, int32_t a1, float a2)
{
    return C2DA__SetFLOATEntry__2(this, a0, a1, a2);
}

int32_t C2DA::SetFLOATEntry(CExoString a0, CExoString a1, float a2)
{
    return C2DA__SetFLOATEntry__3(this, a0, a1, a2);
}

int32_t C2DA::SetINTEntry(CExoString a0, CExoString a1, int32_t a2)
{
    return C2DA__SetINTEntry__0(this, a0, a1, a2);
}

int32_t C2DA::SetINTEntry(int32_t a0, int32_t a1, int32_t a2)
{
    return C2DA__SetINTEntry__1(this, a0, a1, a2);
}

int32_t C2DA::SetINTEntry(int32_t a0, CExoString a1, int32_t a2)
{
    return C2DA__SetINTEntry__2(this, a0, a1, a2);
}

int32_t C2DA::SetINTEntry(CExoString a0, int32_t a1, int32_t a2)
{
    return C2DA__SetINTEntry__3(this, a0, a1, a2);
}

int32_t C2DA::SkipNewLines(char** a0, uint32_t* a1)
{
    return C2DA__SkipNewLines(this, a0, a1);
}

void C2DA::Unload2DArray()
{
    return C2DA__Unload2DArray(this);
}

void C2DA__C2DACtor__0(C2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(C2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__C2DACtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void C2DA__C2DACtor__1(C2DA* thisPtr, CResRef a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(C2DA*, CResRef, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__C2DACtor__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void C2DA__C2DADtor__0(C2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(C2DA*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__C2DADtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t C2DA__GetCExoStringEntry__0(C2DA* thisPtr, const CExoString& a0, const CExoString& a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, const CExoString&, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetCExoStringEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetCExoStringEntry__1(C2DA* thisPtr, int32_t a0, const CExoString& a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, const CExoString&, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetCExoStringEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetCExoStringEntry__2(C2DA* thisPtr, int32_t a0, int32_t a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetCExoStringEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetCExoStringEntry__3(C2DA* thisPtr, const CExoString& a0, int32_t a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, int32_t, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetCExoStringEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetColumnIndex(C2DA* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetColumnIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t C2DA__GetFLOATEntry__0(C2DA* thisPtr, const CExoString& a0, int32_t a1, float* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, int32_t, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetFLOATEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetFLOATEntry__1(C2DA* thisPtr, int32_t a0, const CExoString& a1, float* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, const CExoString&, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetFLOATEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetFLOATEntry__2(C2DA* thisPtr, int32_t a0, int32_t a1, float* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetFLOATEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetFLOATEntry__3(C2DA* thisPtr, const CExoString& a0, const CExoString& a1, float* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, const CExoString&, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetFLOATEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetINTEntry__0(C2DA* thisPtr, const CExoString& a0, const CExoString& a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, const CExoString&, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetINTEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetINTEntry__1(C2DA* thisPtr, int32_t a0, int32_t a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetINTEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetINTEntry__2(C2DA* thisPtr, int32_t a0, const CExoString& a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, const CExoString&, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetINTEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__GetINTEntry__3(C2DA* thisPtr, const CExoString& a0, int32_t a1, int32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&, int32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetINTEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t C2DA__GetNextLineLength(C2DA* thisPtr, char* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(C2DA*, char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetNextLineLength);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t C2DA__GetNextToken(C2DA* thisPtr, char** a0, uint32_t* a1, char* a2, uint32_t a3, uint32_t* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, char**, uint32_t*, char*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetNextToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t C2DA__GetRowIndex(C2DA* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__GetRowIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t C2DA__Load2DArray(C2DA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__Load2DArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t C2DA__SetBlankEntry__0(C2DA* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetBlankEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t C2DA__SetBlankEntry__1(C2DA* thisPtr, CExoString a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetBlankEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t C2DA__SetBlankEntry__2(C2DA* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetBlankEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t C2DA__SetBlankEntry__3(C2DA* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetBlankEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t C2DA__SetCExoStringEntry__0(C2DA* thisPtr, CExoString a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetCExoStringEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetCExoStringEntry__1(C2DA* thisPtr, int32_t a0, CExoString a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetCExoStringEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetCExoStringEntry__2(C2DA* thisPtr, int32_t a0, int32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetCExoStringEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetCExoStringEntry__3(C2DA* thisPtr, CExoString a0, int32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetCExoStringEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetFLOATEntry__0(C2DA* thisPtr, CExoString a0, int32_t a1, float a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetFLOATEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetFLOATEntry__1(C2DA* thisPtr, int32_t a0, CExoString a1, float a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, CExoString, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetFLOATEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetFLOATEntry__2(C2DA* thisPtr, int32_t a0, int32_t a1, float a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetFLOATEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetFLOATEntry__3(C2DA* thisPtr, CExoString a0, CExoString a1, float a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, CExoString, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetFLOATEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetINTEntry__0(C2DA* thisPtr, CExoString a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetINTEntry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetINTEntry__1(C2DA* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetINTEntry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetINTEntry__2(C2DA* thisPtr, int32_t a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, int32_t, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetINTEntry__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SetINTEntry__3(C2DA* thisPtr, CExoString a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, CExoString, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SetINTEntry__3);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t C2DA__SkipNewLines(C2DA* thisPtr, char** a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(C2DA*, char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__SkipNewLines);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void C2DA__Unload2DArray(C2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(C2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::C2DA__Unload2DArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
