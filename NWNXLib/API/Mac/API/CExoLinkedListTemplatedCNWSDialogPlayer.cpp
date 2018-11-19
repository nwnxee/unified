#include "CExoLinkedListTemplatedCNWSDialogPlayer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSDialogPlayer::~CExoLinkedListTemplatedCNWSDialogPlayer()
{
    CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerDtor(this);
}

void CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerDtor(CExoLinkedListTemplatedCNWSDialogPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCNWSDialogPlayer*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
