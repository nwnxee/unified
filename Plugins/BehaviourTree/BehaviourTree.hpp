#pragma once

#include "API/Types.hpp"
#include "Plugin.hpp"

#include <memory>
#include <string>
#include <unordered_map>

namespace BT { class ITask; }

namespace BehaviourTree {

class BehaviourTree : public NWNXLib::Plugin
{
public:
    BehaviourTree(const Plugin::CreateParams& params);
    virtual ~BehaviourTree();

private:
    using NameToBTMap = std::unordered_map<std::string, std::unique_ptr<BT::ITask>>;
    using ObjectIDToNameToBTMap = std::unordered_map<NWNXLib::API::Types::ObjectID, NameToBTMap>;
    ObjectIDToNameToBTMap m_trees;
};

}
