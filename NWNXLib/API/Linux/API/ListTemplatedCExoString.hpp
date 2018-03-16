#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct ListTemplatedCExoString
{
    CExoString* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    ListTemplatedCExoString() = default;
    ListTemplatedCExoString(const ListTemplatedCExoString&) = default;
    ListTemplatedCExoString& operator=(const ListTemplatedCExoString&) = default;

    ~ListTemplatedCExoString();
    void allocate(int32_t);
};

void ListTemplatedCExoString__ListTemplatedCExoStringDtor(ListTemplatedCExoString* thisPtr);
void ListTemplatedCExoString__allocate(ListTemplatedCExoString* thisPtr, int32_t);

}

}
