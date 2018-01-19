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
    CNetLayerPlayerCDKeyInfo() = default;
    CNetLayerPlayerCDKeyInfo(const CNetLayerPlayerCDKeyInfo&) = default;
    CNetLayerPlayerCDKeyInfo& operator=(const CNetLayerPlayerCDKeyInfo&) = default;

    ~CNetLayerPlayerCDKeyInfo();
};

void CNetLayerPlayerCDKeyInfo__CNetLayerPlayerCDKeyInfoDtor(CNetLayerPlayerCDKeyInfo* thisPtr);

}

}
