#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CNWSSpellScriptData
{
    int32_t m_nSpellId;
    uint16_t m_nFeatId;
    uint32_t m_oidCaster;
    uint32_t m_oidTarget;
    uint32_t m_oidItem;
    Vector m_vTargetPosition;
    CExoString m_sScript;
    uint32_t m_oidArea;
    int32_t m_nItemCastLevel;

    int32_t LoadData(CResGFF*, CResStruct*);
    int32_t SaveData(CResGFF*, CResStruct*);
};

int32_t CNWSSpellScriptData__LoadData(CNWSSpellScriptData* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSSpellScriptData__SaveData(CNWSSpellScriptData* thisPtr, CResGFF*, CResStruct*);

}

}
