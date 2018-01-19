#include "CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPlayerJournalQuestUpdates.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate(this, a0);
}

void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
