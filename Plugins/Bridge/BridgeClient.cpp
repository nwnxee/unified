#include "BridgeClient.hpp"
#include "BridgeHooks.hpp"
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include "Services/Config/Config.hpp"
#include <thread>

#include "API/API/CVirtualMachine.hpp"

constexpr auto SELECT_TIMEOUT = 200000;
using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Bridge
{

BridgeServer::BridgeServer(std::string portname, std::string password, std::string keypath, std::string certpath, bool generateCerts)
    : BridgeClient("localhost", portname, password),
    m_keypath(keypath),
    m_certpath(certpath),
    m_generateCerts(generateCerts)
{

}

bool BridgeServer::CheckExistingKey()
{
    FILE* f = fopen(m_keypath.c_str(), "r");
    if (!f)
    {
        LOG_DEBUG("Key not found: %s", m_keypath);
        return false;
    }
    fclose(f);

    f = fopen(m_certpath.c_str(), "r");
    if (!f)
    {
        LOG_DEBUG("Cert not found: %s", m_certpath);
        return false;
    }

    X509* cert = PEM_read_X509(f, NULL, NULL, NULL);
    fclose(f);
    if (!cert)
    {
        LOG_DEBUG("Cert can't be parsed");
        return false;
    }
    //TODO: Check if cert is valid

    return true;
}

void BridgeServer::GenerateKey()
{
    LOG_DEBUG("Generating new key pair");
    BIGNUM* e = BN_new();
    BN_set_word(e, 3);
    RSA* rsa = RSA_new();
    EVP_PKEY* pkey = nullptr;
    int generated = RSA_generate_key_ex(rsa, 2048, e, nullptr);
    
    if (!generated)
    {
        BN_free(e);
        LOG_ERROR("Failed to generate RSA key");
        return;
    }
    pkey = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey, rsa);
    if (!pkey)
    {
        BN_free(e);
        RSA_free(rsa);
        LOG_ERROR("Failed to generate private key");
        return;
    }
    X509* x509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(x509), 1);
    X509_gmtime_adj(X509_get_notBefore(x509), 0);
    X509_gmtime_adj(X509_get_notAfter(x509), 315360000L);
    X509_set_pubkey(x509, pkey);
    X509_NAME* name = X509_get_subject_name(x509);
    X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC, (unsigned char*)"XX", -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "O", MBSTRING_ASC, (unsigned char*)"Company", -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC, (unsigned char*)"localhost", -1, -1, 0);
    X509_set_issuer_name(x509, name);
    X509_sign(x509, pkey, EVP_sha256());
    FILE* f = fopen(m_keypath.c_str(), "wb");
    PEM_write_PrivateKey(f, pkey, nullptr, nullptr, 10, nullptr, nullptr);
    fclose(f);
    f = fopen(m_certpath.c_str(), "wb");
    PEM_write_X509(f, x509);
    fclose(f);
    X509_free(x509);
    EVP_PKEY_free(pkey);
    BN_free(e);
}

