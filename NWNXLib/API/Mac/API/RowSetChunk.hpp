#pragma once

#include <cstdint>

#include "RowSetEntry.hpp"

namespace NWNXLib {

namespace API {

struct RowSetChunk
{
    RowSetChunk* pNextChunk;
    RowSetEntry aEntry[63];
};

}

}
