#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CScriptTalent
{
    int32_t m_nType;
    int32_t m_nID;
    uint8_t m_nMultiClass;
    uint32_t m_oidItem;
    int32_t m_nItemPropertyIndex;
    uint8_t m_nCasterLevel;
    uint8_t m_nMetaType;

    // The below are auto generated stubs.
    CScriptTalent(const CScriptTalent&) = default;
    CScriptTalent& operator=(const CScriptTalent&) = default;

    CScriptTalent();
    ~CScriptTalent();
    void CopyScriptTalent(CScriptTalent*);
    int32_t Equals(CScriptTalent*);
    int32_t LoadTalent(CResGFF*, CResStruct*);
    int32_t SaveTalent(CResGFF*, CResStruct*);
};

void CScriptTalent__CScriptTalentCtor(CScriptTalent* thisPtr);
void CScriptTalent__CScriptTalentDtor(CScriptTalent* thisPtr);
void CScriptTalent__CopyScriptTalent(CScriptTalent* thisPtr, CScriptTalent*);
int32_t CScriptTalent__Equals(CScriptTalent* thisPtr, CScriptTalent*);
int32_t CScriptTalent__LoadTalent(CScriptTalent* thisPtr, CResGFF*, CResStruct*);
int32_t CScriptTalent__SaveTalent(CScriptTalent* thisPtr, CResGFF*, CResStruct*);

}

}
