#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSExpression.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerInfo.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CServerAIMaster.hpp"

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
        &CNWSMessage::SendServerToPlayerChatMessage,
          +[](CNWSMessage *thisPtr, uint8_t nChatMessageType, OBJECT_ID oidSpeaker, CExoString sSpeakerMessage, uint32_t nTellPlayerId,
                     const CExoString &sTellName)
        {
            int32_t retVal = false;

            if (s_Depth == 0 && !s_ChatScript.empty())
            {
                s_ActiveChannel = nChatMessageType;
                s_ActiveMessage = sSpeakerMessage.CStr();
                s_ActiveSenderObjectId = oidSpeaker;

                CNWSPlayer *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nTellPlayerId);
                s_ActiveTargetObjectId = pPlayer ? pPlayer->m_oidPCObject : Constants::OBJECT_INVALID;

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
                    if (nChatMessageType == Constants::ChatChannel::PlayerShout &&
                        Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bDisallowShouting)
                    {
                        nChatMessageType = Constants::ChatChannel::PlayerTalk;
                    }

                    if (nChatMessageType == Constants::ChatChannel::PlayerTalk ||
                        nChatMessageType == Constants::ChatChannel::PlayerWhisper ||
                        nChatMessageType == Constants::ChatChannel::DmTalk ||
                        nChatMessageType == Constants::ChatChannel::DmWhisper)
                    {
                        auto distance = s_HearingDistances[nChatMessageType];
                        auto speakerPos = Vector{0.0f, 0.0f, 0.0f};
                        CNWSArea *pSpeakerArea = nullptr;

                        if (auto *pSpeaker = Utils::AsNWSObject(Utils::GetGameObject(oidSpeaker)))
                        {
                            pSpeakerArea = pSpeaker->GetArea();
                            speakerPos = pSpeaker->m_vPosition;
                            pSpeaker->BroadcastDialog(sSpeakerMessage, distance);
                        }

                        for (auto *pPlayer : Globals::AppManager()->m_pServerExoApp->GetPlayerList())
                        {
                            auto *pListenerCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject));

                            if (!pListenerCreature)// No valid creature, player likely on character selection, so skip them
                                continue;

                            if (auto customHearingDistance = pListenerCreature->nwnxGet<float>("HEARING_DISTANCE:" + std::to_string(nChatMessageType)))
                                distance = *customHearingDistance;

                            float vSquared = Vector::MagnitudeSquared(pListenerCreature->m_vPosition - speakerPos);

                            if (pSpeakerArea == pListenerCreature->GetArea() && vSquared <= distance * distance)
                            {
                                switch (nChatMessageType)
                                {
                                    case Constants::ChatChannel::PlayerTalk:
                                        thisPtr->SendServerToPlayerChat_Talk(pPlayer->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                        break;
                                    case Constants::ChatChannel::DmTalk:
                                        thisPtr->SendServerToPlayerChat_DM_Talk(pPlayer->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                        break;
                                    case Constants::ChatChannel::PlayerWhisper:
                                        thisPtr->SendServerToPlayerChat_Whisper(pPlayer->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                        break;
                                    case Constants::ChatChannel::DmWhisper:
                                        thisPtr->SendServerToPlayerChat_DM_Whisper(pPlayer->m_nPlayerID, oidSpeaker, sSpeakerMessage);
                                        break;
                                    default:
                                        break;
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

NWNX_EXPORT ArgumentStack SendMessage(ArgumentStack &&args)
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
        CNWSMessage *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();

        if (hasManualPlayerId)
        {
            // This means we're sending this to one player only.
            // The normal function broadcasts in an area for talk, shout, and whisper, therefore
            // we need to call these functions directly if we are in those categories.
            if (channel == Constants::ChatChannel::PlayerTalk)
            {
                pMessage->SendServerToPlayerChat_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmTalk)
            {
                pMessage->SendServerToPlayerChat_DM_Talk(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmDm || channel == Constants::ChatChannel::PlayerDm)
            {
                pMessage->SendServerToPlayerChat_DM_Silent_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerShout || channel == Constants::ChatChannel::DmShout)
            {
                pMessage->SendServerToPlayerChat_Shout(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerWhisper)
            {
                pMessage->SendServerToPlayerChat_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::DmWhisper)
            {
                pMessage->SendServerToPlayerChat_DM_Whisper(playerId, speaker, message.c_str());
                sentMessage = true;
            }
            else if (channel == Constants::ChatChannel::PlayerParty || channel == Constants::ChatChannel::DmParty)
            {
                pMessage->SendServerToPlayerChat_Party(playerId, speaker, message.c_str());
                sentMessage = true;
            }
        }

        if (!sentMessage)
        {
            pMessage->SendServerToPlayerChatMessage(static_cast<uint8_t>(channel), speaker, message.c_str(), playerId, nullptr);
        }

        retVal = true;
    }
    else if (speaker != target)
    {
        // We shouldn't forget to handle listening NPCs.
        auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(target));
        if (pTarget && pTarget->m_bListening)
        {
            int32_t nMatched = pTarget->TestListenExpression(message);

            if (nMatched >= 0)
            {
                auto *pScriptEvent = new CScriptEvent;
                pScriptEvent->m_nType = Constants::ScriptEvent::OnDialogue;
                pScriptEvent->SetInteger(0, pTarget->GetListenExpressionObj(nMatched)->m_aStored.num);
                pScriptEvent->SetInteger(1, nMatched);
                for (int i = 1; i < pTarget->GetListenExpressionObj(nMatched)->m_aStored.num; i++)
                {
                    pScriptEvent->SetString(i, *pTarget->GetListenExpressionObj(nMatched)->m_aStored[i]);
                }

                Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pServerAIMaster->AddEventDeltaTime(
                        0, 0, speaker, target, Constants::AIMasterEvent::SignalEvent, pScriptEvent);
            }
        }
    }

    return ScriptAPI::Arguments(retVal);
}

NWNX_EXPORT ArgumentStack RegisterChatScript(ArgumentStack &&args)
{
    s_ChatScript = args.extract<std::string>();
    return {};
}

NWNX_EXPORT ArgumentStack SkipMessage(ArgumentStack &&)
{
    s_SkipMessage = true;
    return {};
}

NWNX_EXPORT ArgumentStack GetChannel(ArgumentStack &&)
{
    return static_cast<int32_t>(s_ActiveChannel);
}

NWNX_EXPORT ArgumentStack GetMessage(ArgumentStack &&)
{
    return s_ActiveMessage;
}

NWNX_EXPORT ArgumentStack GetSender(ArgumentStack &&)
{
    return s_ActiveSenderObjectId;
}

NWNX_EXPORT ArgumentStack GetTarget(ArgumentStack &&)
{
    return s_ActiveTargetObjectId;
}

NWNX_EXPORT ArgumentStack SetChatHearingDistance(ArgumentStack &&args)
{
    const auto distance = args.extract<float>();
      ASSERT_OR_THROW(distance >= 0.0f);
    const auto playerOid = args.extract<ObjectID>();
    const auto channel = (Constants::ChatChannel::TYPE)args.extract<int32_t>();

    if (playerOid == Constants::OBJECT_INVALID)
    {
        s_CustomHearingDistances = true;
        s_HearingDistances[channel] = distance;
    }
    else
    {
        if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerOid))
        {
            if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
            {
                s_CustomHearingDistances = true;
                pCreature->nwnxSet("HEARING_DISTANCE:" + std::to_string(channel), distance, true);
            }
        }
        else
        {
            LOG_NOTICE("NWNX_Chat function called on non-player object %x", playerOid);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetChatHearingDistance(ArgumentStack &&args)
{
    const auto playerOid = args.extract<ObjectID>();
    const auto channel = (Constants::ChatChannel::TYPE)args.extract<int32_t>();
    float retVal = s_HearingDistances[channel];

    if (playerOid != Constants::OBJECT_INVALID)
    {
        if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(playerOid))
        {
            if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
            {
                if (auto customHearingDistance = pCreature->nwnxGet<float>("HEARING_DISTANCE:" + std::to_string(channel)))
                {
                    retVal = *customHearingDistance;
                }
            }
        }
    }

    return retVal;
}
