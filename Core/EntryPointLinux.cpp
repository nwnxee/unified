#include "NWNXCore.hpp"
#include <memory>

class EntryPoint
{
public:
    EntryPoint();

private:
    std::unique_ptr<Core::NWNXCore> m_nwnxCore;
};

// Created when the .so is inserted via LD_PRELOAD.
static EntryPoint g_entryPoint;

EntryPoint::EntryPoint()
    : m_nwnxCore(std::make_unique<Core::NWNXCore>())
{
    (void)g_entryPoint; // Surpress the unused variable warning.
}
