#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCLinuxFileKey.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CLinuxFileSection
{
    CExoString sSection;
    CExoLinkedListTemplatedCLinuxFileKey lKey;
};

}

}