void BridgeServer::Start()
{
    m_threadRunning = false;
    m_connectionState = DISCONNECTED;

    if (!m_ssl_ctx || !m_ssl_ctx->ctx)
        return;

    if (!CheckExistingKey())
    {
        if (!m_generateCerts)
        {
            LOG_ERROR("Private key not found. If you want to generate self-signed certificates set NWNX_BRIDGE_SELFSIGN_CERT=1");
            return;
        }
        GenerateKey();
    }

    SSL_CTX_set_ecdh_auto(ssl_ctx, 1);
    if (SSL_CTX_use_certificate_file(m_ssl_ctx->ctx, m_certpath.c_str(), SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stderr);
        return;
    }

    if (SSL_CTX_use_PrivateKey_file(m_ssl_ctx->ctx, m_keypath.c_str(), SSL_FILETYPE_PEM) <= 0)
    {
        ERR_print_errors_fp(stderr);
        return;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(m_portname.c_str()));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    SocketWrapper serverSocket;

    serverSocket.sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket.sock < 0)
    {
        LOG_ERROR("Unable to create socket");
        return;
    }
    if (fcntl(serverSocket.sock, F_SETFL, fcntl(serverSocket.sock, F_GETFL) | O_NONBLOCK) == -1)
    {
        LOG_ERROR("Unable to set non-blocking mode on socket");
        return;
    }
    if (bind(serverSocket.sock, (struct sockaddr*) & addr, sizeof(addr)) < 0)
    {
        LOG_ERROR("Unable to bind socket");
        return;
    }
    if (listen(serverSocket.sock, 1) < 0)
    {
        LOG_ERROR("Unable to listen on socket");
        return;
    }

    LOG_INFO("Server started. Waiting for connections...");

    m_ownServerId = serverSocket.sock;

    uint len = sizeof(addr);
    fd_set socketSet;
    static int lastSocket, activeSockets;
    struct timeval setTimeout = { 0, SELECT_TIMEOUT };

    clientSockets.clear();
    int err = 0;
    m_threadRunning = true;
    m_connectionState = CONNECTED;
    //Queue event to grab player list from nwserver thread
    QueueIncomingEvent(std::make_unique<ServerInfoRequestMessage>());

    while (m_threadRunning)
    {
        FD_ZERO(&socketSet);
        FD_SET(serverSocket.sock, &socketSet);
        lastSocket = serverSocket.sock;

        for (auto& c : clientSockets)
        {
            FD_SET(c.clientSocket, &socketSet);
            if (c.clientSocket > lastSocket)
                lastSocket = c.clientSocket;
        }

        errno = 0;
        setTimeout.tv_usec = SELECT_TIMEOUT;
        setTimeout.tv_sec = 0;
        activeSockets = select(lastSocket + 1, &socketSet, nullptr, nullptr, &setTimeout);

        if(activeSockets < 0 && errno != EINTR) {
            LOG_ERROR("Select error: %d - %d", activeSockets, errno);
            continue;
        }

        if (auto event = GetOutgoingEvent())
        {
            LOG_DEBUG("DEBUG ServerLoop(): %s", event->type);
            event->origin = m_ownServerId;
            if (HandleOutgoingEvent(event))
            {
                RelayMessage(std::move(event));
            }
        }

        if (!activeSockets)
            continue;

        if (FD_ISSET(serverSocket.sock, &socketSet))
        {
            LOG_DEBUG("New connection incoming");
            int client = accept(serverSocket.sock, (struct sockaddr*) & addr, &len);
            if (client < 0)
            {
                LOG_ERROR("Unable to accept incoming connection");
                continue;
            }
            int opt = 1;
            setsockopt(client, IPPROTO_TCP, TCP_NODELAY, (char*)&opt, sizeof(opt));

            clientSockets.emplace_back(m_ssl_ctx->ctx, client);
            auto& c = clientSockets.back();
            c.state = SSL_PENDING;
        }

        for (int i = clientSockets.size()-1; i >= 0; i--)
        {
            auto& c = clientSockets[i];
            LOG_DEBUG("Checking client: %d | state: %d", c.clientSocket, c.state);
            if (FD_ISSET(c.clientSocket, &socketSet))
            {
                LOG_DEBUG("Client socket ready to receive: %d | state: %d", c.clientSocket, c.state);
                switch (c.state)
                {
                    case SSL_PENDING:
                        if ((err = SSL_accept(c.clientSSL)) <= 0)
                        {
                            LOG_ERROR("SSL error: %i - %i", err, SSL_get_error(c.clientSSL, err));
                            ERR_print_errors_fp(stderr);
                        }
                        else
                        {
                            LOG_DEBUG("Handshake finished");
                            c.state = AUTH_PENDING;
                        }
                        break;
                    case AUTH_PENDING:
                    {
                        int ret = ReadFromSocket(c);
                        if (ret == 0)
                            continue;
                        if (ret < 0)
                        {
                            LOG_DEBUG("Connection to server %d closed", c.clientSocket);
                            clientSockets.erase(clientSockets.begin() + i);
                            continue;
                        }

                        std::unique_ptr<Message> request = c.GetMessage();
                        if (auto* r = dynamic_cast<AuthRequest*>(request.get()))
                        {
                            bool refused = !m_password.empty() && m_password != r->password;
                            auto response = AuthResponse(refused?0:1, refused?-1:c.clientSocket, refused?"Invalid password": "").GetSerializedMessage();
                            if (WriteToSocket(c, response) < 1)
                            {
                                LOG_DEBUG("Couldn't send AuthResponse to client: %d", c.clientSocket);
                                refused = true;
                            }
                            if (refused)
                            {
                                LOG_DEBUG("Client sent a wrong password: %d", c.clientSocket);
                                clientSockets.erase(clientSockets.begin() + i);
                                continue;
                            }
                            LOG_DEBUG("Client connected: %d", c.clientSocket);
                            c.state = CONNECTED;

                            ServerListMessage serverList;
                            {
                                std::scoped_lock<std::mutex> lock(m_serverList.mutex);
                                serverList.servers = m_serverList.servers;
                            }
                            SendMessage(c, serverList);
                            ServerInfoRequestMessage msg;
                            SendMessage(c, msg);
                        }
                        else
                        {
                            LOG_ERROR("Client sent unknown message when AuthRequest was expected");
                            clientSockets.erase(clientSockets.begin() + i);
                            continue;
                        }
                        break;
                    }
                    case CONNECTED:
                    {
                        int ret = ReadFromSocket(c);
                        if (ret == 0)
                            continue;
                        if (ret < 0)
                        {
                            int clientSocket = c.clientSocket;
                            LOG_DEBUG("Connection to client %d closed", clientSocket);
                            clientSockets.erase(clientSockets.begin() + i);
                            auto msg = std::unique_ptr<ServerDisconnectMessage>(new ServerDisconnectMessage(clientSocket));
                            msg->origin = clientSocket;
                            BroadcastMessage(std::move(msg));
                            continue;
                        }

                        std::unique_ptr<Message> msg = c.GetMessage();
                        if (msg)
                        {
                            msg->origin = c.clientSocket;
                            RelayMessage(std::move(msg));
                        }
                        else
                        {
                            LOG_ERROR("Couldn't retrieve message from client %d", c.clientSocket);
                        }
                        break;
                    }
                    default:
                        //Unknown state?
                        break;
                }
            }
        }
    }

    m_connectionState = DISCONNECTED;
    m_threadRunning = false;
}

