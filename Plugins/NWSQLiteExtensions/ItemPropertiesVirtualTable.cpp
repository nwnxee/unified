#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWSItem.hpp"
#include "API/CGameEffect.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_ItemPropertiesVirtualTableEnabled = false;
static int SetupItemPropertiesVirtualTableModule(sqlite3 *db);

void ItemPropertiesVirtualTable() __attribute__((constructor));
void ItemPropertiesVirtualTable()
{
    if ((s_ItemPropertiesVirtualTableEnabled = Config::Get<bool>("ENABLE_ITEMPROPERTIES_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the ItemProperties Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (SetupItemPropertiesVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the ItemProperties Virtual Table Module.");
                    s_ItemPropertiesVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

typedef struct vItemProperties_tab vItemProperties_tab;
struct vItemProperties_tab
{
    sqlite3_vtab base;
};

typedef struct vItemProperties_cursor vItemProperties_cursor;
struct vItemProperties_cursor
{
    sqlite3_vtab_cursor base;
    ObjectID oidItem;
    uint32_t currentItemPropertyIndex;
};

namespace ItemPropertiesColumns
{
    enum TYPE
    {
        Type = 0,
        SubType,
        CostTable,
        CostTableValue,
        Param1,
        Param1Value,
        Tag,
        ItemOID,
        Num, // Keep Last
    };
    constexpr int32_t MAX = 7;
    constexpr int32_t NUM = MAX + 1;
    static_assert(MAX == ItemOID);
    static_assert(NUM == Num);

    constexpr const char* ToColumnWithType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "type INTEGER",
            "subtype INTEGER",
            "cost_table INTEGER",
            "cost_table_value INTEGER",
            "param1 INTEGER",
            "param1_value INTEGER",
            "tag TEXT",
            "target_item_oid INTEGER HIDDEN",
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

static void vItemPropertiesSetErrmsg(vItemProperties_cursor *pCur, const char *zFmt, ...)
{
    va_list ap;
    va_start(ap, zFmt);
    pCur->base.pVtab->zErrMsg = sqlite3_vmprintf(zFmt, ap);
    va_end(ap);
}

static int vItemPropertiesConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux; (void)argc; (void)argv; (void)pzErr;

    vItemProperties_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, ItemPropertiesColumns::GetSchema().CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<vItemProperties_tab*>(sqlite3_malloc(sizeof(vItemProperties_tab)));
        if (!pNewVtab)
            return SQLITE_NOMEM;

        memset(pNewVtab, 0, sizeof(vItemProperties_tab));
        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int vItemPropertiesDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (vItemProperties_tab*)pVtab;
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int vItemPropertiesOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<vItemProperties_cursor*>(sqlite3_malloc(sizeof(vItemProperties_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(vItemProperties_cursor));
    pCursor->oidItem = Constants::OBJECT_INVALID;
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int vItemPropertiesClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vItemProperties_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int vItemPropertiesNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vItemProperties_cursor*)cur;
    pCursor->currentItemPropertyIndex++;
    return SQLITE_OK;
}

static CGameEffect *vItemPropertiesGetCurrentItemProperty(ObjectID oidItem, uint32_t nCurrentItemPropertyIndex)
{
    int32_t nIndex = 0;
    uint32_t nCount = 0;
    if (auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItem)))
    {
        while (nIndex < pItem->m_appliedEffects.num)
        {
            auto *pEffect = pItem->m_appliedEffects[nIndex];
            if (pEffect->m_bExpose && pEffect->m_nType == Constants::EffectTrueType::ItemProperty &&
                (pEffect->GetDurationType() == Constants::EffectDurationType::Permanent ||
                 pEffect->GetDurationType() == Constants::EffectDurationType::Temporary))
            {
                if (nCount == nCurrentItemPropertyIndex)
                    return pEffect;

                nCount++;
            }

            nIndex++;
        }
    }

    return nullptr;
}

static int vItemPropertiesColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int nColumn)
{
    auto *pCursor = (vItemProperties_cursor*)cur;

    if (nColumn == ItemPropertiesColumns::ItemOID)
        return SQLITE_OK;

    if (auto *pItemProperty = vItemPropertiesGetCurrentItemProperty(pCursor->oidItem, pCursor->currentItemPropertyIndex))
    {
        switch (nColumn)
        {
            case ItemPropertiesColumns::Type:
            case ItemPropertiesColumns::SubType:
            case ItemPropertiesColumns::CostTable:
            case ItemPropertiesColumns::CostTableValue:
            case ItemPropertiesColumns::Param1:
            case ItemPropertiesColumns::Param1Value:
            {
                sqlite3_result_int(ctx, pItemProperty->GetInteger(nColumn));
                break;
            }

            case ItemPropertiesColumns::Tag:
            {
                sqlite3_result_text(ctx, pItemProperty->m_sCustomTag.CStr(), -1, SQLITE_TRANSIENT);
                break;
            }

            default:
                LOG_WARNING("Forgot to implement a column?");
                break;
        }
    }

    return SQLITE_OK;
}

static int vItemPropertiesRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (vItemProperties_cursor*)cur;
    *pRowid = pCursor->currentItemPropertyIndex;
    return SQLITE_OK;
}

