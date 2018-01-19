#include "CNWMessage.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWMessage::CNWMessage()
{
    CNWMessage__CNWMessageCtor(this);
}

CNWMessage::~CNWMessage()
{
    CNWMessage__CNWMessageDtor__0(this);
}

void CNWMessage::ClearReadMessage()
{
    return CNWMessage__ClearReadMessage(this);
}

void CNWMessage::CreateWriteMessage(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWMessage__CreateWriteMessage(this, a0, a1, a2);
}

void CNWMessage::ExtendWriteBuffer(uint32_t a0)
{
    return CNWMessage__ExtendWriteBuffer(this, a0);
}

void CNWMessage::ExtendWriteFragmentsBuffer(uint32_t a0)
{
    return CNWMessage__ExtendWriteFragmentsBuffer(this, a0);
}

int32_t CNWMessage::GetWriteMessage(unsigned char** a0, uint32_t* a1)
{
    return CNWMessage__GetWriteMessage(this, a0, a1);
}

int32_t CNWMessage::MessageMoreDataToRead()
{
    return CNWMessage__MessageMoreDataToRead(this);
}

int32_t CNWMessage::MessageReadOverflow(int32_t a0)
{
    return CNWMessage__MessageReadOverflow(this, a0);
}

int32_t CNWMessage::MessageReadUnderflow(int32_t a0)
{
    return CNWMessage__MessageReadUnderflow(this, a0);
}

uint32_t CNWMessage::PeekAtWriteMessageSize()
{
    return CNWMessage__PeekAtWriteMessageSize(this);
}

unsigned char CNWMessage::ReadBit(unsigned char a0)
{
    return CNWMessage__ReadBit(this, a0);
}

int64_t CNWMessage::ReadBits(int32_t a0)
{
    return CNWMessage__ReadBits(this, a0);
}

int32_t CNWMessage::ReadBOOL()
{
    return CNWMessage__ReadBOOL(this);
}

unsigned char CNWMessage::ReadBYTE(int32_t a0)
{
    return CNWMessage__ReadBYTE(this, a0);
}

CExoString CNWMessage::ReadCExoString(int32_t a0)
{
    return CNWMessage__ReadCExoString(this, a0);
}

char CNWMessage::ReadCHAR(int32_t a0)
{
    return CNWMessage__ReadCHAR(this, a0);
}

CResRef CNWMessage::ReadCResRef(int32_t a0)
{
    return CNWMessage__ReadCResRef(this, a0);
}

double CNWMessage::ReadDOUBLE(double a0, int32_t a1)
{
    return CNWMessage__ReadDOUBLE__0(this, a0, a1);
}

double CNWMessage::ReadDOUBLE(double a0, double a1, int32_t a2)
{
    return CNWMessage__ReadDOUBLE__1(this, a0, a1, a2);
}

uint32_t CNWMessage::ReadDWORD(int32_t a0)
{
    return CNWMessage__ReadDWORD(this, a0);
}

uint64_t CNWMessage::ReadDWORD64(int32_t a0)
{
    return CNWMessage__ReadDWORD64(this, a0);
}

float CNWMessage::ReadFLOAT(float a0, int32_t a1)
{
    return CNWMessage__ReadFLOAT__0(this, a0, a1);
}

float CNWMessage::ReadFLOAT(float a0, float a1, int32_t a2)
{
    return CNWMessage__ReadFLOAT__1(this, a0, a1, a2);
}

int32_t CNWMessage::ReadINT(int32_t a0)
{
    return CNWMessage__ReadINT(this, a0);
}

int64_t CNWMessage::ReadINT64(int32_t a0)
{
    return CNWMessage__ReadINT64(this, a0);
}

int16_t CNWMessage::ReadSHORT(int32_t a0)
{
    return CNWMessage__ReadSHORT(this, a0);
}

int64_t CNWMessage::ReadSigned(int32_t a0)
{
    return CNWMessage__ReadSigned(this, a0);
}

uint64_t CNWMessage::ReadUnsigned(int32_t a0)
{
    return CNWMessage__ReadUnsigned(this, a0);
}