int BridgeServer::BroadcastMessage(std::unique_ptr<Message> msg)
{
    if (!msg)
        return false;

    //Send messages to remote servers
    auto ss = msg->GetSerializedMessage();
    bool sent = false;
    for (auto& c : clientSockets)
    {
        if (msg->destination == -1 || msg->destination == c.clientSocket)
            if (c.state >= CONNECTED && msg->origin != c.clientSocket)
            {
                LOG_DEBUG("Sending message (%d) to client %d", msg->type, c.clientSocket);
                sent |= SendMessage(c, *msg.get()) > 0;
            }
    }

    //Relay messages directly to the client instance
    if (msg->destination == m_ownServerId || msg->destination == -1)
    {
        if (msg->origin != m_ownServerId)
        {
            sent |= true;
            HandleIncomingMessage(std::move(msg));
        }
    }

    return sent;
}

BridgeServer::~BridgeServer()
{
    
}

bool BridgeClient::IsConnected()
{
    return m_threadRunning && m_connectionState >= CONNECTED;
}

void BridgeClient::Start()
{
    m_threadRunning = false;
    m_connectionState = DISCONNECTED;
    m_ssl = nullptr;

    if (!m_ssl_ctx->ctx)
        return;

    SocketWrapper socketWrapper;
    addrinfo hints, *addr;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = 0;
    int err = 0;

    if ((err = getaddrinfo(m_hostname.c_str(), m_portname.c_str(), &hints, &addr)))
    {
        LOG_ERROR("Can't resolve server name: %s:%s", m_hostname, m_portname);
        LOG_ERROR("%s", gai_strerror(err));
        return;
    }
    m_threadRunning = true;

    addrinfo* a = addr;
    socketWrapper.sock = socket(a->ai_family, a->ai_socktype, a->ai_protocol);
    if (socketWrapper.sock == -1)
    {
        LOG_ERROR("Error trying to create socket");
        return;
    }

    int opt = 1;
    if (setsockopt(socketWrapper.sock, IPPROTO_TCP, TCP_NODELAY, (char*)&opt, sizeof(opt)) < 0)
    {
        LOG_ERROR("Error setting socket options");
        return;
    }

    fd_set socketSet;
    static int lastSocket, activeSockets;
    struct timeval setTimeout = { 0, SELECT_TIMEOUT };

    while(m_threadRunning)
    {
        if (m_connectionState < CONNECTED)
        {
            switch (m_connectionState)
            {
                case DISCONNECTED:
                    m_serverList.servers.clear();
                    while (!m_inque.empty())
                        m_inque.pop();
                    while (!m_outque.empty())
                        m_outque.pop();
                    LOG_DEBUG("Trying to connect to server %s:%s", m_hostname, m_portname);
                    m_connectionState = CONNECTING;
                    break;
                case CONNECTING:
                    if ((err = connect(socketWrapper.sock, (struct sockaddr*) a->ai_addr, a->ai_addrlen)))
                    {
                        a = a->ai_next;
                        if (!a)
                            a = addr;
                    }
                    else
                    {
                        m_connectionState = SSL_PENDING;
                        fcntl(socketWrapper.sock, F_SETFL, fcntl(socketWrapper.sock, F_GETFL) | O_NONBLOCK);
                        m_ssl = std::make_unique<SSLWrapper>(m_ssl_ctx->ctx, socketWrapper.sock);
                        LOG_DEBUG("Socket connection established");
                    }
                    break;
                case SSL_PENDING:
                {
                    //TODO: Remote cert validation (share cert chain for self-signed certs?)
                    const int status = SSL_connect(m_ssl->clientSSL);
                    if (status != 1)
                    {
                        if (status == -1)
                        {
                            switch ((err = SSL_get_error(m_ssl->clientSSL, status)))
                            {
                                case SSL_ERROR_WANT_READ:
                                case SSL_ERROR_WANT_WRITE:
                                    usleep(100000);
                                    continue;
                                case SSL_ERROR_ZERO_RETURN:
                                case SSL_ERROR_SSL:
                                default:
                                    LOG_ERROR("SSL_connect failed with SSL_get_error(): %d - %d\n", status, err);
                                    return;
                            }
                        }
                        ERR_print_errors_fp(stderr);
                        LOG_ERROR("SSL_connect failed with SSL_get_error(): %d - %d\n", status, SSL_get_error(m_ssl->clientSSL, status));
                        return;
                    }
                    LOG_DEBUG("Connected using %s encryption", SSL_get_cipher(m_ssl->clientSSL));

                    std::stringstream req = AuthRequest(m_password).GetSerializedMessage();
                    if (WriteToSocket(*m_ssl.get(), req) < 1)
                    {
                        LOG_ERROR("Error sending auth message");
                        return;
                    }
                    m_connectionState = AUTH_PENDING;
                    break;
                }
                case AUTH_PENDING:
                    if (ReadFromSocket(*m_ssl.get()) > 0)
                    {
                        auto msg = m_ssl->GetMessage();
                        if (auto* r = dynamic_cast<AuthResponse*>(msg.get()))
                        {
                            if (r->value == 1)
                            {
                                m_ownServerId = r->id;
                                LOG_INFO("Connected to %s:%s", m_hostname, m_portname);
                                m_connectionState = CONNECTED;
                            }
                            else
                            {
                                LOG_ERROR("Connection refused. Reason: %s", r->response);
                                return;
                            }
                        }
                        else
                        {
                            LOG_ERROR("Received unknown message while expecting AuthResponse");
                            return;
                        }
                    }
                    break;
            }
            usleep(500000);
            continue;
        }

        FD_ZERO(&socketSet);
        FD_SET(m_ssl->clientSocket, &socketSet);
        lastSocket = m_ssl->clientSocket;

        errno = 0;
        setTimeout.tv_usec = SELECT_TIMEOUT;
        setTimeout.tv_sec = 0;
        activeSockets = select(lastSocket + 1, &socketSet, nullptr, nullptr, &setTimeout);

        if (auto event = GetOutgoingEvent())
        {
            LOG_DEBUG("DEBUG ClientLoop(): %s", event->type);
            if (HandleOutgoingEvent(event))
            {
                auto ss = event->GetSerializedMessage();
                WriteToSocket(*m_ssl.get(), ss);
            }

        }

        if (activeSockets < 0 && errno != EINTR)
        {
            LOG_ERROR("Select error: %d - %d", activeSockets, errno);
            //TODO: Test if detach/join called and return
            continue;
        }

        if (!activeSockets)
            continue;

        int ret = ReadFromSocket(*m_ssl.get());
        if (ret == 0)
            continue;
        if (ret < 0)
        {
            LOG_INFO("Connection to server closed");
            return;
        }

        if (auto msg = m_ssl->GetMessage())
        {
            LOG_DEBUG("Message received: %d", msg->type);
            HandleIncomingMessage(std::move(msg));
        }
        else
        {
            LOG_ERROR("Couldn't retrieve message from server");
        }

    }
}

