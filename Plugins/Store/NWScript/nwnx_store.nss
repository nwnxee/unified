/// @addtogroup store
/// @brief Functions exposing additional store properties.
/// @{
/// @file nwnx_store.nss
#include "nwnx"

const string NWNX_Store = "NWNX_Store"; ///< @private

/// @brief Return status of a base item purchase status.
/// @param oStore The store object.
/// @param nBaseItem A BASE_ITEM_* value
/// @return TRUE if the quest has been completed. -1 if the player does not have the journal entry.
int NWNX_Store_GetIsRestrictedBuyItem(object oStore, int nBaseItem);

/// @brief Return the blackmarket mark down of a store
/// @param oStore The store object.
/// @return mark down of a store, -1 on error
int NWNX_Store_GetBlackMarketMarkDown(object oStore);

/// @brief Set the blackmarket mark down of a store
/// @param oStore The store object.
/// @param nValue The amount.
void NWNX_Store_SetBlackMarketMarkDown(object oStore, int nValue);

/// @brief Return the mark down of a store
/// @param oStore The store object.
/// @return mark down of a store, -1 on error
int NWNX_Store_GetMarkDown(object oStore);

/// @brief Set the mark down of a store
/// @param oStore The store object.
/// @param nValue The amount.
void NWNX_Store_SetMarkDown(object oStore, int nValue);

/// @brief Return the mark up of a store
/// @param oStore The store object.
/// @return mark up of a store, -1 on error
int NWNX_Store_GetMarkUp(object oStore);

/// @brief Set the mark up of a store
/// @param oStore The store object.
/// @param nValue The amount.
void NWNX_Store_SetMarkUp(object oStore, int nValue);

/// @brief Return current customer count
/// @param oStore The store object.
/// @return count, or -1 on error
int NWNX_Store_GetCurrentCustomersCount(object oStore);

/// @}

int NWNX_Store_GetIsRestrictedBuyItem(object oStore, int nBaseItem)
{
    string sFunc = "GetIsRestrictedBuyItem";

    NWNX_PushArgumentInt(nBaseItem);
    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
    return NWNX_GetReturnValueInt();
}

int NWNX_Store_GetBlackMarketMarkDown(object oStore)
{
    string sFunc = "GetBlackMarketMarkDown";

    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Store_SetBlackMarketMarkDown(object oStore, int nValue)
{
    string sFunc = "SetBlackMarketMarkDown";

    NWNX_PushArgumentInt(nValue);
    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
}

int NWNX_Store_GetMarkDown(object oStore)
{
    string sFunc = "GetMarkDown";

    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Store_SetMarkDown(object oStore, int nValue)
{
    string sFunc = "SetMarkDown";

    NWNX_PushArgumentInt(nValue);
    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
}

int NWNX_Store_GetMarkUp(object oStore)
{
    string sFunc = "GetMarkUp";

    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
    return NWNX_GetReturnValueInt();
}

void NWNX_Store_SetMarkUp(object oStore, int nValue)
{
    string sFunc = "SetMarkUp";

    NWNX_PushArgumentInt(nValue);
    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
}

int NWNX_Store_GetCurrentCustomerCount(object oStore)
{
    string sFunc = "GetCurrentCustomerCount";

    NWNX_PushArgumentObject(oStore);

    NWNX_CallFunction(NWNX_Store, sFunc);
    return NWNX_GetReturnValueInt();
}
