#pragma once

#include "BT/Nodes/CompositeSequence.hpp"
#include <algorithm>
#include <random>

namespace BT {

class CompositeRandomSequence : public CompositeSequence
{
public:
    template <typename ... Args>
    CompositeRandomSequence(Args ... args) : CompositeSequence(args ...) { }

    virtual ~CompositeRandomSequence() override {}

protected:
    virtual void Init() override { Reset(); }

    virtual void Reset() override
    {
        static auto rng = std::default_random_engine(std::random_device{}());
        std::shuffle(std::begin(m_children), std::end(m_children), rng);
    }
};

}