//Called from server thread
//Process messages before they are relayed to other servers
int BridgeServer::RelayMessage(std::unique_ptr<Message> m)
{
    if (!m)
        return 0;

    LOG_DEBUG("Relaying message %d from %d", m->type, m->origin);

    switch (m->type)
    {
        case SERVER_INFO:
            if (auto l = dynamic_cast<ServerInfoMessage*>(m.get()))
            {
                LOG_DEBUG("Checking serverinfo before relaying: %d | %s", l->origin, l->name);
            }
            break;
        default:
            return BroadcastMessage(std::move(m));
    }
    return 1;
}

//Called from client auxiliary thread
//Process outgoing messages before they are sent to the master server
int BridgeClient::HandleOutgoingEvent(std::unique_ptr<Message>& msg)
{
    if (!msg)
        return 0;

    msg->origin = m_ownServerId;

    switch (msg->type)
    {
        //Save own server info that is being sent
        case PLAYER_INFO:
            if (auto l = dynamic_cast<PlayerInfoMessage*>(msg.get()))
            {
                AddPlayerToServerList(*l);

            }
            else
            {
                LOG_DEBUG("Can't cast message to PlayerInfoMessage");
            }
            break;
        case PLAYER_DISCONNECT:
            if (auto m = dynamic_cast<PlayerDisconnectMessage*>(msg.get()))
            {
                RemovePlayerFromServerList(*m);
            }
            else
            {
                LOG_DEBUG("Can't cast message to PlayerDisconnectMessage");
            }
            break;
        case SERVER_INFO:
            if (auto l = dynamic_cast<ServerInfoMessage*>(msg.get()))
            {
                AddServerToServerList(*l);
            }
            else
            {
                LOG_DEBUG("Can't cast message to ServerInfoMessage");
            }
            break;
        default:
            break;
    }
    
    return 1;
}

