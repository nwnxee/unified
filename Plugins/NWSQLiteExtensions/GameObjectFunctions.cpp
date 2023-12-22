#include "nwnx.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWVisibilityNode.hpp"
#include "API/Database.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static void SetupGameObjectFunctionsHook(NWSQLite::Database*);
static bool s_EnableGameObjectFunctions = false;

void GameObjectFunctions() __attribute__((constructor));
void GameObjectFunctions()
{
    if ((s_EnableGameObjectFunctions = Config::Get<bool>("ENABLE_GAMEOBJECT_FUNCTIONS", false)))
    {
        LOG_INFO("Enabling SQLite GameObject functions for the module database.");
        static Hooks::Hook s_DatabaseSetupHook = Hooks::HookFunction(&NWSQLite::Database::Setup,
        +[](NWSQLite::Database *pThis) -> void
        {
            s_DatabaseSetupHook->CallOriginal<void>(pThis);

            if (strcmp(pThis->m_label.c_str(), "Module()") == 0)
            {
                SetupGameObjectFunctionsHook(pThis);
            }
        }, Hooks::Order::Early);
    }
}

static ObjectID GetObjectIDFromSqliteValue(sqlite3_value *arg)
{
    ObjectID oid = Constants::OBJECT_INVALID;
    if (sqlite3_value_type(arg) == SQLITE_INTEGER)
        oid = sqlite3_value_int(arg);
    else if (sqlite3_value_type(arg) == SQLITE_TEXT)
        oid = Utils::StringToObjectID((const char*)sqlite3_value_text(arg));
    return oid;
}

