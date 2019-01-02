#include "Area.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"
#include "Serialize.hpp"
#include "Utils.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Area::Area> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Area",
        "Functions exposing additional area properties",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Area::Area(params);
    return g_plugin;
}


namespace Area {

Area::Area(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Area::func, this, std::placeholders::_1))

    REGISTER(GetNumberOfPlayersInArea);
    REGISTER(GetLastEntered);
    REGISTER(GetLastLeft);
    REGISTER(GetPVPSetting);
    REGISTER(SetPVPSetting);
    REGISTER(GetAreaSpotModifier);
    REGISTER(SetAreaSpotModifier);
    REGISTER(GetAreaListenModifier);
    REGISTER(SetAreaListenModifier);
    REGISTER(GetNoRestingAllowed);
    REGISTER(SetNoRestingAllowed);
    REGISTER(GetWindPower);
    REGISTER(SetWindPower);
    REGISTER(GetWeatherChance);
    REGISTER(SetWeatherChance);    

#undef REGISTER
}

Area::~Area()
{
}

CNWSArea *Area::area(ArgumentStack& args)
{
    const auto areaId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (areaId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Area function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaId);

    if (!pArea)
    {
        LOG_NOTICE("NWNX_Area function called on non-area object %x", areaId);
    }

    return pArea;
}

ArgumentStack Area::GetNumberOfPlayersInArea(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nPlayersInArea;
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::GetLastEntered(ArgumentStack&& args)
{
    ArgumentStack stack;
    Types::ObjectID retVal = Constants::OBJECT_INVALID;
    
    if (auto *pArea = area(args))
    {
        retVal = static_cast<Types::ObjectID>(pArea->m_oidLastEntered);
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::GetLastLeft(ArgumentStack&& args)
{
    ArgumentStack stack;
    Types::ObjectID retVal = Constants::OBJECT_INVALID;
    
    if (auto *pArea = area(args))
    {
        retVal = static_cast<Types::ObjectID>(pArea->m_oidLastLeft);
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::GetPVPSetting(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nPVPSetting;
    }
    
    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::SetPVPSetting(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto pvpSetting = Services::Events::ExtractArgument<int32_t>(args);
        
        ASSERT(pvpSetting >= 0);
        ASSERT(pvpSetting <= 3);

        pArea->m_nPVPSetting = pvpSetting;
    }    

    return stack;
}

ArgumentStack Area::GetAreaSpotModifier(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaSpotModifier;
    }
    
    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::SetAreaSpotModifier(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto spotModifier = Services::Events::ExtractArgument<int32_t>(args);
        
        pArea->m_nAreaSpotModifier = spotModifier;
    }    

    return stack;
}

ArgumentStack Area::GetAreaListenModifier(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nAreaListenModifier;
    }
    
    Services::Events::InsertArgument(stack, retVal);
    
    return stack;
}

ArgumentStack Area::SetAreaListenModifier(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto listenModifier = Services::Events::ExtractArgument<int32_t>(args);
        
        pArea->m_nAreaListenModifier = listenModifier;
    }    

    return stack;
}

ArgumentStack Area::GetNoRestingAllowed(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_bNoRestingAllowed;
    }
    
    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::SetNoRestingAllowed(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto noRestingAllowed = Services::Events::ExtractArgument<int32_t>(args);
        
        ASSERT(noRestingAllowed >= 0);
        ASSERT(noRestingAllowed <= 1);

        pArea->m_bNoRestingAllowed = noRestingAllowed;
    }    

    return stack;
}

ArgumentStack Area::GetWindPower(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        retVal = pArea->m_nWindAmount;
    }
    
    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::SetWindPower(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto windPower = Services::Events::ExtractArgument<int32_t>(args);
        
        ASSERT(windPower >= 0);
        ASSERT(windPower <= 2);

        pArea->m_nWindAmount = windPower;
    }    

    return stack;
}

ArgumentStack Area::GetWeatherChance(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    
    if (auto *pArea = area(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT(type >= 0);
        ASSERT(type <= 2);

        switch (type)
        {
            case 0:
                retVal = pArea->m_nChanceOfRain;
                break;
            
            case 1:
                retVal = pArea->m_nChanceOfSnow;
                break;

            case 2:
                retVal = pArea->m_nChanceOfLightning;
                break;

            default:
                retVal = 0;
                break;
        }        
    }
    
    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Area::SetWeatherChance(ArgumentStack&& args)
{
    ArgumentStack stack;
    
    if (auto *pArea = area(args))
    {
        const auto type = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT(type >= 0);
        ASSERT(type <= 2);

        const auto chance = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT(chance >= 0);
        ASSERT(chance <= 100);        

        switch (type)
        {
            case 0:
                pArea->m_nChanceOfRain = chance;
                break;
            
            case 1:
                pArea->m_nChanceOfSnow = chance;
                break;

            case 2:
                pArea->m_nChanceOfLightning = chance;
                break;

            default:
                break;
        }
    }    

    return stack;
}

}
