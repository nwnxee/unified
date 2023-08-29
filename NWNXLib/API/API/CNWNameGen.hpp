#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CResHelper.hpp"
#include "CResLTR.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWNameGen)
#endif



typedef int BOOL;


class CNWNameGen : public CResHelper<CResLTR, 2036>
{
public:
    BOOL m_bLoaded;
    uint16_t m_nTableRace;
    uint8_t m_nTableNameType;

    CNWNameGen();
    ~CNWNameGen();
    BOOL LoadNameTable(CExoString sTable);
    void UnloadNameTable();
    CExoString GetRandomName();
    CExoString GetRandomName(uint16_t nRace, uint8_t nNameType);


#ifdef NWN_CLASS_EXTENSION_CNWNameGen
    NWN_CLASS_EXTENSION_CNWNameGen
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWNameGen)
#endif