static void SetupGameObjectFunctionsHook(NWSQLite::Database *pThis)
{
#define NWNX_SQLITE_FUNCTION(name, num_args, body)                                                                                      \
    sqlite3_create_function(pThis->connection().get(), name, num_args, SQLITE_UTF8 | SQLITE_DETERMINISTIC | SQLITE_DIRECTONLY, nullptr, \
    [](sqlite3_context *ctx, int argc, sqlite3_value **argv) -> void body, nullptr, nullptr);

#define NWNX_SQLITE_EXPOSE_INTEGER_INTERNAL(cast_type, name, func_or_variable)                                                          \
    NWNX_SQLITE_FUNCTION(name, 1,                                                                                                       \
    {                                                                                                                                   \
        (void)argc;                                                                                                                     \
        int32_t retVal = 0;                                                                                                             \
        if (auto *pObject = Utils::AsNWS##cast_type(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0]))))                         \
            retVal = pObject->func_or_variable;                                                                                         \
        sqlite3_result_int(ctx, retVal);                                                                                                \
    })
#define NWNX_SQLITE_EXPOSE_FLOAT_INTERNAL(cast_type, name, func_or_variable)                                                            \
    NWNX_SQLITE_FUNCTION(name, 1,                                                                                                       \
    {                                                                                                                                   \
        (void)argc;                                                                                                                     \
        float retVal = 0.0f;                                                                                                            \
        if (auto *pObject = Utils::AsNWS##cast_type(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0]))))                         \
            retVal = pObject->func_or_variable;                                                                                         \
        sqlite3_result_double(ctx, retVal);                                                                                             \
    })
#define NWNX_SQLITE_EXPOSE_STRING_INTERNAL(cast_type, name, func_or_variable)                                                           \
    NWNX_SQLITE_FUNCTION(name, 1,                                                                                                       \
    {                                                                                                                                   \
        (void)argc;                                                                                                                     \
        CExoString retVal;                                                                                                              \
        if (auto *pObject = Utils::AsNWS##cast_type(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0]))))                         \
            retVal = pObject->func_or_variable;                                                                                         \
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);                                                                  \
    })

#define NWNX_SQLITE_EXPOSE_INTEGER_OBJECT(name, func_or_variable)                                                                       \
    NWNX_SQLITE_EXPOSE_INTEGER_INTERNAL(Object, name, func_or_variable)
#define NWNX_SQLITE_EXPOSE_FLOAT_OBJECT(name, func_or_variable)                                                                         \
    NWNX_SQLITE_EXPOSE_FLOAT_INTERNAL(Object, name, func_or_variable)
#define NWNX_SQLITE_EXPOSE_INTEGER_ITEM(name, func_or_variable)                                                                         \
    NWNX_SQLITE_EXPOSE_INTEGER_INTERNAL(Item, name, func_or_variable)


    NWNX_SQLITE_EXPOSE_INTEGER_OBJECT("plot", m_bPlotObject)
    NWNX_SQLITE_EXPOSE_INTEGER_OBJECT("useable", m_bUseable)
    NWNX_SQLITE_EXPOSE_INTEGER_OBJECT("current_hit_points", GetCurrentHitPoints())
    NWNX_SQLITE_EXPOSE_INTEGER_OBJECT("max_hit_points", GetMaxHitPoints())
    NWNX_SQLITE_EXPOSE_INTEGER_OBJECT("dead", GetDead())
    NWNX_SQLITE_EXPOSE_FLOAT_OBJECT("pos_x", m_vPosition.x)
    NWNX_SQLITE_EXPOSE_FLOAT_OBJECT("pos_y", m_vPosition.y)
    NWNX_SQLITE_EXPOSE_FLOAT_OBJECT("pos_z", m_vPosition.z)

    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("stacksize", m_nStackSize)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("gold_value", GetCost())
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("weight", GetWeight())
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("identified", m_bIdentified)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("droppable", m_bDroppable)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("pickpocketable", m_bPickPocketable)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("cursed", m_bCursed)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("stolen", m_bStolen)
    NWNX_SQLITE_EXPOSE_INTEGER_ITEM("baseitem", m_nBaseItem)

    NWNX_SQLITE_FUNCTION("tag", 1,
    {
        (void)argc;
        CExoString retVal;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pObject = Utils::AsNWSObject(pGameObject))
                retVal = pObject->m_sTag;
            else if (auto *pArea = Utils::AsNWSArea(pGameObject))
                retVal = pArea->m_sTag;
            else if (auto *pModule = Utils::AsNWSModule(pGameObject))
                retVal = pModule->m_sTag;
        }
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);
    })
    NWNX_SQLITE_FUNCTION("resref", 1,
    {
        (void)argc;
        CExoString retVal;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pObject = Utils::AsNWSObject(pGameObject))
                retVal = pObject->m_sTemplate;
            else if (auto *pArea = Utils::AsNWSArea(pGameObject))
                retVal = pArea->m_cResRef;
        }
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);
    })
    NWNX_SQLITE_FUNCTION("name", -1,
    {
        CExoString retVal;
        if (argc >= 1)
        {
            float fSoundDuration;
            bool bOriginalName = false;
            if (argc >= 2 && sqlite3_value_type(argv[1]) == SQLITE_INTEGER)
                bOriginalName = !!sqlite3_value_int(argv[1]);

            if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
            {
                if (auto *pStore = Utils::AsNWSStore(pGameObject))
                {
                    static CExoLocString sTemp;
                    CNWSMessage::GetLocStringServer(0xFFFFFFFF, pStore->m_sName, sTemp, retVal, fSoundDuration);
                }
                else if (auto *pObject = Utils::AsNWSObject(pGameObject))
                {
                    if (!bOriginalName)
                    {
                        if (auto *pCreature = Utils::AsNWSCreature(pGameObject))
                        {
                            if (!pCreature->m_sDisplayName.IsEmpty())
                                retVal = pCreature->m_sDisplayName;
                        }
                        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pGameObject))
                        {
                            if (!pPlaceable->m_sDisplayName.IsEmpty())
                                retVal = pPlaceable->m_sDisplayName;
                        }
                        else if (auto *pItem = Utils::AsNWSItem(pGameObject))
                        {
                            if (!pItem->m_sDisplayName.IsEmpty())
                                retVal = pItem->m_sDisplayName;
                        }
                        else if (auto *pDoor = Utils::AsNWSDoor(pGameObject))
                        {
                            if (!pDoor->m_sDisplayName.IsEmpty())
                                retVal = pDoor->m_sDisplayName;
                        }
                    }

                    if (retVal.IsEmpty())
                    {
                        CNWSMessage::GetLocStringServer(0xFFFFFFFF, pObject->GetFirstName(), pObject->GetLastName(), retVal, fSoundDuration);
                    }
                }
                else if (auto *pArea = Utils::AsNWSArea(pGameObject))
                {
                    if (bOriginalName || pArea->m_sDisplayName.IsEmpty())
                        pArea->m_lsName.GetString(Globals::AppManager()->m_pServerExoApp->GetModuleLanguage(), &retVal);
                    else
                        retVal = pArea->m_sDisplayName;
                }
                else if (auto *pModule = Utils::AsNWSModule(pGameObject))
                {
                    pModule->m_lsModuleName.GetString(Globals::AppManager()->m_pServerExoApp->GetModuleLanguage(), &retVal);
                }
            }
        }
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);
    })
    NWNX_SQLITE_FUNCTION("uuid", 1,
    {
        (void)argc;
        CExoString retVal;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pObject = Utils::AsNWSObject(pGameObject))
                retVal = pObject->m_pUUID.m_uuid;
            else if (auto *pArea = Utils::AsNWSArea(pGameObject))
                retVal = pArea->m_pUUID.m_uuid;
        }
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);
    })

    NWNX_SQLITE_FUNCTION("area", 1,
    {
        (void)argc;
        ObjectID oidArea = Constants::OBJECT_INVALID;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pObject = Utils::AsNWSObject(pGameObject))
                oidArea = pObject->m_oidArea;
            else if (auto *pArea = Utils::AsNWSArea(pGameObject))
                oidArea = pArea->m_idSelf;
        }
        sqlite3_result_int(ctx, oidArea);
    })

    NWNX_SQLITE_FUNCTION("object_type", 1,
    {
        (void)argc;
        int32_t nObjectType = 0;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
            nObjectType = Utils::EngineObjectTypeToNWScriptObjectType(pGameObject->m_nObjectType);
        sqlite3_result_int(ctx, nObjectType);
    })

    NWNX_SQLITE_FUNCTION("local_int", 2,
    {
        (void)argc;
        int32_t retVal = 0;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pScriptVarTable = Utils::GetScriptVarTable(pGameObject))
            {
                CExoString sVarName = (const char*)sqlite3_value_text(argv[1]);
                retVal = pScriptVarTable->GetInt(sVarName);
            }
        }
        sqlite3_result_int(ctx, retVal);
    })
    NWNX_SQLITE_FUNCTION("local_string", 2,
    {
        (void)argc;
        CExoString retVal;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pScriptVarTable = Utils::GetScriptVarTable(pGameObject))
            {
                CExoString sVarName = (const char*)sqlite3_value_text(argv[1]);
                retVal = pScriptVarTable->GetString(sVarName);
            }
        }
        sqlite3_result_text(ctx, retVal.CStr(), -1, SQLITE_TRANSIENT);
    })
    NWNX_SQLITE_FUNCTION("local_float", 2,
    {
        (void)argc;
        float retVal = 0.0f;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pScriptVarTable = Utils::GetScriptVarTable(pGameObject))
            {
                CExoString sVarName = (const char*)sqlite3_value_text(argv[1]);
                retVal = pScriptVarTable->GetFloat(sVarName);
            }
        }
        sqlite3_result_double(ctx, retVal);
    })
    NWNX_SQLITE_FUNCTION("local_object", 2,
    {
        (void)argc;
        ObjectID retVal = Constants::OBJECT_INVALID;
        if (auto *pGameObject = Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])))
        {
            if (auto *pScriptVarTable = Utils::GetScriptVarTable(pGameObject))
            {
                CExoString sVarName = (const char*)sqlite3_value_text(argv[1]);
                retVal = pScriptVarTable->GetObject(sVarName);
            }
        }
        sqlite3_result_int(ctx, retVal);
    })

    NWNX_SQLITE_FUNCTION("int_to_hex_string", 1,
    {
        (void)argc;
        ObjectID oid = 0;
        if (sqlite3_value_type(argv[0]) == SQLITE_INTEGER)
            oid = sqlite3_value_int(argv[0]);
        sqlite3_result_text(ctx, Utils::ObjectIDToString(oid).c_str(), -1, SQLITE_TRANSIENT);
    })

    NWNX_SQLITE_FUNCTION("hex_string_to_int", 1,
    {
        (void)argc;
        std::string oid;
        if (sqlite3_value_type(argv[0]) == SQLITE_TEXT)
            oid = (const char*)sqlite3_value_text(argv[0]);
        sqlite3_result_int(ctx, Utils::StringToObjectID(oid));
    })

    NWNX_SQLITE_FUNCTION("has_inventory", 1,
    {
        (void)argc;
        sqlite3_result_int(ctx, Utils::GetItemRepository(GetObjectIDFromSqliteValue(argv[0])) != nullptr);
    })

    NWNX_SQLITE_FUNCTION("in_range", 3,
    {
        (void)argc;
        bool retVal = false;
        CNWSObject *pObject1 = Utils::AsNWSObject(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])));
        CNWSObject *pObject2 = Utils::AsNWSObject(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[1])));
        double fDistance = sqlite3_value_double(argv[2]);
        if (pObject1 && pObject2 && pObject1->m_oidArea == pObject2->m_oidArea && fDistance >= 0.0)
            retVal = Vector::MagnitudeSquared(pObject1->m_vPosition - pObject2->m_vPosition) <= (fDistance * fDistance);
        sqlite3_result_int(ctx, retVal);
    })

    NWNX_SQLITE_FUNCTION("distance_between", 2,
    {
        (void)argc;
        CNWSObject *pSource = Utils::AsNWSObject(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])));
        CNWSObject *pTarget = Utils::AsNWSObject(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[1])));

        if (!pSource)
        {
            sqlite3_result_error(ctx, "distance_between: invalid source object.", -1);
            return;
        }
        if (!pTarget)
        {
            sqlite3_result_error(ctx, "distance_between: invalid target object.", -1);
            return;
        }
        if (pSource->m_oidArea != pTarget->m_oidArea)
        {
            sqlite3_result_error(ctx, "distance_between: source and target are in different areas.", -1);
            return;
        }
        sqlite3_result_double(ctx, Vector::Magnitude(pSource->m_vPosition - pTarget->m_vPosition));
    })

    NWNX_SQLITE_FUNCTION("perception_heard", 2,
    {
        (void)argc;
        CNWSCreature *pSource = Utils::AsNWSCreature(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])));
        CNWSCreature *pTarget = Utils::AsNWSCreature(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[1])));

        if (!pSource)
        {
            sqlite3_result_error(ctx, "perception_heard: invalid or non-creature source object.", -1);
            return;
        }
        if (!pTarget)
        {
            sqlite3_result_error(ctx, "perception_heard: invalid or non-creature target object.", -1);
            return;
        }
        if (pSource->m_oidArea != pTarget->m_oidArea)
        {
            sqlite3_result_error(ctx, "perception_heard: source and target are in different areas.", -1);
            return;
        }

        int32_t retVal = 0;
        if (auto *pNode = pSource->GetVisibleListElement(pTarget->m_idSelf))
            retVal = pNode->m_bHeard;
        sqlite3_result_int(ctx, retVal);
    })

    NWNX_SQLITE_FUNCTION("perception_seen", 2,
    {
        (void)argc;
        CNWSCreature *pSource = Utils::AsNWSCreature(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[0])));
        CNWSCreature *pTarget = Utils::AsNWSCreature(Utils::GetGameObject(GetObjectIDFromSqliteValue(argv[1])));

        if (!pSource)
        {
            sqlite3_result_error(ctx, "perception_seen: invalid or non-creature source object.", -1);
            return;
        }
        if (!pTarget)
        {
            sqlite3_result_error(ctx, "perception_seen: invalid or non-creature target object.", -1);
            return;
        }
        if (pSource->m_oidArea != pTarget->m_oidArea)
        {
            sqlite3_result_error(ctx, "perception_seen: source and target are in different areas.", -1);
            return;
        }

        int32_t retVal = 0;
        if (auto *pNode = pSource->GetVisibleListElement(pTarget->m_idSelf))
            retVal = pNode->m_bSeen;
        sqlite3_result_int(ctx, retVal);
    })
}
