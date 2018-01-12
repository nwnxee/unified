#pragma once

#include <cstdint>

#include "CNWAmbientSound.hpp"
#include "unknown_CExoArrayListTemplatedunsignedlong.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSMessage;
struct CResGFF;
struct CResStruct;

struct CNWSAmbientSound
    : CNWAmbientSound
{
    uint32_t m_nArea;

    // The below are auto generated stubs.
    CNWSAmbientSound() = default;
    CNWSAmbientSound(const CNWSAmbientSound&) = default;
    CNWSAmbientSound& operator=(const CNWSAmbientSound&) = default;

    CNWSAmbientSound(uint32_t);
    ~CNWSAmbientSound();
    int32_t GetPlayersInArea(CExoArrayListTemplatedunsignedlong*);
    int32_t Load(CResGFF*, CResStruct*);
    void PackIntoMessage(CNWSMessage*);
    void PlayAmbientSound(int32_t);
    void PlayBattleMusic(int32_t);
    void PlayMusic(int32_t);
    void Save(CResGFF*, CResStruct*);
    void SetAmbientDayTrack(int32_t);
    void SetAmbientDayVolume(int32_t);
    void SetAmbientNightTrack(int32_t);
    void SetAmbientNightVolume(int32_t);
    void SetBattleMusicTrack(int32_t);
    void SetMusicDayTrack(int32_t);
    void SetMusicDelay(int32_t);
    void SetMusicNightTrack(int32_t);
};

void CNWSAmbientSound__CNWSAmbientSoundCtor__0(CNWSAmbientSound* thisPtr, uint32_t);
void CNWSAmbientSound__CNWSAmbientSoundDtor__0(CNWSAmbientSound* thisPtr);
int32_t CNWSAmbientSound__GetPlayersInArea(CNWSAmbientSound* thisPtr, CExoArrayListTemplatedunsignedlong*);
int32_t CNWSAmbientSound__Load(CNWSAmbientSound* thisPtr, CResGFF*, CResStruct*);
void CNWSAmbientSound__PackIntoMessage(CNWSAmbientSound* thisPtr, CNWSMessage*);
void CNWSAmbientSound__PlayAmbientSound(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__PlayBattleMusic(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__PlayMusic(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__Save(CNWSAmbientSound* thisPtr, CResGFF*, CResStruct*);
void CNWSAmbientSound__SetAmbientDayTrack(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetAmbientDayVolume(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetAmbientNightTrack(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetAmbientNightVolume(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetBattleMusicTrack(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetMusicDayTrack(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetMusicDelay(CNWSAmbientSound* thisPtr, int32_t);
void CNWSAmbientSound__SetMusicNightTrack(CNWSAmbientSound* thisPtr, int32_t);

}

}
