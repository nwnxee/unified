#pragma once

#include "BT/Interface/ILeaf.hpp"
#include <chrono>

namespace BT {

class LeafSleep : public ILeaf
{
public:
    LeafSleep(std::chrono::milliseconds interval) : m_interval(interval) { }
    virtual ~LeafSleep() override {}

protected:
    std::chrono::milliseconds m_interval;
    std::chrono::steady_clock::time_point m_start;

    virtual void Init() override { Reset(); }
    virtual void Reset() override { m_start = std::chrono::steady_clock::now(); }

    virtual TaskStatus Run() override
    {
        using namespace std::chrono;
        const bool exceededInterval = duration_cast<milliseconds>(steady_clock::now() - m_start) > m_interval;
        return exceededInterval ? TaskStatus::SUCCESS: TaskStatus::RUNNING;
    }
};

}
