#include "BridgeMessage.hpp"
#include <cereal/types/memory.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

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

AuthResponse::AuthResponse(int value, std::string response) : value(value), response(std::move(response))
{
    type = AUTH_RESPONSE;
}

RunScriptMessage::RunScriptMessage(std::string script, std::string content, bool isChunk, bool mainWrapped) :
    script(std::move(script)), content(std::move(content)), isChunk(isChunk), mainWrapped(mainWrapped)
{
    type = RUN_SCRIPT;
}

}

CEREAL_REGISTER_TYPE(Bridge::CustomMessage);
CEREAL_REGISTER_TYPE(Bridge::AuthRequest);
CEREAL_REGISTER_TYPE(Bridge::AuthResponse);
CEREAL_REGISTER_TYPE(Bridge::RunScriptMessage);