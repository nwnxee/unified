#include "Ruby.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Metrics/Metrics.hpp"

#include "ruby.h" // Included last because ruby redefines snprintf for reasons.

using namespace NWNXLib;

static ViewPtr<Ruby::Ruby> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Ruby",
        "Allows users to execute arbitrary Ruby from the game.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        false // Not hotswappable -- we don't want to tear down the VM ... bad stuff happens.
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Ruby::Ruby(params);
    return g_plugin;
}

using namespace NWNXLib::Services;

namespace Ruby {

Ruby::Ruby(const Plugin::CreateParams& params)
    : Plugin(params), m_nextEvaluationId(0)
{
    m_evaluateMetrics = GetServices()->m_config->Get<bool>("EVALUATE_METRICS", false);

    int argc = 0;
    char** argv;
    ruby_sysinit(&argc, &argv);

    RUBY_INIT_STACK;
    ruby_init();
    ruby_init_loadpath();

    SafeRequire("enc/encdb");
    SafeRequire("enc/trans/transdb");
    SafeRequire("rubygems");

    Maybe<std::string> preloadScript = GetServices()->m_config->Get<std::string>("PRELOAD_SCRIPT");
    if (preloadScript)
    {
        SafeRequire(*preloadScript);
    }

    GetServices()->m_events->RegisterEvent("EVALUATE", std::bind(&Ruby::OnEvaluate, this, std::placeholders::_1));
}

Ruby::~Ruby()
{

}

NWNXLib::Services::Events::ArgumentStack Ruby::OnEvaluate(NWNXLib::Services::Events::ArgumentStack&& args)
{
    const auto code = Events::ExtractArgument<std::string>(args);

    const auto evaluate = [this](const std::string& evalCode) -> const char*
    {
        int state;
        VALUE ret = rb_eval_string_protect(evalCode.c_str(), &state);

        if (state)
        {
            HandleError(state);
        }
        else
        {
            if (ret == Qtrue)
            {
                return "1";
            }
            else if (ret == Qfalse)
            {
                return "0";
            }
            else if (ret != Qnil)
            {
                ret = rb_funcall(ret, rb_intern("to_s"), 0);
                return StringValueCStr(ret);
            }
        }

        return "";
    };

    const int32_t evaluationId = m_nextEvaluationId++;

    const char* retString;

    if (m_evaluateMetrics)
    {
        const auto timeBefore = std::chrono::high_resolution_clock::now();
        retString = evaluate(code);
        const auto timeAfter = std::chrono::high_resolution_clock::now();

        using namespace std::chrono;
        nanoseconds dur = duration_cast<nanoseconds>(timeAfter - timeBefore);

        GetServices()->m_metrics->Push(
            "Evaluate",
            { { "ns", std::to_string(dur.count()) } },
            { { "ID", std::to_string(evaluationId) } });
    }
    else
    {
        retString = evaluate(code);
    }

    Events::ArgumentStack stack;
    Events::InsertArgument(stack, std::string(retString));

    LOG_INFO("Evaluated Ruby. Ruby ID: '%i', code: '%s', got return value '%s'.", evaluationId, code.c_str(), retString);

    return stack;
}

void Ruby::SafeRequire(const std::string& script)
{
    int state;
    rb_protect(reinterpret_cast<VALUE(*)(VALUE)>(&rb_require), reinterpret_cast<VALUE>(script.c_str()), &state);

    if (state)
    {
        HandleError(state);
    }
}

void Ruby::HandleError(const int errCode)
{
    VALUE errInfo = rb_gv_get("$!");
    VALUE errClass = rb_class_path(CLASS_OF(errInfo));
    VALUE errMsg = rb_obj_as_string(errInfo);

    const std::string errClassAsStr = StringValueCStr(errClass);
    const std::string errMsgAsStr = StringValueCStr(errMsg);

    LOG_ERROR("Encountered error code: '%i', class: '%s', msg: '%s'.", errCode, errClassAsStr.c_str(), errMsgAsStr.c_str());
}

}
