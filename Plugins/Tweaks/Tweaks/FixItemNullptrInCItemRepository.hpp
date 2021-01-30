#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class FixItemNullptrInCItemRepository
{
public:
    FixItemNullptrInCItemRepository(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CItemRepository__CalculateContentsWeight_hook(CItemRepository *pThis);
};

}
