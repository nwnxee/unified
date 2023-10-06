#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWRules.hpp"
#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWSModule.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_2DAVirtualTableEnabled = false;
static int Setup2DAVirtualTableModule(sqlite3 *db);

void TwoDAVirtualTable() __attribute__((constructor));
void TwoDAVirtualTable()
{
    if ((s_2DAVirtualTableEnabled = Config::Get<bool>("ENABLE_2DA_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the 2DA Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (Setup2DAVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the 2DA Virtual Table Module.");
                    s_2DAVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

NWNX_EXPORT ArgumentStack CreateVirtual2DATable(ArgumentStack&& args)
{
    const auto twodaName = args.extract<std::string>();
      ASSERT_OR_THROW(!twodaName.empty());
    const auto columnTypeHints = args.extract<std::string>();
    const auto tableName = args.extract<std::string>();

    if (!s_2DAVirtualTableEnabled)
    {
        LOG_ERROR("(CreateVirtual2DATable) Unable to create 2DA virtual table; module not enabled.");
        return false;
    }

    auto *p2DA = Globals::Rules()->m_p2DArrays->GetCached2DA(twodaName);
    if (!p2DA)
    {
        LOG_ERROR("(CreateVirtual2DATable) Unable to create 2DA virtual table; 2DA with name '%s' does not exist.", twodaName);
        return false;
    }

    if (auto *pModule = Utils::GetModule())
    {
        if (auto pDatabase = pModule->m_sqlite3)
        {
            pDatabase->m_authorizer_enabled = false;
            SCOPEGUARD(pDatabase->m_authorizer_enabled = true);
            *pDatabase << "CREATE VIRTUAL TABLE IF NOT EXISTS " + (tableName.empty() ? twodaName : tableName) +
                          " USING v2da(" + twodaName + (columnTypeHints.empty() ? "" : "," + columnTypeHints) + ");";
            return true;
        }
    }
    return false;
}

typedef struct v2da_tab v2da_tab;
struct v2da_tab
{
    sqlite3_vtab base;
    char *twodaName;
    uint32_t numRows;
    uint8_t *columnTypes;
};

typedef struct v2da_cursor v2da_cursor;
struct v2da_cursor
{
    sqlite3_vtab_cursor base;
    uint32_t currentRow;
};

namespace V2DAColumnType
{
    enum TYPE
    {
        String      = 0,
        Integer     = 1,
        Float       = 2,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 2;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "String",
            "Integer",
            "Float",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }

    constexpr const char* ToColumnType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "TEXT",
            "INTEGER",
            "REAL",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

static int v2daConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux;

    LOG_DEBUG("Creating Virtual 2DA Table");

    if (argc < 4)
    {
        *pzErr = sqlite3_mprintf("No 2DA specified");
        return SQLITE_ERROR;
    }

    LOG_DEBUG("  2DAName: %s", argv[3]);

    auto *p2DA = Globals::Rules()->m_p2DArrays->GetCached2DA(argv[3]);
    if (!p2DA)
    {
        *pzErr = sqlite3_mprintf("Could not load 2DA with name: '%s'", argv[3]);
        return SQLITE_ERROR;
    }

    auto *columnTypes = static_cast<uint8_t*>(sqlite3_malloc(p2DA->m_nNumColumns * sizeof(uint8_t)));
    if (!columnTypes) return SQLITE_NOMEM;
    memset(columnTypes, V2DAColumnType::String, p2DA->m_nNumColumns * sizeof(uint8_t));
    if (argc >= 5 && argv[4])
    {
        LOG_DEBUG("  ColumnTypeHints: %s", argv[4]);
        int32_t colHintLength = strlen(argv[4]);
        int32_t maxLength = colHintLength <= p2DA->m_nNumColumns ? colHintLength : p2DA->m_nNumColumns;
        for (int32_t i = 0; i < maxLength; i++)
        {
            if ((argv[4])[i] == '1')
                columnTypes[i] = V2DAColumnType::Integer;
            else if ((argv[4])[i] == '2')
                columnTypes[i] = V2DAColumnType::Float;
            else
                columnTypes[i] = V2DAColumnType::String;

            LOG_DEBUG("    Type Hint for Column %i (%s) = %s", i, p2DA->m_pColumnLabel[i], V2DAColumnType::ToString(columnTypes[i]));
        }
    }

    CExoString sSchema = "CREATE TABLE x(";
    for (int32_t i = 0; i < p2DA->m_nNumColumns; i++)
    {
        sSchema.Format("%s%s%s %s", sSchema.CStr(), i ? ", " : "", p2DA->m_pColumnLabel[i].CStr(), V2DAColumnType::ToColumnType(columnTypes[i]));
    }
    sSchema.Format("%s);", sSchema.CStr());

    LOG_DEBUG("  Schema: %s", sSchema);

    v2da_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, sSchema.CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<v2da_tab*>(sqlite3_malloc(sizeof(v2da_tab)));
        if (!pNewVtab)
        {
            sqlite3_free(columnTypes);
            return SQLITE_NOMEM;
        }

        memset(pNewVtab, 0, sizeof(v2da_tab));
        pNewVtab->twodaName = sqlite3_mprintf("%s", argv[3]);
        pNewVtab->numRows = p2DA->m_nNumRows;
        pNewVtab->columnTypes = columnTypes;

        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int v2daCreate(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    return v2daConnect(db, pAux, argc, argv, ppVtab, pzErr);
}

static int v2daDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (v2da_tab*)pVtab;
    sqlite3_free(p2daVtab->twodaName);
    sqlite3_free(p2daVtab->columnTypes);
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int v2daOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<v2da_cursor*>(sqlite3_malloc(sizeof(v2da_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(v2da_cursor));
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int v2daClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (v2da_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int v2daNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (v2da_cursor*)cur;
    pCursor->currentRow++;
    return SQLITE_OK;
}

static int v2daColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int i)
{
    auto *pCursor = (v2da_cursor*)cur;
    auto *pVtab = (v2da_tab*)pCursor->base.pVtab;

    if (auto *p2DA = Globals::Rules()->m_p2DArrays->GetCached2DA(pVtab->twodaName))
    {
        switch (pVtab->columnTypes[i])
        {
            case V2DAColumnType::String:
            {
                CExoString sValue;
                if (p2DA->GetCExoStringEntry(pCursor->currentRow, i, &sValue))
                {
                    sqlite3_result_text(ctx, sValue.CStr(), -1, SQLITE_TRANSIENT);
                    return SQLITE_OK;
                }
                break;
            }

            case V2DAColumnType::Integer:
            {
                int32_t nValue;
                if (p2DA->GetINTEntry(pCursor->currentRow, i, &nValue))
                {
                    sqlite3_result_int(ctx, nValue);
                    return SQLITE_OK;
                }
                break;
            }

            case V2DAColumnType::Float:
            {
                float fValue;
                if (p2DA->GetFLOATEntry(pCursor->currentRow, i, &fValue))
                {
                    sqlite3_result_double(ctx, fValue);
                    return SQLITE_OK;
                }
                break;
            }
        }
    }

    // If we end up here, a NULL value will be returned.

    return SQLITE_OK;
}

static int v2daRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (v2da_cursor*)cur;
    *pRowid = pCursor->currentRow;
    return SQLITE_OK;
}

static int v2daEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (v2da_cursor*)cur;
    auto *pVtab = (v2da_tab*)pCursor->base.pVtab;
    return pCursor->currentRow >= pVtab->numRows;
}

static int v2daFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxNum; (void)idxStr; (void)argc; (void)argv;
    auto *pCursor = (v2da_cursor*)cur;
    pCursor->currentRow = 0;
    return SQLITE_OK;
}

static int v2daBestIndex(sqlite3_vtab*, sqlite3_index_info*)
{
    return SQLITE_OK;
}

static int Setup2DAVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module v2daModule =
    {
        0,
        v2daCreate,
        v2daConnect,
        v2daBestIndex,
        v2daDisconnect,
        v2daDisconnect,
        v2daOpen,
        v2daClose,
        v2daFilter,
        v2daNext,
        v2daEOF,
        v2daColumn,
        v2daRowid,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    };

    return sqlite3_create_module_v2(db, "v2da", &v2daModule, nullptr, nullptr);
}
