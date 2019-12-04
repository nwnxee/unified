#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWMessage)
#endif



typedef int BOOL;


struct CNWMessage
{
    uint8_t * m_pnWriteBuffer;
    uint32_t m_nWriteBufferSize;
    uint32_t m_nWriteBufferPtr;
    uint8_t * m_pnWriteFragmentsBuffer;
    uint32_t m_nWriteFragmentsBufferSize;
    uint32_t m_nWriteFragmentsBufferPtr;
    uint32_t m_nWriteFragmentsOffset;
    uint8_t m_nCurWriteBit;
    BOOL m_bInWriteMessage;
    uint8_t * m_pnReadBuffer;
    uint32_t m_nReadBufferSize;
    uint32_t m_nReadBufferPtr;
    uint8_t * m_pnReadFragmentsBuffer;
    uint32_t m_nReadFragmentsBufferSize;
    uint32_t m_nReadFragmentsBufferPtr;
    uint32_t m_nReadFragmentsOffset;
    uint8_t m_nCurReadBit;
    uint8_t m_nLastByteBits;
    BOOL m_bHighPriority;
    uint32_t m_dwPlayerID;

    CNWMessage();
    virtual ~CNWMessage();
    BOOL SetReadMessage(uint8_t * pMessage, uint32_t dwSize, uint32_t dwPlayerID = 0xffffffff, BOOL bHighPriority = true);
    void ClearReadMessage();
    BOOL ReadBOOL();
    uint8_t ReadBYTE(int32_t nCount = 8);
    char ReadCHAR(int32_t nCount = 8);
    uint16_t ReadWORD(int32_t nCount = 16);
    int16_t ReadSHORT(int32_t nCount = 16);
    uint32_t ReadDWORD(int32_t nCount = 32);
    int32_t ReadINT(int32_t nCount = 32);
    uint64_t ReadDWORD64(int32_t nCount = 64);
    int64_t ReadINT64(int32_t nCount = 64);
    float ReadFLOAT(float fMultiplier = 1.0, int32_t nCount = 32);
    float ReadFLOAT(float fMin, float fMax, int32_t nCount);
    double ReadDOUBLE(double fMultiplier = 1.0, int32_t nCount = 64);
    double ReadDOUBLE(double lfMin, double lfMax, int32_t nCount);
    CResRef ReadCResRef(int32_t nCount = 16);
    CExoString ReadCExoString(int32_t nCount = 32);
    void * ReadVOIDPtr(int32_t nSize);
    BOOL MessageReadOverflow(BOOL bWarn = true);
    BOOL MessageReadUnderflow(BOOL bWarn = true);
    BOOL MessageMoreDataToRead();
    void CreateWriteMessage(uint32_t nSize = 128, uint32_t dwPlayerID = 0xffffffff, BOOL bHighPriority = true);
    void WriteBOOL(BOOL nBool);
    void WriteBYTE(uint8_t nByte, int32_t nCount = 8);
    void WriteCHAR(char nChar, int32_t nCount = 8);
    void WriteWORD(uint16_t nWord, int32_t nCount = 16);
    void WriteSHORT(int16_t nShort, int32_t nCount = 16);
    void WriteDWORD(uint32_t nDword, int32_t nCount = 32);
    void WriteINT(int32_t nInteger, int32_t nCount = 32);
    void WriteDWORD64(uint64_t nDword64, int32_t nCount = 64);
    void WriteINT64(int64_t nInt64, int32_t nCount = 64);
    void WriteFLOAT(float fFloat, float fMultiplier = 1.0, int32_t nCount = 32);
    void WriteFLOAT(float fFloat, float fMin, float fMax, int32_t nCount);
    void WriteDOUBLE(double fDouble, double fMultiplier = 1.0, int32_t nCount = 64);
    void WriteDOUBLE(double lfDouble, double lfMin, double lfMax, int32_t nCount);
    void WriteCResRef(CResRef cResRef, int32_t nCount = 16);
    void WriteCExoString(CExoString sString, int32_t nCount = 32);
    void WriteVOIDPtr(void * pVoidPtr, int32_t nSize);
    uint32_t PeekAtWriteMessageSize();
    BOOL GetWriteMessage(uint8_t * * pMessage, uint32_t * dwSize);
    void ExtendWriteBuffer(uint32_t nSize);
    void ExtendWriteFragmentsBuffer(uint32_t nSize);
    int64_t ReadBits(int32_t nCount);
    uint8_t ReadBit(uint8_t nBit);
    void WriteBits(uint64_t nInVal, int32_t nCount);
    void WriteBit(uint8_t nBit);
    uint64_t ReadUnsigned(int32_t nCount);
    int64_t ReadSigned(int32_t nCount);
    void WriteUnsigned(uint64_t dw64InVal, int32_t nCount);
    void WriteSigned(int64_t n64InVal, int32_t nCount);


#ifdef NWN_CLASS_EXTENSION_CNWMessage
    NWN_CLASS_EXTENSION_CNWMessage
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWMessage)
#endif

