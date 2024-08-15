#pragma once

#include "nwnx.hpp"
#include "External/httplib.h"

namespace HTTP {
    class Client;

    class HTTP : public NWNXLib::Plugin
    {
    public:
        explicit HTTP(NWNXLib::Services::ProxyServiceList*);
        ~HTTP() override;
        enum RequestMethod
        {
            GET    = 0,
            POST   = 1,
            DELETE = 2,
            PATCH  = 3,
            PUT    = 5,
            OPTION = 6,
            HEAD   = 7
        };
        enum AuthenticationType
        {
            NONE         = 0,
            BASIC        = 1,
            DIGEST       = 2,
            BEARER_TOKEN = 3
        };
        enum ContentType
        {
            HTML               = 0,
            PLAINTEXT          = 1,
            JSON               = 2,
            URL_ENCODED        = 3,
            XML                = 4,
        };

        static constexpr const char* ContentTypeToString(const unsigned value)
        {
            constexpr const char* TYPE_STRINGS[] =
            {
                "text/html",
                "text/plain",
                "application/json",
                "application/x-www-form-urlencoded",
                "application/xml"
            };
            return (value > 4) ? "text/html" : TYPE_STRINGS[value];
        }

    private:
        std::unique_ptr<Client> m_Client;
    };

}
