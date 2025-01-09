#include "nwnx.hpp"

#include <sstream>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CItemRepository.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSInventory.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bMinEquipLevelHooksInitialized = false;

NWNX_EXPORT ArgumentStack SetWeight(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
    {
        pItem->m_nWeight = args.extract<int32_t>();

        if (auto pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pItem->m_oidPossessor)))
            pCreature->UpdateEncumbranceState(true);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetBaseGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        pItem->m_nBaseUnitCost = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack SetAddGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        pItem->m_nAdditionalCost = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetBaseGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        return (int32_t)pItem->m_nBaseUnitCost;

    return -1;
}

NWNX_EXPORT ArgumentStack GetAddGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        return pItem->m_nAdditionalCost;

    return -1;
}

NWNX_EXPORT ArgumentStack SetBaseItemType(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        pItem->m_nBaseItem = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack SetItemAppearance(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
    {
        const auto type  = args.extract<int32_t>();
        const auto idx   = args.extract<int32_t>();
        const auto val   = args.extract<int32_t>();
        const auto bUpdateCreatureAppearance = !!args.extract<int32_t>();

        switch(type)
        {
            case Constants::ItemAppearanceType::SimpleModel:
                if (val > 0)
                {
                    pItem->m_nModelPart[0] = val;
                }
                break;
            case Constants::ItemAppearanceType::WeaponColor:
                if (val >= 1 && val <= 9 && idx >= 0 && idx <= 2)
                {
                    uint16_t nTemp = pItem->m_nModelPart[idx];
                    nTemp = nTemp - (nTemp % 10) + val;
                    pItem->m_nModelPart[idx] = nTemp;
                }
                break;
            case Constants::ItemAppearanceType::WeaponModel:
                if (val >= 0 && idx >= 0 && idx <= 2)
                {
                    uint16_t nTemp = pItem->m_nModelPart[idx];
                    nTemp = (nTemp % 10) + (val * 10);
                    pItem->m_nModelPart[idx] = nTemp;
                }
                break;
            case Constants::ItemAppearanceType::ArmorModel:
                if (val >= 0 && idx >= 0 && idx <= 18)
                {
                    pItem->m_nArmorModelPart[idx] = val;
                    pItem->m_nArmorValue = pItem->ComputeArmorClass();
                    pItem->ComputeWeight();
                }
                break;
            case Constants::ItemAppearanceType::ArmorColor:
                if (val >= 0 && val <= 255 && idx >= 0 && idx <= 119)
                {
                    if (idx <= 5) //1.69 colors
                    {
                        pItem->m_nLayeredTextureColors[idx]=val;
                    }
                    else //per-part coloring
                    {
                        char part = (char)((idx-6)/6);
                        char texture = (char)(idx-6-part*6);
                        pItem->SetLayeredTextureColorPerPart(texture, part, val);
                    }
                }
                break;
        }

        if (auto *pPossessor= Utils::AsNWSCreature(Utils::GetGameObject(pItem->m_oidPossessor)))
        {
            if (!bUpdateCreatureAppearance || !pPossessor->m_pInventory->GetItemInInventory(pItem))
                return {};
            uint32_t nSlot = pPossessor->m_pInventory->GetSlotFromItem(pItem);
            if (nSlot != Constants::EquipmentSlot::Head && nSlot != Constants::EquipmentSlot::Chest && nSlot != Constants::EquipmentSlot::Cloak)
                return {};

            auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
            for (auto *pPlayer : Globals::AppManager()->m_pServerExoApp->GetPlayerList())
            {
                if (auto *pLUO = pPlayer->GetLastUpdateObject(pPossessor->m_idSelf))
                {
#define UPDATE_ITEM_APPEARANCE(oid)                                                                 \
                    if (oid == pItem->m_idSelf) {                                                   \
                        oid = Constants::OBJECT_INVALID;                                            \
                        pMessage->SendServerPlayerItemUpdate_DestroyItem(pPlayer, pItem->m_idSelf); \
                    }

                    UPDATE_ITEM_APPEARANCE(pLUO->m_cAppearance.m_oidHeadItem)
                    UPDATE_ITEM_APPEARANCE(pLUO->m_cAppearance.m_oidChestItem)
                    UPDATE_ITEM_APPEARANCE(pLUO->m_cAppearance.m_oidCloakItem)
#undef UPDATE_ITEM_APPEARANCE
                }
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetEntireItemAppearance(ArgumentStack&& args)
{
    std::stringstream retval;
    char buf[5];

    if (auto *pItem = Utils::PopItem(args))
    {
        for (int idx = 0; idx < 6; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nLayeredTextureColors[idx]);
            retval << buf;
        }

        for (int idx = 0; idx < 3; idx++)
        {
            sprintf(buf, "%04X", pItem->m_nModelPart[idx]);
            retval << buf;
        }
        for (int idx = 0; idx < 19; idx++)
        {
            sprintf(buf, "%04X", pItem->m_nArmorModelPart[idx]);
            retval << buf;
        }
        for (uint8_t texture = 0; texture < 6; texture++)
        {
            for (uint8_t part = 0; part < 19; part++)
            {
                sprintf(buf, "%02X", pItem->GetLayeredTextureColorPerPart(texture, part));
                retval << buf;
            }
        }
    }

    return retval.str();
}

NWNX_EXPORT ArgumentStack RestoreItemAppearance(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
    {
        const auto sAppString = args.extract<std::string>();
        const auto strLength = sAppString.length();
        size_t stringPos = 0;

        switch (strLength)
        {
            case 56:// No .35 extended model parts, no layered colors.
            {
                for (int idx = 0; idx < 6; idx++)
                {
                    pItem->m_nLayeredTextureColors[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (int idx = 0; idx < 3; idx++)
                {
                    pItem->m_nModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (int idx = 0; idx < 19; idx++)
                {
                    pItem->m_nArmorModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                break;
            }

            case 284: // No .35+ Extended Modelparts
            {
                for (int idx = 0; idx < 6; idx++)
                {
                    pItem->m_nLayeredTextureColors[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (int idx = 0; idx < 3; idx++)
                {
                    pItem->m_nModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (int idx = 0; idx < 19; idx++)
                {
                    pItem->m_nArmorModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (uint8_t texture = 0; texture < 6; texture++)
                {
                    for (uint8_t part = 0; part < 19; part++)
                    {
                        pItem->SetLayeredTextureColorPerPart(texture, part, std::stoul(sAppString.substr(stringPos,2), nullptr, 16));
                        stringPos += 2;
                    }
                }
                break;
            }

            case 328:// .35+ Extended Model Parts
            {
                for (int idx = 0; idx < 6; idx++)
                {
                    pItem->m_nLayeredTextureColors[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                    stringPos += 2;
                }
                for (int idx = 0; idx < 3; idx++)
                {
                    pItem->m_nModelPart[idx] = std::stoul(sAppString.substr(stringPos,4), nullptr, 16);
                    stringPos += 4;
                }
                for (int idx = 0; idx < 19; idx++)
                {
                    pItem->m_nArmorModelPart[idx] = std::stoul(sAppString.substr(stringPos,4), nullptr, 16);
                    stringPos += 4;
                }
                for (uint8_t texture = 0; texture < 6; texture++)
                {
                    for (uint8_t part = 0; part < 19; part++)
                    {
                        pItem->SetLayeredTextureColorPerPart(texture, part, std::stoul(sAppString.substr(stringPos,2), nullptr, 16));
                        stringPos += 2;
                    }
                }
                break;
            }
        }
        pItem->m_nArmorValue = pItem->ComputeArmorClass();
    }
    else
    {
        LOG_NOTICE("RestoreItemAppearance: invalid string length, must be 56 or 284 or 328");
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetBaseArmorClass(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        return pItem->m_nArmorValue;

    return -1;
}

NWNX_EXPORT ArgumentStack GetMinEquipLevel(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
        return pItem->GetMinEquipLevel();

    return -1;
}

CItemRepository* GetObjectItemRepository(OBJECT_ID oidPossessor)
{
    auto pPossessor = Utils::GetGameObject(oidPossessor);
    if (!pPossessor) return nullptr;

    switch (pPossessor->m_nObjectType)
    {
        case Constants::ObjectType::Creature:
            return Utils::AsNWSCreature(pPossessor)->m_pcItemRepository;
        case Constants::ObjectType::Placeable:
            return Utils::AsNWSPlaceable(pPossessor)->m_pcItemRepository;
        case Constants::ObjectType::Item:
            return Utils::AsNWSItem(pPossessor)->m_pItemRepository;
    }

    return nullptr;
}

NWNX_EXPORT ArgumentStack MoveTo(ArgumentStack&& args)
{
    if (auto *pItem = Utils::PopItem(args))
    {
        if (auto *pTarget = Utils::PopObject(args))
        {
            auto bHideAllFeedback = !!args.extract<int32_t>();

            auto oidRealItemPossessor = pItem->m_oidPossessor;
            if (pItem->m_oidPossessor != Constants::OBJECT_INVALID) // Item on the ground
            {
                auto pPossessor = Utils::GetGameObject(pItem->m_oidPossessor);
                oidRealItemPossessor = (pPossessor->m_nObjectType == Constants::ObjectType::Item) ? Utils::AsNWSItem(pPossessor)->m_oidPossessor : pPossessor->m_idSelf;
            }
            auto oidRealTargetPossessor = (pTarget->m_nObjectType == Constants::ObjectType::Item) ? Utils::AsNWSItem(pTarget)->m_oidPossessor : pTarget->m_idSelf;

            // Is the item already on/in the target?
            if (oidRealItemPossessor == oidRealTargetPossessor)
            {
                auto pTargetItemRepo = GetObjectItemRepository(pTarget->m_idSelf);
                if ((pTargetItemRepo) && (pTargetItemRepo->GetItemInRepository(pItem)))
                {
                    LOG_DEBUG("NWNX_Item_MoveTo: Item is already on the target!");
                    return true;
                }
            }

            auto bSendFeedback = (!bHideAllFeedback) && (oidRealItemPossessor != oidRealTargetPossessor); // Only send feeback if the item actually changed its owner
            switch (pTarget->m_nObjectType)
            {
                // Target is a creature
                case Constants::ObjectType::Creature:
                {
                    auto pTargetCreature = Utils::AsNWSCreature(pTarget);

                    uint8_t x, y;
                    if (!pTargetCreature->m_pcItemRepository->FindPosition(pItem, x, y))
                    {
                        LOG_DEBUG("NWNX_Item_MoveTo: Item does not fit in target creature!");
                        return false;
                    }

                    pTargetCreature->AcquireItem(&pItem, pItem->m_oidPossessor, Constants::OBJECT_INVALID, 0xFF, 0xFF, false, bSendFeedback);
                    break;
                }

                // Target is a placeable
                case Constants::ObjectType::Placeable:
                {
                    auto pTargetPlaceable = Utils::AsNWSPlaceable(pTarget);

                    uint8_t x, y;
                    if  ((pTargetPlaceable->m_pcItemRepository->m_nHeight >= 125 /* 25 maximum pages x 5 rows per page */) &&
                         (!pTargetPlaceable->m_pcItemRepository->FindPosition(pItem, x, y)))
                    {
                        LOG_DEBUG("NWNX_Item_MoveTo: Item does not fit in target placeable!");
                        return false;
                    }

                    pTargetPlaceable->AcquireItem(&pItem, pItem->m_oidPossessor, 0xFF, 0xFF, bSendFeedback);
                    break;
                }

                // Target is a store
                case Constants::ObjectType::Store:
                {
                    auto pTargetStore = Utils::AsNWSStore(pTarget);
                    auto pOriginalOwnerRepository = GetObjectItemRepository(pItem->m_oidPossessor);

                    pTargetStore->AcquireItem(pItem, false, 0xFF, 0xFF);

                    // CNWSStore::AcquireItem doesn't remove the source item
                    if (pOriginalOwnerRepository)
                        pOriginalOwnerRepository->RemoveItem(pItem);
                    else if (pItem->m_oidArea != Constants::OBJECT_INVALID)
                        pItem->RemoveFromArea();

                    break;
                }

                // Target is a container (bag)
                case Constants::ObjectType::Item:
                {
                    if (pItem->m_pItemRepository)
                    {
                        LOG_DEBUG("NWNX_Item_MoveTo: Can't put a container in a container!");
                        return false;
                    }

                    auto pTargetContainer = Utils::AsNWSItem(pTarget);
                    if (!pTargetContainer->m_pItemRepository)
                    {
                        LOG_DEBUG("NWNX_Item_MoveTo: Target item is not a container!");
                        return false;
                    }

                    uint8_t x, y;
                    if (!pTargetContainer->m_pItemRepository->FindPosition(pItem, x, y))
                    {
                        LOG_DEBUG("NWNX_Item_MoveTo: Item does not fit in target container!");

                        auto pOwnerCreature = Utils::AsNWSCreature(Utils::GetGameObject(oidRealTargetPossessor));
                        if (pOwnerCreature)
                        {
                            auto pMessageData = new CNWCCMessageData;
                            pMessageData->SetObjectID(0, pOwnerCreature->m_idSelf);
                            pOwnerCreature->SendFeedbackMessage(212/*FEEDBACK_CONTAINER_FULL*/, pMessageData);
                        }

                        return false;
                    }

                    pTargetContainer->AcquireItem(&pItem, pItem->m_oidPossessor, 0xFF, 0xFF, bSendFeedback);
                    break;
                }

                default:
                    LOG_ERROR("NWNX_Item_MoveTo: Invalid target object type!");
                    return false;
            }

            return true;
        }
    }

    return false;
}

static void InitItemEquipLevelHook()
{
    static Hooks::Hook pGetMinEquipLevel_hook =
        Hooks::HookFunction(&CNWSItem::GetMinEquipLevel, +[](CNWSItem *pThis) -> uint8_t
        {
            int32_t retVal;

            if (auto minEquipOvr = pThis->nwnxGet<int32_t>("MINIMUM_EQUIP_LEVEL_OVERRIDE"))
                retVal = minEquipOvr.value();
            else
                retVal = pGetMinEquipLevel_hook->CallOriginal<uint8_t>(pThis);

            if (auto minEquipMod = pThis->nwnxGet<int32_t>("MINIMUM_EQUIP_LEVEL_MODIFIER"))
                retVal = retVal + minEquipMod.value();

            return std::clamp<uint8_t>(retVal, 1, 255);
        }, Hooks::Order::Late);

    s_bMinEquipLevelHooksInitialized = true;
}

NWNX_EXPORT ArgumentStack SetMinEquipLevelModifier(ArgumentStack&& args)
{
    if (!s_bMinEquipLevelHooksInitialized)
        InitItemEquipLevelHook();

    if (auto* pItem = Utils::PopItem(args))
    {
        const auto modifier = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();

        if (modifier)
            pItem->nwnxSet("MINIMUM_EQUIP_LEVEL_MODIFIER", modifier, persist);
        else
            pItem->nwnxRemove("MINIMUM_EQUIP_LEVEL_MODIFIER");
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMinEquipLevelModifier(ArgumentStack&& args)
{
    if (auto* pItem = Utils::PopItem(args))
    {
        return pItem->nwnxGet<int32_t>("MINIMUM_EQUIP_LEVEL_MODIFIER").value_or(0);
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetMinEquipLevelOverride(ArgumentStack&& args)
{
    if (!s_bMinEquipLevelHooksInitialized)
        InitItemEquipLevelHook();

    if (auto* pItem = Utils::PopItem(args))
    {
        const auto modifier = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();

        if (modifier)
            pItem->nwnxSet("MINIMUM_EQUIP_LEVEL_OVERRIDE", modifier, persist);
        else
            pItem->nwnxRemove("MINIMUM_EQUIP_LEVEL_OVERRIDE");
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMinEquipLevelOverride(ArgumentStack&& args)
{
    if (auto* pItem = Utils::PopItem(args))
    {
        return pItem->nwnxGet<int32_t>("MINIMUM_EQUIP_LEVEL_OVERRIDE").value_or(0);
    }
    return 0;
}
