#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSItem.hpp"
#include "API/CItemRepository.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_InventoryVirtualTableEnabled = false;
static int SetupInventoryVirtualTableModule(sqlite3 *db);

void InventoryVirtualTable() __attribute__((constructor));
void InventoryVirtualTable()
{
    if ((s_InventoryVirtualTableEnabled = Config::Get<bool>("ENABLE_INVENTORY_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the Inventory Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (SetupInventoryVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the Inventory Virtual Table Module.");
                    s_InventoryVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

typedef struct vInventory_tab vInventory_tab;
struct vInventory_tab
{
    sqlite3_vtab base;
};

typedef struct vInventory_cursor vInventory_cursor;
struct vInventory_cursor
{
    sqlite3_vtab_cursor base;
    uint32_t rowId;
    ObjectID oidMainTarget;
    uint32_t mainItemIndex;
    ObjectID oidCurrentTarget;
    uint32_t currentItemIndex;
    bool bCheckBags;
};

namespace InventoryColumns
{
    enum TYPE
    {
        ObjectID = 0,
        TargetObjectID,
        CheckContainers,
        Num, // Keep Last
    };
    constexpr int32_t MAX = 2;
    constexpr int32_t NUM = MAX + 1;
    static_assert(MAX == CheckContainers);
    static_assert(NUM == Num);

    constexpr const char* ToColumnWithType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "oid INTEGER",
            "target_oid INTEGER HIDDEN",
            "check_containers INTEGER HIDDEN"
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

static void vInventorySetErrmsg(vInventory_cursor *pCur, const char *zFmt, ...)
{
    va_list ap;
    va_start(ap, zFmt);
    pCur->base.pVtab->zErrMsg = sqlite3_vmprintf(zFmt, ap);
    va_end(ap);
}

static CNWSItem* vInventoryGetCurrentItem(ObjectID oidTarget, uint32_t nCurrentItemIndex)
{
    uint32_t nCount = 0;
    if (auto *pItemRepository = Utils::GetItemRepository(oidTarget))
    {
        CExoLinkedListPosition pos = pItemRepository->m_oidItems.GetHeadPos();
        while (pos)
        {
            if (nCount == nCurrentItemIndex)
                return pItemRepository->ItemListGetItem(pos);

            nCount++;
            pItemRepository->m_oidItems.GetNext(pos);
        }
    }

    return nullptr;
}

static int vInventoryConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux; (void)argc; (void)argv; (void)pzErr;

    vInventory_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, InventoryColumns::GetSchema().CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<vInventory_tab*>(sqlite3_malloc(sizeof(vInventory_tab)));
        if (!pNewVtab)
            return SQLITE_NOMEM;

        memset(pNewVtab, 0, sizeof(vInventory_tab));
        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int vInventoryDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (vInventory_tab*)pVtab;
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int vInventoryOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<vInventory_cursor*>(sqlite3_malloc(sizeof(vInventory_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(vInventory_cursor));
    pCursor->oidMainTarget = Constants::OBJECT_INVALID;
    pCursor->oidCurrentTarget = Constants::OBJECT_INVALID;
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int vInventoryClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vInventory_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int vInventoryNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vInventory_cursor*)cur;
    CNWSItem *pItem = nullptr;

    if (pCursor->bCheckBags)
        pItem = vInventoryGetCurrentItem(pCursor->oidCurrentTarget, pCursor->currentItemIndex);

    pCursor->currentItemIndex++;

    if (pItem && pItem->m_pItemRepository)
    {
        pCursor->oidCurrentTarget = pItem->m_idSelf;
        pCursor->mainItemIndex = pCursor->currentItemIndex;
        pCursor->currentItemIndex = 0;
    }

    pCursor->rowId++;

    return SQLITE_OK;
}

static int vInventoryColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int nColumn)
{
    auto *pCursor = (vInventory_cursor*)cur;

    if (nColumn == InventoryColumns::TargetObjectID || nColumn == InventoryColumns::CheckContainers)
        return SQLITE_OK;

    if (auto *pItem = vInventoryGetCurrentItem(pCursor->oidCurrentTarget, pCursor->currentItemIndex))
    {
        switch (nColumn)
        {
            case InventoryColumns::ObjectID:
            {
                sqlite3_result_int(ctx, pItem->m_idSelf);
                break;
            }

            default:
                LOG_WARNING("Forgot to implement a column?");
                break;
        }
    }

    return SQLITE_OK;
}

static int vInventoryRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (vInventory_cursor*)cur;
    *pRowid = pCursor->rowId;
    return SQLITE_OK;
}

static int vInventoryEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vInventory_cursor*)cur;
    auto *pItemRepository = Utils::GetItemRepository(pCursor->oidCurrentTarget);
    if (!pItemRepository)
        return true;

    if (pCursor->oidCurrentTarget != pCursor->oidMainTarget)
    {
        if (pCursor->currentItemIndex >= pItemRepository->m_oidItems.Count())
        {
            pCursor->oidCurrentTarget = pCursor->oidMainTarget;
            pCursor->currentItemIndex = pCursor->mainItemIndex;
            pItemRepository = Utils::GetItemRepository(pCursor->oidCurrentTarget);

            if (!pItemRepository)
                return true;
        }
    }

    return pCursor->currentItemIndex >= pItemRepository->m_oidItems.Count();
}

