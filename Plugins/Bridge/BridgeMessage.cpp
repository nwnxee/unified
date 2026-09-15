#include "BridgeMessage.hpp"

namespace Bridge
{

Message::Message(int origin, int destination, MessageType type) : origin(origin), destination(destination), type(type)
{}

std::stringstream Message::GetSerializedMessage()
{
    std::stringstream ss(std::ios::binary | std::ios::out | std::ios::in);
    std::unique_ptr<Message> request(this);
    {
        cereal::PortableBinaryOutputArchive output(ss);
        output(request);
    }
    request.release();
    return std::move(ss);
}

CustomMessage::CustomMessage(std::string str) : str(std::move(str))
{
    type = CUSTOM_MESSAGE;
}

AuthRequest::AuthRequest(std::string password) : password(std::move(password))
{
    type = AUTH_REQUEST;
}

AuthResponse::AuthResponse(int value, int id, std::string response) : value(value), id(id), response(std::move(response))
{
    type = AUTH_RESPONSE;
}

RunScriptMessage::RunScriptMessage(std::string script, std::string content, bool isChunk, bool mainWrapped) :
    script(std::move(script)), content(std::move(content)), isChunk(isChunk), mainWrapped(mainWrapped)
{
    type = RUN_SCRIPT;
}

ServerInfo* ServerList::GetServerInfo(int serverId)
{
    for (auto& s : servers)
        if (s.id == (uint32_t) serverId)
            return &s;
    return nullptr;
}

ServerInfo* ServerList::AddServerInfo(ServerInfo& serverInfo)
{
    servers.push_back(serverInfo);
    return &servers.back();
}

bool ServerList::RemoveServerInfo(int serverId)
{
    for (auto it = servers.begin(); it != servers.end(); it++)
    {
        if (it->id == (uint32_t) serverId)
        {
            servers.erase(it);
            return true;
        }
    }
    return false;
}

PlayerInfo* ServerInfo::GetPlayerInfo(int playerId)
{
    for (auto& p : players)
        if (p.id == (uint32_t) playerId)
            return &p;
    return nullptr;
}


PlayerInfo* ServerInfo::AddPlayerInfo(const PlayerInfo& playerInfo)
{
    players.push_back(playerInfo);
    return &players.back();
}

bool ServerInfo::RemovePlayerInfo(int playerId)
{
    for (auto it = players.begin(); it != players.end(); it++)
    {
        if (it->id == (uint32_t) playerId)
        {
            players.erase(it);
            return true;
        }
    }
    return false;
}

}

CEREAL_REGISTER_TYPE(Bridge::CustomMessage);
CEREAL_REGISTER_TYPE(Bridge::AuthRequest);
CEREAL_REGISTER_TYPE(Bridge::AuthResponse);
CEREAL_REGISTER_TYPE(Bridge::RunScriptMessage);
CEREAL_REGISTER_TYPE(Bridge::ServerListMessage);
CEREAL_REGISTER_TYPE(Bridge::ServerInfoMessage);
CEREAL_REGISTER_TYPE(Bridge::PlayerInfoMessage);
CEREAL_REGISTER_TYPE(Bridge::ServerDisconnectMessage);
CEREAL_REGISTER_TYPE(Bridge::PlayerDisconnectMessage);
CEREAL_REGISTER_TYPE(Bridge::ServerInfoRequestMessage);
CEREAL_REGISTER_TYPE(Bridge::ChatMessage);