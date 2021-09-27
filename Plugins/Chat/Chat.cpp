#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSExpression.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerInfo.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static uint8_t s_ActiveChannel;
static std::string s_ActiveMessage;
static ObjectID s_ActiveSenderObjectId;
static ObjectID s_ActiveTargetObjectId;

static uint32_t s_Depth;
static bool s_SkipMessage;
static bool s_CustomHearingDistances;
static std::string s_ChatScript = Config::Get<std::string>("CHAT_SCRIPT", "");
static std::unordered_map<uint8_t, float> s_HearingDistances{{Constants::ChatChannel::DmTalk, 20.0f},
                                                             {Constants::ChatChannel::PlayerTalk, 20.0f},
                                                             {Constants::ChatChannel::DmWhisper, 3.0f},
                                                             {Constants::ChatChannel::PlayerWhisper, 3.0f}};

static Hooks::Hook s_SendServerToPlayerChatMessageHook = Hooks::HookFunction(
        Functions::_ZN11CNWSMessage29SendServerToPlayerChatMessageEhj10CExoStringjRKS0_,
        (void *) +[](CNWSMessage *thisPtr, uint8_t nChatMessageType, OBJECT_ID oidSpeaker, CExoString sSpeakerMessage, uint32_t nTellPlayerId,
                     const CExoString &sTellName)
        {
            int32_t retVal = false;

            LOG_DEBUG("%s", s_ChatScript);

            if (s_Depth == 0 && !s_ChatScript.empty())
            {
                s_ActiveChannel = nChatMessageType;
                s_ActiveMessage = sSpeakerMessage.m_sString ? std::string(sSpeakerMessage.m_sString) : "";
                s_ActiveSenderObjectId = oidSpeaker;

                CNWSClient *client = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nTellPlayerId, 0);
                s_ActiveTargetObjectId = client ? static_cast<CNWSPlayer *>(client)->m_oidPCObject : Constants::OBJECT_INVALID;

                ++s_Depth;
                Utils::ExecuteScript(s_ChatScript, oidSpeaker);
                --s_Depth;
            }
            // Suppress player to player tells
            if ((nChatMessageType != Constants::ChatChannel::PlayerTell && nChatMessageType != Constants::ChatChannel::DmTell) ||
                oidSpeaker == nTellPlayerId)
            {
                LOG_DEBUG("%s chat message. Channel: '%i', Message: '%s', Sender (ObjID): '0x%08x', Target (PlayerID): '0x%08x'",
                          s_SkipMessage ? "Skipped" : "Sent", nChatMessageType, sSpeakerMessage, oidSpeaker, nTellPlayerId);
            }
            else
            {
                LOG_DEBUG("%s chat message. Channel: '%i'", s_SkipMessage ? "Skipped" : "Sent", nChatMessageType);
            }

            if (s_Depth > 0 || !s_SkipMessage)
            {
                if (s_CustomHearingDistances)
                {
                    auto *pServer = Globals::AppManager()->m_pServerExoApp;
                    auto *pPlayerList = pServer->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal;
                    if (pPlayerList)
                    {
                        if (nChatMessageType == Constants::ChatChannel::PlayerShout && pServer->GetServerInfo()->m_PlayOptions.bDisallowShouting)
                        {
                            nChatMessageType = Constants::ChatChannel::PlayerTalk;
                        }

                        if (nChatMessageType == Constants::ChatChannel::PlayerTalk ||
                            nChatMessageType == Constants::ChatChannel::PlayerWhisper ||
                            nChatMessageType == Constants::ChatChannel::DmTalk ||
                            nChatMessageType == Constants::ChatChannel::DmWhisper)
                        {
                            auto *pSpeaker = Utils::AsNWSObject(pServer->GetGameObject(oidSpeaker));
                            auto distance = s_HearingDistances[nChatMessageType];
                            auto speakerPos = Vector{0.0f, 0.0f, 0.0f};
                            CNWSArea *pSpeakerArea = nullptr;
                            if (pSpeaker)
                            {
                                pSpeakerArea = pSpeaker->GetArea();
                                speakerPos = pSpeaker->m_vPosition;
                                pSpeaker->BroadcastDialog(sTellName, distance);
                            }

                            for (auto *head = pPlayerList->pHead; head; head = head->pNext)
                            {
                                auto *pClient = static_cast<CNWSClient *>(head->pObject);
                                auto *pListenerClient = pServer->GetClientObjectByPlayerId(pClient->m_nPlayerID, 0);
                                auto *pListener = static_cast<CNWSPlayer *>(pListenerClient);
                                auto *pListenerObj = Utils::AsNWSObject(pListener->GetGameObject());

                                auto pDistance = *pListenerObj->nwnxGet<float>("HEARING_DISTANCE:" + std::to_string(nChatMessageType));
                                if (pDistance >= 0)
                                {
                                    distance = pDistance;

                                    auto v = pListenerObj->m_vPosition;
                                    v.x -= speakerPos.x;
                                    v.y -= speakerPos.y;
                                    v.z -= speakerPos.z;
                                    float vSquared = v.x * v.x + v.y * v.y + v.z * v.z;
                                    if (pSpeakerArea == pListenerObj->GetArea() && vSquared <= distance * distance)
                                    {
                                        switch (nChatMessageType)
                                        {
                                            case Constants::ChatChannel::PlayerTalk:
                                                thisPtr->SendServerToPlayerChat_Talk(pListener->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                                break;
                                            case Constants::ChatChannel::DmTalk:
                                                thisPtr->SendServerToPlayerChat_DM_Talk(pListener->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                                break;
                                            case Constants::ChatChannel::PlayerWhisper:
                                                thisPtr->SendServerToPlayerChat_Whisper(pListener->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                                break;
                                            case Constants::ChatChannel::DmWhisper:
                                                thisPtr->SendServerToPlayerChat_DM_Whisper(pListener->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                }
                            }

                            retVal = true;
                        }
                        else
                        {
                            retVal = s_SendServerToPlayerChatMessageHook->CallOriginal<int32_t>(thisPtr, nChatMessageType, oidSpeaker,
                                                                                                sSpeakerMessage, nTellPlayerId, sTellName);
                        }
                    }
                }
                else
                {
                    retVal = s_SendServerToPlayerChatMessageHook->CallOriginal<int32_t>(thisPtr, nChatMessageType, oidSpeaker, sSpeakerMessage,
                                                                                        nTellPlayerId, sTellName);
                }
            }

            if (s_Depth == 0)
            {
                s_SkipMessage = false;
            }

            return retVal;
        }, Hooks::Order::Late);

NWNX_EXPORT ArgumentStack SendMessage(Events::ArgumentStack &&args)
{
    int32_t retVal = false;
    const auto channel = static_cast<Constants::ChatChannel::TYPE>(args.extract<int32_t>());
    const auto message = args.extract<std::string>();
    const auto speaker = args.extract<ObjectID>();
    const auto target = args.extract<ObjectID>();

    const bool hasManualPlayerId = target != Constants::OBJECT_INVALID;

    const PlayerID playerId = hasManualPlayerId ?
                              Globals::AppManager()->m_pServerExoApp->GetPlayerIDByGameObjectID(target) :
                              Constants::PLAYERID_ALL_CLIENTS;

    if (playerId != Constants::PLAYERID_INVALIDID)
    {
        bool sentMessage = false;
        CNWSMessage *messageDispatch = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());

        if (hasManualPlayerId)
        {
            // This means we're sending this to one player only.
            // The normal function broadcasts in an area for talk, shout, and whisper, therefore
            // we need to call these functions directly if we are in those categories.
            if (channel == Constants::ChatChannel::PlayerTalk)
            {
                messageDispatch->SendServerToPlayerChat_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmTalk)
            {
                messageDispatch->SendServerToPlayerChat_DM_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmDm || channel == Constants::ChatChannel::PlayerDm)
            {
                messageDispatch->SendServerToPlayerChat_DM_Silent_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerShout || channel == Constants::ChatChannel::DmShout)
            {
                messageDispatch->SendServerToPlayerChat_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerWhisper)
            {
                messageDispatch->SendServerToPlayerChat_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmWhisper)
            {
                messageDispatch->SendServerToPlayerChat_DM_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerParty || channel == Constants::ChatChannel::DmParty)
            {
                messageDispatch->SendServerToPlayerChat_Party(playerId, speaker, message.c_str());
                sentMessage = true;
            }
        }

        if (!sentMessage)
        {
            messageDispatch->SendServerToPlayerChatMessage(static_cast<uint8_t>(channel), speaker, message.c_str(), playerId, nullptr);
        }

        retVal = true;
    }
    else if (speaker != target)
    {
        // We shouldn't forget to handle listening NPCs.
        auto targetObj = Utils::AsNWSObject(Utils::GetGameObject(target));
        if (targetObj && targetObj->m_bListening)
        {
            // Sets listening pattern.
            targetObj->m_nMatchedPos = targetObj->TestListenExpression(message);
            if (targetObj->m_nMatchedPos != -1)
            {
                // Sets last speaker.
                targetObj->m_oidLastSpeaker = speaker;

                for (int i = 0; i < targetObj->m_aListenExpressions.num; ++i)
                {
                    if (targetObj->m_aListenExpressions[i]->m_nExpressionId == targetObj->m_nMatchedPos)
                    {
                        targetObj->ClearMatchedExpressionStrings();
                        for (int j = 1; j < targetObj->m_aListenExpressions[i]->m_aStored.num; ++j)
                            targetObj->AddMatchedExpressionString(*targetObj->m_aListenExpressions[i]->m_aStored[j]);
                    }
                }

                // Triggers OnConversation event.
                switch (targetObj->m_nObjectType)
                {
                    case Constants::ObjectType::Creature:
                        retVal = targetObj->RunEventScript(Constants::CreatureEvent::OnConversation);
                        break;
                    case Constants::ObjectType::Placeable:
                        retVal = targetObj->RunEventScript(Constants::PlaceableEvent::OnConversation);
                        break;
                    case Constants::ObjectType::Door:
                        retVal = targetObj->RunEventScript(Constants::DoorEvent::OnConversation);
                        break;
                }
            }
        }
    }

    return Events::Arguments(retVal);
}

NWNX_EXPORT ArgumentStack RegisterChatScript(Events::ArgumentStack &&args)
{
    s_ChatScript = args.extract<std::string>();
    return {};
}

NWNX_EXPORT ArgumentStack SkipMessage(Events::ArgumentStack &&)
{
    s_SkipMessage = true;
    return {};
}

NWNX_EXPORT ArgumentStack GetChannel(Events::ArgumentStack &&)
{
    return static_cast<int32_t>(s_ActiveChannel);
}

NWNX_EXPORT ArgumentStack GetMessage(Events::ArgumentStack &&)
{
    return s_ActiveMessage;
}

NWNX_EXPORT ArgumentStack GetSender(Events::ArgumentStack &&)
{
    return s_ActiveSenderObjectId;
}

NWNX_EXPORT ArgumentStack GetTarget(Events::ArgumentStack &&)
{
    return s_ActiveTargetObjectId;
}

NWNX_EXPORT ArgumentStack SetChatHearingDistance(Events::ArgumentStack &&args)
{
    const auto distance = Events::ExtractArgument<float>(args);
    const auto playerOid = Events::ExtractArgument<ObjectID>(args);
    const auto channel = (Constants::ChatChannel::TYPE) Events::ExtractArgument<int32_t>(args);

    if (playerOid == Constants::OBJECT_INVALID)
    {
        s_CustomHearingDistances = true;
        s_HearingDistances[channel] = distance;
    }
    else
    {
        auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerOid);
        if (!pPlayer)
        {
            LOG_NOTICE("NWNX_Chat function called on non-player object %x", playerOid);
        }
        else
        {
            s_CustomHearingDistances = true;
            auto *playerObj = Utils::GetGameObject(playerOid);
            playerObj->nwnxSet("HEARING_DISTANCE:" + std::to_string(channel), distance, true);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetChatHearingDistance(Events::ArgumentStack &&args)
{
    const auto playerOid = Events::ExtractArgument<ObjectID>(args);
    const auto channel = (Constants::ChatChannel::TYPE) Events::ExtractArgument<int32_t>(args);
    float retVal = s_HearingDistances[channel];

    if (playerOid != Constants::OBJECT_INVALID)
    {
        auto *playerObj = Utils::GetGameObject(playerOid);
        auto playerHearingDistance = *playerObj->nwnxGet<float>("HEARING_DISTANCE:" + std::to_string(channel));
        retVal = playerHearingDistance > 0 ? playerHearingDistance : s_HearingDistances[channel];
    }
    return retVal;
}
