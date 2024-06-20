#include <future>
#include "HTTP/Server.hpp"

using namespace NWNXLib;

namespace HTTP
{

std::unique_ptr<httplib::Server> Server::m_httpServer;
std::unique_ptr<std::thread> Server::m_httpServerThread;
std::chrono::milliseconds Server::m_responseTimeout;

Server::Server()
{
    Events::RegisterEvent(PLUGIN_NAME, "Server_SendResponse", &SendResponse);

    m_responseTimeout = std::chrono::milliseconds(Config::Get<int>("SERVER_RESPONSE_TIMEOUT", 1000));
    auto rootHTML = Config::Get<std::string>("SERVER_ROOT_HTML", "<html><head><title>Welcome to nwnx http!</title></head><body><h1>Welcome to nwnx http!</h1></body></html>");
    auto rootStatus = Config::Get<int>("SERVER_ROOT_STATUS", 403);
    auto httpPort = Config::Get<int>("SERVER_PORT", 8686);
    auto useSSL = Config::Get<bool>("SERVER_USE_SSL", false);
    auto eventURL = Config::Get<std::string>("SERVER_EVENT_URL");
    if (useSSL)
    {
        auto certFile = Config::Get<std::string>("SERVER_SSL_CERT_FILE", "./cert.pem");
        auto certKey = Config::Get<std::string>("SERVER_SSL_KEY_FILE", "./key.pem");
        m_httpServer = std::make_unique<httplib::SSLServer>(certFile.c_str(), certKey.c_str());
        if (!m_httpServer->is_valid())
        {
            BIO* bio = BIO_new(BIO_s_mem());
            ERR_print_errors(bio);
            char *buf = nullptr;
            size_t len = BIO_get_mem_data(bio, &buf);
            std::string sRet((char*)buf, len);
            BIO_free (bio);
            LOG_ERROR("Unable to configure SSL Server, not starting. %s", sRet);
            return;
        }
        else
        {
            // Required to prevent crashing when invalid SSL exchanges take place
            signal(SIGPIPE, SIG_IGN);
        }
    }
    else
    {
        m_httpServer = std::make_unique<httplib::Server>();
    }

    auto *svr = m_httpServer.get();
    m_httpServerThread = std::make_unique<std::thread>([svr,httpPort,rootStatus,rootHTML,eventURL]()
    {
        svr->Get("/", [rootStatus,rootHTML](const httplib::Request &, httplib::Response &res)
        {
            if (rootStatus != 200)
                res.status = rootStatus;
            else
                res.set_content(rootHTML, HTTP::ContentTypeToString(HTTP::ContentType::HTML));
        });
        if (!eventURL->empty())
        {
            svr->Get(eventURL->c_str(), [&](const httplib::Request &req, httplib::Response &res)
            {
                auto path = req.path;
                auto requestThreadId = Server::GetNewRequestID();
                if (m_cachedResponses.find(path) != m_cachedResponses.end())
                {
                    auto now = std::chrono::system_clock::now();
                    if (now < m_cachedResponses[path].cacheUntil)
                    {
                        res.set_content(m_cachedResponses[path].message, HTTP::ContentTypeToString(m_cachedResponses[path].contentType));
                        auto expiresIn = std::chrono::duration_cast<std::chrono::seconds>(m_cachedResponses[path].cacheUntil - now);
                        LOG_DEBUG("Cache hit on %s, cached response expires in %d seconds.", path, expiresIn.count());
                        Server::DeleteResponse(requestThreadId);
                        return;
                    }
                    else
                    {
                        LOG_DEBUG("Cache expired on %s", path);
                        m_cachedResponses.erase(path);
                    }
                }
                Tasks::QueueOnMainThread([requestThreadId,path]()
                {
                   MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(requestThreadId)});
                   MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"PATH", path});
                   MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_SERVER_GET", Utils::ObjectIDToString(0)});
                });
                std::atomic_bool cancellation_token = false;
                auto future = std::async(std::launch::async, Server::WaitForResponse, requestThreadId, std::ref(cancellation_token));
                if (std::future_status::ready == future.wait_for(m_responseTimeout))
                {
                    res.status = 200;
                    auto response = future.get();
                    res.set_content(response.message, HTTP::ContentTypeToString(response.contentType));
                    auto now = std::chrono::system_clock::now();
                    if (response.cacheUntil > now)
                    {
                        m_cachedResponses[path] = response;
                    }
                }
                else
                {
                    cancellation_token = true;
                    res.status = 404;
                }
                Server::DeleteResponse(requestThreadId);
            });
        }
        svr->set_error_handler([](const httplib::Request &, httplib::Response &res) {
            const char *fmt = "<html><head><title>%d %s</title></head><body><center><h1>%d %s</h1></center><hr><center>nwnx http</center></body></html>";
            char buf[256];
            snprintf(buf, sizeof(buf), fmt, res.status, httplib::detail::status_message(res.status), res.status, httplib::detail::status_message(res.status));
            res.set_content(buf, HTTP::ContentTypeToString(HTTP::ContentType::HTML));
        });
        svr->listen("0.0.0.0", httpPort);
    });
    LOG_INFO("%s Server started, accessible on port %d", useSSL ? "HTTPS" : "HTTP", httpPort);
}

Server::~Server()
{
    if (m_httpServerThread)
    {
        if (m_httpServer->is_running())
        {
            LOG_INFO("Shutting down HTTP server.");
            m_httpServer->stop();
        }
        m_httpServerThread->join();
    }
}

void Server::DeleteResponse(uint32_t requestId)
{
    m_responses.erase(requestId);
}

uint32_t Server::GetNewRequestID()
{
    return m_servRequestId++;
}

Server::Response Server::WaitForResponse(uint32_t requestThreadId, const std::atomic_bool& cancelled)
{
    while (m_responses.find(requestThreadId) == m_responses.end() && !cancelled)
        std::this_thread::sleep_for(std::chrono::milliseconds (10));

    if (cancelled)
    {
        if (m_responses.find(requestThreadId) != m_responses.end())
            m_responses.erase(requestThreadId);
        return Server::Response();
    }

    return m_responses[requestThreadId];
}

Events::ArgumentStack Server::SendResponse(Events::ArgumentStack&& args)
{
    if (!m_httpServerThread || !m_httpServer->is_running())
    {
        LOG_ERROR("Can't send HTTP server response, no server is running!");
        return Events::Arguments();
    }
    auto requestId = Events::ExtractArgument<int>(args);
    auto response = Events::ExtractArgument<std::string>(args);
    auto contentType = Events::ExtractArgument<int>(args);
    auto cacheSeconds = Events::ExtractArgument<int>(args);
    auto cacheUntil = std::chrono::system_clock::now() + std::chrono::seconds(cacheSeconds);
    m_responses[requestId] = Server::Response(response, static_cast<HTTP::ContentType>(contentType), cacheUntil);

    return Events::Arguments();
}

}
