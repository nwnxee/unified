#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWAmbientSound)
#endif



typedef int BOOL;


class CNWAmbientSound
{
public:
    BOOL m_bMusicPlaying;
    int32_t m_nMusicDelay;
    int32_t m_nMusicDayTrack;
    int32_t m_nMusicNightTrack;
    BOOL m_bBattlePlaying;
    int32_t m_nBattleTrack;
    BOOL m_bSoundPlaying;
    int32_t m_nSoundDayTrack;
    int32_t m_nSoundNightTrack;
    uint8_t m_nDayVolume;
    uint8_t m_nNightVolume;

    virtual void PlayMusic(BOOL bPlay);
    virtual void SetMusicDelay(int32_t nDelay);
    virtual void SetMusicDayTrack(int32_t nTrack);
    virtual void SetMusicNightTrack(int32_t nTrack);
    virtual void PlayBattleMusic(BOOL bPlay);
    virtual void SetBattleMusicTrack(int32_t nTrack);
    virtual void PlayAmbientSound(BOOL bPlay);
    virtual void SetAmbientDayTrack(int32_t nTrack);
    virtual void SetAmbientNightTrack(int32_t nTrack);


#ifdef NWN_CLASS_EXTENSION_CNWAmbientSound
    NWN_CLASS_EXTENSION_CNWAmbientSound
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWAmbientSound)
#endif

