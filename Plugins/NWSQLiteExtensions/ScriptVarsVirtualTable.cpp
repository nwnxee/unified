#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_ScriptVarsVirtualTableEnabled = false;
static int SetupScriptVarsVirtualTableModule(sqlite3 *db);

void ScriptVarsVirtualTable() __attribute__((constructor));
void ScriptVarsVirtualTable()
{
    if ((s_ScriptVarsVirtualTableEnabled = Config::Get<bool>("ENABLE_SCRIPTVARS_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the ScriptVars Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (SetupScriptVarsVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the ScriptVars Virtual Table Module.");
                    s_ScriptVarsVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

typedef struct vScriptVars_tab vScriptVars_tab;
struct vScriptVars_tab
{
    sqlite3_vtab base;
};

typedef struct vScriptVars_cursor vScriptVars_cursor;
struct vScriptVars_cursor
{
    sqlite3_vtab_cursor base;
    ObjectID oidTarget;
    uint32_t currentScriptVarIndex;
};

namespace ScriptVarsColumns
{
    enum TYPE
    {
        VarName = 0,
        IntValue,
        FloatValue,
        StringValue,
        ObjectValue,
        JsonValue,
        LocationValue,
        CassowaryValue,
        TargetOID,
        Num, // Keep Last
    };
    constexpr int32_t MAX = 8;
    constexpr int32_t NUM = MAX + 1;
    static_assert(MAX == TargetOID);
    static_assert(NUM == Num);

    constexpr const char* ToColumnWithType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "varname TEXT",
            "int INTEGER",
            "float REAL",
            "string TEXT",
            "object INTEGER",
            "json TEXT",
            "location INTEGER",
            "cassowary INTEGER",
            "target_oid INTEGER HIDDEN",
        };
        static_assert((sizeof(TYPE_STRINGS) / sizeof(TYPE_STRINGS[0])) == NUM);
        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }

    static CExoString GetSchema()
    {
        CExoString sSchema = "CREATE TABLE x(";
        for (int i = 0; i < NUM; i++)
        {
            sSchema.Format("%s%s%s", sSchema.CStr(), i ? ", " : "", ToColumnWithType(i));
        }
        sSchema.Format("%s);", sSchema.CStr());
        return sSchema;
    }
}

static void vScriptVarsSetErrmsg(vScriptVars_cursor *pCur, const char *zFmt, ...)
{
    va_list ap;
    va_start(ap, zFmt);
    pCur->base.pVtab->zErrMsg = sqlite3_vmprintf(zFmt, ap);
    va_end(ap);
}

static int vScriptVarsConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux; (void)argc; (void)argv; (void)pzErr;

    vScriptVars_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, ScriptVarsColumns::GetSchema().CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<vScriptVars_tab*>(sqlite3_malloc(sizeof(vScriptVars_tab)));
        if (!pNewVtab)
            return SQLITE_NOMEM;

        memset(pNewVtab, 0, sizeof(vScriptVars_tab));
        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int vScriptVarsDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (vScriptVars_tab*)pVtab;
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int vScriptVarsOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<vScriptVars_cursor*>(sqlite3_malloc(sizeof(vScriptVars_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(vScriptVars_cursor));
    pCursor->oidTarget = Constants::OBJECT_INVALID;
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int vScriptVarsClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vScriptVars_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int vScriptVarsNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vScriptVars_cursor*)cur;
    pCursor->currentScriptVarIndex++;
    return SQLITE_OK;
}

CNWSScriptVarTable* vScriptVarsGetScriptVarTable(ObjectID oidTarget)
{
    if (auto *pGameObject = Utils::GetGameObject(oidTarget))
        return Utils::GetScriptVarTable(pGameObject);
    else
        return nullptr;
}

static int vScriptVarsColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int nColumn)
{
    auto *pCursor = (vScriptVars_cursor*)cur;

    if (nColumn == ScriptVarsColumns::TargetOID)
        return SQLITE_OK;

    if (auto *pScriptVarTable = vScriptVarsGetScriptVarTable(pCursor->oidTarget))
    {
        if (pCursor->currentScriptVarIndex >= pScriptVarTable->m_vars.size())
        {
            vScriptVarsSetErrmsg(pCursor, "ScriptVarsVirtualTable: Row Out Of Bounds!");
            return SQLITE_ERROR;
        }

        auto it = std::next(pScriptVarTable->m_vars.begin(), pCursor->currentScriptVarIndex);

        switch (nColumn)
        {
            case ScriptVarsColumns::VarName:
            {
                sqlite3_result_text(ctx, it->first.CStr(), -1, SQLITE_TRANSIENT);
                break;
            }

            case ScriptVarsColumns::IntValue:
            {
                if (it->second.HasInt())
                    sqlite3_result_int(ctx, it->second.m_int);
                break;
            }

            case ScriptVarsColumns::FloatValue:
            {
                if (it->second.HasFloat())
                    sqlite3_result_double(ctx, it->second.m_float);
                break;
            }

            case ScriptVarsColumns::StringValue:
            {
                if (it->second.HasString())
                    sqlite3_result_text(ctx, it->second.m_string.CStr(), -1, SQLITE_TRANSIENT);
                break;
            }

            case ScriptVarsColumns::ObjectValue:
            {
                if (it->second.HasObject())
                    sqlite3_result_int(ctx, it->second.m_objectId);
                break;
            }

            case ScriptVarsColumns::JsonValue:
            {
                if (it->second.HasJson())
                    sqlite3_result_text(ctx, it->second.m_json.m_shared->m_json.dump().c_str(), -1, SQLITE_TRANSIENT);
                break;
            }

            case ScriptVarsColumns::LocationValue:
            {
                if (it->second.HasLocation())
                    sqlite3_result_int(ctx, 1);
                break;
            }

            case ScriptVarsColumns::CassowaryValue:
            {
                if (it->second.HasCswy())
                    sqlite3_result_int(ctx, 1);
                break;
            }

            default:
                LOG_WARNING("Forgot to implement a column?");
                break;
        }
    }

    return SQLITE_OK;
}

