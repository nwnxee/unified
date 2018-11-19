#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BtShared;
struct PgHdr;

struct MemPage
{
    uint8_t isInit;
    uint8_t bBusy;
    uint8_t intKey;
    uint8_t intKeyLeaf;
    uint32_t pgno;
    uint8_t leaf;
    uint8_t hdrOffset;
    uint8_t childPtrSize;
    uint8_t max1bytePayload;
    uint8_t nOverflow;
    uint16_t maxLocal;
    uint16_t minLocal;
    uint16_t cellOffset;
    uint16_t nFree;
    uint16_t nCell;
    uint16_t maskPage;
    uint16_t aiOvfl[4];
    uint8_t* apOvfl[4];
    BtShared* pBt;
    uint8_t* aData;
    uint8_t* aDataEnd;
    uint8_t* aCellIdx;
    uint8_t* aDataOfst;
    PgHdr* pDbPage;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
};

}

}
