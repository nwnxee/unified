#pragma once
#include "nwn_api.hpp"

#include "External/sqlite3/sqlite_modern_cpp/sqlite_modern_cpp.h"
#include "InstanceLookupList.hpp"
#include "CExoString.hpp"


namespace NWSQLite {

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Database)
#endif

namespace Migrations
{
struct Definition
{
    struct MigrationDef
    {
        const char* m_label;
        const char* m_sql;
    };

    Definition() : m_schema(nullptr) {}
    Definition(const char* schema, std::vector<MigrationDef> migrations) : m_schema(schema), m_migrations(migrations) {}
    const char* m_schema;
    std::vector<MigrationDef> m_migrations;
};
}

struct Database : sqlite::database, InstanceLookup::List<Database>
{
    using TableAccessAuthorizer = std::function<bool(const std::string& table, bool write_or_read)>;
    const std::string m_label;
    const std::string m_path;
    const bool m_writeable;
    bool m_delete_after_close;
    bool m_authorizer_enabled;
    TableAccessAuthorizer m_table_access_authorizer;
    bool m_transaction;

    Database(const Database& other) = delete;
    Database& operator=(const Database&) = delete;
    Database(const std::string & identifier, const std::string & path, DataViewRef copyAtomically = nullptr, const Migrations::Definition & source = NWSQLite::Migrations::Definition());
    virtual ~Database()
    {
        if (m_delete_after_close && m_path != "" && m_path != ":memory:")
        {
            _db = nullptr;
            (void)remove(m_path.c_str());
        }
    }
    void Setup();


#ifdef NWN_CLASS_EXTENSION_Database
    NWN_CLASS_EXTENSION_Database
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Database)
#endif

}
