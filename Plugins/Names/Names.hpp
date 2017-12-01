#pragma once

#include "API/CExoLocString.hpp"
#include "API/Types.hpp"
#include "Common.hpp"
#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"

#include <memory>
#include <unordered_map>
#include <vector>

namespace Names {

class Names : public NWNXLib::Plugin
{
public:
    Names(const Plugin::CreateParams& params);
    virtual ~Names();

private: // Structures
    using PlayerIdToNameMap = std::unordered_map<NWNXLib::API::Types::PlayerID, std::unique_ptr<NWNXLib::API::CExoLocString>>;
    using ObjectIDToNameMap = std::unordered_map<NWNXLib::API::Types::ObjectID, PlayerIdToNameMap>;

private:
    // This maps from objects -> ( playerID -> override name )
    ObjectIDToNameMap m_namesMap;

    static void WriteFullName(NWNXLib::API::CNWSMessage* msg, NWNXLib::API::Types::ObjectID observer, NWNXLib::API::CNWSPlayer* target);
    static void WriteFirstName(NWNXLib::API::CNWSMessage* msg, NWNXLib::API::Types::PlayerID observer, NWNXLib::API::CNWSCreature* target);
    static void WriteLastName(NWNXLib::API::CNWSMessage* msg, NWNXLib::API::Types::PlayerID observer, NWNXLib::API::CNWSCreature* target);

    NWNXLib::Services::Events::ArgumentStack OnSetName(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetName(NWNXLib::Services::Events::ArgumentStack&& args);

    NWNXLib::ViewPtr<NWNXLib::API::CExoLocString> GetStringAsObservedBy(NWNXLib::API::Types::PlayerID observer, NWNXLib::API::Types::ObjectID target);
};

}
