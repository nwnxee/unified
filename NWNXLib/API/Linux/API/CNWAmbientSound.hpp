#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWAmbientSound
{
    void** m_vtable;
    int32_t m_bMusicPlaying;
    int32_t m_nMusicDelay;
    int32_t m_nMusicDayTrack;
    int32_t m_nMusicNightTrack;
    int32_t m_bBattlePlaying;
    int32_t m_nBattleTrack;
    int32_t m_bSoundPlaying;
    int32_t m_nSoundDayTrack;
    int32_t m_nSoundNightTrack;
    uint8_t m_nDayVolume;
    uint8_t m_nNightVolume;
};

}

}
