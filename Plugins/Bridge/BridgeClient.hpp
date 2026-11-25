#pragma once
#include "BridgeMessage.hpp"
#include <string>
#include <sstream>
#include <thread>
#include <queue>
#include <mutex>

#define READ_BUFFER_SIZE 4096

typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;

namespace Bridge
{

typedef enum
{
    DISCONNECTED,
    CONNECTING,
    SSL_PENDING,
    AUTH_PENDING,
    CONNECTED
} ConnectionState;

struct ReadBuffer
{
    int bytesRead = 0;
    int length = -1;
    std::stringstream buf = std::stringstream(std::ios::binary | std::ios::out | std::ios::in);
};

class SSLCtxWrapper
{
public:
    SSL_CTX* ctx = nullptr;
    int sock = -1;
    SSLCtxWrapper(bool isServer);
    ~SSLCtxWrapper();
};

class SocketWrapper
{
public:
    int sock = -1;
    SocketWrapper() = default;
    ~SocketWrapper();
};

class SSLWrapper
{
public:
    SSL* clientSSL;
    int clientSocket;
    ConnectionState state = CONNECTING;
    ReadBuffer* readBuffer = new ReadBuffer();
    SSLWrapper(SSL_CTX* context, int sock);
    ~SSLWrapper();

    std::unique_ptr<Message> GetMessage();
};

class BridgeClient
{
protected:
    int m_ownServerId = -1;
    int m_connectionState = DISCONNECTED;
    std::unique_ptr<SSLWrapper> m_ssl = nullptr;
    std::unique_ptr<SSLCtxWrapper> m_ssl_ctx = nullptr;
    std::string m_hostname;
    std::string m_portname;
    std::string m_password;
    std::unique_ptr<std::thread> m_thread = nullptr;
    bool m_threadRunning = false;
    std::queue<std::unique_ptr<Message>> m_inque;
    std::queue<std::unique_ptr<Message>> m_outque;
    std::mutex m_inqueMutex;
    std::mutex m_outqueMutex;
    ServerList m_serverList;
public:
    BridgeClient(std::string hostname, std::string portname, std::string password);
    ~BridgeClient();
    virtual void Start();
    void Run();
    void Stop();
    bool IsConnected();
    int GetId();
    void QueueIncomingEvent(std::unique_ptr<Message> msg);
    void QueueOutgoingEvent(std::unique_ptr<Message> msg);
    std::vector<ServerInfo> GetServerList();
    std::optional<std::vector<PlayerInfo>> GetPlayerList(uint32_t serverId);
protected:
    std::unique_ptr<Message> GetIncomingEvent();
    std::unique_ptr<Message> GetOutgoingEvent();
    int ReadFromSocket(SSLWrapper& s);
    int WriteToSocket(SSLWrapper& s, std::stringstream& ss);
    int HandleIncomingMessage(std::unique_ptr<Message> msg);
    int HandleOutgoingEvent(std::unique_ptr<Message>& msg);
    int HandleIncomingEvent(std::unique_ptr<Message> msg);
    int SendMessage(SSLWrapper& s, Message& msg);
    int SendMessage(SSLWrapper& s, std::stringstream& ss);
    void AddPlayerToServerList(const PlayerInfoMessage& msg);
    void AddServerToServerList(const ServerInfoMessage& msg);
    void RemovePlayerFromServerList(const PlayerDisconnectMessage& msg);
    void RemoveServerFromServerList(const ServerDisconnectMessage& msg);
    void ReplaceServerList(const ServerListMessage& msg);

    friend class Hooks;
};

class BridgeServer : public BridgeClient
{
private:
    std::vector<SSLWrapper> clientSockets;
    std::string m_keypath;
    std::string m_certpath;
    bool m_generateCerts;
public:
    void Start();
    bool CheckExistingKey();
    void GenerateKey();
    int RelayMessage(std::unique_ptr<Message> msg);
    int BroadcastMessage(std::unique_ptr<Message> msg);

    BridgeServer(std::string portname, std::string password, std::string keypath, std::string certpath, bool generateCerts = false);
    ~BridgeServer();
};

}
