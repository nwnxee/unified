#pragma once

#include "nwnx.hpp"

namespace Tweaks
{

namespace CasterType
{
enum TYPE
{
    None = 0,
    Arcane = 1,
    Divine = 2,
};
}

class AddPrestigeclassCasterLevels
{
public:
    AddPrestigeclassCasterLevels();

private:
    static uint8_t s_classCasterType[NWNXLib::API::Constants::ClassType::MAX + 1];
    static uint8_t s_divModClasses[NWNXLib::API::Constants::ClassType::MAX + 1];
    static uint8_t s_arcModClasses[NWNXLib::API::Constants::ClassType::MAX + 1];
    static bool s_bAdjustCasterLevel;

    static void CNWRules__LoadClassInfo(CNWRules* thisPtr);
    static uint8_t CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel);
};

}