static int vInventoryFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxStr;
    auto *pCursor = (vInventory_cursor*)cur;
    pCursor->oidMainTarget = Constants::OBJECT_INVALID;
    pCursor->oidCurrentTarget = Constants::OBJECT_INVALID;
    pCursor->currentItemIndex = 0;
    pCursor->mainItemIndex = 0;
    pCursor->bCheckBags = false;

    if ((idxNum & 1) && argc >= 1)
    {
        if (sqlite3_value_type(argv[0]) == SQLITE_INTEGER)
        {
            ObjectID oidTarget = sqlite3_value_int(argv[0]);
            pCursor->oidMainTarget = oidTarget;
            pCursor->oidCurrentTarget = oidTarget;
        }
        else if (sqlite3_value_type(argv[0]) == SQLITE_TEXT)
        {
            ObjectID oidTarget = Utils::StringToObjectID((const char*)sqlite3_value_text(argv[0]));
            pCursor->oidMainTarget = oidTarget;
            pCursor->oidCurrentTarget = oidTarget;
        }
        else
        {
            vInventorySetErrmsg(pCursor, "InventoryVirtualTable: Invalid Target Parameter Specified!");
            return SQLITE_ERROR;
        }
    }
    else
    {
        vInventorySetErrmsg(pCursor, "InventoryVirtualTable: No Target Specified!");
        return SQLITE_ERROR;
    }

    if ((idxNum & 2) && argc >= 2)
    {
        if (sqlite3_value_type(argv[1]) == SQLITE_INTEGER)
            pCursor->bCheckBags = !!sqlite3_value_int(argv[1]);
    }

    auto *pItemRepository = Utils::GetItemRepository(pCursor->oidCurrentTarget);
    if (!pItemRepository)
    {
        vInventorySetErrmsg(pCursor, "InventoryVirtualTable: Invalid Target Specified! ObjectID = %s", Utils::ObjectIDToString(pCursor->oidCurrentTarget).c_str());
        return SQLITE_ERROR;
    }

    return SQLITE_OK;
}

static int vInventoryBestIndex(sqlite3_vtab*, sqlite3_index_info *pIndexInfo)
{
    int nTargetInventoryConstraintIndex = -1;
    int nCheckBagsConstraintIndex = -1;
    for (int i = 0; i < pIndexInfo->nConstraint; i++)
    {
        auto constraint = pIndexInfo->aConstraint[i];
        if (constraint.iColumn == InventoryColumns::TargetObjectID)
        {
            if (constraint.usable)
                nTargetInventoryConstraintIndex = i;
        }

        if (constraint.iColumn == InventoryColumns::CheckContainers)
        {
            if (constraint.usable)
                nCheckBagsConstraintIndex = i;
        }
    }

    if (nTargetInventoryConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 1;
        pIndexInfo->aConstraintUsage[nTargetInventoryConstraintIndex].argvIndex = 1;
        pIndexInfo->aConstraintUsage[nTargetInventoryConstraintIndex].omit = true;

    }

    if (nCheckBagsConstraintIndex != -1)
    {
        pIndexInfo->idxNum |= 2;
        pIndexInfo->aConstraintUsage[nCheckBagsConstraintIndex].argvIndex = 2;
        pIndexInfo->aConstraintUsage[nCheckBagsConstraintIndex].omit = true;
    }

    return SQLITE_OK;
}

static int SetupInventoryVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module vInventoryModule =
    {
        0,
        nullptr,
        vInventoryConnect,
        vInventoryBestIndex,
        vInventoryDisconnect,
        nullptr,
        vInventoryOpen,
        vInventoryClose,
        vInventoryFilter,
        vInventoryNext,
        vInventoryEOF,
        vInventoryColumn,
        vInventoryRowid,
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

    return sqlite3_create_module_v2(db, "inventory", &vInventoryModule, nullptr, nullptr);
}
