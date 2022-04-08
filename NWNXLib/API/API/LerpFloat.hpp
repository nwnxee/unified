#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(LerpFloat)
#endif

struct CResGFF;
struct CResStruct;



template<typename T> struct totally_ordered
{
    friend bool operator<=(const T& a, const T& b) { return a < b || a == b; }
    friend bool operator>(const T& a, const T& b) { return !(a <= b); }
    friend bool operator!=(const T& a, const T& b) { return !(a == b); }
    friend bool operator>=(const T& a, const T& b) { return !(a < b); }
};

enum class LerpTimerType {
    RealTime = 0,
    WorldTime = 1
};


struct LerpFloat
{
    LerpTimerType m_timer_type;
    float m_value_to;
    float m_value_from;
    int m_lerp_type;
    float m_lerp_duration;
    float m_lerp_existing_progress;

    struct TimeType
    {
        struct World : public totally_ordered<World>
        {
            uint32_t m_day;
            uint32_t m_time;

            World() : m_day(0), m_time(0) {}

            bool operator<(const World& rhs) const {
                if (m_day < rhs.m_day) return true;
                else if (m_day > rhs.m_day) return false;
                else return m_time < rhs.m_time;
            }
            bool operator==(const World& rhs) const {
                return m_day == rhs.m_day && m_time == rhs.m_time;
            }
        };

        uint64_t m_real;
        World m_world;
    };

    TimeType m_lerp_start;
    TimeType m_lerp_end;

    LerpFloat(float initial = 0.0) :
            m_timer_type(LerpTimerType::RealTime),
            m_value_to(initial),
            m_value_from(initial),
            m_lerp_type(0),
            m_lerp_duration(0.0),
            m_lerp_existing_progress(0.0)
    {}

    LerpFloat(LerpTimerType type, float to, float from, int lerpType, float lerpDuration, float existingProgress = 0.0) :
            m_timer_type(type),
            m_value_to(to),
            m_value_from(from),
            m_lerp_type(lerpType),
            m_lerp_duration(lerpDuration),
            m_lerp_existing_progress(existingProgress)
    {
        Refresh();
    }

    LerpFloat(const LerpFloat& other)
    {
        AdoptLerp(other);
        *this = other;
    }

    LerpFloat& operator=(const float& to)
    {
        AssignStatic(to);
        return *this;
    }

    LerpFloat& operator=(const LerpFloat& other)
    {
        AdoptLerp(other);
        return *this;
    }

    bool operator==(const LerpFloat& rhs) const {
        return m_value_to == rhs.m_value_to;
    }

    LerpTimerType TimerType() const { return m_timer_type; }
    int LerpType() const { return m_lerp_type; }
    float LerpDuration() const { return m_lerp_duration; }
    float Value() const { return m_value_to; }
    float ValueFrom() const { return m_value_from; }
    float Progress() const { return 1.0; }
    float Lerped() const { return m_value_to; }

    void WriteGFF(CResGFF* pRes, CResStruct* pStruct, char* szLabel);

    void AssignStatic(float to)
    {
        m_value_to = to;
        m_value_from = to;
        m_lerp_type = 0;
        m_lerp_duration = 0;
        m_lerp_existing_progress = 0.0;
    }

    void AdoptLerp(const LerpFloat& other)
    {
        m_timer_type = other.m_timer_type;
        m_value_from = other.m_value_from;
        m_value_to = other.m_value_to;
        m_lerp_type = other.m_lerp_type;
        m_lerp_duration = other.m_lerp_duration;
        m_lerp_existing_progress = other.m_lerp_existing_progress;
        m_lerp_start = other.m_lerp_start;
        m_lerp_end = other.m_lerp_end;
        Refresh();
    }

    void Refresh();

#ifdef NWN_CLASS_EXTENSION_LerpFloat
    NWN_CLASS_EXTENSION_LerpFloat
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(LerpFloat)
#endif

