#pragma once

#include <cstdint>

#include "unknown_EResult.hpp"

namespace NWNXLib {

namespace API {

struct CreateItemResult_t
{
    EResult m_eResult;
    uint64_t m_nPublishedFileId;
    int32_t m_bUserNeedsToAcceptWorkshopLegalAgreement;
};

}

}
