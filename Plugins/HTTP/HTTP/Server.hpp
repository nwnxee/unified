#pragma once

#include "HTTP.hpp"

using ArgumentStack = NWNXLib::ArgumentStack;

namespace HTTP {

using namespace NWNXLib::Services;

class Server
{
    struct Response
    {
        std::string message;
        HTTP::ContentType contentType;
        std::chrono::system_clock::time_point cacheUntil;

        Response()
        {
            message = "";
            contentType = HTTP::ContentType::PLAINTEXT;
            cacheUntil = std::chrono::system_clock::now();
        }
        Response(std::string message, HTTP::ContentType contentType, std::chrono::system_clock::time_point cacheUntil)
        {
            this->message = std::move(message);
            this->contentType = contentType;
            this->cacheUntil = cacheUntil;
        }
    };
public:
    explicit Server();
    virtual ~Server();
    static Response WaitForResponse(uint32_t, const std::atomic_bool&);
    static void DeleteResponse(uint32_t);
    static uint32_t GetNewRequestID();
    static std::unique_ptr<httplib::Server> m_httpServer;
    static std::unique_ptr<std::thread> m_httpServerThread;
    static std::chrono::milliseconds m_responseTimeout;

private:

    static ArgumentStack SendResponse(ArgumentStack&&);

    static inline std::unordered_map<uint32_t, Response> m_responses;
    static inline std::unordered_map<std::string, Response> m_cachedResponses;
    static inline uint32_t m_servRequestId = 0;
};

}
