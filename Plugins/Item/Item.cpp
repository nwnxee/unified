
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

#include "Item.hpp"

#include <sstream>
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Log/Log.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Item::Item> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
    {
      "Item",
	"Functions exposing additional item properties",
	"Various / sherincall / Bhaal",
	"marca.argentea at gmail.com",
	2,
	true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
  g_plugin = new Item::Item(params);
  return g_plugin;
}


namespace Item {
  
Item::Item(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)							\
  GetServices()->m_events->RegisterEvent(#func, std::bind(&Item::func, this, std::placeholders::_1))
  
  REGISTER(SetWeight);
  REGISTER(SetBaseGoldPieceValue);
  REGISTER(SetAddGoldPieceValue);
  REGISTER(GetBaseGoldPieceValue);
  REGISTER(GetAddGoldPieceValue);
  REGISTER(SetBaseItemType);
  REGISTER(SetItemAppearance);
  REGISTER(GetEntireItemAppearance);
  REGISTER(RestoreItemAppearance);
  
#undef REGISTER
}
  
Item::~Item()
{
}

CNWSItem *Item::item(ArgumentStack& args)
{
  const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);
  
  if (objectId == Constants::OBJECT_INVALID)
    {
      GetServices()->m_log->Notice("NWNX_Item function called on OBJECT_INVALID");
      return nullptr;
    }
  
  
  auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
  if(pGameObject==nullptr || pGameObject->m_nObjectType!=Constants::OBJECT_TYPE_ITEM)
    {
      GetServices()->m_log->Notice("NWNX_Item function called on non item object");
      return nullptr;	
    }
  
  return static_cast<CNWSItem*>(pGameObject);
}
  

ArgumentStack Item::SetWeight(ArgumentStack&& args)
{
  ArgumentStack stack;
  if (auto *pItem = item(args))
    {
      const auto w = Services::Events::ExtractArgument<int32_t>(args);
      pItem->m_nWeight = w;
    }
  return stack;
}
  
ArgumentStack Item::SetBaseGoldPieceValue(ArgumentStack&& args)
{
  ArgumentStack stack;
  if (auto *pItem = item(args))
    {
      const auto g = Services::Events::ExtractArgument<int32_t>(args);
      pItem->m_nBaseUnitCost = g;
    }
  return stack;
}

ArgumentStack Item::SetAddGoldPieceValue(ArgumentStack&& args)
{
  ArgumentStack stack;
  if (auto *pItem = item(args))
    {
      const auto g = Services::Events::ExtractArgument<int32_t>(args);
      pItem->m_nAdditionalCost = g;
    }
  return stack;
}  
  
ArgumentStack Item::GetBaseGoldPieceValue(ArgumentStack&& args)
{
  ArgumentStack stack;
  int32_t retval = -1; 
  if (auto *pItem = item(args))
    {
      retval = pItem->m_nBaseUnitCost;
    }
  Services::Events::InsertArgument(stack, retval);
  return stack;
}

ArgumentStack Item::GetAddGoldPieceValue(ArgumentStack&& args)
{
  ArgumentStack stack;
  int32_t retval = -1; 
  if (auto *pItem = item(args))
    {
      retval = pItem->m_nAdditionalCost;
    }
  Services::Events::InsertArgument(stack, retval);
  return stack;
}  

ArgumentStack Item::SetBaseItemType(ArgumentStack&& args)
{
  ArgumentStack stack;
  if (auto *pItem = item(args))
    {
      const auto bt = Services::Events::ExtractArgument<int32_t>(args);
      pItem->m_nBaseItem = bt;
    }
  return stack;
}
  
ArgumentStack Item::SetItemAppearance(ArgumentStack&& args)
{   
  ArgumentStack stack;
  if (auto *pItem = item(args))
    {
      
      const auto idx = Services::Events::ExtractArgument<int32_t>(args);
      const auto val = Services::Events::ExtractArgument<int32_t>(args);
      
      if(idx >= 0  && idx <= 28 && val >=0 && val <= 255)
	{
	  //Color appearance starts at 0 and ends at 5 
	  if(idx <= 5) 
	    {
	      pItem->m_nLayeredTextureColors[idx] = val;
	    }
	  //Item appearance starts at 6 and ends at 8
          else if(idx <= 8) 
	    {
	      pItem->m_nModelPart[idx - 6] = val;
	    }
	  //Armor appearance starts at 9 and ends at 28
	  else 
	    {
	       pItem->m_nArmorModelPart[idx - 9] = val;
	    }
	}   
    }   
  return stack;
}

ArgumentStack Item::GetEntireItemAppearance(ArgumentStack&& args)
{
  ArgumentStack stack;
  std::stringstream retval;
  char buf[4];
  int idx;
  
  if (auto *pItem = item(args))
    {
      for(idx = 0; idx < 6; idx++)
	{
	  sprintf(buf, "%02X", pItem->m_nLayeredTextureColors[idx]);
	  retval << buf;		  
	}

      for(idx = 0; idx < 3; idx++)
	{
	  sprintf(buf, "%02X", pItem->m_nModelPart[idx]);
	  retval << buf;		  
	}
      for(idx = 0; idx < 19; idx++)
	{
	  sprintf(buf, "%02X", pItem->m_nArmorModelPart[idx]);
	  retval << buf;		  
	}

    }
  
  Services::Events::InsertArgument(stack, retval.str()); 
  return stack;
}

ArgumentStack Item::RestoreItemAppearance(ArgumentStack&& args)
{   
  ArgumentStack stack;
 
  if (auto *pItem = item(args))
    {
      const auto sAppString = Services::Events::ExtractArgument<std::string>(args);
      int idx; 
      int stringPos=0;
      
      for(idx = 0; idx < 6; idx++)
	{
          pItem->m_nLayeredTextureColors[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
	  stringPos+=2;
	}
      
      for(idx = 0; idx < 3; idx++)
	{
          pItem->m_nModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
	  stringPos+=2;		  
	}
      for(idx = 0; idx < 19; idx++)
	{
	  pItem->m_nArmorModelPart[idx] = std::stoul(sAppString.substr(stringPos,2), nullptr, 16);
	  stringPos+=2;		  
	}
      
    }   
  return stack;
}  
}
