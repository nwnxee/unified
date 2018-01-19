#include "CExoArrayListTemplatedCNWSExpressionListPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSExpressionList.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSExpressionListPtr::Add(CNWSExpressionList* a0)
{
    return CExoArrayListTemplatedCNWSExpressionListPtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWSExpressionListPtr__Add(CExoArrayListTemplatedCNWSExpressionListPtr* thisPtr, CNWSExpressionList* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSExpressionListPtr*, CNWSExpressionList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSExpressionListPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
