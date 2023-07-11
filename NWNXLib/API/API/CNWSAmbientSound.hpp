#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CNWAmbientSound.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSAmbientSound)
#endif

class CNWSMessage;
class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSAmbientSound : CNWAmbientSound
{
    OBJECT_ID m_nArea;

    CNWSAmbientSound(OBJECT_ID nArea);
    virtual ~CNWSAmbientSound();
    void PlayMusic(BOOL bPlay);
    void SetMusicDelay(int32_t nDelay);
    void SetMusicDayTrack(int32_t nTrack);
    void SetMusicNightTrack(int32_t nTrack);
    void PlayBattleMusic(BOOL bPlay);
    void SetBattleMusicTrack(int32_t nTrack);
    void PlayAmbientSound(BOOL bPlay);
    void SetAmbientDayTrack(int32_t nTrack);
    void SetAmbientNightTrack(int32_t nTrack);
    void SetAmbientDayVolume(int32_t nVolume);
    void SetAmbientNightVolume(int32_t nVolume);
    BOOL Load(CResGFF * pRes, CResStruct * pStruct);
    void Save(CResGFF * pRes, CResStruct * pStruct);
    void PackIntoMessage(CNWSMessage * pMessage);
    int32_t GetPlayersInArea(CExoArrayList<OBJECT_ID> * pList);


#ifdef NWN_CLASS_EXTENSION_CNWSAmbientSound
    NWN_CLASS_EXTENSION_CNWSAmbientSound
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSAmbientSound)
#endif

