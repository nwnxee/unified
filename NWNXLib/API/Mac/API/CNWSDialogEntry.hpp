#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSDialogLinkReply;

struct CNWSDialogEntry
{
    CExoString m_sSpeaker;
    uint32_t m_nAnimation;
    uint8_t m_bAnimationLoop;
    CExoLocString m_sText;
    CNWSDialogLinkReply* m_pReplies;
    uint32_t m_nReplies;
    CResRef m_sScript;
    uint32_t m_nDelay;
    CResRef m_sSound;
    CExoString m_sQuestTag;
    uint32_t m_nQuestId;
};

}

}