static int vScriptVarsRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (vScriptVars_cursor*)cur;
    *pRowid = pCursor->currentScriptVarIndex;
    return SQLITE_OK;
}

static int vScriptVarsEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vScriptVars_cursor*)cur;
    auto *pScriptVarTable = vScriptVarsGetScriptVarTable(pCursor->oidTarget);
    if (!pScriptVarTable)
        return true;

    return pCursor->currentScriptVarIndex >= pScriptVarTable->m_vars.size();
}

static int vScriptVarsFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxStr;
    auto *pCursor = (vScriptVars_cursor*)cur;
    pCursor->oidTarget = Constants::OBJECT_INVALID;
    pCursor->currentScriptVarIndex = 0;

    if ((idxNum & 1) && argc >= 1)
    {
        if (sqlite3_value_type(argv[0]) == SQLITE_INTEGER)
            pCursor->oidTarget = sqlite3_value_int(argv[0]);
        else if (sqlite3_value_type(argv[0]) == SQLITE_TEXT)
            pCursor->oidTarget = Utils::StringToObjectID((const char*)sqlite3_value_text(argv[0]));
        else
        {
            vScriptVarsSetErrmsg(pCursor, "ScriptVarsVirtualTable: Invalid Target Parameter Specified!");
            return SQLITE_ERROR;
        }
    }
    else
    {
        vScriptVarsSetErrmsg(pCursor, "ScriptVarsVirtualTable: No Target Specified!");
        return SQLITE_ERROR;
    }

    auto *pGameObject= Utils::GetGameObject(pCursor->oidTarget);
    if (!pGameObject)
    {
        vScriptVarsSetErrmsg(pCursor, "ScriptVarsVirtualTable: Invalid Target Specified! ObjectID = %s", Utils::ObjectIDToString(pCursor->oidTarget).c_str());
        return SQLITE_ERROR;
    }

    return SQLITE_OK;
}

static int vScriptVarsBestIndex(sqlite3_vtab*, sqlite3_index_info *pIndexInfo)
{
    int nTargetConstraintIndex = -1;
    for (int i = 0; i < pIndexInfo->nConstraint; i++)
    {
        auto constraint = pIndexInfo->aConstraint[i];
        if (constraint.iColumn == ScriptVarsColumns::TargetOID)
        {
            if (constraint.usable)
                nTargetConstraintIndex = i;
        }
    }

    if (nTargetConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 1;
        pIndexInfo->aConstraintUsage[nTargetConstraintIndex].argvIndex = 1;
        pIndexInfo->aConstraintUsage[nTargetConstraintIndex].omit = true;
    }

    return SQLITE_OK;
}

static int SetupScriptVarsVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module vScriptVarsModule =
    {
        0,
        nullptr,
        vScriptVarsConnect,
        vScriptVarsBestIndex,
        vScriptVarsDisconnect,
        nullptr,
        vScriptVarsOpen,
        vScriptVarsClose,
        vScriptVarsFilter,
        vScriptVarsNext,
        vScriptVarsEOF,
        vScriptVarsColumn,
        vScriptVarsRowid,
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

    return sqlite3_create_module_v2(db, "scriptvars", &vScriptVarsModule, nullptr, nullptr);
}
