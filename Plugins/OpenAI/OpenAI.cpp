#include "API/CNWSModule.hpp"
#include "nwnx.hpp"

#include "External/json/json.hpp"

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "External/httplib.h"

#include <future>

using namespace NWNXLib;

// from webhook
static std::string escape_json(const std::string& s) {
    std::ostringstream o;
    for (auto c = s.cbegin(); c != s.cend(); c++) {
        if (*c == '"' || *c == '\\' || ('\x00' <= *c && *c <= '\x1f')) {
            o << "\\u"
                << std::hex << std::setw(4) << std::setfill('0') << (int)*c;
        }
        else {
            o << *c;
        }
    }
    return o.str();
}

void DoRequest(const std::string& prompt, const std::string& token, const float randomness, const int maxTokens)
{
    httplib::Client client("https://api.openai.com");
    client.enable_server_certificate_verification(false);
    client.set_read_timeout(std::chrono::seconds(60));
    client.set_write_timeout(std::chrono::seconds(60));

    // See https://platform.openai.com/docs/api-reference/completions/create

    httplib::Headers header = {
        { "Authorization", "Bearer " + Config::Get<std::string>("TOKEN", "SET_ENV_CONFIG") }
    };

    std::string params = R"(
    {
        "model": "$1",
        "prompt": "$2",
        "temperature": $3,
        "max_tokens": $4
    })";

    params.replace(params.find("$1"), 2, "text-davinci-003");
    params.replace(params.find("$2"), 2, escape_json(String::ToUTF8(prompt)));
    params.replace(params.find("$3"), 2, std::to_string(randomness));
    params.replace(params.find("$4"), 2, std::to_string(maxTokens));

    LOG_DEBUG("Making request %s", params.c_str());
    httplib::Result result = client.Post("/v1/completions", header, params, "application/json");

    if (result)
    {
        LOG_DEBUG("Got result %s", result->body.c_str());

        json bodyAsJson = json::parse(result->body);
        const std::string text = bodyAsJson["choices"][0]["text"];

        Tasks::QueueOnMainThread([=]()
            {
                auto moduleOid = NWNXLib::Utils::ObjectIDToString(Utils::GetModule()->m_idSelf);
                MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", { "RESPONSE", text });
                MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", { "TOKEN", token });
                MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", { "NWNX_ON_OPENAI_RESPONSE", moduleOid });
            });
    }
    else
    {
        LOG_ERROR("Failed to make request due to: '%s'", httplib::to_string(result.error()).c_str());
    }
}

NWNX_EXPORT ArgumentStack ChatAsync(ArgumentStack&& args)
{
    const std::string prompt = args.extract<std::string>();
    const std::string token = args.extract<std::string>();
    const float randomness = args.extract<float>();
    const int maxTokens = args.extract<int>();
    std::async(std::launch::async, &DoRequest, prompt, token, randomness, maxTokens);
    return {};
}
