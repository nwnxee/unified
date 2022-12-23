#pragma once
#include "nwn_api.hpp"
#include "CExoString.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(JsonEngineStructure)
#endif

struct JsonEngineStructureShared
{
    uint64_t m_id = 0;
    json m_json;
    CExoString m_error;
};

struct JsonEngineStructure : public SharedPtrEngineStructure<JsonEngineStructureShared>
{
    JsonEngineStructure()
    {
        m_shared = std::make_shared<JsonEngineStructureShared>();
        m_shared->m_id = ++(*GetNextIdPtr());
    }

    JsonEngineStructure(const json& j, const CExoString& err)
    {
        m_shared = std::make_shared<JsonEngineStructureShared>();
        m_shared->m_id = ++(*GetNextIdPtr());
        m_shared->m_json = j;
        m_shared->m_error = err;
    }

    JsonEngineStructure(json&& j, CExoString&& err)
    {
        m_shared = std::make_shared<JsonEngineStructureShared>();
        m_shared->m_id = ++(*GetNextIdPtr());
        m_shared->m_json = std::move(j);
        m_shared->m_error = std::move(err);
    }

    virtual ~JsonEngineStructure() {}

    static uint64_t* GetNextIdPtr();

    bool IsEmpty() const { return m_shared->m_json.is_null(); }
    void Clear() { m_shared->m_json = nullptr; m_shared->m_error = ""; }
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(JsonEngineStructure)
#endif

