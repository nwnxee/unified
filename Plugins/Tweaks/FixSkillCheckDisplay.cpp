#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CTlkTable.hpp"

#include <cstdlib>


namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SendServerToPlayerCCMessageHook;

static int32_t SendServerToPlayerCCMessageHook(CNWSMessage*, uint32_t, uint8_t, CNWCCMessageData*, CNWSCombatAttackData*);

void FixSkillCheckDisplay() __attribute__((constructor));
void FixSkillCheckDisplay()
{
    if (!Config::Get<bool>("FIX_SKILL_CHECK_DISPLAY", false))
        return;

    LOG_INFO("Skill checks with a DC or modifier the client can't display will be sent as feedback text.");

    // Runs after the Feedback plugin's hook, so hidden skill feedback stays hidden.
    s_SendServerToPlayerCCMessageHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerCCMessage,
                                                            &SendServerToPlayerCCMessageHook, Hooks::Order::VeryLate);
}

static std::string GetTlkString(uint32_t strRef)
{
    CExoString str = Globals::TlkTable()->GetSimpleString(strRef);
    return str.CStr() ? str.CStr() : "";
}

static void ReplaceToken(std::string& text, const std::string& token, const std::string& value)
{
    for (auto pos = text.find(token); pos != std::string::npos; pos = text.find(token, pos + value.size()))
        text.replace(pos, token.size(), value);
}

static uint32_t GetResultStrRef(int32_t nResult)
{
    switch (nResult)
    {
        case 0: return 5353;  // failure
        case 1: return 5352;  // success
        case 2: return 8100;  // critical failure
        case 3: return 8101;  // success not possible
        case 4: return 53306; // automatic success
        case 5: return 40091; // Success will never be possible
        default: return 0xFFFFFFFF;
    }
}

static int32_t SendServerToPlayerCCMessageHook(CNWSMessage *pMessage, uint32_t nPlayerId, uint8_t nMinor,
                                               CNWCCMessageData *pData, CNWSCombatAttackData *pAttackData)
{
    auto CallOriginal = [&]()
    {
        return s_SendServerToPlayerCCMessageHook->CallOriginal<int32_t>(pMessage, nPlayerId, nMinor, pData, pAttackData);
    };

    if (nMinor != Constants::MessageClientSideMsgMinor::UseSkill || !pData)
        return CallOriginal();

    // Integers: 0 skill name strref, 1 d20, 2 modifier (sent in 8 signed bits), 3 DC (sent in 7 bits), 4 take 20, 5 result.
    const int32_t nRoll = pData->GetInteger(1);
    const int32_t nModifier = pData->GetInteger(2);
    const int32_t nDC = pData->GetInteger(3);
    if (nDC >= 0 && nDC <= 127 && nModifier >= -128 && nModifier <= 127)
        return CallOriginal();

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId);
    auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pData->GetObjectID(0)));
    if (!pPlayer || !pCreature || !pCreature->m_pStats)
        return CallOriginal();

    // Same colours as the client: light blue for yourself, pink for others.
    auto *pPlayerObject = pPlayer->GetGameObject();
    const bool bSelf = pPlayerObject && pPlayerObject->m_idSelf == pCreature->m_idSelf;
    const auto sColour = bSelf ? CExoString::F("<c%c%c%c>", 153, 255, 255) : CExoString::F("<c%c%c%c>", 204, 153, 204);
    const auto sCreatureName = pCreature->m_sDisplayName.IsEmpty() ? pCreature->m_pStats->GetFullName() : pCreature->m_sDisplayName;
    const std::string sName = std::string(sColour.CStr()) + sCreatureName.CStr() + "</c>";

    const int32_t nResult = pData->GetInteger(5);
    const std::string sResult = GetTlkString(GetResultStrRef(nResult));
    const std::string sSkill = GetTlkString(pData->GetInteger(0));

    std::string sText;
    if (nResult == 5)
    {
        sText = sName + " : " + sSkill + " : *" + sResult + "*";
    }
    else
    {
        // "<CUSTOM0> : <CUSTOM1> : *<CUSTOM2>* : (<CUSTOM3> <CUSTOM4> <CUSTOM5> = <CUSTOM6> vs. DC: <CUSTOM7>)"
        sText = GetTlkString(10484);
        ReplaceToken(sText, "<CUSTOM0>", sName);
        ReplaceToken(sText, "<CUSTOM1>", sSkill);
        ReplaceToken(sText, "<CUSTOM2>", sResult);
        ReplaceToken(sText, "<CUSTOM3>", std::to_string(nRoll));
        ReplaceToken(sText, "<CUSTOM4>", nModifier < 0 ? "-" : "+");
        ReplaceToken(sText, "<CUSTOM5>", std::to_string(std::abs(nModifier)));
        ReplaceToken(sText, "<CUSTOM6>", std::to_string(nRoll + nModifier));
        ReplaceToken(sText, "<CUSTOM7>", std::to_string(nDC));
        if (pData->GetInteger(4))
            sText += " : " + GetTlkString(10485); // Take 20
    }

    pCreature->SendFeedbackString(CExoString(sText), pPlayer);
    return true;
}

}
