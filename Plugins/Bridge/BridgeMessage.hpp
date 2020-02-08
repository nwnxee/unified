#pragma once
#include <string>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/base_class.hpp>

namespace Bridge
{

typedef enum
{
    INVALID_MESSAGE,
    CUSTOM_MESSAGE,
    AUTH_REQUEST,
    AUTH_RESPONSE,
    RUN_SCRIPT

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
    std::string response = "";
    AuthResponse(int value, std::string response);
    AuthResponse() { type = AUTH_RESPONSE; }
    ~AuthResponse() override = default;

    template<class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::base_class<Message>(this), value, response);
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

}