void* CNWMessage::ReadVOIDPtr(int32_t a0)
{
    return CNWMessage__ReadVOIDPtr(this, a0);
}

uint16_t CNWMessage::ReadWORD(int32_t a0)
{
    return CNWMessage__ReadWORD(this, a0);
}

int32_t CNWMessage::SetReadMessage(unsigned char* a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNWMessage__SetReadMessage(this, a0, a1, a2, a3);
}

void CNWMessage::WriteBit(unsigned char a0)
{
    return CNWMessage__WriteBit(this, a0);
}

void CNWMessage::WriteBits(uint64_t a0, int32_t a1)
{
    return CNWMessage__WriteBits(this, a0, a1);
}

void CNWMessage::WriteBOOL(int32_t a0)
{
    return CNWMessage__WriteBOOL(this, a0);
}

void CNWMessage::WriteBYTE(unsigned char a0, int32_t a1)
{
    return CNWMessage__WriteBYTE(this, a0, a1);
}

void CNWMessage::WriteCExoString(CExoString a0, int32_t a1)
{
    return CNWMessage__WriteCExoString(this, a0, a1);
}

void CNWMessage::WriteCHAR(char a0, int32_t a1)
{
    return CNWMessage__WriteCHAR(this, a0, a1);
}

void CNWMessage::WriteCResRef(CResRef a0, int32_t a1)
{
    return CNWMessage__WriteCResRef(this, a0, a1);
}

void CNWMessage::WriteDOUBLE(double a0, double a1, int32_t a2)
{
    return CNWMessage__WriteDOUBLE__0(this, a0, a1, a2);
}

void CNWMessage::WriteDOUBLE(double a0, double a1, double a2, int32_t a3)
{
    return CNWMessage__WriteDOUBLE__1(this, a0, a1, a2, a3);
}

void CNWMessage::WriteDWORD(uint32_t a0, int32_t a1)
{
    return CNWMessage__WriteDWORD(this, a0, a1);
}

void CNWMessage::WriteDWORD64(uint64_t a0, int32_t a1)
{
    return CNWMessage__WriteDWORD64(this, a0, a1);
}

void CNWMessage::WriteFLOAT(float a0, float a1, int32_t a2)
{
    return CNWMessage__WriteFLOAT__0(this, a0, a1, a2);
}

void CNWMessage::WriteFLOAT(float a0, float a1, float a2, int32_t a3)
{
    return CNWMessage__WriteFLOAT__1(this, a0, a1, a2, a3);
}

void CNWMessage::WriteINT(int32_t a0, int32_t a1)
{
    return CNWMessage__WriteINT(this, a0, a1);
}

void CNWMessage::WriteINT64(int64_t a0, int32_t a1)
{
    return CNWMessage__WriteINT64(this, a0, a1);
}

void CNWMessage::WriteSHORT(int16_t a0, int32_t a1)
{
    return CNWMessage__WriteSHORT(this, a0, a1);
}

void CNWMessage::WriteSigned(int64_t a0, int32_t a1)
{
    return CNWMessage__WriteSigned(this, a0, a1);
}

void CNWMessage::WriteUnsigned(uint64_t a0, int32_t a1)
{
    return CNWMessage__WriteUnsigned(this, a0, a1);
}

void CNWMessage::WriteVOIDPtr(void* a0, int32_t a1)
{
    return CNWMessage__WriteVOIDPtr(this, a0, a1);
}

void CNWMessage::WriteWORD(uint16_t a0, int32_t a1)
{
    return CNWMessage__WriteWORD(this, a0, a1);
}

