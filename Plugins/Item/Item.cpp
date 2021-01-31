#include "nwnx.hpp"

#include <sstream>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Item {

CNWSItem *item(ArgumentStack& args)
{
    const auto objectId = args.extract<ObjectID>();

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Item function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pGameObject = Utils::GetGameObject(objectId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
    if (!pItem)
        LOG_NOTICE("NWNX_Item function called on non item object");

    return pItem;
}


NWNX_EXPORT ArgumentStack SetWeight(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        pItem->m_nWeight = args.extract<int32_t>();

        if (auto pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pItem->m_oidPossessor)))
            pCreature->UpdateEncumbranceState(true);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetBaseGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        pItem->m_nBaseUnitCost = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack SetAddGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        pItem->m_nAdditionalCost = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetBaseGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        return pItem->m_nBaseUnitCost;

    return -1;
}

NWNX_EXPORT ArgumentStack GetAddGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        return pItem->m_nAdditionalCost;

    return -1;
}

NWNX_EXPORT ArgumentStack SetBaseItemType(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        pItem->m_nBaseItem = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack SetItemAppearance(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto type  = args.extract<int32_t>();
        const auto idx   = args.extract<int32_t>();
        const auto val   = args.extract<int32_t>();

        switch(type)
        {
            case Constants::ItemAppearanceType::SimpleModel:
                if (val > 0)
                {
                    pItem->m_nModelPart[0] = val;
                }
                break;
            case Constants::ItemAppearanceType::WeaponColor:
                if (val >= 0 && val <= 255 && idx >= 0 && idx <= 5)
                {
                    pItem->m_nLayeredTextureColors[idx] = val;
                }
                break;
            case Constants::ItemAppearanceType::WeaponModel:
                if (val >= 0 && idx >= 0 && idx <= 2)
                {
                    pItem->m_nModelPart[idx] = val;
                }
                break;
            case Constants::ItemAppearanceType::ArmorModel:
                if (val >= 0 && idx >= 0 && idx <= 18)
                {
                    pItem->m_nArmorModelPart[idx] = val;
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
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetEntireItemAppearance(ArgumentStack&& args)
{
    std::stringstream retval;
    char buf[4];

    if (auto *pItem = item(args))
    {
        for (int idx = 0; idx < 6; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nLayeredTextureColors[idx]);
            retval << buf;
        }

        for (int idx = 0; idx < 3; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nModelPart[idx]);
            retval << buf;
        }
        for (int idx = 0; idx < 19; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nArmorModelPart[idx]);
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
    if (auto *pItem = item(args))
    {
        const auto sAppString = args.extract<std::string>();
        int  stringPos = 0;
        int  strLength = sAppString.length();


        if (strLength == 2*142 || strLength == 2*28)
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
            if (strLength == 2*142)
            {
                for (uint8_t texture = 0; texture < 6; texture++)
                {
                    for (uint8_t part = 0; part < 19; part++)
                    {
                        pItem->SetLayeredTextureColorPerPart(texture, part, std::stoul(sAppString.substr(stringPos,2), nullptr, 16));
                        stringPos += 2;
                    }
                }
            }
        }
    }
    else
    {
        LOG_NOTICE("RestoreItemAppearance: invalid string length, must be 284");
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetBaseArmorClass(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        return pItem->m_nArmorValue;

    return -1;
}

NWNX_EXPORT ArgumentStack GetMinEquipLevel(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
        return pItem->GetMinEquipLevel();

    return -1;
}


}
