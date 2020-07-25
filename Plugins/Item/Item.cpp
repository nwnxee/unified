#include "Item.hpp"

#include <sstream>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Item::Item* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Item::Item(services);
    return g_plugin;
}


namespace Item {

Item::Item(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetWeight);
    REGISTER(SetBaseGoldPieceValue);
    REGISTER(SetAddGoldPieceValue);
    REGISTER(GetBaseGoldPieceValue);
    REGISTER(GetAddGoldPieceValue);
    REGISTER(SetBaseItemType);
    REGISTER(SetItemAppearance);
    REGISTER(GetEntireItemAppearance);
    REGISTER(RestoreItemAppearance);
    REGISTER(GetBaseArmorClass);
    REGISTER(GetMinEquipLevel);

#undef REGISTER
}

Item::~Item()
{
}

CNWSItem *Item::item(ArgumentStack& args)
{
    const auto objectId = Services::Events::ExtractArgument<ObjectID>(args);

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Item function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
    if (!pItem)
        LOG_NOTICE("NWNX_Item function called on non item object");

    return pItem;
}


ArgumentStack Item::SetWeight(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto w = Services::Events::ExtractArgument<int32_t>(args);
        pItem->m_nWeight = w;
        auto oidPossessor = pItem->m_oidPossessor;
        auto pCreature = Utils::AsNWSCreature(Globals::AppManager()->m_pServerExoApp->GetGameObject(oidPossessor));
        if (pCreature)
        {
            pCreature->UpdateEncumbranceState(true);
        }
    }
    return Services::Events::Arguments();
}

ArgumentStack Item::SetBaseGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto g = Services::Events::ExtractArgument<int32_t>(args);
        pItem->m_nBaseUnitCost = g;
    }
    return Services::Events::Arguments();
}

ArgumentStack Item::SetAddGoldPieceValue(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto g = Services::Events::ExtractArgument<int32_t>(args);
        pItem->m_nAdditionalCost = g;
    }
    return Services::Events::Arguments();
}

ArgumentStack Item::GetBaseGoldPieceValue(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pItem = item(args))
    {
        retval = pItem->m_nBaseUnitCost;
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Item::GetAddGoldPieceValue(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pItem = item(args))
    {
        retval = pItem->m_nAdditionalCost;
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Item::SetBaseItemType(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto bt = Services::Events::ExtractArgument<int32_t>(args);
        pItem->m_nBaseItem = bt;
    }
    return Services::Events::Arguments();
}

ArgumentStack Item::SetItemAppearance(ArgumentStack&& args)
{
    if (auto *pItem = item(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);
        const auto idx   = Services::Events::ExtractArgument<int32_t>(args);
        const auto val   = Services::Events::ExtractArgument<int32_t>(args);

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
    return Services::Events::Arguments();
}

ArgumentStack Item::GetEntireItemAppearance(ArgumentStack&& args)
{
    std::stringstream retval;
    char buf[4];
    int idx;
    char part, texture;


    if (auto *pItem = item(args))
    {
        for (idx = 0; idx < 6; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nLayeredTextureColors[idx]);
            retval << buf;
        }

        for (idx = 0; idx < 3; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nModelPart[idx]);
            retval << buf;
        }
        for (idx = 0; idx < 19; idx++)
        {
            sprintf(buf, "%02X", pItem->m_nArmorModelPart[idx]);
            retval << buf;
        }
        for (texture=0; texture<6; texture++)
        {
            for (part=0; part<19; part++)
            {
                sprintf(buf, "%02X", pItem->GetLayeredTextureColorPerPart(texture, part));
                retval << buf;
            }
        }
    }

    return Services::Events::Arguments(retval.str());
}

ArgumentStack Item::RestoreItemAppearance(ArgumentStack&& args)
{

    if (auto *pItem = item(args))
    {
        const auto sAppString = Services::Events::ExtractArgument<std::string>(args);
        int  idx;
        int  stringPos=0;
        char texture, part;
        int  strLength = sAppString.length();


        if (strLength == 2*142 || strLength == 2*28)
        {
            for (idx = 0; idx < 6; idx++)
            {
                pItem->m_nLayeredTextureColors[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                stringPos+=2;
            }

            for (idx = 0; idx < 3; idx++)
            {
                pItem->m_nModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                stringPos += 2;
            }
            for (idx = 0; idx < 19; idx++)
            {
                pItem->m_nArmorModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
                stringPos += 2;
            }
            if (strLength == 2*142)
            {
                for (texture = 0; texture < 6; texture++)
                {
                    for (part = 0; part < 19; part++)
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
    return Services::Events::Arguments();
}

ArgumentStack Item::GetBaseArmorClass(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pItem = item(args))
    {
        retval = pItem->m_nArmorValue;
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Item::GetMinEquipLevel(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pItem = item(args))
    {
        retval = pItem->GetMinEquipLevel();
    }
    return Services::Events::Arguments(retval);
}


}
