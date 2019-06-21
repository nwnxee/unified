#include "CExoArrayListTemplatedCNWSExpressionPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSExpression.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCNWSExpressionPtr::~CExoArrayListTemplatedCNWSExpressionPtr()
{
    CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrDtor(this);
}

void CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrDtor(CExoArrayListTemplatedCNWSExpressionPtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSExpressionPtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
