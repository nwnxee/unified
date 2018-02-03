#include "CNWSDialog.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"
#include "CNWSDialogEntry.hpp"
#include "CNWSDialogLinkEntry.hpp"
#include "CNWSDialogReply.hpp"
#include "CNWSDialogSpeaker.hpp"
#include "CNWSObject.hpp"
#include "CResGFF.hpp"

namespace NWNXLib {

namespace API {

CNWSDialog::CNWSDialog()
{
    CNWSDialog__CNWSDialogCtor__0(this);
}

CNWSDialog::~CNWSDialog()
{
    CNWSDialog__CNWSDialogDtor__0(this);
}

void CNWSDialog::AddJournalEntry(const CExoString& a0, uint32_t a1, uint32_t a2)
{
    return CNWSDialog__AddJournalEntry(this, a0, a1, a2);
}

int32_t CNWSDialog::CheckScript(CNWSObject* a0, const CResRef& a1)
{
    return CNWSDialog__CheckScript(this, a0, a1);
}

void CNWSDialog::Cleanup()
{
    return CNWSDialog__Cleanup(this);
}

void CNWSDialog::ClearDialogOwnerInObject(uint32_t a0)
{
    return CNWSDialog__ClearDialogOwnerInObject(this, a0);
}

CNWSObject* CNWSDialog::GetSpeaker(CNWSObject* a0, const CExoString& a1)
{
    return CNWSDialog__GetSpeaker(this, a0, a1);
}

uint32_t CNWSDialog::GetStartEntry(CNWSObject* a0)
{
    return CNWSDialog__GetStartEntry(this, a0);
}

int32_t CNWSDialog::GetStartEntryOneLiner(CNWSObject* a0, CExoLocString& a1, CResRef& a2, CResRef& a3)
{
    return CNWSDialog__GetStartEntryOneLiner(this, a0, a1, a2, a3);
}

int32_t CNWSDialog::HandleReply(uint32_t a0, CNWSObject* a1, uint32_t a2, int32_t a3, uint32_t a4)
{
    return CNWSDialog__HandleReply(this, a0, a1, a2, a3, a4);
}

int32_t CNWSDialog::IsPlayerInDialog(uint32_t a0)
{
    return CNWSDialog__IsPlayerInDialog(this, a0);
}

int32_t CNWSDialog::LoadDialog(CResGFF* a0, int32_t a1)
{
    return CNWSDialog__LoadDialog(this, a0, a1);
}

int32_t CNWSDialog::RemovePlayer(uint32_t a0)
{
    return CNWSDialog__RemovePlayer(this, a0);
}

void CNWSDialog::RunScript(CNWSObject* a0, const CResRef& a1)
{
    return CNWSDialog__RunScript(this, a0, a1);
}

int32_t CNWSDialog::SendDialogEntry(CNWSObject* a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNWSDialog__SendDialogEntry(this, a0, a1, a2, a3);
}

int32_t CNWSDialog::SendDialogReplies(CNWSObject* a0, uint32_t a1)
{
    return CNWSDialog__SendDialogReplies(this, a0, a1);
}

float CNWSDialog::SetDialogDelay(CNWSObject* a0, CExoLocString a1, uint32_t a2, int32_t a3)
{
    return CNWSDialog__SetDialogDelay(this, a0, a1, a2, a3);
}

void CNWSDialog__CNWSDialogCtor__0(CNWSDialog* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__CNWSDialogCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSDialog__CNWSDialogDtor__0(CNWSDialog* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__CNWSDialogDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSDialog__AddJournalEntry(CNWSDialog* thisPtr, const CExoString& a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*, const CExoString&, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__AddJournalEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSDialog__CheckScript(CNWSDialog* thisPtr, CNWSObject* a0, const CResRef& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__CheckScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSDialog__Cleanup(CNWSDialog* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__Cleanup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSDialog__ClearDialogOwnerInObject(CNWSDialog* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__ClearDialogOwnerInObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSObject* CNWSDialog__GetSpeaker(CNWSDialog* thisPtr, CNWSObject* a0, const CExoString& a1)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__GetSpeaker);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSDialog__GetStartEntry(CNWSDialog* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__GetStartEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSDialog__GetStartEntryOneLiner(CNWSDialog* thisPtr, CNWSObject* a0, CExoLocString& a1, CResRef& a2, CResRef& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, CExoLocString&, CResRef&, CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__GetStartEntryOneLiner);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSDialog__HandleReply(CNWSDialog* thisPtr, uint32_t a0, CNWSObject* a1, uint32_t a2, int32_t a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, uint32_t, CNWSObject*, uint32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__HandleReply);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSDialog__IsPlayerInDialog(CNWSDialog* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__IsPlayerInDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSDialog__LoadDialog(CNWSDialog* thisPtr, CResGFF* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, CResGFF*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__LoadDialog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSDialog__RemovePlayer(CNWSDialog* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__RemovePlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSDialog__RunScript(CNWSDialog* thisPtr, CNWSObject* a0, const CResRef& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__RunScript);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSDialog__SendDialogEntry(CNWSDialog* thisPtr, CNWSObject* a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__SendDialogEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSDialog__SendDialogReplies(CNWSDialog* thisPtr, CNWSObject* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__SendDialogReplies);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CNWSDialog__SetDialogDelay(CNWSDialog* thisPtr, CNWSObject* a0, CExoLocString a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSDialog*, CNWSObject*, CExoLocString, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDialog__SetDialogDelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
