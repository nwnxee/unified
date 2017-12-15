#include "CStoreCustomer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CStoreCustomer::CStoreCustomer(const CStoreCustomer&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CStoreCustomer& CStoreCustomer::operator=(const CStoreCustomer&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CStoreCustomer::CStoreCustomer()
{
    CStoreCustomer__CStoreCustomerCtor__0(this);
}

void CStoreCustomer__CStoreCustomerCtor__0(CStoreCustomer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CStoreCustomer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CStoreCustomer__CStoreCustomerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
