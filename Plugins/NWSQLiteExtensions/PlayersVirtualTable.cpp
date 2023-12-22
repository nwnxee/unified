#include "nwnx.hpp"
#include "API/Database.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_PlayersVirtualTableEnabled = false;
static int SetupPlayersVirtualTableModule(sqlite3 *db);

void PlayersVirtualTable() __attribute__((constructor));
void PlayersVirtualTable()
{
    if ((s_PlayersVirtualTableEnabled = Config::Get<bool>("ENABLE_PLAYERS_VIRTUAL_TABLE_MODULE", false)))
    {
        LOG_INFO("Enabling the Players Virtual Table Module for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                if (SetupPlayersVirtualTableModule(pThis->connection().get()) != SQLITE_OK)
                {
                    LOG_ERROR("Failed to setup the Players Virtual Table Module.");
                    s_PlayersVirtualTableEnabled = false;
                }
            }
        }, Hooks::Order::Early);
    }
}

typedef struct vPlayers_tab vPlayers_tab;
struct vPlayers_tab
{
    sqlite3_vtab base;
};

typedef struct vPlayers_cursor vPlayers_cursor;
struct vPlayers_cursor
{
    sqlite3_vtab_cursor base;
    uint32_t currentPlayerIndex;
};

namespace PlayersColumns
{
    enum TYPE
    {
        PCOID = 0,
        ControlledOID,
        DM,
        PlayerDM,
        Num, // Keep Last
    };
    constexpr int32_t MAX = 3;
    constexpr int32_t NUM = MAX + 1;
    static_assert(MAX == PlayerDM);
    static_assert(NUM == Num);

    constexpr const char* ToColumnWithType(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "oid_pc INTEGER",
            "oid_controlled INTEGER",
            "dm INTEGER",
            "player_dm INTEGER",
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

static int vPlayersConnect(sqlite3 *db, void *pAux, int argc, const char* const *argv, sqlite3_vtab **ppVtab, char **pzErr)
{
    (void)pAux; (void)argc; (void)argv; (void)pzErr;

    vPlayers_tab *pNewVtab = nullptr;
    int32_t ret = sqlite3_declare_vtab(db, PlayersColumns::GetSchema().CStr());
    if (ret == SQLITE_OK)
    {
        pNewVtab = static_cast<vPlayers_tab*>(sqlite3_malloc(sizeof(vPlayers_tab)));
        if (!pNewVtab)
            return SQLITE_NOMEM;

        memset(pNewVtab, 0, sizeof(vPlayers_tab));
        sqlite3_vtab_config(db, SQLITE_VTAB_DIRECTONLY);
    }

    *ppVtab = (sqlite3_vtab*)pNewVtab;
    return ret;
}

static int vPlayersDisconnect(sqlite3_vtab *pVtab)
{
    auto *p2daVtab = (vPlayers_tab*)pVtab;
    sqlite3_free(p2daVtab);
    return SQLITE_OK;
}

static int vPlayersOpen(sqlite3_vtab*, sqlite3_vtab_cursor **ppCursor)
{
    auto *pCursor = static_cast<vPlayers_cursor*>(sqlite3_malloc(sizeof(vPlayers_cursor)));
    if(!pCursor) return SQLITE_NOMEM;
    memset(pCursor, 0, sizeof(vPlayers_cursor));
    *ppCursor = &pCursor->base;
    return SQLITE_OK;
}

static int vPlayersClose(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vPlayers_cursor*)cur;
    sqlite3_free(pCursor);
    return SQLITE_OK;
}

static int vPlayersNext(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vPlayers_cursor*)cur;
    pCursor->currentPlayerIndex++;
    return SQLITE_OK;
}

static CNWSPlayer *vPlayersGetCurrentPlayer(uint32_t nCurrentPlayerIndex)
{
    auto *pServerExoAppInternal = g_pAppManager->m_pServerExoApp->m_pcExoAppInternal;
    auto *pPlayerList = pServerExoAppInternal->m_pNWSPlayerList;
    uint32_t nCount = 0;

    CExoLinkedListPosition pos = pPlayerList->GetHeadPos();
    while (pos)
    {
        if (auto *pPlayer = static_cast<CNWSPlayer*>(pPlayerList->GetAtPos(pos)))
        {
            if (pPlayer->m_oidPCObject != Constants::OBJECT_INVALID)
            {
                if (nCount == nCurrentPlayerIndex)
                    return pPlayer;
                nCount++;
            }
        }

        pPlayerList->GetNext(pos);
    }

    return nullptr;
}

static int vPlayersColumn(sqlite3_vtab_cursor *cur, sqlite3_context *ctx, int nColumn)
{
    auto *pCursor = (vPlayers_cursor*)cur;

    if (auto *pPlayer = vPlayersGetCurrentPlayer(pCursor->currentPlayerIndex))
    {
        switch (nColumn)
        {
            case PlayersColumns::PCOID:
            {
                sqlite3_result_int(ctx, pPlayer->m_oidPCObject);
                break;
            }

            case PlayersColumns::ControlledOID:
            {
                sqlite3_result_int(ctx, pPlayer->m_oidNWSObject);
                break;
            }

            case PlayersColumns::DM:
            {
                sqlite3_result_int(ctx, pPlayer->GetIsDM());
                break;
            }

            case PlayersColumns::PlayerDM:
            {
                sqlite3_result_int(ctx, pPlayer->GetIsPlayerDM());
                break;
            }

            default:
                LOG_WARNING("Forgot to implement a column?");
                break;
        }
    }

    return SQLITE_OK;
}

static int vPlayersRowid(sqlite3_vtab_cursor *cur, sqlite_int64 *pRowid)
{
    auto *pCursor = (vPlayers_cursor*)cur;
    *pRowid = pCursor->currentPlayerIndex;
    return SQLITE_OK;
}

static int vPlayersEOF(sqlite3_vtab_cursor *cur)
{
    auto *pCursor = (vPlayers_cursor*)cur;
    return !vPlayersGetCurrentPlayer(pCursor->currentPlayerIndex);
}

static int vPlayersFilter(sqlite3_vtab_cursor *cur, int idxNum, const char *idxStr, int argc, sqlite3_value **argv)
{
    (void)idxNum; (void)idxStr; (void)argc; (void)argv;
    auto *pCursor = (vPlayers_cursor*)cur;
    pCursor->currentPlayerIndex = 0;
    return SQLITE_OK;
}

static int vPlayersBestIndex(sqlite3_vtab*, sqlite3_index_info *)
{
    return SQLITE_OK;
}

static int SetupPlayersVirtualTableModule(sqlite3 *db)
{
    static sqlite3_module vPlayersModule =
    {
        0,
        nullptr,
        vPlayersConnect,
        vPlayersBestIndex,
        vPlayersDisconnect,
        nullptr,
        vPlayersOpen,
        vPlayersClose,
        vPlayersFilter,
        vPlayersNext,
        vPlayersEOF,
        vPlayersColumn,
        vPlayersRowid,
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

    return sqlite3_create_module_v2(db, "players", &vPlayersModule, nullptr, nullptr);
}
