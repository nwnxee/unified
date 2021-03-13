#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CScriptLocation.hpp"
#include "CassowarySolverEngineStructure.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSScriptVar)
#endif



typedef uint32_t OBJECT_ID;


struct CNWSScriptVar
{
    int32_t m_int;
    float m_float;
    OBJECT_ID m_objectId;
    CExoString m_string;
    CScriptLocation m_location;
    CassowarySolverEngineStructure m_cswy;

    CNWSScriptVar();
    CNWSScriptVar(const CNWSScriptVar &);
    CNWSScriptVar & operator=(const CNWSScriptVar &);
    void Reset(uint32_t nVarType);

    bool HasInt() const { return m_int != 0; }
    bool HasFloat() const { return m_float != 0.0f; }
    bool HasObject() const { return m_objectId != NWNXLib::API::Constants::OBJECT_INVALID; }
    bool HasString() const { return !m_string.IsEmpty(); }
    bool HasLocation() const { return m_location.m_oArea != NWNXLib::API::Constants::OBJECT_INVALID; }


#ifdef NWN_CLASS_EXTENSION_CNWSScriptVar
    NWN_CLASS_EXTENSION_CNWSScriptVar
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSScriptVar)
#endif