void CNWMessage__CNWMessageCtor(CNWMessage* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__CNWMessageCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWMessage__CNWMessageDtor__0(CNWMessage* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__CNWMessageDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWMessage__ClearReadMessage(CNWMessage* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ClearReadMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWMessage__CreateWriteMessage(CNWMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__CreateWriteMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWMessage__ExtendWriteBuffer(CNWMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ExtendWriteBuffer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWMessage__ExtendWriteFragmentsBuffer(CNWMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ExtendWriteFragmentsBuffer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWMessage__GetWriteMessage(CNWMessage* thisPtr, unsigned char** a0, uint32_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*, unsigned char**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__GetWriteMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWMessage__MessageMoreDataToRead(CNWMessage* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__MessageMoreDataToRead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWMessage__MessageReadOverflow(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__MessageReadOverflow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWMessage__MessageReadUnderflow(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__MessageReadUnderflow);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWMessage__PeekAtWriteMessageSize(CNWMessage* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__PeekAtWriteMessageSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWMessage__ReadBit(CNWMessage* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWMessage*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadBit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int64_t CNWMessage__ReadBits(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int64_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadBits);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWMessage__ReadBOOL(CNWMessage* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadBOOL);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWMessage__ReadBYTE(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadBYTE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWMessage__ReadCExoString(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadCExoString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char CNWMessage__ReadCHAR(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadCHAR);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CNWMessage__ReadCResRef(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadCResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

double CNWMessage__ReadDOUBLE__0(CNWMessage* thisPtr, double a0, int32_t a1)
{
    using FuncPtrType = double(__attribute__((cdecl)) *)(CNWMessage*, double, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadDOUBLE__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

double CNWMessage__ReadDOUBLE__1(CNWMessage* thisPtr, double a0, double a1, int32_t a2)
{
    using FuncPtrType = double(__attribute__((cdecl)) *)(CNWMessage*, double, double, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadDOUBLE__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWMessage__ReadDWORD(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadDWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint64_t CNWMessage__ReadDWORD64(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadDWORD64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWMessage__ReadFLOAT__0(CNWMessage* thisPtr, float a0, int32_t a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWMessage*, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadFLOAT__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CNWMessage__ReadFLOAT__1(CNWMessage* thisPtr, float a0, float a1, int32_t a2)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWMessage*, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadFLOAT__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWMessage__ReadINT(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadINT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int64_t CNWMessage__ReadINT64(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int64_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadINT64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int16_t CNWMessage__ReadSHORT(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadSHORT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int64_t CNWMessage__ReadSigned(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int64_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadSigned);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint64_t CNWMessage__ReadUnsigned(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadUnsigned);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CNWMessage__ReadVOIDPtr(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadVOIDPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWMessage__ReadWORD(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__ReadWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWMessage__SetReadMessage(CNWMessage* thisPtr, unsigned char* a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWMessage*, unsigned char*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__SetReadMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWMessage__WriteBit(CNWMessage* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteBit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWMessage__WriteBits(CNWMessage* thisPtr, uint64_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint64_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteBits);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteBOOL(CNWMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteBOOL);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWMessage__WriteBYTE(CNWMessage* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteBYTE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteCExoString(CNWMessage* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteCExoString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteCHAR(CNWMessage* thisPtr, char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteCHAR);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteCResRef(CNWMessage* thisPtr, CResRef a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, CResRef, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteCResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteDOUBLE__0(CNWMessage* thisPtr, double a0, double a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, double, double, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteDOUBLE__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWMessage__WriteDOUBLE__1(CNWMessage* thisPtr, double a0, double a1, double a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, double, double, double, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteDOUBLE__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWMessage__WriteDWORD(CNWMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteDWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteDWORD64(CNWMessage* thisPtr, uint64_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint64_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteDWORD64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteFLOAT__0(CNWMessage* thisPtr, float a0, float a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteFLOAT__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWMessage__WriteFLOAT__1(CNWMessage* thisPtr, float a0, float a1, float a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteFLOAT__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWMessage__WriteINT(CNWMessage* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteINT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteINT64(CNWMessage* thisPtr, int64_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int64_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteINT64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteSHORT(CNWMessage* thisPtr, int16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteSHORT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteSigned(CNWMessage* thisPtr, int64_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, int64_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteSigned);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteUnsigned(CNWMessage* thisPtr, uint64_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint64_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteUnsigned);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteVOIDPtr(CNWMessage* thisPtr, void* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteVOIDPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWMessage__WriteWORD(CNWMessage* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWMessage*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWMessage__WriteWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
