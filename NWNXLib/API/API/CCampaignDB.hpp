#pragma once
#include "nwn_api.hpp"
#include "CExoString.hpp"
#include "JsonEngineStructure.hpp"
#include "Database.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CCampaignDB)
#endif

struct Vector;
struct CScriptLocation;

struct CCampaignDB
{
    std::unordered_map<std::string, std::shared_ptr<NWSQLite::Database>> m_open_dbs;
    char NWCompressedBuffer_CompressedBufferHandler_m_cbh_size_placeholder[104];

    CCampaignDB();
    virtual ~CCampaignDB();
    float GetFloat(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, float fOtherwise = 0.0f);
    int32_t GetInt(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, int32_t nOtherwise = 0);
    Vector* GetVector(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId);
    CScriptLocation* GetLocation(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId);
    CExoString GetString(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const CExoString& sOtherwise = "");
    JsonEngineStructure GetJson(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId);
    DataBlockRef GetBinaryData(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId);
    bool SetFloat(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, float flData);
    bool SetInt(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, int32_t nData);
    bool SetVector(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const Vector &vData);
    bool SetLocation(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const CScriptLocation &locData);
    bool SetString(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const CExoString &sData);
    bool SetJson(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const JsonEngineStructure& data);
    bool SetBinaryData(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId, const DataViewRef& data, RESTYPE restypeHint);
    bool DeleteVar(const CExoString &sDatabase, const CExoString &sVarName, const CExoString &sPlayerId);
    bool DestroyDatabase(const CExoString &sDatabase);
    bool HasEntry(const CExoString &sDatabase, char nVarType, const CExoString &sVarName, const CExoString &sPlayerId);
    std::unique_ptr<NWSQLite::Database> OpenDatabase(const CExoString& sDatabase, bool tableAuthorizer);
    std::shared_ptr<NWSQLite::Database> GetDatabaseFor(const CExoString& sDatabase, bool tableAuthorizer);
    void MigrateLegacyRecords();
    void HandleError(std::exception& err);
    std::tuple<bool, DataBlockRef> Compress(const DataViewRef& in, RESTYPE advisoryResType, const CExoString& debugOrigin);
    DataBlockRef Decompress(const DataViewRef& in, bool compressed, const CExoString& debugOrigin);

    static CExoString SanitiseDatabaseName(const CExoString& sDatabase)
    {
        CExoString sanitised = sDatabase.LowerCase();
        sanitised.StripNonAlphaNumeric();
        return sanitised;
    }

    static CExoString SanitiseVariableName(const CExoString& sVarName)
    {
        return sVarName.Left(32);
    }

    static CExoString SanitisePlayerId(const CExoString& sPlayerId)
    {
        return sPlayerId.Left(32);
    }

    std::shared_ptr<NWSQLite::Database> GetDatabaseForUserAccess(const CExoString& sDatabase)
    {
        return GetDatabaseFor(sDatabase, true);
    }

    template<typename T>
    T WithDB(const CExoString& sDatabase, const T otherwise, std::function<T(sqlite::database&)> call)
    {
        try
        {
            return call(*GetDatabaseFor(sDatabase, false));
        }
        catch (std::exception& err)
        {
            HandleError(err);
            return otherwise;
        }
    }

#ifdef NWN_CLASS_EXTENSION_CCampaignDB
    NWN_CLASS_EXTENSION_CCampaignDB
#endif
};

#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CCampaignDB)
#endif
