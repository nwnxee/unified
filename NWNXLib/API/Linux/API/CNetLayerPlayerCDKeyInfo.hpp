#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNetLayerPlayerCDKeyInfo
{
    CExoString sPublic;
    CExoString sResponse;
    int32_t bValidated;
    uint32_t nExpansionPack;

    // The below are auto generated stubs.
    CNetLayerPlayerCDKeyInfo();
    CNetLayerPlayerCDKeyInfo(const CNetLayerPlayerCDKeyInfo&);
    CNetLayerPlayerCDKeyInfo& operator=(const CNetLayerPlayerCDKeyInfo&);

    ~CNetLayerPlayerCDKeyInfo();
};

void CNetLayerPlayerCDKeyInfo__CNetLayerPlayerCDKeyInfoDtor(CNetLayerPlayerCDKeyInfo* thisPtr);

}

}
