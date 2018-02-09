#pragma once

#include <cstdint>

#include "unknown_EResult.hpp"

namespace NWNXLib {

namespace API {

struct SubmitItemUpdateResult_t
{
    EResult m_eResult;
    int32_t m_bUserNeedsToAcceptWorkshopLegalAgreement;
    uint64_t m_nPublishedFileId;
};

}

}
