#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "Common.hpp"
#include "API/CExoLocString.hpp"
#include "ViewPtr.hpp"

#include <unordered_map>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
    Rename(const Plugin::CreateParams& params);
    virtual ~Rename();

private:

    static void HookPlayerList(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer* pPlayer);
    static void HookPartyInvite(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, unsigned char);

    NWNXLib::API::CExoLocString ContainString(const std::string& str);
    std::string ExtractString(NWNXLib::API::CExoLocString& locStr);
    std::string GenerateRandomPlayerName(size_t length);

    void GlobalNameChange(bool bOriginal, NWNXLib::API::CNWSPlayer* pPlayer);
    void UpdateName(NWNXLib::API::CNWSCreature* targetObject);

    ArgumentStack SetPCNameOverride(ArgumentStack&& args);

    NWNXLib::API::CNWSPlayer *player(NWNXLib::API::Types::ObjectID playerId);
};

}
