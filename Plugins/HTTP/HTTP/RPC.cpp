#include "HTTP/RPC.hpp"

#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/Tasks/Tasks.hpp"

using namespace NWNXLib;

namespace HTTP
{

TasksProxy* RPC::m_servTasks;
MessagingProxy* RPC::m_servMessaging;

RPC::RPC(ConfigProxy* config, MessagingProxy* messaging, TasksProxy* tasks)
{
    m_authToken = config->Get<std::string>("RPC_AUTH_TOKEN", "");
    m_rpcURL = config->Get<std::string>("RPC_URL", "/rpc");
    if (m_rpcURL.rfind('/', 0) == std::string::npos)
        m_rpcURL = "/" + m_rpcURL;
    if (m_authToken.empty() && m_rpcURL == "/rpc")
    {
        LOG_ERROR("You have not set up an authorization token for your RPC server and you're using the default path of /rpc. You must either "
                      "set an authorization token (NWNX_HTTP_RPC_AUTH_TOKEN) or set a unique URL (NWNX_HTTP_RPC_URL) for your rpc path. The server will not be started.");
        return;
    }
    m_servTasks = tasks;
    m_servMessaging = messaging;

    StartRPCServer();
}

httplib::Server* RPC::WaitForWebServer(const std::atomic_bool& cancelled)
{
    auto *svr = Server::m_httpServer.get();
    while ((svr == nullptr || !svr->is_running())  && !cancelled)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds (10));
        svr = Server::m_httpServer.get();
    }
    return svr;
}

void RPC::StartRPCServer()
{
    // RPC needs to wait for the HTTP server to be up and running on its own thread before it can start
    auto *svr = Server::m_httpServer.get();
    if (svr == nullptr || !svr->is_running())
    {
        std::atomic_bool cancellation_token = false;
        auto future = std::async(std::launch::async, WaitForWebServer, std::ref(cancellation_token));
        if (std::future_status::ready == future.wait_for(std::chrono::seconds(3)))
        {
            svr = future.get();
        }
        else
        {
            cancellation_token = true;
            LOG_ERROR("No NWNX web server was detected for RPC to use, not started.");
            return;
        }
    }
    LOG_INFO("RPC Server up and available at %s", m_rpcURL.c_str());

    svr->Post(m_rpcURL.c_str(), [&](const httplib::Request &req, httplib::Response &res)
    {
        auto requestId = Server::GetNewRequestID();

        if (!m_authToken.empty() && (!req.has_header("Authorization") || req.get_header_value("Authorization") != m_authToken))
        {
            res.status = 401;
        }
        else
        {
            auto ct = req.get_header_value("Content-Type");
            std::string json_data;
            std::unordered_map<std::string,std::string> params;
            int paramCount = 0;
            if (ct.find(HTTP::ContentTypeToString(HTTP::ContentType::JSON)) != std::string::npos)
                json_data = req.body;
            else
            {
                paramCount = req.params.size();
                for (const auto & param : req.params)
                    params[param.first] = param.second;
            }
            m_servTasks->QueueOnMainThread([requestId,json_data,paramCount,params]()
            {
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(requestId)});
                if (!json_data.empty())
                    m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"JSON_DATA", json_data});
                else
                {
                    m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"PARAM_COUNT", std::to_string(paramCount)});
                    int i = 0;
                    for (const auto & param : params)
                    {
                        std::string sParamKey = "PARAM_KEY_" + std::to_string(i);
                        std::string sParamValue = "PARAM_VALUE_" + std::to_string(i);
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {sParamKey, param.first});
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {sParamValue, param.second});
                        i++;
                    }
                }
                m_servMessaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_SERVER_POST", Utils::ObjectIDToString(((CGameObject*)Utils::GetModule())->m_idSelf)});
            });

            // Our event was sent to nwscript on the main thread, wait for a response here or timeout after m_responseTimeout seconds
            std::atomic_bool cancellation_token = false;
            auto future = std::async(std::launch::async, Server::WaitForResponse, requestId, std::ref(cancellation_token));
            if (std::future_status::ready == future.wait_for(Server::m_responseTimeout))
            {
                res.status = 200;
                auto response = future.get();
                res.set_content(response.message, HTTP::ContentTypeToString(response.contentType));
            }
            else
            {
                cancellation_token = true;
                // Confirm the request was received but no response was returned.
                res.status = 202;
            }
            Server::DeleteResponse(requestId);
        }
    });
}

}
