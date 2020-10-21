#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixItemNullptrInCItemRepository
{
public:
    FixItemNullptrInCItemRepository(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CItemRepository__CalculateContentsWeight_hook(CItemRepository *pThis);
};

}
