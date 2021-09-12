#pragma once
#include "nwn_api.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(JsonEngineStructure)
#endif


struct JsonEngineStructure
{
    json m_json;
    CExoString m_error;

    JsonEngineStructure() {}
    JsonEngineStructure(const json& j, const CExoString& err = "") : m_json(j), m_error(err) {}
    JsonEngineStructure(const JsonEngineStructure& other) : m_json(other.m_json), m_error(other.m_error) {}
    JsonEngineStructure& operator=(const JsonEngineStructure& other)
    {
        m_json = other.m_json;
        m_error = other.m_error;
        return *this;
    }
    bool IsEmpty() const { return m_json.m_type == 0; }
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(JsonEngineStructure)
#endif

