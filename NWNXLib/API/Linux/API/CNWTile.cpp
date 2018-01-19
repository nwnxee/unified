#include "CNWTile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWTile::CNWTile()
{
    CNWTile__CNWTileCtor(this);
}

CNWTile::~CNWTile()
{
    CNWTile__CNWTileDtor__0(this);
}

void CNWTile::GetAnimLoop(unsigned char* a0, unsigned char* a1, unsigned char* a2)
{
    return CNWTile__GetAnimLoop(this, a0, a1, a2);
}

void CNWTile::GetLocation(int32_t* a0, int32_t* a1)
{
    return CNWTile__GetLocation(this, a0, a1);
}

void CNWTile::GetMainLightColor(unsigned char* a0, unsigned char* a1)
{
    return CNWTile__GetMainLightColor(this, a0, a1);
}

void CNWTile::GetSourceLightColor(unsigned char* a0, unsigned char* a1)
{
    return CNWTile__GetSourceLightColor(this, a0, a1);
}

void CNWTile::RotateCanonicalToReal(float a0, float a1, float* a2, float* a3)
{
    return CNWTile__RotateCanonicalToReal(this, a0, a1, a2, a3);
}

void CNWTile::RotateCanonicalToRealTile(float a0, float a1, float* a2, float* a3)
{
    return CNWTile__RotateCanonicalToRealTile(this, a0, a1, a2, a3);
}

void CNWTile::RotateRealToCanonical(float a0, float a1, float* a2, float* a3)
{
    return CNWTile__RotateRealToCanonical(this, a0, a1, a2, a3);
}

void CNWTile::RotateRealToCanonicalTile(float a0, float a1, float* a2, float* a3)
{
    return CNWTile__RotateRealToCanonicalTile(this, a0, a1, a2, a3);
}

void CNWTile::SetAnimLoop(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWTile__SetAnimLoop(this, a0, a1, a2);
}

void CNWTile::SetID(int32_t a0)
{
    return CNWTile__SetID(this, a0);
}

void CNWTile::SetMainLightColor(unsigned char a0, unsigned char a1)
{
    return CNWTile__SetMainLightColor(this, a0, a1);
}

void CNWTile::SetOrientation(int32_t a0)
{
    return CNWTile__SetOrientation(this, a0);
}

void CNWTile::SetPosition(int32_t a0, int32_t a1, int32_t a2, float a3)
{
    return CNWTile__SetPosition(this, a0, a1, a2, a3);
}

void CNWTile::SetReplaceTexture(unsigned char a0)
{
    return CNWTile__SetReplaceTexture(this, a0);
}

void CNWTile::SetSourceLightColor(unsigned char a0, unsigned char a1)
{
    return CNWTile__SetSourceLightColor(this, a0, a1);
}

void CNWTile__CNWTileCtor(CNWTile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__CNWTileCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWTile__CNWTileDtor__0(CNWTile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__CNWTileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWTile__GetAnimLoop(CNWTile* thisPtr, unsigned char* a0, unsigned char* a1, unsigned char* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char*, unsigned char*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__GetAnimLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWTile__GetLocation(CNWTile* thisPtr, int32_t* a0, int32_t* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__GetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTile__GetMainLightColor(CNWTile* thisPtr, unsigned char* a0, unsigned char* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__GetMainLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTile__GetSourceLightColor(CNWTile* thisPtr, unsigned char* a0, unsigned char* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__GetSourceLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTile__RotateCanonicalToReal(CNWTile* thisPtr, float a0, float a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__RotateCanonicalToReal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTile__RotateCanonicalToRealTile(CNWTile* thisPtr, float a0, float a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__RotateCanonicalToRealTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTile__RotateRealToCanonical(CNWTile* thisPtr, float a0, float a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__RotateRealToCanonical);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTile__RotateRealToCanonicalTile(CNWTile* thisPtr, float a0, float a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__RotateRealToCanonicalTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTile__SetAnimLoop(CNWTile* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetAnimLoop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWTile__SetID(CNWTile* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTile__SetMainLightColor(CNWTile* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetMainLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTile__SetOrientation(CNWTile* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetOrientation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTile__SetPosition(CNWTile* thisPtr, int32_t a0, int32_t a1, int32_t a2, float a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, int32_t, int32_t, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWTile__SetReplaceTexture(CNWTile* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetReplaceTexture);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTile__SetSourceLightColor(CNWTile* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTile*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTile__SetSourceLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