//Called from nwserver thread ( CServerExoApp::MainLoop() )
//Messages meant to be handled by nwserver thread are processed here
int BridgeClient::HandleIncomingEvent(std::unique_ptr<Message> msg)
{
    if (!msg)
        return 0;

    LOG_DEBUG("Processing event %d from %d", msg->type, msg->origin);

    auto ss = msg->GetSerializedMessage();
    switch (msg->type)
    {
        case CUSTOM_MESSAGE:
            if (auto m = dynamic_cast<CustomMessage*>(msg.get()))
            {
                LOG_DEBUG("Received a custom message from %d. Content: %s", m->origin, m->str);
            }
            break;
        case RUN_SCRIPT:
            if (auto m = dynamic_cast<RunScriptMessage*>(msg.get()))
            {
                if (m->isChunk)
                {
                    LOG_DEBUG("Executing chunk in nwserver thread: %s", m->script);
                    auto ret = Globals::VirtualMachine()->RunScriptChunk(m->script, Constants::OBJECT_INVALID, false, m->mainWrapped);
                    LOG_DEBUG("Executed chunk in nwserver thread with return value: %d", ret);
                }
                else
                {
                    CExoString script = CExoString(m->script);
                    Globals::VirtualMachine()->RunScript(&script, Constants::OBJECT_INVALID, false);
                }
            }
            else
            {
                LOG_ERROR("Received RUN_SCRIPT from %d that can't be read", m->origin);
            }
            break;
        case PLAYER_INFO:
            if (auto m = dynamic_cast<PlayerInfoMessage*>(msg.get()))
            {
                LOG_DEBUG("Nwserver thread: Received new player info: %s", m->player.id);
                Hooks::BroadcastFakePlayerAdd(m->player.id, m->player.playername, m->player.oid, m->player.firstName, m->player.lastName, m->player.isDM, m->origin);
            }
            else
            {
                LOG_ERROR("Can't cast message to PlayerInfoMessage");
            }
            break;
        case PLAYER_DISCONNECT:
            if (auto m = dynamic_cast<PlayerDisconnectMessage*>(msg.get()))
            {
                LOG_DEBUG("Nwserver thread: Received player disconnection");
                Hooks::BroadcastFakePlayerDelete(m->id, m->origin);
            }
            else
            {
                LOG_ERROR("Can't cast message to PlayerDisconnectMessage");
            }
            break;
        case SERVER_DISCONNECT:
        case SERVER_INFO:
            LOG_DEBUG("Nwserver thread: Server (dis)connected. Full playerlist updates required");
            Hooks::ResendAllPlayerLists();
            break;
        case SERVER_LIST:
            LOG_DEBUG("Nwserver thread: New server list received. Full playerlist updates required");
            Hooks::ResendAllPlayerLists();
            break;
        case SERVER_INFO_REQUEST:
        {
            Hooks::SendPlayerList();
            break;
        }
        case CHAT_MESSAGE:
            if (auto m = dynamic_cast<ChatMessage*>(msg.get()))
            {
                PlayerInfo* playerInfo = nullptr;
                {
                    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
                    LOG_DEBUG("Nwserver thread: Received chat message from %d (%d)", m->speakerId, m->origin);
                    auto serverInfo = m_serverList.GetServerInfo(m->origin);//Maybe use ((m->speakerId & 0xFFFF00u) >> 8u)
                    if (!serverInfo)
                    {
                        LOG_DEBUG("Nwserver thread: Can't find origin server info");
                        break;
                    }
                    playerInfo = serverInfo->GetPlayerInfo(m->speakerId & 0xFFu);
                    if (!playerInfo)
                    {
                        LOG_DEBUG("Nwserver thread: Can't find speaker info");
                        break;
                    }
                }
                Hooks::SendFakeChatMessage(m->message, m->targetId, playerInfo, (Constants::MessageChatMinor::TYPE) m->channel);
            }
            else
            {
                LOG_ERROR("Can't cast message to ChatMessage");
            }
            break;
        default:
            LOG_DEBUG("Received a message from %d.", msg->origin);
            break;
    }

    return 1;
}

