#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class FixItemNullptrInCItemRepository
{
public:
    FixItemNullptrInCItemRepository();

private:
    static int32_t CItemRepository__CalculateContentsWeight_hook(CItemRepository *pThis);
};

}
