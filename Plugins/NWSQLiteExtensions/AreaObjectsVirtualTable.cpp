#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlaceable.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_AreaObjectsVirtualTableEnabled = false;
static int SetupAreaObjectsVirtualTableModule(sqlite3 *db);

void AreaObjectsVirtualTable() __attribute__((constructor));
void AreaObjectsVirtualTable()
{
    if ((s_AreaObjectsVirtualTableEnabled = Config::Get<bool>("ENABLE_INVENTORY_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the AreaObjects Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (SetupAreaObjectsVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the AreaObjects Virtual Table Module.");
                    s_AreaObjectsVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

typedef struct vAreaObjects_tab vAreaObjects_tab;
struct vAreaObjects_tab
{
    sqlite3_vtab base;
};

typedef struct vAreaObjects_cursor vAreaObjects_cursor;
struct vAreaObjects_cursor
{
    sqlite3_vtab_cursor base;
    ObjectID oidArea;
    int32_t currentObjectIndex;
    int32_t objectFilter;
    bool skipStaticPlaceables;
};

namespace AreaObjectsColumns
{
    enum TYPE
    {
        ObjectID = 0,
        AreaObjectID,
        ObjectFilter,
        SkipStaticPlaceables,
        Num, // Keep Last
    };
    constexpr int32_t MAX = 3;
    constexpr int32_t NUM = MAX + 1;
    static_assert(MAX == SkipStaticPlaceables);
    static_assert(NUM == Num);

    constexpr const char* ToColumnWithType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "oid INTEGER",
            "area_oid INTEGER HIDDEN",
            "object_filter INTEGER HIDDEN",
            "skip_static_placeables INTEGER HIDDEN",
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

static void vAreaObjectsSetErrmsg(vAreaObjects_cursor *pCur, const char *zFmt, ...)
{
    va_list ap;
    va_start(ap, zFmt);
    pCur->base.pVtab->zErrMsg = sqlite3_vmprintf(zFmt, ap);
    va_end(ap);
}

static CNWSObject* vAreaObjectsGetCurrentObject(ObjectID oidArea, int32_t nCurrentObjectIndex)
{
    if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(oidArea)))
    {
        if (nCurrentObjectIndex < pArea->m_aGameObjects.num)
        {
            return Utils::AsNWSObject(Utils::GetGameObject(pArea->m_aGameObjects[nCurrentObjectIndex]));
        }
    }

    return nullptr;
}

static int vAreaObjectsConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux; (void)argc; (void)argv; (void)pzErr;

    vAreaObjects_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, AreaObjectsColumns::GetSchema().CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<vAreaObjects_tab*>(sqlite3_malloc(sizeof(vAreaObjects_tab)));
        if (!pNewVtab)
            return SQLITE_NOMEM;

        memset(pNewVtab, 0, sizeof(vAreaObjects_tab));
        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int vAreaObjectsDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (vAreaObjects_tab*)pVtab;
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int vAreaObjectsOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<vAreaObjects_cursor*>(sqlite3_malloc(sizeof(vAreaObjects_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(vAreaObjects_cursor));
    pCursor->oidArea = Constants::OBJECT_INVALID;
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int vAreaObjectsClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vAreaObjects_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int vAreaIncrementObjectIndexIfInvalid(vAreaObjects_cursor *pCursor)
{
    auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(pCursor->oidArea));
    if (!pArea)
        return SQLITE_ERROR;

    CGameObject *pGO;
    while (pCursor->currentObjectIndex < pArea->m_aGameObjects.num && (pGO = Utils::GetGameObject(pArea->m_aGameObjects[pCursor->currentObjectIndex])) &&
           (!(pCursor->objectFilter & Utils::EngineObjectTypeToNWScriptObjectType(pGO->m_nObjectType)) ||
           (pCursor->skipStaticPlaceables && pGO->m_nObjectType == Constants::ObjectType::Placeable && Utils::AsNWSPlaceable(pGO)->m_bStaticObject)))
    {
        pCursor->currentObjectIndex++;
    }

    return SQLITE_OK;
}

static int vAreaObjectsNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vAreaObjects_cursor*)cur;
    pCursor->currentObjectIndex++;
    return vAreaIncrementObjectIndexIfInvalid(pCursor);
}

static int vAreaObjectsColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int nColumn)
{
    auto *pCursor = (vAreaObjects_cursor*)cur;

    if (nColumn == AreaObjectsColumns::AreaObjectID ||
        nColumn == AreaObjectsColumns::ObjectFilter ||
        nColumn == AreaObjectsColumns::SkipStaticPlaceables)
        return SQLITE_OK;

    if (auto *pObject = vAreaObjectsGetCurrentObject(pCursor->oidArea, pCursor->currentObjectIndex))
    {
        switch (nColumn)
        {
            case AreaObjectsColumns::ObjectID:
            {
                sqlite3_result_int(ctx, pObject->m_idSelf);
                break;
            }

            default:
                LOG_WARNING("Forgot to implement a column?");
                break;
        }
    }

    return SQLITE_OK;
}

