#pragma once

#include "BT/Nodes/CompositeSelector.hpp"
#include <algorithm>
#include <random>

namespace BT {

class CompositeRandomSelector : public CompositeSelector
{
public:
    template <typename ... Args>
    CompositeRandomSelector(Args ... args) : CompositeSelector(args ...) { }

    virtual ~CompositeRandomSelector() override {}

protected:
    virtual void Init() override { Reset(); }

    virtual void Reset() override
    {
        static auto rng = std::default_random_engine(std::random_device{}());
        std::shuffle(std::begin(m_children), std::end(m_children), rng);
    }
};

}
