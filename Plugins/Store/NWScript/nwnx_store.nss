/// @addtogroup store
/// @brief Functions exposing additional store properties.
/// @{
/// @file nwnx_store.nss

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
    NWNXPushInt(nBaseItem);
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "GetIsRestrictedBuyItem");
    return NWNXPopInt();
}

int NWNX_Store_GetBlackMarketMarkDown(object oStore)
{
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "GetBlackMarketMarkDown");
    return NWNXPopInt();
}

void NWNX_Store_SetBlackMarketMarkDown(object oStore, int nValue)
{
    NWNXPushInt(nValue);
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "SetBlackMarketMarkDown");
}

int NWNX_Store_GetMarkDown(object oStore)
{
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "GetMarkDown");
    return NWNXPopInt();
}

void NWNX_Store_SetMarkDown(object oStore, int nValue)
{
    NWNXPushInt(nValue);
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "SetMarkDown");
}

int NWNX_Store_GetMarkUp(object oStore)
{
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "GetMarkUp");
    return NWNXPopInt();
}

void NWNX_Store_SetMarkUp(object oStore, int nValue)
{
    NWNXPushInt(nValue);
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "SetMarkUp");
}

int NWNX_Store_GetCurrentCustomersCount(object oStore)
{
    NWNXPushObject(oStore);
    NWNXCall(NWNX_Store, "GetCurrentCustomersCount");
    return NWNXPopInt();
}
