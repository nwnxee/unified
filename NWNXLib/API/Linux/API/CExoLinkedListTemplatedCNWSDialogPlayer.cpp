#include "CExoLinkedListTemplatedCNWSDialogPlayer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSDialogPlayer::CExoLinkedListTemplatedCNWSDialogPlayer()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSDialogPlayer::CExoLinkedListTemplatedCNWSDialogPlayer(const CExoLinkedListTemplatedCNWSDialogPlayer&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSDialogPlayer& CExoLinkedListTemplatedCNWSDialogPlayer::operator=(const CExoLinkedListTemplatedCNWSDialogPlayer&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

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