int BridgeClient::ReadFromSocket(SSLWrapper& s)
{
    static char buffer[READ_BUFFER_SIZE + 1];
    auto& readBuffer = *s.readBuffer;

    if (readBuffer.length < 0)
    {
        errno = 0;
        s.readBuffer->bytesRead = 0;
        int bytesRead = SSL_read(s.clientSSL, buffer, 4);
        if (bytesRead < 0)
        {
            switch ((errno = SSL_get_error(s.clientSSL, bytesRead)))
            {
                case SSL_ERROR_WANT_READ:
                case SSL_ERROR_WANT_WRITE:
                    return 0;
                case SSL_ERROR_ZERO_RETURN:
                case SSL_ERROR_SSL:
                    return -1;
                default:
                    LOG_ERROR("SSL_read() error, SSL_get_error(): %d", errno);
                    return -1;
            }
        }
        else
        {
            if (bytesRead != 4)
            {
                return -1;
            }
        }
        readBuffer.length = ntohl(*(uint32_t*)buffer);
        if (readBuffer.length < 1)
        {
            readBuffer.length = -1;
        }
        readBuffer.buf.str(std::string());
    }

    int bytesRead = 0, remaining;
    while (readBuffer.bytesRead < readBuffer.length)
    {
        errno = 0;
        remaining = readBuffer.length - readBuffer.bytesRead;
        bytesRead = SSL_read(s.clientSSL, buffer, remaining > READ_BUFFER_SIZE ? READ_BUFFER_SIZE : remaining);
 
        if (bytesRead < 1)
        {
            switch ((errno = SSL_get_error(s.clientSSL, bytesRead)))
            {
                case SSL_ERROR_WANT_READ:
                case SSL_ERROR_WANT_WRITE:
                    return 0;
                case SSL_ERROR_ZERO_RETURN:
                case SSL_ERROR_SSL:
                    return -1;
                default:
                    LOG_ERROR("SSL_read() error, SSL_get_error(): %d", errno);
                    return -1;
            }
        }

        readBuffer.bytesRead += bytesRead;
        readBuffer.buf.write(buffer, bytesRead);
    }
    readBuffer.bytesRead = 0;
    readBuffer.length = -1;
    return 1;
}

int BridgeClient::SendMessage(SSLWrapper& s, std::stringstream& ss)
{
    if (WriteToSocket(s, ss) < 1)
    {
        LOG_ERROR("Couldn't send message to client: %d", s.clientSocket);
        return 0;
    }
    return 1;
}

int BridgeClient::SendMessage(SSLWrapper& s, Message& msg)
{
    auto ss = msg.GetSerializedMessage();
    if (WriteToSocket(s, ss) < 1)
    {
        LOG_ERROR("Couldn't send message (type %d) to client: %d", msg.type, s.clientSocket);
        return 0;
    }
    return 1;
}

int BridgeClient::WriteToSocket(SSLWrapper& s, std::stringstream& ss)
{
    static char buffer[READ_BUFFER_SIZE + 1];
    int sent = 0;

    const std::string& message = ss.str();
    if (message.empty())
    {
        return 0;
    }

    const char* msg = message.c_str();
    *((int*)buffer) = htonl(message.size());
    errno = 0;
    sent = SSL_write(s.clientSSL, buffer, sizeof(uint32_t));
    if(sent < 1)
    {
        errno = SSL_get_error(s.clientSSL, sent);
        LOG_DEBUG("Failed to send message length header. Size: %d | SSL_write() error: %d", message.size(), errno);
        switch (errno)
        {
            case SSL_ERROR_WANT_READ:
            case SSL_ERROR_WANT_WRITE:
                return 0;
            case SSL_ERROR_ZERO_RETURN:
            case SSL_ERROR_SSL:
                return -1;
            default:
                LOG_ERROR("SSL_send() error, SSL_get_error(): %d", errno);
                return -1;
        }
    }
    LOG_DEBUG("Sending %d bytes", message.size());

    sent = SSL_write(s.clientSSL, msg, message.size());
    //TODO: Loop to ensure all bytes are buffered/sent
    if (sent < (int) message.size())
        return -1;
    else
        return sent;
}

std::unique_ptr<Message> SSLWrapper::GetMessage()
{
    try
    {
        std::unique_ptr<Message> event;
        {
            cereal::PortableBinaryInputArchive input(readBuffer->buf);
            input(event);
        }
        if (!event)
            LOG_DEBUG("De-serialization failed.");

        return event;
    }
    catch (cereal::Exception & e)
    {
        LOG_ERROR("Received a serialized message that can't be read. Error message: %s", e.what());
    }
    return nullptr;
}

