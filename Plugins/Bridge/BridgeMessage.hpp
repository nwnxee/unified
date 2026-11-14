#pragma once
#include <string>
#include <mutex>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

namespace Bridge
{

struct PlayerInfo
{
    std::string playername;
    std::string firstName;
    std::string lastName;
    uint32_t id = -1;
    uint32_t oid = 0x7F000000;
    bool isDM = false;

    int GetServerId() { return (oid & 0xFFFF00)>>8; }
    int GetPlayerId() { return /*oid & 0xFF*/ id; }
    int GetXServerPlayerId() { return oid & 0xFFFFFF; }

    template<class Archive>
    void serialize(Archive& ar) { ar(playername, firstName, lastName, id, oid, isDM); }

    void serialize(cereal::JSONOutputArchive& ar)
    {
        ar(cereal::make_nvp("playerId", id), cereal::make_nvp("playerName", playername),
            cereal::make_nvp("firstName", firstName), cereal::make_nvp("lastName", lastName),
            cereal::make_nvp("DM", isDM));
    }
};

struct ServerInfo
{
    uint32_t id;
    std::string name;
    std::vector<PlayerInfo> players;

    PlayerInfo* GetPlayerInfo(int playerId);
    PlayerInfo* AddPlayerInfo(const PlayerInfo& playerInfo);
    bool RemovePlayerInfo(int playerId);

    template<class Archive>
    void serialize(Archive& ar) { ar(id, name, players); }

    void serialize(cereal::JSONOutputArchive& ar)
    {
        ar(cereal::make_nvp("serverId", id), cereal::make_nvp("serverName", name), cereal::make_nvp("players", players));
    }
};

struct ServerList
{
    std::vector<ServerInfo> servers;
    std::mutex mutex;

    ServerInfo* GetServerInfo(int serverId);
    ServerInfo* AddServerInfo(ServerInfo& serverInfo);
    bool RemoveServerInfo(int serverId);

    template<class Archive>
    void serialize(Archive& ar) { ar(servers); }
};

typedef enum
{
    INVALID_MESSAGE,
    CUSTOM_MESSAGE,
    AUTH_REQUEST,
    AUTH_RESPONSE,
    RUN_SCRIPT,
    SERVER_LIST,
    SERVER_INFO,
    PLAYER_INFO,
    SERVER_DISCONNECT,
    PLAYER_DISCONNECT,
    SERVER_INFO_REQUEST,
    CHAT_MESSAGE

} MessageType;

struct Message
{
    int origin = -1;
    int destination = -1;
    MessageType type = INVALID_MESSAGE;

    Message(int origin, int destination, MessageType type);
    Message() = default;
    virtual ~Message() = default;

    std::stringstream GetSerializedMessage();

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(origin, destination, type);
    }
};

struct CustomMessage : public Message
{
    std::string str;
    CustomMessage(std::string str);
    CustomMessage() { type = CUSTOM_MESSAGE; }
    ~CustomMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), str);
    }
};

struct AuthRequest : public Message
{
    std::string password = "";
    AuthRequest(std::string password);
    AuthRequest() { type = AUTH_REQUEST; }
    ~AuthRequest() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), password);
    }
};

struct AuthResponse : public Message
{
    int value = 0;
    int id = -1;
    std::string response = "";
    AuthResponse(int value, int id, std::string response);
    AuthResponse() { type = AUTH_RESPONSE; }
    ~AuthResponse() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), value, id, response);
    }
};

struct RunScriptMessage : public Message
{
    std::string script = "";
    std::string content = "";
    bool isChunk = true;
    bool mainWrapped = false;
    RunScriptMessage(std::string script, std::string content = "", bool isChunk = true, bool mainWrapped = false);
    RunScriptMessage() { type = RUN_SCRIPT; }
    ~RunScriptMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), script, content, isChunk, mainWrapped);
    }
};

struct ServerListMessage : public Message
{
    std::vector<ServerInfo> servers;
    ServerListMessage(std::vector<ServerInfo> servers) : servers(std::move(servers)) { type = SERVER_LIST; }
    ServerListMessage() { type = SERVER_LIST; }
    ~ServerListMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), servers);
    }
};

struct ServerInfoMessage : public Message
{
    std::vector<PlayerInfo> players;
    std::string name;
    ServerInfoMessage(std::string name, std::vector<PlayerInfo> players) : players(std::move(players)), name(std::move(name)) { type = SERVER_INFO; }
    ServerInfoMessage() { type = SERVER_INFO; }
    ~ServerInfoMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), players);
    }
};

struct PlayerInfoMessage : public Message
{
    PlayerInfo player;
    PlayerInfoMessage(PlayerInfo& player) : player(player) { type = PLAYER_INFO; }
    PlayerInfoMessage() { type = PLAYER_INFO; }
    ~PlayerInfoMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), player);
    }
};

struct ServerDisconnectMessage : public Message
{
    int id;
    ServerDisconnectMessage(int id) : id(id) { type = SERVER_DISCONNECT; }
    ServerDisconnectMessage() { type = SERVER_DISCONNECT; }
    ~ServerDisconnectMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), id);
    }
};

struct PlayerDisconnectMessage : public Message
{
    int id;
    int server;
    PlayerDisconnectMessage(int id, int server) : id(id), server(server) { type = PLAYER_DISCONNECT; }
    PlayerDisconnectMessage() { type = PLAYER_DISCONNECT; }
    ~PlayerDisconnectMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), id, server);
    }
};

struct ChatMessage : public Message
{
    uint32_t speakerId;
    uint32_t targetId;
    std::string message;
    uint32_t channel;
    
    ChatMessage(uint32_t speakerId, uint32_t targetId, std::string message, uint32_t channel) : speakerId(speakerId), targetId(targetId), message(std::move(message)), channel(channel) { type = CHAT_MESSAGE; }
    ChatMessage(uint32_t speakerId, std::string message, uint32_t channel) : ChatMessage(speakerId, -1, std::move(message), channel) {}
    ChatMessage() { type = CHAT_MESSAGE; }
    ~ChatMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), speakerId, targetId, message, channel);
    }
};

struct ServerInfoRequestMessage : public Message
{
    ServerInfoRequestMessage() { type = SERVER_INFO_REQUEST; }
    ~ServerInfoRequestMessage() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this));
    }
};

}