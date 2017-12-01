#pragma once

#include <cstdint>

#include "unknown_TableCompareFn.hpp"
#include "unknown_TableElementFreeFn.hpp"
#include "unknown_TableHashFn.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DArrayImplementation;

struct HashImplementation
{
    DArrayImplementation** buckets;
    int32_t nbuckets;
    TableElementFreeFn freefn;
    TableHashFn hashfn;
    TableCompareFn compfn;
};

}

}