static int vItemPropertiesEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vItemProperties_cursor*)cur;
    return !vItemPropertiesGetCurrentItemProperty(pCursor->oidItem, pCursor->currentItemPropertyIndex);
}

static int vItemPropertiesFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxStr;
    auto *pCursor = (vItemProperties_cursor*)cur;
    pCursor->oidItem = Constants::OBJECT_INVALID;
    pCursor->currentItemPropertyIndex = 0;

    if ((idxNum & 1) && argc >= 1)
    {
        if (sqlite3_value_type(argv[0]) == SQLITE_INTEGER)
            pCursor->oidItem = sqlite3_value_int(argv[0]);
        else if (sqlite3_value_type(argv[0]) == SQLITE_TEXT)
            pCursor->oidItem = Utils::StringToObjectID((const char*)sqlite3_value_text(argv[0]));
        else
        {
            vItemPropertiesSetErrmsg(pCursor, "ItemPropertyVirtualTable: Invalid Target Parameter Specified!");
            return SQLITE_ERROR;
        }
    }
    else
    {
        vItemPropertiesSetErrmsg(pCursor, "ItemPropertyVirtualTable: No Item Specified!");
        return SQLITE_ERROR;
    }

    auto *pItem= Utils::AsNWSItem(Utils::GetGameObject(pCursor->oidItem));
    if (!pItem)
    {
        vItemPropertiesSetErrmsg(pCursor, "ItemPropertyVirtualTable: Invalid Or Non-Item Target Specified! ObjectID = %s", Utils::ObjectIDToString(pCursor->oidItem).c_str());
        return SQLITE_ERROR;
    }

    return SQLITE_OK;
}

static int vItemPropertiesBestIndex(sqlite3_vtab*, sqlite3_index_info *pIndexInfo)
{
    int nTargetItemConstraintIndex = -1;
    for (int i = 0; i < pIndexInfo->nConstraint; i++)
    {
        auto constraint = pIndexInfo->aConstraint[i];
        if (constraint.iColumn == ItemPropertiesColumns::ItemOID)
        {
            if (constraint.usable)
                nTargetItemConstraintIndex = i;
        }
    }

    if (nTargetItemConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 1;
        pIndexInfo->aConstraintUsage[nTargetItemConstraintIndex].argvIndex = 1;
        pIndexInfo->aConstraintUsage[nTargetItemConstraintIndex].omit = true;
    }

    return SQLITE_OK;
}

static int SetupItemPropertiesVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module vItemPropertiesModule =
    {
        0,
        nullptr,
        vItemPropertiesConnect,
        vItemPropertiesBestIndex,
        vItemPropertiesDisconnect,
        nullptr,
        vItemPropertiesOpen,
        vItemPropertiesClose,
        vItemPropertiesFilter,
        vItemPropertiesNext,
        vItemPropertiesEOF,
        vItemPropertiesColumn,
        vItemPropertiesRowid,
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

    return sqlite3_create_module_v2(db, "itemproperties", &vItemPropertiesModule, nullptr, nullptr);
}
