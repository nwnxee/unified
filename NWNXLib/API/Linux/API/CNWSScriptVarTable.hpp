#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCNWSScriptVar.hpp"
#include "CExoString.hpp"
#include "CScriptLocation.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSCreature;
struct CNWSScriptVar;
struct CResGFF;
struct CResStruct;

struct CNWSScriptVarTable
{
    CExoArrayListTemplatedCNWSScriptVar m_lVarList;
    CNWSCreature* m_pCreature;

    // The below are auto generated stubs.
    CNWSScriptVarTable() = default;
    CNWSScriptVarTable(const CNWSScriptVarTable&) = default;
    CNWSScriptVarTable& operator=(const CNWSScriptVarTable&) = default;

    ~CNWSScriptVarTable();
    void DeleteIndex(CExoString&, uint32_t);
    void DestroyFloat(CExoString&);
    void DestroyInt(CExoString&);
    void DestroyLocation(CExoString&);
    void DestroyObject(CExoString&);
    void DestroyString(CExoString&);
    float GetFloat(CExoString&);
    int32_t GetInt(CExoString&);
    CScriptLocation GetLocation(CExoString&);
    uint32_t GetObject(CExoString&);
    CExoString GetString(CExoString&);
    void LoadVarTable(CResGFF*, CResStruct*);
    CNWSScriptVar* MatchIndex(CExoString&, uint32_t, int32_t);
    void SaveVarTable(CResGFF*, CResStruct*);
    void SetFloat(CExoString&, float);
    void SetInt(CExoString&, int32_t, int32_t);
    void SetLocation(CExoString&, CScriptLocation);
    void SetObject(CExoString&, uint32_t);
    void SetString(CExoString&, CExoString&);
};

void CNWSScriptVarTable__CNWSScriptVarTableDtor(CNWSScriptVarTable* thisPtr);
void CNWSScriptVarTable__DeleteIndex(CNWSScriptVarTable* thisPtr, CExoString&, uint32_t);
void CNWSScriptVarTable__DestroyFloat(CNWSScriptVarTable* thisPtr, CExoString&);
void CNWSScriptVarTable__DestroyInt(CNWSScriptVarTable* thisPtr, CExoString&);
void CNWSScriptVarTable__DestroyLocation(CNWSScriptVarTable* thisPtr, CExoString&);
void CNWSScriptVarTable__DestroyObject(CNWSScriptVarTable* thisPtr, CExoString&);
void CNWSScriptVarTable__DestroyString(CNWSScriptVarTable* thisPtr, CExoString&);
float CNWSScriptVarTable__GetFloat(CNWSScriptVarTable* thisPtr, CExoString&);
int32_t CNWSScriptVarTable__GetInt(CNWSScriptVarTable* thisPtr, CExoString&);
CScriptLocation CNWSScriptVarTable__GetLocation(CNWSScriptVarTable* thisPtr, CExoString&);
uint32_t CNWSScriptVarTable__GetObject(CNWSScriptVarTable* thisPtr, CExoString&);
CExoString CNWSScriptVarTable__GetString(CNWSScriptVarTable* thisPtr, CExoString&);
void CNWSScriptVarTable__LoadVarTable(CNWSScriptVarTable* thisPtr, CResGFF*, CResStruct*);
CNWSScriptVar* CNWSScriptVarTable__MatchIndex(CNWSScriptVarTable* thisPtr, CExoString&, uint32_t, int32_t);
void CNWSScriptVarTable__SaveVarTable(CNWSScriptVarTable* thisPtr, CResGFF*, CResStruct*);
void CNWSScriptVarTable__SetFloat(CNWSScriptVarTable* thisPtr, CExoString&, float);
void CNWSScriptVarTable__SetInt(CNWSScriptVarTable* thisPtr, CExoString&, int32_t, int32_t);
void CNWSScriptVarTable__SetLocation(CNWSScriptVarTable* thisPtr, CExoString&, CScriptLocation);
void CNWSScriptVarTable__SetObject(CNWSScriptVarTable* thisPtr, CExoString&, uint32_t);
void CNWSScriptVarTable__SetString(CNWSScriptVarTable* thisPtr, CExoString&, CExoString&);

}

}