static int vAreaObjectsRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (vAreaObjects_cursor*)cur;
    *pRowid = pCursor->currentObjectIndex;
    return SQLITE_OK;
}

static int vAreaObjectsEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vAreaObjects_cursor*)cur;
    auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(pCursor->oidArea));
    if (!pArea)
        return true;
    return pCursor->currentObjectIndex >= pArea->m_aGameObjects.num;
}

static int vAreaObjectsFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxStr;
    auto *pCursor = (vAreaObjects_cursor*)cur;
    pCursor->oidArea = Constants::OBJECT_INVALID;
    pCursor->currentObjectIndex = 0;
    pCursor->objectFilter = 32767;
    pCursor->skipStaticPlaceables = false;

    if ((idxNum & 1) && argc >= 1)
    {
        if (sqlite3_value_type(argv[0]) == SQLITE_INTEGER)
            pCursor->oidArea = sqlite3_value_int(argv[0]);
        else if (sqlite3_value_type(argv[0]) == SQLITE_TEXT)
            pCursor->oidArea = Utils::StringToObjectID((const char*)sqlite3_value_text(argv[0]));
        else
        {
            vAreaObjectsSetErrmsg(pCursor, "AreaObjectsVirtualTable: Invalid Target Parameter Specified!");
            return SQLITE_ERROR;
        }
    }
    else
    {
        vAreaObjectsSetErrmsg(pCursor, "AreaObjectsVirtualTable: No Area Specified!");
        return SQLITE_ERROR;
    }

    if ((idxNum & 2) && argc >= 2)
    {
        if (sqlite3_value_type(argv[1]) == SQLITE_INTEGER)
            pCursor->objectFilter = sqlite3_value_int(argv[1]);
    }

    if ((idxNum & 4) && argc >= 3)
    {
        if (sqlite3_value_type(argv[2]) == SQLITE_INTEGER)
            pCursor->skipStaticPlaceables = !!sqlite3_value_int(argv[2]);
    }

    auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(pCursor->oidArea));
    if (!pArea)
    {
        vAreaObjectsSetErrmsg(pCursor, "AreaObjectsVirtualTable: Invalid Area Or Non-Area Object Specified! ObjectID = %s", Utils::ObjectIDToString(pCursor->oidArea).c_str());
        return SQLITE_ERROR;
    }

    return vAreaIncrementObjectIndexIfInvalid(pCursor);
}

static int vAreaObjectsBestIndex(sqlite3_vtab*, sqlite3_index_info *pIndexInfo)
{
    int nTargetAreaConstraintIndex = -1;
    int nObjectTypeFilterConstraintIndex = -1;
    int nSkipStaticPlaceablesConstraintIndex = -1;
    for (int i = 0; i < pIndexInfo->nConstraint; i++)
    {
        auto constraint = pIndexInfo->aConstraint[i];
        if (constraint.iColumn == AreaObjectsColumns::AreaObjectID)
        {
            if (constraint.usable)
                nTargetAreaConstraintIndex = i;
        }

        if (constraint.iColumn == AreaObjectsColumns::ObjectFilter)
        {
            if (constraint.usable)
                nObjectTypeFilterConstraintIndex = i;
        }

        if (constraint.iColumn == AreaObjectsColumns::SkipStaticPlaceables)
        {
            if (constraint.usable)
                nSkipStaticPlaceablesConstraintIndex = i;
        }
    }

    if (nTargetAreaConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 1;
        pIndexInfo->aConstraintUsage[nTargetAreaConstraintIndex].argvIndex = 1;
        pIndexInfo->aConstraintUsage[nTargetAreaConstraintIndex].omit = true;
    }

    if (nObjectTypeFilterConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 2;
        pIndexInfo->aConstraintUsage[nObjectTypeFilterConstraintIndex].argvIndex = 2;
        pIndexInfo->aConstraintUsage[nObjectTypeFilterConstraintIndex].omit = true;
    }

    if (nSkipStaticPlaceablesConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 4;
        pIndexInfo->aConstraintUsage[nSkipStaticPlaceablesConstraintIndex].argvIndex = 3;
        pIndexInfo->aConstraintUsage[nSkipStaticPlaceablesConstraintIndex].omit = true;
    }

    return SQLITE_OK;
}

static int SetupAreaObjectsVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module vAreaObjectsModule =
    {
        0,
        nullptr,
        vAreaObjectsConnect,
        vAreaObjectsBestIndex,
        vAreaObjectsDisconnect,
        nullptr,
        vAreaObjectsOpen,
        vAreaObjectsClose,
        vAreaObjectsFilter,
        vAreaObjectsNext,
        vAreaObjectsEOF,
        vAreaObjectsColumn,
        vAreaObjectsRowid,
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

    return sqlite3_create_module_v2(db, "areaobjects", &vAreaObjectsModule, nullptr, nullptr);
}