void BridgeClient::QueueIncomingEvent(std::unique_ptr<Message> msg)
{
    std::scoped_lock<std::mutex> lock(m_inqueMutex);
    m_inque.push(std::move(msg));
}

void BridgeClient::QueueOutgoingEvent(std::unique_ptr<Message> msg)
{
    std::scoped_lock<std::mutex> lock(m_outqueMutex);
    m_outque.push(std::move(msg));
}

std::unique_ptr<Message> BridgeClient::GetIncomingEvent()
{
    if (m_inque.empty())
        return nullptr;
    std::scoped_lock<std::mutex> lock(m_inqueMutex);
    if (m_inque.empty())
        return nullptr;
    std::unique_ptr<Message> ret = std::move(m_inque.front());
    m_inque.pop();
    return std::move(ret);
}

std::unique_ptr<Message> BridgeClient::GetOutgoingEvent()
{
    if (m_outque.empty())
        return nullptr;
    std::scoped_lock<std::mutex> lock(m_outqueMutex);
    if (m_outque.empty())
        return nullptr;
    std::unique_ptr<Message> ret = std::move(m_outque.front());
    m_outque.pop();
    return std::move(ret);
}

//Called from client thread
//Messages meant to be handled by auxiliary thread are processed here
//Messages meant to be handled by nwserver are forwarded (queued)
int BridgeClient::HandleIncomingMessage(std::unique_ptr<Message> msg)
{
    if (!msg)
        return -1;
    LOG_DEBUG("Received message %d from %d", msg->type, msg->origin);

    switch (msg->type)
    {
        case PLAYER_INFO:
            if (auto l = dynamic_cast<PlayerInfoMessage*>(msg.get()))
            {
                AddPlayerToServerList(*l);
                QueueIncomingEvent(std::move(msg));
            }
            else
            {
                LOG_DEBUG("Can't cast message to PlayerInfoMessage");
            }
            break;
        case PLAYER_DISCONNECT:
            if (auto m = dynamic_cast<PlayerDisconnectMessage*>(msg.get()))
            {
                RemovePlayerFromServerList(*m);
                QueueIncomingEvent(std::move(msg));
            }
            else
            {
                LOG_DEBUG("Can't cast message to PlayerDisconnectMessage");
            }
            break;
        case SERVER_DISCONNECT:
            if (auto m = dynamic_cast<ServerDisconnectMessage*>(msg.get()))
            {
                RemoveServerFromServerList(*m);
                QueueIncomingEvent(std::move(msg));
            }
            else
            {
                LOG_DEBUG("Can't cast message to ServerDisconnectMessage");
            }
            break;
        case CUSTOM_MESSAGE:
            if (auto m = dynamic_cast<CustomMessage*>(msg.get()))
            {
                LOG_DEBUG("ClientThread: Received custom message: %s", m->str);
                QueueIncomingEvent(std::move(msg));
            }
            break;
        case SERVER_LIST:
            if (auto l = dynamic_cast<ServerListMessage*>(msg.get()))
            {
                ReplaceServerList(*l);
                QueueIncomingEvent(std::move(msg));
            }
            else
            {
                LOG_DEBUG("Can't cast message to ServerListMessage");
                return 0;
            }
            break;
        case SERVER_INFO:
            if (auto l = dynamic_cast<ServerInfoMessage*>(msg.get()))
            {
                AddServerToServerList(*l);
                QueueIncomingEvent(std::move(msg));
            }
            else
            {
                LOG_DEBUG("Can't cast message to ServerInfoMessage");
            }
            break;
        case INVALID_MESSAGE:
            break;
        default:
            QueueIncomingEvent(std::move(msg));
            break;
    }
    return 1;
}

void BridgeClient::Run()
{
    m_thread = std::make_unique<std::thread>(std::thread([this]()
        {
            SSL_load_error_strings();
            OpenSSL_add_ssl_algorithms();

            m_ssl_ctx = std::make_unique<SSLCtxWrapper>(dynamic_cast<BridgeServer*>(this));
            if (!m_ssl_ctx || !m_ssl_ctx->ctx)
            {
                LOG_ERROR("Can't create SSL context");
                ERR_print_errors_fp(stderr);
                return;
            }

            try
            {
                do
                {
                    Start();
                    m_connectionState = DISCONNECTED;
                } while (m_threadRunning);
            }
            catch (...)
            {
                //Catch-all for testing/debuging purposes
                std::exception_ptr e = std::current_exception();
                LOG_ERROR("Exception thrown from server thread: %s", e.__cxa_exception_type()->name());
            }
            m_threadRunning = false;
            m_connectionState = DISCONNECTED;
            m_ssl = nullptr;
            m_ssl_ctx = nullptr;
        }
    ));
}

