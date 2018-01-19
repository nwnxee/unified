#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWMessage
{
    void** m_vtable;
    uint8_t* m_pnWriteBuffer;
    uint32_t m_nWriteBufferSize;
    uint32_t m_nWriteBufferPtr;
    uint8_t* m_pnWriteFragmentsBuffer;
    uint32_t m_nWriteFragmentsBufferSize;
    uint32_t m_nWriteFragmentsBufferPtr;
    uint32_t m_nWriteFragmentsOffset;
    uint8_t m_nCurWriteBit;
    int32_t m_bInWriteMessage;
    uint8_t* m_pnReadBuffer;
    uint32_t m_nReadBufferSize;
    uint32_t m_nReadBufferPtr;
    uint8_t* m_pnReadFragmentsBuffer;
    uint32_t m_nReadFragmentsBufferSize;
    uint32_t m_nReadFragmentsBufferPtr;
    uint32_t m_nReadFragmentsOffset;
    uint8_t m_nCurReadBit;
    uint8_t m_nLastByteBits;
    int32_t m_bHighPriority;
    uint32_t m_dwPlayerID;

    // The below are auto generated stubs.
    CNWMessage(const CNWMessage&) = default;
    CNWMessage& operator=(const CNWMessage&) = default;

    CNWMessage();
    ~CNWMessage();
    void ClearReadMessage();
    void CreateWriteMessage(uint32_t, uint32_t, int32_t);
    void ExtendWriteBuffer(uint32_t);
    void ExtendWriteFragmentsBuffer(uint32_t);
    int32_t GetWriteMessage(unsigned char**, uint32_t*);
    int32_t MessageMoreDataToRead();
    int32_t MessageReadOverflow(int32_t);
    int32_t MessageReadUnderflow(int32_t);
    uint32_t PeekAtWriteMessageSize();
    unsigned char ReadBit(unsigned char);
    int64_t ReadBits(int32_t);
    int32_t ReadBOOL();
    unsigned char ReadBYTE(int32_t);
    CExoString ReadCExoString(int32_t);
    char ReadCHAR(int32_t);
    CResRef ReadCResRef(int32_t);
    double ReadDOUBLE(double, int32_t);
    double ReadDOUBLE(double, double, int32_t);
    uint32_t ReadDWORD(int32_t);
    uint64_t ReadDWORD64(int32_t);
    float ReadFLOAT(float, int32_t);
    float ReadFLOAT(float, float, int32_t);
    int32_t ReadINT(int32_t);
    int64_t ReadINT64(int32_t);
    int16_t ReadSHORT(int32_t);
    int64_t ReadSigned(int32_t);
    uint64_t ReadUnsigned(int32_t);
    void* ReadVOIDPtr(int32_t);
    uint16_t ReadWORD(int32_t);
    int32_t SetReadMessage(unsigned char*, uint32_t, uint32_t, int32_t);
    void WriteBit(unsigned char);
    void WriteBits(uint64_t, int32_t);
    void WriteBOOL(int32_t);
    void WriteBYTE(unsigned char, int32_t);
    void WriteCExoString(CExoString, int32_t);
    void WriteCHAR(char, int32_t);
    void WriteCResRef(CResRef, int32_t);
    void WriteDOUBLE(double, double, int32_t);
    void WriteDOUBLE(double, double, double, int32_t);
    void WriteDWORD(uint32_t, int32_t);
    void WriteDWORD64(uint64_t, int32_t);
    void WriteFLOAT(float, float, int32_t);
    void WriteFLOAT(float, float, float, int32_t);
    void WriteINT(int32_t, int32_t);
    void WriteINT64(int64_t, int32_t);
    void WriteSHORT(int16_t, int32_t);
    void WriteSigned(int64_t, int32_t);
    void WriteUnsigned(uint64_t, int32_t);
    void WriteVOIDPtr(void*, int32_t);
    void WriteWORD(uint16_t, int32_t);
};

