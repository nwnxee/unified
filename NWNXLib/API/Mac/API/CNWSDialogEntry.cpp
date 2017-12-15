#include "CNWSDialogEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSDialogLinkReply.hpp"

namespace NWNXLib {

namespace API {

CNWSDialogEntry::CNWSDialogEntry(const CNWSDialogEntry&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWSDialogEntry& CNWSDialogEntry::operator=(const CNWSDialogEntry&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWSDialogEntry::CNWSDialogEntry()
{
    CNWSDialogEntry__CNWSDialogEntryCtor(this);
}

void CNWSDialogEntry__CNWSDialogEntryCtor(CNWSDialogEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialogEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialogEntry__CNWSDialogEntryCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