void BridgeClient::Stop()
{
    m_threadRunning = false;
    if (m_thread)
    {
        //m_thread->detach();
        m_thread->join();
        m_thread = nullptr;
    }
}

int BridgeClient::GetId()
{
    return m_ownServerId;
}

BridgeClient::BridgeClient(std::string hostname, std::string portname, std::string password) : m_hostname(hostname), m_portname(portname), m_password(password)
{

}

BridgeClient::~BridgeClient()
{
    Stop();
}

SSLWrapper::SSLWrapper(SSL_CTX* context, int sock)
{
    clientSocket = sock;
    clientSSL = SSL_new(context);
    SSL_set_fd(clientSSL, clientSocket);
}
SSLWrapper::~SSLWrapper()
{
    SSL_shutdown(clientSSL);
    SSL_free(clientSSL);
    close(clientSocket);
}

SSLCtxWrapper::SSLCtxWrapper(bool isServer)
{
    ctx = SSL_CTX_new(isServer ? TLS_server_method() : TLS_client_method());
}

SSLCtxWrapper::~SSLCtxWrapper()
{
    if (ctx) SSL_CTX_free(ctx);
}

SocketWrapper::~SocketWrapper()
{
    if (sock != -1) close(sock);
}

void BridgeClient::AddPlayerToServerList(const PlayerInfoMessage& msg)
{
    auto* serverInfo = m_serverList.GetServerInfo(msg.origin);
    if (!serverInfo)
    {
        LOG_DEBUG("Received player connect message from unknown server %d. Creating server info", msg.origin);
        ServerInfo info;
        info.id = msg.origin;
        info.name = "Unknown server";
        serverInfo = m_serverList.AddServerInfo(info);
    }

    LOG_DEBUG("Updating player %d from server %d with name %s and oid %#010x", msg.player.id, msg.origin, msg.player.playername, msg.player.oid);
    auto* playerInfo = serverInfo->GetPlayerInfo(msg.player.id);
    if (!playerInfo)
    {
        LOG_DEBUG("New player %d added to server %d with name %s", msg.player.id, msg.origin, msg.player.playername);
        playerInfo = serverInfo->AddPlayerInfo(msg.player);
    }
    playerInfo->id = msg.player.id;
    playerInfo->oid = msg.player.oid;
    playerInfo->firstName = msg.player.firstName;
    playerInfo->lastName = msg.player.lastName;
    playerInfo->isDM = msg.player.isDM;
    playerInfo->playername = msg.player.playername;
}

void BridgeClient::AddServerToServerList(const ServerInfoMessage& msg)
{
    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
    auto* serverInfo = m_serverList.GetServerInfo(msg.origin);
    if (!serverInfo)
    {
        ServerInfo newServer;
        serverInfo = m_serverList.AddServerInfo(newServer);
    }
    LOG_DEBUG("Updating server %d info: %s", msg.origin, msg.name);
    serverInfo->players = msg.players;
    serverInfo->name = msg.name;
    serverInfo->id = msg.origin;
}

void BridgeClient::RemovePlayerFromServerList(const PlayerDisconnectMessage& msg)
{
    LOG_DEBUG("Received disconnect event for playerid %d from server %d", msg.id, msg.origin);
    {
        std::scoped_lock<std::mutex> lock(m_serverList.mutex);
        if (auto* serverInfo = m_serverList.GetServerInfo(msg.origin))
        {
            if (serverInfo->RemovePlayerInfo(msg.id))
            {
                LOG_DEBUG("Client %d disconnected from server %d", msg.id, msg.origin);
            }
            else
            {
                LOG_DEBUG("Received player disconnect message for an unknown player: %d (%d)", msg.id, msg.origin);
            }
        }
        else
        {
            LOG_DEBUG("Received player disconnect message from an unknown server: %d", msg.origin);
        }
    }
}

void BridgeClient::RemoveServerFromServerList(const ServerDisconnectMessage& msg)
{
    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
    m_serverList.RemoveServerInfo(msg.id);
}

void BridgeClient::ReplaceServerList(const ServerListMessage& msg)
{
    LOG_DEBUG("Received a full server list with %d servers", msg.servers.size());
    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
    m_serverList.servers = msg.servers;
}

std::vector<ServerInfo> BridgeClient::GetServerList()
{
    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
    return m_serverList.servers;
}
std::optional<std::vector<PlayerInfo>> BridgeClient::GetPlayerList(uint32_t serverId)
{
    std::scoped_lock<std::mutex> lock(m_serverList.mutex);
    for (auto& s : m_serverList.servers)
    {
        if (s.id == serverId)
            return s.players;
    }
    return {};
}

}