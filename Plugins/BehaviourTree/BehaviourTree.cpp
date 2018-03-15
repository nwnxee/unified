#include "BehaviourTree.hpp"
#include "BT/BehaviourTree.hpp"
#include "API/Version.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<BehaviourTree::BehaviourTree> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "BehaviourTree",
        "TODO",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new BehaviourTree::BehaviourTree(params);
    return g_plugin;
}

namespace BehaviourTree {

static std::vector<BT::ITask*> s_stagingTasks;

template <typename T, typename ... Args>
int32_t CreateNode(Args ... args)
{
    int32_t id = static_cast<int32_t>(s_stagingTasks.size());
    s_stagingTasks.push_back(new T(args ...));
    return id;
}

BehaviourTree::BehaviourTree(const Plugin::CreateParams& params)
    : Plugin(params)
{
    using namespace NWNXLib::API;
    using namespace NWNXLib::API::Types;
    using namespace NWNXLib::Services;

    MessagingProxy* messaging = GetServices()->m_messaging.get();
    auto profilePerf = [messaging](const std::string& name, std::function<void()> operation)
    {
        static std::unordered_map<std::string, bool> s_madeResamplers;

        if (!s_madeResamplers[name])
        {
            messaging->BroadcastMessage("NWNX_PROFILER_SET_PERF_SCOPE_RESAMPLER", { name });
            s_madeResamplers[name] = true;
        }

        messaging->BroadcastMessage("NWNX_PROFILER_PUSH_PERF_SCOPE", { name });
        operation();
        messaging->BroadcastMessage("NWNX_PROFILER_POP_PERF_SCOPE", { name });
    };

    // Utility
    GetServices()->m_events->RegisterEvent("CREATE_BT", [this, profilePerf](Events::ArgumentStack&& args)
    {
        const ObjectID oid = Events::ExtractArgument<ObjectID>(args);
        const std::string name = Events::ExtractArgument<std::string>(args);
        const int32_t childId = Events::ExtractArgument<int32_t>(args);
        ASSERT(childId >= 0);
        profilePerf("CreateBT", [&]() { m_trees[oid][name] = std::unique_ptr<BT::ITask>(s_stagingTasks[static_cast<size_t>(childId)]); });
        s_stagingTasks.clear();
        return Events::ArgumentStack();
    });

    GetServices()->m_events->RegisterEvent("CLEAR_BT", [this, profilePerf](Events::ArgumentStack&& args)
    {
        const ObjectID oid = Events::ExtractArgument<ObjectID>(args);
        const std::string name = Events::ExtractArgument<std::string>(args);
        profilePerf("ClearBT", [&]() { m_trees[oid].erase(name); });
        return Events::ArgumentStack();
    });

    GetServices()->m_events->RegisterEvent("TICK_BT", [this, profilePerf](Events::ArgumentStack&& args)
    {
        const ObjectID oid = Events::ExtractArgument<ObjectID>(args);
        const std::string name = Events::ExtractArgument<std::string>(args);
        profilePerf("TickBT", [&]() { m_trees[oid][name]->Tick(); });
        return Events::ArgumentStack();
    });

    // Composites
    auto getChildren = [](Events::ArgumentStack& args) -> auto
    {
        const size_t childCount = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));

        std::vector<BT::ITask*> children;
        for (size_t i = 0; i < childCount; ++i)
        {
            const int32_t childId = Events::ExtractArgument<int32_t>(args);
            ASSERT(childId >= 0);
            children.push_back(s_stagingTasks[static_cast<size_t>(childId)]);
        }

        return children;
    };

    GetServices()->m_events->RegisterEvent("CREATE_COMPOSITE_RANDOM_SELECTOR", [getChildren](Events::ArgumentStack&& args)
    {
        auto children = getChildren(args);
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::CompositeRandomSelector>(children));
        return stack;
    });

    GetServices()->m_events->RegisterEvent("CREATE_COMPOSITE_RANDOM_SEQUENCE", [getChildren](Events::ArgumentStack&& args)
    {
        auto children = getChildren(args);
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::CompositeRandomSequence>(children));
        return stack;
    });

    GetServices()->m_events->RegisterEvent("CREATE_COMPOSITE_SELECTOR", [getChildren](Events::ArgumentStack&& args)
    {
        auto children = getChildren(args);
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::CompositeSelector>(children));
        return stack;
    });

    GetServices()->m_events->RegisterEvent("CREATE_COMPOSITE_SEQUENCE", [getChildren](Events::ArgumentStack&& args)
    {
        auto children = getChildren(args);
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::CompositeSequence>(children));
        return stack;
    });

    // Decorators
    GetServices()->m_events->RegisterEvent("CREATE_DECORATOR_INVERT", [](Events::ArgumentStack&& args)
    {
        const int32_t childId = Events::ExtractArgument<int32_t>(args);
        ASSERT(childId >= 0);
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::DecoratorInvert>(s_stagingTasks[static_cast<size_t>(childId)]));
        return stack;
    });

    // Leafs
    GetServices()->m_events->RegisterEvent("CREATE_LEAF_ALWAYS_FAIL", [](Events::ArgumentStack&&)
    {
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::LeafAlwaysFail>());
        return stack;
    });

    GetServices()->m_events->RegisterEvent("CREATE_LEAF_ALWAYS_SUCCEED", [](Events::ArgumentStack&&)
    {
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::LeafAlwaysSucceed>());
        return stack;
    });

    GetServices()->m_events->RegisterEvent("CREATE_LEAF_SLEEP", [](Events::ArgumentStack&& args)
    {
        using namespace std::chrono;
        const milliseconds interval = static_cast<milliseconds>(Events::ExtractArgument<int32_t>(args));
        Events::ArgumentStack stack;
        Events::InsertArgument(stack, CreateNode<BT::LeafSleep>(interval));
        return stack;
    });
}

BehaviourTree::~BehaviourTree()
{
}

}
