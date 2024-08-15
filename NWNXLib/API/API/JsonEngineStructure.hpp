#pragma once
#include "nwn_api.hpp"
#include "CExoString.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(JsonEngineStructure)
#endif

struct JsonEngineStructureShared
{
    const uint64_t m_id;
    json m_json;
    CExoString m_error;
};

struct JsonEngineStructure : public SharedPtrEngineStructure<JsonEngineStructureShared>
{
    JsonEngineStructure();
    JsonEngineStructure(const json& j, const CExoString& err);
    JsonEngineStructure(json&& j, CExoString&& err);
    virtual ~JsonEngineStructure() {}
    bool IsEmpty() const override;
    void Clear() override;
    void Unlink() override;
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(JsonEngineStructure)
#endif

