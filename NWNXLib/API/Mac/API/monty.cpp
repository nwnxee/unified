#include "monty.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

monty::monty()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

monty::monty(const monty&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

monty& monty::operator=(const monty&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

monty::~monty()
{
    monty__montyDtor(this);
}

void monty__montyDtor(monty* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(monty*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::monty__montyDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
