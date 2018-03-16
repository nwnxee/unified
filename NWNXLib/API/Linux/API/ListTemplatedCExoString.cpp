#include "ListTemplatedCExoString.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

ListTemplatedCExoString::~ListTemplatedCExoString()
{
    ListTemplatedCExoString__ListTemplatedCExoStringDtor(this);
}

void ListTemplatedCExoString::allocate(int32_t a0)
{
    return ListTemplatedCExoString__allocate(this, a0);
}

void ListTemplatedCExoString__ListTemplatedCExoStringDtor(ListTemplatedCExoString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(ListTemplatedCExoString*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ListTemplatedCExoString__ListTemplatedCExoStringDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void ListTemplatedCExoString__allocate(ListTemplatedCExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(ListTemplatedCExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::ListTemplatedCExoString__allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
