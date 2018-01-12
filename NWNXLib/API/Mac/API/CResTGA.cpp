#include "CResTGA.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "ExoTGAHeader_st.hpp"

namespace NWNXLib {

namespace API {

CResTGA::CResTGA()
{
    CResTGA__CResTGACtor__0(this);
}

CResTGA::~CResTGA()
{
    CResTGA__CResTGADtor__0(this);
}

int32_t CResTGA::CopyTGAData(unsigned char* a0)
{
    return CResTGA__CopyTGAData(this, a0);
}

int32_t CResTGA::GetTGAAttrib(uint32_t* a0, uint32_t* a1, unsigned char* a2)
{
    return CResTGA__GetTGAAttrib(this, a0, a1, a2);
}

unsigned char* CResTGA::GetTGAColorMapPtr()
{
    return CResTGA__GetTGAColorMapPtr(this);
}

unsigned char* CResTGA::GetTGADataPtr()
{
    return CResTGA__GetTGADataPtr(this);
}

ExoTGAHeader_st* CResTGA::GetTGAHeaderPtr()
{
    return CResTGA__GetTGAHeaderPtr(this);
}

uint32_t CResTGA::GetTGASize()
{
    return CResTGA__GetTGASize(this);
}

int32_t CResTGA::IsColorMapped()
{
    return CResTGA__IsColorMapped(this);
}

int32_t CResTGA::IsCompressed()
{
    return CResTGA__IsCompressed(this);
}

int32_t CResTGA::IsLoaded()
{
    return CResTGA__IsLoaded(this);
}

int32_t CResTGA::OnResourceFreed()
{
    return CResTGA__OnResourceFreed(this);
}

int32_t CResTGA::OnResourceServiced()
{
    return CResTGA__OnResourceServiced(this);
}

int32_t CResTGA::ReadColorMappedRLETGA()
{
    return CResTGA__ReadColorMappedRLETGA(this);
}

int32_t CResTGA::ReadUnmappedRLETGA()
{
    return CResTGA__ReadUnmappedRLETGA(this);
}

int32_t CResTGA::Write(CExoString& a0)
{
    return CResTGA__Write(this, a0);
}

void CResTGA__CResTGACtor__0(CResTGA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__CResTGACtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResTGA__CResTGADtor__0(CResTGA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResTGA*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__CResTGADtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CResTGA__CopyTGAData(CResTGA* thisPtr, unsigned char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__CopyTGAData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResTGA__GetTGAAttrib(CResTGA* thisPtr, uint32_t* a0, uint32_t* a1, unsigned char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*, uint32_t*, uint32_t*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__GetTGAAttrib);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char* CResTGA__GetTGAColorMapPtr(CResTGA* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__GetTGAColorMapPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char* CResTGA__GetTGADataPtr(CResTGA* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__GetTGADataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

ExoTGAHeader_st* CResTGA__GetTGAHeaderPtr(CResTGA* thisPtr)
{
    using FuncPtrType = ExoTGAHeader_st*(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__GetTGAHeaderPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CResTGA__GetTGASize(CResTGA* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__GetTGASize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__IsColorMapped(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__IsColorMapped);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__IsCompressed(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__IsCompressed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__IsLoaded(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__OnResourceFreed(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__OnResourceServiced(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__ReadColorMappedRLETGA(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__ReadColorMappedRLETGA);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__ReadUnmappedRLETGA(CResTGA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__ReadUnmappedRLETGA);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResTGA__Write(CResTGA* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResTGA*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResTGA__Write);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
