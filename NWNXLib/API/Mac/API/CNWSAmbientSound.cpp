#include "CNWSAmbientSound.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CNWSMessage.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSAmbientSound::CNWSAmbientSound(uint32_t a0)
{
    CNWSAmbientSound__CNWSAmbientSoundCtor__0(this, a0);
}

CNWSAmbientSound::~CNWSAmbientSound()
{
    CNWSAmbientSound__CNWSAmbientSoundDtor__0(this);
}

int32_t CNWSAmbientSound::GetPlayersInArea(CExoArrayListTemplatedunsignedlong* a0)
{
    return CNWSAmbientSound__GetPlayersInArea(this, a0);
}

int32_t CNWSAmbientSound::Load(CResGFF* a0, CResStruct* a1)
{
    return CNWSAmbientSound__Load(this, a0, a1);
}

void CNWSAmbientSound::PackIntoMessage(CNWSMessage* a0)
{
    return CNWSAmbientSound__PackIntoMessage(this, a0);
}

void CNWSAmbientSound::PlayAmbientSound(int32_t a0)
{
    return CNWSAmbientSound__PlayAmbientSound(this, a0);
}

void CNWSAmbientSound::PlayBattleMusic(int32_t a0)
{
    return CNWSAmbientSound__PlayBattleMusic(this, a0);
}

void CNWSAmbientSound::PlayMusic(int32_t a0)
{
    return CNWSAmbientSound__PlayMusic(this, a0);
}

void CNWSAmbientSound::Save(CResGFF* a0, CResStruct* a1)
{
    return CNWSAmbientSound__Save(this, a0, a1);
}

void CNWSAmbientSound::SetAmbientDayTrack(int32_t a0)
{
    return CNWSAmbientSound__SetAmbientDayTrack(this, a0);
}

void CNWSAmbientSound::SetAmbientDayVolume(int32_t a0)
{
    return CNWSAmbientSound__SetAmbientDayVolume(this, a0);
}

void CNWSAmbientSound::SetAmbientNightTrack(int32_t a0)
{
    return CNWSAmbientSound__SetAmbientNightTrack(this, a0);
}

void CNWSAmbientSound::SetAmbientNightVolume(int32_t a0)
{
    return CNWSAmbientSound__SetAmbientNightVolume(this, a0);
}

void CNWSAmbientSound::SetBattleMusicTrack(int32_t a0)
{
    return CNWSAmbientSound__SetBattleMusicTrack(this, a0);
}

void CNWSAmbientSound::SetMusicDayTrack(int32_t a0)
{
    return CNWSAmbientSound__SetMusicDayTrack(this, a0);
}

void CNWSAmbientSound::SetMusicDelay(int32_t a0)
{
    return CNWSAmbientSound__SetMusicDelay(this, a0);
}

void CNWSAmbientSound::SetMusicNightTrack(int32_t a0)
{
    return CNWSAmbientSound__SetMusicNightTrack(this, a0);
}

void CNWSAmbientSound__CNWSAmbientSoundCtor__0(CNWSAmbientSound* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__CNWSAmbientSoundCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSAmbientSound__CNWSAmbientSoundDtor__0(CNWSAmbientSound* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__CNWSAmbientSoundDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSAmbientSound__GetPlayersInArea(CNWSAmbientSound* thisPtr, CExoArrayListTemplatedunsignedlong* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAmbientSound*, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__GetPlayersInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSAmbientSound__Load(CNWSAmbientSound* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAmbientSound*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__Load);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAmbientSound__PackIntoMessage(CNWSAmbientSound* thisPtr, CNWSMessage* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, CNWSMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__PackIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__PlayAmbientSound(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__PlayAmbientSound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__PlayBattleMusic(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__PlayBattleMusic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__PlayMusic(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__PlayMusic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__Save(CNWSAmbientSound* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__Save);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAmbientSound__SetAmbientDayTrack(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetAmbientDayTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetAmbientDayVolume(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetAmbientDayVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetAmbientNightTrack(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetAmbientNightTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetAmbientNightVolume(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetAmbientNightVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetBattleMusicTrack(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetBattleMusicTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetMusicDayTrack(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetMusicDayTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetMusicDelay(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetMusicDelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAmbientSound__SetMusicNightTrack(CNWSAmbientSound* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAmbientSound*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAmbientSound__SetMusicNightTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
