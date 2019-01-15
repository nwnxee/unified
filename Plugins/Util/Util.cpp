#include "Util.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CVirtualMachine.hpp"
#include "Utils.hpp"
#include "ViewPtr.hpp"

#include <string>
#include <functional>

using namespace NWNXLib;

static ViewPtr<Util::Util> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Util",
        "Miscellaneous utility functions",
        "sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Util::Util(params);
    return g_plugin;
}


namespace Util {

Util::Util(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Util::func, this, std::placeholders::_1))

    REGISTER(GetCurrentScriptName);
    REGISTER(GetAsciiTableString);
    REGISTER(Hash);
    REGISTER(PackEffect);
    REGISTER(UnpackEffect);

#undef REGISTER

}

Util::~Util()
{
}

ArgumentStack Util::GetCurrentScriptName(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retval = "";

    const auto depth = Services::Events::ExtractArgument<int32_t>(args);

    auto *pVM = API::Globals::VirtualMachine();
    if (pVM && pVM->m_pVirtualMachineScript && pVM->m_nRecursionLevel >= 0 && pVM->m_nRecursionLevel >= depth)
    {
        auto& script = pVM->m_pVirtualMachineScript[pVM->m_nRecursionLevel - depth];
        if (!script.m_sScriptName.IsEmpty())
            retval = script.m_sScriptName.CStr();
    }

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Util::GetAsciiTableString(ArgumentStack&& args)
{
    (void)args;
    ArgumentStack stack;
    static char table[256];

    if (table[0] == 0)
    {
        table[0] = ' '; // Can't pass NULL or it will terminate the string
        for (size_t i = 1; i < sizeof(table); i++)
            table[i] = i;
    }

    Services::Events::InsertArgument(stack, std::string(table));
    return stack;
}

ArgumentStack Util::Hash(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto str = Services::Events::ExtractArgument<std::string>(args);

    Services::Events::InsertArgument(stack, (int32_t)std::hash<std::string>{}(str));
    return stack;
}

ArgumentStack Util::PackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    API::CGameEffect *eff = new API::CGameEffect();

    eff->m_sCustomTag = Services::Events::ExtractArgument<std::string>(args).c_str();

    eff->m_oidParamObjectID[3] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[2] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[1] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[0] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);

    eff->m_sParamString[5] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[4] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[3] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[2] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[1] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[0] = Services::Events::ExtractArgument<std::string>(args).c_str();

    eff->m_nParamFloat[3] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[2] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[1] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[0] = Services::Events::ExtractArgument<float>(args);

    eff->SetNumIntegers(8); // allocate array
    eff->m_nParamInteger[7] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[6] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[5] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[4] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[3] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[2] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[1] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[0] = Services::Events::ExtractArgument<int32_t>(args);
    // Overwrite num integers from 8
    eff->m_nNumIntegers = Services::Events::ExtractArgument<int32_t>(args);

    int32_t bRightLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    API::CGameEffect *pRightLink = Services::Events::ExtractArgument<API::CGameEffect*>(args);
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    int32_t bLeftLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    API::CGameEffect *pLeftLink = Services::Events::ExtractArgument<API::CGameEffect*>(args);
    eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

    eff->m_nCasterLevel       = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bShowIcon          = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bExpose            = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nSpellId           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_oidCreator         = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_nExpiryTimeOfDay   = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nExpiryCalendarDay = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_fDuration          = Services::Events::ExtractArgument<float>(args);
    eff->m_nSubType           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nType              = Services::Events::ExtractArgument<int32_t>(args);

    if (bLeftLinkValid || bRightLinkValid)
        eff->UpdateLinked();

    Services::Events::InsertArgument(stack, eff);
    return stack;
}
ArgumentStack Util::UnpackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto eff = Services::Events::ExtractArgument<API::CGameEffect*>(args);

    Services::Events::InsertArgument(stack, (int32_t)eff->m_nType);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSubType);
    Services::Events::InsertArgument(stack, (float)eff->m_fDuration);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryCalendarDay);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryTimeOfDay);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidCreator);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSpellId);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bExpose);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bShowIcon);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nCasterLevel);
    Services::Events::InsertArgument(stack, (API::CGameEffect*)eff->m_pLinkLeft);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_pLinkLeft != nullptr));
    Services::Events::InsertArgument(stack, (API::CGameEffect*)eff->m_pLinkRight);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_pLinkRight != nullptr));

    Services::Events::InsertArgument(stack, (int32_t)eff->m_nNumIntegers);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[0]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[1]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[2]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[3]);

    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[0].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[1].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[2].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[3].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[4].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[5].CStr()));

    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[0]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[1]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[2]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[3]);

    Services::Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));
    delete eff;
    return stack;
}


}
