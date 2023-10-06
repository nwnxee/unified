#include "nwnx.hpp"
#include "API/CNWSObject.hpp"
#include "API/Database.hpp"
#include <random>

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_DatabaseSetupHook = nullptr;
static void DatabaseSetupHook(NWSQLite::Database*);

static bool s_EnableMersenneTwisterFunctions = false;
static std::unordered_map<std::string, std::mt19937> s_MersenneTwisters;

void NWSQLiteExtensions() __attribute__((constructor));
void NWSQLiteExtensions()
{
    if (Config::Get<bool>("ENABLE_DATABASE_ON_ALL_OBJECT_TYPES", false))
    {
        LOG_INFO("All object types except areas can hold a sqlite database.");
        static Hooks::Hook s_GetObjectSqlDatabaseHook = Hooks::HookFunction(&CNWSObject::GetObjectSqlDatabase,
        +[](CNWSObject *pThis) -> std::shared_ptr<NWSQLite::Database>
        {
            if (!pThis->m_sqlite_db)
                pThis->m_sqlite_db = std::make_shared<NWSQLite::Database>(CExoString::F("Object(%x[%u],tag=%s)", pThis->m_idSelf,
                                                                                        pThis->m_nObjectType, pThis->m_sTag.CStr()), "");

            return pThis->m_sqlite_db;
        }, Hooks::Order::Final);
    }

    if ((s_EnableMersenneTwisterFunctions = Config::Get<bool>("ENABLE_MERSENNE_TWISTER_FUNCTIONS", false)))
        LOG_INFO("Enabling SQLite Mersenne Twister functions.");

    if (s_EnableMersenneTwisterFunctions)
    {
        s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup, &DatabaseSetupHook, Hooks::Order::Early);
    }
}

static void DatabaseSetupHook(NWSQLite::Database *pThis)
{
    s_DatabaseSetupHook->CallOriginal<void>(pThis);

    if (s_EnableMersenneTwisterFunctions)
    {
        pThis->define("mt_seed",
            [](const std::string &sName, int32_t nSeed) -> bool
            {
                if (sName.empty()) return false;
                s_MersenneTwisters[sName].seed(std::abs(nSeed));
                return true;
            }
        );
        pThis->define("mt_value",
            [](const std::string &sName) -> sqlite3_int64
            {
                if (sName.empty()) return -1;
                return (sqlite3_int64)s_MersenneTwisters[sName]();
            }
        );
        pThis->define("mt_discard",
            [](const std::string &sName, int32_t nDiscard) -> bool
            {
                if (sName.empty()) return false;
                s_MersenneTwisters[sName].discard(std::abs(nDiscard));
                return true;
            }
        );
    }
}
