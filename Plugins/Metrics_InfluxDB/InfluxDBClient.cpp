#include "InfluxDBClient.hpp"

#include <netdb.h>
#include <unistd.h>
#include <stdexcept>
#include <string.h>
#include <sstream>

namespace Metrics_InfluxDB {

namespace {

std::string Replace(const std::string in, const std::string search, const std::string repl)
{
    auto ret = in;

    size_t pos = 0;
    while ((pos = ret.find(search, pos)) != std::string::npos)
    {
        ret.replace(pos, search.size(), repl);
        pos += repl.size();
    }

    return ret;
}

std::string Escape(const std::string inp)
{
    return Replace(Replace(inp, " ", "\\ "), ",", "\\,");
}

}

using namespace NWNXLib::Services;

InfluxDBClient::InfluxDBClient(const std::string& host, uint16_t port)
    : m_clientData()
{
    m_clientData.m_host = host;
    m_clientData.m_port = port;
    m_clientData.m_socket = -1;

    m_clientData.m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (m_clientData.m_socket == -1)
    {
        throw std::runtime_error("NWNX_Metrics_InfluxDB: Could not create socket");
    }

    m_clientData.m_server.sin_family = AF_INET;
    m_clientData.m_server.sin_port = htons(m_clientData.m_port);

    int ret = inet_aton(m_clientData.m_host.c_str(), &m_clientData.m_server.sin_addr);

    if (ret == 0)
    {
        addrinfo hints, *result = nullptr;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_DGRAM;

        ret = getaddrinfo(m_clientData.m_host.c_str(), nullptr, &hints, &result);

        if (ret)
        {
            throw std::runtime_error("NWNX_Metrics_InfluxDB: GetAddrInfo failed, please check the host/port config.");
        }

        sockaddr_in* host_addr = reinterpret_cast<sockaddr_in*>(result->ai_addr);
        memcpy(&m_clientData.m_server.sin_addr, &host_addr->sin_addr, sizeof(in_addr));
        freeaddrinfo(result);
    }
}

InfluxDBClient::~InfluxDBClient()
{
    close(m_clientData.m_socket);
}

void InfluxDBClient::Send(const MetricData& data)
{
    std::ostringstream oss;
    oss << Escape(data.m_name);

    for (auto& tag : data.m_tags)
    {
        if (tag.second != "")
        {
            oss << "," << Escape(tag.first) << "=" << Escape(tag.second);
        }
    }

    oss << " ";

    for (size_t i = 0; i < data.m_fields.size(); ++i)
    {
        auto& field = data.m_fields[i];
        oss << Escape(field.first) << "=" << field.second
            << ((i == data.m_fields.size() - 1) ? " " : ",");
    }

    oss << data.m_timestamp.time_since_epoch().count();
    SendSocket(oss.str());
}

void InfluxDBClient::SendSocket(const std::string message)
{
    int ret = sendto(m_clientData.m_socket, message.data(), message.size(), 0,
        reinterpret_cast<sockaddr*>(&m_clientData.m_server), sizeof(m_clientData.m_server));

    if (ret == -1)
    {
        throw std::runtime_error("NWNX_Metrics_InfluxDB: sendto failed");
    }
}

}
