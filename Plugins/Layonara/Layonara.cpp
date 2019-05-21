#include "Layonara.hpp"

#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWFeat.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Layonara::Layonara> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
  {
    "Layonara",
    "Functions specific to Layonara",
    "orth",
    "orth@layonara.com",
    1,
    true
  };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Layonara::Layonara(params);
    return g_plugin;
}


namespace Layonara {

Layonara::Layonara(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Layonara::func, this, std::placeholders::_1));

    REGISTER(SetEquippableSlots)
    REGISTER(SetHostileFeat);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSInventory__GetItemInSlot>(&Layonara::GetItemInSlotHook);
    m_GetItemInSlotHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSInventory__GetItemInSlot);

}

Layonara::~Layonara()
{
}

CNWSItem *Layonara::GetItemInSlotHook(CNWSInventory *pThis, uint32_t nSlot)
{
    // Arrow
    if (nSlot == 0x03800)
        nSlot = 0x00800;
    // Bolt
    else if (nSlot == 0x1f800)
        nSlot = 0x02000;
    // Bullet
    else if (nSlot == 0x23800)
        nSlot = 0x01000;
    return g_plugin->m_GetItemInSlotHook->CallOriginal<CNWSItem*>(pThis, nSlot);
}

ArgumentStack Layonara::SetEquippableSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto baseItemId =  Services::Events::ExtractArgument<int32_t>(args);
    auto slots =  Services::Events::ExtractArgument<int32_t>(args);
    Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItemId)->m_nEquipableSlots = slots;
    return stack;
}

ArgumentStack Layonara::SetHostileFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto featId =  Services::Events::ExtractArgument<int32_t>(args);
    auto hostile =  Services::Events::ExtractArgument<int32_t>(args);
    auto feat = Globals::Rules()->GetFeat(featId);
    feat->m_bHostileFeat = hostile;
    return stack;
}

}