void CNWMessage__CNWMessageCtor__0(CNWMessage* thisPtr);
void CNWMessage__CNWMessageDtor__0(CNWMessage* thisPtr);
void CNWMessage__ClearReadMessage(CNWMessage* thisPtr);
void CNWMessage__CreateWriteMessage(CNWMessage* thisPtr, uint32_t, uint32_t, int32_t);
void CNWMessage__ExtendWriteBuffer(CNWMessage* thisPtr, uint32_t);
void CNWMessage__ExtendWriteFragmentsBuffer(CNWMessage* thisPtr, uint32_t);
int32_t CNWMessage__GetWriteMessage(CNWMessage* thisPtr, unsigned char**, uint32_t*);
int32_t CNWMessage__MessageMoreDataToRead(CNWMessage* thisPtr);
int32_t CNWMessage__MessageReadOverflow(CNWMessage* thisPtr, int32_t);
int32_t CNWMessage__MessageReadUnderflow(CNWMessage* thisPtr, int32_t);
uint32_t CNWMessage__PeekAtWriteMessageSize(CNWMessage* thisPtr);
unsigned char CNWMessage__ReadBit(CNWMessage* thisPtr, unsigned char);
int64_t CNWMessage__ReadBits(CNWMessage* thisPtr, int32_t);
int32_t CNWMessage__ReadBOOL(CNWMessage* thisPtr);
unsigned char CNWMessage__ReadBYTE(CNWMessage* thisPtr, int32_t);
CExoString CNWMessage__ReadCExoString(CNWMessage* thisPtr, int32_t);
char CNWMessage__ReadCHAR(CNWMessage* thisPtr, int32_t);
CResRef CNWMessage__ReadCResRef(CNWMessage* thisPtr, int32_t);
double CNWMessage__ReadDOUBLE__0(CNWMessage* thisPtr, double, int32_t);
double CNWMessage__ReadDOUBLE__1(CNWMessage* thisPtr, double, double, int32_t);
uint32_t CNWMessage__ReadDWORD(CNWMessage* thisPtr, int32_t);
uint64_t CNWMessage__ReadDWORD64(CNWMessage* thisPtr, int32_t);
float CNWMessage__ReadFLOAT__0(CNWMessage* thisPtr, float, int32_t);
float CNWMessage__ReadFLOAT__1(CNWMessage* thisPtr, float, float, int32_t);
int32_t CNWMessage__ReadINT(CNWMessage* thisPtr, int32_t);
int64_t CNWMessage__ReadINT64(CNWMessage* thisPtr, int32_t);
int16_t CNWMessage__ReadSHORT(CNWMessage* thisPtr, int32_t);
int64_t CNWMessage__ReadSigned(CNWMessage* thisPtr, int32_t);
uint64_t CNWMessage__ReadUnsigned(CNWMessage* thisPtr, int32_t);
void* CNWMessage__ReadVOIDPtr(CNWMessage* thisPtr, int32_t);
uint16_t CNWMessage__ReadWORD(CNWMessage* thisPtr, int32_t);
int32_t CNWMessage__SetReadMessage(CNWMessage* thisPtr, unsigned char*, uint32_t, uint32_t, int32_t);
void CNWMessage__WriteBit(CNWMessage* thisPtr, unsigned char);
void CNWMessage__WriteBits(CNWMessage* thisPtr, uint64_t, int32_t);
void CNWMessage__WriteBOOL(CNWMessage* thisPtr, int32_t);
void CNWMessage__WriteBYTE(CNWMessage* thisPtr, unsigned char, int32_t);
void CNWMessage__WriteCExoString(CNWMessage* thisPtr, CExoString, int32_t);
void CNWMessage__WriteCHAR(CNWMessage* thisPtr, char, int32_t);
void CNWMessage__WriteCResRef(CNWMessage* thisPtr, CResRef, int32_t);
void CNWMessage__WriteDOUBLE__0(CNWMessage* thisPtr, double, double, int32_t);
void CNWMessage__WriteDOUBLE__1(CNWMessage* thisPtr, double, double, double, int32_t);
void CNWMessage__WriteDWORD(CNWMessage* thisPtr, uint32_t, int32_t);
void CNWMessage__WriteDWORD64(CNWMessage* thisPtr, uint64_t, int32_t);
void CNWMessage__WriteFLOAT__0(CNWMessage* thisPtr, float, float, int32_t);
void CNWMessage__WriteFLOAT__1(CNWMessage* thisPtr, float, float, float, int32_t);
void CNWMessage__WriteINT(CNWMessage* thisPtr, int32_t, int32_t);
void CNWMessage__WriteINT64(CNWMessage* thisPtr, int64_t, int32_t);
void CNWMessage__WriteSHORT(CNWMessage* thisPtr, int16_t, int32_t);
void CNWMessage__WriteSigned(CNWMessage* thisPtr, int64_t, int32_t);
void CNWMessage__WriteUnsigned(CNWMessage* thisPtr, uint64_t, int32_t);
void CNWMessage__WriteVOIDPtr(CNWMessage* thisPtr, void*, int32_t);
void CNWMessage__WriteWORD(CNWMessage* thisPtr, uint16_t, int32_t);

}

}
