#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CNWSScriptVar.hpp"
#include "CScriptLocation.hpp"
#include "CassowarySolverEngineStructure.hpp"
#include "JsonEngineStructure.hpp"
#include <unordered_map>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSScriptVarTable)
#endif

struct CNWSCreature;
struct CNWSScriptVar;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSScriptVarTable
{
    std::unordered_map<CExoString, CNWSScriptVar> m_vars;
    CNWSCreature * m_pCreature;

    int32_t GetInt(CExoString & sVarName);
    float GetFloat(CExoString & sVarName);
    CExoString GetString(CExoString & sVarName);
    OBJECT_ID GetObject(CExoString & sVarName);
    CScriptLocation GetLocation(CExoString & sVarName);
    CassowarySolverEngineStructure GetCswy(CExoString & sVarName);
    JsonEngineStructure GetJson(CExoString & sVarName);
    void SetInt(CExoString & sVarName, int32_t nValue, BOOL bLoading = false);
    void SetFloat(CExoString & sVarName, float fValue);
    void SetString(CExoString & sVarName, CExoString & sValue);
    void SetObject(CExoString & sVarName, OBJECT_ID oValue);
    void SetLocation(CExoString & sVarName, CScriptLocation lValue);
    void SetCswy(CExoString & sVarName, CassowarySolverEngineStructure cSolver);
    void SetJson(CExoString & sVarName, JsonEngineStructure cJson);
    void DestroyInt(CExoString & sVarName);
    void DestroyFloat(CExoString & sVarName);
    void DestroyString(CExoString & sVarName);
    void DestroyObject(CExoString & sVarName);
    void DestroyLocation(CExoString & sVarName);
    void DestroyCswy(CExoString & sVarName);
    void DestroyJson(CExoString & sVarName);
    void LoadVarTable(CResGFF * pRes, CResStruct * pStruct);
    void SaveVarTable(CResGFF * pRes, CResStruct * pStruct);
    CNWSScriptVar * MatchIndex(CExoString & sVarName, uint32_t nVarType, BOOL bCreate);
    void DeleteIndex(CExoString & sVarName, uint32_t nVarType);


#ifdef NWN_CLASS_EXTENSION_CNWSScriptVarTable
    NWN_CLASS_EXTENSION_CNWSScriptVarTable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSScriptVarTable)
#endif

