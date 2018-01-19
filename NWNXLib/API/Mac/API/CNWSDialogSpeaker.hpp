#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWSDialogSpeaker
{
    CExoString m_sSpeaker;
    uint32_t m_id;
};

}

}
