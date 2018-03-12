
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

#include "Item.hpp"

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
        "bhaal@marcaargentea.net",
        1,
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
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Item::func, this, std::placeholders::_1))

    REGISTER(SetWeight);

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
}
