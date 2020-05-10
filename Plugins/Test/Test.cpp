#include "Test.hpp"
#include "Utils/String.hpp"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

static Test::Test* g_plugin;

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
            {
                    "test",
                    "Test some stuff",
                    "jmd",
                    "jmd2028@gmail.com",
                    1,
                    true,
                    0
            };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Test::Test(params);
    return g_plugin;
}

namespace Test
{

Test::Test(const Plugin::CreateParams& params)
        : Plugin(params)
{
    LOG_NOTICE("Running Tests...");
    int result = Catch::Session().run();
    if(result) 
    {
        LOG_FATAL("Tests failed");
    }
    else 
    {
        LOG_NOTICE("Tests passed");
        std::exit(0);
    }
}

Test::~Test()
{
}
    
} // namespace Test

TEST_CASE( "Utils: String", "[utils]") {
    REQUIRE(*NWNXLib::Utils::from_string<bool>("0") == false);
    REQUIRE(*NWNXLib::Utils::from_string<bool>("1") == true);
    REQUIRE(*NWNXLib::Utils::from_string<int32_t>("0") == 0);
}
